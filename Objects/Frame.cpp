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

#include "Frame.hpp"

// Returns gender of 12.5% F ratio
QString Frame::GetFemale125()
{
    return (gender >= 31) ? "M" : "F";
}

// Returns gender of 25% F ratio
QString Frame::GetFemale25()
{
    return (gender >= 63) ? "M" : "F";
}

// Returns gender of 50% F ratio
QString Frame::GetFemale50()
{
    return (gender >= 127) ? "M" : "F";
}

// Returns gender of 75% F ratio
QString Frame::GetFemale75()
{
    return (gender >= 191) ? "M" : "F";
}

// Returns string equivalent of nature
QString Frame::GetNature()
{
    return natures[nature];
}

// Returns string equivalent of hidden power
QString Frame::GetPower()
{
    return powers[hidden];
}

// Returns !!! if shiny or blank if not
QString Frame::GetShiny()
{
    return shiny ? "!!!" : "";
}

// Sets IVs and calculates characteristics based on IVs
void Frame::SetIVs(u32 iv1, u32 iv2)
{
    ivs[0] = iv1 & 0x1f;
    ivs[1] = (iv1 >> 5) & 0x1f;
    ivs[2] = (iv1 >> 10) & 0x1f;
    ivs[3] = (iv2 >> 5) & 0x1f;
    ivs[4] = (iv2 >> 10) & 0x1f;
    ivs[5] = iv2 & 0x1f;
    hidden = ((((ivs[0] & 1) + 2 * (ivs[1] & 1) + 4 * (ivs[2] & 1) + 8 * (ivs[5] & 1) + 16 * (ivs[3] & 1) + 32 * (ivs[4] & 1)) * 15) / 63);
    power = (30 + ((((ivs[0] >> 1) & 1) + 2 * ((ivs[1] >> 1) & 1) + 4 * ((ivs[2] >> 1) & 1) + 8 * ((ivs[5] >> 1) & 1) + 16 * ((ivs[3] >> 1) & 1) + 32 * ((ivs[4] >> 1) & 1)) * 40 / 63));
}

// Sets PID and calculates characteristics based on PID
void Frame::SetPID(u32 pid1, u32 pid2)
{
    pid = (pid1 << 16) | pid2;
    nature = pid % 25;
    gender = pid & 255;
    ability = pid & 1;
    if ((pid1 ^ pid2 ^ psv) < 8)
        shiny = true;
    else
        shiny = false;
}

// Sets PID and calculates characteristics based on PID
void Frame::SetPID(u32 pid, u32 pid1, u32 pid2)
{
    this->pid = pid;
    gender = pid & 255;
    ability = pid & 1;
    if ((pid1 ^ pid2 ^ psv) < 8)
        shiny = true;
    else
        shiny = false;
}
