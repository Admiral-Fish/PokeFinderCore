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

#include "Profile.hpp"

Profile::Profile(QString profileName, Game version, u32 tid, u32 sid, int language, bool valid)
{
    this->profileName = profileName;
    this->version = version;
    this->tid = tid;
    this->sid = sid;
    this->language = language;
    this->valid = valid;
}

Profile::Profile()
{
    profileName = "None";
    version = Emerald;
    language = 0;
    tid = 12345;
    sid = 54321;
    valid = false;
}

QString Profile::getVersion()
{
    switch (version)
    {
        case Ruby:
            return QObject::tr("Ruby");
        case Sapphire:
            return QObject::tr("Sapphire");
        case FireRed:
            return QObject::tr("Fire Red");
        case LeafGreen:
            return QObject::tr("Leaf Green");
        case Emerald:
            return QObject::tr("Emerald");
        case Gales:
            return QObject::tr("XD");
        case Colosseum:
            return QObject::tr("Colosseum");
        case Diamond:
            return QObject::tr("Diamond");
        case Pearl:
            return QObject::tr("Pearl");
        case Platinum:
            return QObject::tr("Platinum");
        case HeartGold:
            return QObject::tr("Heart Gold");
        case SoulSilver:
            return QObject::tr("Soul Silver");
        default:
            return "-";
    }
}

QString Profile::getLanguage()
{
    switch (language)
    {
        case 1:
            return "ENG";
        case 2:
            return "SPA";
        case 3:
            return "FRE";
        case 4:
            return "ITA";
        case 5:
            return "DEU";
        case 6:
            return "JPN";
        default:
            return "-";
    }
}
