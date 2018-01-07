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
Generator3::Generator3(u32 maxResults, u32 initialFrame, u32 initialSeed, u32 tid, u32 sid, u32 offset)
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
vector<Frame3> Generator3::GenerateMethodChannel(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int i = 0; i < 12; i++)
        rngList.push_back(rng.Nextushort());

    // Method Channel [SEED] [SID] [PID] [PID] [BERRY] [GAME ORIGIN] [OT GENDER] [IV] [IV] [IV] [IV] [IV] [IV]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.Nextushort()))
    {
        frame.SetIDs(40122, rngList[0], 40122 ^ rngList[0]);
        if ((rngList[2] > 7 ? 0 : 1) != (rngList[1] ^ 40122 ^ rngList[0]))
            frame.SetPID(rngList[2], rngList[1] ^ 0x8000);
        else
            frame.SetPID(rngList[2], rngList[1]);
        if (!compare.ComparePID(frame))
            continue;

        frame.SetIVsManual(rngList[6] >> 11, rngList[7] >> 11, rngList[8] >> 11, rngList[10] >> 11, rngList[11] >> 11, rngList[9] >> 11);
        if (!compare.CompareIVs(frame))
            continue;

        frame.frame = cnt;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

// Returns vector of frames for Method H 1, 2, or 4
vector<Frame3> Generator3::GenerateMethodH124(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.Nextushort());
    size = 18;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.Nextushort()))
    {
        hunt = 0;
        frame.encounterSlot = EncounterSlot::HSlot(rngList[hunt++], encounterType);

        // Method H relies on grabbing a hunt nature and generating PIDs until the PID nature matches the hunt nature
        // Grab the hunt nature
        frame.nature = rngList[++hunt] % 25;
        if (!compare.CompareNature(frame))
            continue;

        // Now search for a Method 124 PID that matches our hunt nature
        do
        {
            if (hunt >= size)
                Refill();
            pid2 = rngList[++hunt];
            pid1 = rngList[++hunt];
            pid = (pid1 << 16) | pid2;
        }
        while (pid % 25 != frame.nature);

        frame.SetPID(pid, pid1, pid2);
        if (!compare.ComparePID(frame))
            continue;

        if (hunt >= size)
            Refill();

        // Valid PID is found now time to generate IVs
        frame.SetIVs(rngList[hunt + iv1], rngList[hunt + iv2]);
        if (!compare.CompareIVs(frame))
            continue;

        frame.frame = cnt;
        frame.occidentary = hunt + cnt - 1;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

// Returns vector of frames for Method H 1, 2, or 4 given synch lead
vector<Frame3> Generator3::GenerateMethodH124Synch(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.Nextushort());
    size = 18;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.Nextushort()))
    {
        hunt = 0;
        frame.encounterSlot = EncounterSlot::HSlot(rngList[hunt++], encounterType);

        // Method H relies on grabbing a hunt nature and generating PIDs until the PID nature matches the hunt nature
        // Check by seeing if frame can synch
        first = rngList[++hunt];
        if ((first & 1) == 0)
        {
            // Frame is synchable so set nature to synch nature
            frame.nature = synchNature;
        }
        else
        {
            // Synch failed so grab hunt nature from next RNG call
            frame.nature = rngList[++hunt] % 25;
        }
        if (!compare.CompareNature(frame))
            continue;

        // Now search for a Method 124 PID that matches our hunt nature
        do
        {
            if (hunt >= size)
                Refill();
            pid2 = rngList[++hunt];
            pid1 = rngList[++hunt];
            pid = (pid1 << 16) | pid2;
        }
        while (pid % 25 != frame.nature);

        frame.SetPID(pid, pid1, pid2);
        if (!compare.ComparePID(frame))
            continue;

        if (hunt >= size)
            Refill();

        // Valid PID is found now time to generate IVs
        frame.SetIVs(rngList[hunt + iv1], rngList[hunt + iv2]);
        if (!compare.CompareIVs(frame))
            continue;

        frame.frame = cnt;
        frame.occidentary = hunt + cnt - 1;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}



