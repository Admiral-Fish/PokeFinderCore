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

#ifndef ENCOUNTERAREA_HPP
#define ENCOUNTERAREA_HPP

#include <QFile>
#include <QVector>
#include <Objects/Encounter.hpp>
#include <Translator.hpp>

using u32 = uint32_t;
using u16 = uint16_t;

class Slot;

class EncounterArea
{

public:
    EncounterArea() = default;
    EncounterArea(int location, Encounter type, const QVector<Slot> &pokemon);
    Encounter getType() const;
    int getLocation() const;
    QVector<int> getUniqueSpecies() const;
    QVector<bool> getSlots(u32 num) const;
    QStringList getSpecieNames() const;

protected:
    QVector<Slot> pokemon;
    int location;
    Encounter type;

};

class Slot
{

public:
    Slot() = default;
    Slot(int specie, u32 minLevel, u32 maxLevel);
    Slot(int specie, u32 level);

    u32 getMinLevel() const { return minLevel; }
    u32 getMaxLevel() const { return maxLevel; }
    int getSpecie() const { return specie; }
    void setSpecie(int specie) { this->specie = specie; }

private:
    u32 minLevel;
    u32 maxLevel;
    int specie;

};

#endif // ENCOUNTERAREA_HPP
