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

#include "Egg3.hpp"

Egg3::Egg3()
{
    maxResults = 100000;
    initialFrame = 1;
    seed = 0;
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
}

Egg3::Egg3(u32 maxFrame, u32 initialFrame, u16 tid, u16 sid, Method method, u32 seed)
{
    maxResults = maxFrame;
    this->initialFrame = initialFrame;
    this->seed = seed;
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    frameType = method;
}

Egg3::~Egg3()
{
    delete rng;
}

QVector<Frame3> Egg3::generateEmeraldPID(FrameCompare compare)
{
    QVector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    int i;
    u32 pid = 0;

    for (int x = 0; x < 19; x++)
        rngList.append(rng->nextUShort());

    u32 val = initialFrame;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()), val++)
    {
        for (u32 redraw = minRedraw; redraw <= maxRedraw; redraw++)
        {
            if (((rngList[0] * 100) / 0xFFFF) >= compatability)
                continue;

            u32 offset = calibration + 3 * redraw;

            i = 1;

            bool flag = everstone ? (rngList[i++] >> 15) == 0 : false;

            PokeRNG trng((val - offset) & 0xFFFF);

            if (!flag)
            {
                // Lower PID
                pid = (rngList[i] % 0xFFFE) + 1;

                // Upper PID
                pid |= trng.nextUInt() & 0xFFFF0000;

                frame.setPID(pid, pid >> 16, pid & 0xFFFF);
                frame.setNature(pid % 25);
            }
            else
            {
                do
                {
                    // VBlank at 17 from starting PID generation
                    // Adjusted i value is 19
                    // Skip at this point since spread is unlikely to occur
                    if (i == 19)
                        break;

                    // generate lower
                    pid = rngList[i++];

                    // generate upper
                    pid |= trng.nextUInt() & 0xFFFF0000;
                }
                while (pid % 0x19 != everstoneNature);

                if (i == 19)
                    continue;

                frame.setPID(pid, pid >> 16, pid & 0xFFFF);
                frame.setNature(everstoneNature);
            }

            if (compare.comparePID(frame))
            {
                frame.setFrame(cnt - offset);
                frame.setOccidentary(redraw);
                frames.append(frame);
            }
        }
    }

    std::sort(frames.begin(), frames.end(), [](const Frame3 & frameA, const Frame3 & frameB)
    {
        return frameA.getFrame() < frameB.getFrame();
    });

    return frames;
}

