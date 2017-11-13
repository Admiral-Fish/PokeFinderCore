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

#ifndef RNGCACHE_HPP
#define RNGCACHE_HPP
#include <libPokeFinder/Objects/Method.hpp>
#include <cstdint>
#include <vector>
#include <unordered_map>

using namespace std;
typedef uint32_t u32;

class RNGCache
{

private:
    u32 add;
    u32 k;
    u32 mult;
    unordered_map<u32, u32> keys;

    void populateMap();

    void setupCache(Method MethodType);

public:

    RNGCache(Method MethodType);

    vector<u32> RecoverLower16BitsIV(u32 first, u32 second);

    vector<u32> RecoverLower16BitsPID(u32 first, u32 second);

    void SwitchCache(Method MethodType);

};

#endif // RNGCACHE_HPP
