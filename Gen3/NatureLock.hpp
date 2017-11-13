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

#ifndef NATURELOCK_HPP
#define NATURELOCK_HPP
#include <libPokeFinder/RNG/LCRNG.hpp>
#include <cstdint>
#include <vector>

using namespace std;
typedef uint32_t u32;

// Defines the different types of shadows
enum ShadowType
{
    NoLock,
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

    u32 GetGenderLower();

    u32 GetGenderUpper();
    
    u32 GetNature();
    
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
    LCRNG rng = XDRNG(0);
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

    ShadowType GetType();

    bool IVMethodFirstShadow(u32 seed);

    bool IVMethodFirstShadowSet(u32 seed);

    bool IVMethodFirstShadowShinySkip(u32 seed);

    bool IVMethodFirstShadowUnset(u32 seed);

    bool IVMethodSalamenceSet(u32 seed);

    bool IVMethodSalamenceShinySkip(u32 seed);

    bool IVMethodSalamenceUnset(u32 seed);

    bool IVMethodSingleNL(u32 seed);

    void SwitchLockColo(int lockNum);
    
    void SwitchLockGales(int lockNum);

};

#endif // NATURELOCK_HPP
