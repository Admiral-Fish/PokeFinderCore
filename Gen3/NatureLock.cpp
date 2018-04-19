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

#include "NatureLock.hpp"

/* Each non-shadow before a shadow has to match
 * a specific gender/nature and these preset
 * values directly impact what spreads are available */

// Constructor for NatureLock
NatureLock::NatureLock()
{
    natureLockSetupGales(0);
    backCount = (int)lockInfo.size();
    frontCount = backCount == 1 ? 0 : backCount - 2;
    x = 0;
    if (backCount == 1)
        getCurrLock();
}

// Keeps rerolling PID backwards by 2 until it finds a match for current lock
void NatureLock::countBackTwo()
{
    do
    {
        pid = getPIDReverse();
        gender = pid & 255;
    }
    while (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature));
}

// Keeps rerolling PID forward by 2 until it finds a match for current lock
void NatureLock::countForwardTwo()
{
    do
    {
        pid = getPIDForward();
        gender = pid & 255;
    }
    while (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature));
}

// Quick sets the values of the current lock
void NatureLock::getCurrLock()
{
    nature = lockInfo[x].getNature();
    genderLower = lockInfo[x].getGenderLower();
    genderUpper = lockInfo[x].getGenderUpper();
}

// Generates the next PID forwards
u32 NatureLock::getPIDForward()
{
    u32 high = forward.nextUInt() & 0xFFFF0000;
    u32 low = forward.nextUShort();
    return high | low;
}

// Generates the next PID backwards
u32 NatureLock::getPIDReverse()
{
    u32 low = backward.nextUShort();
    u32 high = backward.nextUInt() & 0xFFFF0000;
    return low | high;
}

// Generates the PSV of the next PID backwards
u32 NatureLock::getPSVReverse()
{
    return (backward.nextUShort() ^ backward.nextUShort()) >> 3;
}

