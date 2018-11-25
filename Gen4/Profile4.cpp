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

#include "Profile4.hpp"

Profile4::Profile4(const QString &profileName, Game version, u16 tid, u16 sid, Game dual, int radio, int language)
    : Profile(profileName, version, tid, sid, language)
{
    this->dual = dual;
    this->radio = radio;
}

Profile4::Profile4(QJsonObject data)
    : Profile(data["name"].toString(), static_cast<Game>(data["version"].toInt()), data["tid"].toInt(), data["sid"].toInt(), data["version"].toInt())
{
    dual = static_cast<Game>(data["dual"].toInt());
    radio = data["radio"].toInt();
}

Profile4::Profile4() : Profile()
{
    version = Game::Diamond;
    dual = Game::Blank;
    radio = 0;
}

Game Profile4::getDualSlot()
{
    return dual;
}

int Profile4::getRadio()
{
    return radio;
}

QString Profile4::getDualSlotString()
{
    switch (dual)
    {
        case Game::Ruby:
            return QObject::tr("Ruby");
        case Game::Sapphire:
            return QObject::tr("Sapphire");
        case Game::FireRed:
            return QObject::tr("Fire Red");
        case Game::LeafGreen:
            return QObject::tr("Leaf Green");
        case Game::Emerald:
            return QObject::tr("Emerald");
        default:
            return QObject::tr("None");
    }
}

QString Profile4::getRadioString()
{
    switch (radio)
    {
        case 1:
            return QObject::tr("Hoenn Sound");
        case 2:
            return QObject::tr("Sinnoh Sound");
        default:
            return QObject::tr("None");
    }
}

QJsonObject Profile4::getJson()
{
    QJsonObject profile;
    profile["name"] = profileName;
    profile["version"] = version;
    profile["language"] = language;
    profile["tid"] = tid;
    profile["sid"] = sid;
    profile["dual"] = dual;
    profile["radio"] = radio;
    return profile;
}

void Profile4::deleteProfile()
{
    QFile file(QApplication::applicationDirPath() + "/profiles.json");
    if (file.open(QIODevice::ReadWrite | QFile::Text))
    {
        QJsonObject profiles(QJsonDocument::fromJson(file.readAll()).object());
        QJsonArray gen4 = profiles["gen4"].toArray();

        for (int i = 0; i < gen4.size(); i++)
        {
            Profile4 profile(gen4[i].toObject());

            if (profile.profileName == profileName && profile.version == version && profile.language == language &&
                    profile.tid == tid && profile.sid == sid && profile.dual == dual && profile.radio == radio)
            {
                gen4.removeAt(i);
                profiles["gen4"] = gen4;

                file.resize(0);
                file.write(QJsonDocument(profiles).toJson());
                break;
            }
        }

        file.close();
    }
}

void Profile4::updateProfile(Profile4 original)
{
    QFile file(QApplication::applicationDirPath() + "/profiles.json");
    if (file.open(QIODevice::ReadWrite | QFile::Text))
    {
        QJsonObject profiles(QJsonDocument::fromJson(file.readAll()).object());
        QJsonArray gen4 = profiles["gen4"].toArray();

        for (auto &&i : gen4)
        {
            Profile4 profile(i.toObject());

            if (original.profileName == profile.profileName && original.version == profile.version && original.language == profile.language &&
                    original.tid == profile.tid && original.sid == profile.sid && original.dual == profile.dual && original.radio == profile.radio)
            {
                i = getJson();
                profiles["gen4"] = gen4;

                file.resize(0);
                file.write(QJsonDocument(profiles).toJson());
                break;
            }
        }
        file.close();
    }
}

void Profile4::saveProfile()
{
    QFile file(QApplication::applicationDirPath() + "/profiles.json");
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QJsonObject profiles(QJsonDocument::fromJson(file.readAll()).object());
        QJsonArray gen4 = profiles["gen4"].toArray();

        gen4.append(getJson());
        profiles["gen4"] = gen4;

        file.resize(0);
        file.write(QJsonDocument(profiles).toJson());
        file.close();
    }
}

QVector<Profile4> Profile4::loadProfileList()
{
    QVector<Profile4> profileList;

    QFile file(QApplication::applicationDirPath() + "/profiles.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument profiles(QJsonDocument::fromJson(file.readAll()));
        QJsonArray gen4 = profiles["gen4"].toArray();

        for (const auto &&i : gen4)
        {
            profileList.append(Profile4(i.toObject()));
        }
        file.close();
    }

    return profileList;
}
