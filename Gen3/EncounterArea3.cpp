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

EncounterArea3::EncounterArea3(u32 data[])
{
    Encounter type = (Encounter)data[1];
    vector<u32> minLevel, maxLevel, species;

    int length = 0;
    int max = 0;

    switch (type)
    {
        case Wild:
            length = 12;
            max = 14;
            break;
        case RockSmash:
        case Surfing:
        case SuperRod:
            length = 5;
            max = 7;
            break;
        case OldRod:
            length = 2;
            max = 4;
            break;
        case GoodRod:
            length = 3;
            max = 5;
            break;
    }

    for (int j = 2; j < max; j++)
    {
        minLevel.push_back(data[j]);
        maxLevel.push_back(data[j + length]);
        species.push_back(data[j] + length * 2);
    }

    this->location = data[0];
    this->type = type;
    this->species = species;
    this->minLevel = minLevel;
    this->maxLevel = maxLevel;
}

vector<EncounterArea3> EncounterArea3::getEncountersRuby(Encounter type)
{
    QFile file(":/ruby.csv");
    vector<EncounterArea3> areas;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream ts(&file);

        while (!ts.atEnd())
        {
            QStringList data = ts.readLine().split(",");
            Encounter ty = (Encounter)data[1].toUInt();

            if (ty == type)
            {
                u32 loc = data[0].toUInt();
                int len = (data.length() - 2) / 3;
                vector<u32> num, min, max;
                for (int i = 2; i < len + 2; i++)
                {
                    num.push_back(i);
                    min.push_back(i + len);
                    max.push_back(i + len * 2);
                }
                EncounterArea3 area = EncounterArea3(loc, ty, num, min, max);
                areas.push_back(area);
            }
        }
    }
    file.close();
    return areas;
}
