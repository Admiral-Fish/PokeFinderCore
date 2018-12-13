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

#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <QVector>
#include <Objects/Encounter.hpp>
#include <Objects/EncounterSlot.hpp>
#include <Objects/FrameCompare.hpp>
#include <Objects/Lead.hpp>
#include <Objects/Method.hpp>
#include <RNG/IRNG.hpp>

class Generator
{

public:
    Encounter getEncounterType() const;
    void setEncounterType(const Encounter &value);
    Lead getLeadType() const;
    void setLeadType(const Lead &value);
    u8 getSynchNature() const;
    void setSynchNature(const u8 &value);

protected:
    u16 psv;
    u16 sid;
    u16 tid;
    u32 offset;
    Method frameType = Method::Method1;
    Encounter encounterType = Encounter::Stationary;
    Lead leadType = Lead::None;
    u32 initialSeed;
    u32 initialFrame;
    u32 maxResults;
    u8 synchNature;
    u8 cuteCharm;

};

#endif // GENERATOR_HPP
