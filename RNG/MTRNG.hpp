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

#ifndef MTRNG_HPP
#define MTRNG_HPP

#include <libPokeFinder/RNG/IRNG.hpp>

class MersenneTwister : public IRNG
{

private:
    static const u32 LOWERMASK = 0x7FFFFFFF;
    static const int M = 397;
    static const u32 MATRIXA = 0x9908B0DF;
    static const int N = 624;
    static const u32 UPPERMASK = 0x80000000;
    static const u32 TEMPERINGMASKB = 0x9D2C5680;
    static const u32 TEMPERINGMASKC = 0xEFC60000;
    const u32 mag01[2] = { 0x0, MATRIXA };
    u32 mt[624];
    int index;

    void initialize(u32 seed);
    void shuffle();
    inline u32 temperingShiftL(u32 y) { return (y >> 18); }
    inline u32 temperingShiftS(u32 y) { return (y << 7); }
    inline u32 temperingShiftT(u32 y) { return (y << 15); }
    inline u32 temperingShiftU(u32 y) { return (y >> 11); }

public:
    MersenneTwister(u32 seed);
    void advanceFrames(int frames) override;
    u32 nextUInt() override;
    void reseed(u32 seed) override;

};

class MersenneTwisterUntempered : public IRNG
{

private:
    static const int M = 397;
    static const int N = 624;
    static const u32 MATRIXA = 0x9908B0DF;
    static const u32 LOWERMASK = 0x7FFFFFFF;
    static const u32 UPPERMASK = 0x80000000;
    u32 mt[624];
    const u32 mag01[2] = { 0x0, MATRIXA };
    int index;

    void initialize(u32 seed);
    void shuffle();

public:
    MersenneTwisterUntempered(u32 seed);
    void advanceFrames(int frames) override;
    void reseed(u32 seed) override;
    u32 nextUInt() override;

};

class MersenneTwisterFast : public IRNG
{

private:
    static const int M = 397;
    static const int N = 624;
    static const u32 LOWERMASK = 0x7FFFFFFF;
    static const u32 MATRIXA = 0x9908B0DF;
    static const u32 TEMPERINGMASKB = 0x9D2C5680;
    static const u32 TEMPERINGMASKC2 = 0xEF000000;
    static const u32 UPPERMASK = 0x80000000;
    const u32 mag01[2] = { 0x0, MATRIXA };
    int max;
    int maxCalls;
    u32 mt[624];
    int index;

    void initialize(u32 seed);
    void shuffle();
    inline u32 temperingShiftS(u32 y) { return (y << 7); }
    inline u32 temperingShiftT(u32 y) { return (y << 15); }
    inline u32 temperingShiftU(u32 y) { return (y >> 11); }


public:
    MersenneTwisterFast(u32 seed, int calls);
    void advanceFrames(int frames) override;
    u32 nextUInt() override;
    void reseed(u32 seed) override;

};

#endif //MTRNG_HPP
