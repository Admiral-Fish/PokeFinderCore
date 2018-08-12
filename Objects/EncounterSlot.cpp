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

#include "EncounterSlot.hpp"

/* Ranges are used alongside an RNG call to
 * determine what encounter slot a frame will have
 */

// Constructor for Range
Range::Range()
{
    min = 0;
    max = 99;
}

Range::Range(u32 min, u32 max)
{
    this->min = min;
    this->max = max;
}

// Gets current value of the max
u32 Range::getMax()
{
    return max;
}

// Gets current value of the min
u32 Range::getMin()
{
    return min;
}


// Encounter slot calculations

// Runs through ranges and compare value to get the encounter slot
u32 EncounterSlot::calcSlot(u32 compare, QVector<Range> ranges)
{
    int size = ranges.size();
    for (int i = 0; i < size; i++)
        if (compare >= ranges[i].getMin() && compare <= ranges[i].getMax())
            return static_cast<u32>(i);
    return 0;
}

// Calcs the encounter slot for Method H 1/2/4 (Emerald, FRLG, RS)
u32 EncounterSlot::hSlot(u32 result, Encounter encounterType)
{
    u32 compare = result % 100;
    QVector<Range> ranges;
    switch (encounterType)
    {
        case OldRod:
            ranges = { Range(0, 69), Range(70, 99) } ;
            return calcSlot(compare, ranges);
        case GoodRod:
            ranges = { Range(0, 59), Range(60, 79), Range(80, 99) };
            return calcSlot(compare, ranges);
        case SuperRod:
            ranges = { Range(0, 39), Range(40, 79), Range(80, 94), Range(95, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
        case Surfing:
        case RockSmash:
            ranges = { Range(0, 59), Range(60, 89), Range(90, 94), Range(95, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
        default:
            ranges = { Range(0, 19), Range(20, 39), Range(40, 49), Range(50, 59), Range(60, 69),
                       Range(70, 79), Range(80, 84), Range(85, 89), Range(90, 93), Range(94, 97),
                       Range(98, 98), Range(99, 99)
                 };
            return calcSlot(compare, ranges);
    }
}

// Calcs the encounter slot for Method J (DPPt)
u32 EncounterSlot::jSlot(u32 result, Encounter encounterType)
{
    u32 compare = result / 656;
    QVector<Range> ranges;
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
                       Range(98, 98), Range(99, 99)
                 };
            return calcSlot(compare, ranges);
    }
}

// Calcs the encounter slot for Method K (HGSS)
u32 EncounterSlot::kSlot(u32 result, Encounter encounterType)
{
    u32 compare = result % 100;
    QVector<Range> ranges;
    switch (encounterType)
    {
        case OldRod:
        case GoodRod:
        case SuperRod:
            ranges = { Range(0, 39), Range(40, 69), Range(70, 84), Range(85, 94), Range(95, 99) };
            return calcSlot(compare, ranges);
        case Surfing:
            ranges = { Range(0, 59), Range(60, 89), Range(90, 94), Range(95, 98), Range(99, 99) };
            return calcSlot(compare, ranges);
        case BugCatchingContest:
            ranges = { Range(80, 99), Range(60, 79), Range(50, 59), Range(40, 49), Range(30, 39),
                       Range(20, 29), Range(15, 19), Range(10, 14), Range(5, 9), Range(0, 4)
                 };
            return calcSlot(compare, ranges);
        case SafariZone:
            return compare % 10;
        case HeadButt:
            ranges = { Range(0, 49), Range(50, 64), Range(65, 79), Range(80, 89), Range(90, 94),
                       Range(95, 99)
                 };
            return calcSlot(compare, ranges);
        case RockSmash: // Might be 80/20
            ranges = { Range(0, 89), Range(90, 99) };
            return calcSlot(compare, ranges);
        default:
            ranges = { Range(0, 19), Range(20, 39), Range(40, 49), Range(50, 59), Range(60, 69),
                       Range(70, 79), Range(80, 84), Range(85, 89), Range(90, 93), Range(94, 97),
                       Range(98, 98), Range(99, 99)
                 };
            return calcSlot(compare, ranges);
    }
}
