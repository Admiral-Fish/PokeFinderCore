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

#include "HGSSRoamer.hpp"

HGSSRoamer::HGSSRoamer(u32 seed, QVector<bool> roamers, QVector<u16> routes)
{
    PokeRNG rng(seed);
    this->roamers = roamers;

    if (roamers[0])
    {
        do
        {
            skips++;
            raikouRoute = getRouteJ(rng.nextUShort());
        }
        while (routes[0] != raikouRoute);
    }

    if (roamers[1])
    {
        do
        {
            skips++;
            enteiRoute = getRouteJ(rng.nextUShort());
        }
        while (routes[1] != enteiRoute);
    }

    if (roamers[2])
    {
        do
        {
            skips++;
            latiRoute = getRouteK(rng.nextUShort());
        }
        while (routes[2] != latiRoute);
    }
}

int HGSSRoamer::getSkips() const
{
    return skips;
}

u16 HGSSRoamer::getRaikouRoute() const
{
    return raikouRoute;
}

u16 HGSSRoamer::getEnteiRoute() const
{
    return enteiRoute;
}

u16 HGSSRoamer::getLatiRoute() const
{
    return latiRoute;
}

QString HGSSRoamer::getRoutes()
{
    QString routes = "";

    if (roamers[0])
        routes += "R: " + QString::number(raikouRoute) + " ";
    if (roamers[1])
        routes += "E: " + QString::number(enteiRoute) + " ";
    if (roamers[2])
        routes += "L: " + QString::number(latiRoute);

    return routes;
}

u16 HGSSRoamer::getRouteJ(u16 prng)
{
    u16 val = prng & 15;

    if (val < 11)
        return val + 29;
    else
        return val + 31;
}

u16 HGSSRoamer::getRouteK(u16 prng)
{
    u16 val = prng % 25;

    if (val > 21)
        switch (val)
        {
            case 22:
                return 24;
            case 23:
                return 26;
            case 24:
                return 28;
        }

    return val + 1;
}
