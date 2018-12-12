/*
 * This file is part of PokéFinderCore
 * Copyright (C) 2017 by Admiral_Fish, bumba, and EzPzStreamz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
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

#include "Searcher4.hpp"

Searcher4::Searcher4()
{
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
    frame.setIDs(tid, sid, psv);
}

// Constructor given user defined parameters
Searcher4::Searcher4(u16 tid, u16 sid, u32 ratio, u32 minDelay, u32 maxDelay, u32 minFrame, u32 maxFrame, const FrameCompare &compare, Method method)
{
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    this->compare = compare;
    frame.setIDs(tid, sid, psv);
    frame.setGenderRatio(ratio);
    frameType = method;
    this->minDelay = minDelay;
    this->maxDelay = maxDelay;
    this->minFrame = minFrame;
    this->maxFrame = maxFrame;
    cache = new RNGCache(method);
    backward = new PokeRNGR(0);
}

Searcher4::~Searcher4()
{
    delete cache;
    delete backward;
}

QVector<Frame4> Searcher4::search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;
    switch (frameType)
    {
        case Method::Method1:
            frames = searchMethod1(hp, atk, def, spa, spd, spe);
            break;
        case Method::MethodJ:
            switch (leadType)
            {
                case Lead::None:
                    frame.setLeadType(Lead::None);
                    frames = searchMethodJ(hp, atk, def, spa, spd, spe);
                    break;
                case Lead::Synchronize:
                    frame.setLeadType(Lead::Synchronize);
                    frames = searchMethodJSynch(hp, atk, def, spa, spd, spe);
                    break;
                case Lead::CuteCharm:
                    frames = searchMethodJCuteCharm(hp, atk, def, spa, spd, spe);
                    break;
                case Lead::Search:
                    frames = searchMethodJSearch(hp, atk, def, spa, spd, spe);
                    break;
                default:
                    break;
            }
            break;
        case Method::MethodK:
            switch (leadType)
            {
                case Lead::None:
                    frame.setLeadType(Lead::None);
                    frames = searchMethodK(hp, atk, def, spa, spd, spe);
                    break;
                case Lead::Synchronize:
                    frame.setLeadType(Lead::Synchronize);
                    frames = searchMethodKSynch(hp, atk, def, spa, spd, spe);
                    break;
                case Lead::CuteCharm:
                    frames = searchMethodKCuteCharm(hp, atk, def, spa, spd, spe);
                    break;
                case Lead::SuctionCups:
                    frames = searchMethodKSuctionCups(hp, atk, def, spa, spd, spe);
                    break;
                case Lead::Search:
                    frames = searchMethodKSearch(hp, atk, def, spa, spd, spe);
                    break;
                default:
                    break;
            }
            break;
        case Method::ChainedShiny:
            frames = searchChainedShiny(hp, atk, def, spa, spd, spe);
            break;
        case Method::WondercardIVs:
            frames = searchWondercardIVs(hp, atk, def, spa, spd, spe);
            break;
        default:
            break;
    }
    return searchInitialSeeds(frames);
}

void Searcher4::setEncounter(const EncounterArea4 &value)
{
    encounter = value;
}

QVector<Frame4> Searcher4::searchMethod1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    for (const auto &seed : seeds)
    {
        // Setup normal frame
        backward->setSeed(seed);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        frame.setSeed(backward->nextUInt());
        if (compare.comparePID(frame))
            frames.append(frame);

        // Setup XORed frame
        frame.xorFrame();
        if (compare.comparePID(frame))
        {
            frame.setSeed(frame.getSeed() ^ 0x80000000);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodJ(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.xorFrame();
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            PokeRNGR testRNG(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                u32 nibble;
                bool skip = false;

                if ((nextRNG / 0xa3e) == frame.getNature())
                {
                    switch (encounterType)
                    {
                        case Encounter::Grass:
                            slot = testRNG.getSeed();
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::OldRod:
                        case Encounter::GoodRod:
                        case Encounter::SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) / 656) <= thresh)
                            {
                                frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skip = true;
                            break;
                        case Encounter::Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                        frames.append(frame);
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.nextUShort();
                nextRNG2 = testRNG.nextUShort();
            }
            while (testPID % 25 != frame.getNature());
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodJSynch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.xorFrame();
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            PokeRNGR testRNG(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                u32 nibble;
                bool skip = false;

                // Successful synch
                if ((nextRNG >> 15) == 0)
                {
                    switch (encounterType)
                    {
                        case Encounter::Grass:
                            slot = testRNG.getSeed();
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::OldRod:
                        case Encounter::GoodRod:
                        case Encounter::SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) / 656) <= thresh)
                            {
                                frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skip = true;
                            break;
                        case Encounter::Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }
                }
                // Failed Synch
                else if ((nextRNG2 >> 15) == 1 && (nextRNG / 0xa3e) == frame.getNature())
                {
                    switch (encounterType)
                    {
                        case Encounter::Grass:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::Surfing:
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::OldRod:
                        case Encounter::GoodRod:
                        case Encounter::SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) / 656) <= thresh)
                            {
                                frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), slot >> 16));
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skip = true;
                            break;
                        case Encounter::Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                            break;
                    }
                }

                if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                    frames.append(frame);

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.nextUShort();
                nextRNG2 = testRNG.nextUShort();
            }
            while (testPID % 25 != frame.getNature());
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodJCuteCharm(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u32 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        u16 pid2 = backward->nextUShort();
        u16 pid1 = backward->nextUShort();
        u32 seed = backward->nextUInt();
        u32 nibble;

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                pid2 ^= 0x8000;
                pid1 ^= 0x8000;
                seed ^= 0x80000000;
            }

            if ((pid1 / 0x5556) != 0)
            {
                u32 slot = 0;

                switch (encounterType)
                {
                    case Encounter::Grass:
                        slot = seed;
                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Encounter::Surfing:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), seed >> 16));
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Encounter::OldRod:
                    case Encounter::GoodRod:
                    case Encounter::SuperRod:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                        if ((nibble >> 16) / 656 <= thresh)
                        {
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), seed >> 16));
                            frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                        }
                        else
                            continue;
                        break;
                    case Encounter::Stationary:
                    default:
                        frame.setSeed(seed);
                        break;
                }

                u32 choppedPID = pid2 / 0xa3e;
                for (const auto &buffer : unbiasedBuffer)
                {
                    switch (buffer)
                    {
                        case 0x0:
                            frame.setLeadType(Lead::CuteCharmFemale);
                            break;
                        case 0x96:
                            frame.setLeadType(Lead::CuteCharm50M);
                            break;
                        case 0xC8:
                            frame.setLeadType(Lead::CuteCharm25M);
                            break;
                        case 0x4B:
                            frame.setLeadType(Lead::CuteCharm75M);
                            break;
                        case 0x32:
                            frame.setLeadType(Lead::CuteCharm875M);
                            break;
                        default:
                            frame.setLeadType(Lead::CuteCharm);
                            break;
                    }

                    frame.setPID(choppedPID + buffer, 0);
                    if (!compare.comparePID(frame))
                        continue;

                    if (encounterType == Encounter::Stationary || compare.compareSlot(frame))
                        frames.append(frame);
                }
            }
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodJSearch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    u16 adjustedThresh = encounterType == Encounter::OldRod ? 48 : encounterType == Encounter::GoodRod ? 98 : encounterType == Encounter::SuperRod ? 99 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        u16 pid2 = backward->nextUShort();
        u16 pid1 = backward->nextUShort();
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                pid1 ^= 0x8000;
                pid2 ^= 0x8000;
                seed ^= 0x80000000;
            }

            PokeRNGR testRNG(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();
            u32 nibble = 0;

            frame.setPID(pid1, pid2);
            if (compare.comparePID(frame))
            {
                do
                {
                    bool skip = false;

                    // Normal
                    if ((nextRNG / 0xa3e) == frame.getNature())
                    {
                        frame.setLeadType(Lead::None);
                        switch (encounterType)
                        {
                            case Encounter::Grass:
                                slot = testRNG.getSeed();
                                frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Encounter::Surfing:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Encounter::OldRod:
                            case Encounter::GoodRod:
                            case Encounter::SuperRod:
                                slot = testRNG.getSeed();
                                nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                                if (((nibble >> 16) / 656) <= adjustedThresh)
                                {
                                    if (((nibble >> 16) / 656) > thresh)
                                        frame.setLeadType(Lead::SuctionCups);
                                    frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                    frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), slot >> 16));
                                    frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                }
                                else
                                    skip = true;
                                break;
                            case Stationary:
                            default:
                                frame.setSeed(testRNG.getSeed());
                                break;
                        }

                        if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                            frames.append(frame);

                        // Failed synch
                        if ((nextRNG2 >> 15) == 1)
                        {
                            frame.setLeadType(Lead::Synchronize);
                            u32 level;
                            switch (encounterType)
                            {
                                case Encounter::Grass:
                                    slot = frame.getSeed();
                                    frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                    frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                    frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                    break;
                                case Encounter::Surfing:
                                    level = slot;
                                    slot = frame.getSeed();
                                    frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                    frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), level >> 16));
                                    frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                    break;
                                case Encounter::OldRod:
                                case Encounter::GoodRod:
                                case Encounter::SuperRod:
                                    slot = nibble;
                                    nibble = frame.getSeed();
                                    if (((nibble >> 16) / 656) <= thresh)
                                    {
                                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), slot >> 16));
                                        frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                    }
                                    else
                                        skip = true;
                                    break;
                                case Encounter::Stationary:
                                default:
                                    frame.setSeed(testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                                    break;
                            }

                            if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                                frames.append(frame);
                        }
                    }
                    // Successful synch
                    else if ((nextRNG >> 15) == 0)
                    {
                        frame.setLeadType(Lead::Synchronize);
                        switch (encounterType)
                        {
                            case Encounter::Grass:
                                slot = testRNG.getSeed();
                                frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Encounter::Surfing:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Encounter::OldRod:
                            case Encounter::GoodRod:
                            case Encounter::SuperRod:
                                slot = testRNG.getSeed();
                                nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                                if (((nibble >> 16) / 656) <= thresh)
                                {
                                    frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                    frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), slot >> 16));
                                    frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                }
                                else
                                    skip = true;
                                break;
                            case Encounter::Stationary:
                            default:
                                frame.setSeed(testRNG.getSeed());
                                break;
                        }

                        if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                            frames.append(frame);
                    }

                    testPID = (nextRNG << 16) | nextRNG2;
                    nextRNG = testRNG.nextUShort();
                    nextRNG2 = testRNG.nextUShort();
                }
                while (testPID % 25 != frame.getNature());
            }

            if (pid1 / 0x5556 != 0)
            {
                u32 slot = 0;
                bool skipFrame = false;

                switch (encounterType)
                {
                    case Encounter::Grass:
                        slot = seed;
                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Encounter::Surfing:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), seed >> 16));
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Encounter::OldRod:
                    case Encounter::GoodRod:
                    case Encounter::SuperRod:
                        slot = seed;
                        nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                        if ((nibble >> 16) / 656 <= thresh)
                        {
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), slot >> 16));
                            frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                        }
                        else
                            continue;
                        break;
                    case Encounter::Stationary:
                    default:
                        frame.setSeed(seed);
                        break;
                }

                u32 choppedPID = pid2 / 0xA3E;
                if (!skipFrame)
                {
                    for (const auto &buffer : unbiasedBuffer)
                    {
                        switch (buffer)
                        {
                            case 0x0:
                                frame.setLeadType(Lead::CuteCharmFemale);
                                break;
                            case 0x96:
                                frame.setLeadType(Lead::CuteCharm50M);
                                break;
                            case 0xC8:
                                frame.setLeadType(Lead::CuteCharm25M);
                                break;
                            case 0x4B:
                                frame.setLeadType(Lead::CuteCharm75M);
                                break;
                            case 0x32:
                                frame.setLeadType(Lead::CuteCharm875M);
                                break;
                            default:
                                frame.setLeadType(Lead::CuteCharm);
                                break;
                        }

                        frame.setPID(buffer + choppedPID, 0);
                        if (!compare.comparePID(frame))
                            continue;

                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Encounter::Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
                }
            }
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodK(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.xorFrame();
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            PokeRNGR testRNG(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                u32 nibble;
                bool skip = false;

                if ((nextRNG % 25) == frame.getNature())
                {
                    switch (encounterType)
                    {
                        case Encounter::Grass:
                            slot = testRNG.getSeed();
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::OldRod:
                        case Encounter::GoodRod:
                        case Encounter::SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) % 100) <= thresh)
                            {
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skip = true;
                            break;
                        case Encounter::RockSmash:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            if (((slot >> 16) % 100) < 40) // Need to setup lookup table for locations
                            {
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            }
                            break;
                        case Encounter::Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                        frames.append(frame);
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.nextUShort();
                nextRNG2 = testRNG.nextUShort();
            }
            while (testPID % 25 != frame.getNature());
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodKSynch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.xorFrame();
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            PokeRNGR testRNG(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                u32 nibble;
                bool skip = false;

                // Successful synch
                if ((nextRNG & 1) == 0)
                {
                    switch (encounterType)
                    {
                        case Encounter::Grass:
                            slot = testRNG.getSeed();
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::OldRod:
                        case Encounter::GoodRod:
                        case Encounter::SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) % 100) <= thresh)
                            {
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skip = true;
                            break;
                        case Encounter::Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                        frames.append(frame);
                }
                // Failed Synch
                else if ((nextRNG2 & 1) == 1 && (nextRNG % 25) == frame.getNature())
                {
                    switch (encounterType)
                    {
                        case Encounter::Grass:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::Surfing:
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::OldRod:
                        case Encounter::GoodRod:
                        case Encounter::SuperRod:
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) % 100) <= thresh)
                            {
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skip = true;
                            break;
                        case Encounter::Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                            break;
                    }

                    if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                        frames.append(frame);
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.nextUShort();
                nextRNG2 = testRNG.nextUShort();
            }
            while (testPID % 25 != frame.getNature());
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodKCuteCharm(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u32 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        u16 pid2 = backward->nextUShort();
        u16 pid1 = backward->nextUShort();
        u32 seed = backward->nextUInt();
        u32 nibble;

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                pid2 ^= 0x8000;
                pid1 ^= 0x8000;
                seed ^= 0x80000000;
            }

            if ((pid1 % 3) != 0)
            {
                u32 slot = 0;

                switch (encounterType)
                {
                    case Encounter::Grass:
                        slot = seed;
                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Encounter::Surfing:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), seed >> 16));
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Encounter::OldRod:
                    case Encounter::GoodRod:
                    case Encounter::SuperRod:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;;
                        nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                        if ((nibble >> 16) % 100 <= thresh)
                        {
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                        }
                        else
                            continue;
                        break;
                    case Encounter::Stationary:
                    default:
                        frame.setSeed(seed);
                        break;
                }

                u32 choppedPID = pid2 % 25;
                for (const auto &buffer : unbiasedBuffer)
                {
                    switch (buffer)
                    {
                        case 0x0:
                            frame.setLeadType(Lead::CuteCharmFemale);
                            break;
                        case 0x96:
                            frame.setLeadType(Lead::CuteCharm50M);
                            break;
                        case 0xC8:
                            frame.setLeadType(Lead::CuteCharm25M);
                            break;
                        case 0x4B:
                            frame.setLeadType(Lead::CuteCharm75M);
                            break;
                        case 0x32:
                            frame.setLeadType(Lead::CuteCharm875M);
                            break;
                        default:
                            frame.setLeadType(Lead::CuteCharm);
                            break;
                    }

                    frame.setPID(choppedPID + buffer, 0);
                    if (!compare.comparePID(frame))
                        continue;

                    if (encounterType == Encounter::Stationary || compare.compareSlot(frame))
                        frames.append(frame);
                }
            }
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodKSuctionCups(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    u16 adjustedThresh = encounterType == Encounter::OldRod ? 48 : encounterType == Encounter::GoodRod ? 98 : encounterType == Encounter::SuperRod ? 99 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.xorFrame();
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            PokeRNGR testRNG(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                u32 nibble;
                bool skip = false;

                if ((nextRNG % 25) == frame.getNature())
                {
                    frame.setLeadType(Lead::None);
                    switch (encounterType)
                    {
                        case Encounter::Grass:
                            slot = testRNG.getSeed();
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Encounter::OldRod:
                        case Encounter::GoodRod:
                        case Encounter::SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) % 100) <= adjustedThresh)
                            {
                                if (((nibble >> 16) % 100) > thresh)
                                    frame.setLeadType(Lead::SuctionCups);
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skip = true;
                            break;
                        case Encounter::Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                        frames.append(frame);
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.nextUShort();
                nextRNG2 = testRNG.nextUShort();
            }
            while (testPID % 25 != frame.getNature());
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodKSearch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;
    u16 adjustedThresh = encounterType == Encounter::OldRod ? 48 : encounterType == Encounter::GoodRod ? 98 : encounterType == Encounter::SuperRod ? 99 : 0;
    for (const auto &val : seeds)
    {
        // Setup normal frame
        backward->setSeed(val);
        u16 pid2 = backward->nextUShort();
        u16 pid1 = backward->nextUShort();
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                pid1 ^= 0x8000;
                pid2 ^= 0x8000;
                seed ^= 0x80000000;
            }

            PokeRNGR testRNG(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();
            u32 nibble = 0;

            frame.setPID(pid1, pid2);
            if (compare.comparePID(frame))
            {
                do
                {
                    bool skip = false;

                    // Normal
                    if ((nextRNG % 25) == frame.getNature())
                    {
                        frame.setLeadType(Lead::None);
                        switch (encounterType)
                        {
                            case Encounter::Grass:
                                slot = testRNG.getSeed();
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Encounter::Surfing:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Encounter::OldRod:
                            case Encounter::GoodRod:
                            case Encounter::SuperRod:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;;
                                nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                                if (((nibble >> 16) % 100) <= adjustedThresh)
                                {
                                    if (((nibble >> 16) % 100) > thresh)
                                        frame.setLeadType(Lead::SuctionCups);
                                    frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                    frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                    frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                }
                                else
                                    skip = true;
                                break;
                            case Encounter::Stationary:
                            default:
                                frame.setSeed(testRNG.getSeed());
                                break;
                        }

                        if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                            frames.append(frame);

                        // Failed synch
                        if ((nextRNG2 & 1) == 1)
                        {
                            frame.setLeadType(Lead::Synchronize);
                            u32 level;
                            switch (encounterType)
                            {
                                case Encounter::Grass:
                                    slot = frame.getSeed();
                                    frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                    frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                    frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                    break;
                                case Encounter::Surfing:
                                    level = slot;
                                    slot = frame.getSeed();
                                    frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                    frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), level >> 16));
                                    frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                    break;
                                case Encounter::OldRod:
                                case Encounter::GoodRod:
                                case Encounter::SuperRod:
                                    slot = nibble;
                                    nibble = frame.getSeed();
                                    if (((nibble >> 16) / 656) <= thresh)
                                    {
                                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                        frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                    }
                                    else
                                        skip = true;
                                    break;
                                case Encounter::Stationary:
                                default:
                                    frame.setSeed(testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                                    break;
                            }

                            if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                                frames.append(frame);
                        }
                    }
                    // Successful synch
                    else if ((nextRNG & 1) == 0)
                    {
                        frame.setLeadType(Lead::Synchronize);
                        switch (encounterType)
                        {
                            case Encounter::Grass:
                                slot = testRNG.getSeed();
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Encounter::Surfing:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), testRNG.getSeed() >> 16));
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Encounter::OldRod:
                            case Encounter::GoodRod:
                            case Encounter::SuperRod:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;;
                                nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                                if (((nibble >> 16) % 100) <= thresh)
                                {
                                    frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                    frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                                    frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                }
                                else
                                    skip = true;
                                break;
                            case Encounter::Stationary:
                            default:
                                frame.setSeed(testRNG.getSeed());
                                break;
                        }

                        if (!skip && (encounterType == Encounter::Stationary || compare.compareSlot(frame)))
                            frames.append(frame);
                    }

                    testPID = (nextRNG << 16) | nextRNG2;
                    nextRNG = testRNG.nextUShort();
                    nextRNG2 = testRNG.nextUShort();
                }
                while (testPID % 25 != frame.getNature());
            }

            if ((pid1 % 3) != 0)
            {
                u32 slot = 0;
                bool skipFrame = false;

                switch (encounterType)
                {
                    case Encounter::Grass:
                        slot = seed;
                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Encounter::Surfing:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), seed >> 16));
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Encounter::OldRod:
                    case Encounter::GoodRod:
                    case Encounter::SuperRod:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;;
                        nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                        if (((nibble >> 16) % 100) <= thresh)
                        {
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                            frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                        }
                        else
                            continue;
                        break;
                    case Encounter::Stationary:
                    default:
                        frame.setSeed(seed);
                        break;
                }

                u32 choppedPID = pid2 % 25;
                if (!skipFrame)
                {
                    for (const auto &buffer : unbiasedBuffer)
                    {
                        switch (buffer)
                        {
                            case 0x0:
                                frame.setLeadType(Lead::CuteCharmFemale);
                                break;
                            case 0x96:
                                frame.setLeadType(Lead::CuteCharm50M);
                                break;
                            case 0xC8:
                                frame.setLeadType(Lead::CuteCharm25M);
                                break;
                            case 0x4B:
                                frame.setLeadType(Lead::CuteCharm75M);
                                break;
                            case 0x32:
                                frame.setLeadType(Lead::CuteCharm875M);
                                break;
                            default:
                                frame.setLeadType(Lead::CuteCharm);
                                break;
                        }

                        frame.setPID(buffer + choppedPID, 0);
                        if (!compare.comparePID(frame))
                            continue;

                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Encounter::Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
                }
            }
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchChainedShiny(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);

    u16 calls[15];
    u16 low, high;

    for (const auto &seed : seeds)
    {
        backward->setSeed(seed);

        for (auto &call : calls)
            call = backward->nextUShort();

        low = chainedPIDLow(calls);
        high = chainedPIDHigh(calls[13], low, tid, sid);
        frame.setPID(low, high);

        if (compare.comparePID(frame))
        {
            backward->nextUInt();
            frame.setSeed(backward->nextUInt());
            frames.append(frame);

            // Sister spread shares PID
            frame.setSeed(frame.getSeed() ^ 0x80000000);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchWondercardIVs(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<u32> seeds = cache->recoverLower16BitsIV(first, second);
    for (const auto &seed : seeds)
    {
        // Setup normal frame
        backward->setSeed(seed);
        frame.setSeed(backward->nextUInt());
        frames.append(frame);

        // Setup XORed frame
        frame.setSeed(frame.getSeed() ^ 0x80000000);
        frames.append(frame);
    }

    return frames;
}

QVector<Frame4> Searcher4::searchInitialSeeds(QVector<Frame4> results)
{
    QVector<Frame4> frames;

    for (Frame4 result : results)
    {
        backward->setSeed(result.getSeed());
        backward->advanceFrames(minFrame - 1);
        u32 test = backward->getSeed();

        for (u32 cnt = minFrame; cnt <= maxFrame; cnt++)
        {
            u32 hour = (test >> 16) & 0xFF;
            u32 delay = test & 0xFFFF;

            // Check if seed matches a valid gen 4 format
            if (hour < 24 && delay >= minDelay && delay <= maxDelay)
            {
                result.setSeed(test);
                result.setFrame(cnt);
                frames.append(result);
            }

            test = backward->nextUInt();
        }
    }

    return frames;
}


u16 Searcher4::chainedPIDLow(const u16 *calls)
{
    return static_cast<u16>((calls[14] & 7) | ((calls[12] & 1) << 3) | ((calls[11] & 1) << 4) | ((calls[10] & 1) << 5) | ((calls[9] & 1) << 6) |
                            ((calls[8] & 1) << 7) | ((calls[7] & 1) << 8) | ((calls[6] & 1) << 9) | ((calls[5] & 1) << 10) | ((calls[4] & 1) << 11) |
                            ((calls[3] & 1) << 12) | ((calls[2] & 1) << 13) | ((calls[1] & 1) << 14) | ((calls[0] & 1) << 15));
}

u16 Searcher4::chainedPIDHigh(u16 high, u16 low, u16 tid, u16 sid)
{
    return (((low ^ tid ^ sid) & 0xFFF8) | (high & 7));
}
