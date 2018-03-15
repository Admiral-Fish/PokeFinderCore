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

#include "MTRNG.hpp"

// Mersenne Twister

// Constructor for Mersenne Twister
MersenneTwister::MersenneTwister(u32 seed)
{
    initialize(seed);
}

void MersenneTwister::advanceFrames(int frames)
{
    index += frames;
    while (index >= 624)
    {
        index -= 624;
        shuffle();
    }
}

// Initializes
void MersenneTwister::initialize(u32 seed)
{
    mt[0] = seed;

    for (index = 1; index < N; index++)
        mt[index] = (0x6C078965 * (mt[index - 1] ^ (mt[index - 1] >> 30)) + index);
}

void MersenneTwister::shuffle()
{
    u32 y;
    int kk = 0;

    for (; kk < 227; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
    }

    for (; kk < 623; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk - 227] ^ (y >> 1) ^ mag01[y & 0x1];
    }

    y = (mt[623] & UPPERMASK) | (mt[0] & LOWERMASK);
    mt[623] = mt[396] ^ (y >> 1) ^ mag01[y & 0x1];
}

// Calls the next psuedo-random number
u32 MersenneTwister::nextUInt()
{
    // Array reshuffle check
    if (index >= N)
    {
        shuffle();
        index = 0;
    }

    u32 y = mt[index++];
    y ^= temperingShiftU(y);
    y ^= temperingShiftS(y) & TEMPERINGMASKB;
    y ^= temperingShiftT(y) & TEMPERINGMASKC;
    y ^= temperingShiftL(y);

    return y;
}

// Recreates the Mersenne Twister with a new seed
void MersenneTwister::reseed(u32 seed)
{
    initialize(seed);
}


// Mersenne Twister Untempered

// Constructor for Mersenne Twister Untempered
MersenneTwisterUntempered::MersenneTwisterUntempered(u32 seed)
{
    initialize(seed);
}

void MersenneTwisterUntempered::advanceFrames(int frames)
{
    index += frames;
    while (index >= 624)
    {
        index -= 624;
        shuffle();
    }
}

// Initializes
void MersenneTwisterUntempered::initialize(u32 seed)
{
    mt[0] = seed;

    for (index = 1; index < N; index++)
        mt[index] = (0x6C078965 * (mt[index - 1] ^ (mt[index - 1] >> 30)) + index);
}

void MersenneTwisterUntempered::shuffle()
{
    int kk = 0;
    u32 y;

    for (; kk < 227; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
    }

    for (; kk < 623; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk - 227] ^ (y >> 1) ^ mag01[y & 0x1];
    }

    y = (mt[623] & UPPERMASK) | (mt[0] & LOWERMASK);
    mt[623] = mt[396] ^ (y >> 1) ^ mag01[y & 0x1];
}

// Calls the next psuedo-random number
u32 MersenneTwisterUntempered::nextUInt()
{
    // Array reshuffle check
    if (index >= N)
    {
        shuffle();
        index = 0;
    }

    return mt[index++];
}

// Recreates the Mersenne Twister Untempered with a new seed
void MersenneTwisterUntempered::reseed(u32 seed)
{
    initialize(seed);
}


// Mersenne Twister Fast

// Constructor for Mersenne Twister Fast
MersenneTwisterFast::MersenneTwisterFast(u32 seed, int calls)
{
    maxCalls = calls;

    if (maxCalls > 227)
    {
        return;
        //Throw an error eventually
    }
    max = M + maxCalls;
    initialize(seed);
}

void MersenneTwisterFast::advanceFrames(int frames)
{
    index += frames;
    while (index >= max)
    {
        index -= max;
        shuffle();
    }
}

// Initializes
void MersenneTwisterFast::initialize(u32 seed)
{
    mt[0] = seed;

    for (index = 1; index < max; ++index)
        mt[index] = (0x6C078965 * (mt[index - 1] ^ (mt[index - 1] >> 30)) + index);
}

void MersenneTwisterFast::shuffle()
{
    u32 y;
    int kk = 0;

    for (; kk < maxCalls; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
    }
}

// Calls the next psuedo-random number
u32 MersenneTwisterFast::nextUInt()
{
    // Array reshuffle check
    if (index >= max)
    {
        shuffle();
        index = 0;
    }

    u32 y = mt[index++];
    y ^= temperingShiftU(y);
    y ^= temperingShiftS(y) & TEMPERINGMASKB;
    y ^= temperingShiftT(y) & TEMPERINGMASKC2;

    return y;
}

// Recreates the Mersenne Twister Fast with a new seed
void MersenneTwisterFast::reseed(u32 seed)
{
    initialize(seed);
}
