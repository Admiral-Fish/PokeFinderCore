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

#include "Encounters4.hpp"

QVector<EncounterArea4> Encounters4::getEncounters(Encounter type, Game game, int time)
{
    QVector<EncounterArea4> encounters;
    switch (game)
    {
        case Diamond:
            encounters = Encounters4::encountersDiamond;
            break;
        case Pearl:
            encounters = Encounters4::encountersPearl;
            break;
        case Platinum:
            encounters = Encounters4::encountersPlatinum;
            break;
        case HeartGold:
            encounters = Encounters4::encountersHeartGold;
            break;
        case SoulSilver:
        default:
            encounters = Encounters4::encountersSoulSilver;
            break;
    }

    QVector<EncounterArea4> areas;
    for (auto &area : encounters)
    {
        // Temp remove all slots related to sound and dual
        // Implement later
        if (area.getType() == type && area.getSound() == 0 && area.getDual() == 0)
        {
            if (area.getType() == Encounter::Grass && !(area.getTime() == 0 || area.getTime() == time))
                continue;
            areas.append(area);
        }
    }

    return areas;
}
