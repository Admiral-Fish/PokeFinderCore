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

#include "EncounterArea4.hpp"

EncounterArea4::EncounterArea4(int location, int time, Game dual, Encounter type, const QVector<int> &species, const QVector<u32> &minLevel, const QVector<u32> &maxLevel)
    : EncounterArea(location, type, species, minLevel, maxLevel)
{
    this->dual = dual;
    this->time = time;
    sound = 0;
}

EncounterArea4::EncounterArea4(int location, int time, int sound, Encounter type, const QVector<int> &species, const QVector<u32> &minLevel, const QVector<u32> &maxLevel)
    : EncounterArea(location, type, species, minLevel, maxLevel)
{
    this->sound = sound;
    this->time = time;
    dual = Game::Blank;
}

EncounterArea4::EncounterArea4(int location, int time, Game dual, Encounter type, const QVector<int> &species, const QVector<u32> &levels)
    : EncounterArea(location, type, species, levels)
{
    this->dual = dual;
    this->time = time;
    sound = 0;
}

EncounterArea4::EncounterArea4(int location, int time, int sound, Encounter type, const QVector<int> &species, const QVector<u32> &levels)
    : EncounterArea(location, type, species, levels)
{
    this->sound = sound;
    this->time = time;
    dual = Game::Blank;
}

u32 EncounterArea4::calcLevel(u32 index, u32 prng)
{
    if (levelLocked(index))
        return minLevel[static_cast<int>(index)];

    return (prng % (maxLevel[static_cast<int>(index)] - minLevel[static_cast<int>(index)] + 1)) + minLevel[static_cast<int>(index)];
}

u32 EncounterArea4::calcLevel(u32 index)
{
    return maxLevel[static_cast<int>(index)];
}

Game EncounterArea4::getDual() const
{
    return dual;
}

int EncounterArea4::getTime() const
{
    return time;
}

int EncounterArea4::getSound() const
{
    return sound;
}
