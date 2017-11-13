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

#ifndef LCRNG64_HPP
#define LCRNG64_HPP

#include <libPokeFinder/RNG/IRNG64.hpp>

class LCRNG64 : IRNG64
{

private:
    u64 add;
    u64 addr;
    u64 mult;
    u64 multr;

public:
    u64 seed;

    LCRNG64(u64 add, u64 addr, u64 mult, u64 multr, u64 seed);

    void AdvanceFrames(int frames);

    u32 Next32Bit();

    u32 Next32Bit(u32 max);

    u64 Next64Bit();

    u32 Prev32Bit();

    u32 Prev32Bit(u32 max);

    u64 Prev64Bit();

    void ReverseFrames(int frames);

    virtual u64 Nextulong();

    virtual u32 Nextuint();

    virtual void Reseed(u64 seed);

};

class BWRNG : public LCRNG64
{

public:

    BWRNG(u64 seed) : LCRNG64(0x269ec3, 0x9b1ae6e9a384e6f9, 0x5d588b656c078965, 0xdedcedae9638806d, seed)
    {
    }

};

#endif // LCRNG64_HPP
