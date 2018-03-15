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

#ifndef SEARCHER3_HPP
#define SEARCHER3_HPP

#include <libPokeFinder/Gen3/Frame3.hpp>
#include <libPokeFinder/Gen3/NatureLock.hpp>
#include <libPokeFinder/Objects/Searcher.hpp>
#include <libPokeFinder/RNG/RNGCache.hpp>
#include <libPokeFinder/RNG/RNGEuclidean.hpp>
#include <QObject>

class Searcher3: public Searcher
{

private:
    RNGCache cache;
    RNGEuclidean euclidean = RNGEuclidean(XDColo);
    Frame3 frame = Frame3(0, 0, 0);
    LCRNG forward = PokeRNG(0);
    LCRNG backward = PokeRNGR(0);
    NatureLock natureLock;
    ShadowType type;

    vector<Frame3> searchMethodChannel(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethodColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethodH1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethodH2(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethodH4(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethodXD(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethodXDColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethod1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethod1Reverse(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethod2(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> searchMethod4(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);

public:
    Searcher3();
    Searcher3(u16 tid, u16 sid, u32 ratio);
    vector<Frame3> search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    void setup(Method method);
    void setupNatureLock(int num);

};

#endif // SEARCHER3_HPP
