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
#include <PokeFinderCore/Objects/Encounter.hpp>
#include <PokeFinderCore/Translator.hpp>

using u32 = uint32_t;
using u16 = uint16_t;

class EncounterArea
{

protected:
    QVector<u32> minLevel;
    QVector<u32> maxLevel;
    QVector<int> species;
    int location;
    Encounter type;

public:
    EncounterArea() = default;
    EncounterArea(int location, Encounter type, const QVector<int> &species, const QVector<u32> &minLevel, const QVector<u32> &maxLevel);
    EncounterArea(int location, Encounter type, const QVector<int> &species, const QVector<u32> &levels);
    bool levelLocked(u32 slot);
    Encounter getType();
    int getLocation();
    QVector<u32> getMinLevel();
    QVector<u32> getMaxLevel();
    QVector<int> getSpecies();
    QVector<int> getUniqueSpecies();
    QVector<bool> getSlots(u32 num);
    QStringList getSpecieNames();

};

#endif // ENCOUNTERAREA_HPP
