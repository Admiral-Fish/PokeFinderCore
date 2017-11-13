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

#ifndef ENCOUNTERSLOT_HPP
#define ENCOUNTERSLOT_HPP
#include <libPokeFinder/Objects/Encounter.hpp>
#include <cstdint>
#include <vector>

using namespace std;
typedef uint32_t u32;

class Range
{
    
private:
    u32 max;
    u32 min;
    
public:

    Range(u32 min, u32 max);

    u32 GetMax();
    
    u32 GetMin();
    

};

class EncounterSlot
{
    
private:
    static int calcSlot(unsigned int compare, vector<Range> ranges);
    
public:

    static int HSlot(u32 result, Encounter encounterType);

    static int JSlot(u32 result, Encounter encounterType);
    
    static int KSlot(u32 result, Encounter encounterType);
};

#endif // ENCOUNTERSLOT_HPP
