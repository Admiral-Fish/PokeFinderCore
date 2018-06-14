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

#ifndef PROFILE3_HPP
#define PROFILE3_HPP

#include <PokeFinderCore/Objects/Profile.hpp>

class Profile3 : public Profile
{

private:
    bool deadBattery;

public:
    Profile3(QString profileName, Game version, u32 tid, u32 sid, int language = 0, bool deadBattery = false);
    Profile3();
    static vector<Profile3> loadProfileList();
    void saveProfile();
    void deleteProfile();
    void updateProfile(Profile3 original);
    bool getDeadBattery() const;

};

#endif // PROFILE3_HPP
