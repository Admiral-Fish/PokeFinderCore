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

#include "Frame3.hpp"

Frame3::Frame3(u16 tid, u16 sid, u16 psv)
{
    this->tid = tid;
    this->sid = sid;
    this->psv = psv;
}

// Returns real time for a given frame
QString Frame3::getTime()
{
    int32_t seconds = frame / 60;
    int32_t milliseconds = ((frame % 60) * 100) / 60;
    if (seconds < 60)
        return QString("%1.%2 s").arg(seconds).arg(milliseconds, 2, 10, QChar('0'));

    int32_t minutes = frame / 3600;
    seconds -= minutes * 60;
    if (minutes < 60)
        return QString("%1 m %2.%3 s").arg(minutes).arg(seconds).arg(milliseconds, 2, 10, QChar('0'));

    int32_t hours = minutes / 60;
    minutes -= 60 * hours;

    return QString("%1 h %2 m %3.%4 s").arg(hours).arg(minutes).arg(seconds).arg(milliseconds, 2, 10, QChar('0'));
}

// Change the tid/sid (mostly used for Channel)
void Frame3::setIDs(u16 tid, u16 sid, u16 psv)
{
    this->tid = tid;
    this->sid = sid;
    this->psv = psv;
}

// Sets IVs for either Channel method or manual input and calculates characteristics based on IVs
void Frame3::setIVsManual(u32 iv1, u32 iv2, u32 iv3, u32 iv4, u32 iv5, u32 iv6)
{
    ivs[0] = iv1;
    ivs[1] = iv2;
    ivs[2] = iv3;
    ivs[3] = iv4;
    ivs[4] = iv5;
    ivs[5] = iv6;
    hidden = ((((ivs[0] & 1) + 2 * (ivs[1] & 1) + 4 * (ivs[2] & 1) + 8 * (ivs[5] & 1) + 16 * (ivs[3] & 1) + 32 * (ivs[4] & 1)) * 15) / 63);
    power = (30 + ((((ivs[0] >> 1) & 1) + 2 * ((ivs[1] >> 1) & 1) + 4 * ((ivs[2] >> 1) & 1) + 8 * ((ivs[5] >> 1) & 1) + 16 * ((ivs[3] >> 1) & 1) + 32 * ((ivs[4] >> 1) & 1)) * 40 / 63));
}
