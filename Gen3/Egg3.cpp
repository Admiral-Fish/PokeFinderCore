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
    initialSeed = 0;
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
}

Egg3::Egg3(u32 maxFrame, u32 initialFrame, u16 tid, u16 sid, Method method, u32 seed)
{
    maxResults = maxFrame;
    this->initialFrame = initialFrame;
    initialSeed = seed;
    this->tid = tid;
    this->sid = sid;
    psv = tid ^ sid;
    frameType = method;
    rng.seed = seed;
}

vector<Frame3> Egg3::generateEmeraldPID(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.genderRatio = compare.getGenderRatio();

    int i;
    u32 pid;

    rng.seed = 0;
    rng.advanceFrames(initialFrame - 1);
    for (int x = 0; x < 19; x++)
        rngList.push_back(rng.nextUShort());

    u32 val = initialFrame;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()), val++)
    {
        for (u32 redraw = minRedraw; redraw <= maxRedraw; redraw++)
        {
            if (((rngList[0] * 100) / 0xFFFF) >= compatability)
                continue;

            u32 offset = calibration + 3 * redraw;

            i = 1;

            bool flag = everstone ? (rngList[i++] >> 15) == 0 : false;

            LCRNG trng = PokeRNG((val - offset) & 0xFFFF);

            if (!flag)
            {
                // Lower PID
                pid = rngList[i];
                if (pid > 0xFFFD)
                    pid -= 0xFFFC;
                else
                    pid++;

                // Upper PID
                pid |= trng.nextUInt() & 0xFFFF0000;

                frame.setPID(pid, pid >> 16, pid & 0xFFFF);
                frame.nature = pid % 25;

                if (compare.comparePID(frame))
                {
                    frame.frame = cnt - offset - 18;
                    frame.occidentary = redraw;
                    frames.push_back(frame);
                }
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
                frame.nature = everstoneNature;

                if (compare.comparePID(frame))
                {
                    frame.frame = cnt - offset - 18;
                    frame.occidentary = redraw;
                    frames.push_back(frame);
                }
            }
        }
    }

    sort(frames.begin(), frames.end(), [](const Frame3 & frame1, const Frame3 & frame2)
    {
        return frame1.frame < frame2.frame;
    });

    return frames;
}

vector<Frame3> Egg3::generateEmerald(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    rng.seed = 0;
    rng.advanceFrames(initialFrame - 1);
    for (int x = 0; x < 13; x++)
        rngList.push_back(rng.nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
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
            frame.frame = cnt;
            frames.push_back(frame);
        }
    }

    return frames;
}

vector<Frame3> Egg3::generateEmeraldSplit(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    rng.seed = 0;
    rng.advanceFrames(initialFrame - 1);
    for (int x = 0; x < 14; x++)
        rngList.push_back(rng.nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
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
            frame.frame = cnt;
            frames.push_back(frame);
        }
    }
    return frames;
}

vector<Frame3> Egg3::generateEmeraldAlternate(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    rng.seed = 0;
    rng.advanceFrames(initialFrame - 1);
    for (int x = 0; x < 14; x++)
        rngList.push_back(rng.nextUShort());

    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
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
            frame.frame = cnt;
            frames.push_back(frame);
        }
    }

    return frames;
}

vector<Frame3> Egg3::generateLower()
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    rng.seed = seed;
    rng.advanceFrames(initialFrame + 17);
    for (int x = 0; x < 2; x++)
        rngList.push_back(rng.nextUShort());

    u32 pid;

    for (u32 cnt = initialFrame; cnt <= maxResults; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        if (((rngList[0] * 100) / 0xFFFF) >= compatability)
            continue;

        pid = rngList[1];

        if (pid > 0xFFFD)
        {
            frame.pid = pid - 0xFFFC;
        }
        else
            frame.pid = pid + 1;

        frame.frame = cnt;
        frames.push_back(frame);
    }

    return frames;
}

vector<Frame3> Egg3::generateUpper(vector<Frame3> lower, FrameCompare compare)
{
    vector<Frame3> upper;
    Frame3 frame = Frame3(tid, sid, psv);

    rng.seed = seed;
    rng.advanceFrames(minPickup - 1);
    rngList.clear();
    for (int x = 0; x < 14; x++)
        rngList.push_back(rng.nextUShort());

    u32 low = lower[0].pid;
    u32 iv1, iv2, inh1, inh2, inh3, par1, par2, par3;

    for (u32 cnt = minPickup; cnt <= maxPickup; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        frame.setPID(low, rngList[3]);

        if (!compare.comparePID(frame))
            continue;

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
            frame.occidentary = cnt;
            upper.push_back(frame);
        }
    }

    vector<Frame3> frames;

    for (Frame3 low : lower)
    {
        for (Frame3 up : upper)
        {
            if (up.occidentary <= low.frame)
                continue;

            up.frame = low.frame;
            frames.push_back(up);
        }
    }

    return frames;
}

vector<Frame3> Egg3::generate(FrameCompare compare)
{
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
        default:
            vector<Frame3> lower = generateLower();
            if (lower.size() == 0)
                return lower;
            else
                return generateUpper(lower, compare);
    }
}

void Egg3::setParents(vector<u32> parent1, vector<u32> parent2)
{
    this->parent1 = parent1;
    this->parent2 = parent2;
}
