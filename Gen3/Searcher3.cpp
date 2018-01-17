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
    frame.SetIDs(tid, sid, psv);
}

// Constructor given user defined parameters
Searcher3::Searcher3(uint tid, uint sid)
{
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    frame.SetIDs(tid, sid, psv);
}

// Returns vector of frames for Channel Method
vector<Frame3> Searcher3::SearchMethodChannel(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    vector<uint> seeds = euclidean.RecoverLower27BitsChannel(hp, atk, def, spa, spd, spe);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];

        // Calculate PID
        backward.AdvanceFrames(3);
        uint pid2 = backward.Nextushort();
        uint pid1 = backward.Nextushort();

        // Determine if PID needs to be XORed
        if ((pid2 > 7 ? 0 : 1) != (pid1 ^ backward.Nextushort() ^ 40122))
            pid1 ^= 0x8000;
        frame.SetPID(pid2, pid1);

        if (compare.ComparePID(frame))
        {
            frame.seed = backward.Nextuint();
            frames.push_back(frame);
        }
    }
    return frames;
}

// Returns vector of frames for Method Colo Shadows
vector<Frame3> Searcher3::SearchMethodColo(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = euclidean.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();

    // Need to eventually add Naturelock checking
    for (auto i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        forward.Nextuint();
        frame.SetPID(forward.Nextushort(), forward.Nextushort());
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
vector<Frame3> Searcher3::SearchMethodH1(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();
    uint seed;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        frame.SetPID(backward.Nextushort(), backward.Nextushort());
        seed = backward.Nextuint();

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
            uint nextRNG2 = testRNG.Nextushort();

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
                nextRNG = testRNG.Nextushort();
                nextRNG2 = testRNG.Nextushort();
            }
            while ((testPID % 25) != frame.nature);
        }
    }
    return frames;
}

// Returns vector of frames for Method H2
vector<Frame3> Searcher3::SearchMethodH2(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();
    uint seed;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        backward.AdvanceFrames(1);
        frame.SetPID(backward.Nextushort(), backward.Nextushort());
        seed = backward.Nextushort();

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
            uint nextRNG2 = testRNG.Nextushort();

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
                nextRNG = testRNG.Nextushort();
                nextRNG2 = testRNG.Nextushort();
            }
            while ((testPID % 25) != frame.nature);
        }
    }
    return frames;
}

// Returns vector of frames for Method H4
vector<Frame3> Searcher3::SearchMethodH4(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();
    uint seed;

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        frame.SetPID(backward.Nextushort(), backward.Nextushort());
        seed = backward.Nextuint();

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
            uint nextRNG2 = testRNG.Nextushort();

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
                nextRNG = testRNG.Nextushort();
                nextRNG2 = testRNG.Nextushort();
            }
            while ((testPID % 25) != frame.nature);
        }
    }
    return frames;
}

// Returns vector of frames for Method Gales Shadows
vector<Frame3> Searcher3::SearchMethodXD(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = euclidean.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();

    // Need to setup Naturelock checking
    for (auto i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        forward.Nextuint();
        frame.SetPID(forward.Nextushort(), forward.Nextushort());
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
vector<Frame3> Searcher3::SearchMethodXDColo(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = euclidean.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i += 2)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        forward.seed = seeds[i + 1];
        forward.Nextuint();
        frame.SetPID(forward.Nextushort(), forward.Nextushort());
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
vector<Frame3> Searcher3::SearchMethod1(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        frame.SetPID(backward.Nextushort(), backward.Nextushort());
        frame.seed = backward.Nextuint();
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
vector<Frame3> Searcher3::SearchMethod2(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        backward.AdvanceFrames(1);
        frame.SetPID(backward.Nextushort(), backward.Nextushort());
        frame.seed = backward.Nextuint();
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
vector<Frame3> Searcher3::SearchMethod4(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    vector<Frame3> frames;

    uint first = (hp | (atk << 5) | (def << 10)) << 16;
    uint second = (spe | (spa << 5) | (spd << 10)) << 16;
    vector<uint> seeds = cache.RecoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        frame.SetIVsManual(hp, atk, def, spa, spd, spe);
        backward.seed = seeds[i];
        frame.SetPID(backward.Nextushort(), backward.Nextushort());
        frame.seed = backward.Nextuint();
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
vector<Frame3> Searcher3::Search(uint hp, uint atk, uint def, uint spa, uint spd, uint spe, FrameCompare compare)
{
    switch (frameType)
    {
        case Method1:
            return SearchMethod1(hp, atk, def, spa, spd, spe, compare);
        case Method2:
            return SearchMethod2(hp, atk, def, spa, spd, spe, compare);
        case Method4:
            return SearchMethod4(hp, atk, def, spa, spd, spe, compare);
        case MethodH1:
            return SearchMethodH1(hp, atk, def, spa, spd, spe, compare);
        case MethodH2:
            return SearchMethodH2(hp, atk, def, spa, spd, spe, compare);
        case MethodH4:
            return SearchMethodH4(hp, atk, def, spa, spd, spe, compare);
        case Colo:
            return SearchMethodColo(hp, atk, def, spa, spd, spe, compare);
        case XD:
            return SearchMethodXD(hp, atk, def, spa, spd, spe, compare);
        case XDColo:
            return SearchMethodXDColo(hp, atk, def, spa, spd, spe, compare);
        // case Channel:
        // Set to default to avoid compiler warning message
        default:
            return SearchMethodChannel(hp, atk, def, spa, spd, spe, compare);
    }
}

// Switches cache or euclidean to user defined method
void Searcher3::Setup(Method method)
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
