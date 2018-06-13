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
    psv = tid ^ sid;
    this->offset = offset;
    frameType = type;
}

vector<Frame4> Generator4::generate(FrameCompare compare)
{
    rng.setSeed(initialSeed);
    rng.advanceFrames(initialFrame - 1 + offset);
    switch (frameType)
    {
        case Method1:
            return generateMethod1(compare);
        case MethodJ:
            switch (leadType)
            {
                case None:
                case SuctionCups:
                    return generateMethodJ(compare);
                case Synchronize:
                    return generateMethodJSynch(compare);
                // Default to cover all cute charm cases
                default:
                    return generateMethodJCuteCharm(compare);
            }
        case MethodK:
            switch (leadType)
            {
                case None:
                case SuctionCups:
                    return generateMethodK(compare);
                case Synchronize:
                    return generateMethodKSynch(compare);
                // Default to cover all cute charm cases
                default:
                    return generateMethodKCuteCharm(compare);
            }
        case ChainedShiny:
            return generateChainedShiny(compare);
        case WondercardIVs:
            return generateWondercardIVs(compare);
        default:
            return vector<Frame4>();
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
    frame.setGenderRatio(compare.getGenderRatio());

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

        frame.seed = rngList[0];
        frame.setFrame(cnt);
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateMethodJ(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first, thresh;

    if (encounterType == OldRod)
        thresh = leadType == SuctionCups ? 48 : 24;
    else if (encounterType == GoodRod)
        thresh = leadType == SuctionCups ? 98 : 49;
    else if (encounterType == SuperRod)
        thresh = leadType == SuctionCups ? 100 : 74;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        hunt = 0;
        first = rngList[hunt++];

        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Wild:
                frame.setEncounterSlot(EncounterSlot::jSlot(first, Wild));
                first = rngList[hunt++]; // Probably level call
                break;
            case Surfing:
                frame.setEncounterSlot(EncounterSlot::jSlot(first, Surfing));
                hunt++; // Level/item ? not sure if same as fishing
                first = rngList[hunt++]; // Level/item ? not sure if same as fishing
                break;
            case OldRod:
                if ((first / 656) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], OldRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case GoodRod:
                if ((first / 656) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], GoodRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case SuperRod:
                if ((first / 656) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], SuperRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            // Stationary
            default:
                break;
        }

        // Get hunt nature
        frame.setNature(first / 0xa3e);

        if (!compare.compareNature(frame))
            continue;

        // Begin search for valid pid
        do
        {
            if (hunt >= size)
                refill();
            pid1 = rngList[hunt++];
            pid2 = rngList[hunt++];
            pid = (pid2 << 16) | pid1;
        }
        while (pid % 25 != frame.getNature());

        frame.setPID(pid, pid2, pid1);
        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        frame.setIVs(rngList[hunt], rngList[hunt + 1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.seed = rngList[0];
        frame.setFrame(cnt);
        frame.occidentary = hunt + cnt - 2;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateMethodJSynch(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        hunt = 0;
        first = rngList[hunt++];

        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Wild:
                frame.setEncounterSlot(EncounterSlot::jSlot(first, Wild));
                first = rngList[hunt++]; // Probably level call
                break;
            case Surfing:
                frame.setEncounterSlot(EncounterSlot::jSlot(first, Surfing));
                hunt++; // Level/item ? not sure if same as fishing
                first = rngList[hunt++]; // Level/item ? not sure if same as fishing
                break;
            case OldRod:
                if ((first / 656) > 24)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], OldRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case GoodRod:
                if ((first / 656) > 49)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], GoodRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case SuperRod:
                if ((first / 656) > 74)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], SuperRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            default:
                break;
        }

        // Get hunt nature
        // Successful synch
        if ((first >> 15) == 0)
            frame.setNature(synchNature);
        // Failed synch
        else
            frame.setNature(rngList[hunt++] / 0xa3e);

        if (!compare.compareNature(frame))
            continue;

        // Begin search for valid pid
        do
        {
            if (hunt >= size)
                refill();
            pid1 = rngList[hunt++];
            pid2 = rngList[hunt++];
            pid = (pid2 << 16) | pid1;
        }
        while (pid % 25 != frame.getNature());

        frame.setPID(pid, pid2, pid1);
        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        frame.setIVs(rngList[hunt], rngList[hunt + 1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.seed = rngList[0];
        frame.setFrame(cnt);
        frame.occidentary = hunt + cnt - 2;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateMethodJCuteCharm(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first, buffer;

    switch (leadType)
    {
        case CuteCharmFemale:
            buffer = 0;
            break;
        case CuteCharm25M:
            buffer = 0xC8;
            break;
        case CuteCharm50M:
            buffer = 0x96;
            break;
        case CuteCharm75M:
            buffer = 0x4B;
            break;
        case CuteCharm875M:
            buffer = 0x32;
            break;
        default:
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
                frame.setEncounterSlot(EncounterSlot::jSlot(first, Wild));
                first = rngList[hunt++]; // Probably level call
                break;
            case Surfing:
                frame.setEncounterSlot(EncounterSlot::jSlot(first, Surfing));
                hunt++; // Level/item ? not sure if same as fishing
                first = rngList[hunt++]; // Level/item ? not sure if same as fishing
                break;
            case OldRod:
                if ((first / 656) > 24)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], OldRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case GoodRod:
                if ((first / 656) > 49)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], OldRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case SuperRod:
                if ((first / 656) > 74)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[hunt++], OldRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            default:
                break;
        }

        // Get nature
        frame.setNature(rngList[hunt++] / 0xa3e);

        if (!compare.compareNature(frame))
            continue;

        if ((first / 0x5556) != 0)
        {
            frame.setPID(buffer + frame.getNature(), 0, buffer + frame.getNature());
            if (!compare.comparePID(frame))
                continue;

            frame.setIVs(rngList[hunt], rngList[hunt + 1]);
            if (!compare.compareIVs(frame))
                continue;

            frame.seed = rngList[0];
            frame.setFrame(cnt);
            frame.occidentary = cnt;
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
            while (pid % 25 != frame.getNature());

            frame.setPID(pid, pid2, pid1);
            if (!compare.comparePID(frame))
                continue;

            if (hunt >= size)
                refill();

            frame.setIVs(rngList[hunt], rngList[hunt + 1]);
            if (!compare.compareIVs(frame))
                continue;

            frame.seed = rngList[0];
            frame.setFrame(cnt);
            frame.occidentary = hunt + cnt - 3;
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
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first, thresh;

    if (encounterType == OldRod)
        thresh = leadType == SuctionCups ? 48 : 24;
    else if (encounterType == GoodRod)
        thresh = leadType == SuctionCups ? 98 : 49;
    else if (encounterType == SuperRod)
        thresh = leadType == SuctionCups ? 100 : 74;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        hunt = 0;
        first = rngList[hunt++];

        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Wild:
                frame.setEncounterSlot(EncounterSlot::kSlot(first, Wild));
                first = rngList[hunt++]; // Probably level call
                break;
            case Surfing:
            case HeadButt:
            case BugCatchingContest:
                frame.setEncounterSlot(EncounterSlot::kSlot(first, encounterType));
                hunt++; // Level/item ? not sure if same as fishing
                first = rngList[hunt++]; // Level/item ? not sure if same as fishing
                break;
            case OldRod:
                if ((first  % 100) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], OldRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case GoodRod:
                if ((first  % 100) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], GoodRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case SuperRod:
                if ((first % 100) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], SuperRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            default:
                break;
        }

        // Get hunt nature
        frame.setNature(first % 25);

        if (!compare.compareNature(frame))
            continue;

        // Begin search for valid pid
        do
        {
            if (hunt >= size)
                refill();
            pid1 = rngList[hunt++];
            pid2 = rngList[hunt++];
            pid = (pid2 << 16) | pid1;
        }
        while (pid % 25 != frame.getNature());

        frame.setPID(pid, pid2, pid1);
        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        frame.setIVs(rngList[hunt], rngList[hunt + 1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.seed = rngList[0];
        frame.setFrame(cnt);
        frame.occidentary = hunt + cnt - 2;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateMethodKSynch(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        frame.seed = rngList[0];
        hunt = 0;
        first = rngList[hunt++];

        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Wild:
                frame.setEncounterSlot(EncounterSlot::kSlot(first, Wild));
                first = rngList[hunt++]; // Probably level call
                break;
            case Surfing:
            case HeadButt:
            case BugCatchingContest:
                frame.setEncounterSlot(EncounterSlot::kSlot(first, encounterType));
                hunt++; // Level/item ? not sure if same as fishing
                first = rngList[hunt++]; // Level/item ? not sure if same as fishing
                break;
            case OldRod:
                if ((first  % 100) > 24)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], OldRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case GoodRod:
                if ((first  % 100) > 49)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], GoodRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case SuperRod:
                if ((first % 100) > 74)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], SuperRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            default:
                break;
        }

        // Get hunt nature
        // Successful synch
        if ((first >> 15) == 0)
            frame.setNature(synchNature);
        // Failed synch
        else
            frame.setNature(rngList[hunt++] % 25);

        if (!compare.compareNature(frame))
            continue;

        // Begin search for valid pid
        do
        {
            if (hunt >= size)
                refill();
            pid1 = rngList[hunt++];
            pid2 = rngList[hunt++];
            pid = (pid2 << 16) | pid1;
        }
        while (pid % 25 != frame.getNature());

        frame.setPID(pid, pid2, pid1);
        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        frame.setIVs(rngList[hunt], rngList[hunt + 1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.seed = rngList[0];
        frame.setFrame(cnt);
        frame.occidentary = hunt + cnt - 2;
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateMethodKCuteCharm(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.push_back(rng.nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, hunt, first, buffer;

    switch (leadType)
    {
        case CuteCharmFemale:
            buffer = 0;
            break;
        case CuteCharm25M:
            buffer = 0xC8;
            break;
        case CuteCharm50M:
            buffer = 0x96;
            break;
        case CuteCharm75M:
            buffer = 0x4B;
            break;
        case CuteCharm875M:
            buffer = 0x32;
            break;
        default:
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
                frame.setEncounterSlot(EncounterSlot::kSlot(first, Wild));
                first = rngList[hunt++]; // Probably level call
                break;
            case Surfing:
            case HeadButt:
            case BugCatchingContest:
                frame.setEncounterSlot(EncounterSlot::kSlot(first, encounterType));
                hunt++; // Level/item ? not sure if same as fishing
                first = rngList[hunt++]; // Level/item ? not sure if same as fishing
                break;
            case OldRod:
                if ((first  % 100) > 24)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], OldRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case GoodRod:
                if ((first  % 100) > 49)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], GoodRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            case SuperRod:
                if ((first % 100) > 74)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[hunt++], SuperRod));
                hunt++; // Level/item
                first = rngList[hunt++]; // Level/item
                break;
            default:
                break;
        }

        // Get hunt nature
        frame.setNature(rngList[hunt++] % 25);

        if (!compare.compareNature(frame))
            continue;

        if ((first % 3) != 0)
        {
            frame.setPID(buffer + frame.getNature(), 0, buffer + frame.getNature());
            if (!compare.comparePID(frame))
                continue;

            frame.setIVs(rngList[hunt], rngList[hunt + 1]);
            if (!compare.compareIVs(frame))
                continue;

            frame.seed = rngList[0];
            frame.setFrame(cnt);
            frame.occidentary = cnt;
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
            while (pid % 25 != frame.getNature());

            frame.setPID(pid, pid2, pid1);
            if (!compare.comparePID(frame))
                continue;

            if (hunt >= size)
                refill();

            frame.setIVs(rngList[hunt], rngList[hunt + 1]);
            if (!compare.compareIVs(frame))
                continue;

            frame.seed = rngList[0];
            frame.setFrame(cnt);
            frame.occidentary = hunt + cnt - 3;
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
    frame.setGenderRatio(compare.getGenderRatio());

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

        frame.setFrame(cnt);
        frames.push_back(frame);
    }
    rngList.clear();

    return frames;
}

vector<Frame4> Generator4::generateWondercardIVs(FrameCompare compare)
{
    vector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);

    for (int i = 0; i < 2; i++)
        rngList.push_back(rng.nextUShort());

    // Wondercard IVs [SEED] [IVS] [IVS]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.erase(rngList.begin()), rngList.push_back(rng.nextUShort()))
    {
        frame.setIVs(rngList[0], rngList[1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setFrame(cnt);
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
    return (((low ^ tid ^ sid) & 0xFFF8) | (high & 0x7));
}
