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

#include "EncounterArea.hpp"

EncounterArea::EncounterArea(u32 location, Encounter type, vector<u32> species, vector<u32> minLevel, vector<u32> maxLevel)
{
    this->type = type;
    this->location = location;
    this->species = species;
    this->minLevel = minLevel;
    this->maxLevel = maxLevel;
}

bool EncounterArea::levelLocked(u32 slot)
{
    return minLevel[slot] == maxLevel[slot];
}

Encounter EncounterArea::getType()
{
    return type;
}

u32 EncounterArea::getLocation()
{
    return location;
}

vector<u32> EncounterArea::getMinLevel()
{
    return minLevel;
}

vector<u32> EncounterArea::getMaxLevel()
{
    return maxLevel;
}

vector<u32> EncounterArea::getSpecies()
{
    return species;
}

vector<u32> EncounterArea::getUniqueSpecies()
{
    vector<u32> nums;

    nums.push_back(species[0]);
    for (int i = 1; i < species.size(); i++)
        if (std::find(nums.begin(), nums.end(), species[i]) == nums.end())
            nums.push_back(species[i]);

    return nums;
}

vector<bool> EncounterArea::getSlots(u32 num)
{
    vector<bool> flags;

    for (int i = 0; i < species.size(); i++)
        flags.push_back(species[i] == num);

    return flags;
}
