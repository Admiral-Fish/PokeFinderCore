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

#include "FrameCompare.hpp"

FrameCompare::FrameCompare( int hpEvalIndex,    int hpNum,
                            int atkEvalIndex,   int atkNum,
                            int defEvalIndex,   int defNum,
                            int spaEvalIndex,   int spaNum,
                            int spdEvalIndex,   int spdNum,
                            int speEvalIndex,   int speNum,
                            int genderIndex,
                            int genderRatioIndex,
                            int abilityIndex,
                            QComboBox *natureBox,
                            QComboBox *hiddenPowerBox,
                            bool onlyShiny,
                            bool skipCompare
                          )
{
    hp[0] = (u32)hpEvalIndex;
    hp[1] = (u32)hpNum;
    atk[0] = (u32)atkEvalIndex;
    atk[1] = (u32)atkNum;
    def[0] = (u32)defEvalIndex;
    def[1] = (u32)defNum;
    spa[0] = (u32)spaEvalIndex;
    spa[1] = (u32)spaNum;
    spd[0] = (u32)spdEvalIndex;
    spd[1] = (u32)spdNum;
    spe[0] = (u32)speEvalIndex;
    spe[1] = (u32)speNum;

    gender = (u32)genderIndex;
    genderRatio = (u32)genderRatioIndex;
    ability = (u32)abilityIndex;

    for(u32 i = 1; i < 26; i++)
        if(natureBox->model()->data(natureBox->model()->index(i, 0), Qt::CheckStateRole).toBool())
            natures.push_back(Nature::GetAdjustedNature(i - 1));

    for(u32 i = 1; i < 17; i++)
        if(hiddenPowerBox->model()->data(hiddenPowerBox->model()->index(i, 0), Qt::CheckStateRole).toBool())
            powers.push_back(i - 1);

    shiny = onlyShiny;
    skip = skipCompare;
}

bool FrameCompare::CompareFramePID(Frame frame)
{
    if (skip)
        return true;

    if(shiny && !frame.shiny)
        return false;

    switch(genderRatio)
    {
        case 1:
            switch(gender)
            {
                case 1:
                    if(frame.gender < 127)
                        return false;

                    break;
                case 2:
                    if(frame.gender >= 127)
                        return false;

                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch(gender)
            {
                case 1:
                    if(frame.gender < 191)
                        return false;

                    break;
                case 2:
                    if(frame.gender >= 191)
                        return false;

                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch(gender)
            {
                case 1:
                    if(frame.gender < 63)
                        return false;

                    break;
                case 2:
                    if(frame.gender >= 63)
                        return false;

                    break;
                default:
                    break;
            }
            break;
        case 4:
            switch(gender)
            {
                case 1:
                    if(frame.gender < 31)
                        return false;

                    break;
                case 2:
                    if(frame.gender >= 31)
                        return false;

                    break;
                default:
                    break;
            }
            break;
        case 5:
            switch(gender)
            {
                case 2:
                    return false;
                default:
                    break;
                }
                break;
        case 6:
            switch(gender)
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

    if(ability != 0 && ability - 1 != frame.ability)
        return false;

    if(natures.size() != 0 && find(natures.begin(), natures.end(), frame.nature) == natures.end())
        return false;

    return true;
}

bool FrameCompare::CompareFrameIVs(Frame frame)
{
    if (skip)
        return true;

    if(powers.size() != 0 && find(powers.begin(), powers.end(), frame.hidden) == powers.end())
        return false;

    switch(hp[0])
    {
        case 1:
            if(frame.ivs[0] != hp[1])
                return false;
            break;
        case 2:
            if(frame.ivs[0] < hp[1])
                return false;
            break;
        case 3:
            if(frame.ivs[0] > hp[1])
                return false;
            break;
        case 4:
            if(frame.ivs[0] == hp[1])
                return false;
            break;
        default:
            break;
    }

    switch(atk[0])
    {
        case 1:
            if(frame.ivs[1] != atk[1])
                return false;
            break;
        case 2:
            if(frame.ivs[1] < atk[1])
                return false;
            break;
        case 3:
            if(frame.ivs[1] > atk[1])
                return false;
            break;
        case 4:
            if(frame.ivs[1] == atk[1])
                return false;
            break;
        default:
            break;
    }

    switch(def[0])
    {
        case 1:
            if(frame.ivs[2] != def[1])
                return false;
            break;
        case 2:
            if(frame.ivs[2] < def[1])
                return false;
            break;
        case 3:
            if(frame.ivs[2] > def[1])
                return false;
            break;
        case 4:
            if(frame.ivs[2] == def[1])
                return false;
            break;
        default:
            break;
    }

    switch(spa[0])
    {
        case 1:
            if(frame.ivs[3] != spa[1])
                return false;
            break;
        case 2:
            if(frame.ivs[3] < spa[1])
                return false;
            break;
        case 3:
            if(frame.ivs[3] > spa[1])
                return false;
            break;
        case 4:
            if(frame.ivs[3] == spa[1])
                return false;
            break;
        default:
            break;
    }

    switch(spd[0])
    {
        case 1:
            if(frame.ivs[4] != spd[1])
                return false;
            break;
        case 2:
            if(frame.ivs[4] < spd[1])
                return false;
            break;
        case 3:
            if(frame.ivs[4] > spd[1])
                return false;
            break;
        case 4:
            if(frame.ivs[4] == spd[1])
                return false;
            break;
        default:
            break;
    }

    switch(spe[0])
    {
        case 1:
            if(frame.ivs[5] != spe[1])
                return false;
            break;
        case 2:
            if(frame.ivs[5] < spe[1])
                return false;
            break;
        case 3:
            if(frame.ivs[5] > spe[1])
                return false;
            break;
        case 4:
            if(frame.ivs[5] == spe[1])
                return false;
            break;
        default:
            break;
    }

    return true;
}
