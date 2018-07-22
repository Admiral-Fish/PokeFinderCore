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

#ifndef TINYMT_HPP
#define TINYMT_HPP

#include <PokeFinderCore/RNG/IRNG.hpp>

class TinyMT : public IRNG
{

private:
    static const u32 MAT1 = 0x8f7011ee;
    static const u32 MAT2 = 0xfc78ff1f;
    static const u32 TMAT = 0x3793fdff;
    static const u32 TINYMT32MASK = 0x7FFFFFFF;
    static const int TINYMT32SH0 = 1;
    static const int TINYMT32SH1 = 10;
    static const int TINYMT32SH8 = 8;
    u32 *state = nullptr;
    u32 seed;

    void initialize(u32 seed);
    void periodCertification();

public:
    TinyMT(u32 seed);
    TinyMT(u32 st[]);
    ~TinyMT() override { delete state; }
    void advanceFrames(u32 frames) override;
    void nextState();
    u32 nextUInt() override;
    u16 nextUShort() override;
    u32 temper();
    void setSeed(u32 seed) override;
    u32 getSeed() override;
    u32 *getState();

};

#endif // TINYMT_HPP
