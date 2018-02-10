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

#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include <libPokeFinder/Objects/FrameCompare.hpp>
#include <libPokeFinder/Objects/Encounter.hpp>
#include <libPokeFinder/Objects/EncounterSlot.hpp>
#include <libPokeFinder/Objects/Lead.hpp>
#include <libPokeFinder/Objects/Method.hpp>
#include <libPokeFinder/RNG/IRNG.hpp>
#include <vector>

using std::vector;
typedef uint32_t u32;
typedef uint16_t u16;

class Generator
{

protected:
    u16 psv;
    vector<u32> rngList;
    u16 sid;
    u16 tid;
    u32 offset;

public:
    Method frameType = Method1;
    Encounter encounterType = Stationary;
    Lead leadType = None;
    u32 initialSeed;
    u32 initialFrame;
    u32 maxResults;
    u32 synchNature;
    u32 cuteCharm;

};

#endif // GENERATOR_HPP
