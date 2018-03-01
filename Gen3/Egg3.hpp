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

#ifndef EGG3_HPP
#define EGG3_HPP

#include <libPokeFinder/Objects/Egg.hpp>
#include <libPokeFinder/Gen3/Frame3.hpp>
#include <libPokeFinder/Objects/FrameCompare.hpp>
#include <libPokeFinder/RNG/LCRNG.hpp>

class Egg3 : public Egg
{

private:
    LCRNG rng = PokeRNG(0);

    vector<Frame3> generateEmeraldPID(FrameCompare compare);
    void refill();

public:
    Egg3();
    Egg3(u32 maxFrame, u32 initialFrame, u16 tid, u16 sid, Method method, u32 seed = 0);
    vector<Frame3> generate(FrameCompare compare);

    u32 calibration;
    u32 minRedraw;
    u32 maxRedraw;
    u32 compatability;
    bool everstone;

};

#endif // EGG3_HPP
