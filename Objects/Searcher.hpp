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

#ifndef SEARCHER_HPP
#define SEARCHER_HPP

#include <PokeFinderCore/Objects/Encounter.hpp>
#include <PokeFinderCore/Objects/EncounterSlot.hpp>
#include <PokeFinderCore/Objects/FrameCompare.hpp>
#include <PokeFinderCore/Objects/Lead.hpp>
#include <PokeFinderCore/Objects/Method.hpp>
#include <PokeFinderCore/Objects/Utilities.hpp>
#include <PokeFinderCore/RNG/LCRNG.hpp>
#include <vector>

using std::vector;
typedef uint32_t u32;
typedef uint16_t u16;

class Searcher
{

protected:
    u16 psv;
    u16 sid;
    u16 tid;
    u32 cuteCharm;
    Encounter encounterType = Stationary;
    Method frameType = Method1;
    Lead leadType = None;
    u32 synchNature;

public:
    Encounter getEncounterType() const;
    void setEncounterType(const Encounter &value);
    Method getFrameType() const;
    void setFrameType(const Method &value);
    Lead getLeadType() const;
    void setLeadType(const Lead &value);

};

#endif // SEARCHER_HPP
