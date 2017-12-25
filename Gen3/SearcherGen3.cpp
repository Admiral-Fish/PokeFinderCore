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

#include "SearcherGen3.hpp"

// Default constructor
SearcherGen3::SearcherGen3()
{
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
    frame.SetIDs(tid, sid, psv);
}

// Constructor given user defined parameters
SearcherGen3::SearcherGen3(uint tid, uint sid)
{
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    frame.SetIDs(tid, sid, psv);
}

// Returns vector of frames for Channel Method
vector<FrameGen3> SearcherGen3::searchMethodChannel(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    vector<uint> seeds = euclidean.RecoverLower27BitsChannel(hp, atk, def, spa, spd, spe);
    int size = seeds.size();

    for (int i = 0; i < size; i++)
    {
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];

        // Calculate PID
        backward.AdvanceFrames(3);
        uint pid2 = backward.Next16Bit();
        uint pid1 = backward.Next16Bit();

        // Determine if PID needs to be XORed
        if ((pid2 > 7 ? 0 : 1) != (pid1 ^ backward.Next16Bit() ^ 40122))
            pid1 ^= 0x8000;
        frame.SetPID(pid1, pid2);

        if (compare.ComparePID(frame))
        {
            frame.seed = backward.Next32Bit();
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method Colo Shadows
vector<FrameGen3> SearcherGen3::searchMethodColo(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = euclidean.RecoverLower16BitsIV(first, second);
    int size = seeds.size();

    // Need to eventually add Naturelock checking
    for (int i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        forward.AdvanceFrames(1);
        frame.SetPID(forward.Next16Bit(), forward.Next16Bit());
        frame.seed = seeds[i] * 0xB9B33155 + 0xA170F641;
        if (compare.ComparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.ComparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method H1
vector<FrameGen3> SearcherGen3::searchMethodH1(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    int size = seeds.size();
    uint seed;

    for (int i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        frame.SetPID(backward.Next16Bit(), backward.Next16Bit());
        seed = backward.Next32Bit();

        // Use for loop to check both normal and sister spread
        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.pid ^= 0x80008000;
                frame.nature = frame.pid % 25;
                seed ^= 0x80000000;
            }

            if (!compare.ComparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            uint testPID, slot, testSeed;
            uint nextRNG = seed >> 16;
            uint nextRNG2 = testRNG.Next16Bit();

            do
            {
                frame.leadType = None;

                // Check normal
                if ((nextRNG % 25) == frame.nature)
                {
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = seed;
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);
                    frames.push_back(frame);

                    slot = slot * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = testSeed * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = testSeed;
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);

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
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);
                    frames.push_back(frame);
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.Next16Bit();
                nextRNG2 = testRNG.Next16Bit();
            }
            while ((testPID % 25) != frame.nature);
        }
    }
    return frames;
}

// Returns vector of frames for Method H2
vector<FrameGen3> SearcherGen3::searchMethodH2(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    int size = seeds.size();
    uint seed;

    for (int i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        backward.AdvanceFrames(1);
        frame.SetPID(backward.Next16Bit(), backward.Next16Bit());
        seed = backward.Next16Bit();

        // Use for loop to check both normal and sister spread
        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.pid ^= 0x80008000;
                frame.nature = frame.pid % 25;
                seed ^= 0x80000000;
            }

            if (!compare.ComparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            uint testPID, slot, testSeed;
            uint nextRNG = seed >> 16;
            uint nextRNG2 = testRNG.Next16Bit();

            do
            {
                frame.leadType = None;

                // Check normal
                if ((nextRNG % 25) == frame.nature)
                {
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = seed;
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);
                    frames.push_back(frame);

                    slot = slot * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = testSeed * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = testSeed;
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);

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
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);
                    frames.push_back(frame);
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.Next16Bit();
                nextRNG2 = testRNG.Next16Bit();
            }
            while ((testPID % 25) != frame.nature);
        }
    }
    return frames;
}

// Returns vector of frames for Method H4
vector<FrameGen3> SearcherGen3::searchMethodH4(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    int size = seeds.size();
    uint seed;

    for (int i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        frame.SetPID(backward.Next16Bit(), backward.Next16Bit());
        seed = backward.Next32Bit();

        // Use for loop to check both normal and sister spread
        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                frame.pid ^= 0x80008000;
                frame.nature = frame.pid % 25;
                seed ^= 0x80000000;
            }

            if (!compare.ComparePID(frame))
                continue;

            LCRNG testRNG = PokeRNGR(seed);
            uint testPID, slot, testSeed;
            uint nextRNG = seed >> 16;
            uint nextRNG2 = testRNG.Next16Bit();

            do
            {
                frame.leadType = None;

                // Check normal
                if (nextRNG % 25 == frame.nature)
                {
                    slot = testRNG.seed * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = slot * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = seed;
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);
                    frames.push_back(frame);

                    slot = slot * 0xeeb9eb65 + 0xa3561a1;
                    testSeed = testSeed * 0xeeb9eb65 + 0xa3561a1;
                    frame.seed = testSeed;
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);

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
                    frame.encounterSlot = EncounterSlot::HSlot(slot >> 16, encounterType);
                    frames.push_back(frame);
                }

                testPID = (nextRNG << 16) | nextRNG2;
                nextRNG = testRNG.Next16Bit();
                nextRNG2 = testRNG.Next16Bit();
            }
            while ((testPID % 25) != frame.nature);
        }
    }
    return frames;
}

