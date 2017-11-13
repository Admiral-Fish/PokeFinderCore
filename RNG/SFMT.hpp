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

#ifndef SFMT_HPP
#define SFMT_HPP

#include <libPokeFinder/RNG/IRNG64.hpp>

class SFMT : public IRNG64
{

private:
    u32 const CMSK1 = 0xdfffffef;
    u32 const CMSK2 = 0xddfecb7f;
    u32 const CMSK3 = 0xbffaffff;
    u32 const CMSK4 = 0xbffffff6;
    int const CSL1 = 18;
    int const CSR1 = 11;
    int const N32 = 624;
    int index;
    u32 parity[4] = { 0x1, 0x0, 0x0, 0x13c9e684 };
    u32 sfmt[624];

    void init(u32 seed);

    void periodCertificaion();

    inline u32 getRand() { return sfmt[index++]; }


public:

    SFMT(u32 seed);

    void AdvanceFrames(int n);

    virtual u32 Nextuint();

    virtual u64 Nextulong();

    virtual void Reseed(u32 seed);

    void Shuffle();

};

#endif // SFMT_HPP
