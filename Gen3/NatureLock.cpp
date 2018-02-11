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
    switch(lockNum)
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
        case 27: // Magmar
            lockInfo = { LockInfo(0, 0, 126), LockInfo(18, 191, 255), LockInfo(18, 127, 255) };
            type = FirstShadow;
            break;
        case 28: // Magneton
            lockInfo = { LockInfo(12, 0, 126), LockInfo(0, 127, 255), LockInfo(18, 0, 255) };
            type = FirstShadow;
            break;
        case 29: // Makuhita
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 30: // Manectric
            lockInfo = { LockInfo(6, 0, 126) };
            type = SingleLock;
            break;
        case 31: // Marowak
            lockInfo = { LockInfo(24, 127, 255), LockInfo(500, 500, 500), LockInfo(500, 500, 500), LockInfo(6, 0, 126) };
            type = FirstShadow;
            break;
        case 32: // Mawile
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 33: // Meowth
            lockInfo =  { LockInfo(18, 0, 126), LockInfo(0, 0, 126), LockInfo(6, 63, 255) };
            type = FirstShadow;
            break;
        case 34: // Mr. Mime
            lockInfo = { LockInfo(6, 0, 126), LockInfo(24, 127, 255), LockInfo(18, 127, 255), LockInfo(18, 127, 255) };
            type = SecondShadow;
            break;
        case 35: // Natu
            lockInfo = { LockInfo(0, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 36: // Nosepass
            lockInfo = { LockInfo(12, 0, 126), LockInfo(18, 127, 255), LockInfo(0, 127, 255) };
            type = FirstShadow;
            break;
        case 37: // Numel
            lockInfo = { LockInfo(24, 0, 126), LockInfo(0, 0, 255), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 38: // Paras
            lockInfo = { LockInfo(6, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 39: // Pidgeotto
            lockInfo = { LockInfo(18, 31, 255), LockInfo(12, 127, 255) };
            type = FirstShadow;
            break;
        case 40: // Pineco
            lockInfo = { LockInfo(6, 127, 255) };
            type = SingleLock;
            break;
        case 41: // Pinsir
            lockInfo = { LockInfo(0, 0, 126), LockInfo(18, 191, 255), LockInfo(18, 127, 255) };
            type = SecondShadow;
            break;
        case 42: // Poliwrath
            lockInfo = { LockInfo(6, 0, 126), LockInfo(24, 127, 255), LockInfo(18, 127, 255), LockInfo(18, 127, 255) };
            type = FirstShadow;
            break;
        case 43: // Poochyena
            lockInfo = { LockInfo(12, 0, 126) };
            type = SingleLock;
            break;
        case 44: // Primeape
            lockInfo = { LockInfo(24, 127, 255), LockInfo(6, 0, 126), LockInfo(12, 0, 126), LockInfo(18, 0, 126) };
            type = FirstShadow;
            break;
        case 45: // Ralts
            lockInfo = { LockInfo(18, 127, 255), LockInfo(6, 0, 126), LockInfo(0, 63, 255) };
            type = FirstShadow;
            break;
        case 46: // Rapidash
            lockInfo = { LockInfo(12, 0, 126), LockInfo(6, 127, 255), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 47: // Raticate
            lockInfo = { LockInfo(18, 127, 255), LockInfo(500, 500, 500), LockInfo(18, 0, 126) };
            type = FirstShadow;
            break;
        case 48: // Roselia
            lockInfo = { LockInfo(18, 127, 255), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 49: // Sableye
            lockInfo = { LockInfo(18, 0, 126), LockInfo(6, 0, 126), LockInfo(24, 127, 255) };
            type = SecondShadow;
            break;
        case 50: // Salamence
            lockInfo = { LockInfo(6, 0, 126) };
            type = Salamence;
            break;
        case 51: // Scyther
            lockInfo = { LockInfo(24, 127, 255), LockInfo(6, 0, 126) };
            type = FirstShadow;
            break;
        case 52: // Seedot 3
            lockInfo = { LockInfo(12, 127, 255), LockInfo(0, 127, 255), LockInfo(0, 0, 126), LockInfo(24, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
        case 53: // Seedot 1
            lockInfo = { LockInfo(12, 127, 255), LockInfo(0, 127, 255), LockInfo(18, 0, 126), LockInfo(24, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 54: // Seedot 2
            lockInfo = { LockInfo(6, 127, 255), LockInfo(0, 0, 126), LockInfo(0, 0, 126), LockInfo(24, 0, 126), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 55: // Seel
            lockInfo = { LockInfo(18, 0, 126), LockInfo(18, 127, 255), LockInfo(6, 127, 255) };
            type = FirstShadow;
            break;
        case 56: // Shroomish
            lockInfo = { LockInfo(0, 0, 126), LockInfo(24, 0, 190) };
            type = FirstShadow;
            break;
        case 57: // Snorlax
            lockInfo =  { LockInfo(18, 0, 126), LockInfo(6, 0, 126), LockInfo(24, 63, 255) };
            type = SecondShadow;
            break;
        case 58: // Snorunt
            lockInfo = { LockInfo(6, 0, 126) };
            type = SingleLock;
            break;
        case 59: // Solrock
            lockInfo = { LockInfo(0, 0, 126), LockInfo(6, 127, 255), LockInfo(24, 0, 255) };
            type = FirstShadow;
            break;
        case 60: // Spearow
            lockInfo = { LockInfo(6, 0, 126), LockInfo(18, 127, 255) };
            type = FirstShadow;
            break;
        case 61: // Spheal 3
        case 63: // Spheal 2
            lockInfo = { LockInfo(0, 0, 255), LockInfo(12, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 62: // Spheal 1
            lockInfo = { LockInfo(12, 0, 126), LockInfo(24, 127, 255) };
            type = FirstShadow;
            break;
        case 64: // Spinarak
            lockInfo = { LockInfo(6, 127, 255), LockInfo(12, 0, 126) };
            type = FirstShadow;
            break;
        case 65: // Starmie
            lockInfo = { LockInfo(18, 127, 255), LockInfo(500, 500, 500), LockInfo(0, 0, 126), LockInfo(6, 127, 255), LockInfo(24, 0, 255) };
            type = FirstShadow;
            break;
        case 66: // Swinub
            lockInfo =  { LockInfo(0, 127, 255), LockInfo(18, 0, 126) };
            type = FirstShadow;
            break;
        case 67: // Tangela
            lockInfo = { LockInfo(0, 0, 126), LockInfo(6, 127, 255), LockInfo(12, 0, 190) };
            type = FirstShadow;
            break;
        case 68: // Venomoth
            lockInfo = { LockInfo(12, 63, 255), LockInfo(24, 0, 255), LockInfo(18, 0, 126) };
            type = FirstShadow;
            break;
        case 69: // Voltorb
            lockInfo = { LockInfo(12, 0, 126), LockInfo(18, 127, 255), LockInfo(0, 127, 255) };
            type = FirstShadow;
            break;
        case 70: // Vulpix
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
    backward.seed = seed;
    backward.advanceFrames(1);

    // Build temp pid first to not waste time looping if first backwards nl fails
    pidOriginal = getPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && pidOriginal % 25 == lockInfo[0].getNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.advanceFrames(3);
        pid = getPIDReverse();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countBackTwo();
        }
    }

    forward.seed = backward.seed;
    forward.advanceFrames(1);

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.advanceFrames(3);
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
    backward.seed = seed;
    backward.advanceFrames(6);

    // Build temp pid first to not waste time looping if first nl fails
    pidOriginal = getPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && pidOriginal % 25 == lockInfo[0].getNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.advanceFrames(3);
        pid = getPIDReverse();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countBackTwo();
        }
    }

    forward.seed = backward.seed;
    forward.advanceFrames(1);

    // Forwards nature lock check
    for (x = frontCount; x >= 0; x--)
    {
        forward.advanceFrames(3);
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
    backward.seed = seed;
    backward.advanceFrames(1);

    u32 psv, psvtemp;

    // Check how many advances from shiny skip and build initial pid for first nl
    psv = getPSVReverse();
    psvtemp = getPSVReverse();
    while (psv == psvtemp)
    {
        psvtemp = psv;
        psv = getPSVReverse();
    }

    backward.advanceFrames(5);
    pidOriginal = getPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && pidOriginal % 25 == lockInfo[0].getNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.advanceFrames(3);
        pid = getPIDReverse();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countBackTwo();
        }
    }

    forward.seed = backward.seed;
    forward.advanceFrames(1);

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.advanceFrames(3);
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
    backward.seed = seed;
    backward.advanceFrames(8);

    // Build temp pid first to not waste time looping if first nl fails
    pidOriginal = getPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].getGenderLower() && gender <= lockInfo[0].getGenderUpper() && pidOriginal % 25 == lockInfo[0].getNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.advanceFrames(3);
        pid = getPIDReverse();
        getCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                countBackTwo();
        }
    }

    forward.seed = backward.seed;
    forward.advanceFrames(1);

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.advanceFrames(3);
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
    backward.seed = seed;
    backward.advanceFrames(6);

    // Build PID
    pid = getPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
}

// Checks if seed is valid for 1st shadow unset and antishiny(aka Shiny Skip) for Salamence
bool NatureLock::salamenceShinySkip(u32 seed)
{
    backward.seed = seed;
    backward.advanceFrames(1);

    u32 psv, psvtemp;

    // Check how many advances from shiny skip and build PID
    psv = getPSVReverse();
    psvtemp = getPSVReverse();

    while (psv == psvtemp)
    {
        psvtemp = psv;
        psv = getPSVReverse();
    }

    backward.advanceFrames(5);
    pid = getPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender > genderLower && gender < genderUpper && pid % 25 == nature);
}

// Salamence is a special case of single nature lock and second shadow
// Checks if seed is valid for 1st shadow unset for Salamence
bool NatureLock::salamenceUnset(u32 seed)
{
    backward.seed = seed;
    backward.advanceFrames(8);

    // Build PID
    pid = getPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
}

// Checks if seed is valid for single nature lock
bool NatureLock::singleNL(u32 seed)
{
    backward.seed = seed;
    backward.advanceFrames(1);

    // Build PID
    pid = getPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
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
