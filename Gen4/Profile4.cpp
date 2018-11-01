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

Profile4::Profile4(const QString &profileName, Game version, u16 tid, u16 sid, Game dual, int radio, int language) : Profile(profileName, version, tid, sid, language)
{
    this->dual = dual;
    this->radio = radio;
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

void Profile4::deleteProfile()
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
                if (domElement.tagName() == "Gen4")
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
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            stream << doc.toString();
        }
        file.close();
    }
}

void Profile4::updateProfile(Profile4 original)
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
            if (!domElement.isNull() && domElement.tagName() == "Gen4")
            {
                QString name = domElement.childNodes().at(0).toElement().text();
                int ver = domElement.childNodes().at(1).toElement().text().toInt();
                int lang = domElement.childNodes().at(2).toElement().text().toInt();
                u16 id = domElement.childNodes().at(3).toElement().text().toUShort();
                u16 id2 = domElement.childNodes().at(4).toElement().text().toUShort();
                int dualVer = domElement.childNodes().at(5).toElement().text().toInt();
                int rad = domElement.childNodes().at(6).toElement().text().toInt();

                if (original.profileName == name && original.version == ver && original.language == lang && original.tid == id && original.sid == id2 && original.dual == dualVer && original.radio == rad)
                {
                    domElement.childNodes().at(0).toElement().firstChild().setNodeValue(profileName);
                    domElement.childNodes().at(1).toElement().firstChild().setNodeValue(QString::number(version));
                    domElement.childNodes().at(2).toElement().firstChild().setNodeValue(QString::number(language));
                    domElement.childNodes().at(3).toElement().firstChild().setNodeValue(QString::number(tid));
                    domElement.childNodes().at(4).toElement().firstChild().setNodeValue(QString::number(sid));
                    domElement.childNodes().at(5).toElement().firstChild().setNodeValue(QString::number(dual));
                    domElement.childNodes().at(6).toElement().firstChild().setNodeValue(QString::number(radio));

                    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QFile::Text))
                    {
                        QTextStream stream(&file);
                        stream.setCodec("UTF-8");
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

void Profile4::saveProfile()
{
    QDomDocument doc;
    QFile file(QApplication::applicationDirPath() + "/profiles.xml");
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        doc.setContent(&file);

        file.close();

        QDomElement profiles = doc.documentElement();

        QDomElement gen4 = doc.createElement("Gen4");
        QDomElement name = doc.createElement("profileName");
        QDomElement ver = doc.createElement("version");
        QDomElement lang = doc.createElement("language");
        QDomElement id1 = doc.createElement("tid");
        QDomElement id2 = doc.createElement("sid");
        QDomElement dualVer = doc.createElement("dual");
        QDomElement rad = doc.createElement("radio");

        name.appendChild(doc.createTextNode(profileName));
        ver.appendChild(doc.createTextNode(QString::number(version)));
        lang.appendChild(doc.createTextNode(QString::number(language)));
        id1.appendChild(doc.createTextNode(QString::number(tid)));
        id2.appendChild(doc.createTextNode(QString::number(sid)));
        dualVer.appendChild(doc.createTextNode(QString::number(dual)));
        rad.appendChild(doc.createTextNode(QString::number(radio)));

        gen4.appendChild(name);
        gen4.appendChild(ver);
        gen4.appendChild(lang);
        gen4.appendChild(id1);
        gen4.appendChild(id2);
        gen4.appendChild(dualVer);
        gen4.appendChild(rad);

        if (profiles.isNull())
        {
            profiles = doc.createElement("Profiles");
            profiles.appendChild(gen4);
            doc.appendChild(profiles);
        }
        else
        {
            profiles.appendChild(gen4);
        }

        if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QFile::Text))
        {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            stream << doc.toString();
        }
        file.close();
    }
}

QVector<Profile4> Profile4::loadProfileList()
{
    static QVector<Profile4> profileList;
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
                if (domElement.tagName() == "Gen4")
                {
                    QDomNode info = domElement.firstChild();
                    QString profileName;
                    int version = 0;
                    int language = 0;
                    u16 tid = 0;
                    u16 sid = 0;
                    int dual = 0;
                    int radio = 0;
                    while (!info.isNull())
                    {
                        QDomElement infoElement = info.toElement();
                        if (!infoElement.isNull())
                        {
                            const QString tagName(infoElement.tagName());
                            if (tagName == "profileName")
                                profileName = infoElement.text();
                            else if (tagName == "version")
                                version = infoElement.text().toInt();
                            else if (tagName == "language")
                                language = infoElement.text().toInt();
                            else if (tagName == "tid")
                                tid = infoElement.text().toUShort();
                            else if (tagName == "sid")
                                sid = infoElement.text().toUShort();
                            else if (tagName == "dual")
                                dual = infoElement.text().toInt();
                            else if (tagName == "radio")
                                radio = infoElement.text().toInt();

                            info = info.nextSibling();
                        }
                    }
                    profileList.append(Profile4(profileName, static_cast<Game>(version), tid, sid, static_cast<Game>(dual), radio, language));
                }
            }
            domNode = domNode.nextSibling();
        }
        file.close();
    }

    return profileList;
}
