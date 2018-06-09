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

HGSSRoamer::HGSSRoamer(u32 seed, vector<bool> roamers, vector<u32> routes)
{
    PokeRNG rng(seed);
    this->roamers = roamers;

    if (roamers[0])
    {
        while (true)
        {
            skips++;
            u32 route = getRouteJ(rng.nextUShort());

            if (routes[0] != route)
            {
                raikouRoute = route;
                break;
            }
        }
    }

    if (roamers[1])
    {
        while (true)
        {
            skips++;
            u32 route = getRouteJ(rng.nextUShort());

            if (routes[1] != route)
            {
                enteiRoute = route;
                break;
            }
        }
    }

    if (roamers[2])
    {
        while (true)
        {
            skips++;
            u32 route = getRouteK(rng.nextUShort());

            if (routes[2] != route)
            {
                latiRoute = route;
                break;
            }
        }
    }
}

u32 HGSSRoamer::getSkips() const
{
    return skips;
}

u32 HGSSRoamer::getRaikouRoute() const
{
    return raikouRoute;
}

u32 HGSSRoamer::getEnteiRoute() const
{
    return enteiRoute;
}

u32 HGSSRoamer::getLatiRoute() const
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
        routes += "L: " + QString::number(latiRoute) + " ";

    return routes;
}

u32 HGSSRoamer::getRouteJ(u32 prng)
{
    u32 route = 0;

    u32 val = prng & 15;

    if (val < 11)
        route = val + 29;
    else
        route = val + 31;

    return route;
}

u32 HGSSRoamer::getRouteK(u32 prng)
{
    u32 route = 0;

    u32 val = prng % 25;

    if (val < 22)
        route = val + 1;
    else
        switch (val)
        {
            case 22:
                route = 24;
                break;
            case 23:
                route = 26;
                break;
            case 24:
                route = 28;
                break;
        }

    return route;
}
