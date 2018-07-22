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

#ifndef HGSSROAMER_HPP
#define HGSSROAMER_HPP

#include <QVector>
#include <cstdint>
#include <PokeFinderCore/RNG/LCRNG.hpp>
#include <QString>

typedef uint32_t u32;

class HGSSRoamer
{

private:
    u32 getRouteJ(u32 prng);
    u32 getRouteK(u32 prng);

    int skips = 0;
    u32 raikouRoute;
    u32 enteiRoute;
    u32 latiRoute;
    QVector<bool> roamers;

public:
    HGSSRoamer() {}
    HGSSRoamer(u32 seed, QVector<bool> roamers, QVector<u32> routes);
    int getSkips() const;
    u32 getRaikouRoute() const;
    u32 getEnteiRoute() const;
    u32 getLatiRoute() const;
    QString getRoutes();

};

#endif // HGSSROAMER_HPP
