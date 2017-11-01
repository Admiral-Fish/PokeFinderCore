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

#include "EncounterSlot.hpp"

/* Ranges are used alongside an RNG call to 
 * determine what encounter slot a frame will have
 */
 
// Constructor for Range
Range::Range(uint32_t min, uint32_t max)
{
    this->min = min;
    this->max = max;
}

// Gets current value of the max
uint32_t Range::GetMax()
{
    return max;
}

// Gets current value of the min
uint32_t Range::GetMin()
{
    return min;
}


// Encounter slot calculations

// Runs through ranges and compare value to get the encounter slot
int EncounterSlot::calcSlot(unsigned int compare, vector<Range> ranges)
{
    for (unsigned int i = 0; i < ranges.size(); i++)
        if (compare >= ranges[i].GetMin() && compare <= ranges[i].GetMax())
            return i;
    return -1;
}

// Calcs the encounter slot for Method H 1/2/4 (Emerald, FRLG, RS)
int EncounterSlot::HSlot(uint32_t result, Encounter encounterType)
{
    int compare = result % 100;
    vector<Range> ranges;
    switch(encounterType)
    {
        case OldRod:
            ranges = { Range(0, 69), Range(70, 99) } ;
            return calcSlot(compare, ranges);
        case GoodRod:
            ranges = { Range(0, 59), Range(60, 79), Range(80, 99) };
            return calcSlot(compare, ranges);
        case SuperRod:
            ranges = { Range(0, 39), Range(40, 69), Range(70, 84), Range(85, 94), Range(95, 99) };
            return calcSlot(compare, ranges);
        case Surfing:
            ranges = { Range(0, 59), Range(60, 89), Range(90, 94), Range(95, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
        default:
            ranges = { Range(0, 19), Range(20, 39), Range(40, 49), Range(50, 59), Range(60, 69), 
                        Range(70, 79), Range(80, 84), Range(85, 89), Range(90, 93), Range(94, 97), 
                        Range(98, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
    }
}

// Calcs the encounter slot for Method J (DPPt)
int EncounterSlot::JSlot(uint32_t result, Encounter encounterType)
{
    int compare = (result >> 16) / 656;
    vector<Range> ranges;
    switch (encounterType)
    {
        case GoodRod:
        case SuperRod:
            ranges = { Range(0, 39), Range(40, 79), Range(80, 94), Range(95, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
        case OldRod:
        case Surfing:
            ranges = { Range(0, 59), Range(60, 89), Range(90, 94), Range(95, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
        default:
            ranges = { Range(0, 19), Range(20, 39), Range(40, 49), Range(50, 59), Range(60, 69),
                        Range(70, 79), Range(80, 84), Range(85, 89), Range(90, 93), Range(94, 97),
                        Range(98, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
    }
}

// Calcs the encounter slot for Method K (HGSS)
int EncounterSlot::KSlot(uint32_t result, Encounter encounterType)
{
    int compare = (result >> 16) % 100;
    vector<Range> ranges;
    switch(encounterType)
    {
        case OldRod:
        case GoodRod:
        case SuperRod:
            ranges = { Range(0, 39), Range(40, 69), Range(70, 84), Range(85, 94), Range(95, 99) };
            return calcSlot(compare, ranges);
        case Surfing:
            ranges = { Range(0, 59), Range(60, 89), Range(90, 94), Range(95, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
        case BugCatchingContestPreDex:
        case BugCatchingContestTues:
            ranges = { Range(80, 99), Range(60, 79), Range(50, 59), Range(40, 49), Range(10, 14), 
                        Range(15, 19), Range(30, 39), Range(20, 29), Range(5, 9), Range(0, 4) };
            return calcSlot(compare, ranges);
        case BugCatchingContestThurs:
        case BugCatchingContestSat:
            ranges = { Range(80, 99), Range(50, 59), Range(60, 79), Range(40, 49), Range(30, 39), 
                        Range(20, 29), Range(15, 19), Range(10, 14), Range(5, 9), Range(0, 4) };
            return calcSlot(compare, ranges);
        case SafariZone:
            return (int) (compare % 10);
        case HeadButt:
            ranges = { Range(0, 49), Range(50, 64), Range(65, 79), Range(80, 89), Range(90, 94), 
                        Range(95, 99) };
            return calcSlot(compare, ranges);
        default:
            ranges = { Range(0, 19), Range(20, 39), Range(40, 49), Range(50, 59), Range(60, 69), 
                        Range(70, 79), Range(80, 84), Range(85, 89), Range(90, 93), Range(94, 97), 
                        Range(98, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
    }
}
