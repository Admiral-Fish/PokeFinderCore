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
Searcher4::Searcher4(u16 tid, u16 sid, u32 ratio, u32 minDelay, u32 maxDelay, u32 minFrame, u32 maxFrame, FrameCompare compare, Method method)
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
        case Method1:
            frames = searchMethod1(hp, atk, def, spa, spd, spe);
            break;
        case MethodJ:
            switch (leadType)
            {
                case None:
                    frames = searchMethodJ(hp, atk, def, spa, spd, spe);
                    break;
                case Synchronize:
                    frames = searchMethodJSynch(hp, atk, def, spa, spd, spe);
                    break;
                case CuteCharm:
                    frames = searchMethodJCuteCharm(hp, atk, def, spa, spd, spe);
                    break;
                case SuctionCups:
                    frames = searchMethodJSuctionCups(hp, atk, def, spa, spd, spe);
                    break;
                case Search:
                    frames = searchMethodJSearch(hp, atk, def, spa, spd, spe);
                    break;
                default:
                    break;
            }
            break;
        case MethodK:
            switch (leadType)
            {
                case None:
                    frames = searchMethodK(hp, atk, def, spa, spd, spe);
                    break;
                case Synchronize:
                    frames = searchMethodKSynch(hp, atk, def, spa, spd, spe);
                    break;
                case CuteCharm:
                    frames = searchMethodKCuteCharm(hp, atk, def, spa, spd, spe);
                    break;
                case SuctionCups:
                    frames = searchMethodKSuctionCups(hp, atk, def, spa, spd, spe);
                    break;
                case Search:
                    frames = searchMethodKSearch(hp, atk, def, spa, spd, spe);
                    break;
                default:
                    break;
            }
            break;
        case ChainedShiny:
            frames = searchChainedShiny(hp, atk, def, spa, spd, spe);
            break;
        case WondercardIVs:
            frames = searchWondercardIVs(hp, atk, def, spa, spd, spe);
            break;
        default:
            break;
    }
    return searchInitialSeeds(frames);
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
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        frame.setSeed(backward->nextUInt());
        if (compare.comparePID(frame))
            frames.append(frame);

        // Setup XORed frame
        frame.setPID(frame.getPid() ^ 0x80008000);
        frame.setNature(frame.getPid() % 25);
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

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.setPID(frame.getPid() ^ 0x80008000);
                frame.setNature(frame.getPid() % 25);
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                bool skipFrame = false;
                u32 nibble;

                if ((nextRNG / 0xa3e) == frame.getNature())
                {
                    frame.setLeadType(None);

                    switch (encounterType)
                    {
                        case Wild:
                            slot = testRNG.getSeed();
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case OldRod:
                        case GoodRod:
                        case SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) / 656) <= thresh)
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            else
                                skipFrame = true;
                            break;
                        case Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skipFrame)
                    {
                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
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

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.setPID(frame.getPid() ^ 0x80008000);
                frame.setNature(frame.getPid() % 25);
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                bool skipFrame = false;
                u32 nibble;

                // Successful synch
                if ((nextRNG >> 15) == 0)
                {
                    switch (encounterType)
                    {
                        case Wild:
                            slot = testRNG.getSeed();
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case OldRod:
                        case GoodRod:
                        case SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) / 656) <= thresh)
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            else
                                skipFrame = true;
                            break;
                        case Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skipFrame)
                    {
                        frame.setLeadType(Synchronize);
                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
                }
                // Failed Synch
                else if ((nextRNG2 >> 15) == 1 && (nextRNG / 0xa3e) == frame.getNature())
                {
                    switch (encounterType)
                    {
                        case Wild:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Surfing:
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case OldRod:
                        case GoodRod:
                        case SuperRod:
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) / 656) <= thresh)
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            else
                                skipFrame = true;
                            break;
                        case Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                            break;
                    }

                    if (!skipFrame)
                    {
                        frame.setLeadType(Synchronize);
                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
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

QVector<Frame4> Searcher4::searchMethodJCuteCharm(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        u32 pid2 = backward->nextUShort();
        u32 pid1 = backward->nextUShort();
        u32 seed = backward->nextUInt();

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
                bool skipFrame = false;

                switch (encounterType)
                {
                    case Wild:
                        slot = seed;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Surfing:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case OldRod:
                    case GoodRod:
                    case SuperRod:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        if ((frame.getSeed() >> 16) / 656 > thresh)
                            skipFrame = true;
                        else
                            frame.setSeed(frame.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Stationary:
                    default:
                        frame.setSeed(seed);
                        break;
                }

                u32 choppedPID = pid2 / 0xa3e;
                if (!skipFrame)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        u32 buffer = unbiasedBuffer[i];
                        switch (buffer)
                        {
                            case 0x0:
                                frame.setLeadType(CuteCharmFemale);
                                break;
                            case 0x96:
                                frame.setLeadType(CuteCharm50M);
                                break;
                            case 0xC8:
                                frame.setLeadType(CuteCharm25M);
                                break;
                            case 0x4B:
                                frame.setLeadType(CuteCharm75M);
                                break;
                            case 0x32:
                                frame.setLeadType(CuteCharm875M);
                                break;
                            default:
                                frame.setLeadType(CuteCharm);
                                break;
                        }

                        frame.setPID(choppedPID + buffer, 0);
                        if (!compare.comparePID(frame))
                            continue;

                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
                }
            }
        }
    }

    return frames;
}

