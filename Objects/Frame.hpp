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

#ifndef FRAME_HPP
#define FRAME_HPP

#include <QString>
#include <QVector>
#include <PokeFinderCore/Objects/Encounter.hpp>
#include <PokeFinderCore/Objects/Lead.hpp>
#include <PokeFinderCore/Objects/Method.hpp>
#include <PokeFinderCore/Objects/Nature.hpp>
#include <PokeFinderCore/Objects/Power.hpp>

using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;

class Frame
{

protected:
    u32 ivs[6];
    u32 ability;
    u32 encounterSlot;
    Encounter encounterType;
    u32 frame;
    u32 gender;
    u32 genderRatio;
    u32 hidden;
    Lead leadType;
    Method methodType;
    u32 nature;
    u32 pid;
    u32 power;
    u16 psv;
    bool shiny;
    u16 sid;
    u16 tid;
    u32 level;

    QString getFemale125();
    QString getFemale25();
    QString getFemale50();
    QString getFemale75();

public:
    QString getGenderString();
    QString getNatureString();
    QString getPowerString();
    QString getShinyString();
    void setIVsManual(u32 iv1, u32 iv2, u32 iv3, u32 iv4, u32 iv5, u32 iv6);
    void setIDs(u16 tid, u16 sid, u16 psv);
    void setIVs(u32 iv1, u32 iv2);
    void setPID(u32 pid1, u32 pid2);
    void setPID(u32 pid, u32 pid1, u32 pid2);
    void setPID(u32 pid);
    u32 getFrame() const;
    u32 getIV(int index) const;
    u32 getPower() const;
    u32 getPID() const;
    u32 getAbility() const;
    Lead getLeadType() const;
    u32 getEncounterSlot() const;
    void setEncounterSlot(const u32 &value);
    u32 getLevel() const;
    void setLevel(const u32 &value);
    bool getShiny() const;
    u32 getNature() const;
    void setNature(const u32 &value);
    u32 getHidden() const;
    u32 getGender() const;
    u32 getGenderRatio() const;
    void setGenderRatio(const u32 &value);
    void setFrame(const u32 &value);
    void setLeadType(const Lead &value);

};

#endif // FRAME_HPP
