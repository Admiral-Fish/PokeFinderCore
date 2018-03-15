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

#ifndef NATURELOCK_HPP
#define NATURELOCK_HPP

#include <PokeFinderCore/RNG/LCRNG.hpp>
#include <vector>

using std::vector;

// Defines the different types of shadows
enum ShadowType
{
    SingleLock,
    FirstShadow,
    Salamence,
    SecondShadow
};

class LockInfo
{

private:
    u32 genderUpper;
    u32 genderLower;
    u32 nature;

public:
    LockInfo(u32 nature, u32 genderLower, u32 genderUpper);
    u32 getGenderLower();
    u32 getGenderUpper();
    u32 getNature();

};

class NatureLock
{

private:
    int backCount;
    int frontCount;
    u32 gender;
    u32 genderLower;
    u32 genderUpper;
    vector<LockInfo> lockInfo;
    u32 nature;
    u32 pid;
    u32 pidOriginal;
    LCRNG forward = XDRNG(0);
    LCRNG backward = XDRNGR(0);
    ShadowType type;
    int x;

    void countBackTwo();
    void countForwardTwo();
    void getCurrLock();
    u32 getPIDForward();
    u32 getPIDReverse();
    u32 getPSVReverse();
    void natureLockSetupColo(int lockNum);
    void natureLockSetupGales(int lockNum);

public:
    NatureLock();
    ShadowType getType();
    bool firstShadowNormal(u32 seed);
    bool firstShadowSet(u32 seed);
    bool firstShadowShinySkip(u32 seed);
    bool firstShadowUnset(u32 seed);
    bool salamenceSet(u32 seed);
    bool salamenceShinySkip(u32 seed);
    bool salamenceUnset(u32 seed);
    bool singleNL(u32 seed);
    void switchLockColo(int lockNum);
    void switchLockGales(int lockNum);

};

#endif // NATURELOCK_HPP
