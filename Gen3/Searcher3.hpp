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

#ifndef SEARCHER3_HPP
#define SEARCHER3_HPP

#include <Gen3/EncounterArea3.hpp>
#include <Gen3/Frame3.hpp>
#include <Gen3/NatureLock.hpp>
#include <Objects/Searcher.hpp>
#include <RNG/RNGCache.hpp>
#include <RNG/RNGEuclidean.hpp>

class Searcher3: public Searcher
{

private:
    RNGCache *cache = nullptr;
    RNGEuclidean *euclidean = nullptr;
    Frame3 frame = Frame3(0, 0, 0);
    LCRNG *forward = nullptr;
    LCRNG *backward = nullptr;
    NatureLock *natureLock = nullptr;
    ShadowType type;
    FrameCompare compare;
    EncounterArea3 encounter;

    QVector<Frame3> searchMethodChannel(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame3> searchMethodColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame3> searchMethodH124(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame3> searchMethodXD(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame3> searchMethodXDColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame3> searchMethod124(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame3> searchMethod1Reverse(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);

public:
    Searcher3();
    Searcher3(u16 tid, u16 sid, u32 ratio, const FrameCompare &compare);
    ~Searcher3();
    QVector<Frame3> search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    void setup(Method method);
    void setupNatureLock(int num);
    void setEncounter(const EncounterArea3 &value);

};

#endif // SEARCHER3_HPP
