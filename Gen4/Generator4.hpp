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

#include <Gen4/EncounterArea4.hpp>
#include <Gen4/Frame4.hpp>
#include <Objects/FrameCompare.hpp>
#include <Objects/Generator.hpp>
#include <RNG/LCRNG.hpp>

class Generator4 : public Generator
{

public:
    Generator4();
    Generator4(u32 maxResults, u32 initialFrame, u32 initialSeed, u16 tid, u16 sid, u32 offset, Method type);
    ~Generator4();
    void setEncounter(const EncounterArea4 &value);
    QVector<Frame4> generate(const FrameCompare &compare);

private:
    PokeRNG *rng = nullptr;
    EncounterArea4 encounter;

    QVector<Frame4> generateMethod1(FrameCompare compare);
    QVector<Frame4> generateMethodJ(FrameCompare compare);
    QVector<Frame4> generateMethodJSynch(FrameCompare compare);
    QVector<Frame4> generateMethodJCuteCharm(FrameCompare compare);
    QVector<Frame4> generateMethodK(FrameCompare compare);
    QVector<Frame4> generateMethodKSynch(FrameCompare compare);
    QVector<Frame4> generateMethodKCuteCharm(FrameCompare compare);
    QVector<Frame4> generateChainedShiny(FrameCompare compare);
    QVector<Frame4> generateWondercardIVs(FrameCompare compare);
    u16 chainedPIDLow(u16 low, u16 call1, u16 call2, u16 call3, u16 call4, u16 call5,
                      u16 call6, u16 call7, u16 call8, u16 call9, u16 call10, u16 call11,
                      u16 call12, u16 call13);
    u16 chainedPIDHigh(u16 high, u16 low, u16 tid, u16 sid);

};

#endif // GENERATOR4_HPP
