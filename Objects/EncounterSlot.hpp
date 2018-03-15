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

#ifndef ENCOUNTERSLOT_HPP
#define ENCOUNTERSLOT_HPP

#include <libPokeFinder/Objects/Encounter.hpp>
#include <cstdint>
#include <vector>

using std::vector;
typedef uint32_t u32;

class Range
{

private:
    u32 max;
    u32 min;

public:
    Range(u32 min, u32 max);
    u32 getMax();
    u32 getMin();

};

class EncounterSlot
{

private:
    static int calcSlot(u32 compare, vector<Range> ranges);

public:
    static int hSlot(u32 result, Encounter encounterType);
    static int jSlot(u32 result, Encounter encounterType);
    static int kSlot(u32 result, Encounter encounterType);
};

#endif // ENCOUNTERSLOT_HPP
