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

#include "TinyMT.hpp"

// Constructor
TinyMT::TinyMT(u32 seed)
{
    initialize(seed);
}

// Constructor given Tiny states
TinyMT::TinyMT(u32 st[])
{
    for (int i = 0; i < 4; i++)
        state[i] = st[i];
    periodCertification();
}

void TinyMT::advanceFrames(int frames)
{
    for (int i = 0; i < frames; i++)
        nextState();
}

// Creates Tiny state given seed
void TinyMT::initialize(u32 seed)
{
    state[0] = seed;
    state[1] = MAT1;
    state[2] = MAT2;
    state[3] = TMAT;

    int i;
    for (i = 1; i < MINLOOP; i++)
        state[i & 3] ^= i + 0x6c078965 * (state[(i - 1) & 3] ^ (state[(i - 1) & 3] >> 30));

    periodCertification();

    for (i = 0; i < PRELOOP; i++)
        nextState();
}

// Verifies not all 4 Tiny states are 0
void TinyMT::periodCertification()
{
    if (state[0] == 0 && state[1] == 0 && state[2] == 0 && state[3] == 0)
    {
        state[0] = 'T';
        state[1] = 'I';
        state[2] = 'N';
        state[3] = 'Y';
    }
}

// Generates the next Tiny state
void TinyMT::nextState()
{
    u32 y = state[3];
    u32 x = (state[0] & TINYMT32MASK) ^ state[1] ^ state[2];
    x ^= (x << TINYMT32SH0);
    y ^= (y >> TINYMT32SH0) ^ x;
    state[0] = state[1];
    state[1] = state[2];
    state[2] = x ^ (y << TINYMT32SH1);
    state[3] = y;

    if ((y & 1) == 1)
    {
        state[1] ^= MAT1;
        state[2] ^= MAT2;
    }
}

// Calls the next state and next psuedo random number
u32 TinyMT::nextUInt()
{
    nextState();
    return temper();
}

// Generates the psuedo random number from the Tiny state
u32 TinyMT::temper()
{
    u32 t0 = state[3];
    u32 t1 = state[0] + (state[2] >> TINYMT32SH8);

    t0 ^= t1;
    if ((t1 & 1) == 1)
        t0 ^= TMAT;
    return t0;
}

// IRNG Memeber
void TinyMT::reseed(u32 seed)
{
    initialize(seed);
}