QVector<Frame4> Searcher4::searchMethodJSuctionCups(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;
    u32 adjustedThresh = encounterType == OldRod ? 48 : encounterType == GoodRod ? 98 : encounterType == SuperRod ? 99 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.setPID(frame.getPid() ^ 0x80008000);
                frame.setNature(frame.getPid() % 25);
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                bool skipFrame = false;
                u32 nibble;

                if ((nextRNG / 0xa3e) == frame.getNature())
                {
                    frame.setLeadType(None);

                    switch (encounterType)
                    {
                        case Wild:
                            slot = testRNG.getSeed();
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case OldRod:
                        case GoodRod:
                        case SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) / 656) <= adjustedThresh)
                            {
                                if (((nibble >> 16) / 656) > thresh)
                                    frame.setLeadType(SuctionCups);
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skipFrame = true;
                            break;
                        case Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skipFrame)
                    {
                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
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

QVector<Frame4> Searcher4::searchMethodJSearch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    QVector<Frame4> frames;

    frame.setIVsManual(hp, atk, def, spa, spd, spe);
    if (!compare.compareHiddenPower(frame))
        return frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;
    u32 adjustedThresh = encounterType == OldRod ? 48 : encounterType == GoodRod ? 98 : encounterType == SuperRod ? 99 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        u32 pid2 = backward->nextUShort();
        u32 pid1 = backward->nextUShort();
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                pid1 ^= 0x8000;
                pid2 ^= 0x8000;
                seed ^= 0x80000000;
            }

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            frame.setPID(pid1, pid2);
            if (compare.comparePID(frame))
            {
                do
                {
                    bool skipFrame = false;
                    u32 nibble;

                    // Normal
                    if ((nextRNG / 0xa3e) == frame.getNature())
                    {
                        frame.setLeadType(None);
                        switch (encounterType)
                        {
                            case Wild:
                                slot = testRNG.getSeed();
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Surfing:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case OldRod:
                            case GoodRod:
                            case SuperRod:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;;
                                nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                                if (((nibble >> 16) / 656) <= adjustedThresh)
                                {
                                    if (((nibble >> 16) / 656) > thresh)
                                        frame.setLeadType(SuctionCups);
                                    frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                }
                                else
                                    skipFrame = true;
                                break;
                            case Stationary:
                            default:
                                frame.setSeed(testRNG.getSeed());
                                break;
                        }

                        if (!skipFrame)
                        {
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            if (encounterType == Stationary || compare.compareSlot(frame))
                                frames.append(frame);
                        }

                        // Failed synch
                        if ((nextRNG2 >> 15) == 1)
                        {
                            switch (encounterType)
                            {
                                case OldRod:
                                case GoodRod:
                                case SuperRod:
                                    nibble = (frame.getSeed() >> 16) / 656;
                                    if (nibble > thresh)
                                        skipFrame = true;
                                    break;
                                default:
                                    break;
                            }

                            slot = frame.getSeed();
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);

                            if (!skipFrame)
                            {
                                frame.setLeadType(Synchronize);
                                frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                                if (encounterType == Stationary || compare.compareSlot(frame))
                                    frames.append(frame);
                            }
                        }
                    }
                    // Successful synch
                    else if ((nextRNG >> 15) == 0)
                    {
                        switch (encounterType)
                        {
                            case Wild:
                                slot = testRNG.getSeed();
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Surfing:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case OldRod:
                            case GoodRod:
                            case SuperRod:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                                if (((nibble >> 16) / 656) <= thresh)
                                    frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                else
                                    skipFrame = true;
                                break;
                            case Stationary:
                            default:
                                frame.setSeed(testRNG.getSeed());
                                break;
                        }

                        if (!skipFrame)
                        {
                            frame.setLeadType(Synchronize);
                            frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                            if (encounterType == Stationary || compare.compareSlot(frame))
                                frames.append(frame);
                        }
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
                    case Wild:
                        slot = seed;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Surfing:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case OldRod:
                    case GoodRod:
                    case SuperRod:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        if ((frame.getSeed() >> 16) / 656 > thresh)
                            skipFrame = true;
                        else
                            frame.setSeed(frame.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Stationary:
                    default:
                        frame.setSeed(seed);
                }

                u32 choppedPID = pid2 / 0xA3E;
                if (!skipFrame)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        u32 buffer = unbiasedBuffer[i];
                        switch (buffer)
                        {
                            case 0x0:
                                frame.setLeadType(CuteCharmFemale);
                                break;
                            case 0x96:
                                frame.setLeadType(CuteCharm50M);
                                break;
                            case 0xC8:
                                frame.setLeadType(CuteCharm25M);
                                break;
                            case 0x4B:
                                frame.setLeadType(CuteCharm75M);
                                break;
                            case 0x32:
                                frame.setLeadType(CuteCharm875M);
                                break;
                            default:
                                frame.setLeadType(CuteCharm);
                                break;
                        }

                        frame.setPID(buffer + choppedPID, 0);
                        if (!compare.comparePID(frame))
                            continue;

                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
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

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.setPID(frame.getPid() ^ 0x80008000);
                frame.setNature(frame.getPid() % 25);
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                bool skipFrame = false;
                u32 nibble;

                if ((nextRNG % 25) == frame.getNature())
                {
                    frame.setLeadType(None);

                    switch (encounterType)
                    {
                        case Wild:
                            slot = testRNG.getSeed();
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case OldRod:
                        case GoodRod:
                        case SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) % 100) <= thresh)
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            else
                                skipFrame = true;
                            break;
                        case Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skipFrame)
                    {
                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
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

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.setPID(frame.getAbility() ^ 0x80008000);
                frame.setNature(frame.getPid() % 25);
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                bool skipFrame = false;
                u32 nibble;

                // Successful synch
                if ((nextRNG & 1) == 0)
                {
                    switch (encounterType)
                    {
                        case Wild:
                            slot = testRNG.getSeed();
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case OldRod:
                        case GoodRod:
                        case SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) % 100) <= thresh)
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            else
                                skipFrame = true;
                            break;
                        case Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skipFrame)
                    {
                        frame.setLeadType(Synchronize);
                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
                }
                // Failed Synch
                else if ((nextRNG2 & 1) == 1 && (nextRNG % 25) == frame.getNature())
                {
                    switch (encounterType)
                    {
                        case Wild:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Surfing:
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case OldRod:
                        case GoodRod:
                        case SuperRod:
                            slot = testRNG.getSeed() * 0xdc6c95d9 + 0x4d3cb126;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) % 100) <= thresh)
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            else
                                skipFrame = true;
                            break;
                        case Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                            break;
                    }

                    if (!skipFrame)
                    {
                        frame.setLeadType(Synchronize);
                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
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

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        u32 pid2 = backward->nextUShort();
        u32 pid1 = backward->nextUShort();
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                pid1 ^= 0x8000;
                pid2 ^= 0x8000;
                seed ^= 0x80000000;
            }

            if (pid1 % 3 != 0)
            {
                u32 slot = 0;
                bool skipFrame = false;

                switch (encounterType)
                {
                    case Wild:
                        slot = seed;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Surfing:
                    case BugCatchingContest:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setSeed(frame.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case OldRod:
                    case GoodRod:
                    case SuperRod:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setSeed(frame.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                        if ((frame.getSeed() >> 16) % 100 > thresh)
                            skipFrame = true;
                        else
                            frame.setSeed(frame.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Stationary:
                    default:
                        frame.setSeed(seed);
                        break;
                }

                u32 choppedPID = pid2 % 25;
                if (!skipFrame)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        u32 buffer = unbiasedBuffer[i];
                        switch (buffer)
                        {
                            case 0x0:
                                frame.setLeadType(CuteCharmFemale);
                                break;
                            case 0x96:
                                frame.setLeadType(CuteCharm50M);
                                break;
                            case 0xC8:
                                frame.setLeadType(CuteCharm25M);
                                break;
                            case 0x4B:
                                frame.setLeadType(CuteCharm75M);
                                break;
                            case 0x32:
                                frame.setLeadType(CuteCharm875M);
                                break;
                            default:
                                frame.setLeadType(CuteCharm);
                                break;
                        }

                        frame.setPID(choppedPID + buffer, 0);
                        if (!compare.comparePID(frame))
                            continue;

                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
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

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;
    u32 adjustedThresh = encounterType == OldRod ? 48 : encounterType == GoodRod ? 98 : encounterType == SuperRod ? 99 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        frame.setPID(backward->nextUShort(), backward->nextUShort());
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.setPID(frame.getPid() ^ 0x80008000);
                frame.setNature(frame.getPid() % 25);
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                bool skipFrame = false;
                u32 nibble;

                if ((nextRNG % 25) == frame.getNature())
                {
                    frame.setLeadType(None);

                    switch (encounterType)
                    {
                        case Wild:
                            slot = testRNG.getSeed();
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case Surfing:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                            break;
                        case OldRod:
                        case GoodRod:
                        case SuperRod:
                            slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;;
                            nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                            if (((nibble >> 16) % 100) <= adjustedThresh)
                            {
                                if (((nibble >> 16) % 100) > thresh)
                                    frame.setLeadType(SuctionCups);
                                frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                            }
                            else
                                skipFrame = true;
                            break;
                        case Stationary:
                        default:
                            frame.setSeed(testRNG.getSeed());
                            break;
                    }

                    if (!skipFrame)
                    {
                        frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
                            frames.append(frame);
                    }
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

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 thresh = encounterType == OldRod ? 24 : encounterType == GoodRod ? 49 : encounterType == SuperRod ? 74 : 0;
    u32 adjustedThresh = encounterType == OldRod ? 48 : encounterType == GoodRod ? 98 : encounterType == SuperRod ? 99 : 0;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
        u32 pid2 = backward->nextUShort();
        u32 pid1 = backward->nextUShort();
        u32 seed = backward->nextUInt();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                pid2 ^= 0x8000;
                pid1 ^= 0x8000;
                seed ^= 0x80000000;
            }

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot = 0;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            frame.setPID(pid1, pid2);
            if (compare.comparePID(frame))
            {
                do
                {
                    bool skipFrame = false;
                    u32 nibble;

                    // Normal
                    if ((nextRNG % 25) == frame.getNature())
                    {
                        frame.setLeadType(None);
                        switch (encounterType)
                        {
                            case Wild:
                                slot = testRNG.getSeed();
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Surfing:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case OldRod:
                            case GoodRod:
                            case SuperRod:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;;
                                nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                                if (((nibble >> 16) % 100) <= adjustedThresh)
                                {
                                    if (((nibble >> 16) % 100) > thresh)
                                        frame.setLeadType(SuctionCups);
                                    frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                }
                                else
                                    skipFrame = true;
                                break;
                            case Stationary:
                            default:
                                frame.setSeed(testRNG.getSeed());
                                break;
                        }

                        if (!skipFrame)
                        {
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            if (encounterType == Stationary || compare.compareSlot(frame))
                                frames.append(frame);
                        }

                        // Failed synch
                        if ((nextRNG2 & 1) == 1)
                        {
                            switch (encounterType)
                            {
                                case OldRod:
                                case GoodRod:
                                case SuperRod:
                                    nibble = (frame.getSeed() >> 16) % 100;
                                    if (nibble > thresh)
                                        skipFrame = true;
                                    break;
                                default:
                                    break;
                            }

                            slot = frame.getSeed();
                            frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);

                            if (!skipFrame)
                            {
                                frame.setLeadType(Synchronize);
                                frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                                if (encounterType == Stationary || compare.compareSlot(frame))
                                    frames.append(frame);
                            }
                        }
                    }
                    // Successful synch
                    else if ((nextRNG & 1) == 0)
                    {
                        switch (encounterType)
                        {
                            case Wild:
                                slot = testRNG.getSeed();
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case Surfing:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                                break;
                            case OldRod:
                            case GoodRod:
                            case SuperRod:
                                slot = testRNG.getSeed() * 0xeeb9eb65 + 0xa3561a1;
                                nibble = slot * 0xeeb9eb65 + 0xa3561a1;
                                if (((nibble >> 16) % 100) <= thresh)
                                    frame.setSeed(nibble * 0xeeb9eb65 + 0xa3561a1);
                                else
                                    skipFrame = true;
                                break;
                            case Stationary:
                            default:
                                frame.setSeed(testRNG.getSeed());
                                break;
                        }

                        if (!skipFrame)
                        {
                            frame.setLeadType(Synchronize);
                            frame.setEncounterSlot(EncounterSlot::kSlot(slot >> 16, encounterType));
                            if (encounterType == Stationary || compare.compareSlot(frame))
                                frames.append(frame);
                        }
                    }

                    testPID = (nextRNG << 16) | nextRNG2;
                    nextRNG = testRNG.nextUShort();
                    nextRNG2 = testRNG.nextUShort();
                }
                while (testPID % 25 != frame.getNature());
            }

            if (pid1 % 3 != 0)
            {
                u32 slot = 0;
                bool skipFrame = false;

                switch (encounterType)
                {
                    case Wild:
                        slot = seed;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Surfing:
                    case BugCatchingContest:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case OldRod:
                    case GoodRod:
                    case SuperRod:
                        slot = seed * 0xeeb9eb65 + 0xa3561a1;
                        frame.setSeed(slot * 0xeeb9eb65 + 0xa3561a1);
                        if ((frame.getSeed() >> 16) % 100 > thresh)
                            skipFrame = true;
                        else
                            frame.setSeed(frame.getSeed() * 0xeeb9eb65 + 0xa3561a1);
                        break;
                    case Stationary:
                    default:
                        frame.setSeed(seed);
                }

                u32 choppedPID = pid2 % 25;
                if (!skipFrame)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        u32 buffer = unbiasedBuffer[i];
                        switch (buffer)
                        {
                            case 0x0:
                                frame.setLeadType(CuteCharmFemale);
                                break;
                            case 0x96:
                                frame.setLeadType(CuteCharm50M);
                                break;
                            case 0xC8:
                                frame.setLeadType(CuteCharm25M);
                                break;
                            case 0x4B:
                                frame.setLeadType(CuteCharm75M);
                                break;
                            case 0x32:
                                frame.setLeadType(CuteCharm875M);
                                break;
                            default:
                                frame.setLeadType(CuteCharm);
                                break;
                        }

                        frame.setPID(choppedPID + buffer, 0);
                        if (!compare.comparePID(frame))
                            continue;

                        frame.setEncounterSlot(EncounterSlot::jSlot(slot >> 16, encounterType));
                        if (encounterType == Stationary || compare.compareSlot(frame))
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

    QVector<uint> seeds = cache->recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 calls[15];
    u32 low, high;

    for (auto i = 0; i < size; i++)
    {
        backward->setSeed(seeds[i]);

        for (int i = 0; i < 15; i++)
            calls[i] = backward->nextUShort();

        low = chainedPIDLow(calls[14], calls[0], calls[1], calls[2], calls[3], calls[4], calls[5], calls[6], calls[7], calls[8], calls[9], calls[10], calls[11], calls[12]);
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
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward->setSeed(seeds[i]);
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


u32 Searcher4::chainedPIDLow(u32 low, u32 call1, u32 call2, u32 call3, u32 call4, u32 call5, u32 call6, u32 call7, u32 call8, u32 call9, u32 call10, u32 call11, u32 call12, u32 call13)
{
    return (low & 0x7) | (call13 & 1) << 3 | (call12 & 1) << 4 | (call11 & 1) << 5 | (call10 & 1) << 6 |
           (call9 & 1) << 7 | (call8 & 1) << 8 | (call7 & 1) << 9 | (call6 & 1) << 10 | (call5 & 1) << 11 |
           (call4 & 1) << 12 | (call3 & 1) << 13 | (call2 & 1) << 14 | (call1 & 1) << 15;
}

u32 Searcher4::chainedPIDHigh(u32 high, u32 low, u32 tid, u32 sid)
{
    return (((low ^ tid ^ sid) & 0xFFF8) | (high & 0x7));
}
