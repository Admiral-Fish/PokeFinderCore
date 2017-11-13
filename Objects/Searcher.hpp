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

#ifndef SEARCHER_HPP
#define SEARCHER_HPP
#include <libPokeFinder/Objects/Encounter.hpp>
#include <libPokeFinder/Objects/EncounterSlot.hpp>
#include <libPokeFinder/Objects/FrameCompare.hpp>
#include <libPokeFinder/Objects/Lead.hpp>
#include <libPokeFinder/Objects/Method.hpp>
#include <libPokeFinder/RNG/LCRNG.hpp>
#include <cstdint>
#include <vector>

using namespace std;
typedef uint32_t u32;

class Searcher
{

protected:
    u32 psv;
    u32 sid;
    u32 tid;

public:
    u32 cuteCharm;
    Encounter encounterType = Stationary;
    Method frameType = Method1;
    Lead leadType = None;
    u32 synchNature;

};

#endif // SEARCHER_HPP
