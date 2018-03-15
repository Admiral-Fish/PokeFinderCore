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

#ifndef TINYMT_HPP
#define TINYMT_HPP

#include <libPokeFinder/RNG/IRNG.hpp>

class TinyMT : public IRNG
{

private:
    static const u32 MAT1 = 0x8f7011ee;
    static const u32 MAT2 = 0xfc78ff1f;
    static const int MINLOOP = 8;
    static const int PRELOOP = 8;
    static const u32 TMAT = 0x3793fdff;
    static const u32 TINYMT32MASK = 0x7FFFFFFF;
    static const int TINYMT32SH0 = 1;
    static const int TINYMT32SH1 = 10;
    static const int TINYMT32SH8 = 8;
    u32 state[4];

    void initialize(u32 seed);
    void periodCertification();

public:
    TinyMT(u32 seed);
    TinyMT(u32 st[]);
    void advanceFrames(int frames) override;
    void nextState();
    u32 nextUInt() override;
    u32 temper();
    void reseed(u32 seed) override;

};

#endif // TINYMT_HPP
