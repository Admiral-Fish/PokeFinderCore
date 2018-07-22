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

#include "Translator.hpp"

QStringList Translator::getSpecies(QVector<int> nums)
{
    QStringList species;

    QString locale = QLocale().name().left(2);
    QFile file(QString(":/species_%1.txt").arg(locale));

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream ts(&file);
        ts.setCodec("UTF-8");
        QStringList input;
        while (!ts.atEnd())
            input << ts.readLine();

        for (int x : nums)
            species.append(input[x - 1]);
    }
    file.close();

    return species;
}

QStringList Translator::getLocationsGen3(QVector<int> nums)
{
    QStringList locations;

    QString locale = QLocale().name().left(2);
    QFile file(QString(":/rsefrlg_%1.txt").arg(locale));

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream ts(&file);
        ts.setCodec("UTF-8");
        QStringList input;
        while (!ts.atEnd())
            input << ts.readLine();

        for (int x : nums)
            locations.append(input[x]);
    }
    file.close();

    return locations;
}

QStringList Translator::getLocationsGen4(QVector<int> nums)
{
    QStringList locations;

    QString locale = QLocale().name().left(2);
    QFile file(QString(":/dppthgss_%1.txt").arg(locale));

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream ts(&file);
        ts.setCodec("UTF-8");
        QStringList input;
        while (!ts.atEnd())
            input << ts.readLine();

        for (int x : nums)
            locations.append(input[x]);
    }
    file.close();

    return locations;
}
