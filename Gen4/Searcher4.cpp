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
Searcher4::Searcher4(u16 tid, u16 sid, u32 ratio, FrameCompare compare, Method method)
{
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    this->compare = compare;
    frame.setIDs(tid, sid, psv);
    frame.genderRatio = ratio;
    frameType = method;
}

vector<Frame4> Searcher4::search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    switch (frameType)
    {
        case Method1:
            return searchMethod1(hp, atk, def, spa, spd, spe);
        case MethodJ:
            return searchMethodJ(hp, atk, def, spa, spd, spe);
        case MethodK:
            return searchMethodK(hp, atk, def, spa, spd, spe);
        case ChainedShiny:
            return searchChainedShiny(hp, atk, def, spa, spd, spe);
        default:
            return vector<Frame4>();
    }
}

vector<Frame4> Searcher4::searchMethod1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame4> results;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    frame.setIVsManual(hp, atk, def, spa, spd, spe);

    vector<uint> seeds = cache.recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // Setup normal frame
        backward.seed = seeds[i];
        frame.setPID(backward.nextUShort(), backward.nextUShort());
        frame.seed = backward.nextUInt();
        //if (compare.comparePID(frame))
        results.push_back(frame);

        // Setup XORed frame
        frame.pid ^= 0x80008000;
        frame.nature = frame.pid % 25;
        //if (compare.comparePID(frame))
        //{
        frame.seed ^= 0x80000000;
        results.push_back(frame);
        // }
    }

    vector<Frame4> frames;

    for (Frame4 result : results)
    {
        backward.seed = result.seed;

        for (u32 cnt = 1; cnt < maxFrame; cnt++)
        {
            u32 test = backward.seed;

            u32 hour = (test >> 16) & 0xFF;
            u32 delay = test & 0xFFFF;

            // Check if seed matches a valid gen 4 format
            if (hour < 23 && delay > minDelay && delay < maxDelay)
            {
                // Check if within user specific frame range
                if (cnt >= minFrame)
                {
                    result.seed = test;
                    result.frame = cnt;
                    frames.push_back(result);
                }
            }

            backward.nextUInt();
        }
    }

    return frames;
}

vector<Frame4> Searcher4::searchMethodJ(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame4> results;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    frame.setIVsManual(hp, atk, def, spa, spd, spe);

    vector<uint> seeds = cache.recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // TODO
    }

    vector<Frame4> frames;

    // Filter out by user specific min/max frame/delay
    for (Frame4 result : results)
    {
        backward.seed = result.seed;

        for (u32 cnt = 1; cnt < maxFrame; cnt++)
        {
            u32 test = backward.seed;

            u32 hour = (test >> 16) & 0xFF;
            u32 delay = test & 0xFFFF;

            // Check if seed matches a valid gen 4 format
            if (hour < 23 && delay > minDelay && delay < maxDelay)
            {
                // Check if within user specific frame range
                if (cnt >= minFrame)
                {
                    result.seed = test;
                    result.frame = cnt;
                    frames.push_back(result);
                }
            }

            backward.nextUInt();
        }
    }

    return frames;
}

vector<Frame4> Searcher4::searchMethodK(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame4> results;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    frame.setIVsManual(hp, atk, def, spa, spd, spe);

    vector<uint> seeds = cache.recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    for (auto i = 0; i < size; i++)
    {
        // TODO
    }

    vector<Frame4> frames;

    // Filter out by user specific min/max frame/delay
    for (Frame4 result : results)
    {
        backward.seed = result.seed;

        for (u32 cnt = 1; cnt < maxFrame; cnt++)
        {
            u32 test = backward.seed;

            u32 hour = (test >> 16) & 0xFF;
            u32 delay = test & 0xFFFF;

            // Check if seed matches a valid gen 4 format
            if (hour < 23 && delay > minDelay && delay < maxDelay)
            {
                // Check if within user specific frame range
                if (cnt >= minFrame)
                {
                    result.seed = test;
                    result.frame = cnt;
                    frames.push_back(result);
                }
            }

            backward.nextUInt();
        }
    }

    return frames;
}

vector<Frame4> Searcher4::searchChainedShiny(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe)
{
    vector<Frame4> results;

    u32 first = (hp | (atk << 5) | (def << 10)) << 16;
    u32 second = (spe | (spa << 5) | (spd << 10)) << 16;
    frame.setIVsManual(hp, atk, def, spa, spd, spe);

    vector<uint> seeds = cache.recoverLower16BitsIV(first, second);
    auto size = seeds.size();

    u32 calls[15];
    u32 low, high;

    for (auto i = 0; i < size; i++)
    {
        backward.seed = seeds[i];

        for (int i = 0; i < 15; i++)
            calls[i] = backward.nextUShort();

        low = chainedPIDLow(calls[14], calls[0], calls[1], calls[2], calls[3], calls[4], calls[5], calls[6], calls[7], calls[8], calls[9], calls[10], calls[11], calls[12]);
        high = chainedPIDHigh(calls[13], low, tid, sid);
        frame.setPID(low, high);

        //if (!compare.comparePID(frame))
        backward.nextUInt();
        frame.seed = backward.nextUInt();
        results.push_back(frame);
        frame.seed ^= 0x80000000;
        results.push_back(frame);
    }

    vector<Frame4> frames;

    // Filter out by user specific min/max frame/delay
    for (Frame4 result : results)
    {
        backward.seed = result.seed;

        for (u32 cnt = 1; cnt <= maxFrame; cnt++)
        {
            u32 test = backward.seed;

            u32 hour = (test >> 16) & 0xFF;
            u32 delay = test & 0xFFFF;

            // Check if seed matches a valid gen 4 format
            if (hour < 24 && delay > minDelay && delay < maxDelay)
            {
                // Check if within user specific frame range
                if (cnt >= minFrame)
                {
                    result.seed = test;
                    result.frame = cnt;
                    frames.push_back(result);
                }
            }

            backward.nextUInt();
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
    return ((low ^ tid ^ sid) & 0xFFF8 | high & 0x7);
}
