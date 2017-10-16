/*
 * This file is part of PokéFinder
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

#ifndef SEARCHERGEN3_HPP
#define SEARCHERGEN3_HPP
#include <libPokeFinder/Gen3/FrameGen3.hpp>
#include <libPokeFinder/Gen3/NatureLock.hpp>
#include <libPokeFinder/Objects/Searcher.hpp>
#include <libPokeFinder/RNG/RNGCache.hpp>
#include <libPokeFinder/RNG/RNGEuclidean.hpp>

class SearcherGen3: public Searcher
{

private:
    RNGCache cache = RNGCache(Method1);
    RNGEuclidean euclidean = RNGEuclidean(XDColo);
    FrameGen3 frame = FrameGen3(0, 0, 0);
    LCRNG rng = PokeRNG(0);
    NatureLock natureLock = NatureLock();

    std::vector<FrameGen3> searchMethodChannel(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethodColo(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethodH1(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethodH2(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethodH4(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethodXD(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethodXDColo(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethod1(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethod2(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    std::vector<FrameGen3> searchMethod4(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);



public:

    SearcherGen3();

    SearcherGen3(uint32_t tid, uint32_t sid);

    std::vector<FrameGen3> Search(uint32_t hp, uint32_t atk, uint32_t def, uint32_t spa, uint32_t spd, uint32_t spe, FrameCompare compare);

    void SetMethod(Method frameType);
};

#endif // SEARCHERGEN3_HPP
