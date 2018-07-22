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

#include "MTRNG.hpp"

// Shared advance function
void MT::advanceFrames(u32 frames)
{
    index += frames;
    while (index >= 624)
    {
        index -= 624;
        shuffle();
    }
}

// Mersenne Twister

// Constructor for Mersenne Twister
MersenneTwister::MersenneTwister(u32 seed)
{
    mt = new u32[624];
    initialize(seed);
}

// Initializes
void MersenneTwister::initialize(u32 seed)
{
    this->seed = seed;
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

u16 MersenneTwister::nextUShort()
{
    return static_cast<u16>(nextUInt() >> 16);
}

// Recreates the Mersenne Twister with a new seed
void MersenneTwister::setSeed(u32 seed)
{
    initialize(seed);
}

u32 MersenneTwister::getSeed()
{
    return seed;
}


// Mersenne Twister Untempered

// Constructor for Mersenne Twister Untempered
MersenneTwisterUntempered::MersenneTwisterUntempered(u32 seed)
{
    mt = new u32[624];
    initialize(seed);
}

// Initializes
void MersenneTwisterUntempered::initialize(u32 seed)
{
    this->seed = seed;
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

u16 MersenneTwisterUntempered::nextUShort()
{
    return static_cast<u16>(nextUInt() >> 16);
}

// Recreates the Mersenne Twister Untempered with a new seed
void MersenneTwisterUntempered::setSeed(u32 seed)
{
    initialize(seed);
}

u32 MersenneTwisterUntempered::getSeed()
{
    return seed;
}


// Mersenne Twister Fast

// Constructor for Mersenne Twister Fast
MersenneTwisterFast::MersenneTwisterFast(u32 seed, u32 calls)
{
    maxCalls = calls;

    if (maxCalls > 227)
    {
        return;
        //Throw an error eventually
    }
    max = M + maxCalls;
    mt = new u32[max];
    initialize(seed);
}

// Initializes
void MersenneTwisterFast::initialize(u32 seed)
{
    this->seed = seed;
    mt[0] = seed;

    for (index = 1; index < max; ++index)
        mt[index] = (0x6C078965 * (mt[index - 1] ^ (mt[index - 1] >> 30)) + index);
}

void MersenneTwisterFast::shuffle()
{
    u32 y;

    for (u32 kk = 0; kk < maxCalls; ++kk)
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

u16 MersenneTwisterFast::nextUShort()
{
    return static_cast<u16>(nextUInt() >> 16);
}

// Recreates the Mersenne Twister Fast with a new seed
void MersenneTwisterFast::setSeed(u32 seed)
{
    initialize(seed);
}

u32 MersenneTwisterFast::getSeed()
{
    return seed;
}
