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

EncounterArea4::EncounterArea4(int location, Encounter type, QVector<int> species, QVector<u32> minLevel, QVector<u32> maxLevel, Game dual, int time)
    : EncounterArea(location, type, species, minLevel, maxLevel)
{
    this->dual = dual;
    this->time = time;
}

EncounterArea4::EncounterArea4(int location, Encounter type, QVector<int> species, QVector<u32> minLevel, QVector<u32> maxLevel, int sound, int time)
    : EncounterArea(location, type, species, minLevel, maxLevel)
{
    this->sound = sound;
    this->time = time;
}

EncounterArea4::EncounterArea4(QStringList data, Game game)
{
    location = data[0].toInt();
    time = data[1].toInt();
    if (game == Game::HeartGold || game == Game::SoulSilver)
    {
        sound = data[2].toInt();
        dual = Game::Blank;
    }
    else
    {
        dual = static_cast<Game>(data[2].toInt());
        sound = 0;
    }
    type = static_cast<Encounter>(data[3].toInt());

    bool flag = type == Encounter::Wild || type == Encounter::Swarm || type == Encounter::PokeRadar;

    int len = (data.length() - 4) / (flag ? 2 : 3);
    for (int i = 4; i < len + 4; i++)
    {
        species.append(data[i].toInt());
        minLevel.append(data[i + len].toUInt());
        maxLevel.append(data[i + (flag ? len : len * 2)].toUInt());
    }
}

QVector<EncounterArea4> EncounterArea4::getEncounters(Encounter type, Game game, int time)
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

    QVector<EncounterArea4> areas;
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
                if (area.type == Encounter::Wild && !(area.time == 0 || area.time == time))
                    continue;
                areas.append(area);
            }
        }
    }
    file.close();
    return areas;
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
