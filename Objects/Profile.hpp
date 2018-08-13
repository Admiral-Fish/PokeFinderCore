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

#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <QString>
#include <QDomDocument>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <PokeFinderCore/Objects/Game.hpp>

typedef uint32_t u32;
typedef uint16_t u16;

class Profile
{

protected:
    QString profileName;
    Game version;
    int language;
    u16 tid;
    u16 sid;

public:
    Profile(QString profileName, Game version, u16 tid, u16 sid, int language = 0);
    Profile();
    QString getVersionString() const;
    QString getLanguageString() const;
    Game getVersion() const;
    int getLanguage() const;
    QString getProfileName() const;
    u16 getTID() const;
    u16 getSID() const;

};

#endif // PROFILE_HPP
