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

#include "Profile3.hpp"

Profile3::Profile3(QString profileName, Game version, u32 tid, u32 sid, int language, bool deadBattery, bool valid)
{
    this->profileName = profileName;
    this->version = version;
    this->language = language;
    this->tid = tid;
    this->sid = sid;
    this->deadBattery = deadBattery;
    this->valid = valid;

}

Profile3::Profile3()
{
    profileName = "";
    version = Emerald;
    language = 0;
    tid = 0;
    sid = 0;
    deadBattery = false;
    valid = false;
}

void Profile3::deleteProfile()
{
    bool exists = false;
    QDomDocument doc;
    QFile file(QApplication::applicationDirPath() + "/profiles.xml");
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        doc.setContent(&file);

        file.close();

        QDomElement profiles = doc.documentElement();
        QDomNode domNode = profiles.firstChild();
        while (!domNode.isNull() && !exists)
        {
            QDomElement domElement = domNode.toElement();
            if (!domElement.isNull())
            {
                if (domElement.tagName() == "Gen3")
                {
                    QDomNode info = domElement.firstChild();
                    while (!info.isNull())
                    {
                        QDomElement infoElement = info.toElement();
                        if (!infoElement.isNull())
                        {
                            const QString tagName(infoElement.tagName());
                            if (tagName == "profileName")
                            {
                                if (this->profileName == infoElement.text())
                                {
                                    exists = true;
                                    domNode.parentNode().removeChild(domNode);
                                }
                                break;
                            }
                            info = info.nextSibling();
                        }
                    }
                }
            }
            domNode = domNode.nextSibling();
        }

        if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QFile::Text))
        {
            QTextStream stream( &file );
            stream << doc.toString();
        }
        file.close();
    }
}

void Profile3::updateProfile(Profile3 original)
{
    QDomDocument doc;
    QFile file(QApplication::applicationDirPath() + "/profiles.xml");
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        doc.setContent(&file);
        file.close();

        QDomElement profiles = doc.documentElement();
        QDomNode domNode = profiles.firstChild();
        while (!domNode.isNull())
        {
            QDomElement domElement = domNode.toElement();
            if (!domElement.isNull() && domElement.tagName() == "Gen3")
            {
                QString name = domElement.childNodes().at(0).toElement().text();
                int ver = domElement.childNodes().at(1).toElement().text().toUInt(NULL, 10);
                int lang = domElement.childNodes().at(2).toElement().text().toUInt(NULL, 10);
                u32 id = domElement.childNodes().at(3).toElement().text().toUInt(NULL, 10);
                u32 id2 = domElement.childNodes().at(4).toElement().text().toInt(NULL, 10);
                bool flag = domElement.childNodes().at(5).toElement().text() == "0" ? false : true;

                if (original.profileName == name && original.version == ver && original.language == lang && original.tid == id && original.sid == id2 && original.deadBattery == flag)
                {
                    domElement.childNodes().at(0).toElement().firstChild().setNodeValue(profileName);
                    domElement.childNodes().at(1).toElement().firstChild().setNodeValue(QString::number(version));
                    domElement.childNodes().at(2).toElement().firstChild().setNodeValue(QString::number(language));
                    domElement.childNodes().at(3).toElement().firstChild().setNodeValue(QString::number(tid));
                    domElement.childNodes().at(4).toElement().firstChild().setNodeValue(QString::number(sid));
                    domElement.childNodes().at(5).toElement().firstChild().setNodeValue(QString::number(deadBattery));

                    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QFile::Text))
                    {
                        QTextStream stream( &file );
                        stream << doc.toString();
                    }
                    file.close();
                    return;
                }
            }
            domNode = domNode.nextSibling();
        }
    }
}

void Profile3::saveProfile()
{
    QDomDocument doc;
    QFile file(QApplication::applicationDirPath() + "/profiles.xml");
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        doc.setContent(&file);

        file.close();

        QDomElement profiles = doc.documentElement();

        QDomElement gen3 = doc.createElement("Gen3");
        QDomElement profileNameE = doc.createElement("profileName");
        QDomElement versionE = doc.createElement("version");
        QDomElement languageE = doc.createElement("language");
        QDomElement tidE = doc.createElement("tid");
        QDomElement sidE = doc.createElement("sid");
        QDomElement deadBatteryE = doc.createElement("deadBattery");

        profileNameE.appendChild(doc.createTextNode(profileName));
        versionE.appendChild(doc.createTextNode(QString::number(version)));
        languageE.appendChild(doc.createTextNode(QString::number(language)));
        tidE.appendChild(doc.createTextNode(QString::number(tid)));
        sidE.appendChild(doc.createTextNode(QString::number(sid)));
        deadBatteryE.appendChild(doc.createTextNode(QString::number(deadBattery)));

        gen3.appendChild(profileNameE);
        gen3.appendChild(versionE);
        gen3.appendChild(languageE);
        gen3.appendChild(tidE);
        gen3.appendChild(sidE);
        gen3.appendChild(deadBatteryE);

        if (profiles.isNull())
        {
            profiles = doc.createElement("Profiles");
            profiles.appendChild(gen3);
            doc.appendChild(profiles);
        }
        else
        {
            profiles.appendChild(gen3);
        }

        if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QFile::Text))
        {
            QTextStream stream( &file );
            stream << doc.toString();
        }
        file.close();
    }
}

vector<Profile3> Profile3::loadProfileList()
{
    static vector<Profile3> profileList;
    profileList.clear();

    QDomDocument doc;
    QFile file(QApplication::applicationDirPath() + "/profiles.xml");
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        doc.setContent(&file);

        QDomElement profiles = doc.documentElement();
        QDomNode domNode = profiles.firstChild();
        while (!domNode.isNull())
        {
            QDomElement domElement = domNode.toElement();
            if (!domElement.isNull())
            {
                if (domElement.tagName() == "Gen3")
                {
                    QDomNode info = domElement.firstChild();
                    QString profileName;
                    int version;
                    int language;
                    QString tid;
                    QString sid;
                    bool deadBattery;
                    while (!info.isNull())
                    {
                        QDomElement infoElement = info.toElement();
                        if (!infoElement.isNull())
                        {
                            const QString tagName(infoElement.tagName());
                            if (tagName == "profileName")
                            {
                                profileName = infoElement.text();
                            }
                            else if (tagName == "version")
                            {
                                version = infoElement.text().toInt(NULL, 10);
                            }
                            else if (tagName == "language")
                            {
                                language = infoElement.text().toInt(NULL, 10);
                            }
                            else if (tagName == "tid")
                            {
                                tid = infoElement.text();
                            }
                            else if (tagName == "sid")
                            {
                                sid = infoElement.text();
                            }
                            else if (tagName == "deadBattery")
                            {
                                deadBattery = (infoElement.text() == "1" ? true : false);
                            }

                            info = info.nextSibling();
                        }
                    }
                    Profile3 profile(profileName, (Game)version, tid.toUInt(NULL, 10), sid.toUInt(NULL, 10), language, deadBattery, true);
                    profileList.push_back(profile);
                }
            }
            domNode = domNode.nextSibling();
        }
        file.close();
    }

    return profileList;
}

QString Profile3::getVersion()
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
        default:
            return "-";
    }
}

QString Profile3::getLanguage()
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
