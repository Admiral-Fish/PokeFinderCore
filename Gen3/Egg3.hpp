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

#ifndef EGG3_HPP
#define EGG3_HPP

#include <PokeFinderCore/Objects/Egg.hpp>
#include <PokeFinderCore/Gen3/Frame3.hpp>
#include <PokeFinderCore/Objects/FrameCompare.hpp>
#include <PokeFinderCore/RNG/LCRNG.hpp>

class Egg3 : public Egg
{

private:
    PokeRNG *rng = nullptr;
    QVector<u16> rngList;
    QVector<u32> parent1;
    QVector<u32> parent2;
    const u32 HABCDS[6] = { 0, 1, 2, 5, 3, 4 };
    const u32 ABCDS[5] = { 1, 2, 5, 3, 4 };
    const u32 ACDS[4] = { 1, 5, 3, 4 };
    u32 calibration;
    u32 minRedraw;
    u32 maxRedraw;
    u32 compatability;
    u32 minPickup;
    u32 maxPickup;
    bool everstone;

    QVector<Frame3> generateEmeraldPID(FrameCompare compare);
    QVector<Frame3> generateEmerald(FrameCompare compare);
    QVector<Frame3> generateEmeraldSplit(FrameCompare compare);
    QVector<Frame3> generateEmeraldAlternate(FrameCompare compare);
    QVector<Frame3> generateLower(FrameCompare compare);
    QVector<Frame3> generateUpper(QVector<Frame3> lower, FrameCompare compare);

public:
    Egg3();
    Egg3(u32 maxFrame, u32 initialFrame, u16 tid, u16 sid, Method method, u32 seed = 0);
    ~Egg3();
    QVector<Frame3> generate(FrameCompare compare);
    void setParents(QVector<u32> parent1, QVector<u32> parent2);
    void setMinRedraw(const u32 &value);
    void setMaxRedraw(const u32 &value);
    void setCompatability(const u32 &value);
    void setCalibration(const u32 &value);
    void setEverstone(bool value);
    void setMinPickup(const u32 &value);
    void setMaxPickup(const u32 &value);
    u32 getSeed() const;
    void setSeed(const u32 &value);

};

#endif // EGG3_HPP
