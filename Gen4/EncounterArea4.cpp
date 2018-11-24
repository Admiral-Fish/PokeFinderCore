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

EncounterArea4::EncounterArea4(int location, int time, Encounter type, const QVector<Slot> &pokemon)
    : EncounterArea(location, type, pokemon)
{
    this->time = time;
}

u32 EncounterArea4::calcLevel(u32 index, u32 prng) const
{
    return (prng % (pokemon.at(index).getMaxLevel() - pokemon.at(index).getMinLevel() + 1)) + pokemon.at(index).getMinLevel();
}

u32 EncounterArea4::calcLevel(u32 index) const
{
    return pokemon.at(index).getMinLevel();
}

int EncounterArea4::getTime() const
{
    return time;
}

void EncounterArea4::setSlot(int index, int specie)
{
    pokemon[index].setSpecie(specie);
}

QDataStream &operator>>(QDataStream &in, EncounterArea4 &encounter)
{
    QVariant location, time, type;
    in >> location >> time >> type;

    int size;
    switch (static_cast<Encounter>(type.toInt()))
    {
        case Encounter::Grass:
        case Encounter::Swarm:
        case Encounter::PokeRadar:
            size = 12;
        case Encounter::SafariZone:
            break;
        case Encounter::RockSmash:
            size = 2;
            break;
        case Encounter::OldRod:
        case Encounter::GoodRod:
        case Encounter::SuperRod:
        case Encounter::Surfing:
            size = 5;
            break;
        default:
            break;
    }

    QVector<Slot> pokemon;
    for (int i = 0; i < size; i++)
    {
        QVariant specie, min, max;
        in >> specie >> min >> max;
        pokemon.append(Slot(specie.toInt(), min.toUInt(), max.toUInt()));
    }

    encounter = EncounterArea4(location.toInt(), time.toInt(), static_cast<Encounter>(type.toInt()), pokemon);
    return in;
}
