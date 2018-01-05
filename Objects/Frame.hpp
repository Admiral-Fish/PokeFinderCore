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

#ifndef FRAME_HPP
#define FRAME_HPP

#include <libPokeFinder/Objects/Encounter.hpp>
#include <libPokeFinder/Objects/Lead.hpp>
#include <libPokeFinder/Objects/Method.hpp>
#include <libPokeFinder/Objects/Nature.hpp>
#include <libPokeFinder/Objects/Power.hpp>
#include <QString>
#include <cstdint>
#include <vector>

using namespace std;
typedef uint32_t u32;

class Frame
{

protected:
    vector<QString> natures = Nature::GetFrameNatures();
    vector<QString> powers = Power::GetPowers();

public:
    u32 ivs[6];
    u32 ability;
    u32 dv1;
    u32 dv2;
    u32 encounterSlot;
    Encounter encounterType;
    u32 frame;
    u32 gender;
    u32 hidden;
    Lead leadType;
    Method methodType;
    u32 nature;
    u32 pid;
    u32 power;
    u32 psv;
    bool shiny;
    u32 sid;
    bool synchable;
    u32 tid;

    QString GetFemale125();
    QString GetFemale25();
    QString GetFemale50();
    QString GetFemale75();
    QString GetNature();
    QString GetPower();
    QString GetShiny();
    void SetIVs(u32 iv1, u32 iv2);
    void SetPID(u32 pid1, u32 pid2);
    void SetPID(u32 pid, u32 pid1, u32 pid2);

};

#endif // FRAME_HPP