// Returns vector of frames for Method H 1, 2, or 4 given cute charm lead
vector<Frame3> Generator3::GenerateMethodH124CuteCharm(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.Nextushort());
    size = 18;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first;

    bool (*cuteCharm)(u32);
    switch (leadType)
    {
        case Lead::CuteCharm125F:
            cuteCharm = &Generator3::CuteCharm125F;
            break;
        case Lead::CuteCharm875M:
            cuteCharm = &Generator3::CuteCharm875M;
            break;
        case Lead::CuteCharm25F:
            cuteCharm = &Generator3::CuteCharm25F;
            break;
        case Lead::CuteCharm75M:
            cuteCharm = &Generator3::CuteCharm75M;
            break;
        case Lead::CuteCharm50F:
            cuteCharm = &Generator3::CuteCharm50F;
            break;
        case Lead::CuteCharm50M:
            cuteCharm = &Generator3::CuteCharm50M;
            break;
        case Lead::CuteCharm75F:
            cuteCharm = &Generator3::CuteCharm75F;
            break;
        // Case CuteCharm25M:
        // Set to default to avoid compiler warning message
        default:
            cuteCharm = &Generator3::CuteCharm25F;
            break;
    }

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.Nextushort()))
    {
        hunt = 0;
        frame.encounterSlot = EncounterSlot::HSlot(rngList[hunt++], encounterType);

        // Method H relies on grabbing a hunt nature and generating PIDs until the PID nature matches the hunt nature
        first = rngList[++hunt];

        // Cute charm uses first call
        // Call next RNG to determine hunt nature
        frame.nature = rngList[++hunt] % 25;
        if (compare.CompareNature(frame))
            continue;

        // Check if cute charm will effect frame
        if (first % 3 > 0)
        {
            // Now search for a Method 124 PID that matches our hunt nature and cute charm
            do
            {
                if (hunt >= size)
                    Refill();
                pid2 = rngList[++hunt];
                pid1 = rngList[++hunt];
                pid = (pid1 << 16) | pid2;
            }
            while (pid % 25 != frame.nature || !cuteCharm(pid));
        }
        else
        {
            // Cute charm failed
            // Only search for a Method 124 PID that matches our hunt nature
            do
            {
                if (hunt > size)
                    Refill();
                pid2 = rngList[++hunt];
                pid1 = rngList[++hunt];
                pid = (pid1 << 16) | pid2;
            }
            while (pid % 25 != frame.nature);
        }

        frame.SetPID(pid, pid1, pid2);
        if (!compare.ComparePID(frame))
            continue;

        if (hunt >= size)
            Refill();

        // Valid PID is found now time to generate IVs
        frame.SetIVs(rngList[hunt + iv1], rngList[hunt + iv2]);
        if (!compare.CompareIVs(frame))
            continue;

        frame.frame = cnt;
        frame.occidentary = hunt + cnt - 1;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

// Returns vector of frames for Method XD/Colo
vector<Frame3> Generator3::GenerateMethodXDColo(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int i = 0; i < 5; i++)
        rngList.push_back(rng.Nextushort());

    // Method XD/Colo [SEED] [IVS] [IVS] [BLANK] [PID] [PID]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.Nextushort()))
    {
        frame.SetPID(rngList[4], rngList[3]);
        if (!compare.ComparePID(frame))
            continue;

        frame.SetIVs(rngList[0], rngList[1]);
        if (!compare.CompareIVs(frame))
            continue;

        frame.frame = cnt;
        frames.push_back(frame);
    }
    rngList.clear();
    return frames;
}

// Returns vector of frames for Method 1, 2, or 4
vector<Frame3> Generator3::GenerateMethod124(FrameCompare compare)
{
    vector<Frame3> frames;
    Frame3 frame = Frame3(tid, sid, psv);

    for (int i = 0; i < 5; i++)
        rngList.push_back(rng.Nextushort());

    // Method 1 [SEED] [PID] [PID] [IVS] [IVS]
    // Method 2 [SEED] [PID] [PID] [BLANK] [IVS] [IVS]
    // Method 4 [SEED] [PID] [PID] [IVS] [BLANK] [IVS]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.Nextushort()))
    {
        frame.SetPID(rngList[0], rngList[1]);
        if (!compare.ComparePID(frame))
            continue;

        frame.SetIVs(rngList[iv1], rngList[iv2]);
        if (!compare.CompareIVs(frame))
            continue;

        frame.frame = cnt;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

void Generator3::Refill()
{
    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.Nextushort());
    size = (int)rngList.size() - 2;
}

// Determines what generational method to return
vector<Frame3> Generator3::Generate(FrameCompare compare)
{
    if (frameType == XDColo || frameType == Channel)
        rng = XDRNG(initialSeed);
    else
        rng = PokeRNG(initialSeed);

    rng.AdvanceFrames(initialFrame - 1 + offset);

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

    switch (frameType)
    {
        case Method1:
        case Method2:
        case Method4:
            return GenerateMethod124(compare);
        case MethodH1:
        case MethodH2:
        case MethodH4:
            switch (leadType)
            {
                case None:
                    return GenerateMethodH124(compare);
                case Synchronize:
                    return GenerateMethodH124Synch(compare);
                // case CuteCharm:
                // Set to default to avoid compiler warning message
                default:
                    return GenerateMethodH124CuteCharm(compare);
            }
        case XDColo:
            return GenerateMethodXDColo(compare);
        // case Channel:
        // Set to default to avoid compiler warning message
        default:
            return GenerateMethodChannel(compare);
    }
}
