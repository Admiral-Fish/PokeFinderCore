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

#ifndef ENCOUNTERS4_HPP
#define ENCOUNTERS4_HPP

#include <QDataStream>
#include <PokeFinderCore/Gen4/EncounterArea4.hpp>
//#include <PokeFinderCore/Gen4/Modifiers4.hpp>

class Encounters4
{

public:
    Encounters4(Encounter type, Game game, Game dual, int time, int radio);
    QVector<EncounterArea4> getEncounters();

private:
    Encounter type;
    Game game, dual; // Dual is used in DPPt
    int time; // 0: Any 1: Morning, 2: Day, 3: Night
    int radio; // 0: None, 1: Hoenn, 2: Sinnoh, For HGSS

    QVector<EncounterArea4> getBaseEncounters() const;
    //QVector<EncounterArea4> modifySlotsDual(QVector<EncounterArea4> encounters);
    //QVector<EncounterArea4> modifySlotsSound(QVector<EncounterArea4> encounters);

};

#endif // ENCOUNTERS4_HPP
