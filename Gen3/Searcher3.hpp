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

#ifndef SEARCHER3_HPP
#define SEARCHER3_HPP

#include <QObject>
#include <libPokeFinder/Gen3/Frame3.hpp>
#include <libPokeFinder/Gen3/NatureLock.hpp>
#include <libPokeFinder/Objects/Searcher.hpp>
#include <libPokeFinder/RNG/RNGCache.hpp>
#include <libPokeFinder/RNG/RNGEuclidean.hpp>

typedef uint32_t u32;

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

    vector<Frame3> SearchMethodChannel(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethodColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethodH1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethodH2(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethodH4(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethodXD(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethodXDColo(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethod1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethod2(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    vector<Frame3> SearchMethod4(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);

public:
    Searcher3();
    Searcher3(u32 tid, u32 sid);
    vector<Frame3> Search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe, FrameCompare compare);
    void Setup(Method method);
    void SetupNatureLock(int num);

};

#endif // SEARCHER3_HPP
