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
    NatureLockSetupGales(0);
    backCount = (int)lockInfo.size();
    frontCount = backCount == 1 ? 0 : backCount - 2;
    x = 0;
    if (backCount == 1)
        GetCurrLock();
}

// Keeps rerolling PID backwards by 2 until it finds a match for current lock
void NatureLock::CountBackTwo()
{
    do
    {
        pid = GetPIDReverse();
        gender = pid & 255;
    }
    while (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature));
}

// Keeps rerolling PID forward by 2 until it finds a match for current lock
void NatureLock::CountForwardTwo()
{
    do
    {
        pid = GetPIDForward();
        gender = pid & 255;
    }
    while (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature));
}

// Quick sets the values of the current lock
void NatureLock::GetCurrLock()
{
    nature = lockInfo[x].GetNature();
    genderLower = lockInfo[x].GetGenderLower();
    genderUpper = lockInfo[x].GetGenderUpper();
}

// Generates the next PID forwards
u32 NatureLock::GetPIDForward()
{
    return (forward.Nextuint() & 0xFFFF0000) | forward.Nextushort();
}

// Generates the next PID backwards
u32 NatureLock::GetPIDReverse()
{
    return backward.Nextushort() | (backward.Nextuint() & 0xFFFF0000);
}

// Generates the PSV of the next PID backwards
u32 NatureLock::GetPSVReverse()
{
    return (backward.Nextushort() ^ backward.Nextushort()) >> 3;
}

// Sets up rest of nature lock data for Colo
void NatureLock::NatureLockSetupColo(int lockNum)
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
void NatureLock::NatureLockSetupGales(int lockNum)
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
            backCount = 2;
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
ShadowType NatureLock::GetType()
{
    return type;
}

// Checks if seed is valid for single shadow case
bool NatureLock::FirstShadowNormal(u32 seed)
{
    backward.seed = seed;
    backward.AdvanceFrames(1);

    // Build temp pid first to not waste time looping if first backwards nl fails
    pidOriginal = GetPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].GetGenderLower() && gender <= lockInfo[0].GetGenderUpper() && pidOriginal % 25 == lockInfo[0].GetNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.AdvanceFrames(3);
        pid = GetPIDReverse();
        GetCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                CountBackTwo();
        }
    }

    forward.seed = backward.seed;
    forward.AdvanceFrames(1);

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.AdvanceFrames(3);
        pid = GetPIDForward();
        GetCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                CountForwardTwo();
        }
    }

    // Checks if first NL PID back from target matches
    return pidOriginal == pid;
}

// Checks if seed is valid for second shadow with first shadow set
bool NatureLock::FirstShadowSet(u32 seed)
{
    backward.seed = seed;
    backward.AdvanceFrames(6);

    // Build temp pid first to not waste time looping if first nl fails
    pidOriginal = GetPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].GetGenderLower() && gender <= lockInfo[0].GetGenderUpper() && pidOriginal % 25 == lockInfo[0].GetNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.AdvanceFrames(3);
        pid = GetPIDReverse();
        GetCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                CountBackTwo();
        }
    }

    forward.seed = backward.seed;
    forward.AdvanceFrames(1);

    // Forwards nature lock check
    for (x = frontCount; x >= 0; x--)
    {
        forward.AdvanceFrames(3);
        pid = GetPIDForward();
        GetCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                CountForwardTwo();
        }
    }

    // Checks if first NL PID back from target matches
    return pidOriginal == pid;
}

// Checks if seed is valid for second shadow with first shadow unset and antishiny(aka Shiny Skip)
bool NatureLock::FirstShadowShinySkip(u32 seed)
{
    backward.seed = seed;
    backward.AdvanceFrames(1);

    u32 psv, psvtemp;

    // Check how many advances from shiny skip and build initial pid for first nl
    psv = GetPSVReverse();
    psvtemp = GetPSVReverse();
    while (psv == psvtemp)
    {
        psvtemp = psv;
        psv = GetPSVReverse();
    }

    backward.AdvanceFrames(5);
    pidOriginal = GetPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].GetGenderLower() && gender <= lockInfo[0].GetGenderUpper() && pidOriginal % 25 == lockInfo[0].GetNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.AdvanceFrames(3);
        pid = GetPIDReverse();
        GetCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                CountBackTwo();
        }
    }

    forward.seed = backward.seed;
    forward.AdvanceFrames(1);

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.AdvanceFrames(3);
        pid = GetPIDForward();
        GetCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                CountForwardTwo();
        }
    }

    // Checks if first NL PID back from target matches
    return pidOriginal == pid;
}

