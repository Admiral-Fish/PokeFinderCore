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

#ifndef RNGCACHE_HPP
#define RNGCACHE_HPP

#include <PokeFinderCore/Objects/Method.hpp>
#include <QVector>
#include <QHash>

typedef uint32_t u32;

class RNGCache
{

private:
    u32 add;
    u32 k;
    u32 mult;
    QHash<u32, u32> keys;

    void populateMap();
    void setupCache(Method MethodType);

public:
    RNGCache(Method MethodType);
    QVector<u32> recoverLower16BitsIV(u32 first, u32 second);
    QVector<u32> recoverLower16BitsPID(u32 first, u32 second);
    void switchCache(Method MethodType);

};

#endif // RNGCACHE_HPP
