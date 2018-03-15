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

#include "FrameCompare.hpp"

FrameCompare::FrameCompare(vector<u32> eval, vector<u32> values, int genderIndex, int genderRatioIndex, int abilityIndex,
                           vector<bool> nature, vector<bool> power, bool onlyShiny, bool skipCompare)
{
    this->eval = eval;
    val = values;

    gender = (u32)genderIndex;
    genderRatio = (u32)genderRatioIndex;
    ability = (u32)abilityIndex;

    natures.resize(25);
    for (auto i = 0; i < nature.size(); i++)
    {
        natures[Nature::getAdjustedNature(i)] = nature[i];
    }
    powers = power;

    shiny = onlyShiny;
    skip = skipCompare;
}

FrameCompare::FrameCompare(int genderIndex, int genderRatioIndex, int abilityIndex, vector<bool> nature, bool onlyShiny)
{
    gender = (u32)genderIndex;
    genderRatio = (u32)genderRatioIndex;
    ability = (u32)abilityIndex;

    natures.resize(25);
    for (auto i = 0; i < nature.size(); i++)
    {
        natures[Nature::getAdjustedNature(i)] = nature[i];
    }

    shiny = onlyShiny;
    skip = false;
}

FrameCompare::FrameCompare(vector<u32> eval, vector<u32> values, vector<bool> power)
{
    this->eval = eval;
    val = values;
    powers = power;
}

bool FrameCompare::comparePID(Frame frame)
{
    if (skip)
        return true;

    if (shiny && !frame.shiny)
        return false;

    if (!natures[frame.nature])
        return false;

    if (ability != 0 && ability - 1 != frame.ability)
        return false;

    switch (genderRatio)
    {
        case 1:
            switch (gender)
            {
                case 1:
                    if (frame.gender < 127)
                        return false;

                    break;
                case 2:
                    if (frame.gender >= 127)
                        return false;

                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch (gender)
            {
                case 1:
                    if (frame.gender < 191)
                        return false;

                    break;
                case 2:
                    if (frame.gender >= 191)
                        return false;

                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch (gender)
            {
                case 1:
                    if (frame.gender < 63)
                        return false;

                    break;
                case 2:
                    if (frame.gender >= 63)
                        return false;

                    break;
                default:
                    break;
            }
            break;
        case 4:
            switch (gender)
            {
                case 1:
                    if (frame.gender < 31)
                        return false;

                    break;
                case 2:
                    if (frame.gender >= 31)
                        return false;

                    break;
                default:
                    break;
            }
            break;
        case 5:
            switch (gender)
            {
                case 2:
                    return false;
                default:
                    break;
            }
            break;
        case 6:
            switch (gender)
            {
                case 1:
                    return false;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    return true;
}

bool FrameCompare::compareIVs(Frame frame)
{
    if (skip)
        return true;

    if (!powers[frame.hidden])
        return false;

    for (int i = 0; i < 6; i++)
    {
        switch (eval[i])
        {
            case 1:
                if (frame.ivs[i] != val[i])
                    return false;
                break;
            case 2:
                if (frame.ivs[i] < val[i])
                    return false;
                break;
            case 3:
                if (frame.ivs[i] > val[i])
                    return false;
                break;
            case 4:
                if (frame.ivs[i] == val[i])
                    return false;
                break;
            default:
                break;
        }
    }

    return true;
}

bool FrameCompare::compareNature(Frame frame)
{
    return natures[frame.nature];
}

u32 FrameCompare::getGenderRatio()
{
    return genderRatio;
}
