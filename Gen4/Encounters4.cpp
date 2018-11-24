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

#include "Encounters4.hpp"

Encounters4::Encounters4(Encounter type, Game game, Game dual, int time, int radio)
{
    this->type = type;
    this->game = game;
    this->dual = dual;
    this->time = time;
    this->radio = radio;
}

QVector<EncounterArea4> Encounters4::getEncounters()
{
    QVector<EncounterArea4> encounters;
    for (const auto &area : getBaseEncounters())
    {
        if (area.getType() == type && (area.getTime() == 0 || area.getTime() == time))
            encounters.append(area);
    }

    // TODO
    /*if (dual != Game::Blank && (type == Encounter::Grass || type == Encounter::PokeRadar || type == Encounter::Swarm))
        encounters = modifySlotsDual(encounters);

    if (radio != 0)
        encounters = modifySlotsSound(encounters);*/

    return encounters;
}

QVector<EncounterArea4> Encounters4::getBaseEncounters() const
{
    QString path;
    switch (game)
    {
        case Game::Diamond:
            path = ":/diamond.bin";
            break;
        case Game::Pearl:
            path = ":/pearl.bin";
            break;
        case Game::Platinum:
            path = ":/platinum.bin";
            break;
        case Game::HeartGold:
            path = ":/heartgold.bin";
            break;
        case Game::SoulSilver:
        default:
            path = ":/soulsilver.bin";
            break;
    }

    QVector<EncounterArea4> encounters;
    QFile file(path);
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&file);
        stream >> encounters;
        file.close();
    }

    return encounters;
}

// Changes slots 8 & 9
/*QVector<EncounterArea4> Encounters4::modifySlotsDual(QVector<EncounterArea4> encounters)
{
    const auto &modifiers = Modifiers::getDualModifiers(game, dual);
    for (auto &encounter : encounters)
    {
        const auto &iterator = modifiers.find(encounter.getLocation());
        if (iterator != modifiers.end())
        {
            const auto &modify = iterator.value();
            encounter.setSlot(8, modify.first);
            encounter.setSlot(9, modify.second);
        }
    }
    return encounters;
}*/

// TODO figure out slot changes
/*QVector<EncounterArea4> Encounters4::modifySlotsSound(QVector<EncounterArea4> encounters)
{
    const auto &modifiers = Modifiers::getRadioModifiers(game, radio);
    for (auto &encounter : encounters)
    {
        const auto &iterator = modifiers.find(encounter.getLocation());
        if (iterator != modifiers.end())
        {
            const auto &modify = iterator.value();
        }
    }
    return encounters;
}*/