// Checks if seed is valid for second shadow with first shadow unset
bool NatureLock::FirstShadowUnset(u32 seed)
{
    backward.seed = seed;
    backward.AdvanceFrames(8);

    // Build temp pid first to not waste time looping if first nl fails
    pidOriginal = GetPIDReverse();

    // Backwards nature lock check
    gender = pidOriginal & 255;
    if (!(gender >= lockInfo[0].GetGenderLower() && gender <= lockInfo[0].GetGenderUpper() && pidOriginal % 25 == lockInfo[0].GetNature()))
        return false;

    // Backwards nature lock check loop
    for (x = 1; x < backCount; x++)
    {
        backward.AdvanceFrames(3);
        pid = GetPIDReverse();
        GetCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                CountBackTwo();
        }
    }

    forward.seed = backward.seed;
    forward.AdvanceFrames(1);

    // Forwards nature lock check loop
    for (x = frontCount; x >= 0; x--)
    {
        forward.AdvanceFrames(3);
        pid = GetPIDForward();
        GetCurrLock();
        if (nature != 500)
        {
            gender = pid & 255;
            if (!(gender >= genderLower && gender <= genderUpper && pid % 25 == nature))
                CountForwardTwo();
        }
    }

    // Checks if first NL PID back from target matches
    return pidOriginal == pid;
}

// Checks if seed is valid for 1st shadow set for Salamence
bool NatureLock::SalamenceSet(u32 seed)
{
    backward.seed = seed;
    backward.AdvanceFrames(6);

    // Build PID
    pid = GetPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
}

// Checks if seed is valid for 1st shadow unset and antishiny(aka Shiny Skip) for Salamence
bool NatureLock::SalamenceShinySkip(u32 seed)
{
    backward.seed = seed;
    backward.AdvanceFrames(1);

    u32 psv, psvtemp;

    // Check how many advances from shiny skip and build PID
    psv = GetPSVReverse();
    psvtemp = GetPSVReverse();

    while (psv == psvtemp)
    {
        psvtemp = psv;
        psv = GetPSVReverse();
    }

    backward.AdvanceFrames(5);
    pid = GetPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender > genderLower && gender < genderUpper && pid % 25 == nature);
}

// Salamence is a special case of single nature lock and second shadow
// Checks if seed is valid for 1st shadow unset for Salamence
bool NatureLock::SalamenceUnset(u32 seed)
{
    backward.seed = seed;
    backward.AdvanceFrames(8);

    // Build PID
    pid = GetPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
}

// Checks if seed is valid for single nature lock
bool NatureLock::SingleNL(u32 seed)
{
    backward.seed = seed;
    backward.AdvanceFrames(1);

    // Build PID
    pid = GetPIDReverse();

    // Backwards nature lock check
    gender = pid & 255;
    return (gender >= genderLower && gender <= genderUpper && pid % 25 == nature);
}

// Changes which lock info is being used for Colo
void NatureLock::SwitchLockColo(int lockNum)
{
    NatureLockSetupColo(lockNum);
    backCount = (int)lockInfo.size();
    frontCount = backCount == 1 ? 0 : backCount - 2;
    x = 0;
    if (backCount == 1)
        GetCurrLock();
}

// Changes which lock info is being used for Gales
void NatureLock::SwitchLockGales(int lockNum)
{
    NatureLockSetupGales(lockNum);
    backCount = (int)lockInfo.size();
    frontCount = backCount == 1 ? 0 : backCount - 2;
    x = 0;
    if (backCount == 1)
        GetCurrLock();
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
u32 LockInfo::GetGenderLower()
{
    return genderLower;
}

// Gets upper gender thresh value
u32 LockInfo::GetGenderUpper()
{
    return genderUpper;
}

// Gets nature value
u32 LockInfo::GetNature()
{
    return nature;
}
