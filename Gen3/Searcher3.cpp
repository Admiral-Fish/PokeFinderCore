/*
 * This file is part of PokéFinderCore
 * Copyright (C) 2017 by Admiral_Fish, bumba, and EzPzStreamz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "Searcher3.hpp"

Searcher3::Searcher3()
{
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
    frame.setIDs(tid, sid, psv);
}

Searcher3::Searcher3(u16 tid, u16 sid, u32 ratio, const FrameCompare &compare)
{
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    this->compare = compare;
    frame.setIDs(tid, sid, psv);
    frame.setGenderRatio(ratio);
}

Searcher3::~Searcher3()
{
    delete forward;
    delete backward;
    delete cache;
    delete euclidean;
    delete natureLock;
}

QVector<Frame3> Searcher3::search(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe)
{
    switch (frameType)
    {
        case Method::Method1:
        case Method::Method2:
        case Method::Method4:
            return searchMethod124(hp, atk, def, spa, spd, spe);
        case Method::Method1Reverse:
            return searchMethod1Reverse(hp, atk, def, spa, spd, spe);
        case Method::MethodH1:
        case Method::MethodH2:
        case Method::MethodH4:
            return searchMethodH124(hp, atk, def, spa, spd, spe);
        case Method::Colo:
            return searchMethodColo(hp, atk, def, spa, spd, spe);
        case Method::XD:
            return searchMethodXD(hp, atk, def, spa, spd, spe);
        case Method::XDColo:
            return searchMethodXDColo(hp, atk, def, spa, spd, spe);
        case Method::Channel:
            return searchMethodChannel(hp, atk, def, spa, spd, spe);
        default:
            return QVector<Frame3>();
    }
}

void Searcher3::setup(Method method)
{
    frameType = method;

    if (frameType == Method::XDColo || frameType == Method::Channel || frameType == Method::XD || frameType == Method::Colo)
    {
        forward = new XDRNG(0);
        backward = new XDRNGR(0);
    }
    else
    {
        forward = new PokeRNG(0);
        backward = new PokeRNGR(0);
    }

    switch (frameType)
    {
        case Method::Method1:
        case Method::Method1Reverse:
        case Method::MethodH1:
            cache = new RNGCache(Method::Method1);
            break;
        case Method::Method2:
        case Method::MethodH2:
            cache = new RNGCache(Method::Method2);
            break;
        case Method::Method4:
        case Method::MethodH4:
            cache = new RNGCache(Method::Method4);
            break;
        case Method::Colo:
        case Method::XD:
        case Method::XDColo:
            euclidean = new RNGEuclidean(Method::XDColo);
            break;
        case Method::Channel:
            euclidean = new RNGEuclidean(Method::Channel);
            break;
        default:
            break;
    }
}

void Searcher3::setupNatureLock(int num)
{
    if (frameType == Method::XD)
    {
        natureLock = new NatureLock(num, Method::XD);
    }
    else if (frameType == Method::Colo)
    {
        natureLock = new NatureLock(num, Method::Colo);
    }
    type = natureLock->getType();
    frame.setLockReason(QObject::tr("Pass NL"));
}

void Searcher3::setEncounter(const EncounterArea3 &value)
{
    encounter = value;
}

QVector<Frame3> Searcher3::searchMethodChannel(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe)
{
    QVector<Frame3> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
    {
        return frames;
    }

    QVector<u32> seeds = euclidean->recoverLower27BitsChannel(hp, atk, def, spa, spd, spe);
    for (const auto &seed : seeds)
    {
        backward->setSeed(seed, 3);

        // Calculate PID
        u16 pid2 = backward->nextUShort();
        u16 pid1 = backward->nextUShort();
        u16 sid = backward->nextUShort();

        // Determine if PID needs to be XORed
        if ((pid2 > 7 ? 0 : 1) != (pid1 ^ sid ^ 40122))
        {
            pid1 ^= 0x8000;
        }

        frame.setIDs(40122, sid, 40122 ^ sid);
        frame.setPID(pid2, pid1);

        if (compare.comparePID(frame))
        {
            frame.setSeed(backward->nextUInt());
            frames.append(frame);
        }
    }
    return frames;
}

QVector<Frame3> Searcher3::searchMethodColo(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe)
{
    QVector<Frame3> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
    {
        return frames;
    }

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<QPair<u32, u32>> seeds = euclidean->recoverLower16BitsIV(first, second);
    for (const auto &pair : seeds)
    {
        // Setup normal frame
        forward->setSeed(pair.second, 1);
        frame.setPID(forward->nextUShort(), forward->nextUShort());
        frame.setSeed(pair.first * 0xB9B33155 + 0xA170F641);
        if (compare.comparePID(frame))
        {
            switch (type)
            {
                case ShadowType::FirstShadow:
                    if (natureLock->firstShadowNormal(frame.getSeed()))
                    {
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    break;
                case ShadowType::EReader:
                    if (natureLock->eReader(frame.getSeed(), frame.getPID()))
                    {
                        frames.push_back(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    break;
                default:
                    break;
            }
        }

        // Setup XORed frame
        frame.xorFrame(true);
        if (compare.comparePID(frame))
        {
            switch (type)
            {
                case ShadowType::FirstShadow:
                    if (natureLock->firstShadowNormal(frame.getSeed()))
                    {
                        frames.append(frame);
                    }
                    break;
                case ShadowType::EReader:
                    if (natureLock->eReader(frame.getSeed(), frame.getPID()))
                    {
                        frames.append(frame);
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return frames;
}

QVector<Frame3> Searcher3::searchMethodH124(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe)
{
    QVector<Frame3> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
    {
        return frames;
    }

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val, frameType == MethodH2 ? 1 : 0);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        // Use for loop to check both normal and sister spread
        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.xorFrame();
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
            {
                continue;
            }

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot;
            u16 nextRNG = seed >> 16;
            u16 nextRNG2 = testRNG.nextUShort();

            do
            {
                switch (leadType)
                {
                    case Lead::None:
                        if ((nextRNG % 25) == frame.getNature())
                        {
                            frame.setLeadType(Lead::None);
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xdc6c95d9 + 0x4d3cb126);
                            frame.setEncounterSlot(EncounterSlot::hSlot(slot >> 16, encounterType));
                            if (compare.compareSlot(frame))
                            {
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frames.append(frame);
                            }
                        }
                        break;
                    case Lead::Synchronize:
                        // Successful synch
                        if ((nextRNG & 1) == 0)
                        {
                            frame.setLeadType(Lead::Synchronize);
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xdc6c95d9 + 0x4d3cb126);
                            frame.setEncounterSlot(EncounterSlot::hSlot(slot >> 16, encounterType));
                            if (compare.compareSlot(frame))
                            {
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frames.append(frame);
                            }
                        }
                        // Failed synch
                        else if ((nextRNG2 & 1) == 1 && (nextRNG % 25) == frame.getNature())
                        {
                            frame.setLeadType(Lead::Synchronize);
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            frame.setSeed(slot * 0xdc6c95d9 + 0x4d3cb126);
                            frame.setEncounterSlot(EncounterSlot::hSlot(slot >> 16, encounterType));
                            if (compare.compareSlot(frame))
                            {
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frames.append(frame);
                            }
                        }
                        break;
                    case Lead::CuteCharm:
                        if ((nextRNG2 % 3) > 0)
                        {
                            frame.setLeadType(Lead::CuteCharm);
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            frame.setSeed(slot * 0xdc6c95d9 + 0x4d3cb126);
                            frame.setEncounterSlot(EncounterSlot::hSlot(slot >> 16, encounterType));
                            if (compare.compareSlot(frame))
                            {
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frames.append(frame);
                            }
                        }
                        break;
                    case Lead::Search:
                    default:
                        // Normal
                        if ((nextRNG % 25) == frame.getNature())
                        {
                            frame.setLeadType(Lead::None);
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xdc6c95d9 + 0x4d3cb126);
                            frame.setEncounterSlot(EncounterSlot::hSlot(slot >> 16, encounterType));
                            if (compare.compareSlot(frame))
                            {
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frames.append(frame);
                            }

                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            frame.setSeed(slot * 0xdc6c95d9 + 0x4d3cb126);
                            frame.setEncounterSlot(EncounterSlot::hSlot(slot >> 16, encounterType));
                            if (compare.compareSlot(frame))
                            {
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));

                                // Failed synch
                                if ((nextRNG2 & 1) == 1 && (nextRNG % 25) == frame.getNature())
                                {
                                    frame.setLeadType(Lead::Synchronize);
                                    frames.append(frame);
                                }

                                // Cute Charm
                                if ((nextRNG2 % 3) > 0)
                                {
                                    frame.setLeadType(Lead::CuteCharm);
                                    frames.append(frame);
                                }
                            }
                        }
                        // Successful Synch
                        else if ((nextRNG & 1) == 0)
                        {
                            frame.setLeadType(Lead::Synchronize);
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xdc6c95d9 + 0x4d3cb126);
                            frame.setEncounterSlot(EncounterSlot::hSlot(slot >> 16, encounterType));
                            if (compare.compareSlot(frame))
                            {
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frames.append(frame);
                            }

                        }
                        break;
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.nextUShort();
                nextRNG2 = testRNG.nextUShort();
            }
            while ((testPID % 25) != frame.getNature());
        }
    }

    // RSE rock smash is dependent on origin seed for encounter check
    if (encounterType == Encounter::RockSmash)
    {
        u16 rate = encounter.getEncounterRate() * 16;

        // 2880 means FRLG which is not dependent on origin seed for encounter check
        if (rate != 2880)
        {
            for (int i = 0; i < frames.size();)
            {
                u32 check = frames[i].getSeed() * 0x41c64e6d + 0x6073;

                if (((check >> 16) % 2880) >= rate)
                {
                    frames.erase(frames.begin() + i);
                }
                else
                {
                    frames[i].setSeed(frames[i].getSeed() * 0xeeb9eb65 + 0xa3561a1);
                    i++;
                }
            }
        }
    }

    return frames;
}

QVector<Frame3> Searcher3::searchMethodXD(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe)
{
    QVector<Frame3> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
    {
        return frames;
    }

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<QPair<u32, u32>> seeds = euclidean->recoverLower16BitsIV(first, second);
    for (const auto &pair : seeds)
    {
        // Setup normal frame
        forward->setSeed(pair.second, 1);
        frame.setPID(forward->nextUShort(), forward->nextUShort());
        frame.setSeed(pair.first * 0xB9B33155 + 0xA170F641);
        if (compare.comparePID(frame))
        {
            switch (type)
            {
                case ShadowType::SingleLock:
                    if (natureLock->singleNL(frame.getSeed()))
                    {
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    break;
                case ShadowType::FirstShadow:
                    if (natureLock->firstShadowNormal(frame.getSeed()))
                    {
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    break;
                case ShadowType::SecondShadow:
                    if (natureLock->firstShadowUnset(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("First shadow unset")); // Also unlikely for the other methods of encounter to pass
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    if (natureLock->firstShadowSet(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("First shadow set")); // Also unlikely for the other methods of encounter to pass
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    if (natureLock->firstShadowShinySkip(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("Shiny Skip")); // Also unlikely for the other methods of encounter to pass
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    break;
                case ShadowType::Salamence:
                    if (natureLock->salamenceUnset(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("First shadow unset")); // Also unlikely for the other methods of encounter to pass
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    if (natureLock->salamenceSet(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("First shadow set")); // Also unlikely for the other methods of encounter to pass
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    if (natureLock->salamenceShinySkip(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("Shiny Skip")); // Also unlikely for the other methods of encounter to pass
                        frames.append(frame); // If this seed passes it is impossible for the sister spread to generate
                        continue;
                    }
                    break;
                default:
                    break;
            }
        }

        // Setup XORed frame
        frame.xorFrame(true);
        if (compare.comparePID(frame))
        {
            switch (type)
            {
                case ShadowType::SingleLock:
                    if (natureLock->singleNL(frame.getSeed()))
                    {
                        frames.append(frame);
                    }
                    break;
                case ShadowType::FirstShadow:
                    if (natureLock->firstShadowNormal(frame.getSeed()))
                    {
                        frames.append(frame);
                    }
                    break;
                case ShadowType::SecondShadow:
                    if (natureLock->firstShadowUnset(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("First shadow unset"));
                        frames.append(frame);
                    }
                    else if (natureLock->firstShadowSet(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("First shadow set"));
                        frames.append(frame);
                    }
                    else if (natureLock->firstShadowShinySkip(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("Shiny Skip"));
                        frames.append(frame);
                    }
                    break;
                case ShadowType::Salamence:
                    if (natureLock->salamenceUnset(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("First shadow unset"));
                        frames.append(frame);
                    }
                    else if (natureLock->salamenceSet(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("First shadow set"));
                        frames.append(frame);
                    }
                    else if (natureLock->salamenceShinySkip(frame.getSeed()))
                    {
                        frame.setLockReason(QObject::tr("Shiny Skip"));
                        frames.append(frame);
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return frames;
}

QVector<Frame3> Searcher3::searchMethodXDColo(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe)
{
    QVector<Frame3> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
    {
        return frames;
    }

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<QPair<u32, u32>> seeds = euclidean->recoverLower16BitsIV(first, second);
    for (const auto &pair : seeds)
    {
        // Setup normal frame
        forward->setSeed(pair.second, 1);
        frame.setPID(forward->nextUShort(), forward->nextUShort());
        frame.setSeed(pair.first * 0xB9B33155 + 0xA170F641);
        if (compare.comparePID(frame))
        {
            frames.append(frame);
        }

        // Setup XORed frame
        frame.xorFrame(true);
        if (compare.comparePID(frame))
        {
            frames.append(frame);
        }
    }
    return frames;
}

QVector<Frame3> Searcher3::searchMethod124(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe)
{
    QVector<Frame3> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
    {
        return frames;
    }

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    for (const auto &seed : seeds)
    {
        // Setup normal frame
        backward->setSeed(seed, frameType == Method2 ? 1 : 0);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        frame.setSeed(backward->nextUInt());
        if (compare.comparePID(frame))
        {
            frames.append(frame);
        }

        // Setup XORed frame
        frame.xorFrame(true);
        if (compare.comparePID(frame))
        {
            frames.append(frame);
        }
    }
    return frames;
}

// Returns QVector of frames for Method 1 Reverse
QVector<Frame3> Searcher3::searchMethod1Reverse(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe)
{
    QVector<Frame3> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
    {
        return frames;
    }

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    for (const auto &seed : seeds)
    {
        // Setup normal frame
        backward->setSeed(seed);
        u16 temp = backward->nextUShort();
        frame.setPID(temp, backward->nextUShort());
        frame.setSeed(backward->nextUInt());
        if (compare.comparePID(frame))
        {
            frames.append(frame);
        }

        // Setup XORed frame
        frame.xorFrame(true);
        if (compare.comparePID(frame))
        {
            frames.append(frame);
        }
    }
    return frames;
}
