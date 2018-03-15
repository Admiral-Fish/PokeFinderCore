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

#include "Utilities.hpp"

// Returns initial seed for Ruby/Sapphire live battery given date and time
u32 Utilities::calcGen3Seed(QDate time, u32 h, u32 m)
{
    u32 d = QDate(time.year() == 2000 ? 1999 : 2000, 12, 31).daysTo(time);

    u32 seed = 1440 * d + 960 * (h / 10) + 60 * (h % 10) + 16 * (m / 10) + m % 10;
    return (seed >> 16) ^ (seed & 0xFFFF);
}

bool Utilities::shiny(u32 pid, u32 tid, u32 sid)
{
    return (((pid & 0xFFFF) ^ (pid >> 16) ^ tid ^ sid) < 8);
}
