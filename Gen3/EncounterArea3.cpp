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

#include "EncounterArea3.hpp"

EncounterArea3::EncounterArea3(int location, u32 delay, Encounter type, const QVector<int> &species, const QVector<u32> &minLevel, const QVector<u32> &maxLevel)
    : EncounterArea(location, type, species, minLevel, maxLevel)
{
    this->delay = delay;
}

EncounterArea3::EncounterArea3(int location, u32 delay, Encounter type, const QVector<int> &species, const QVector<u32> &levels)
    : EncounterArea(location, type, species, levels)
{
    this->delay = delay;
}

QVector<EncounterArea3> EncounterArea3::getEncounters(Encounter type, Game game)
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

u32 EncounterArea3::calcLevel(u32 index, u32 prng)
{
    if (levelLocked(index))
        return minLevel[static_cast<int>(index)];

    return (prng % (maxLevel[static_cast<int>(index)] - minLevel[static_cast<int>(index)] + 1)) + minLevel[static_cast<int>(index)];
}

u32 EncounterArea3::calcLevel(u32 index)
{
    return maxLevel[static_cast<int>(index)];
}

// Only for Rock Smash since all other encounters can be forced
u16 EncounterArea3::getEncounterRate() const
{
    switch (location)
    {
        case 18: // Route 111
        case 21: // Route 114
        case 47: // Granite Cave B2F
        case 72: // Victory Road B1F (RSE)
            return 20;
        case 51: // Safari Zone 4
        case 53: // Safari Zone 6
            return 25;
        // FRLG doesn't force encounter
        // Uses a different RNG to proc the encounter
        case 134: // Rock Tunnel B1F (50)
        case 145: // Cerulean Cave 1F  (50)
        case 146: // Cerulean Cave 2F (50)
        case 147: // Cerulean Cave B1F (50)
        case 152: // Kindle Road (25)
        case 167: // Sevault Canyon (25)
        case 169: // Mt. Ember (50)
        case 171: // Mt. Ember Room 2 (50)
        case 173: // Mt. Ember 1F (50)
        case 174: // Mt. Ember B1F (50)
        case 175: // Mt. Ember B2F (50)
        case 176: // Mt. Ember B3F (50)
        case 177: // Mt. Ember B4F (50)
        case 178: // Mt. Ember B5F (50)
            return 180;
        default:
            return 0;
    }
}

u32 EncounterArea3::getDelay() const
{
    return delay;
}
