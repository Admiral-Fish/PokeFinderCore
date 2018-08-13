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

Generator4::~Generator4()
{
    delete rng;
}

QVector<Frame4> Generator4::generate(FrameCompare compare)
{
    rng = new PokeRNG(initialSeed, initialFrame - 1 + offset);
    switch (frameType)
    {
        case Method::Method1:
            return generateMethod1(compare);
        case Method::MethodJ:
            switch (leadType)
            {
                case Lead::None:
                case Lead::SuctionCups:
                    return generateMethodJ(compare);
                case Lead::Synchronize:
                    return generateMethodJSynch(compare);
                // Default to cover all cute charm cases
                default:
                    return generateMethodJCuteCharm(compare);
            }
        case Method::MethodK:
            switch (leadType)
            {
                case Lead::None:
                case Lead::SuctionCups:
                    return generateMethodK(compare);
                case Synchronize:
                    return generateMethodKSynch(compare);
                // Default to cover all cute charm cases
                default:
                    return generateMethodKCuteCharm(compare);
            }
        case Method::ChainedShiny:
            return generateChainedShiny(compare);
        case Method::WondercardIVs:
            return generateWondercardIVs(compare);
        default:
            return QVector<Frame4>();
    }
}

void Generator4::refill()
{
    for (int i = 0; i < 20; i++)
        rngList.append(rng->nextUShort());
    size += 20;
}

void Generator4::setEncounter(const EncounterArea4 &value)
{
    encounter = value;
}

