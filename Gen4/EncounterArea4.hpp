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

#ifndef ENCOUNTERAREA4_HPP
#define ENCOUNTERAREA4_HPP

#include <PokeFinderCore/Objects/EncounterArea.hpp>
#include <PokeFinderCore/Objects/Game.hpp>

class EncounterArea4 : public EncounterArea
{

private:
    int time;

public:
    EncounterArea4() = default;
    EncounterArea4(int location, int time, Encounter type, const QVector<Slot> &pokemon);
    u32 calcLevel(u32 index, u32 prng) const;
    u32 calcLevel(u32 index) const;
    int getTime() const;
    void setSlot(int index, int specie);

};

QDataStream &operator>>(QDataStream &in, EncounterArea4 &encounter);

#endif // ENCOUNTERAREA4_HPP
