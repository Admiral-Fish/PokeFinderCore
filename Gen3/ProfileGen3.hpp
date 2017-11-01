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

#ifndef PROFILEGEN3_HPP
#define PROFILEGEN3_HPP

#include <libPokeFinder/Objects/Profile.hpp>
#include <QList>
#include <QStandardItemModel>

class ProfileGen3 : public Profile
{
public:
    ProfileGen3(QString profileName, int version, uint32_t tid, uint32_t sid, int language = 0, bool deadBattery = false, bool valid = false);

    void saveProfile();

    void deleteProfile();

    static ProfileGen3& loadProfile(QString profileName);

    static vector<QList<QStandardItem *>>& loadProfiles();

    static vector<ProfileGen3>& loadProfileList();

    static QString getVersion(int i);

    static QString getLanguage(int i);

    static int getVersionIndex(QString s);

    static int getLanguageIndex(QString s);

    uint32_t tid;
    uint32_t sid;
    bool deadBattery;

};

#endif // PROFILEGEN3_HPP
