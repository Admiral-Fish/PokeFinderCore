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

#include "Frame.hpp"

// Gets gender based on gender ratio
QString Frame::getGenderString()
{
    switch (genderRatio)
    {
        case 0:
            return "-";
        case 1:
            return (gender >= 127) ? "♂" : "♀";
        case 2:
            return (gender >= 191) ? "♂" : "♀";
        case 3:
            return (gender >= 63) ? "♂" : "♀";
        case 4:
            return (gender >= 31) ? "♂" : "♀";
        case 5:
            return "♂";
        case 6:
        default:
            return "♀";
    }
}

// Returns string equivalent of nature
QString Frame::getNatureString()
{
    return natures[static_cast<int>(nature)];
}

// Returns string equivalent of hidden power
QString Frame::getPowerString()
{
    return powers[static_cast<int>(hidden)];
}

// Returns !!! if shiny or blank if not
QString Frame::getShinyString()
{
    return shiny ? "!!!" : "";
}

// Change the tid/sid
void Frame::setIDs(u16 tid, u16 sid, u16 psv)
{
    this->tid = tid;
    this->sid = sid;
    this->psv = psv;
}

// Sets IVs for either Channel method or manual input and calculates characteristics based on IVs
void Frame::setIVsManual(u32 iv1, u32 iv2, u32 iv3, u32 iv4, u32 iv5, u32 iv6)
{
    ivs[0] = iv1;
    ivs[1] = iv2;
    ivs[2] = iv3;
    ivs[3] = iv4;
    ivs[4] = iv5;
    ivs[5] = iv6;
    hidden = ((((ivs[0] & 1) + 2 * (ivs[1] & 1) + 4 * (ivs[2] & 1) + 8 * (ivs[5] & 1) + 16 * (ivs[3] & 1) + 32 * (ivs[4] & 1)) * 15) / 63);
    power = (30 + ((((ivs[0] >> 1) & 1) + 2 * ((ivs[1] >> 1) & 1) + 4 * ((ivs[2] >> 1) & 1) + 8 * ((ivs[5] >> 1) & 1) + 16 * ((ivs[3] >> 1) & 1) + 32 * ((ivs[4] >> 1) & 1)) * 40 / 63));
}

// Sets IVs and calculates characteristics based on IVs
void Frame::setIVs(u32 iv1, u32 iv2)
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
void Frame::setPID(u32 pid1, u32 pid2)
{
    pid = (pid2 << 16) | pid1;
    nature = pid % 25;
    gender = pid & 255;
    ability = pid & 1;
    shiny = (pid1 ^ pid2 ^ psv) < 8;
}

// Sets PID and calculates characteristics based on PID
void Frame::setPID(u32 pid, u32 pid1, u32 pid2)
{
    this->pid = pid;
    gender = pid & 255;
    ability = pid & 1;
    shiny = (pid1 ^ pid2 ^ psv) < 8;
}

void Frame::setPID(u32 pid)
{
    this->pid = pid;
    nature = pid % 25;
    gender = pid & 255;
    ability = pid & 1;
    shiny = ((pid >> 16) ^ (pid & 0xFFFF) ^ psv) < 8;
}

u32 Frame::getFrame() const
{
    return frame;
}

u32 Frame::getIV(int index) const
{
    return ivs[index];
}

u32 Frame::getPower() const
{
    return power;
}

u32 Frame::getPid() const
{
    return pid;
}

void Frame::setPid(const u32 &value)
{
    pid = value;
}

u32 Frame::getAbility() const
{
    return ability;
}

Lead Frame::getLeadType() const
{
    return leadType;
}

u32 Frame::getEncounterSlot() const
{
    return encounterSlot;
}

void Frame::setEncounterSlot(const u32 &value)
{
    encounterSlot = value;
}

u32 Frame::getLevel() const
{
    return level;
}

void Frame::setLevel(const u32 &value)
{
    level = value;
}

bool Frame::getShiny() const
{
    return shiny;
}

u32 Frame::getNature() const
{
    return nature;
}

void Frame::setNature(const u32 &value)
{
    nature = value;
}

u32 Frame::getHidden() const
{
    return hidden;
}

u32 Frame::getGender() const
{
    return gender;
}

u32 Frame::getGenderRatio() const
{
    return genderRatio;
}

void Frame::setGenderRatio(const u32 &value)
{
    genderRatio = value;
}

void Frame::setFrame(const u32 &value)
{
    frame = value;
}

void Frame::setLeadType(const Lead &value)
{
    leadType = value;
}
