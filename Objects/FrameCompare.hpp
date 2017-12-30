/*
 * This file is part of libPokéFinder
 * Copyright (C) 2017 by Admiral_Fish and bumba
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
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
#include <QString>
#include <QTranslator>
#include <QComboBox>
#include <libPokeFinder/Objects/Nature.hpp>
#include <cstdint>
#include <vector>
#include <libPokeFinder/Objects/Frame.hpp>

using namespace std;
typedef uint32_t u32;

class FrameCompare
{
private:

    uint hp[2];
    u32 atk[2];
    u32 def[2];
    u32 spa[2];
    u32 spd[2];
    u32 spe[2];

    u32 gender;
    u32 genderRatio;
    u32 ability;
    vector<bool> natures;
    vector<bool> powers;

    bool shiny;
    bool skip;

public:
    FrameCompare(int hpEvalIndex, int hpNum, int atkEvalIndex, int atkNum,
                 int defEvalIndex, int defNum, int spaEvalIndex, int spaNum,
                 int spdEvalIndex, int spdNum, int speEvalIndex, int speNum,
                 int genderIndex, int genderRatioIndex, int abilityIndex,
                 vector<bool> nature, vector<bool> power, bool onlyShiny, bool skipCompare);

    bool ComparePID(Frame frame);

    bool CompareIVs(Frame frame);

    bool CompareNature(Frame frame);

};

#endif // FRAMECOMPARE_HPP
