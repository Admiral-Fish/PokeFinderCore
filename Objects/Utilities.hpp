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

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <QDateTime>
#include <QString>
#include <QVector>
#include <PokeFinderCore/RNG/MTRNG.hpp>
#include <PokeFinderCore/RNG/LCRNG.hpp>
#include <PokeFinderCore/Gen4/HGSSRoamer.hpp>

typedef uint32_t u32;

class Utilities
{

public:
    static u32 calcGen3Seed(QDate time, u32 h, u32 m);
    static u32 calcGen4Seed(QDateTime dateTime, u32 delay);
    static bool shiny(u32 pid, u32 tid, u32  sid);
    static QString coinFlips(u32 seed, int flips);
    static QString getCalls(u32 seed, int num, HGSSRoamer info);

};

#endif // UTILITIES_HPP
