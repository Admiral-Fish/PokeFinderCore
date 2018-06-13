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

#include "Generator3.hpp"

// Default constructor
Generator3::Generator3()
{
    maxResults = 100000;
    initialFrame = 1;
    initialSeed = 0;
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
}

// Constructor given user defined parameters
Generator3::Generator3(u32 maxResults, u32 initialFrame, u32 initialSeed, u16 tid, u16 sid, u32 offset)
{
    this->maxResults = maxResults;
    this->initialFrame = initialFrame;
    this->initialSeed = initialSeed;
    this->tid = tid;
    this->sid = sid;
    this->offset = offset;
    psv = tid ^ sid;
}

// Returns vector of frames for Method Channel
vector<Frame3> Generator3::generateMethodChannel(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 12; i++)
        rngList.push_back(rng.nextUShort());

    // Method Channel [SEED] [SID] [PID] [PID] [BERRY] [GAME ORIGIN] [OT GENDER] [IV] [IV] [IV] [IV] [IV] [IV]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        frame.setIDs(40122, rngList[0], 40122 ^ rngList[0]);
        if ((rngList[2] > 7 ? 0 : 1) != (rngList[1] ^ 40122 ^ rngList[0]))
            frame.setPID(rngList[2], rngList[1] ^ 0x8000);
        else
            frame.setPID(rngList[2], rngList[1]);
        if (!compare.comparePID(frame))
            continue;

        frame.setIVsManual(rngList[6] >> 11, rngList[7] >> 11, rngList[8] >> 11, rngList[10] >> 11, rngList[11] >> 11, rngList[9] >> 11);
        if (!compare.compareIVs(frame))
            continue;

        frame.setFrame(cnt);
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

