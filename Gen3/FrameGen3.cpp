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

#include "FrameGen3.hpp"

FrameGen3::FrameGen3(u32 tid, u32 sid, u32 psv)
{
    this->tid = tid;
    this->sid = sid;
    this->psv = psv;
}

// Returns real time for a given frame
QString FrameGen3::GetTime()
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
void FrameGen3::SetIDs(u32 tid, u32 sid, u32 psv)
{
    this->tid = tid;
    this->sid = sid;
    this->psv = psv;
}

// Sets IVs for either Channel method or manual input and calculates characteristics based on IVs
void FrameGen3::SetIVsManual(u32 iv1, u32 iv2, u32 iv3, u32 iv4, u32 iv5, u32 iv6)
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

QList<QStandardItem *> FrameGen3::GetTableRow(int genderRatioIndex)
{
    QList<QStandardItem *> row;
    row.append(new QStandardItem(QString::number(frame)));
    row.append(new QStandardItem(QString::number(pid, 16).toUpper().rightJustified(8,'0')));
    row.append(new QStandardItem(GetShiny()));
    row.append(new QStandardItem(GetNature()));
    row.append(new QStandardItem(QString::number(ability)));
    row.append(new QStandardItem(QString::number(ivs[0])));
    row.append(new QStandardItem(QString::number(ivs[1])));
    row.append(new QStandardItem(QString::number(ivs[2])));
    row.append(new QStandardItem(QString::number(ivs[3])));
    row.append(new QStandardItem(QString::number(ivs[4])));
    row.append(new QStandardItem(QString::number(ivs[5])));
    row.append(new QStandardItem(GetPower()));
    row.append(new QStandardItem(QString::number(power)));
    switch(genderRatioIndex)
    {
        case 1:
            row.append(new QStandardItem(GetFemale50()));
            break;
        case 2:
            row.append(new QStandardItem(GetFemale75()));
            break;
        case 3:
            row.append(new QStandardItem(GetFemale25()));
            break;
        case 4:
            row.append(new QStandardItem(GetFemale125()));
            break;
        case 5:
            row.append(new QStandardItem(QString("M")));
            break;
        case 6:
            row.append(new QStandardItem(QString("F")));
            break;
        default:
            row.append(new QStandardItem(QString("-")));
            break;
    }
    row.append(new QStandardItem(GetTime()));

    for(int i = 0; i < row.count(); i++)
    {
        row.at(i)->setData(Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    return row;
}
