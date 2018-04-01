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

#ifndef PROFILE4_HPP
#define PROFILE4_HPP

#include <PokeFinderCore/Objects/Profile.hpp>
#include <QStandardItemModel>

class Profile4 : public Profile
{

public:
    Profile4(QString profileName, Game version, u32 tid, u32 sid, int language = 0, bool valid = false);
    Profile4();
    static vector<Profile4> loadProfileList();
    void saveProfile();
    void deleteProfile();
    void updateProfile(Profile4 original);
    QString getVersion();
    QString getLanguage();

};

#endif // PROFILE4_HPP
