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

#include "LCRNG64.hpp"

// LCRNG64 constructor that sets a given seed
LCRNG64::LCRNG64(u64 add, u64 mult,u64 seed)
{
    this->add = add;
    this->mult = mult;
    this->seed = seed;
}

// Method for advancing seed by a given number of frames
void LCRNG64::AdvanceFrames(int frames)
{
    for (int i = 0; i < frames; i++)
        seed = seed * mult + add;
}

// Method for finding next 32 bit seed
u32 LCRNG64::Next32Bit()
{
    return (u32) (Next64Bit() >> 32);
}

// Method for finding next modified 32 bit seed
u32 LCRNG64::Next32Bit(u32 max)
{
    return (u32) (((Next64Bit() >> 32) * max) >> 32);
}

// Method for finding next 64 bit seed
u64 LCRNG64::Next64Bit()
{
    seed = seed * mult + add;
    return seed;
}

// IRNG64 Member
u64 LCRNG64::Nextulong()
{
    return Next64Bit();
}

// IRNG64 Memeber
u32 LCRNG64::Nextuint()
{
    return Next32Bit();
}

// IRNG64 Member
void LCRNG64::Reseed(u64 seed)
{
    this->seed = seed;
}
