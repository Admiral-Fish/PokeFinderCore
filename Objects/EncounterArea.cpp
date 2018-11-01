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

EncounterArea::EncounterArea(int location, Encounter type, const QVector<int> &species, const QVector<u32> &minLevel, const QVector<u32> &maxLevel)
{
    this->type = type;
    this->location = location;
    this->species = species;
    this->minLevel = minLevel;
    this->maxLevel = maxLevel;
}

bool EncounterArea::levelLocked(u32 slot)
{
    return minLevel[static_cast<int>(slot)] == maxLevel[static_cast<int>(slot)];
}

Encounter EncounterArea::getType()
{
    return type;
}

int EncounterArea::getLocation()
{
    return location;
}

QVector<u32> EncounterArea::getMinLevel()
{
    return minLevel;
}

QVector<u32> EncounterArea::getMaxLevel()
{
    return maxLevel;
}

QVector<int> EncounterArea::getSpecies()
{
    return species;
}

QVector<int> EncounterArea::getUniqueSpecies()
{
    QVector<int> nums;

    nums.append(species[0]);
    for (int i = 1; i < species.size(); i++)
        if (!nums.contains(species[i]))
            nums.append(species[i]);

    return nums;
}

QVector<bool> EncounterArea::getSlots(u32 num)
{
    QVector<bool> flags;

    for (int specie : species)
        flags.append(specie == static_cast<int>(num));

    return flags;
}

QStringList EncounterArea::getSpecieNames()
{
    return Translator::getSpecies(getUniqueSpecies());
}
