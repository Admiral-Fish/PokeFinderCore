/*
 * This file is part of libPokéFinder
 * Copyright (C) 2017 by Admiral_Fish, bumba, and EzPzStreamz
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

#include <libPokeFinder/Objects/Nature.hpp>
#include <libPokeFinder/Objects/Frame.hpp>

class FrameCompare
{

private:
    vector<u32> eval;
    vector<u32> val;
    u32 gender;
    u32 genderRatio;
    u32 ability;
    vector<bool> natures;
    vector<bool> powers;
    bool shiny;
    bool skip;

public:
    FrameCompare(vector<u32> eval, vector<u32> values, int genderIndex, int genderRatioIndex, int abilityIndex,
                 vector<bool> nature, vector<bool> power, bool onlyShiny, bool skipCompare);
    FrameCompare(int genderIndex, int genderRatioIndex, int abilityIndex, vector<bool> nature, bool onlyShiny);
    FrameCompare(vector<u32> eval, vector<u32> values, vector<bool> power);
    bool comparePID(Frame frame);
    bool compareIVs(Frame frame);
    bool compareNature(Frame frame);
    u32 getGenderRatio();

};

#endif // FRAMECOMPARE_HPP
