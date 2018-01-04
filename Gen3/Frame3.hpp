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
#include <QList>
#include <QStandardItem>

class Frame3: public Frame
{

private:
    u32 ABCDS[5] = { 1, 2, 5, 3, 4 };
    u32 ACDS[4] = { 1, 5, 3, 4 };
    u32 HABCDS[6] = { 0, 1, 2, 5, 3, 4 };

public:
    u32 inh1;
    u32 inh2;
    u32 inh3;
    string lockReason;
    u32 occidentary;
    u32 par1;
    u32 par2;
    u32 par3;

    Frame3(u32 tid, u32 sid, u32 psv);

    QString GetTime();

    void SetIDs(u32 tid, u32 sid, u32 psv);

    void SetIVsManual(u32 iv1, u32 iv2, u32 iv3, u32 iv4, u32 iv5, u32 iv6);

    QList<QStandardItem *> GetTableRow(int genderRatioIndex);

};

#endif // FRAME3_HPP
