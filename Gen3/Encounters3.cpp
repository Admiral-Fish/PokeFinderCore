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

#include "Encounters3.hpp"

QVector<EncounterArea3> Encounters3::getEncounters(Encounter type, Game game)
{
    QVector<EncounterArea3> encounters;
    switch (game)
    {
        case Ruby:
            encounters = Encounters3::encountersRuby;
            break;
        case Sapphire:
            encounters = Encounters3::encountersSapphire;
            break;
        case FireRed:
            encounters = Encounters3::encountersFireRed;
            break;
        case LeafGreen:
            encounters = Encounters3::encountersLeafGreen;
            break;
        case Emerald:
        default:
            encounters = Encounters3::encountersEmerald;
            break;
    }

    QVector<EncounterArea3> areas;
    for (auto &area : encounters)
    {
        if (area.getType() == type)
            areas.append(area);
    }

    return areas;
}
