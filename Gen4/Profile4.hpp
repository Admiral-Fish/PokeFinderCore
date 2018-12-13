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

#include <Objects/Profile.hpp>

class Profile4 : public Profile
{

public:
    Profile4(const QString &profileName, Game version, u16 tid, u16 sid, Game dual = Game::Blank, int radio = 0, int language = 0, bool radar = false, bool swarm = false);
    Profile4(QJsonObject data);
    Profile4();
    QString getDualSlotString() const;
    Game getDualSlot() const;
    QString getRadioString() const;
    int getRadio() const;
    bool getRadar() const;
    bool getSwarm() const;
    QJsonObject getJson();
    static QVector<Profile4> loadProfileList();
    void saveProfile();
    void deleteProfile();
    void updateProfile(Profile4 original);

private:
    Game dual;
    int radio;
    bool radar;
    bool swarm;

};

#endif // PROFILE4_HPP
