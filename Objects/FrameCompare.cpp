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

FrameCompare::FrameCompare(const QVector<u8> &eval, const QVector<u8> &values, int genderIndex, int genderRatioIndex, int abilityIndex,
                           const QVector<bool> &nature, const QVector<bool> &power, bool onlyShiny, bool skipCompare)
{
    this->eval = eval;
    val = values;

    gender = genderIndex;
    genderRatio = genderRatioIndex;
    ability = abilityIndex;

    natures.resize(25);
    for (u8 i = 0; i < 25; i++)
    {
        natures[Nature::getAdjustedNature(i)] = nature[i];
    }

    powers = power;

    shiny = onlyShiny;
    skip = skipCompare;
}

FrameCompare::FrameCompare(const QVector<u8> &eval, const QVector<u8> &values, int genderIndex, int genderRatioIndex, int abilityIndex,
                           const QVector<bool> &nature, const QVector<bool> &power, bool onlyShiny, bool skipCompare, const QVector<bool> &encounter)
{
    this->eval = eval;
    val = values;

    gender = genderIndex;
    genderRatio = genderRatioIndex;
    ability = abilityIndex;

    natures.resize(25);
    for (u32 i = 0; i < 25; i++)
    {
        natures[Nature::getAdjustedNature(i)] = nature[i];
    }

    powers = power;
    encounterSlots = encounter;

    shiny = onlyShiny;
    skip = skipCompare;
}

FrameCompare::FrameCompare(int genderIndex, int genderRatioIndex, int abilityIndex, QVector<bool> nature, bool onlyShiny)
{
    gender = genderIndex;
    genderRatio = genderRatioIndex;
    ability = abilityIndex;

    natures.resize(25);
    for (u32 i = 0; i < 25; i++)
    {
        natures[static_cast<int>(Nature::getAdjustedNature(i))] = nature[static_cast<int>(i)];
    }

    shiny = onlyShiny;
    skip = false;
}

FrameCompare::FrameCompare(const QVector<u8> &eval, const QVector<u8> &values, const QVector<bool> &power)
{
    this->eval = eval;
    val = values;
    powers = power;
}

bool FrameCompare::comparePID(const Frame &frame)
{
    if (skip)
    {
        return true;
    }

    if (shiny && !frame.getShiny())
    {
        return false;
    }

    if (!natures[frame.getNature()])
    {
        return false;
    }

    if (ability != 0 && ability - 1 != frame.getAbility())
    {
        return false;
    }

    if (!compareGender(frame))
    {
        return false;
    }

    return true;
}

bool FrameCompare::compareIVs(const Frame &frame)
{
    if (skip)
    {
        return true;
    }

    if (!powers[frame.getHidden()])
    {
        return false;
    }

    for (int i = 0; i < 6; i++)
    {
        switch (eval[i])
        {
            case 1:
                if (frame.getIV(i) != val[i])
                {
                    return false;
                }
                break;
            case 2:
                if (frame.getIV(i) < val[i])
                {
                    return false;
                }
                break;
            case 3:
                if (frame.getIV(i) > val[i])
                {
                    return false;
                }
                break;
            case 4:
                if (frame.getIV(i) == val[i])
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    return true;
}

bool FrameCompare::compareNature(const Frame &frame)
{
    return natures[frame.getNature()];
}

bool FrameCompare::compareHiddenPower(const Frame &frame)
{
    return powers[frame.getHidden()];
}

bool FrameCompare::compareSlot(const Frame &frame)
{
    return encounterSlots[frame.getEncounterSlot()];
}

bool FrameCompare::compareGender(const Frame &frame)
{
    switch (genderRatio)
    {
        case 1:
            switch (gender)
            {
                case 1:
                    if (frame.getGender() < 127)
                    {
                        return false;
                    }
                    break;
                case 2:
                    if (frame.getGender() >= 127)
                    {
                        return false;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch (gender)
            {
                case 1:
                    if (frame.getGender() < 191)
                    {
                        return false;
                    }
                    break;
                case 2:
                    if (frame.getGender() >= 191)
                    {
                        return false;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch (gender)
            {
                case 1:
                    if (frame.getGender() < 63)
                    {
                        return false;
                    }
                    break;
                case 2:
                    if (frame.getGender() >= 63)
                    {
                        return false;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 4:
            switch (gender)
            {
                case 1:
                    if (frame.getGender() < 31)
                    {
                        return false;
                    }
                    break;
                case 2:
                    if (frame.getGender() >= 31)
                    {
                        return false;
                    }
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

bool FrameCompare::compareFrame(const Frame &frame)
{
    if (skip)
    {
        return true;
    }

    if (!comparePID(frame))
    {
        return false;
    }

    if (!compareIVs(frame))
    {
        return false;
    }

    return true;
}

u8 FrameCompare::getGenderRatio()
{
    return genderRatio;
}
