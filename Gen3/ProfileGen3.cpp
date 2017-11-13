/*
 * This file is part of libPok�Finder
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

#include "ProfileGen3.hpp"

ProfileGen3::ProfileGen3(QString profileName, int version, u32 tid, u32 sid, int language, bool deadBattery, bool valid)
{
    this->profileName = profileName;
    this->version = version;
    this->language = language;
    this->tid = tid;
    this->sid = sid;
    this->deadBattery = deadBattery;
    this->valid = valid;

}

void ProfileGen3::deleteProfile()
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

void ProfileGen3::saveProfile()
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
                                    for(int i = 0; i < domNode.childNodes().count(); i++)
                                    {
                                        QDomNode node = domNode.childNodes().at(i);
                                        if(!node.isNull())
                                        {
                                            QDomElement nodeElement = node.toElement();
                                            if(!nodeElement.isNull())
                                            {
                                                if(nodeElement.tagName() == "version")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->version));
                                                }
                                                else if(nodeElement.tagName() == "language")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->language));
                                                }
                                                else if(nodeElement.tagName() == "tid")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->tid));
                                                }
                                                else if(nodeElement.tagName() == "sid")
                                                {
                                                    node.firstChild().setNodeValue(QString::number(this->sid));
                                                }
                                                else if(nodeElement.tagName() == "deadBattery")
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

        if(!exists)
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

            if(profiles.isNull())
            {
                profiles = doc.createElement("Profiles");
                profiles.appendChild(gen3);
                doc.appendChild(profiles);
            } else
            {
                profiles.appendChild(gen3);
            }


        }

        if(file.open(QIODevice::ReadWrite | QIODevice::Truncate | QFile::Text))
        {
            QTextStream stream( &file );
            stream << doc.toString();
        }
        file.close();

    }
}

ProfileGen3& ProfileGen3::loadProfile(QString profileName)
{
    int version;
    int language;
    u32 tid;
    u32 sid;
    bool deadBattery;

    bool exists;
    bool pass;
    QDomDocument doc;
    QFile file(QApplication::applicationDirPath() + "/profiles.xml");
    if(file.open(QIODevice::ReadOnly | QFile::Text))
    {
        doc.setContent(&file);

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
                                if(profileName == infoElement.text())
                                {
                                    exists = true;
                                    for(int i = 0; i < domNode.childNodes().count(); i++)
                                    {
                                        QDomNode node = domNode.childNodes().at(i);
                                        if(!node.isNull())
                                        {
                                            QDomElement nodeElement = node.toElement();
                                            if(!nodeElement.isNull())
                                            {
                                                if(nodeElement.tagName() == "version")
                                                {
                                                    version = nodeElement.text().toInt(&pass, 10);
                                                }
                                                else if(nodeElement.tagName() == "language")
                                                {
                                                    language = nodeElement.text().toInt(&pass, 10);
                                                }
                                                else if(nodeElement.tagName() == "tid")
                                                {
                                                    tid = nodeElement.text().toUInt(&pass, 10);
                                                }
                                                else if(nodeElement.tagName() == "sid")
                                                {
                                                    sid = nodeElement.text().toUInt(&pass, 10);
                                                }
                                                else if(nodeElement.tagName() == "deadBattery")
                                                {
                                                    deadBattery = (nodeElement.text() == "1" ? true : false);
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

        file.close();
    }
    static ProfileGen3 profile(profileName, version, tid, sid, language, deadBattery, exists);
    return profile;

}

vector<QList<QStandardItem *>>& ProfileGen3::loadProfiles()
{
    static vector<QList<QStandardItem *>> profileList;

    profileList.clear();

    bool pass;
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
                    QList<QStandardItem *> row;
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
                                version = infoElement.text().toInt(&pass, 10);
                            }
                            else if(tagName == "language")
                            {
                                language = infoElement.text().toInt(&pass, 10);
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

                    row.append(new QStandardItem(profileName));
                    row.append(new QStandardItem(getVersion(version)));
                    row.append(new QStandardItem(getLanguage(language)));
                    row.append(new QStandardItem(tid));
                    row.append(new QStandardItem(sid));

                    if(version == 0 || version == 1)
                    {
                        row.append(new QStandardItem(deadBattery ? "Yes" : "No"));
                    }
                    else
                    {
                        row.append(new QStandardItem("N/A"));
                    }

                    for(int i = 0; i < row.count(); i++)
                    {
                        row.at(i)->setData(Qt::AlignCenter, Qt::TextAlignmentRole);
                    }

                    profileList.push_back(row);

                }
            }
            domNode = domNode.nextSibling();
        }

        file.close();
    }

    return profileList;
}

vector<ProfileGen3>& ProfileGen3::loadProfileList()
{
    static vector<ProfileGen3> profileList;
    profileList.clear();

    bool pass;
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
                                version = infoElement.text().toInt(&pass, 10);
                            }
                            else if(tagName == "language")
                            {
                                language = infoElement.text().toInt(&pass, 10);
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

                    ProfileGen3 profile(profileName, version, tid.toUInt(&pass, 10), sid.toUInt(&pass, 10), language, deadBattery, true);

                    profileList.push_back(profile);

                }
            }
            domNode = domNode.nextSibling();
        }

        file.close();
    }

    return profileList;
}

QString ProfileGen3::getVersion(int i)
{
    switch(i)
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

QString ProfileGen3::getLanguage(int i)
{
    switch(i)
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

int ProfileGen3::getVersionIndex(QString s)
{
    if(s.toLower() == QObject::tr("Ruby").toLower())
    {
        return 0;
    }
    else if(s.toLower() == QObject::tr("Sapphire").toLower())
    {
        return 1;
    }
    else if(s.toLower() == QObject::tr("Fire Red").toLower())
    {
        return 2;
    }
    else if(s.toLower() == QObject::tr("Leaf Green").toLower())
    {
        return 3;
    }
    else if(s.toLower() == QObject::tr("Emerald").toLower())
    {
        return 4;
    }
    else if(s.toLower() == QObject::tr("XD").toLower())
    {
        return 5;
    }
    else if(s.toLower() == QObject::tr("Colosseum").toLower())
    {
        return 6;
    }
    else
    {
        return 0;
    }
}

int ProfileGen3::getLanguageIndex(QString s)
{
    if(s.toLower() == "eng")
    {
        return 1;
    }
    else if(s.toLower() == "spa")
    {
        return 2;
    }
    else if(s.toLower() == "fre")
    {
        return 3;
    }
    else if(s.toLower() == "ita")
    {
        return 4;
    }
    else if(s.toLower() == "deu")
    {
        return 5;
    }
    else if(s.toLower() == "jpn")
    {
        return 6;
    }
    else
    {
        return 0;
    }
}
