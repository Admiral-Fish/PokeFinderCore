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

#include "Frame3.hpp"

Frame3::Frame3()
{
    tid = 12345;
    sid = 54321;
    psv = 12345 ^ 54321;
}

Frame3::Frame3(u16 tid, u16 sid, u16 psv)
{
    this->tid = tid;
    this->sid = sid;
    this->psv = psv;
}

QString Frame3::getTime()
{
    int seconds = frame / 60;
    int milliseconds = ((frame % 60) * 100) / 60;
    if (seconds < 60)
    {
        return QString("%1.%2 s").arg(seconds).arg(milliseconds, 2, 10, QChar('0'));
    }

    int minutes = frame / 3600;
    seconds -= minutes * 60;
    if (minutes < 60)
    {
        return QString("%1 m %2.%3 s").arg(minutes).arg(seconds).arg(milliseconds, 2, 10, QChar('0'));
    }

    int hours = minutes / 60;
    minutes -= 60 * hours;

    return QString("%1 h %2 m %3.%4 s").arg(hours).arg(minutes).arg(seconds).arg(milliseconds, 2, 10, QChar('0'));
}

QString Frame3::getTimeEgg()
{
    int seconds = occidentary / 60;
    int milliseconds = ((occidentary % 60) * 100) / 60;
    if (seconds < 60)
    {
        return QString("%1.%2 s").arg(seconds).arg(milliseconds, 2, 10, QChar('0'));
    }

    int minutes = occidentary / 3600;
    seconds -= minutes * 60;
    if (minutes < 60)
    {
        return QString("%1 m %2.%3 s").arg(minutes).arg(seconds).arg(milliseconds, 2, 10, QChar('0'));
    }

    int hours = minutes / 60;
    minutes -= 60 * hours;

    return QString("%1 h %2 m %3.%4 s").arg(hours).arg(minutes).arg(seconds).arg(milliseconds, 2, 10, QChar('0'));
}

void Frame3::setInheritanceEmerald(u16 iv1, u16 iv2, u16 par1, u16 par2, u16 par3, u16 inh1, u16 inh2, u16 inh3, QVector<u8> parent1, QVector<u8> parent2)
{
    ivs[0] = iv1 & 0x1f;
    ivs[1] = (iv1 >> 5) & 0x1f;
    ivs[2] = (iv1 >> 10) & 0x1f;
    ivs[3] = (iv2 >> 5) & 0x1f;
    ivs[4] = (iv2 >> 10) & 0x1f;
    ivs[5] = iv2 & 0x1f;

    switch (inh1)
    {
        case 0:
            ivs[0] = par1 == 0 ? parent1[0] : parent2[0];
            break;
        case 1:
            ivs[1] = par1 == 0 ? parent1[1] : parent2[1];
            break;
        case 2:
            ivs[2] = par1 == 0 ? parent1[2] : parent2[2];
            break;
        case 3:
            ivs[3] = par1 == 0 ? parent1[3] : parent2[3];
            break;
        case 4:
            ivs[4] = par1 == 0 ? parent1[4] : parent2[4];
            break;
        case 5:
            ivs[5] = par1 == 0 ? parent1[5] : parent2[5];
            break;
    }

    switch (inh2)
    {
        case 1:
            ivs[1] = par2 == 0 ? parent1[1] : parent2[1];
            break;
        case 2:
            ivs[2] = par2 == 0 ? parent1[2] : parent2[2];
            break;
        case 3:
            ivs[3] = par2 == 0 ? parent1[3] : parent2[3];
            break;
        case 4:
            ivs[4] = par2 == 0 ? parent1[4] : parent2[4];
            break;
        case 5:
            ivs[5] = par2 == 0 ? parent1[5] : parent2[5];
            break;
    }

    switch (inh3)
    {
        case 1:
            ivs[1] = par3 == 0 ? parent1[1] : parent2[1];
            break;
        case 3:
            ivs[3] = par3 == 0 ? parent1[3] : parent2[3];
            break;
        case 4:
            ivs[4] = par3 == 0 ? parent1[4] : parent2[4];
            break;
        case 5:
            ivs[5] = par3 == 0 ? parent1[5] : parent2[5];
            break;
    }

    hidden = ((((ivs[0] & 1) + 2 * (ivs[1] & 1) + 4 * (ivs[2] & 1) + 8 * (ivs[5] & 1) + 16 * (ivs[3] & 1) + 32 * (ivs[4] & 1)) * 15) / 63);
    power = (30 + ((((ivs[0] >> 1) & 1) + 2 * ((ivs[1] >> 1) & 1) + 4 * ((ivs[2] >> 1) & 1) + 8 * ((ivs[5] >> 1) & 1) + 16 * ((ivs[3] >> 1) & 1) + 32 * ((ivs[4] >> 1) & 1)) * 40 / 63));
}

