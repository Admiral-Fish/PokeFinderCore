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

#include "LCRNG.hpp"

// LCRNG is used for Gen 3 and 4

// Default constructor for LCRNG
LCRNG::LCRNG(u32 add, u32 mult, u32 seed)
{
    this->add = add;
    this->mult = mult;
    this->seed = seed;
}

// Method for advancing seed by a given number of frames
void LCRNG::AdvanceFrames(int frames)
{
    for(int i = 0; i < frames; i++)
        seed = seed * mult + add;
}

// Method for finding next 16 bit seed
u32 LCRNG::Next16Bit()
{
    return (Next32Bit() >> 16);
}

// Method for finding next 32 bit seed
u32 LCRNG::Next32Bit()
{
    seed = seed * mult + add;
    return seed;
}

// IRNG Member
u32 LCRNG::Nextuint()
{
    return Next32Bit();
}

// IRNG Member
void LCRNG::Reseed(u32 seed)
{
    this->seed = seed;
}
