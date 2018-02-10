/*
 * This file is part of libPokéFinder
 * Copyright (C) 2017 by Admiral_Fish and bumba
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

#ifndef FRAME3_HPP
#define FRAME3_HPP

#include <libPokeFinder/Objects/Frame.hpp>

class Frame3: public Frame
{

public:
    QString lockReason;
    u32 occidentary;
    u32 seed;

    Frame3(u16 tid, u16 sid, u16 psv);
    QString getTime();
    void setIDs(u16 tid, u16 sid, u16 psv);
    void setIVsManual(u32 iv1, u32 iv2, u32 iv3, u32 iv4, u32 iv5, u32 iv6);

};

#endif // FRAME3_HPP
