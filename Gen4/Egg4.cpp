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

#include "Egg4.hpp"

Egg4::Egg4()
{
    maxResults = 100000;
    initialFrame = 1;
    seed = 0;
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
}

Egg4::Egg4(u32 maxFrame, u32 initialFrame, u16 tid, u16 sid, Method method, u32 seed)
{
    maxResults = maxFrame;
    this->initialFrame = initialFrame;
    this->seed = seed;
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    frameType = method;

    if (frameType == Gen4Normal || frameType == Gen4Masuada)
        mt = new MersenneTwister(seed);
    else
        rng = new PokeRNG(seed);
}

Egg4::~Egg4()
{
    delete rng;
    delete mt;
}

QVector<Frame4> Egg4::generatePID(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());
    frame.setInitialSeed(seed);

    mt->setSeed(seed, initialFrame - 1);

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++)
    {
        frame.setPID(mt->nextUInt());

        if (compare.comparePID(frame))
        {
            frame.setFrame(cnt);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame4> Egg4::generatePIDMasuada(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());
    frame.setInitialSeed(seed);

    mt->setSeed(seed, initialFrame - 1);

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++)
    {
        u32 pid = mt->nextUInt();

        for (int i = 0; i <= 3; i++)
        {
            u32 val = (pid >> 16) ^ (pid & 0xFFFF);

            if ((val ^ psv) < 8)
                break;

            pid = pid * 0x6c078965 + 1; // Advance with ARNG
        }

        frame.setPID(pid);

        if (compare.comparePID(frame))
        {
            frame.setFrame(cnt);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame4> Egg4::generateIVsDPPt(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setInitialSeed(seed);

    rng->setSeed(seed, initialFrame - 1);

    for (int x = 0; x < 8; x++)
        rngList.append(rng->nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        iv1 = rngList[0];
        iv2 = rngList[1];
        inh1 = rngList[2];
        inh2 = rngList[3];
        inh3 = rngList[4];
        par1 = rngList[5];
        par2 = rngList[6];
        par3 = rngList[7];

        frame.setInheritanceDPPt(iv1, iv2, par1 & 1, par2 & 1, par3 & 1, HABCDS[inh1 % 6],
                                 ABCDS[inh2 % 5], ACDS[inh3 & 3], parent1, parent2);

        if (compare.compareIVs(frame))
        {
            frame.setSeed(rngList[0]);
            frame.setFrame(cnt);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame4> Egg4::generateIVsHGSS(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setInitialSeed(seed);

    rng->setSeed(seed, initialFrame - 1);

    for (int x = 0; x < 8; x++)
        rngList.append(rng->nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        iv1 = rngList[0];
        iv2 = rngList[1];
        inh1 = rngList[2];
        inh2 = rngList[3];
        inh3 = rngList[4];
        par1 = rngList[5];
        par2 = rngList[6];
        par3 = rngList[7];

        frame.setInheritanceHGSS(iv1, iv2, par1, par2, par3, inh1,
                                 inh2, inh3, parent1, parent2);

        if (compare.compareIVs(frame))
        {
            frame.setSeed(rngList[0]);
            frame.setFrame(cnt);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame4> Egg4::generate(FrameCompare compare)
{
    switch (frameType)
    {
        case Gen4Normal:
            return generatePID(compare);
        case Gen4Masuada:
            return generatePIDMasuada(compare);
        case DPPtIVs:
            return generateIVsDPPt(compare);
        case HGSSIVs:
            return generateIVsHGSS(compare);
        default:
            return QVector<Frame4>();
    }
}

void Egg4::setParents(QVector<u32> parent1, QVector<u32> parent2)
{
    this->parent1 = parent1;
    this->parent2 = parent2;
}
