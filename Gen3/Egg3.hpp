/*
 * This file is part of libPokéFinder
 * Copyright (C) 2017 by Admiral_Fish, bumba, and EzPzStreamz
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

#ifndef EGG3_HPP
#define EGG3_HPP

#include <PokeFinderCore/Objects/Egg.hpp>
#include <PokeFinderCore/Gen3/Frame3.hpp>
#include <PokeFinderCore/Objects/FrameCompare.hpp>
#include <PokeFinderCore/RNG/LCRNG.hpp>

class Egg3 : public Egg
{

private:
    LCRNG rng = PokeRNG(0);
    vector<u32> parent1;
    vector<u32> parent2;
    const u32 HABCDS[6] = { 0, 1, 2, 5, 3, 4 };
    const u32 ABCDS[5] = { 1, 2, 5, 3, 4 };
    const u32 ACDS[4] = { 1, 5, 3, 4 };

    vector<Frame3> generateEmeraldPID(FrameCompare compare);
    vector<Frame3> generateEmerald(FrameCompare compare);
    vector<Frame3> generateEmeraldSplit(FrameCompare compare);
    vector<Frame3> generateEmeraldAlternate(FrameCompare compare);
    vector<Frame3> generateLower();
    vector<Frame3> generateUpper(vector<Frame3> lower, FrameCompare compare);

public:
    Egg3();
    Egg3(u32 maxFrame, u32 initialFrame, u16 tid, u16 sid, Method method, u32 seed = 0);
    vector<Frame3> generate(FrameCompare compare);
    void setParents(vector<u32> parent1, vector<u32> parent2);

    u32 calibration;
    u32 minRedraw;
    u32 maxRedraw;
    u32 compatability;
    u32 minPickup;
    u32 maxPickup;
    u32 seed;
    bool everstone;

};

#endif // EGG3_HPP
