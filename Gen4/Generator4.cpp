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

#include "Generator4.hpp"

Generator4::Generator4()
{
    maxResults = 100000;
    initialFrame = 1;
    initialSeed = 0;
    tid = 12345;
    sid = 54321;
    psv = tid ^ sid;
}

Generator4::Generator4(u32 maxResults, u32 initialFrame, u32 initialSeed, u16 tid, u16 sid, u32 offset, Method type)
{
    this->maxResults = maxResults;
    this->initialFrame = initialFrame;
    this->initialSeed = initialSeed;
    this->tid = tid;
    this->sid = sid;
    this->offset = offset;
    frameType = type;
}

vector<Frame4> Generator4::generate(FrameCompare compare)
{
    rng.seed = initialSeed;
    rng.advanceFrames(initialFrame - 1 + offset);
    switch (frameType)
    {
        case Method1:
            return generateMethod1(compare);
        case MethodJ:
            return generateMethodJ(compare);
        case MethodK:
            return generateMethodK(compare);
        case ChainedShiny:
        default:
            return generateChainedShiny(compare);
    }
}

void Generator4::refill()
{
    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size += 20;
}

vector<Frame4> Generator4::generateMethod1(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.genderRatio = compare.getGenderRatio();

    for (int i = 0; i < 4; i++)
        rngList.push_back(rng.nextUShort());

    // Method 1 [SEED] [PID] [PID] [IVS] [IVS]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        frame.setPID(rngList[0], rngList[1]);
        if (!compare.comparePID(frame))
            continue;

        frame.setIVs(rngList[2], rngList[3]);
        if (!compare.compareIVs(frame))
            continue;

        frame.frame = cnt;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateMethodJ(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.genderRatio = compare.getGenderRatio();

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first, thresh;

    switch (encounterType)
    {
        case OldRod:
            thresh = leadType == SuctionCups ? 48 : 24;
            break;
        case GoodRod:
            thresh = leadType == SuctionCups ? 98 : 49;
            break;
        case SuperRod:
            thresh = leadType == SuctionCups ? 100 : 74;
            break;
    }

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        hunt = 0;
        first = rngList[hunt++];

        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Wild:
                frame.encounterSlot = EncounterSlot::jSlot(first, Wild);
                first = rngList[hunt++]; // Probably level call
                break;
            case Surfing:
                frame.encounterSlot = EncounterSlot::jSlot(first, Surfing);
                hunt++; // Level/item ? not sure if same as fishing
                first = rngList[hunt++]; // Level/item ? not sure if same as fishing
                break;
            case OldRod:
                if ((first / 656) > thresh)
                    continue;

                frame.encounterSlot = EncounterSlot::jSlot(rngList[hunt++], OldRod);
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case GoodRod:
                if ((first / 656) > thresh)
                    continue;

                frame.encounterSlot = EncounterSlot::jSlot(rngList[hunt++], OldRod);
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case SuperRod:
                if ((first / 656) > thresh)
                    continue;

                frame.encounterSlot = EncounterSlot::jSlot(rngList[hunt++], OldRod);
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            default:
                break;
        }

        // Get hunt nature
        if (leadType == Synchronize)
        {
            // Successful synch
            if ((first >> 15) == 0)
                frame.nature = synchNature;
            // Failed synch
            else
                frame.nature = rngList[hunt] / 0xa3e;
        }
        else if (leadType == CuteCharm)
        {
            frame.nature = rngList[hunt] / 0xa3e;
        }
        else
        {
            frame.nature = first / 0xa3e;
        }
        if (!compare.compareNature(frame))
            continue;

        if (leadType == CuteCharm && (first / 0x5556) != 0)
        {
            u32 buffer = 0; // TODO

            frame.setPID(buffer + frame.nature, 0, buffer + frame.nature);
            if (!compare.comparePID(frame))
                continue;

            frame.setIVs(rngList[hunt + 2], rngList[hunt + 3]);
            if (!compare.compareIVs(frame))
                continue;

            frame.frame = cnt;
            frame.occidentary = hunt + cnt - 1;
            frames.push_back(frame);
        }
        else
        {
            // Begin search for valid pid
            do
            {
                if (hunt >= size)
                    refill();
                pid1 = rngList[hunt++];
                pid2 = rngList[hunt++];
                pid = (pid2 << 16) | pid1;
            }
            while (pid % 25 != frame.nature);

            frame.setPID(pid, pid2, pid1);
            if (!compare.comparePID(frame))
                continue;

            if (hunt >= size)
                refill();

            frame.setIVs(rngList[hunt + 2], rngList[hunt + 3]);
            if (!compare.compareIVs(frame))
                continue;

            frame.frame = cnt;
            frame.occidentary = hunt + cnt - 2;
            frames.push_back(frame);
        }
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateMethodK(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.genderRatio = compare.getGenderRatio();

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first, thresh;

    switch (encounterType)
    {
        case OldRod:
            thresh = leadType == SuctionCups ? 48 : 24;
            break;
        case GoodRod:
            thresh = leadType == SuctionCups ? 98 : 49;
            break;
        case SuperRod:
            thresh = leadType == SuctionCups ? 100 : 74;
            break;
    }

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        hunt = 0;
        first = rngList[hunt++];

        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Wild:
                frame.encounterSlot = EncounterSlot::jSlot(first, Wild);
                first = rngList[hunt++]; // Probably level call
                break;
            case Surfing:
            case HeadButt:
            case BugCatchingContest:
                frame.encounterSlot = EncounterSlot::jSlot(first, Surfing);
                hunt++; // Level/item ? not sure if same as fishing
                first = rngList[hunt++]; // Level/item ? not sure if same as fishing
                break;
            case OldRod:
                if ((first  % 100) > thresh)
                    continue;

                frame.encounterSlot = EncounterSlot::jSlot(rngList[hunt++], OldRod);
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case GoodRod:
                if ((first  % 100) > thresh)
                    continue;

                frame.encounterSlot = EncounterSlot::jSlot(rngList[hunt++], OldRod);
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case SuperRod:
                if ((first % 100) > thresh)
                    continue;

                frame.encounterSlot = EncounterSlot::jSlot(rngList[hunt++], OldRod);
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            default:
                break;
        }

        // Get hunt nature
        if (leadType == Synchronize)
        {
            // Successful synch
            if ((first >> 15) == 0)
                frame.nature = synchNature;
            // Failed synch
            else
                frame.nature = rngList[hunt] % 25;
        }
        else if (leadType == CuteCharm)
        {
            frame.nature = rngList[hunt] % 25;
        }
        else
        {
            frame.nature = first % 25;
        }
        if (!compare.compareNature(frame))
            continue;

        if (leadType == CuteCharm && (first % 3) != 0)
        {
            u32 buffer = 0; // TODO

            frame.setPID(buffer + frame.nature, 0, buffer + frame.nature);
            if (!compare.comparePID(frame))
                continue;

            frame.setIVs(rngList[hunt + 2], rngList[hunt + 3]);
            if (!compare.compareIVs(frame))
                continue;

            frame.frame = cnt;
            frame.occidentary = hunt + cnt - 1;
            frames.push_back(frame);
        }
        else
        {
            // Begin search for valid pid
            do
            {
                if (hunt >= size)
                    refill();
                pid1 = rngList[hunt++];
                pid2 = rngList[hunt++];
                pid = (pid2 << 16) | pid1;
            }
            while (pid % 25 != frame.nature);

            frame.setPID(pid, pid2, pid1);
            if (!compare.comparePID(frame))
                continue;

            if (hunt >= size)
                refill();

            frame.setIVs(rngList[hunt + 2], rngList[hunt + 3]);
            //if (!compare.compareIVs(frame))
            //  continue;

            frame.frame = cnt;
            frame.occidentary = hunt + cnt - 2;
            frames.push_back(frame);
        }
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateChainedShiny(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.genderRatio = compare.getGenderRatio();

    for (int i = 0; i < 18; i++)
        rngList.push_back(rng.nextUShort());

    u32 low, high;

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        low = chainedPIDLow(rngList[1], rngList[15], rngList[14], rngList[13], rngList[12], rngList[11], rngList[10], rngList[9], rngList[8], rngList[7], rngList[6], rngList[5], rngList[4], rngList[3]);
        high = chainedPIDHigh(rngList[2], low, tid, sid);

        frame.setPID(low, high);
        if (!compare.comparePID(frame))
            continue;

        frame.setIVs(rngList[16], rngList[17]);
        if (!compare.compareIVs(frame))
            continue;

        frame.frame = cnt;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

u32 Generator4::chainedPIDLow(u32 low, u32 call1, u32 call2, u32 call3, u32 call4, u32 call5, u32 call6, u32 call7, u32 call8, u32 call9, u32 call10, u32 call11, u32 call12, u32 call13)
{
    return (low & 0x7) | (call13 & 1) << 3 | (call12 & 1) << 4 | (call11 & 1) << 5 | (call10 & 1) << 6 |
           (call9 & 1) << 7 | (call8 & 1) << 8 | (call7 & 1) << 9 | (call6 & 1) << 10 | (call5 & 1) << 11 |
           (call4 & 1) << 12 | (call3 & 1) << 13 | (call2 & 1) << 14 | (call1 & 1) << 15;
}

u32 Generator4::chainedPIDHigh(u32 high, u32 low, u32 tid, u32 sid)
{
    return ((low ^ tid ^ sid) & 0xFFF8 | high & 0x7);
}
