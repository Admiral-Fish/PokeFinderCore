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

#ifndef GENERATOR3_HPP
#define GENERATOR3_HPP

#include <PokeFinderCore/Gen3/Frame3.hpp>
#include <PokeFinderCore/Objects/Generator.hpp>
#include <PokeFinderCore/Objects/FrameCompare.hpp>
#include <PokeFinderCore/RNG/LCRNG.hpp>
#include <PokeFinderCore/Gen3/EncounterArea3.hpp>

class Generator3: public Generator
{

private:
    u16 iv1;
    u16 iv2;
    LCRNG *rng = nullptr;
    EncounterArea3 encounter;

    QVector<Frame3> generateMethodChannel(FrameCompare compare);
    QVector<Frame3> generateMethodH124(FrameCompare compare);
    QVector<Frame3> generateMethodH124Synch(FrameCompare compare);
    QVector<Frame3> generateMethodH124CuteCharm(FrameCompare compare);
    QVector<Frame3> generateMethodXDColo(FrameCompare compare);
    QVector<Frame3> generateMethod124(FrameCompare compare);
    QVector<Frame3> generateMethod1Reverse(FrameCompare compare);
    static inline bool cuteCharm125F(u32 pid) { return (pid & 0xff) < 31; }
    static inline bool cuteCharm875M(u32 pid) { return (pid & 0xff) >= 31; }
    static inline bool cuteCharm25F(u32 pid) { return (pid & 0xff) < 63; }
    static inline bool cuteCharm75M(u32 pid) { return (pid & 0xff) >= 63; }
    static inline bool cuteCharm50F(u32 pid) { return (pid & 0xff) < 127; }
    static inline bool cuteCharm50M(u32 pid) { return (pid & 0xff) >= 127; }
    static inline bool cuteCharm75F(u32 pid) { return (pid & 0xff) < 191; }
    static inline bool cuteCharm25M(u32 pid) { return (pid & 0xff) >= 191; }

public:
    Generator3();
    Generator3(u32 maxResults, u32 initialFrame, u32 initialSeed, u16 tid, u16 sid, u32 offset);
    ~Generator3();
    QVector<Frame3> generate(FrameCompare compare);
    void setup(Method method);
    void setEncounter(const EncounterArea3 &value);

};

#endif // GENERATOR3_HPP
