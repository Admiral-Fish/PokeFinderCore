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
#include <Objects/Global.hpp>

class Range
{

public:
    Range();
    Range(u8 min, u8 max);
    u8 getMax();
    u8 getMin();

private:
    u8 max;
    u8 min;

};

namespace EncounterSlot
{
    u8 calcSlot(u8 compare, QVector<Range> ranges);
    u8 hSlot(u32 result, Encounter encounterType);
    u8 jSlot(u32 result, Encounter encounterType);
    u8 kSlot(u32 result, Encounter encounterType);
};

#endif // ENCOUNTERSLOT_HPP
