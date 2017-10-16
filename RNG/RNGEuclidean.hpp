/*
 * This file is part of PokéFinder
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

class RNGEuclidean
{

private:
    const uint32_t ADD = 0x269EC3;
    const uint32_t MULT = 0x343FD;
    uint64_t base;
    uint64_t sub1;
    uint64_t sub2;

    void setupEuclidean(Method FrameType);

public:

    RNGEuclidean(Method FrameType);

    std::vector<uint32_t> RecoverLower16BitsIV(uint32_t first, uint32_t second);

    std::vector<uint32_t> RecoverLower16BitsPID(uint32_t first, uint32_t second);

    std::vector<uint32_t> RecoverLower27BitsChannel(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe);

    void SwitchEuclidean(Method FrameType);

};

#endif // RNGEUCLIDEAN_HPP
