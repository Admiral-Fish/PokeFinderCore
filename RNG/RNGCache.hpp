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

#ifndef RNGCACHE_HPP
#define RNGCACHE_HPP
#include <libPokeFinder/Objects/Method.hpp>
#include <cstdint>
#include <vector>


class RNGCache
{

private:
    uint32_t add;
    bool flags[0x10000];
    uint32_t k;
    uint8_t low8[0x10000];
    uint32_t mult;

    void populateArrays();

    void setupCache(Method MethodType);

public:

    RNGCache(Method MethodType);

    std::vector<uint32_t> RecoverLower16BitsIV(uint32_t first, uint32_t second);

    std::vector<uint32_t> RecoverLower16BitsPID(uint32_t first, uint32_t second);

    void SwitchCache(Method MethodType);

};

#endif // RNGCACHE_HPP