// Returns vector of frames for Method Gales Shadows
vector<FrameGen3> SearcherGen3::searchMethodXD(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = euclidean.RecoverLower16BitsIV(first, second);
    int size = seeds.size();

    // Need to setup Naturelock checking
    for (int i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        frame.SetPID(forward.Next16Bit(), forward.Next16Bit());
        frame.seed = seeds[i] * 0xB9B33155 + 0xA170F641;
        if (compare.ComparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.ComparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Return vector of frames for Method XDColo
vector<FrameGen3> SearcherGen3::searchMethodXDColo(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = euclidean.RecoverLower16BitsIV(first, second);
    int size = seeds.size();

    for (int i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        frame.SetPID(forward.Next16Bit(), forward.Next16Bit());
        frame.seed = seeds[i] * 0xB9B33155 + 0xA170F641;
        if (compare.ComparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.ComparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method 1
vector<FrameGen3> SearcherGen3::searchMethod1(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    int size = seeds.size();

    for (int i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        frame.SetPID(backward.Next16Bit(), backward.Next16Bit());
        frame.seed = backward.Next32Bit();
        if (compare.ComparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.ComparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method 2
vector<FrameGen3> SearcherGen3::searchMethod2(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    int size = seeds.size();

    for (int i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        backward.AdvanceFrames(1);
        frame.SetPID(backward.Next16Bit(), backward.Next16Bit());
        frame.seed = backward.Next32Bit();
        if (compare.ComparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.ComparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method 4
vector<FrameGen3> SearcherGen3::searchMethod4(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<FrameGen3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    int size = seeds.size();

    for (int i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        frame.SetPID(backward.Next16Bit(), backward.Next16Bit());
        frame.seed = backward.Next32Bit();
        if (compare.ComparePID(frame))
            frames.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        if (compare.ComparePID(frame))
        {
            frame.seed ^= 0x80000000;
            frames.push_back(frame);
        }
    }
    return frames;
}

// Determines which generational method to return
vector<FrameGen3> SearcherGen3::Search(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
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
            cache.SwitchCache(Method1);
            return searchMethod1(hp, atk, def, spa, spd, spe, compare);
        case Method2:
            cache.SwitchCache(Method2);
            return searchMethod2(hp, atk, def, spa, spd, spe, compare);
        case Method4:
            cache.SwitchCache(Method4);
            return searchMethod4(hp, atk, def, spa, spd, spe, compare);
        case MethodH1:
            cache.SwitchCache(Method1);
            return searchMethodH1(hp, atk, def, spa, spd, spe, compare);
        case MethodH2:
            cache.SwitchCache(Method2);
            return searchMethodH2(hp, atk, def, spa, spd, spe, compare);
        case MethodH4:
            cache.SwitchCache(Method4);
            return searchMethodH4(hp, atk, def, spa, spd, spe, compare);
        case Colo:
            euclidean.SwitchEuclidean(Colo);
            return searchMethodColo(hp, atk, def, spa, spd, spe, compare);
        case XD:
            euclidean.SwitchEuclidean(XD);
            return searchMethodXD(hp, atk, def, spa, spd, spe, compare);
        case XDColo:
            euclidean.SwitchEuclidean(XDColo);
            return searchMethodXDColo(hp, atk, def, spa, spd, spe, compare);
        // case Channel:
        // Set to default to avoid compiler warning message
        default:
            euclidean.SwitchEuclidean(Channel);
            return searchMethodChannel(hp, atk, def, spa, spd, spe, compare);
    }
}

// Switches cache or euclidean to user defined method
void SearcherGen3::SetMethod(Method frameType)
{
    switch (frameType)
    {
        case Method1:
        case MethodH1:
            cache.SwitchCache(Method1);
            break;
        case Method2:
        case MethodH2:
            cache.SwitchCache(Method2);
            break;
        case Method4:
        case MethodH4:
            cache.SwitchCache(Method4);
            break;
        case Colo:
        case XD:
        case XDColo:
            euclidean.SwitchEuclidean(XDColo);
            break;
        // case Channel:
        // Set to default to avoid compiler warning message
        default:
            euclidean.SwitchEuclidean(Channel);
            break;
    }
}
