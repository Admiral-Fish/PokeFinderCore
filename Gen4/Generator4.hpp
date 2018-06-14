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

#ifndef GENERATOR4_HPP
#define GENERATOR4_HPP

#include <PokeFinderCore/Gen4/Frame4.hpp>
#include <PokeFinderCore/Objects/Generator.hpp>
#include <PokeFinderCore/Objects/FrameCompare.hpp>
#include <PokeFinderCore/RNG/LCRNG.hpp>

class Generator4 : public Generator
{

private:
    PokeRNG *rng = NULL;
    u32 size;

    vector<Frame4> generateMethod1(FrameCompare compare);
    vector<Frame4> generateMethodJ(FrameCompare compare);
    vector<Frame4> generateMethodJSynch(FrameCompare compare);
    vector<Frame4> generateMethodJCuteCharm(FrameCompare compare);
    vector<Frame4> generateMethodK(FrameCompare compare);
    vector<Frame4> generateMethodKSynch(FrameCompare compare);
    vector<Frame4> generateMethodKCuteCharm(FrameCompare compare);
    vector<Frame4> generateChainedShiny(FrameCompare compare);
    vector<Frame4> generateWondercardIVs(FrameCompare compare);
    u32 chainedPIDLow(u32 low, u32 call1, u32 call2, u32 call3, u32 call4, u32 call5,
                      u32 call6, u32 call7, u32 call8, u32 call9, u32 call10, u32 call11,
                      u32 call12, u32 call13);
    u32 chainedPIDHigh(u32 high, u32 low, u32 tid, u32 sid);
    void refill();

public:
    Generator4();
    Generator4(u32 maxResults, u32 initialFrame, u32 initialSeed, u16 tid, u16 sid, u32 offset, Method type);
    ~Generator4();
    vector<Frame4> generate(FrameCompare compare);

};

#endif // GENERATOR4_HPP
