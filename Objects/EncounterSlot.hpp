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

#ifndef ENCOUNTERSLOT_HPP
#define ENCOUNTERSLOT_HPP

#include <QVector>
#include <Objects/Encounter.hpp>

using u32 = uint32_t;

class Range
{

public:
    Range();
    Range(u32 min, u32 max);
    u32 getMax();
    u32 getMin();

private:
    u32 max;
    u32 min;

};

namespace EncounterSlot
{
    u32 calcSlot(u32 compare, QVector<Range> ranges);
    u32 hSlot(u32 result, Encounter encounterType);
    u32 jSlot(u32 result, Encounter encounterType);
    u32 kSlot(u32 result, Encounter encounterType);
};

#endif // ENCOUNTERSLOT_HPP
