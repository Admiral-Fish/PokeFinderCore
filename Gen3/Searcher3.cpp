/*
 * This file is part of libPokéFinder
 * Copyright (C) 2017 by Admiral_Fish and bumba
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
Searcher3::Searcher3(u16 tid, u16 sid, u32 ratio)
{
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    frame.setIDs(tid, sid, psv);
    frame.genderRatio = ratio;
}

// Returns vector of frames for Channel Method
vector<Frame3> Searcher3::searchMethodChannel(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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
vector<Frame3> Searcher3::searchMethodColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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

// Returns vector of frames for Method H1
vector<Frame3> Searcher3::searchMethodH1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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
                frame.leadType = None;

                // Check normal
                if ((nextRNG % 25) == frame.nature)
                {
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = seed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                    frames.push_back(frame);

                    slot = slot * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = testSeed * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = testSeed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);

                    // Check failed synch
                    if ((nextRNG2 & 1) == 1)
                    {
                        frame.leadType = Synchronize;
                        frames.push_back(frame);
                    }

                    // Check Cute Charm
                    if ((nextRNG2 % 3) > 0)
                    {
                        frame.leadType = CuteCharm;
                        frames.push_back(frame);
                    }
                }
                // Check synch
                else if ((nextRNG & 1) == 0)
                {
                    frame.leadType = Synchronize;
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = testSeed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                    frames.push_back(frame);
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

// Returns vector of frames for Method H2
vector<Frame3> Searcher3::searchMethodH2(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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
        backward.advanceFrames(1);
        frame.setPID(backward.nextUShort(), backward.nextUShort());
        seed = backward.nextUShort();

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
                frame.leadType = None;

                // Check normal
                if ((nextRNG % 25) == frame.nature)
                {
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = seed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                    frames.push_back(frame);

                    slot = slot * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = testSeed * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = testSeed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);

                    // Check failed synch
                    if ((nextRNG2 & 1) == 1)
                    {
                        frame.leadType = Synchronize;
                        frames.push_back(frame);
                    }

                    // Check Cute Charm
                    if ((nextRNG2 % 3) > 0)
                    {
                        frame.leadType = CuteCharm;
                        frames.push_back(frame);
                    }
                }
                // Check synch
                else if ((nextRNG2 & 1) == 0)
                {
                    frame.leadType = Synchronize;
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = testSeed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                    frames.push_back(frame);
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

// Returns vector of frames for Method H4
vector<Frame3> Searcher3::searchMethodH4(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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
                frame.leadType = None;

                // Check normal
                if (nextRNG % 25 == frame.nature)
                {
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = seed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                    frames.push_back(frame);

                    slot = slot * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = testSeed * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = testSeed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);

                    // Check failed synch
                    if ((nextRNG2 & 1) == 1)
                    {
                        frame.leadType = Synchronize;
                        frames.push_back(frame);
                    }

                    // Check Cute Charm
                    if ((nextRNG2 % 3) > 0)
                    {
                        frame.leadType = CuteCharm;
                        frames.push_back(frame);
                    }
                }

                // Check synch
                if ((nextRNG2 & 1) == 0)
                {
                    frame.leadType = Synchronize;
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = seed;
                    frame.encounterSlot = EncounterSlot::hSlot(slot >> 16, encounterType);
                    frames.push_back(frame);
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
vector<Frame3> Searcher3::searchMethodXD(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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
vector<Frame3> Searcher3::searchMethodXDColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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

// Returns vector of frames for Method 1
vector<Frame3> Searcher3::searchMethod1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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

// Returns vector of frames for Method 2
vector<Frame3> Searcher3::searchMethod2(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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

// Returns vector of frames for Method 4
vector<Frame3> Searcher3::searchMethod4(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
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

// Determines which generational method to return
vector<Frame3> Searcher3::search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare)
{
    switch (frameType)
    {
        case Method1:
            return searchMethod1(hp, atk, def, spa, spd, spe, compare);
        case Method2:
            return searchMethod2(hp, atk, def, spa, spd, spe, compare);
        case Method4:
            return searchMethod4(hp, atk, def, spa, spd, spe, compare);
        case MethodH1:
            return searchMethodH1(hp, atk, def, spa, spd, spe, compare);
        case MethodH2:
            return searchMethodH2(hp, atk, def, spa, spd, spe, compare);
        case MethodH4:
            return searchMethodH4(hp, atk, def, spa, spd, spe, compare);
        case Colo:
            return searchMethodColo(hp, atk, def, spa, spd, spe, compare);
        case XD:
            return searchMethodXD(hp, atk, def, spa, spd, spe, compare);
        case XDColo:
            return searchMethodXDColo(hp, atk, def, spa, spd, spe, compare);
        // case Channel:
        // Set to default to avoid compiler warning message
        default:
            return searchMethodChannel(hp, atk, def, spa, spd, spe, compare);
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
