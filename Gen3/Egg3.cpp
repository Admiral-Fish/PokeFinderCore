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

    int i, total;
    u32 pid;

    for (u32 redraw = minRedraw; redraw <= maxRedraw; redraw++)
    {
        rng.seed = 0;
        rng.advanceFrames(initialFrame - 1);
        rngList.clear();
        for (uint x = 0; x < 20; x++)
            rngList.push_back(rng.nextUShort());

        u32 offset = calibration + 3 * redraw;
        u32 val = initialFrame - offset;

        for (u32 cnt = initialFrame; cnt < maxResults; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()), val++)
        {
            if (((rngList[0] * 100) / 0xFFFF) >= compatability)
                continue;

            i = 1;
            total = 0;

            bool flag = everstone ? (rngList[i++] >> 15) == 0 : false;

            LCRNG trng = PokeRNG(val & 0xFFFF);

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
                    // VBlank at 17
                    if (total == 17)
                        ++i;

                    // Check if need to add to
                    if (i >= rngList.size())
                        refill();

                    // generate lower
                    pid = rngList[i++];

                    // generate upper
                    pid |= trng.nextUInt() & 0xFFFF0000;
                    ++total;
                }
                while (pid % 0x19 != everstoneNature);

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
    return frames;
}

void Egg3::refill()
{
    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
}

vector<Frame3> Egg3::generate(FrameCompare compare)
{
    switch (frameType)
    {
        case EBredPID:
        default:
            return generateEmeraldPID(compare);
    }
}
