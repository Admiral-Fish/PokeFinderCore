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

QStringList Translator::getSpecies(vector<u32> nums)
{
    QStringList species;

    QString locale = QLocale::QLocale().name().left(2);
    QString path = QString(":/species_%1.txt").arg(locale);
    QFile file(path);

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream ts(&file);
        QStringList input;
        while (!ts.atEnd())
            input << ts.readLine();

        for (u32 x : nums)
            species.push_back(input[x]);
    }

    return species;
}
