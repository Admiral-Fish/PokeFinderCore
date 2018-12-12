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

#ifndef SEARCHER4_HPP
#define SEARCHER4_HPP

#include <Gen4/EncounterArea4.hpp>
#include <Gen4/Frame4.hpp>
#include <Objects/Searcher.hpp>
#include <RNG/RNGCache.hpp>

class Searcher4 : public Searcher
{

private:
    RNGCache *cache = nullptr;
    Frame4 frame = Frame4(0, 0, 0);
    PokeRNGR *backward = nullptr;
    EncounterArea4 encounter;
    FrameCompare compare;
    const u32 unbiasedBuffer[5] = { 0, 0x96, 0xC8, 0x4B, 0x32 };
    u32 minDelay;
    u32 maxDelay;
    u32 minFrame;
    u32 maxFrame;

    QVector<Frame4> searchMethod1(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodJ(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodJSynch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodJCuteCharm(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodJSearch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodK(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodKSynch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodKCuteCharm(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodKSuctionCups(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchMethodKSearch(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchChainedShiny(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchWondercardIVs(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    QVector<Frame4> searchInitialSeeds(QVector<Frame4> results);
    u16 chainedPIDLow(const u16 *calls);
    u16 chainedPIDHigh(u16 high, u16 low, u16 tid, u16 sid);

public:
    Searcher4();
    Searcher4(u16 tid, u16 sid, u32 ratio, u32 minDelay, u32 maxDelay, u32 minFrame, u32 maxFrame, const FrameCompare &compare, Method method);
    ~Searcher4();
    QVector<Frame4> search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);
    void setEncounter(const EncounterArea4 &value);
};

#endif // SEARCHER4_HPP
