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

#include "Nature.hpp"

vector<QString> Nature::getNatures()
{
    vector<QString> natures = { QObject::tr("Adamant"), QObject::tr("Bold"), QObject::tr("Brave"), QObject::tr("Calm"),
                                QObject::tr("Careful"), QObject::tr("Hasty"), QObject::tr("Impish"), QObject::tr("Jolly"),
                                QObject::tr("Lonely"), QObject::tr("Mild"), QObject::tr("Modest"), QObject::tr("Naive"),
                                QObject::tr("Naughty"), QObject::tr("Quiet"), QObject::tr("Rash"), QObject::tr("Relaxed"),
                                QObject::tr("Sassy"), QObject::tr("Timid"), QObject::tr("Gentle"), QObject::tr("Lax"),
                                QObject::tr("Bashful"), QObject::tr("Docile"), QObject::tr("Hardy"), QObject::tr("Quirky"),
                                QObject::tr("Serious")
                              };
    return natures;
}

vector<QString> Nature::getFrameNatures()
{
    vector<QString> natures = { QObject::tr("Hardy"), QObject::tr("Lonely"), QObject::tr("Brave"), QObject::tr("Adamant"),
                                QObject::tr("Naughty"), QObject::tr("Bold"), QObject::tr("Docile"), QObject::tr("Relaxed"),
                                QObject::tr("Impish"), QObject::tr("Lax"), QObject::tr("Timid"), QObject::tr("Hasty"),
                                QObject::tr("Serious"), QObject::tr("Jolly"), QObject::tr("Naive"), QObject::tr("Modest"),
                                QObject::tr("Mild"), QObject::tr("Quiet"), QObject::tr("Bashful"), QObject::tr("Rash"),
                                QObject::tr("Calm"), QObject::tr("Gentle"), QObject::tr("Sassy"), QObject::tr("Careful"),
                                QObject::tr("Quirky")
                              };
    return natures;
}

u32 Nature::getAdjustedNature(u32 nature)
{
    u32 vals[25] = { 3, 5, 2, 20, 23, 11, 8, 13, 1, 16, 15, 14, 4, 17, 19, 7, 22, 10, 21, 9, 18, 6, 0, 24, 12 };
    return vals[nature];
}

u32 Nature::getReversedNature(u32 nature)
{
    u32 vals[25] = { 22, 8, 2, 0, 12, 1, 21, 15, 6, 19, 17, 5, 24, 7, 11, 10, 9, 13, 20, 14, 3, 18, 16, 4, 23 };
    return vals[nature];
}
