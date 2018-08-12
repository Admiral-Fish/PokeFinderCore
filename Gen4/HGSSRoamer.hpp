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
#include <QString>
#include <PokeFinderCore/RNG/LCRNG.hpp>

class HGSSRoamer
{

private:
    u16 getRouteJ(u16 prng);
    u16 getRouteK(u16 prng);

    int skips = 0;
    u16 raikouRoute;
    u16 enteiRoute;
    u16 latiRoute;
    QVector<bool> roamers;

public:
    HGSSRoamer() {}
    HGSSRoamer(u32 seed, QVector<bool> roamers, QVector<u16> routes);
    int getSkips() const;
    u16 getRaikouRoute() const;
    u16 getEnteiRoute() const;
    u16 getLatiRoute() const;
    QString getRoutes();

};

#endif // HGSSROAMER_HPP
