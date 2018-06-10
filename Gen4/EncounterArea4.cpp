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

EncounterArea4::EncounterArea4(u32 location, Encounter type, vector<u32> species, vector<u32> minLevel, vector<u32> maxLevel, Game dual, int time)
    : EncounterArea(location, type, species, minLevel, maxLevel)
{
    this->dual = dual;
    this->time = time;
}

EncounterArea4::EncounterArea4(u32 location, Encounter type, vector<u32> species, vector<u32> minLevel, vector<u32> maxLevel, int sound, int time)
    : EncounterArea(location, type, species, minLevel, maxLevel)
{
    this->sound = sound;
    this->time = time;
}

EncounterArea4::EncounterArea4(QStringList data, Game game)
{
    location = data[0].toUInt();
    time = data[1].toInt();
    if (game == HeartGold || game == SoulSilver)
    {
        sound = data[2].toInt();
        dual = Blank;
    }
    else
    {
        dual = (Game)data[2].toInt();
        sound = 0;
    }
    type = (Encounter)data[3].toInt();

    bool flag = type == Wild || type == Swarm || type == PokeRadar;

    int len = (data.length() - 4) / (flag ? 2 : 3);
    for (int i = 4; i < len + 4; i++)
    {
        species.push_back(data[i].toUInt());
        minLevel.push_back(data[i + len].toUInt());
        maxLevel.push_back(data[i + (flag ? len : len * 2)].toUInt());
    }
}

vector<EncounterArea4> EncounterArea4::getEncounters(Encounter type, Game game, int time)
{
    QString path;
    switch (game)
    {
        case Diamond:
            path = ":/diamond.csv";
            break;
        case Pearl:
            path = ":/pearl.csv";
            break;
        case Platinum:
            path = ":/platinum.csv";
            break;
        case HeartGold:
            path = ":/heartgold.csv";
            break;
        case SoulSilver:
        default:
            path = ":/soulsilver.csv";
            break;
    }

    QFile file(path);

    vector<EncounterArea4> areas;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream ts(&file);

        while (!ts.atEnd())
        {
            QString in = ts.readLine();
            EncounterArea4 area = EncounterArea4(in.split(","), game);

            // Temp remove all slots related to sound and dual
            // Implement later
            if (area.type == type && area.sound == 0 && area.dual == 0)
            {
                if (area.type == Wild && !(area.time == 0 || area.time == time))
                    continue;
                areas.push_back(area);
            }
        }
    }
    file.close();
    return areas;
}

QStringList EncounterArea4::getSpecieNames()
{
    return Translator::getSpecies(getUniqueSpecies());
}

u32 EncounterArea4::calcLevel(u32 index, u32 prng)
{
    if (levelLocked(index))
        return minLevel[index];

    return (prng % (maxLevel[index] - minLevel[index] + 1)) + minLevel[index];
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
