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

#ifndef EGG4_HPP
#define EGG4_HPP

#include <PokeFinderCore/Objects/Egg.hpp>
#include <PokeFinderCore/Gen4/Frame4.hpp>
#include <PokeFinderCore/Objects/FrameCompare.hpp>
#include <PokeFinderCore/RNG/LCRNG.hpp>
#include <PokeFinderCore/RNG/MTRNG.hpp>

class Egg4 : public Egg
{

private:
    QVector<u32> parent1;
    QVector<u32> parent2;
    const u32 HABCDS[6] = { 0, 1, 2, 5, 3, 4 };
    const u32 ABCDS[5] = { 1, 2, 5, 3, 4 };
    const u32 ACDS[4] = { 1, 5, 3, 4 };

    QVector<Frame4> generatePID(FrameCompare compare);
    QVector<Frame4> generatePIDMasuada(FrameCompare compare);
    QVector<Frame4> generateIVsDPPt(FrameCompare compare);
    QVector<Frame4> generateIVsHGSS(FrameCompare compare);

public:
    Egg4();
    Egg4(u32 maxFrame, u32 initialFrame, u16 tid, u16 sid, Method method, u32 seed);
    QVector<Frame4> generate(FrameCompare compare);
    void setParents(QVector<u32> parent1, QVector<u32> parent2);

};

#endif // EGG4_HPP