void Frame3::setInheritance(u16 iv1, u16 iv2, u16 par1, u16 par2, u16 par3, u16 inh1, u16 inh2, u16 inh3, QVector<u8> parent1, QVector<u8> parent2)
{
    ivs[0] = iv1 & 0x1f;
    ivs[1] = (iv1 >> 5) & 0x1f;
    ivs[2] = (iv1 >> 10) & 0x1f;
    ivs[3] = (iv2 >> 5) & 0x1f;
    ivs[4] = (iv2 >> 10) & 0x1f;
    ivs[5] = iv2 & 0x1f;

    u8 available[6] =  { 0, 1, 2, 3, 4, 5 };
    u16 val[6] = { inh1, inh2, inh3, par1, par2, par3 };

    for (u8 cnt = 0; cnt < 3; cnt++)
    {
        // Decide which parent (1 or 2) from which we'll pick an IV
        u8 par = val[3 + cnt] & 1;

        // Decide which stat to pick for IV inheritance
        u8 ivslot = available[val[cnt] % (6 - cnt)];

        switch (ivslot)
        {
            case 0:
                ivs[0] = par == 0 ? parent1[0] : parent2[0];
                break;
            case 1:
                ivs[1] = par == 0 ? parent1[1] : parent2[1];
                break;
            case 2:
                ivs[2] = par == 0 ? parent1[2] : parent2[2];
                break;
            case 3:
                ivs[5] = par == 0 ? parent1[5] : parent2[5];
                break;
            case 4:
                ivs[3] = par == 0 ? parent1[3] : parent2[3];
                break;
            case 5:
                ivs[4] = par == 0 ? parent1[4] : parent2[4];
                break;
        }

        // Avoids repeat IV inheritance
        for (u8 i = ivslot; i < 5; i++)
        {
            available[i] = available[i + 1];
        }
    }

    hidden = ((((ivs[0] & 1) + 2 * (ivs[1] & 1) + 4 * (ivs[2] & 1) + 8 * (ivs[5] & 1) + 16 * (ivs[3] & 1) + 32 * (ivs[4] & 1)) * 15) / 63);
    power = (30 + ((((ivs[0] >> 1) & 1) + 2 * ((ivs[1] >> 1) & 1) + 4 * ((ivs[2] >> 1) & 1) + 8 * ((ivs[5] >> 1) & 1) + 16 * ((ivs[3] >> 1) & 1) + 32 * ((ivs[4] >> 1) & 1)) * 40 / 63));
}

QString Frame3::getLockReason() const
{
    return lockReason;
}

void Frame3::setLockReason(const QString &value)
{
    lockReason = value;
}

u32 Frame3::getOccidentary() const
{
    return occidentary;
}

void Frame3::setOccidentary(const u32 &value)
{
    occidentary = value;
}

u32 Frame3::getSeed() const
{
    return seed;
}

void Frame3::setSeed(const u32 &value)
{
    seed = value;
}

void Frame3::xorFrame(bool flag)
{
    if (flag)
    {
        seed ^= 0x80000000;
    }
    pid ^= 0x80008000;
    nature = pid % 25;
}
