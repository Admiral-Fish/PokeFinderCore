/*
 * This file is part of libPokéFinder
 * Copyright (C) 2017 by Admiral_Fish, bumba, and EzPzStreamz
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

#ifndef IRNG64_HPP
#define IRNG64_HPP

#include <cstdint>

typedef uint64_t u64;
typedef uint32_t u32;

class IRNG64
{

public:
    virtual u64 nextULong() = 0;
    virtual u32 nextUInt() = 0;
    virtual void reseed(u64 seed) = 0;
    virtual void advanceFrames(int frames) = 0;
    virtual ~IRNG64() { }

};

#endif // IRNG64_HPP
