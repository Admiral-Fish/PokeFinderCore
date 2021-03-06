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

#ifndef ENCOUNTER_HPP
#define ENCOUNTER_HPP

// All the different encounter types wild pokémon can have
enum Encounter
{
    Grass               = 1 << 0,
    RockSmash           = 1 << 1,
    Surfing             = 1 << 2,
    OldRod              = 1 << 3,
    GoodRod             = 1 << 4,
    SuperRod            = 1 << 5,
    Stationary          = 1 << 6,
    SafariZone          = 1 << 7,
    BugCatchingContest  = 1 << 8,
    HeadButt            = 1 << 9
};

#endif // ENCOUNTER_HPP