// Sets up rest of nature lock data for Colo
void NatureLock::natureLockSetupColo(int lockNum)
{
    switch (lockNum)
    {
        case 0: // Gligar
            lockInfo = { LockInfo(18, 127, 255), LockInfo(6, 0, 190), LockInfo(12, 127, 255) };
            type = FirstShadow;
            break;
        case 1: // Heracross
            lockInfo = { LockInfo(0, 0, 126), LockInfo(0, 127, 255) };
            type = FirstShadow;
            break;
        case 2: // Makuhita
            lockInfo = { LockInfo(0, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 3: // Murkrow
            lockInfo = { LockInfo(18, 127, 255), LockInfo(12, 0, 126), LockInfo(6, 127, 255 ) };
            type = FirstShadow;
            break;
        default: // Ursaring
            lockInfo = { LockInfo(21, 0, 126), LockInfo(16, 31, 255), LockInfo(20, 0, 63) };
            type = FirstShadow;
            break;
    }
}

// Sets up rest of nature lock data for Gales
void NatureLock::natureLockSetupGales(int lockNum)
{
    switch (lockNum)
    {
        case 0: // Altaria
            lockInfo = { LockInfo(24, 127, 255), LockInfo(0, 0, 126), LockInfo(12, 127, 255) };
            type = SecondShadow;
            break;
        case 1: // Arbok
            lockInfo =  { LockInfo(18, 0, 126), LockInfo(12, 0, 126), LockInfo(0, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 2: // Banette
            lockInfo =  { LockInfo(12, 0, 255), LockInfo(18, 0, 126), LockInfo(0, 0, 255) };
            type = SecondShadow;
            break;
        case 3: // Butterfree
            lockInfo = { LockInfo(0, 0, 126), LockInfo(6, 127, 255), LockInfo(12, 0, 190) };
            type = SecondShadow;
            break;
        case 4: // Chansey
            lockInfo = { LockInfo(24, 127, 255), LockInfo(6, 0, 126) };
            type = SecondShadow;
            break;
        case 5: // Delcatty
            lockInfo = { LockInfo(24, 127, 255), LockInfo(0, 127, 255), LockInfo(6, 0, 190) };
            type = FirstShadow;
            break;
        case 6: // Dodrio
            lockInfo =  { LockInfo(18, 0, 126) };
            type = SingleLock;
            break;
        case 7: // Dragonite
            lockInfo = { LockInfo(0, 127, 255), LockInfo(12, 0, 126), LockInfo(12, 0, 126), LockInfo(18, 127, 255), LockInfo(0, 127, 255) };
            type = FirstShadow;
            break;
        case 8: // Dugtrio
            lockInfo = { LockInfo(12, 127, 255), LockInfo(6, 0, 126), LockInfo(18, 127, 255), LockInfo(0, 127, 255) };
            type = FirstShadow;
            break;
        case 9: // Duskull
            lockInfo = { LockInfo(24, 127, 255), LockInfo(18, 0, 126), LockInfo(12, 127, 255) };
            type = FirstShadow;
            break;
        case 10: // Electabuzz
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 0, 126), LockInfo(24, 63, 255) };
            type = FirstShadow;
            break;
        case 11: // Farfetch'd
            lockInfo = { LockInfo(24, 127, 255), LockInfo(0, 0, 126), LockInfo(12, 127, 255) };
            type = FirstShadow;
            break;
        case 12: // Golduck
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 13: // Grimer
            lockInfo = { LockInfo(18, 127, 255), LockInfo(12, 127, 255) };
            type = FirstShadow;
            break;
        case 14: // Growlithe
            lockInfo = { LockInfo(6, 0, 126), LockInfo(24, 127, 255) };
            type = SecondShadow;
            break;
        case 15: // Gulpin 3
        case 16: // Gulpin 1
        case 17: // Gulpin 2
            lockInfo = { LockInfo(6, 127, 255), LockInfo(12, 0, 126) };
            type = FirstShadow;
            break;
        case 18: // Hitmonchan
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 19: // Hitmonlee
            lockInfo = { LockInfo(24, 0, 62), LockInfo(6, 0, 255), LockInfo(12, 0, 126), LockInfo(18, 127, 255) };
            type = FirstShadow;
            break;
        case 20: // Hypno
            lockInfo = { LockInfo(24, 127, 255), LockInfo(6, 0, 126), LockInfo(12, 0, 126), LockInfo(18, 0, 126) };
            type = SecondShadow;
            break;
        case 21: // Kangaskhan
            lockInfo = { LockInfo(12, 0, 255), LockInfo(18, 0, 126), LockInfo(0, 0, 255) };
            type = FirstShadow;
            break;
        case 22: // Lapras
            lockInfo = { LockInfo(24, 127, 255), LockInfo(500, 500, 500), LockInfo(500, 500, 500), LockInfo(6, 0, 126) };
            type = SecondShadow;
            break;
        case 23: // Ledyba
            lockInfo = { LockInfo(0, 0, 126) };
            type = SingleLock;
            break;
        case 24: // Lickitung
            lockInfo = { LockInfo(6, 0, 255), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 25: // Lunatone
            lockInfo = { LockInfo(18, 127, 255), LockInfo(0, 0, 126) };
            type = FirstShadow;
            break;
        case 26: // Marcargo
            lockInfo = { LockInfo(12, 0, 126), LockInfo(6, 127, 255), LockInfo(24, 127, 255) };
            type = SecondShadow;
            break;
        case 27: // Mareep E-Reader
            lockInfo = { LockInfo(16, 0, 126), LockInfo(12, 0, 126), LockInfo(10, 0, 126), LockInfo(4, 0, 190)};
            type = EReader;
            break;
        case 28: // Magmar
            lockInfo = { LockInfo(0, 0, 126), LockInfo(18, 191, 255), LockInfo(18, 127, 255) };
            type = FirstShadow;
            break;
        case 29: // Magneton
            lockInfo = { LockInfo(12, 0, 126), LockInfo(0, 127, 255), LockInfo(18, 0, 255) };
            type = FirstShadow;
            break;
        case 30: // Makuhita
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 31: // Manectric
            lockInfo = { LockInfo(6, 0, 126) };
            type = SingleLock;
            break;
        case 32: // Marowak
            lockInfo = { LockInfo(24, 127, 255), LockInfo(500, 500, 500), LockInfo(500, 500, 500), LockInfo(6, 0, 126) };
            type = FirstShadow;
            break;
        case 33: // Mawile
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 34: // Meowth
            lockInfo =  { LockInfo(18, 0, 126), LockInfo(0, 0, 126), LockInfo(6, 63, 255) };
            type = FirstShadow;
            break;
        case 35: // Mr. Mime
            lockInfo = { LockInfo(6, 0, 126), LockInfo(24, 127, 255), LockInfo(18, 127, 255), LockInfo(18, 127, 255) };
            type = SecondShadow;
            break;
        case 36: // Natu
            lockInfo = { LockInfo(0, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 37: // Nosepass
            lockInfo = { LockInfo(12, 0, 126), LockInfo(18, 127, 255), LockInfo(0, 127, 255) };
            type = FirstShadow;
            break;
        case 38: // Numel
            lockInfo = { LockInfo(24, 0, 126), LockInfo(0, 0, 255), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 39: // Paras
            lockInfo = { LockInfo(6, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 40: // Pidgeotto
            lockInfo = { LockInfo(18, 31, 255), LockInfo(12, 127, 255) };
            type = FirstShadow;
            break;
        case 41: // Pineco
            lockInfo = { LockInfo(6, 127, 255) };
            type = SingleLock;
            break;
        case 42: // Pinsir
            lockInfo = { LockInfo(0, 0, 126), LockInfo(18, 191, 255), LockInfo(18, 127, 255) };
            type = SecondShadow;
            break;
        case 43: // Poliwrath
            lockInfo = { LockInfo(6, 0, 126), LockInfo(24, 127, 255), LockInfo(18, 127, 255), LockInfo(18, 127, 255) };
            type = FirstShadow;
            break;
        case 44: // Poochyena
            lockInfo = { LockInfo(12, 0, 126) };
            type = SingleLock;
            break;
        case 45: // Primeape
            lockInfo = { LockInfo(24, 127, 255), LockInfo(6, 0, 126), LockInfo(12, 0, 126), LockInfo(18, 0, 126) };
            type = FirstShadow;
            break;
        case 46: // Ralts
            lockInfo = { LockInfo(18, 127, 255), LockInfo(6, 0, 126), LockInfo(0, 63, 255) };
            type = FirstShadow;
            break;
        case 47: // Rapidash
            lockInfo = { LockInfo(12, 0, 126), LockInfo(6, 127, 255), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 48: // Raticate
            lockInfo = { LockInfo(18, 127, 255), LockInfo(500, 500, 500), LockInfo(18, 0, 126) };
            type = FirstShadow;
            break;
        case 49: // Roselia
            lockInfo = { LockInfo(18, 127, 255), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 50: // Sableye
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 0, 126), LockInfo(24, 127, 255) };
            type = SecondShadow;
            break;
        case 51: // Salamence
            lockInfo = { LockInfo(6, 0, 126) };
            type = Salamence;
            break;
        case 52: // Scyther
            lockInfo = { LockInfo(24, 127, 255), LockInfo(6, 0, 126) };
            type = FirstShadow;
            break;
        case 53: // Seedot 3
            lockInfo = { LockInfo(12, 127, 255), LockInfo(0, 127, 255), LockInfo(0, 0, 126), LockInfo(24, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
        case 54: // Seedot 1
            lockInfo = { LockInfo(12, 127, 255), LockInfo(0, 127, 255), LockInfo(18, 0, 126), LockInfo(24, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 55: // Seedot 2
            lockInfo = { LockInfo(6, 127, 255), LockInfo(0, 0, 126), LockInfo(0, 0, 126), LockInfo(24, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 56: // Seel
            lockInfo = { LockInfo(18, 0, 126), LockInfo(18, 127, 255), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 57: // Shroomish
            lockInfo = { LockInfo(0, 0, 126), LockInfo(24, 0, 190) };
            type = FirstShadow;
            break;
        case 58: // Snorlax
            lockInfo =  { LockInfo(18, 0, 126), LockInfo(6, 0, 126), LockInfo(24, 63, 255) };
            type = SecondShadow;
            break;
        case 59: // Snorunt
            lockInfo = { LockInfo(6, 0, 126) };
            type = SingleLock;
            break;
        case 60: // Solrock
            lockInfo = { LockInfo(0, 0, 126), LockInfo(6, 127, 255), LockInfo(24, 0, 255) };
            type = FirstShadow;
            break;
        case 61: // Spearow
            lockInfo = { LockInfo(6, 0, 126), LockInfo(18, 127, 255) };
            type = FirstShadow;
            break;
        case 62: // Spheal 3
        case 64: // Spheal 2
            lockInfo = { LockInfo(0, 0, 255), LockInfo(12, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 63: // Spheal 1
            lockInfo = { LockInfo(12, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 65: // Spinarak
            lockInfo = { LockInfo(6, 127, 255), LockInfo(12, 0, 126) };
            type = FirstShadow;
            break;
        case 66: // Starmie
            lockInfo = { LockInfo(18, 127, 255), LockInfo(500, 500, 500), LockInfo(0, 0, 126), LockInfo(6, 127, 255), LockInfo(24, 0, 255) };
            type = FirstShadow;
            break;
        case 67: // Swinub
            lockInfo =  { LockInfo(0, 127, 255), LockInfo(18, 0, 126) };
            type = FirstShadow;
            break;
        case 68: // Tangela
            lockInfo = { LockInfo(0, 0, 126), LockInfo(6, 127, 255), LockInfo(12, 0, 190) };
            type = FirstShadow;
            break;
        case 69: // Venomoth
            lockInfo = { LockInfo(12, 63, 255), LockInfo(24, 0, 255), LockInfo(18, 0, 126) };
            type = FirstShadow;
            break;
        case 70: // Voltorb
            lockInfo = { LockInfo(12, 0, 126), LockInfo(18, 127, 255), LockInfo(0, 127, 255) };
            type = FirstShadow;
            break;
        case 71: // Vulpix
            lockInfo = { LockInfo(18, 127, 255), LockInfo(6, 0, 126), LockInfo(0, 127, 255) };
            type = FirstShadow;
            break;
        default: // Weepinbell
            lockInfo = { LockInfo(12, 63, 255), LockInfo(24, 0, 255), LockInfo(18, 0, 126) };
            type = SecondShadow;
            break;
    }
}

// Returns what type the shadow is
ShadowType NatureLock::getType()
{
    return type;
}

// Checks if seed is valid for single shadow case
bool NatureLock::firstShadowNormal(u32 seed)
{
    backward.seed = seed * 0xB9B33155 + 0xA170F641; // 1 frame

    // Build temp pid first to not waste time looping if first backwards nl fails
    pidOriginal = getPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && pidOriginal % 25 == lockInfo[0].getNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.seed = backward.seed * 0x2D4673C5 + 0x16AEB36D; // 5 frames
        pid = getPIDReverse();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countBackTwo();
        }
    }

    forward.seed = backward.seed * 0x343FD + 0x269EC3; // 1 frame

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.seed = forward.seed * 0x284A930D + 0xA2974C77; // 5 frames
        pid = getPIDForward();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countForwardTwo();
        }
    }

    // Checks if first NL PID back from target matches
    return pidOriginal == pid;
}

// Checks if seed is valid for second shadow with first shadow set
bool NatureLock::firstShadowSet(u32 seed)
{
    backward.seed = seed * 0xD44C2569 + 0xD4016672; // 6 frames

    // Build temp pid first to not waste time looping if first nl fails
    pidOriginal = getPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && pidOriginal % 25 == lockInfo[0].getNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.seed = backward.seed * 0x2D4673C5 + 0x16AEB36D; // 5 frames
        pid = getPIDReverse();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countBackTwo();
        }
    }

    forward.seed = backward.seed * 0x343FD + 0x269EC3; // 1 frame

    // Forwards nature lock check
    for (x = frontCount; x >= 0; x--)
    {
        forward.seed = forward.seed * 0x284A930D + 0xA2974C77; // 5 frames
        pid = getPIDForward();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countForwardTwo();
        }
    }

    // Checks if first NL PID back from target matches
    return pidOriginal == pid;
}

// Checks if seed is valid for second shadow with first shadow unset and antishiny(aka Shiny Skip)
bool NatureLock::firstShadowShinySkip(u32 seed)
{
    backward.seed = seed * 0xB9B33155 + 0xA170F641; // 1 frame

    u32 psv, psvtemp;

    // Check how many advances from shiny skip and build initial pid for first nl
    psv = getPSVReverse();
    psvtemp = getPSVReverse();
    while (psv == psvtemp)
    {
        psvtemp = psv;
        psv = getPSVReverse();
    }

    backward.seed = backward.seed * 0x2D4673C5 + 0x16AEB36D; // 5 frames
    pidOriginal = getPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && pidOriginal % 25 == lockInfo[0].getNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.seed = backward.seed * 0x2D4673C5 + 0x16AEB36D; // 5 frames
        pid = getPIDReverse();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countBackTwo();
        }
    }

    forward.seed = backward.seed * 0x343FD + 0x269EC3; // 1 frame

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.seed = forward.seed * 0x284A930D + 0xA2974C77; // 5 frames
        pid = getPIDForward();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countForwardTwo();
        }
    }

    // Checks if first NL PID back from target matches
    return pidOriginal == pid;
}

// Checks if seed is valid for second shadow with first shadow unset
bool NatureLock::firstShadowUnset(u32 seed)
{
    backward.seed = seed * 0x672D6A61 + 0xE493E638; // 8 frames

    // Build temp pid first to not waste time looping if first nl fails
    pidOriginal = getPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && pidOriginal % 25 == lockInfo[0].getNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.seed = backward.seed * 0x2D4673C5 + 0x16AEB36D; // 5 frames
        pid = getPIDReverse();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countBackTwo();
        }
    }

    forward.seed = backward.seed * 0x343FD + 0x269EC3; // 1 frame

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.seed = forward.seed * 0x284A930D + 0xA2974C77; // 5 frames
        pid = getPIDForward();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countForwardTwo();
        }
    }

    // Checks if first NL PID back from target matches
    return pidOriginal == pid;
}

// Checks if seed is valid for 1st shadow set for Salamence
bool NatureLock::salamenceSet(u32 seed)
{
    backward.seed = seed * 0xD44C2569 + 0xD4016672; // 6 frames

    // Build PID
    pid = getPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
}

// Checks if seed is valid for 1st shadow unset and antishiny(aka Shiny Skip) for Salamence
bool NatureLock::salamenceShinySkip(u32 seed)
{
    backward.seed = seed * 0xB9B33155 + 0xA170F641; // 1 frame

    u32 psv, psvtemp;

    // Check how many advances from shiny skip and build PID
    psv = getPSVReverse();
    psvtemp = getPSVReverse();

    while (psv == psvtemp)
    {
        psvtemp = psv;
        psv = getPSVReverse();
    }

    backward.seed = backward.seed * 0x2D4673C5 + 0x16AEB36D; // 5 frames
    pid = getPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender > genderLower && gender < genderUpper && pid % 25 == nature);
}

// Salamence is a special case of single nature lock and second shadow
// Checks if seed is valid for 1st shadow unset for Salamence
bool NatureLock::salamenceUnset(u32 seed)
{
    backward.seed = seed * 0x672D6A61 + 0xE493E638; // 8 frames

    // Build PID
    pid = getPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
}

// Checks if seed is valid for single nature lock
bool NatureLock::singleNL(u32 seed)
{
    backward.seed = seed * 0xB9B33155 + 0xA170F641; // 1 frame

    // Build PID
    pid = getPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
}

bool NatureLock::eReader(u32 seed, u32 val)
{
    // Check if PID is even valid for E-Reader
    gender = val % 25;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && val % 25 == lockInfo[0].getNature()))
        return false;

    backward.seed = seed * 0xB9B33155 + 0xA170F641; // 1 frame

    // Build temp pid first to not waste time looping if first backwards nl fails
    pidOriginal = getPIDReverse();

    x = 1;
    getCurrLock();
    gender = pidOriginal & 255;
    if (!(gender >= genderLower && gender <= genderUpper && pidOriginal % 25 == nature))
        countBackTwo();

    // Backwards nature lock check loop
    for (x = 2; x < backCount; x++)
    {
        backward.seed = backward.seed * 0x2D4673C5 + 0x16AEB36D; // 5 frames
        pid = getPIDReverse();
        getCurrLock();
        gender = val & 255;
        if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
            countBackTwo();
    }

    forward.seed = backward.seed * 0x343FD + 0x269EC3; // 1 frame

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.seed = forward.seed * 0x284A930D + 0xA2974C77; // 5 frames
        pid = getPIDForward();
        getCurrLock();
        gender = val & 255;
        if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
            countForwardTwo();
    }

    // Checks if first NL PID back from target matches
    return pid == val;
}

// Changes which lock info is being used for Colo
void NatureLock::switchLockColo(int lockNum)
{
    natureLockSetupColo(lockNum);
    backCount = (int)lockInfo.size();
    frontCount = backCount == 1 ? 0 : backCount - 2;
    x = 0;
    if (backCount == 1)
        getCurrLock();
}

// Changes which lock info is being used for Gales
void NatureLock::switchLockGales(int lockNum)
{
    natureLockSetupGales(lockNum);
    backCount = (int)lockInfo.size();
    frontCount = backCount == 1 ? 0 : backCount - 2;
    x = 0;
    if (backCount == 1)
        getCurrLock();
}


// LockInfo

// Constructor for LockInfo
LockInfo::LockInfo(u32 nature, u32 genderLower, u32 genderUpper)
{
    this->nature = nature;
    this->genderLower = genderLower;
    this->genderUpper = genderUpper;
}

// Gets lower gender thresh value
u32 LockInfo::getGenderLower()
{
    return genderLower;
}

// Gets upper gender thresh value
u32 LockInfo::getGenderUpper()
{
    return genderUpper;
}

// Gets nature value
u32 LockInfo::getNature()
{
    return nature;
}