// Returns vector of frames for Method H 1, 2, or 4
vector<Frame3> Generator3::generateMethodH124(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 18;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt;

    u32 rate = encounter.getEncounterRate() * 16;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        if (encounterType == RockSmash)
        {
            if ((rngList[0] % 2880) >= rate)
                continue;
        }

        hunt = 1;
        frame.setEncounterSlot(EncounterSlot::hSlot(rngList[hunt++], encounterType));
        if (!compare.compareSlot(frame))
            continue;

        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[hunt++]));

        // Method H relies on grabbing a hunt nature and generating PIDs until the PID nature matches the hunt nature
        // Grab the hunt nature
        frame.setNature(rngList[hunt] % 25);
        if (!compare.compareNature(frame))
            continue;

        // Now search for a Method 124 PID that matches our hunt nature
        do
        {
            if (hunt >= size)
                refill();
            pid2 = rngList[++hunt];
            pid1 = rngList[++hunt];
            pid = (pid1 << 16) | pid2;
        }
        while (pid % 25 != frame.getNature());

        frame.setPID(pid, pid1, pid2);
        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        // Valid PID is found now time to generate IVs
        frame.setIVs(rngList[hunt + iv1], rngList[hunt + iv2]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setEncounterSlot(cnt);
        frame.occidentary = hunt + cnt - 1;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

// Returns vector of frames for Method H 1, 2, or 4 given synch lead
vector<Frame3> Generator3::generateMethodH124Synch(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 18;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first;

    u32 rate = encounter.getEncounterRate() * 16;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        if (encounterType == RockSmash)
        {
            if ((rngList[0] % 2880) >= rate)
                continue;
        }

        hunt = 1;
        frame.setEncounterSlot(EncounterSlot::hSlot(rngList[hunt++], encounterType));
        if (!compare.compareSlot(frame))
            continue;

        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[hunt++]));

        // Method H relies on grabbing a hunt nature and generating PIDs until the PID nature matches the hunt nature
        // Check by seeing if frame can synch
        first = rngList[hunt];
        if ((first & 1) == 0)
        {
            // Frame is synchable so set nature to synch nature
            frame.setNature(synchNature);
        }
        else
        {
            // Synch failed so grab hunt nature from next RNG call
            frame.setNature(rngList[++hunt] % 25);
        }
        if (!compare.compareNature(frame))
            continue;

        // Now search for a Method 124 PID that matches our hunt nature
        do
        {
            if (hunt >= size)
                refill();
            pid2 = rngList[++hunt];
            pid1 = rngList[++hunt];
            pid = (pid1 << 16) | pid2;
        }
        while (pid % 25 != frame.getNature());

        frame.setPID(pid, pid1, pid2);
        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        // Valid PID is found now time to generate IVs
        frame.setIVs(rngList[hunt + iv1], rngList[hunt + iv2]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setFrame(cnt);
        frame.occidentary = hunt + cnt - 1;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

// Returns vector of frames for Method H 1, 2, or 4 given cute charm lead
vector<Frame3> Generator3::generateMethodH124CuteCharm(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 18;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first;

    bool (*cuteCharm)(u32);
    switch (leadType)
    {
        case Lead::CuteCharm125F:
            cuteCharm = &Generator3::cuteCharm125F;
            break;
        case Lead::CuteCharm875M:
            cuteCharm = &Generator3::cuteCharm875M;
            break;
        case Lead::CuteCharm25F:
            cuteCharm = &Generator3::cuteCharm25F;
            break;
        case Lead::CuteCharm75M:
            cuteCharm = &Generator3::cuteCharm75M;
            break;
        case Lead::CuteCharm50F:
            cuteCharm = &Generator3::cuteCharm50F;
            break;
        case Lead::CuteCharm50M:
            cuteCharm = &Generator3::cuteCharm50M;
            break;
        case Lead::CuteCharm75F:
            cuteCharm = &Generator3::cuteCharm75F;
            break;
        // Case CuteCharm25M:
        // Set to default to avoid compiler warning message
        default:
            cuteCharm = &Generator3::cuteCharm25F;
            break;
    }

    u32 rate = encounter.getEncounterRate() * 16;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        if (encounterType == RockSmash)
        {
            if ((rngList[0] % 2880) >= rate)
                continue;
        }

        hunt = 1;
        frame.setEncounterSlot(EncounterSlot::hSlot(rngList[hunt++], encounterType));
        if (!compare.compareSlot(frame))
            continue;

        frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[hunt++]));

        // Method H relies on grabbing a hunt nature and generating PIDs until the PID nature matches the hunt nature
        first = rngList[hunt];

        // Cute charm uses first call
        // Call next RNG to determine hunt nature
        frame.setNature(rngList[++hunt] % 25);
        if (!compare.compareNature(frame))
            continue;

        // Check if cute charm will effect frame
        if (first % 3 > 0)
        {
            // Now search for a Method 124 PID that matches our hunt nature and cute charm
            do
            {
                if (hunt >= size)
                    refill();
                pid2 = rngList[++hunt];
                pid1 = rngList[++hunt];
                pid = (pid1 << 16) | pid2;
            }
            while (pid % 25 != frame.getNature() || !cuteCharm(pid));
        }
        else
        {
            // Cute charm failed
            // Only search for a Method 124 PID that matches our hunt nature
            do
            {
                if (hunt > size)
                    refill();
                pid2 = rngList[++hunt];
                pid1 = rngList[++hunt];
                pid = (pid1 << 16) | pid2;
            }
            while (pid % 25 != frame.getNature());
        }

        frame.setPID(pid, pid1, pid2);
        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        // Valid PID is found now time to generate IVs
        frame.setIVs(rngList[hunt + iv1], rngList[hunt + iv2]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setFrame(cnt);
        frame.occidentary = hunt + cnt - 1;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

// Returns vector of frames for Method XD/Colo
vector<Frame3> Generator3::generateMethodXDColo(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 5; i++)
        rngList.push_back(rng.nextUShort());

    // Method XD/Colo [SEED] [IVS] [IVS] [BLANK] [PID] [PID]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        frame.setPID(rngList[4], rngList[3]);
        if (!compare.comparePID(frame))
            continue;

        frame.setIVs(rngList[0], rngList[1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setFrame(cnt);
        frames.push_back(frame);
    }
    rngList.clear();
    return frames;
}

// Returns vector of frames for Method 1, 2, or 4
vector<Frame3> Generator3::generateMethod124(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 5; i++)
        rngList.push_back(rng.nextUShort());

    // Method 1 [SEED] [PID] [PID] [IVS] [IVS]
    // Method 2 [SEED] [PID] [PID] [BLANK] [IVS] [IVS]
    // Method 4 [SEED] [PID] [PID] [IVS] [BLANK] [IVS]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        frame.setPID(rngList[0], rngList[1]);
        if (!compare.comparePID(frame))
            continue;

        frame.setIVs(rngList[iv1], rngList[iv2]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setFrame(cnt);
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

vector<Frame3> Generator3::generateMethod1Reverse(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 4; i++)
        rngList.push_back(rng.nextUShort());

    // Method 1 Reverse [SEED] [PID] [PID] [IVS] [IVS]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        frame.setPID(rngList[1], rngList[0]);
        if (!compare.comparePID(frame))
            continue;

        frame.setIVs(rngList[2], rngList[3]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setFrame(cnt);
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

void Generator3::refill()
{
    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size += 20;
}

// Generates frames
vector<Frame3> Generator3::generate(FrameCompare compare)
{
    switch (frameType)
    {
        case Method1:
        case Method2:
        case Method4:
            return generateMethod124(compare);
        case Method1Reverse:
            return generateMethod1Reverse(compare);
        case MethodH1:
        case MethodH2:
        case MethodH4:
            switch (leadType)
            {
                case None:
                    return generateMethodH124(compare);
                case Synchronize:
                    return generateMethodH124Synch(compare);
                // case CuteCharm:
                // Set to default to avoid compiler warning message
                default:
                    return generateMethodH124CuteCharm(compare);
            }
        case XDColo:
            return generateMethodXDColo(compare);
        case Channel:
            return generateMethodChannel(compare);
        default:
            return vector<Frame3>();
    }
}

// Determines what generational method to use
void Generator3::setup(Method method)
{
    frameType = method;
    if (frameType == XDColo || frameType == Channel)
        rng = XDRNG(initialSeed);
    else
        rng = PokeRNG(initialSeed);

    rng.advanceFrames(initialFrame - 1 + offset);

    if (frameType == Method1 || frameType == MethodH1)
    {
        iv1 = frameType == MethodH1 ? 1 : 2;
        iv2 = frameType == MethodH1 ? 2 : 3;
    }
    else if (frameType == Method2 || frameType == MethodH2)
    {
        iv1 = frameType == MethodH2 ? 2 : 3;
        iv2 = frameType == MethodH2 ? 3 : 4;
    }
    else if (frameType == Method4 || frameType == MethodH4)
    {
        iv1 = frameType == MethodH4 ? 1 : 2;
        iv2 = frameType == MethodH4 ? 3 : 4;
    }
}
