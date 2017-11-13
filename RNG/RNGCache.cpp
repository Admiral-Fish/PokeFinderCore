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

#include "RNGCache.hpp"

// See https://crypto.stackexchange.com/a/10609 for how the following math works
// Uses a brute force meet in the middle attack using precomputated data

// Constructor for RNGCache
RNGCache::RNGCache(Method MethodType)
{
    setupCache(MethodType);
}

// Populates cache to use for brute forcing
void RNGCache::populateMap()
{
    for (u32 i = 0; i < 256; i++)
    {
        u32 right = mult * i + add;
        u32 val = right >> 16;

        keys[val] = i;
        keys[val - 1] = i;
    }
}

// Generates brute force cache based on which method is provided
void RNGCache::setupCache(Method MethodType)
{
    if (MethodType == Method4)
    {
        k = 0xa29a6900; // Mult * Mult << 8
        mult = 0xc2a29a69; // Mult * Mult
        add = 0xe97e7b6a; // Add * (Mult + 1)
    }
    // Method 1/2
    else
    {
        k = 0xc64e6d00; // Mult << 8
        mult = 0x41c64e6d; // pokerng constant
        add = 0x6073; // pokerng constant
    }

    populateMap();
}

// Recovers origin seeds for two 16 bit calls(15 bits known) with or without gap based on the cache
vector<u32> RNGCache::RecoverLower16BitsIV(u32 first, u32 second)
{
    vector<u32> origin;

    // Check with the top bit of the first call both
    // flipped and unflipped to account for only knowing 15 bits
    u32 search1 = second - first * mult;
    u32 search2 = second - (first ^ 0x80000000) * mult;
    unordered_map<u32, u32>::const_iterator locate;
    for (u32 i = 0; i < 256; i++, search1 -= k, search2 -= k)
    {
        locate = keys.find(search1 >> 16);
        if (locate != keys.end())
        {
            u32 test = first | (i << 8) | locate->second;
            // Verify IV calls line up
            if (((test * mult + add) & 0x7fff0000) == second)
                origin.push_back(test);
        }

        locate = keys.find(search2 >> 16);
        if (locate != keys.end())
        {
            u32 test = first | (i << 8) | locate->second;
            // Verify IV calls line up
            if (((test * mult + add) & 0x7fff0000) == second)
                origin.push_back(test);
        }
    }

    return origin;
}

// Recovers origin seeds for two 16 bit calls based on the cache
vector<u32> RNGCache::RecoverLower16BitsPID(u32 first, u32 second)
{
    vector<u32> origin;
    u32 search = second - first * mult;
    unordered_map<u32, u32>::const_iterator locate;
    for (u32 i = 0; i < 256; i++, search -= k)
    {
        locate = keys.find(search >> 16);
        if (locate != keys.end())
        {
            u32 test = first | (i << 8) | locate->second;
            // Verify PID calls line up
            if (((test * mult + add) & 0xffff0000) == second)
                origin.push_back(test);
        }
    }
    return origin;
}

// Switches cache being used
void RNGCache::SwitchCache(Method MethodType)
{
    setupCache(MethodType);
}
