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

#ifndef LCRNG_HPP
#define LCRNG_HPP

#include <cstdint>
#include <libPokeFinder/RNG/IRNG.hpp>

class LCRNG : public IRNG
{

private:
    u32 add;
    u32 mult;

public:
    u32 seed;

    LCRNG(u32 add, u32 mult, u32 seed);

    virtual void AdvanceFrames(int frames);

    u32 Next16Bit();

    u32 Next32Bit();

    virtual u32 Nextuint();

    virtual void Reseed(u32 seed);

};

class ARNG : public LCRNG
{

public:

    ARNG(u32 seed) : LCRNG(0x01, 0x6c078965, seed)
    {
    }

};

class ARNGR : public LCRNG
{

public:

    ARNGR(u32 seed) : LCRNG(0x69c77f93, 0x9638806d, seed)
    {
    }

};

class PokeRNG : public LCRNG
{

public:

    PokeRNG(u32 seed) : LCRNG(0x6073, 0x41c64e6d, seed)
    {
    }

};

class PokeRNGR : public LCRNG
{

public:

    PokeRNGR(u32 seed) : LCRNG(0xa3561a1, 0xeeb9eb65, seed)
    {
    }

};

class XDRNG : public LCRNG
{

public:

    XDRNG(u32 seed) : LCRNG(0x269EC3, 0x343FD, seed)
    {
    }

};

class XDRNGR: public LCRNG
{

public:

    XDRNGR(u32 seed) : LCRNG(0xA170F641, 0xB9B33155, seed)
    {
    }

};

#endif //LCRNG_HPP
