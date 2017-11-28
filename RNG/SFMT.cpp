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

#include "SFMT.hpp"

// Constructor for SFMT
SFMT::SFMT(u32 seed)
{
    init(seed);
}

// Initializes
void SFMT::init(u32 seed)
{
    sfmt[0] = seed;

    for (index = 1; index < N32; index++)
        sfmt[index] = 0x6C078965 * (sfmt[index - 1] ^ (sfmt[index - 1] >> 30)) + index;

    periodCertificaion();
    Shuffle();
}

// Verify internal state vector
void SFMT::periodCertificaion()
{
    u32 inner = 0;
    u32 work;
    int i, j;

    for (i = 0; i < 4; i++)
        inner ^= sfmt[i] & parity[i];
    for (i = 16; i > 0; i >>= 1)
        inner ^= inner >> i;
    inner &= 1;
    if (inner == 1)
        return;

    for (i = 0; i < 4; i++)
    {
        work = 1;
        for (j = 0; j < 32; j++)
        {
            if ((work & parity[i]) != 0)
            {
                sfmt[i] ^= work;
                return;
            }
            work <<= 1;
        }
    }
}

// Advances by n frames shuffling the correct amount of times
void SFMT::AdvanceFrames(int frames)
{
    int temp = index + (frames * 2);
    while (temp >= 624)
    {
        temp -= 624;
        Shuffle();
    }
    index = temp;
}

// Generates the next psuedo random number
u32 SFMT::Nextuint()
{
    // Array reshuffle check
    if (index >= N32)
    {
        Shuffle();
        index = 0;
    }
    ++index;
    return getRand();
}

// Generates the next 64bit psuedo random number
u64 SFMT::Nextulong()
{
    // Array reshuffle check
    if (index >= N32)
    {
        Shuffle();
        index = 0;
    }
    return getRand() | ((u64)getRand() << 32);
}

// Recreates the SFMT with a new seed
void SFMT::Reseed(u64 seed)
{
    init((u32)seed);
}

// Shuffles the array once all 624 states have been used
void SFMT::Shuffle()
{
    int a = 0;
    int b = 488;
    int c = 616;
    int d = 620;
    do
    {
        sfmt[a + 3] = sfmt[a + 3] ^ (sfmt[a + 3] << 8) ^ (sfmt[a + 2] >> 24) ^ (sfmt[c + 3] >> 8) ^ ((sfmt[b + 3] >> CSR1) & CMSK4) ^ (sfmt[d + 3] << CSL1);
        sfmt[a + 2] = sfmt[a + 2] ^ (sfmt[a + 2] << 8) ^ (sfmt[a + 1] >> 24) ^ (sfmt[c + 3] << 24) ^ (sfmt[c + 2] >> 8) ^ ((sfmt[b + 2] >> CSR1) & CMSK3) ^ (sfmt[d + 2] << CSL1);
        sfmt[a + 1] = sfmt[a + 1] ^ (sfmt[a + 1] << 8) ^ (sfmt[a] >> 24) ^ (sfmt[c + 2] << 24) ^ (sfmt[c + 1] >> 8) ^ ((sfmt[b + 1] >> CSR1) & CMSK2) ^ (sfmt[d + 1] << CSL1);
        sfmt[a] = sfmt[a] ^ (sfmt[a] << 8) ^ (sfmt[c + 1] << 24) ^ (sfmt[c] >> 8) ^ ((sfmt[b] >> CSR1) & CMSK1) ^ (sfmt[d] << CSL1);
        c = d;
        d = a;
        a += 4;
        b += 4;
        if (b >= N32)
            b = 0;
    }
    while (a < N32);
}
