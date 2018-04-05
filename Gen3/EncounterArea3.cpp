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

vector<EncounterArea3> EncounterArea3::getEncounters(Encounter type, Game game)
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
    vector<u32> nums;

    nums.push_back(species[0]);
    for (int i = 1; i < species.size(); i++)
        if (std::find(nums.begin(), nums.end(), species[i]) == nums.end())
            nums.push_back(species[i]);

    return Translator::getSpecies(nums);
}

u32 EncounterArea3::calcLevel(u32 index, u32 prng)
{
    if (levelLocked(index))
        return minLevel[index];

    return (prng % (maxLevel[index] - minLevel[index] + 1)) + minLevel[index];
}

// Only for Rock Smash since all other encounters can be forced
u32 EncounterArea3::getEncounterRate()
{
    switch (location)
    {
        case 18: // Route 111
        case 21: // Route 114
        case 47: // Granite Cave B2F
        case 72: // Victory Road B1F (RSE)
            return 20;
        case 51: // Safari Zone 4
        case 53: // Safari Zone 6
        case 152: // Kindle Road
        case 167: // Sevault Canyon
            return 25;
        case 134: // Rock Tunnel B1F
        case 145: // Cerulean Cave 1F
        case 146: // Cerulean Cave 2F
        case 147: // Cerulean Cave B1F
        case 169: // Mt. Ember
        case 171: // Mt. Ember Room 2
        case 173: // Mt. Ember 1F
        case 174: // Mt. Ember B1F
        case 175: // Mt. Ember B2F
        case 176: // Mt. Ember B3F
        case 177: // Mt. Ember B4F
        case 178: // Mt. Ember B5F
            return 50;
        default:
            return 0;
    }
}
