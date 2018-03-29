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

#include "EncounterArea3.hpp"

EncounterArea3::EncounterArea3(u32 location, Encounter type, vector<u32> species, vector<u32> minLevel, vector<u32> maxLevel)
    : EncounterArea(location, type, species, minLevel, maxLevel)
{
}

EncounterArea3::EncounterArea3(QStringList data)
{
    location = data[0].toUInt();
    type = (Encounter)data[1].toUInt();

    int len = (data.length() - 2) / 3;
    for (int i = 2; i < len + 2; i++)
    {
        species.push_back(data[i].toUInt());
        minLevel.push_back(data[i + len].toUInt());
        maxLevel.push_back(data[i + len * 2].toUInt());
    }
}

vector<EncounterArea3> EncounterArea3::getEncounters(Encounter type, Games game)
{
    QString path;
    switch (game)
    {
        case Ruby:
            path = ":/ruby.csv";
            break;
        case Sapphire:
            path = ":/sapphire.csv";
            break;
        case FireRed:
            path = ":/firered.csv";
            break;
        case LeafGreen:
            path = ":/leafgreen.csv";
            break;
        case Emerald:
        default:
            path = ":/emerald.csv";
            break;
    }

    QFile file(path);

    vector<EncounterArea3> areas;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream ts(&file);

        while (!ts.atEnd())
        {
            EncounterArea3 area = EncounterArea3(ts.readLine().split(","));

            if (area.getType() == type)
                areas.push_back(area);
        }
    }
    file.close();
    return areas;
}

QStringList EncounterArea3::getSpecieNames()
{
    vector<u32> nums = species;
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return Translator::getSpecies(nums);
}