QVector<Frame3> Egg3::generateEmerald(FrameCompare compare)
{
    QVector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int x = 0; x < 13; x++)
        rngList.append(rng->nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        iv1 = rngList[4];
        iv2 = rngList[5];
        inh1 = rngList[7];
        inh2 = rngList[8];
        inh3 = rngList[9];
        par1 = rngList[10];
        par2 = rngList[11];
        par3 = rngList[12];
        frame.setInheritanceEmerald(iv1, iv2, par1 & 1, par2 & 1, par3 & 1, HABCDS[inh1 % 6],
                                    ABCDS[inh2 % 5], ACDS[inh3 & 3], parent1, parent2);

        if (compare.compareIVs(frame))
        {
            frame.setFrame(cnt);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame3> Egg3::generateEmeraldSplit(FrameCompare compare)
{
    QVector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int x = 0; x < 14; x++)
        rngList.append(rng->nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        iv1 = rngList[4];
        iv2 = rngList[6];
        inh1 = rngList[8];
        inh2 = rngList[9];
        inh3 = rngList[10];
        par1 = rngList[11];
        par2 = rngList[12];
        par3 = rngList[13];
        frame.setInheritanceEmerald(iv1, iv2, par1 & 1, par2 & 1, par3 & 1, HABCDS[inh1 % 6],
                                    ABCDS[inh2 % 5], ACDS[inh3 & 3], parent1, parent2);

        if (compare.compareIVs(frame))
        {
            frame.setFrame(cnt);
            frames.append(frame);
        }
    }
    return frames;
}

QVector<Frame3> Egg3::generateEmeraldAlternate(FrameCompare compare)
{
    QVector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int x = 0; x < 14; x++)
        rngList.append(rng->nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        iv1 = rngList[4];
        iv2 = rngList[5];
        inh1 = rngList[8];
        inh2 = rngList[9];
        inh3 = rngList[10];
        par1 = rngList[11];
        par2 = rngList[12];
        par3 = rngList[13];
        frame.setInheritanceEmerald(iv1, iv2, par1 & 1, par2 & 1, par3 & 1, HABCDS[inh1 % 6],
                                    ABCDS[inh2 % 5], ACDS[inh3 & 3], parent1, parent2);

        if (compare.compareIVs(frame))
        {
            frame.setFrame(cnt);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame3> Egg3::generateLower(FrameCompare compare)
{
    QVector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int x = 0; x < 2; x++)
        rngList.append(rng->nextUShort());

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        if (((rngList[0] * 100) / 0xFFFF) >= compatability)
            continue;

        frame.setPID((rngList[1] % 0xFFFE) + 1);

        if (compare.compareGender(frame))
        {
            frame.setFrame(cnt);
            frames.append(frame);
        }
    }

    return frames;
}

QVector<Frame3> Egg3::generateUpper(QVector<Frame3> lower, FrameCompare compare)
{
    QVector<Frame3> upper;
    Frame3 frame = Frame3(tid, sid, psv);

    rngList.clear();
    for (int x = 0; x < 14; x++)
        rngList.append(rng->nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = minPickup; cnt <= maxPickup; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        frame.setPID(rngList[3]);

        iv1 = rngList[5];
        iv2 = rngList[6];
        inh1 = rngList[8];
        inh2 = rngList[9];
        inh3 = rngList[10];
        par1 = rngList[11];
        par2 = rngList[12];
        par3 = rngList[13];

        frame.setInheritance(iv1, iv2, par1, par2, par3, inh1,
                             inh2, inh3, parent1, parent2);

        if (compare.compareIVs(frame))
        {
            frame.setOccidentary(cnt);
            upper.append(frame);
        }
    }

    QVector<Frame3> frames;

    for (Frame3 low : lower)
    {
        for (Frame3 up : upper)
        {
            up.setPID(low.getPid(), up.getPid());
            if (compare.comparePID(up))
            {
                up.setFrame(low.getFrame());
                frames.append(up);
            }
        }
    }

    return frames;
}

QVector<Frame3> Egg3::generate(FrameCompare compare)
{
    rng = new PokeRNG(seed, initialFrame - 1);

    switch (frameType)
    {
        case EBredPID:
            return generateEmeraldPID(compare);
        case EBred:
            return generateEmerald(compare);
        case EBredSplit:
            return generateEmeraldSplit(compare);
        case EBredAlternate:
            return generateEmeraldAlternate(compare);
        case RSBred:
        case FRLGBred:
            {
                QVector<Frame3> lower = generateLower(compare);
                if (lower.size() == 0)
                    return lower;
                else
                {
                    rng->setSeed(seed, minPickup - 1);
                    return generateUpper(lower, compare);
                }
            }
        default:
            return QVector<Frame3>();
    }
}

void Egg3::setParents(QVector<u32> parent1, QVector<u32> parent2)
{
    this->parent1 = parent1;
    this->parent2 = parent2;
}

void Egg3::setMinRedraw(const u32 &value)
{
    minRedraw = value;
}

void Egg3::setMaxRedraw(const u32 &value)
{
    maxRedraw = value;
}

void Egg3::setCompatability(const u16 &value)
{
    compatability = value;
}

void Egg3::setCalibration(const u32 &value)
{
    calibration = value;
}

void Egg3::setEverstone(bool value)
{
    everstone = value;
}

void Egg3::setMinPickup(const u32 &value)
{
    minPickup = value;
}

void Egg3::setMaxPickup(const u32 &value)
{
    maxPickup = value;
}

u32 Egg3::getSeed() const
{
    return seed;
}

void Egg3::setSeed(const u32 &value)
{
    seed = value;
}
