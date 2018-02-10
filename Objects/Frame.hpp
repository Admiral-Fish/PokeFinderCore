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
#include <vector>

using std::vector;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;

class Frame
{

protected:
    vector<QString> natures = Nature::getFrameNatures();
    vector<QString> powers = Power::getPowers();

public:
    u32 ivs[6];
    u32 ability;
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
    u16 psv;
    bool shiny;
    u16 sid;
    bool synchable;
    u16 tid;

    QString getFemale125();
    QString getFemale25();
    QString getFemale50();
    QString getFemale75();
    QString getNature();
    QString getPower();
    QString getShiny();
    void setIVs(u32 iv1, u32 iv2);
    void setPID(u32 pid1, u32 pid2);
    void setPID(u32 pid, u32 pid1, u32 pid2);

};

#endif // FRAME_HPP