QVector<Frame4> Generator4::generateMethod1(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 4; i++)
        rngList.append(rng->nextUShort());

    // Method 1 [SEED] [PID] [PID] [IVS] [IVS]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        frame.setPID(rngList[0], rngList[1]);
        if (!compare.comparePID(frame))
            continue;

        frame.setIVs(rngList[2], rngList[3]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setSeed(rngList[0]);
        frame.setFrame(cnt);
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

QVector<Frame4> Generator4::generateMethodJ(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.append(rng->nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2;
    u16 thresh = 0;
    int hunt = 0;

    if (encounterType == Encounter::OldRod)
        thresh = leadType == Lead::SuctionCups ? 48 : 24;
    else if (encounterType == Encounter::GoodRod)
        thresh = leadType == Lead::SuctionCups ? 98 : 49;
    else if (encounterType == Encounter::SuperRod)
        thresh = leadType == Lead::SuctionCups ? 100 : 74;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Encounter::Wild:
                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 1;
                break;
            case Encounter::Surfing:
                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            case Encounter::OldRod:
            case Encounter::GoodRod:
            case Encounter::SuperRod:
                if ((rngList[0] / 656) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[1], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            default:
                break;
        }

        // Get hunt nature
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

        frame.setSeed(rngList[0]);
        frame.setFrame(cnt);
        frame.setOccidentary(static_cast<u32>(hunt) + cnt - 2);
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

QVector<Frame4> Generator4::generateMethodJSynch(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.append(rng->nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2;
    int hunt = 0;

    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Encounter::Wild:
                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 1;
                break;
            case Encounter::Surfing:
                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            case Encounter::OldRod:
            case Encounter::GoodRod:
            case Encounter::SuperRod:
                if ((rngList[0] / 656) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[1], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            default:
                break;
        }

        // Successful synch
        if ((rngList[hunt++] >> 15) == 0)
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

        frame.setSeed(rngList[0]);
        frame.setFrame(cnt);
        frame.setOccidentary(static_cast<u32>(hunt) + cnt - 2);
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

QVector<Frame4> Generator4::generateMethodJCuteCharm(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.append(rng->nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, buffer = 0;
    int hunt = 0;

    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;

    switch (leadType)
    {
        case Lead::CuteCharmFemale:
            buffer = 0;
            break;
        case Lead::CuteCharm25M:
            buffer = 0xC8;
            break;
        case Lead::CuteCharm50M:
            buffer = 0x96;
            break;
        case Lead::CuteCharm75M:
            buffer = 0x4B;
            break;
        case Lead::CuteCharm875M:
            buffer = 0x32;
            break;
        default:
            break;
    }

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Encounter::Wild:
                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 1;
                break;
            case Encounter::Surfing:
                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            case Encounter::OldRod:
            case Encounter::GoodRod:
            case Encounter::SuperRod:
                if ((rngList[0] / 656) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::jSlot(rngList[1], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            default:
                break;
        }

        // Successful cute charm
        if ((rngList[hunt++] / 0x5556) != 0)
        {
            // Get nature
            frame.setNature(rngList[hunt++] / 0xa3e);

            if (!compare.compareNature(frame))
                continue;

            // Cute charm doesn't hunt for a valid PID, just uses buffer and target nature
            frame.setPID(buffer + frame.getNature(), 0, buffer + frame.getNature());
            frame.setOccidentary(cnt);
        }
        // Failed cute charm
        else
        {
            // Get nature
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
            frame.setOccidentary(static_cast<u32>(hunt) + cnt - 2);
        }

        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        frame.setIVs(rngList[hunt], rngList[hunt + 1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setSeed(rngList[0]);
        frame.setFrame(cnt);
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

QVector<Frame4> Generator4::generateMethodK(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.append(rng->nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2;
    u16 thresh = 0;
    int hunt = 0;

    if (encounterType == Encounter::OldRod)
        thresh = leadType == Lead::SuctionCups ? 48 : 24;
    else if (encounterType == Encounter::GoodRod)
        thresh = leadType == Lead::SuctionCups ? 98 : 49;
    else if (encounterType == Encounter::SuperRod)
        thresh = leadType == Lead::SuctionCups ? 100 : 74;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Encounter::Wild:
                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 1;
                break;
            case Encounter::Surfing:
                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            case Encounter::OldRod:
            case Encounter::GoodRod:
            case Encounter::SuperRod:
                if ((rngList[0] % 100) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[1], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 3;
                break;
            case Encounter::RockSmash: // TODO
                //if ((rngList[0] % 100) >= 40)
                //  continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            case Encounter::HeadButt: // TODO
            case Encounter::BugCatchingContest: // TODO
            default:
                break;
        }

        // Get hunt nature
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

        frame.setSeed(rngList[0]);
        frame.setFrame(cnt);
        frame.setOccidentary(static_cast<u32>(hunt) + cnt - 2);
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

QVector<Frame4> Generator4::generateMethodKSynch(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.append(rng->nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2;
    int hunt = 0;

    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Encounter::Wild:
                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 1;
                break;
            case Encounter::Surfing:
                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            case Encounter::OldRod:
            case Encounter::GoodRod:
            case Encounter::SuperRod:
                if ((rngList[0] % 100) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[1], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 3;
                break;
            case Encounter::HeadButt: // TODO
            case Encounter::BugCatchingContest: // TODO
            case Encounter::RockSmash: // TODO
            default:
                break;
        }

        // Get hunt nature
        // Successful synch
        if ((rngList[hunt++] & 1) == 0)
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

        frame.setSeed(rngList[0]);
        frame.setFrame(cnt);
        frame.setOccidentary(static_cast<u32>(hunt) + cnt - 2);
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

QVector<Frame4> Generator4::generateMethodKCuteCharm(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 20; i++)
        rngList.append(rng->nextUShort());
    size = 17;

    u32 max = initialFrame + maxResults;
    u32 pid, pid1, pid2, buffer = 0;
    int hunt = 0;

    u16 thresh = encounterType == Encounter::OldRod ? 24 : encounterType == Encounter::GoodRod ? 49 : encounterType == Encounter::SuperRod ? 74 : 0;

    switch (leadType)
    {
        case Lead::CuteCharmFemale:
            buffer = 0;
            break;
        case Lead::CuteCharm25M:
            buffer = 0xC8;
            break;
        case Lead::CuteCharm50M:
            buffer = 0x96;
            break;
        case Lead::CuteCharm75M:
            buffer = 0x4B;
            break;
        case Lead::CuteCharm875M:
            buffer = 0x32;
            break;
        default:
            break;
    }

    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        // Check what encounter we are doing and get the necessary slot
        switch (encounterType)
        {
            case Encounter::Wild:
                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 1;
                break;
            case Encounter::Surfing:
                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[0], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot(), rngList[1]));
                hunt = 2;
                break;
            case Encounter::OldRod:
            case Encounter::GoodRod:
            case Encounter::SuperRod:
                if ((rngList[0] % 100) > thresh)
                    continue;

                frame.setEncounterSlot(EncounterSlot::kSlot(rngList[1], encounterType));
                if (!compare.compareSlot(frame))
                    continue;
                frame.setLevel(encounter.calcLevel(frame.getEncounterSlot()));
                hunt = 3;
                break;
            case Encounter::HeadButt: // TODO
            case Encounter::BugCatchingContest: // TODO
            case Encounter::RockSmash: // TODO
            default:
                break;
        }

        // Successfull cute charm
        if ((rngList[hunt++] % 3) != 0)
        {
            // Get hunt nature
            frame.setNature(rngList[hunt++] % 25);

            if (!compare.compareNature(frame))
                continue;

            frame.setPID(buffer + frame.getNature(), 0, buffer + frame.getNature());
            frame.setOccidentary(cnt);
        }
        // Failed cutecharm
        else
        {
            // Get hunt nature
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
            frame.setOccidentary(static_cast<u32>(hunt) + cnt - 3);
        }

        if (!compare.comparePID(frame))
            continue;

        if (hunt >= size)
            refill();

        frame.setIVs(rngList[hunt], rngList[hunt + 1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setSeed(rngList[0]);
        frame.setFrame(cnt);
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

QVector<Frame4> Generator4::generateChainedShiny(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);
    frame.setGenderRatio(compare.getGenderRatio());

    for (int i = 0; i < 18; i++)
        rngList.append(rng->nextUShort());

    u16 low, high;

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
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
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

QVector<Frame4> Generator4::generateWondercardIVs(FrameCompare compare)
{
    QVector<Frame4> frames;
    Frame4 frame = Frame4(tid, sid, psv);

    for (int i = 0; i < 2; i++)
        rngList.append(rng->nextUShort());

    // Wondercard IVs [SEED] [IVS] [IVS]

    u32 max = initialFrame + maxResults;
    for (u32 cnt = initialFrame; cnt < max; cnt++, rngList.removeFirst(), rngList.append(rng->nextUShort()))
    {
        frame.setIVs(rngList[0], rngList[1]);
        if (!compare.compareIVs(frame))
            continue;

        frame.setSeed(rngList[0]);
        frame.setFrame(cnt);
        frames.append(frame);
    }
    rngList.clear();

    return frames;
}

u16 Generator4::chainedPIDLow(u16 low, u16 call1, u16 call2, u16 call3, u16 call4, u16 call5, u16 call6, u16 call7, u16 call8, u16 call9, u16 call10, u16 call11, u16 call12, u16 call13)
{
    return static_cast<u16>((low & 7) | (call13 & 1) << 3 | (call12 & 1) << 4 | (call11 & 1) << 5 | (call10 & 1) << 6 |
                            (call9 & 1) << 7 | (call8 & 1) << 8 | (call7 & 1) << 9 | (call6 & 1) << 10 | (call5 & 1) << 11 |
                            (call4 & 1) << 12 | (call3 & 1) << 13 | (call2 & 1) << 14 | (call1 & 1) << 15);
}

u16 Generator4::chainedPIDHigh(u16 high, u16 low, u16 tid, u16 sid)
{
    return (((low ^ tid ^ sid) & 0xFFF8) | (high & 7));
}
