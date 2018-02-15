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

#include "Profile3.hpp"

Profile3::Profile3(QString profileName, int version, u32 tid, u32 sid, int language, bool deadBattery, bool valid)
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
    version = 0;
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
    if(file.open(QIODevice::ReadOnly | QFile::Text))
    {
        doc.setContent(&file);

        file.close();

        QDomElement profiles = doc.documentElement();
        QDomNode domNode = profiles.firstChild();
        while(!domNode.isNull() && !exists)
        {
            QDomElement domElement = domNode.toElement();
            if(!domElement.isNull())
            {
                if(domElement.tagName() == "Gen3")
                {
                    QDomNode info = domElement.firstChild();
                    while(!info.isNull())
                    {
                        QDomElement infoElement = info.toElement();
                        if(!infoElement.isNull())
                        {
                            const QString tagName(infoElement.tagName());
                            if(tagName == "profileName")
                            {
                                if(this->profileName == infoElement.text())
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

        if(file.open(QIODevice::ReadWrite | QIODevice::Truncate | QFile::Text))
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
                                    for (int i = 0; i < domNode.childNodes().count(); i++)
                                    {
                                        QDomNode node = domNode.childNodes().at(i);
                                        if (!node.isNull())
                                        {
                                            QDomElement nodeElement = node.toElement();
                                            if (!nodeElement.isNull())
                                            {
                                                if (nodeElement.tagName() == "version")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->version));
                                                }
                                                else if (nodeElement.tagName() == "language")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->language));
                                                }
                                                else if (nodeElement.tagName() == "tid")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->tid));
                                                }
                                                else if (nodeElement.tagName() == "sid")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->sid));
                                                }
                                                else if (nodeElement.tagName() == "deadBattery")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->deadBattery));
                                                }
                                            }
                                        }
                                    }
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

        if (!exists)
        {
            QDomElement gen3 = doc.createElement("Gen3");
            QDomElement profileNameE = doc.createElement("profileName");
            QDomElement versionE = doc.createElement("version");
            QDomElement languageE = doc.createElement("language");
            QDomElement tidE = doc.createElement("tid");
            QDomElement sidE = doc.createElement("sid");
            QDomElement deadBatteryE = doc.createElement("deadBattery");

            QDomText profileNameT = doc.createTextNode(this->profileName);
            QDomText versionT = doc.createTextNode(QString::number(this->version));
            QDomText languageT = doc.createTextNode(QString::number(this->language));
            QDomText tidT = doc.createTextNode(QString::number(this->tid));
            QDomText sidT = doc.createTextNode(QString::number(this->sid));
            QDomText deadBatteryT = doc.createTextNode(QString::number(this->deadBattery));

            profileNameE.appendChild(profileNameT);
            versionE.appendChild(versionT);
            languageE.appendChild(languageT);
            tidE.appendChild(tidT);
            sidE.appendChild(sidT);
            deadBatteryE.appendChild(deadBatteryT);

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
    if(file.open(QIODevice::ReadOnly | QFile::Text))
    {
        doc.setContent(&file);

        QDomElement profiles = doc.documentElement();
        QDomNode domNode = profiles.firstChild();
        while(!domNode.isNull())
        {
            QDomElement domElement = domNode.toElement();
            if(!domElement.isNull())
            {
                if(domElement.tagName() == "Gen3")
                {
                    QDomNode info = domElement.firstChild();
                    QString profileName;
                    int version;
                    int language;
                    QString tid;
                    QString sid;
                    bool deadBattery;
                    while(!info.isNull())
                    {
                        QDomElement infoElement = info.toElement();
                        if(!infoElement.isNull())
                        {
                            const QString tagName(infoElement.tagName());
                            if(tagName == "profileName")
                            {
                                profileName = infoElement.text();
                            }
                            else if(tagName == "version")
                            {
                                version = infoElement.text().toInt(NULL, 10);
                            }
                            else if(tagName == "language")
                            {
                                language = infoElement.text().toInt(NULL, 10);
                            }
                            else if(tagName == "tid")
                            {
                                tid = infoElement.text();
                            }
                            else if(tagName == "sid")
                            {
                                sid = infoElement.text();
                            }
                            else if(tagName == "deadBattery")
                            {
                                deadBattery = (infoElement.text() == "1" ? true : false);
                            }

                            info = info.nextSibling();
                        }
                    }
                    Profile3 profile(profileName, version, tid.toUInt(NULL, 10), sid.toUInt(NULL, 10), language, deadBattery, true);
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
    switch(version)
    {
        case 0:
            return QObject::tr("Ruby");
        case 1:
            return QObject::tr("Sapphire");
        case 2:
            return QObject::tr("Fire Red");
        case 3:
            return QObject::tr("Leaf Green");
        case 4:
            return QObject::tr("Emerald");
        case 5:
            return QObject::tr("XD");
        case 6:
            return QObject::tr("Colosseum");
        default:
            return "-";
    }
}

QString Profile3::getLanguage()
{
    switch(language)
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
