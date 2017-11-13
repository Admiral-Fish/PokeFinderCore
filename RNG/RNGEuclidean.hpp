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

#ifndef RNGEUCLIDEAN_HPP
#define RNGEUCLIDEAN_HPP
#include <libPokeFinder/Objects/Method.hpp>
#include <cstdint>
#include <vector>

using namespace std;
typedef uint64_t u64;
typedef uint32_t u32;

class RNGEuclidean
{

private:
    const u32 ADD = 0x269EC3;
    const u32 MULT = 0x343FD;
    u64 base;
    u64 sub1;
    u64 sub2;

    void setupEuclidean(Method FrameType);

public:

    RNGEuclidean(Method FrameType);

    vector<u32> RecoverLower16BitsIV(u32 first, u32 second);

    vector<u32> RecoverLower16BitsPID(u32 first, u32 second);

    vector<u32> RecoverLower27BitsChannel(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);

    void SwitchEuclidean(Method FrameType);

};

#endif // RNGEUCLIDEAN_HPP
