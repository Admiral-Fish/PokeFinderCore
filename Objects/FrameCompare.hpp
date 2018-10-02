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

#ifndef FRAMECOMPARE_HPP
#define FRAMECOMPARE_HPP

#include <QVector>
#include <PokeFinderCore/Objects/Nature.hpp>
#include <PokeFinderCore/Objects/Frame.hpp>

class FrameCompare
{

private:
    QVector<u32> eval;
    QVector<u32> val;
    u32 gender;
    u32 genderRatio;
    u32 ability;
    QVector<bool> natures;
    QVector<bool> powers;
    QVector<bool> encounterSlots;
    bool shiny;
    bool skip;

public:
    FrameCompare() {}
    FrameCompare(QVector<u32> eval, QVector<u32> values, int genderIndex, int genderRatioIndex, int abilityIndex,
                 QVector<bool> nature, QVector<bool> power, bool onlyShiny, bool skipCompare);
    FrameCompare(QVector<u32> eval, QVector<u32> values, int genderIndex, int genderRatioIndex, int abilityIndex,
                 QVector<bool> nature, QVector<bool> power, bool onlyShiny, bool skipCompare, QVector<bool> encounter);
    FrameCompare(int genderIndex, int genderRatioIndex, int abilityIndex, QVector<bool> nature, bool onlyShiny);
    FrameCompare(QVector<u32> eval, QVector<u32> values, QVector<bool> power);
    bool comparePID(Frame frame);
    bool compareIVs(Frame frame);
    bool compareNature(Frame frame);
    bool compareHiddenPower(Frame frame);
    bool compareSlot(Frame frame);
    bool compareGender(Frame frame);
    bool compareFrame(Frame frame);
    u32 getGenderRatio();

};

#endif // FRAMECOMPARE_HPP
