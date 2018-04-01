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

#ifndef ENCOUNTERAREA3_HPP
#define ENCOUNTERAREA3_HPP

#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <PokeFinderCore/Objects/Game.hpp>
#include <PokeFinderCore/Objects/EncounterArea.hpp>
#include <algorithm>

class EncounterArea3 : public EncounterArea
{

public:
    EncounterArea3(u32 location, Encounter type, vector<u32> species, vector<u32> minLevel, vector<u32> maxLevel);
    EncounterArea3(QStringList data);
    static vector<EncounterArea3> getEncounters(Encounter type, Game game);
    QStringList getSpecieNames();

};

#endif // ENCOUNTERAREA3_HPP
