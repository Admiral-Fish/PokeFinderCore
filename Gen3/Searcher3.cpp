/*
 * This file is part of libPokéFinder
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

// Default constructor
Searcher3::Searcher3()
{
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
    frame.setIDs(tid, sid, psv);
}

// Constructor given user defined parameters
Searcher3::Searcher3(u16 tid, u16 sid, u32 ratio, FrameCompare compare)
{
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    this->compare = compare;
    frame.setIDs(tid, sid, psv);
    frame.genderRatio = ratio;
}

// Returns vector of frames for Channel Method
vector<Frame3> Searcher3::searchMethodChannel(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame3> frames;

    vector<uint> seeds = euclidean.recoverLower27BitsChannel(hp, atk, def, spa, spd, spe);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        frame.setIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];

        // Calculate PID
        backward.advanceFrames(3);
        u32 pid2 = backward.nextUShort();
        u32 pid1 = backward.nextUShort();

        // Determine if PID needs to be XORed
        if ((pid2 > 7 ? 0 : 1) != (pid1 ^ backward.nextUShort() ^ 40122))
            pid1 ^= 0x8000;
        frame.setPID(pid2, pid1);

        if (compare.comparePID(frame))
        {
            frame.seed = backward.nextUInt();
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method Colo Shadows
vector<Frame3> Searcher3::searchMethodColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame3> frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = euclidean.recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    // Need to eventually add Naturelock checking
    for (auto i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.setIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        forward.nextUInt();
        frame.setPID(forward.nextUShort(), forward.nextUShort());
        frame.seed = seeds[i] * 0xB9B33155 + 0xA170F641;
        if (compare.comparePID(frame))
        {
            if (natureLock.firstShadowNormal(frame.seed))
            {
                frames.push_back(frame);
                continue;
            }
        }

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.comparePID(frame))
        {
            frame.seed ^= 0x80000000;
            if (natureLock.firstShadowNormal(frame.seed))
                frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method H1/H2/H4
vector<Frame3> Searcher3::searchMethodH124(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame3> frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.recoverLower16BitsIV(first, second);
    auto size = seeds.size();
    u32 seed;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.setIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        if (frameType == MethodH2)
            backward.advanceFrames(1);
        frame.setPID(backward.nextUShort(), backward.nextUShort());
        seed = backward.nextUInt();

        // Use for loop to check both normal and sister spread
        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.pid ^= 0x80008000;
                frame.nature = frame.pid % 25;
                seed ^= 0x80000000;
            }

            if (!compare.comparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            u32 testPID, slot, testSeed;
            u32 nextRNG = seed >> 16;
            u32 nextRNG2 = testRNG.nextUShort();

            do
            {
                switch (leadType)
                {
                    case None:
                        if ((nextRNG % 25) == frame.nature)
                        {
                            frame.leadType = None;
                            slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                            testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                            frame.seed = testSeed;
                            frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                            if (compare.compareSlot(frame))
                                frames.push_back(frame);
                        }
                        break;
                    case Synchronize:
                        // Successful synch
                        if ((nextRNG & 1) == 0)
                        {
                            frame.leadType = Synchronize;
                            slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                            testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                            frame.seed = testSeed;
                            frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                            if (compare.compareSlot(frame))
                                frames.push_back(frame);
                        }
                        // Failed synch
                        else if ((nextRNG2 & 1) == 1 && (nextRNG % 25) == frame.nature)
                        {
                            frame.leadType = Synchronize;
                            slot = testRNG.seed * 0xdc6c95d9 + 0x4d3cb126;
                            testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                            frame.seed = testSeed;
                            frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                            frames.push_back(frame);
                        }
                        break;
                    case CuteCharm:
                        if ((nextRNG2 % 3) > 0)
                        {
                            frame.leadType = CuteCharm;
                            slot = testRNG.seed * 0xdc6c95d9 + 0x4d3cb126;
                            testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                            frame.seed = testSeed;
                            frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                            if (compare.compareSlot(frame))
                                frames.push_back(frame);
                        }
                        break;
                    case Search:
                    default:
                        // Normal
                        if ((nextRNG % 25) == frame.nature)
                        {
                            frame.leadType = None;
                            slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                            testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                            frame.seed = testSeed;
                            frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                            if (compare.compareSlot(frame))
                                frames.push_back(frame);

                            slot = testRNG.seed * 0xdc6c95d9 + 0x4d3cb126;
                            testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                            frame.seed = testSeed;
                            frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                            if (compare.compareSlot(frame))
                            {

                                // Failed synch
                                if ((nextRNG2 & 1) == 1 && (nextRNG % 25) == frame.nature)
                                {
                                    frame.leadType = Synchronize;
                                    frames.push_back(frame);
                                }

                                // Cute Charm
                                if ((nextRNG2 % 3) > 0)
                                {
                                    frame.leadType = CuteCharm;
                                    frames.push_back(frame);
                                }
                            }
                        }
                        // Successful Synch
                        else if ((nextRNG & 1) == 0)
                        {
                            frame.leadType = Synchronize;
                            slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                            testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                            frame.seed = testSeed;
                            frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                            if (compare.compareSlot(frame))
                                frames.push_back(frame);
                        }
                        break;
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.nextUShort();
                nextRNG2 = testRNG.nextUShort();
            }
            while ((testPID % 25) != frame.nature);
        }
    }
    return frames;
}

// Returns vector of frames for Method Gales Shadows
vector<Frame3> Searcher3::searchMethodXD(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame3> frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<u32> seeds = euclidean.recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    // Need to setup Naturelock checking
    for (auto i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.setIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        forward.nextUInt();
        frame.setPID(forward.nextUShort(), forward.nextUShort());
        frame.seed = seeds[i] * 0xB9B33155 + 0xA170F641;
        if (compare.comparePID(frame))
        {
            switch (type)
            {
                case SingleLock:
                    if (natureLock.singleNL(frame.seed))
                    {
                        frames.push_back(frame);
                        continue;
                    }
                    break;
                case FirstShadow:
                    if (natureLock.firstShadowNormal(frame.seed))
                    {
                        frames.push_back(frame);
                        continue;
                    }
                    break;
                case SecondShadow:
                    if (natureLock.firstShadowUnset(frame.seed))
                    {
                        frame.lockReason = QObject::tr("First shadow unset");
                        frames.push_back(frame);
                        continue;
                    }
                    if (natureLock.firstShadowSet(frame.seed))
                    {
                        frame.lockReason = QObject::tr("First shadow set");
                        frames.push_back(frame);
                        continue;
                    }
                    if (natureLock.firstShadowShinySkip(frame.seed))
                    {
                        frame.lockReason = QObject::tr("Shiny Skip");
                        frames.push_back(frame);
                        continue;
                    }
                    break;
                case Salamence:
                    if (natureLock.salamenceUnset(frame.seed))
                    {
                        frame.lockReason = QObject::tr("First shadow unset");
                        frames.push_back(frame);
                        continue;
                    }
                    if (natureLock.salamenceSet(frame.seed))
                    {
                        frame.lockReason = QObject::tr("First shadow set");
                        frames.push_back(frame);
                        continue;
                    }
                    if (natureLock.salamenceShinySkip(frame.seed))
                    {
                        frame.lockReason = QObject::tr("Shiny Skip");
                        frames.push_back(frame);
                        continue;
                    }
                    break;
            }
        }

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.comparePID(frame))
        {
            frame.seed ^= 0x80000000;
            switch (type)
            {
                case SingleLock:
                    if (natureLock.singleNL(frame.seed))
                    {
                        frames.push_back(frame);
                    }
                    break;
                case FirstShadow:
                    if (natureLock.firstShadowNormal(frame.seed))
                    {
                        frames.push_back(frame);
                    }
                    break;
                case SecondShadow:
                    if (natureLock.firstShadowUnset(frame.seed))
                    {
                        frame.lockReason = QObject::tr("First shadow unset");
                        frames.push_back(frame);
                        continue;
                    }
                    if (natureLock.firstShadowSet(frame.seed))
                    {
                        frame.lockReason = QObject::tr("First shadow set");
                        frames.push_back(frame);
                        continue;
                    }
                    if (natureLock.firstShadowShinySkip(frame.seed))
                    {
                        frame.lockReason = QObject::tr("Shiny Skip");
                        frames.push_back(frame);
                    }
                    break;
                case Salamence:
                    if (natureLock.salamenceUnset(frame.seed))
                    {
                        frame.lockReason = QObject::tr("First shadow unset");
                        frames.push_back(frame);
                        continue;
                    }
                    if (natureLock.salamenceSet(frame.seed))
                    {
                        frame.lockReason = QObject::tr("First shadow set");
                        frames.push_back(frame);
                        continue;
                    }
                    if (natureLock.salamenceShinySkip(frame.seed))
                    {
                        frame.lockReason = QObject::tr("Shiny Skip");
                        frames.push_back(frame);
                    }
                    break;
            }
        }
    }
    return frames;
}

// Return vector of frames for Method XDColo
vector<Frame3> Searcher3::searchMethodXDColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame3> frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = euclidean.recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.setIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        forward.nextUInt();
        frame.setPID(forward.nextUShort(), forward.nextUShort());
        frame.seed = seeds[i] * 0xB9B33155 + 0xA170F641;
        if (compare.comparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.comparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method 1/2/4
vector<Frame3> Searcher3::searchMethod124(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame3> frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.setIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        if (frameType = Method2)
            backward.advanceFrames(1);
        frame.setPID(backward.nextUShort(), backward.nextUShort());
        frame.seed = backward.nextUInt();
        if (compare.comparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.comparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method 1 Reverse
vector<Frame3> Searcher3::searchMethod1Reverse(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame3> frames;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.recoverLower16BitsIV(first, second);
    auto size = seeds.size();
    u32 temp;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.setIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        temp = backward.nextUShort();
        frame.setPID(temp, backward.nextUShort());
        frame.seed = backward.nextUInt();
        if (compare.comparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.comparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Determines which generational method to return
vector<Frame3> Searcher3::search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    switch (frameType)
    {
        case Method1:
        case Method2:
        case Method4:
            return searchMethod124(hp, atk, def, spa, spd, spe);
        case Method1Reverse:
            return searchMethod1Reverse(hp, atk, def, spa, spd, spe);
        case MethodH1:
        case MethodH2:
        case MethodH4:
            return searchMethodH124(hp, atk, def, spa, spd, spe);
        case Colo:
            return searchMethodColo(hp, atk, def, spa, spd, spe);
        case XD:
            return searchMethodXD(hp, atk, def, spa, spd, spe);
        case XDColo:
            return searchMethodXDColo(hp, atk, def, spa, spd, spe);
        // case Channel:
        // Set to default to avoid compiler warning message
        default:
            return searchMethodChannel(hp, atk, def, spa, spd, spe);
    }
}

// Switches cache or euclidean to user defined method
void Searcher3::setup(Method method)
{
    frameType = method;

    if (frameType == XDColo || frameType == Channel || frameType == XD || frameType == Colo)
    {
        forward = XDRNG(0);
        backward = XDRNGR(0);
    }
    else
    {
        forward = PokeRNG(0);
        backward = PokeRNGR(0);
    }

    switch (frameType)
    {
        case Method1:
        case Method1Reverse:
        case MethodH1:
            cache.switchCache(Method1);
            break;
        case Method2:
        case MethodH2:
            cache.switchCache(Method2);
            break;
        case Method4:
        case MethodH4:
            cache.switchCache(Method4);
            break;
        case Colo:
        case XD:
        case XDColo:
            euclidean.switchEuclidean(XDColo);
            break;
        // case Channel:
        // Set to default to avoid compiler warning message
        default:
            euclidean.switchEuclidean(Channel);
            break;
    }
}

void Searcher3::setupNatureLock(int num)
{
    if (frameType == XD)
    {
        natureLock.switchLockGales(num);
    }
    else if (frameType == Colo)
    {
        natureLock.switchLockColo(num);
    }
    type = natureLock.getType();
    frame.lockReason = QObject::tr("Pass NL");
}
