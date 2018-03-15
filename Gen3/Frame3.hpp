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

#ifndef FRAME3_HPP
#define FRAME3_HPP

#include <PokeFinderCore/Objects/Frame.hpp>

class Frame3: public Frame
{

public:
    QString lockReason;
    u32 occidentary;
    u32 seed;

    Frame3(u16 tid, u16 sid, u16 psv);
    QString getTime();
    QString getTimeEgg();
    void setIDs(u16 tid, u16 sid, u16 psv);
    void setIVsManual(u32 iv1, u32 iv2, u32 iv3, u32 iv4, u32 iv5, u32 iv6);
    void setInheritanceEmerald(u32 iv1, u32 iv2, u32 par1, u32 par2, u32 par3, u32 inh1,
                               u32 inh2, u32 inh3, vector<u32> parent1, vector<u32> parent2);
    void setInheritance(u32 iv1, u32 iv2, u32 par1, u32 par2, u32 par3, u32 inh1,
                        u32 inh2, u32 inh3, vector<u32> parent1, vector<u32> parent2);

};

#endif // FRAME3_HPP
