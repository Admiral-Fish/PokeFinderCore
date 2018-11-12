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

#ifndef ENCOUNTERAREA3_HPP
#define ENCOUNTERAREA3_HPP

#include <PokeFinderCore/Objects/EncounterArea.hpp>
#include <PokeFinderCore/Objects/Game.hpp>

class EncounterArea3 : public EncounterArea
{

private:
    u32 delay;

public:
    EncounterArea3() = default;
    EncounterArea3(int location, u32 delay, Encounter type, const QVector<int> &species, const QVector<u32> &minLevel, const QVector<u32> &maxLevel);
    EncounterArea3(int location, u32 delay, Encounter type, const QVector<int> &species, const QVector<u32> &levels);
    static QVector<EncounterArea3> getEncounters(Encounter type, Game game);
    u32 calcLevel(u32 index, u32 prng);
    u32 calcLevel(u32 index);
    u16 getEncounterRate() const;
    u32 getDelay() const;

};

namespace Encounters3
{
    const QVector<EncounterArea3> encountersEmerald =
    {
        EncounterArea3(8, 0, Encounter::Grass, {265, 261, 265, 265, 261, 261, 265, 261, 263, 263, 263, 263}, {2, 2, 2, 3, 3, 3, 3, 3, 2, 2, 3, 3}), // Route 101
        EncounterArea3(9, 0, Encounter::Grass, {261, 265, 261, 265, 270, 270, 263, 263, 263, 280, 263, 273}, {3, 3, 4, 4, 3, 4, 3, 3, 4, 4, 4, 3}), // Route 102
        EncounterArea3(10, 0, Encounter::Grass, {261, 261, 261, 261, 278, 263, 263, 263, 278, 278, 278, 278}, {2, 3, 3, 4, 2, 3, 3, 4, 3, 3, 2, 4}), // Route 103
        EncounterArea3(11, 0, Encounter::Grass, {261, 265, 261, 183, 183, 261, 276, 276, 278, 278, 278, 278}, {4, 4, 5, 5, 4, 5, 4, 5, 4, 4, 3, 5}), // Route 104
        EncounterArea3(17, 0, Encounter::Grass, {261, 309, 316, 309, 312, 43, 312, 316, 278, 278, 311, 311}, {12, 12, 12, 13, 13, 13, 13, 13, 12, 12, 12, 13}), // Route 110
        EncounterArea3(18, 0, Encounter::Grass, {27, 328, 27, 328, 343, 343, 27, 328, 343, 331, 331, 331}, {20, 20, 21, 21, 19, 21, 19, 19, 20, 20, 22, 22}), // Route 111
        EncounterArea3(19, 0, Encounter::Grass, {322, 322, 183, 322, 322, 183, 322, 183, 322, 322, 322, 322}, {15, 15, 15, 14, 14, 14, 16, 16, 16, 16, 16, 16}), // Route 112
        EncounterArea3(20, 0, Encounter::Grass, {327, 327, 218, 327, 327, 218, 327, 218, 327, 227, 327, 227}, {15, 15, 15, 14, 14, 14, 16, 16, 16, 16, 16, 16}), // Route 113
        EncounterArea3(21, 0, Encounter::Grass, {333, 270, 333, 333, 270, 271, 271, 271, 336, 336, 336, 274}, {16, 16, 17, 15, 15, 16, 16, 18, 17, 15, 17, 15}), // Route 114
        EncounterArea3(22, 0, Encounter::Grass, {333, 276, 333, 276, 276, 277, 39, 39, 278, 278, 278, 278}, {23, 23, 25, 24, 25, 25, 24, 25, 24, 24, 26, 25}), // Route 115
        EncounterArea3(23, 0, Encounter::Grass, {261, 293, 290, 63, 290, 276, 276, 276, 261, 261, 300, 300}, {6, 6, 6, 7, 7, 6, 7, 8, 7, 8, 7, 8}), // Route 116
        EncounterArea3(24, 0, Encounter::Grass, {261, 43, 261, 43, 183, 43, 314, 314, 314, 314, 313, 273}, {13, 13, 14, 14, 13, 13, 13, 13, 14, 14, 13, 13}), // Route 117
        EncounterArea3(25, 0, Encounter::Grass, {263, 309, 263, 309, 264, 310, 278, 278, 278, 278, 278, 352}, {24, 24, 26, 26, 26, 26, 25, 25, 26, 26, 27, 25}), // Route 118
        EncounterArea3(26, 0, Encounter::Grass, {263, 264, 263, 43, 264, 43, 43, 43, 357, 357, 357, 352}, {25, 25, 27, 25, 27, 26, 27, 24, 25, 26, 27, 25}), // Route 119
        EncounterArea3(27, 0, Encounter::Grass, {261, 262, 262, 43, 183, 43, 43, 183, 359, 359, 352, 273}, {25, 25, 27, 25, 25, 26, 27, 27, 25, 27, 25, 25}), // Route 120
        EncounterArea3(28, 0, Encounter::Grass, {261, 353, 262, 353, 262, 43, 43, 44, 278, 278, 278, 352}, {26, 26, 26, 28, 28, 26, 28, 28, 26, 27, 28, 25}), // Route 121
        EncounterArea3(30, 0, Encounter::Grass, {261, 353, 262, 353, 262, 43, 43, 44, 278, 278, 278, 352}, {26, 26, 26, 28, 28, 26, 28, 28, 26, 27, 28, 25}), // Route 123
        EncounterArea3(37, 0, Encounter::Grass, {360, 360, 360, 360, 360, 360, 360, 360, 360, 360, 360, 360}, {30, 35, 25, 40, 20, 45, 15, 50, 10, 5, 10, 5}), // Route 130
        EncounterArea3(44, 0, Encounter::Grass, {41, 296, 296, 41, 296, 63, 296, 296, 74, 74, 74, 74}, {7, 8, 7, 8, 9, 8, 10, 6, 7, 8, 6, 9}), // Granite Cave 1F
        EncounterArea3(45, 0, Encounter::Grass, {41, 296, 296, 41, 296, 63, 296, 296, 304, 304, 304, 304}, {7, 8, 7, 8, 9, 8, 10, 6, 7, 8, 7, 8}), // Granite Cave Steven's Room
        EncounterArea3(46, 0, Encounter::Grass, {41, 304, 304, 304, 41, 63, 296, 296, 302, 302, 302, 302}, {9, 10, 9, 11, 10, 9, 10, 11, 10, 10, 9, 11}), // Granite Cave B1F
        EncounterArea3(47, 0, Encounter::Grass, {41, 304, 304, 41, 304, 63, 302, 302, 302, 302, 302, 302}, {10, 11, 10, 11, 12, 10, 10, 11, 12, 10, 12, 10}), // Granite Cave B2F
        EncounterArea3(48, 0, Encounter::SafariZone, {43, 43, 203, 203, 177, 84, 44, 202, 25, 202, 25, 202}, {25, 27, 25, 27, 25, 25, 25, 27, 25, 27, 27, 29}), // Safari Zone Area 1
        EncounterArea3(49, 0, Encounter::SafariZone, {43, 43, 203, 203, 177, 84, 44, 202, 25, 202, 25, 202}, {25, 27, 25, 27, 25, 27, 25, 27, 25, 27, 27, 29}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::SafariZone, {111, 43, 111, 43, 84, 44, 44, 84, 85, 127, 85, 127}, {27, 27, 29, 29, 27, 29, 31, 29, 29, 27, 31, 29}), // Safari Zone Area 3
        EncounterArea3(51, 0, Encounter::SafariZone, {231, 43, 231, 43, 177, 44, 44, 177, 178, 214, 178, 214}, {27, 27, 29, 29, 27, 29, 31, 29, 29, 27, 31, 29}), // Safari Zone Area 4
        EncounterArea3(52, 0, Encounter::SafariZone, {191, 179, 191, 179, 190, 167, 163, 209, 234, 207, 234, 207}, {33, 34, 35, 36, 34, 33, 35, 34, 36, 37, 39, 40}), // Safari Zone Area 5
        EncounterArea3(53, 0, Encounter::SafariZone, {190, 216, 190, 216, 191, 165, 163, 204, 228, 241, 228, 241}, {33, 34, 35, 36, 34, 33, 35, 34, 36, 37, 39, 40}), // Safari Zone Area 6
        EncounterArea3(54, 0, Encounter::Grass, {261, 265, 285, 261, 266, 268, 265, 285, 276, 287, 276, 287}, {5, 5, 5, 6, 5, 5, 6, 6, 5, 5, 6, 6}), // Petalburg Woods
        EncounterArea3(55, 0, Encounter::Grass, {293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293}, {6, 7, 6, 6, 7, 7, 5, 8, 5, 8, 5, 8}), // Rusturf Tunnel
        EncounterArea3(57, 0, Encounter::Grass, {100, 81, 100, 81, 100, 81, 100, 81, 100, 81, 100, 81}, {24, 24, 25, 25, 23, 23, 26, 26, 22, 22, 22, 22}), // New Mauville (Entrance)
        EncounterArea3(58, 0, Encounter::Grass, {100, 81, 100, 81, 100, 81, 100, 81, 100, 81, 101, 82}, {24, 24, 25, 25, 23, 23, 26, 26, 22, 22, 26, 26}), // New Mauville (Basement)
        EncounterArea3(59, 0, Encounter::Grass, {41, 41, 41, 41, 41, 338, 338, 338, 41, 41, 41, 41}, {16, 17, 18, 15, 14, 16, 18, 14, 19, 20, 19, 20}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::Grass, {42, 42, 42, 338, 338, 338, 42, 338, 42, 42, 42, 42}, {33, 35, 33, 35, 33, 37, 35, 39, 38, 40, 38, 40}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::Grass, {42, 42, 42, 338, 338, 338, 42, 338, 42, 42, 42, 42}, {33, 35, 33, 35, 33, 37, 35, 39, 38, 40, 38, 40}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::Grass, {42, 42, 371, 338, 371, 338, 371, 338, 42, 42, 42, 42}, {33, 35, 30, 35, 35, 37, 25, 39, 38, 40, 38, 40}), // Meteor Falls B1F 2R
        EncounterArea3(63, 0, Encounter::Grass, {42, 42, 42, 338, 338, 338, 42, 338, 42, 42, 42, 42}, {33, 35, 33, 35, 33, 37, 35, 39, 38, 40, 38, 40}), // Meteor Falls Steven's Cave
        EncounterArea3(64, 0, Encounter::Grass, {353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353}, {27, 28, 26, 25, 29, 24, 23, 22, 29, 24, 29, 24}), // Mt. Pyre 1F-3F
        EncounterArea3(65, 0, Encounter::Grass, {353, 353, 353, 353, 353, 353, 353, 353, 355, 355, 355, 355}, {27, 28, 26, 25, 29, 24, 23, 22, 27, 27, 25, 29}), // Mt. Pyre 4F-6F
        EncounterArea3(66, 0, Encounter::Grass, {353, 353, 353, 353, 37, 37, 37, 37, 278, 278, 278, 278}, {27, 27, 28, 29, 29, 27, 29, 25, 27, 27, 26, 28}), // Mt. Pyre Exterior
        EncounterArea3(67, 0, Encounter::Grass, {353, 353, 353, 353, 353, 353, 353, 355, 355, 355, 358, 358}, {28, 29, 27, 26, 30, 25, 24, 28, 26, 30, 28, 28}), // Mt. Pyre Summit
        EncounterArea3(68, 0, Encounter::Grass, {41, 363, 41, 363, 41, 363, 41, 363, 42, 363, 42, 363}, {26, 26, 28, 28, 30, 30, 32, 32, 32, 32, 32, 32}), // Shoal Cave
        EncounterArea3(69, 0, Encounter::Grass, {41, 363, 41, 363, 41, 363, 361, 363, 42, 361, 42, 361}, {26, 26, 28, 28, 30, 30, 26, 32, 30, 28, 32, 30}), // Shoal Cave Ice Room
        EncounterArea3(70, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 33, 28, 29, 34, 35, 34, 35, 33, 36}), // Seafloor Cavern
        EncounterArea3(71, 0, Encounter::Grass, {42, 297, 305, 294, 41, 296, 42, 297, 304, 293, 304, 293}, {40, 40, 40, 40, 36, 36, 38, 38, 36, 36, 36, 36}), // Victory Road 1F
        EncounterArea3(72, 0, Encounter::Grass, {42, 297, 305, 305, 42, 297, 42, 297, 305, 303, 305, 303}, {40, 40, 40, 40, 38, 38, 42, 42, 42, 38, 42, 38}), // Victory Road B1F
        EncounterArea3(73, 0, Encounter::Grass, {42, 302, 305, 305, 42, 302, 42, 302, 305, 303, 305, 303}, {40, 40, 40, 40, 42, 42, 44, 44, 42, 42, 44, 44}), // Victory Road B2F
        EncounterArea3(74, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 33, 28, 29, 34, 35, 34, 35, 33, 36}), // Cave of Origin Entrance
        EncounterArea3(75, 0, Encounter::Grass, {41, 41, 41, 302, 302, 302, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 30, 32, 34, 33, 34, 34, 35, 33, 36}), // Cave of Origin
        EncounterArea3(76, 0, Encounter::Grass, {322, 109, 322, 66, 324, 218, 109, 66, 324, 324, 88, 88}, {15, 15, 16, 15, 15, 15, 16, 16, 14, 16, 14, 14}), // Fiery Path
        EncounterArea3(77, 0, Encounter::Grass, {322, 322, 66, 322, 325, 66, 325, 66, 322, 325, 322, 325}, {21, 21, 21, 20, 20, 20, 21, 22, 22, 22, 22, 22}), // Jagged Pass
        EncounterArea3(78, 0, Encounter::Grass, {302, 42, 42, 302, 344, 354, 354, 344, 344, 344, 344, 344}, {33, 34, 35, 34, 36, 37, 38, 36, 37, 38, 37, 38}), // Sky Pillar 1F
        EncounterArea3(79, 0, Encounter::Grass, {302, 42, 42, 302, 344, 354, 354, 344, 344, 344, 344, 344}, {33, 34, 35, 34, 36, 37, 38, 36, 37, 38, 37, 38}), // Sky Pillar 3F
        EncounterArea3(80, 0, Encounter::Grass, {302, 42, 42, 302, 344, 354, 354, 344, 344, 334, 334, 334}, {33, 34, 35, 34, 36, 37, 38, 36, 37, 38, 39, 39}), // Sky Pillar 5F
        EncounterArea3(81, 0, Encounter::Grass, {74, 324, 74, 324, 74, 74, 74, 75, 75, 75, 75, 75}, {27, 28, 28, 30, 29, 30, 30, 30, 30, 31, 32, 33}), // Magma Hideout
        EncounterArea3(82, 0, Encounter::Grass, {27, 328, 27, 328, 27, 328, 27, 328, 27, 328, 27, 328}, {21, 21, 20, 20, 20, 20, 22, 22, 23, 23, 24, 24}), // Mirage Tower
        EncounterArea3(83, 0, Encounter::Grass, {235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235}, {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50}), // Artisan Cave
        EncounterArea3(84, 0, Encounter::Grass, {132, 293, 132, 294, 132, 293, 294, 132, 293, 132, 294, 132}, {38, 35, 40, 40, 41, 36, 38, 42, 38, 43, 44, 45}), // Desert Underpass
        EncounterArea3(85, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41}, {10, 12, 8, 14, 10, 12, 16, 6, 8, 14, 8, 14}), // Altering Cave
        EncounterArea3(18, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 15, 15}, {15, 10, 20, 20, 20}), // Route 111
        EncounterArea3(21, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 15, 15}, {15, 10, 20, 20, 20}), // Route 114
        EncounterArea3(47, 0, Encounter::RockSmash, {74, 299, 74, 74, 74}, {10, 10, 5, 15, 15}, {15, 20, 10, 20, 20}), // Granite Cave B2F
        EncounterArea3(51, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 20, 25}, {15, 10, 20, 25, 30}), // Safari Zone Area 4
        EncounterArea3(53, 0, Encounter::RockSmash, {213, 213, 213, 213, 213}, {25, 20, 30, 30, 35}, {30, 25, 35, 35, 40}), // Safari Zone Area 6
        EncounterArea3(72, 0, Encounter::RockSmash, {75, 74, 75, 75, 75}, {30, 30, 35, 35, 35}, {40, 40, 40, 40, 40}), // Victory Road B1F
        EncounterArea3(0, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Dewford Town
        EncounterArea3(1, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::Surfing, {183, 183, 183, 183, 183}, {20, 10, 30, 5, 5}, {30, 20, 35, 10, 10}), // Petalburg City
        EncounterArea3(3, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Slateport City
        EncounterArea3(4, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Lilycove City
        EncounterArea3(5, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::Surfing, {183, 183, 183, 183, 118}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 102
        EncounterArea3(10, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 103
        EncounterArea3(11, 0, Encounter::Surfing, {278, 278, 278, 279, 279}, {10, 15, 15, 25, 25}, {30, 25, 25, 30, 30}), // Route 104
        EncounterArea3(12, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 105
        EncounterArea3(13, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 106
        EncounterArea3(14, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 107
        EncounterArea3(15, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 108
        EncounterArea3(16, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 109
        EncounterArea3(17, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 110
        EncounterArea3(18, 0, Encounter::Surfing, {183, 183, 183, 183, 118}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 111
        EncounterArea3(21, 0, Encounter::Surfing, {183, 183, 183, 183, 118}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 114
        EncounterArea3(22, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 115
        EncounterArea3(24, 0, Encounter::Surfing, {183, 183, 183, 183, 118}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 117
        EncounterArea3(25, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 118
        EncounterArea3(26, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 119
        EncounterArea3(27, 0, Encounter::Surfing, {183, 183, 183, 183, 118}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 120
        EncounterArea3(28, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 121
        EncounterArea3(29, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 122
        EncounterArea3(30, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 123
        EncounterArea3(31, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 124
        EncounterArea3(32, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 125
        EncounterArea3(33, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 126
        EncounterArea3(34, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 127
        EncounterArea3(35, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 128
        EncounterArea3(36, 0, Encounter::Surfing, {72, 278, 278, 279, 321}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 129
        EncounterArea3(37, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 130
        EncounterArea3(38, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 131
        EncounterArea3(39, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 132
        EncounterArea3(40, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 133
        EncounterArea3(41, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 134
        EncounterArea3(42, 0, Encounter::Surfing, {366, 170, 366, 369, 369}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Underwater (Route 124)
        EncounterArea3(43, 0, Encounter::Surfing, {366, 170, 366, 369, 369}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Underwater (Route 126)
        EncounterArea3(49, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::Surfing, {54, 54, 54, 55, 55}, {20, 20, 30, 30, 25}, {30, 30, 35, 35, 40}), // Safari Zone Area 3
        EncounterArea3(52, 0, Encounter::Surfing, {194, 183, 183, 183, 195}, {25, 25, 25, 30, 35}, {30, 30, 30, 35, 40}), // Safari Zone Area 5
        EncounterArea3(56, 0, Encounter::Surfing, {72, 72, 72, 72, 73}, {5, 5, 5, 5, 30}, {35, 35, 35, 35, 35}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::Surfing, {41, 41, 338, 338, 338}, {5, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::Surfing, {42, 42, 338, 338, 338}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::Surfing, {42, 42, 338, 338, 338}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::Surfing, {42, 42, 338, 338, 338}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::Surfing, {72, 41, 363, 363, 363}, {5, 5, 25, 25, 25}, {35, 35, 30, 30, 35}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::Surfing, {72, 41, 41, 42, 42}, {5, 5, 30, 30, 30}, {35, 35, 35, 35, 35}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::Surfing, {42, 42, 42, 42, 42}, {30, 25, 35, 35, 35}, {35, 30, 40, 40, 40}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Dewford Town
        EncounterArea3(1, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Petalburg City
        EncounterArea3(3, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Slateport City
        EncounterArea3(4, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Lilycove City
        EncounterArea3(5, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 102
        EncounterArea3(10, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 103
        EncounterArea3(11, 0, Encounter::OldRod, {129, 129}, {5, 5}, {10, 10}), // Route 104
        EncounterArea3(12, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 105
        EncounterArea3(13, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 106
        EncounterArea3(14, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 107
        EncounterArea3(15, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 108
        EncounterArea3(16, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 109
        EncounterArea3(17, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 110
        EncounterArea3(18, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 111
        EncounterArea3(21, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 114
        EncounterArea3(22, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 115
        EncounterArea3(24, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 117
        EncounterArea3(25, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 118
        EncounterArea3(26, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 119
        EncounterArea3(27, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 120
        EncounterArea3(28, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 121
        EncounterArea3(29, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 122
        EncounterArea3(30, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 123
        EncounterArea3(31, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 124
        EncounterArea3(32, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 125
        EncounterArea3(33, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 126
        EncounterArea3(34, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 127
        EncounterArea3(35, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 128
        EncounterArea3(36, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 129
        EncounterArea3(37, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 130
        EncounterArea3(38, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 131
        EncounterArea3(39, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 132
        EncounterArea3(40, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 133
        EncounterArea3(41, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 134
        EncounterArea3(49, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Safari Zone Area 3
        EncounterArea3(52, 0, Encounter::OldRod, {129, 118}, {25, 25}, {30, 30}), // Safari Zone Area 5
        EncounterArea3(56, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Dewford Town
        EncounterArea3(1, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Petalburg City
        EncounterArea3(3, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Slateport City
        EncounterArea3(4, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Lilycove City
        EncounterArea3(5, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::GoodRod, {129, 129, 129}, {10, 10, 10}, {30, 30, 30}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::GoodRod, {129, 370, 320}, {10, 10, 10}, {30, 30, 30}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Route 102
        EncounterArea3(10, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 103
        EncounterArea3(11, 0, Encounter::GoodRod, {129, 129, 129}, {10, 10, 10}, {30, 30, 30}), // Route 104
        EncounterArea3(12, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 105
        EncounterArea3(13, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 106
        EncounterArea3(14, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 107
        EncounterArea3(15, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 108
        EncounterArea3(16, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 109
        EncounterArea3(17, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 110
        EncounterArea3(18, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 111
        EncounterArea3(21, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 114
        EncounterArea3(22, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 115
        EncounterArea3(24, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Route 117
        EncounterArea3(25, 0, Encounter::GoodRod, {129, 72, 318}, {10, 10, 10}, {30, 30, 30}), // Route 118
        EncounterArea3(26, 0, Encounter::GoodRod, {129, 72, 318}, {10, 10, 10}, {30, 30, 30}), // Route 119
        EncounterArea3(27, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 120
        EncounterArea3(28, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 121
        EncounterArea3(29, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 122
        EncounterArea3(30, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 123
        EncounterArea3(31, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 124
        EncounterArea3(32, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 125
        EncounterArea3(33, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 126
        EncounterArea3(34, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 127
        EncounterArea3(35, 0, Encounter::GoodRod, {129, 370, 320}, {10, 10, 10}, {30, 30, 30}), // Route 128
        EncounterArea3(36, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 129
        EncounterArea3(37, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 130
        EncounterArea3(38, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 131
        EncounterArea3(39, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 132
        EncounterArea3(40, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 133
        EncounterArea3(41, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 134
        EncounterArea3(49, 0, Encounter::GoodRod, {129, 118, 118}, {10, 10, 10}, {30, 25, 30}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::GoodRod, {129, 118, 118}, {10, 10, 10}, {30, 25, 30}), // Safari Zone Area 3
        EncounterArea3(52, 0, Encounter::GoodRod, {129, 118, 223}, {25, 25, 30}, {30, 30, 35}), // Safari Zone Area 5
        EncounterArea3(56, 0, Encounter::GoodRod, {129, 72, 72}, {10, 10, 10}, {30, 30, 30}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Dewford Town
        EncounterArea3(1, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Petalburg City
        EncounterArea3(3, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Slateport City
        EncounterArea3(4, 0, Encounter::SuperRod, {320, 320, 120, 320, 320}, {25, 30, 25, 35, 40}, {30, 35, 30, 40, 45}), // Lilycove City
        EncounterArea3(5, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::SuperRod, {129, 129, 130, 130, 130}, {30, 30, 35, 35, 5}, {35, 35, 40, 45, 45}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::SuperRod, {370, 320, 222, 320, 320}, {30, 30, 30, 35, 40}, {35, 35, 35, 40, 45}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 102
        EncounterArea3(10, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 103
        EncounterArea3(11, 0, Encounter::SuperRod, {129, 129, 129, 129, 129}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 104
        EncounterArea3(12, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 105
        EncounterArea3(13, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 106
        EncounterArea3(14, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 107
        EncounterArea3(15, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 108
        EncounterArea3(16, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 109
        EncounterArea3(17, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 110
        EncounterArea3(18, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 111
        EncounterArea3(21, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 114
        EncounterArea3(22, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 115
        EncounterArea3(24, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 117
        EncounterArea3(25, 0, Encounter::SuperRod, {319, 318, 318, 318, 318}, {30, 30, 20, 35, 40}, {35, 35, 25, 40, 45}), // Route 118
        EncounterArea3(26, 0, Encounter::SuperRod, {318, 318, 318, 318, 318}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 119
        EncounterArea3(27, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 120
        EncounterArea3(28, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 121
        EncounterArea3(29, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 122
        EncounterArea3(30, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 123
        EncounterArea3(31, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 124
        EncounterArea3(32, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 125
        EncounterArea3(33, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 126
        EncounterArea3(34, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 127
        EncounterArea3(35, 0, Encounter::SuperRod, {370, 320, 222, 320, 320}, {30, 30, 30, 35, 40}, {35, 35, 35, 40, 45}), // Route 128
        EncounterArea3(36, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 129
        EncounterArea3(37, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 130
        EncounterArea3(38, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 131
        EncounterArea3(39, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 132
        EncounterArea3(40, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 133
        EncounterArea3(41, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 134
        EncounterArea3(49, 0, Encounter::SuperRod, {118, 118, 119, 119, 119}, {25, 30, 30, 35, 25}, {30, 35, 35, 40, 30}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::SuperRod, {118, 118, 119, 119, 119}, {25, 30, 30, 35, 25}, {30, 35, 35, 40, 30}), // Safari Zone Area 3
        EncounterArea3(52, 0, Encounter::SuperRod, {118, 223, 223, 223, 224}, {25, 25, 30, 30, 35}, {30, 30, 35, 35, 40}), // Safari Zone Area 5
        EncounterArea3(56, 0, Encounter::SuperRod, {72, 72, 73, 73, 73}, {25, 30, 30, 25, 20}, {30, 35, 35, 30, 25}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}) // Victory Road B2F
    };

    const QVector<EncounterArea3> encountersRuby =
    {
        EncounterArea3(8, 0, Encounter::Grass, {265, 263, 265, 265, 263, 263, 265, 263, 261, 261, 261, 261}, {2, 2, 2, 3, 3, 3, 3, 3, 2, 2, 3, 3}), // Route 101
        EncounterArea3(9, 0, Encounter::Grass, {263, 265, 263, 265, 273, 273, 261, 261, 261, 280, 261, 283}, {3, 3, 4, 4, 3, 4, 3, 3, 4, 4, 4, 3}), // Route 102
        EncounterArea3(10, 0, Encounter::Grass, {263, 263, 263, 263, 261, 261, 261, 261, 278, 278, 278, 278}, {2, 3, 3, 4, 2, 3, 3, 4, 3, 3, 2, 4}), // Route 103
        EncounterArea3(11, 0, Encounter::Grass, {263, 265, 263, 265, 263, 263, 276, 276, 278, 278, 278, 278}, {4, 4, 5, 5, 4, 5, 4, 5, 4, 4, 3, 5}), // Route 104
        EncounterArea3(17, 0, Encounter::Grass, {263, 309, 316, 309, 312, 43, 312, 316, 278, 278, 311, 311}, {12, 12, 12, 13, 13, 13, 13, 13, 12, 12, 12, 13}), // Route 110
        EncounterArea3(18, 0, Encounter::Grass, {27, 328, 27, 328, 331, 331, 27, 328, 343, 343, 343, 343}, {20, 20, 21, 21, 19, 21, 19, 19, 20, 20, 22, 22}), // Route 111
        EncounterArea3(19, 0, Encounter::Grass, {322, 322, 66, 322, 322, 66, 322, 66, 322, 322, 322, 322}, {15, 15, 15, 14, 14, 14, 16, 16, 16, 16, 16, 16}), // Route 112
        EncounterArea3(20, 0, Encounter::Grass, {327, 327, 27, 327, 327, 27, 327, 27, 327, 227, 327, 227}, {15, 15, 15, 14, 14, 14, 16, 16, 16, 16, 16, 16}), // Route 113
        EncounterArea3(21, 0, Encounter::Grass, {333, 273, 333, 333, 273, 335, 274, 274, 335, 335, 335, 283}, {16, 16, 17, 15, 15, 16, 16, 18, 17, 15, 17, 15}), // Route 114
        EncounterArea3(22, 0, Encounter::Grass, {333, 276, 333, 276, 276, 277, 39, 39, 278, 278, 278, 278}, {23, 23, 25, 24, 25, 25, 24, 25, 24, 24, 26, 25}), // Route 115
        EncounterArea3(23, 0, Encounter::Grass, {263, 293, 290, 293, 290, 276, 276, 276, 263, 263, 300, 300}, {6, 6, 6, 7, 7, 6, 7, 8, 7, 8, 7, 8}), // Route 116
        EncounterArea3(24, 0, Encounter::Grass, {263, 315, 263, 315, 183, 43, 314, 314, 314, 314, 313, 283}, {13, 13, 14, 14, 13, 13, 13, 13, 14, 14, 13, 13}), // Route 117
        EncounterArea3(25, 0, Encounter::Grass, {263, 309, 263, 309, 264, 310, 278, 278, 278, 278, 278, 352}, {24, 24, 26, 26, 26, 26, 25, 25, 26, 26, 27, 25}), // Route 118
        EncounterArea3(26, 0, Encounter::Grass, {263, 264, 263, 43, 264, 43, 43, 43, 357, 357, 357, 352}, {25, 25, 27, 25, 27, 26, 27, 24, 25, 26, 27, 25}), // Route 119
        EncounterArea3(27, 0, Encounter::Grass, {263, 264, 264, 43, 183, 43, 43, 183, 359, 359, 352, 283}, {25, 25, 27, 25, 25, 26, 27, 27, 25, 27, 25, 25}), // Route 120
        EncounterArea3(28, 0, Encounter::Grass, {263, 355, 264, 355, 264, 43, 43, 44, 278, 278, 278, 352}, {26, 26, 26, 28, 28, 26, 28, 28, 26, 27, 28, 25}), // Route 121
        EncounterArea3(30, 0, Encounter::Grass, {263, 355, 264, 355, 264, 43, 43, 44, 278, 278, 278, 352}, {26, 26, 26, 28, 28, 26, 28, 28, 26, 27, 28, 25}), // Route 123
        EncounterArea3(37, 0, Encounter::Grass, {360, 360, 360, 360, 360, 360, 360, 360, 360, 360, 360, 360}, {30, 35, 25, 40, 20, 45, 15, 50, 10, 5, 10, 5}), // Route 130
        EncounterArea3(44, 0, Encounter::Grass, {41, 296, 296, 41, 296, 63, 296, 296, 74, 74, 74, 74}, {7, 8, 7, 8, 9, 8, 10, 6, 7, 8, 6, 9}), // Granite Cave 1F
        EncounterArea3(45, 0, Encounter::Grass, {41, 296, 296, 41, 296, 63, 296, 296, 304, 304, 304, 304}, {7, 8, 7, 8, 9, 8, 10, 6, 7, 8, 7, 8}), // Granite Cave Steven's Room
        EncounterArea3(46, 0, Encounter::Grass, {41, 304, 304, 304, 41, 63, 296, 296, 303, 303, 303, 303}, {9, 10, 9, 11, 10, 9, 10, 11, 10, 10, 9, 11}), // Granite Cave B1F
        EncounterArea3(47, 0, Encounter::Grass, {41, 304, 304, 41, 304, 63, 303, 303, 303, 303, 303, 303}, {10, 11, 10, 11, 12, 10, 10, 11, 12, 10, 12, 10}), // Granite Cave B2F
        EncounterArea3(48, 0, Encounter::SafariZone, {43, 43, 203, 203, 177, 84, 44, 202, 25, 202, 25, 202}, {25, 27, 25, 27, 25, 25, 25, 27, 25, 27, 27, 29}), // Safari Zone Area 1
        EncounterArea3(49, 0, Encounter::SafariZone, {43, 43, 203, 203, 177, 84, 44, 202, 25, 202, 25, 202}, {25, 27, 25, 27, 25, 25, 25, 27, 25, 27, 27, 29}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::SafariZone, {111, 43, 111, 43, 84, 44, 44, 84, 85, 127, 85, 127}, {27, 27, 29, 29, 27, 29, 31, 29, 29, 27, 31, 29}), // Safari Zone Area 3
        EncounterArea3(51, 0, Encounter::SafariZone, {231, 43, 231, 43, 177, 44, 44, 177, 178, 214, 178, 214}, {27, 27, 29, 29, 27, 29, 31, 29, 29, 27, 31, 29}), // Safari Zone Area 4
        EncounterArea3(54, 0, Encounter::Grass, {263, 265, 285, 263, 266, 268, 265, 285, 276, 287, 276, 287}, {5, 5, 5, 6, 5, 5, 6, 6, 5, 5, 6, 6}), // Petalburg Woods
        EncounterArea3(55, 0, Encounter::Grass, {293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293}, {6, 7, 6, 6, 7, 7, 5, 8, 5, 8, 5, 8}), // Rusturf Tunnel
        EncounterArea3(57, 0, Encounter::Grass, {100, 81, 100, 81, 100, 81, 100, 81, 100, 81, 100, 81}, {24, 24, 25, 25, 23, 23, 26, 26, 22, 22, 22, 22}), // New Mauville (Entrance)
        EncounterArea3(58, 0, Encounter::Grass, {100, 81, 100, 81, 100, 81, 100, 81, 100, 81, 101, 82}, {24, 24, 25, 25, 23, 23, 26, 26, 22, 22, 26, 26}), // New Mauville (Basement)
        EncounterArea3(59, 0, Encounter::Grass, {41, 41, 41, 41, 41, 338, 338, 338, 41, 41, 41, 41}, {16, 17, 18, 15, 14, 16, 18, 14, 19, 20, 19, 20}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::Grass, {42, 42, 42, 338, 338, 338, 42, 338, 42, 42, 42, 42}, {33, 35, 33, 35, 33, 37, 35, 39, 38, 40, 38, 40}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::Grass, {42, 42, 42, 338, 338, 338, 42, 338, 42, 42, 42, 42}, {33, 35, 33, 35, 33, 37, 35, 39, 38, 40, 38, 40}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::Grass, {42, 42, 371, 338, 371, 338, 371, 338, 42, 42, 42, 42}, {33, 35, 30, 35, 35, 37, 25, 39, 38, 40, 38, 40}), // Meteor Falls B1F 2R
        EncounterArea3(64, 0, Encounter::Grass, {355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355}, {27, 28, 26, 25, 29, 24, 23, 22, 29, 24, 29, 24}), // Mt. Pyre 1F-3F
        EncounterArea3(65, 0, Encounter::Grass, {355, 355, 355, 355, 355, 355, 355, 355, 353, 353, 353, 353}, {27, 28, 26, 25, 29, 24, 23, 22, 27, 27, 25, 29}), // Mt. Pyre 4F-6F
        EncounterArea3(66, 0, Encounter::Grass, {355, 307, 355, 307, 355, 37, 37, 37, 278, 278, 278, 278}, {27, 27, 28, 29, 29, 27, 29, 25, 27, 27, 26, 28}), // Mt. Pyre Exterior
        EncounterArea3(67, 0, Encounter::Grass, {355, 355, 355, 355, 355, 355, 355, 353, 353, 353, 358, 358}, {28, 29, 27, 26, 30, 25, 24, 28, 26, 30, 28, 28}), // Mt. Pyre Summit
        EncounterArea3(68, 0, Encounter::Grass, {41, 363, 41, 363, 41, 363, 41, 363, 42, 363, 42, 363}, {26, 26, 28, 28, 30, 30, 32, 32, 32, 32, 32, 32}), // Shoal Cave
        EncounterArea3(69, 0, Encounter::Grass, {41, 363, 41, 363, 41, 363, 361, 363, 42, 361, 42, 361}, {26, 26, 28, 28, 30, 30, 26, 32, 30, 28, 32, 30}), // Shoal Cave Ice Room
        EncounterArea3(70, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 33, 28, 29, 34, 35, 34, 35, 33, 36}), // Seafloor Cavern
        EncounterArea3(71, 0, Encounter::Grass, {42, 297, 305, 294, 41, 296, 42, 297, 304, 293, 304, 293}, {40, 40, 40, 40, 36, 36, 38, 38, 36, 36, 36, 36}), // Victory Road 1F
        EncounterArea3(72, 0, Encounter::Grass, {42, 297, 305, 308, 42, 297, 42, 297, 305, 307, 305, 307}, {40, 40, 40, 40, 38, 38, 42, 42, 42, 38, 42, 38}), // Victory Road B1F
        EncounterArea3(73, 0, Encounter::Grass, {42, 303, 305, 308, 42, 303, 42, 303, 305, 308, 305, 308}, {40, 40, 40, 40, 42, 42, 44, 44, 42, 42, 44, 44}), // Victory Road B2F
        EncounterArea3(74, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 33, 28, 29, 34, 35, 34, 35, 33, 36}), // Cave of Origin Entrance
        EncounterArea3(75, 0, Encounter::Grass, {41, 41, 41, 303, 303, 303, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 30, 32, 34, 33, 34, 34, 35, 33, 36}), // Cave of Origin
        EncounterArea3(76, 0, Encounter::Grass, {322, 109, 322, 66, 324, 218, 109, 66, 324, 324, 88, 88}, {15, 15, 16, 15, 15, 15, 16, 16, 14, 16, 14, 14}), // Fiery Path
        EncounterArea3(77, 0, Encounter::Grass, {322, 322, 66, 322, 325, 66, 325, 66, 322, 325, 322, 325}, {19, 19, 19, 18, 18, 18, 19, 20, 20, 20, 20, 20}), // Jagged Pass
        EncounterArea3(78, 0, Encounter::Grass, {303, 42, 42, 303, 344, 356, 356, 344, 344, 344, 344, 344}, {48, 48, 50, 50, 48, 48, 50, 49, 47, 50, 47, 50}), // Sky Pillar 1F
        EncounterArea3(79, 0, Encounter::Grass, {303, 42, 42, 303, 344, 356, 356, 344, 344, 344, 344, 344}, {51, 51, 53, 53, 51, 51, 53, 52, 50, 53, 50, 53}), // Sky Pillar 3F
        EncounterArea3(80, 0, Encounter::Grass, {303, 42, 42, 303, 344, 356, 356, 344, 344, 334, 334, 334}, {54, 54, 56, 56, 54, 54, 56, 55, 56, 57, 54, 60}), // Sky Pillar 5F
        EncounterArea3(18, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 15, 15}, {15, 10, 20, 20, 20}), // Route 111
        EncounterArea3(21, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 15, 15}, {15, 10, 20, 20, 20}), // Route 114
        EncounterArea3(47, 0, Encounter::RockSmash, {74, 299, 74, 74, 74}, {10, 10, 5, 15, 15}, {15, 20, 10, 20, 20}), // Granite Cave B2F
        EncounterArea3(51, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 20, 25}, {15, 10, 20, 25, 30}), // Safari Zone Area 4
        EncounterArea3(72, 0, Encounter::RockSmash, {75, 74, 75, 75, 75}, {30, 30, 35, 35, 35}, {40, 40, 40, 40, 40}), // Victory Road B1F
        EncounterArea3(0, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Dewford Town
        EncounterArea3(1, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::Surfing, {183, 183, 183, 183, 183}, {20, 10, 30, 5, 5}, {30, 20, 35, 10, 10}), // Petalburg City
        EncounterArea3(3, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Slateport City
        EncounterArea3(4, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Lilycove City
        EncounterArea3(5, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 102
        EncounterArea3(10, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 103
        EncounterArea3(11, 0, Encounter::Surfing, {278, 278, 278, 279, 279}, {10, 15, 15, 25, 25}, {30, 25, 25, 30, 30}), // Route 104
        EncounterArea3(12, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 105
        EncounterArea3(13, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 106
        EncounterArea3(14, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 107
        EncounterArea3(15, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 108
        EncounterArea3(16, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 109
        EncounterArea3(17, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 110
        EncounterArea3(18, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 111
        EncounterArea3(21, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 114
        EncounterArea3(22, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 115
        EncounterArea3(24, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 117
        EncounterArea3(25, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 118
        EncounterArea3(26, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 119
        EncounterArea3(27, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 120
        EncounterArea3(28, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 121
        EncounterArea3(29, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 122
        EncounterArea3(30, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 123
        EncounterArea3(31, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 124
        EncounterArea3(32, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 125
        EncounterArea3(33, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 126
        EncounterArea3(34, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 127
        EncounterArea3(35, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 128
        EncounterArea3(36, 0, Encounter::Surfing, {72, 278, 278, 279, 321}, {5, 10, 15, 25, 35}, {35, 30, 25, 30, 40}), // Route 129
        EncounterArea3(37, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 130
        EncounterArea3(38, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 131
        EncounterArea3(39, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 132
        EncounterArea3(40, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 133
        EncounterArea3(41, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 134
        EncounterArea3(42, 0, Encounter::Surfing, {366, 170, 366, 369, 369}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Underwater (Route 124)
        EncounterArea3(43, 0, Encounter::Surfing, {366, 170, 366, 369, 369}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Underwater (Route 126)
        EncounterArea3(49, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::Surfing, {54, 54, 54, 55, 55}, {20, 20, 30, 30, 25}, {30, 30, 35, 35, 40}), // Safari Zone Area 3
        EncounterArea3(56, 0, Encounter::Surfing, {72, 72, 72, 72, 73}, {5, 5, 5, 5, 30}, {35, 35, 35, 35, 35}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::Surfing, {41, 41, 338, 338, 338}, {5, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::Surfing, {42, 42, 338, 338, 338}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::Surfing, {42, 42, 338, 338, 338}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::Surfing, {42, 42, 338, 338, 338}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::Surfing, {72, 41, 363, 363, 363}, {5, 5, 25, 25, 25}, {35, 35, 30, 30, 35}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::Surfing, {72, 41, 41, 42, 42}, {5, 5, 30, 30, 30}, {35, 35, 35, 35, 35}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::Surfing, {42, 42, 42, 42, 42}, {30, 25, 35, 35, 35}, {35, 30, 40, 40, 40}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Dewford Town
        EncounterArea3(1, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Petalburg City
        EncounterArea3(3, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Slateport City
        EncounterArea3(4, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Lilycove City
        EncounterArea3(5, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::OldRod, {129, 129}, {5, 10}, {10, 15}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 102
        EncounterArea3(10, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 103
        EncounterArea3(11, 0, Encounter::OldRod, {129, 129}, {5, 5}, {10, 10}), // Route 104
        EncounterArea3(12, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 105
        EncounterArea3(13, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 106
        EncounterArea3(14, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 107
        EncounterArea3(15, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 108
        EncounterArea3(16, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 109
        EncounterArea3(17, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 110
        EncounterArea3(18, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 111
        EncounterArea3(21, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 114
        EncounterArea3(22, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 115
        EncounterArea3(24, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 117
        EncounterArea3(25, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 118
        EncounterArea3(26, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 119
        EncounterArea3(27, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 120
        EncounterArea3(28, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 121
        EncounterArea3(29, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 122
        EncounterArea3(30, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 123
        EncounterArea3(31, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 124
        EncounterArea3(32, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 125
        EncounterArea3(33, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 126
        EncounterArea3(34, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 127
        EncounterArea3(35, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 128
        EncounterArea3(36, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 129
        EncounterArea3(37, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 130
        EncounterArea3(38, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 131
        EncounterArea3(39, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 132
        EncounterArea3(40, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 133
        EncounterArea3(41, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 134
        EncounterArea3(49, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Safari Zone Area 3
        EncounterArea3(56, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Dewford Town
        EncounterArea3(1, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Petalburg City
        EncounterArea3(3, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Slateport City
        EncounterArea3(4, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Lilycove City
        EncounterArea3(5, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::GoodRod, {129, 129, 129}, {10, 10, 10}, {30, 30, 30}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::GoodRod, {129, 370, 320}, {10, 10, 10}, {30, 30, 30}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Route 102
        EncounterArea3(10, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 103
        EncounterArea3(11, 0, Encounter::GoodRod, {129, 129, 129}, {10, 10, 10}, {30, 30, 30}), // Route 104
        EncounterArea3(12, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 105
        EncounterArea3(13, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 106
        EncounterArea3(14, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 107
        EncounterArea3(15, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 108
        EncounterArea3(16, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 109
        EncounterArea3(17, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 110
        EncounterArea3(18, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 111
        EncounterArea3(21, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 114
        EncounterArea3(22, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 115
        EncounterArea3(24, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Route 117
        EncounterArea3(25, 0, Encounter::GoodRod, {129, 72, 318}, {10, 10, 10}, {30, 30, 30}), // Route 118
        EncounterArea3(26, 0, Encounter::GoodRod, {129, 72, 318}, {10, 10, 10}, {30, 30, 30}), // Route 119
        EncounterArea3(27, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 120
        EncounterArea3(28, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 121
        EncounterArea3(29, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 122
        EncounterArea3(30, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 123
        EncounterArea3(31, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 124
        EncounterArea3(32, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 125
        EncounterArea3(33, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 126
        EncounterArea3(34, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 127
        EncounterArea3(35, 0, Encounter::GoodRod, {129, 370, 320}, {10, 10, 10}, {30, 30, 30}), // Route 128
        EncounterArea3(36, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 129
        EncounterArea3(37, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 130
        EncounterArea3(38, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 131
        EncounterArea3(39, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 132
        EncounterArea3(40, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 133
        EncounterArea3(41, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 134
        EncounterArea3(49, 0, Encounter::GoodRod, {129, 118, 118}, {10, 10, 10}, {30, 25, 30}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::GoodRod, {129, 118, 118}, {10, 10, 10}, {30, 25, 30}), // Safari Zone Area 3
        EncounterArea3(56, 0, Encounter::GoodRod, {129, 72, 72}, {10, 10, 10}, {30, 30, 30}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Dewford Town
        EncounterArea3(1, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Petalburg City
        EncounterArea3(3, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Slateport City
        EncounterArea3(4, 0, Encounter::SuperRod, {320, 320, 120, 320, 320}, {25, 30, 25, 35, 40}, {30, 35, 30, 40, 45}), // Lilycove City
        EncounterArea3(5, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::SuperRod, {129, 129, 130, 130, 130}, {30, 30, 35, 35, 5}, {35, 35, 40, 45, 45}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::SuperRod, {370, 320, 222, 320, 320}, {30, 30, 30, 35, 40}, {35, 35, 35, 40, 45}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 102
        EncounterArea3(10, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 103
        EncounterArea3(11, 0, Encounter::SuperRod, {129, 129, 129, 129, 129}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 104
        EncounterArea3(12, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 105
        EncounterArea3(13, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 106
        EncounterArea3(14, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 107
        EncounterArea3(15, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 108
        EncounterArea3(16, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 109
        EncounterArea3(17, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 110
        EncounterArea3(18, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 111
        EncounterArea3(21, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 114
        EncounterArea3(22, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 115
        EncounterArea3(24, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 117
        EncounterArea3(25, 0, Encounter::SuperRod, {319, 318, 318, 318, 318}, {30, 30, 20, 35, 40}, {35, 35, 25, 40, 45}), // Route 118
        EncounterArea3(26, 0, Encounter::SuperRod, {318, 318, 318, 318, 318}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 119
        EncounterArea3(27, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 120
        EncounterArea3(28, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 121
        EncounterArea3(29, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 122
        EncounterArea3(30, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 123
        EncounterArea3(31, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 124
        EncounterArea3(32, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 125
        EncounterArea3(33, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 126
        EncounterArea3(34, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 127
        EncounterArea3(35, 0, Encounter::SuperRod, {370, 320, 222, 320, 320}, {30, 30, 30, 35, 40}, {35, 35, 35, 40, 45}), // Route 128
        EncounterArea3(36, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 129
        EncounterArea3(37, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 130
        EncounterArea3(38, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 131
        EncounterArea3(39, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 132
        EncounterArea3(40, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 133
        EncounterArea3(41, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 134
        EncounterArea3(49, 0, Encounter::SuperRod, {118, 118, 119, 119, 119}, {25, 30, 30, 35, 25}, {30, 35, 35, 40, 30}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::SuperRod, {118, 118, 119, 119, 119}, {25, 30, 30, 35, 25}, {30, 35, 35, 40, 30}), // Safari Zone Area 3
        EncounterArea3(56, 0, Encounter::SuperRod, {72, 72, 73, 73, 73}, {25, 30, 30, 25, 20}, {30, 35, 35, 30, 25}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Victory Road B2F
    };

    const QVector<EncounterArea3> encountersSapphire =
    {
        EncounterArea3(8, 0, Encounter::Grass, {265, 263, 265, 265, 263, 263, 265, 263, 261, 261, 261, 261}, {2, 2, 2, 3, 3, 3, 3, 3, 2, 2, 3, 3}), // Route 101
        EncounterArea3(9, 0, Encounter::Grass, {263, 265, 263, 265, 270, 270, 261, 261, 261, 280, 261, 283}, {3, 3, 4, 4, 3, 4, 3, 3, 4, 4, 4, 3}), // Route 102
        EncounterArea3(10, 0, Encounter::Grass, {263, 263, 263, 263, 261, 261, 261, 261, 278, 278, 278, 278}, {2, 3, 3, 4, 2, 3, 3, 4, 3, 3, 2, 4}), // Route 103
        EncounterArea3(11, 0, Encounter::Grass, {263, 265, 263, 265, 263, 263, 276, 276, 278, 278, 278, 278}, {4, 4, 5, 5, 4, 5, 4, 5, 4, 4, 3, 5}), // Route 104
        EncounterArea3(17, 0, Encounter::Grass, {263, 309, 316, 309, 311, 43, 311, 316, 278, 278, 312, 312}, {12, 12, 12, 13, 13, 13, 13, 13, 12, 12, 12, 13}), // Route 110
        EncounterArea3(18, 0, Encounter::Grass, {27, 328, 27, 328, 331, 331, 27, 328, 343, 343, 343, 343}, {20, 20, 21, 21, 19, 21, 19, 19, 20, 20, 22, 22}), // Route 111
        EncounterArea3(19, 0, Encounter::Grass, {322, 322, 66, 322, 322, 66, 322, 66, 322, 322, 322, 322}, {15, 15, 15, 14, 14, 14, 16, 16, 16, 16, 16, 16}), // Route 112
        EncounterArea3(20, 0, Encounter::Grass, {327, 327, 27, 327, 327, 27, 327, 27, 327, 227, 327, 227}, {15, 15, 15, 14, 14, 14, 16, 16, 16, 16, 16, 16}), // Route 113
        EncounterArea3(21, 0, Encounter::Grass, {333, 270, 333, 333, 270, 336, 271, 271, 336, 336, 336, 283}, {16, 16, 17, 15, 15, 16, 16, 18, 17, 15, 17, 15}), // Route 114
        EncounterArea3(22, 0, Encounter::Grass, {333, 276, 333, 276, 276, 277, 39, 39, 278, 278, 278, 278}, {23, 23, 25, 24, 25, 25, 24, 25, 24, 24, 26, 25}), // Route 115
        EncounterArea3(23, 0, Encounter::Grass, {263, 293, 290, 293, 290, 276, 276, 276, 263, 263, 300, 300}, {6, 6, 6, 7, 7, 6, 7, 8, 7, 8, 7, 8}), // Route 116
        EncounterArea3(24, 0, Encounter::Grass, {263, 315, 263, 315, 183, 43, 313, 313, 313, 313, 314, 283}, {13, 13, 14, 14, 13, 13, 13, 13, 14, 14, 13, 13}), // Route 117
        EncounterArea3(25, 0, Encounter::Grass, {263, 309, 263, 309, 264, 310, 278, 278, 278, 278, 278, 352}, {24, 24, 26, 26, 26, 26, 25, 25, 26, 26, 27, 25}), // Route 118
        EncounterArea3(26, 0, Encounter::Grass, {263, 264, 263, 43, 264, 43, 43, 43, 357, 357, 357, 352}, {25, 25, 27, 25, 27, 26, 27, 24, 25, 26, 27, 25}), // Route 119
        EncounterArea3(27, 0, Encounter::Grass, {263, 264, 264, 43, 183, 43, 43, 183, 359, 359, 352, 283}, {25, 25, 27, 25, 25, 26, 27, 27, 25, 27, 25, 25}), // Route 120
        EncounterArea3(28, 0, Encounter::Grass, {263, 353, 264, 353, 264, 43, 43, 44, 278, 278, 278, 352}, {26, 26, 26, 28, 28, 26, 28, 28, 26, 27, 28, 25}), // Route 121
        EncounterArea3(30, 0, Encounter::Grass, {263, 353, 264, 353, 264, 43, 43, 44, 278, 278, 278, 352}, {26, 26, 26, 28, 28, 26, 28, 28, 26, 27, 28, 25}), // Route 123
        EncounterArea3(37, 0, Encounter::Grass, {360, 360, 360, 360, 360, 360, 360, 360, 360, 360, 360, 360}, {30, 35, 25, 40, 20, 45, 15, 50, 10, 5, 10, 5}), // Route 130
        EncounterArea3(44, 0, Encounter::Grass, {41, 296, 296, 41, 296, 63, 296, 296, 74, 74, 74, 74}, {7, 8, 7, 8, 9, 8, 10, 6, 7, 8, 6, 9}), // Granite Cave 1F
        EncounterArea3(45, 0, Encounter::Grass, {41, 296, 296, 41, 296, 63, 296, 296, 304, 304, 304, 304}, {7, 8, 7, 8, 9, 8, 10, 6, 7, 8, 7, 8}), // Granite Cave Steven's Room
        EncounterArea3(46, 0, Encounter::Grass, {41, 304, 304, 304, 41, 63, 296, 296, 302, 302, 302, 302}, {9, 10, 9, 11, 10, 9, 10, 11, 10, 10, 9, 11}), // Granite Cave B1F
        EncounterArea3(47, 0, Encounter::Grass, {41, 304, 304, 41, 304, 63, 302, 302, 302, 302, 302, 302}, {10, 11, 10, 11, 12, 10, 10, 11, 12, 10, 12, 10}), // Granite Cave B2F
        EncounterArea3(48, 9, Encounter::Grass, {43, 43, 203, 203, 177, 84, 44, 202, 25, 202, 25, 202}, {25, 27, 25, 27, 25, 25, 25, 27, 25, 27, 27, 29}), // Safari Zone Area 1
        EncounterArea3(49, 9, Encounter::Grass, {43, 43, 203, 203, 177, 84, 44, 202, 25, 202, 25, 202}, {25, 27, 25, 27, 25, 27, 25, 27, 25, 27, 27, 29}), // Safari Zone Area 2
        EncounterArea3(50, 9, Encounter::Grass, {111, 43, 111, 43, 84, 44, 44, 84, 85, 127, 85, 127}, {27, 27, 29, 29, 27, 29, 31, 29, 29, 27, 31, 29}), // Safari Zone Area 3
        EncounterArea3(51, 9, Encounter::Grass, {231, 43, 231, 43, 177, 44, 44, 177, 178, 214, 178, 214}, {27, 27, 29, 29, 27, 29, 31, 29, 29, 27, 31, 29}), // Safari Zone Area 4
        EncounterArea3(54, 0, Encounter::Grass, {263, 265, 285, 263, 266, 268, 265, 285, 276, 287, 276, 287}, {5, 5, 5, 6, 5, 5, 6, 6, 5, 5, 6, 6}), // Petalburg Woods
        EncounterArea3(55, 0, Encounter::Grass, {293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293}, {6, 7, 6, 6, 7, 7, 5, 8, 5, 8, 5, 8}), // Rusturf Tunnel
        EncounterArea3(57, 0, Encounter::Grass, {100, 81, 100, 81, 100, 81, 100, 81, 100, 81, 100, 81}, {24, 24, 25, 25, 23, 23, 26, 26, 22, 22, 22, 22}), // New Mauville (Entrance)
        EncounterArea3(58, 0, Encounter::Grass, {100, 81, 100, 81, 100, 81, 100, 81, 100, 81, 101, 82}, {24, 24, 25, 25, 23, 23, 26, 26, 22, 22, 26, 26}), // New Mauville (Basement)
        EncounterArea3(59, 0, Encounter::Grass, {41, 41, 41, 41, 41, 337, 337, 337, 41, 41, 41, 41}, {16, 17, 18, 15, 14, 16, 18, 14, 19, 20, 19, 20}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::Grass, {42, 42, 42, 337, 337, 337, 42, 337, 42, 42, 42, 42}, {33, 35, 33, 35, 33, 37, 35, 39, 38, 40, 38, 40}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::Grass, {42, 42, 371, 337, 371, 337, 371, 337, 42, 42, 42, 42}, {33, 35, 30, 35, 35, 37, 25, 39, 38, 40, 38, 40}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::Grass, {42, 42, 42, 337, 337, 337, 42, 337, 42, 42, 42, 42}, {33, 35, 33, 35, 33, 37, 35, 39, 38, 40, 38, 40}), // Meteor Falls B1F 2R
        EncounterArea3(64, 0, Encounter::Grass, {353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353}, {27, 28, 26, 25, 29, 24, 23, 22, 29, 24, 29, 24}), // Mt. Pyre 1F-3F
        EncounterArea3(65, 0, Encounter::Grass, {353, 353, 353, 353, 353, 353, 353, 353, 355, 355, 355, 355}, {27, 28, 26, 25, 29, 24, 23, 22, 27, 27, 25, 29}), // Mt. Pyre 4F-6F
        EncounterArea3(66, 0, Encounter::Grass, {353, 307, 353, 307, 353, 37, 37, 37, 278, 278, 278, 278}, {27, 27, 28, 29, 29, 27, 29, 25, 27, 27, 26, 28}), // Mt. Pyre Exterior
        EncounterArea3(67, 0, Encounter::Grass, {353, 353, 353, 353, 353, 353, 353, 355, 355, 355, 358, 358}, {28, 29, 27, 26, 30, 25, 24, 28, 26, 30, 28, 28}), // Mt. Pyre Summit
        EncounterArea3(68, 0, Encounter::Grass, {41, 363, 41, 363, 41, 363, 41, 363, 42, 363, 42, 363}, {26, 26, 28, 28, 30, 30, 32, 32, 32, 32, 32, 32}), // Shoal Cave
        EncounterArea3(69, 0, Encounter::Grass, {41, 363, 41, 363, 41, 363, 361, 363, 42, 361, 42, 361}, {26, 26, 28, 28, 30, 30, 26, 32, 30, 28, 32, 30}), // Shoal Cave Ice Room
        EncounterArea3(70, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 33, 28, 29, 34, 35, 34, 35, 33, 36}), // Seafloor Cavern
        EncounterArea3(71, 0, Encounter::Grass, {42, 297, 305, 294, 41, 296, 42, 297, 304, 293, 304, 293}, {40, 40, 40, 40, 36, 36, 38, 38, 36, 36, 36, 36}), // Victory Road 1F
        EncounterArea3(72, 0, Encounter::Grass, {42, 297, 305, 308, 42, 297, 42, 297, 305, 307, 305, 307}, {40, 40, 40, 40, 38, 38, 42, 42, 42, 38, 42, 38}), // Victory Road B1F
        EncounterArea3(73, 0, Encounter::Grass, {42, 302, 305, 308, 42, 302, 42, 302, 305, 308, 305, 308}, {40, 40, 40, 40, 42, 42, 44, 44, 42, 42, 44, 44}), // Victory Road B2F
        EncounterArea3(74, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 33, 28, 29, 34, 35, 34, 35, 33, 36}), // Cave of Origin Entrance
        EncounterArea3(75, 0, Encounter::Grass, {41, 41, 41, 302, 302, 302, 41, 41, 42, 42, 42, 42}, {30, 31, 32, 30, 32, 34, 33, 34, 34, 35, 33, 36}), // Cave of Origin
        EncounterArea3(76, 0, Encounter::Grass, {322, 88, 322, 66, 324, 218, 88, 66, 324, 324, 109, 109}, {15, 15, 16, 15, 15, 15, 16, 16, 14, 16, 14, 14}), // Fiery Path
        EncounterArea3(77, 0, Encounter::Grass, {322, 322, 66, 322, 325, 66, 325, 66, 322, 325, 322, 325}, {21, 21, 21, 20, 20, 20, 21, 22, 22, 22, 22, 22}), // Jagged Pass
        EncounterArea3(78, 0, Encounter::Grass, {302, 42, 42, 302, 344, 354, 354, 344, 344, 344, 344, 344}, {48, 48, 50, 50, 48, 48, 50, 49, 47, 50, 47, 50}), // Sky Pillar 1F
        EncounterArea3(79, 0, Encounter::Grass, {302, 42, 42, 302, 344, 354, 354, 344, 344, 344, 344, 344}, {51, 51, 53, 53, 51, 51, 53, 52, 50, 53, 50, 53}), // Sky Pillar 3F
        EncounterArea3(80, 0, Encounter::Grass, {302, 42, 42, 302, 344, 354, 354, 344, 344, 334, 334, 334}, {54, 54, 56, 56, 54, 54, 56, 55, 56, 57, 54, 60}), // Sky Pillar 5F
        EncounterArea3(18, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 15, 15}, {15, 10, 20, 20, 20}), // Route 111
        EncounterArea3(21, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 15, 15}, {15, 10, 20, 20, 20}), // Route 114
        EncounterArea3(47, 0, Encounter::RockSmash, {74, 299, 74, 74, 74}, {10, 10, 5, 15, 15}, {15, 20, 10, 20, 20}), // Granite Cave B2F
        EncounterArea3(51, 0, Encounter::RockSmash, {74, 74, 74, 74, 74}, {10, 5, 15, 20, 25}, {15, 10, 20, 25, 30}), // Safari Zone Area 4
        EncounterArea3(72, 0, Encounter::RockSmash, {75, 74, 75, 75, 75}, {30, 30, 35, 35, 35}, {40, 40, 40, 40, 40}), // Victory Road B1F
        EncounterArea3(0, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Dewford Town
        EncounterArea3(1, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::Surfing, {183, 183, 183, 183, 183}, {20, 10, 30, 5, 5}, {30, 20, 35, 10, 10}), // Petalburg City
        EncounterArea3(3, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Slateport City
        EncounterArea3(4, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Lilycove City
        EncounterArea3(5, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 102
        EncounterArea3(10, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 103
        EncounterArea3(11, 0, Encounter::Surfing, {278, 278, 278, 279, 279}, {10, 15, 15, 25, 25}, {30, 25, 25, 30, 30}), // Route 104
        EncounterArea3(12, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 105
        EncounterArea3(13, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 106
        EncounterArea3(14, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 107
        EncounterArea3(15, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 108
        EncounterArea3(16, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 109
        EncounterArea3(17, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 110
        EncounterArea3(18, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 111
        EncounterArea3(21, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 114
        EncounterArea3(22, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 115
        EncounterArea3(24, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 117
        EncounterArea3(25, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 118
        EncounterArea3(26, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 119
        EncounterArea3(27, 0, Encounter::Surfing, {183, 183, 183, 183, 283}, {20, 10, 30, 5, 20}, {30, 20, 35, 10, 30}), // Route 120
        EncounterArea3(28, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 121
        EncounterArea3(29, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 122
        EncounterArea3(30, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 123
        EncounterArea3(31, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 124
        EncounterArea3(32, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 125
        EncounterArea3(33, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 126
        EncounterArea3(34, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 127
        EncounterArea3(35, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 128
        EncounterArea3(36, 0, Encounter::Surfing, {72, 278, 278, 279, 321}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 129
        EncounterArea3(37, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 130
        EncounterArea3(38, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 131
        EncounterArea3(39, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 132
        EncounterArea3(40, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 133
        EncounterArea3(41, 0, Encounter::Surfing, {72, 278, 278, 279, 279}, {5, 10, 15, 25, 25}, {35, 30, 25, 30, 30}), // Route 134
        EncounterArea3(42, 0, Encounter::Surfing, {366, 170, 366, 369, 369}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Underwater (Route 124)
        EncounterArea3(43, 0, Encounter::Surfing, {366, 170, 366, 369, 369}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Underwater (Route 126)
        EncounterArea3(49, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 30, 30, 30}, {30, 30, 35, 35, 35}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::Surfing, {54, 54, 54, 55, 55}, {20, 20, 30, 30, 25}, {30, 30, 35, 35, 40}), // Safari Zone Area 3
        EncounterArea3(56, 0, Encounter::Surfing, {72, 72, 72, 72, 73}, {5, 5, 5, 5, 30}, {35, 35, 35, 35, 35}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::Surfing, {41, 41, 337, 337, 337}, {5, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::Surfing, {42, 42, 337, 337, 337}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::Surfing, {42, 42, 337, 337, 337}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::Surfing, {42, 42, 337, 337, 337}, {30, 30, 25, 15, 5}, {35, 35, 35, 25, 15}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::Surfing, {72, 41, 363, 363, 363}, {5, 5, 25, 25, 25}, {35, 35, 30, 30, 35}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::Surfing, {72, 41, 41, 42, 42}, {5, 5, 30, 30, 30}, {35, 35, 35, 35, 35}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::Surfing, {42, 42, 42, 42, 42}, {30, 25, 35, 35, 35}, {35, 30, 40, 40, 40}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Dewford Town
        EncounterArea3(1, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Petalburg City
        EncounterArea3(3, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Slateport City
        EncounterArea3(4, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Lilycove City
        EncounterArea3(5, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 102
        EncounterArea3(10, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 103
        EncounterArea3(11, 0, Encounter::OldRod, {129, 129}, {5, 5}, {10, 10}), // Route 104
        EncounterArea3(12, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 105
        EncounterArea3(13, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 106
        EncounterArea3(14, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 107
        EncounterArea3(15, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 108
        EncounterArea3(16, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 109
        EncounterArea3(17, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 110
        EncounterArea3(18, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 111
        EncounterArea3(21, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 1}), // Route 114
        EncounterArea3(22, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 115
        EncounterArea3(24, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 117
        EncounterArea3(25, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 118
        EncounterArea3(26, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 119
        EncounterArea3(27, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Route 120
        EncounterArea3(28, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 121
        EncounterArea3(29, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 122
        EncounterArea3(30, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 123
        EncounterArea3(31, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 124
        EncounterArea3(32, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 125
        EncounterArea3(33, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 126
        EncounterArea3(34, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 127
        EncounterArea3(35, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 128
        EncounterArea3(36, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 129
        EncounterArea3(37, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 130
        EncounterArea3(38, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 131
        EncounterArea3(39, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 132
        EncounterArea3(40, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 133
        EncounterArea3(41, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Route 134
        EncounterArea3(49, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Safari Zone Area 3
        EncounterArea3(56, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::OldRod, {129, 72}, {5, 5}, {10, 10}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::OldRod, {129, 118}, {5, 5}, {10, 10}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Dewford Town
        EncounterArea3(1, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Petalburg City
        EncounterArea3(3, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Slateport City
        EncounterArea3(4, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Lilycove City
        EncounterArea3(5, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::GoodRod, {129, 129, 129}, {10, 10, 10}, {30, 30, 30}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::GoodRod, {129, 370, 320}, {10, 10, 10}, {30, 30, 30}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Route 102
        EncounterArea3(10, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 103
        EncounterArea3(11, 0, Encounter::GoodRod, {129, 129, 129}, {10, 10, 10}, {30, 30, 30}), // Route 104
        EncounterArea3(12, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 105
        EncounterArea3(13, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 106
        EncounterArea3(14, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 107
        EncounterArea3(15, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 108
        EncounterArea3(16, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 109
        EncounterArea3(17, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 110
        EncounterArea3(18, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 111
        EncounterArea3(21, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 114
        EncounterArea3(22, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 115
        EncounterArea3(24, 0, Encounter::GoodRod, {129, 118, 341}, {10, 10, 10}, {30, 30, 30}), // Route 117
        EncounterArea3(25, 0, Encounter::GoodRod, {129, 72, 318}, {10, 10, 10}, {30, 30, 30}), // Route 118
        EncounterArea3(26, 0, Encounter::GoodRod, {129, 72, 318}, {10, 10, 10}, {30, 30, 30}), // Route 119
        EncounterArea3(27, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Route 120
        EncounterArea3(28, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 121
        EncounterArea3(29, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 122
        EncounterArea3(30, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 123
        EncounterArea3(31, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 124
        EncounterArea3(32, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 125
        EncounterArea3(33, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 126
        EncounterArea3(34, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 127
        EncounterArea3(35, 0, Encounter::GoodRod, {129, 370, 320}, {10, 10, 10}, {30, 30, 30}), // Route 128
        EncounterArea3(36, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 129
        EncounterArea3(37, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 130
        EncounterArea3(38, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 131
        EncounterArea3(39, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 132
        EncounterArea3(40, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 133
        EncounterArea3(41, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Route 134
        EncounterArea3(49, 0, Encounter::GoodRod, {129, 118, 118}, {10, 10, 10}, {30, 25, 30}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::GoodRod, {129, 118, 118}, {10, 10, 10}, {30, 25, 30}), // Safari Zone Area 3
        EncounterArea3(56, 0, Encounter::GoodRod, {129, 72, 72}, {10, 10, 10}, {30, 30, 30}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::GoodRod, {129, 72, 320}, {10, 10, 10}, {30, 30, 30}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::GoodRod, {129, 118, 339}, {10, 10, 10}, {30, 30, 30}), // Victory Road B2F
        EncounterArea3(0, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Dewford Town
        EncounterArea3(1, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Pacifidlog Town
        EncounterArea3(2, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Petalburg City
        EncounterArea3(3, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Slateport City
        EncounterArea3(4, 0, Encounter::SuperRod, {320, 320, 120, 320, 320}, {25, 30, 25, 35, 40}, {30, 35, 30, 40, 45}), // Lilycove City
        EncounterArea3(5, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Mossdeep City
        EncounterArea3(6, 0, Encounter::SuperRod, {129, 129, 130, 130, 130}, {30, 30, 35, 35, 5}, {35, 35, 40, 45, 45}), // Sootopolis City
        EncounterArea3(7, 0, Encounter::SuperRod, {370, 320, 222, 320, 320}, {30, 30, 30, 35, 40}, {35, 35, 35, 40, 45}), // Ever Grande City
        EncounterArea3(9, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 102
        EncounterArea3(10, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 103
        EncounterArea3(11, 0, Encounter::SuperRod, {129, 129, 129, 129, 129}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 104
        EncounterArea3(12, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 105
        EncounterArea3(13, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 106
        EncounterArea3(14, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 107
        EncounterArea3(15, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 108
        EncounterArea3(16, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 109
        EncounterArea3(17, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 110
        EncounterArea3(18, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 111
        EncounterArea3(21, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 114
        EncounterArea3(22, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 115
        EncounterArea3(24, 0, Encounter::SuperRod, {341, 341, 341, 341, 341}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 117
        EncounterArea3(25, 0, Encounter::SuperRod, {319, 318, 318, 318, 318}, {30, 30, 20, 35, 40}, {35, 35, 25, 40, 45}), // Route 118
        EncounterArea3(26, 0, Encounter::SuperRod, {318, 318, 318, 318, 318}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 119
        EncounterArea3(27, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 120
        EncounterArea3(28, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 121
        EncounterArea3(29, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 122
        EncounterArea3(30, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Route 123
        EncounterArea3(31, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 124
        EncounterArea3(32, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 125
        EncounterArea3(33, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 126
        EncounterArea3(34, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 127
        EncounterArea3(35, 0, Encounter::SuperRod, {370, 320, 222, 320, 320}, {30, 30, 30, 35, 40}, {35, 35, 35, 40, 45}), // Route 128
        EncounterArea3(36, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 129
        EncounterArea3(37, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 130
        EncounterArea3(38, 0, Encounter::SuperRod, {319, 320, 320, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 131
        EncounterArea3(39, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 132
        EncounterArea3(40, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 133
        EncounterArea3(41, 0, Encounter::SuperRod, {319, 320, 116, 320, 320}, {30, 30, 25, 35, 40}, {35, 35, 30, 40, 45}), // Route 134
        EncounterArea3(49, 0, Encounter::SuperRod, {118, 118, 119, 119, 119}, {25, 30, 30, 35, 25}, {30, 35, 35, 40, 30}), // Safari Zone Area 2
        EncounterArea3(50, 0, Encounter::SuperRod, {118, 118, 119, 119, 119}, {25, 30, 30, 35, 25}, {30, 35, 35, 40, 30}), // Safari Zone Area 3
        EncounterArea3(56, 0, Encounter::SuperRod, {72, 72, 73, 73, 73}, {25, 30, 30, 25, 20}, {30, 35, 35, 30, 25}), // Abandoned Ship
        EncounterArea3(59, 0, Encounter::SuperRod, {339, 339, 339, 339, 339}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Meteor Falls 1F 1R
        EncounterArea3(60, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls 1F 2R
        EncounterArea3(61, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls B1F 1R
        EncounterArea3(62, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Meteor Falls B1F 2R
        EncounterArea3(68, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Shoal Cave
        EncounterArea3(70, 0, Encounter::SuperRod, {320, 320, 320, 320, 320}, {25, 30, 20, 35, 40}, {30, 35, 25, 40, 45}), // Seafloor Cavern
        EncounterArea3(73, 0, Encounter::SuperRod, {339, 339, 340, 340, 340}, {25, 30, 30, 35, 40}, {30, 35, 35, 40, 45}), // Victory Road B2F
    };

    const QVector<EncounterArea3> encountersFireRed =
    {
        EncounterArea3(93, 0, Encounter::Grass, {16, 19, 16, 19, 16, 19, 16, 19, 16, 19, 16, 19}, {3, 3, 3, 3, 2, 2, 3, 3, 4, 4, 5, 4}), // Route 1
        EncounterArea3(94, 0, Encounter::Grass, {19, 16, 19, 16, 19, 16, 19, 16, 10, 13, 10, 13}, {3, 3, 4, 4, 2, 2, 5, 5, 4, 4, 5, 5}), // Route 2
        EncounterArea3(95, 0, Encounter::Grass, {21, 16, 21, 56, 32, 16, 21, 39, 32, 39, 29, 39}, {6, 6, 7, 7, 6, 7, 8, 3, 7, 5, 6, 7}), // Route 3
        EncounterArea3(96, 0, Encounter::Grass, {21, 19, 23, 23, 21, 19, 21, 19, 56, 23, 56, 23}, {10, 10, 6, 10, 8, 8, 12, 12, 10, 8, 12, 12}), // Route 4
        EncounterArea3(97, 0, Encounter::Grass, {52, 16, 43, 52, 43, 16, 43, 16, 16, 52, 16, 52}, {10, 13, 13, 12, 15, 15, 16, 16, 15, 14, 15, 16}), // Route 5
        EncounterArea3(98, 0, Encounter::Grass, {52, 16, 43, 52, 43, 16, 43, 16, 16, 52, 16, 52}, {10, 13, 13, 12, 15, 15, 16, 16, 15, 14, 15, 16}), // Route 6
        EncounterArea3(99, 0, Encounter::Grass, {16, 52, 43, 52, 16, 43, 58, 58, 52, 52, 52, 52}, {19, 17, 19, 18, 22, 22, 18, 20, 17, 19, 17, 20}), // Route 7
        EncounterArea3(100, 0, Encounter::Grass, {16, 52, 58, 16, 52, 23, 58, 23, 23, 58, 23, 58}, {18, 18, 16, 20, 20, 17, 17, 19, 17, 15, 17, 18}), // Route 8
        EncounterArea3(101, 0, Encounter::Grass, {21, 19, 23, 23, 21, 19, 21, 19, 19, 23, 19, 23}, {16, 16, 11, 15, 13, 14, 17, 17, 14, 13, 14, 17}), // Route 9
        EncounterArea3(102, 0, Encounter::Grass, {21, 100, 23, 23, 21, 100, 21, 100, 100, 23, 100, 23}, {16, 16, 11, 15, 13, 14, 17, 17, 14, 13, 14, 17}), // Route 10
        EncounterArea3(103, 0, Encounter::Grass, {23, 21, 23, 21, 96, 96, 23, 21, 23, 96, 23, 96}, {14, 15, 12, 13, 11, 13, 15, 17, 12, 15, 12, 15}), // Route 11
        EncounterArea3(104, 0, Encounter::Grass, {43, 48, 43, 16, 16, 48, 43, 16, 16, 44, 16, 44}, {24, 24, 22, 23, 25, 26, 26, 27, 23, 28, 23, 30}), // Route 12
        EncounterArea3(105, 0, Encounter::Grass, {43, 48, 43, 16, 16, 48, 43, 132, 17, 44, 17, 44}, {24, 24, 22, 27, 25, 26, 26, 25, 29, 28, 29, 30}), // Route 13
        EncounterArea3(106, 0, Encounter::Grass, {43, 48, 43, 132, 16, 48, 43, 44, 132, 17, 132, 17}, {24, 24, 22, 23, 27, 26, 26, 30, 23, 29, 23, 29}), // Route 14
        EncounterArea3(107, 0, Encounter::Grass, {43, 48, 43, 16, 16, 48, 43, 132, 17, 44, 17, 44}, {24, 24, 22, 27, 25, 26, 26, 25, 29, 28, 29, 30}), // Route 15
        EncounterArea3(108, 0, Encounter::Grass, {21, 84, 19, 19, 21, 84, 19, 84, 19, 20, 19, 20}, {20, 18, 18, 20, 22, 20, 22, 22, 18, 23, 18, 25}), // Route 16
        EncounterArea3(109, 0, Encounter::Grass, {21, 84, 21, 84, 20, 20, 84, 20, 19, 22, 19, 22}, {20, 24, 22, 26, 25, 27, 28, 29, 22, 25, 22, 27}), // Route 17
        EncounterArea3(110, 0, Encounter::Grass, {21, 84, 21, 84, 20, 22, 84, 20, 19, 22, 19, 22}, {20, 24, 22, 26, 25, 25, 28, 29, 22, 27, 22, 29}), // Route 18
        EncounterArea3(113, 0, Encounter::Grass, {114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114}, {22, 23, 24, 21, 25, 20, 19, 26, 18, 27, 17, 28}), // Route 21
        EncounterArea3(114, 0, Encounter::Grass, {19, 56, 19, 56, 19, 56, 21, 21, 19, 56, 19, 56}, {3, 3, 4, 4, 2, 2, 3, 5, 5, 5, 5, 5}), // Route 22
        EncounterArea3(115, 0, Encounter::Grass, {56, 22, 56, 21, 23, 23, 57, 24, 21, 22, 21, 22}, {32, 40, 34, 34, 32, 34, 42, 44, 32, 42, 32, 44}), // Route 23
        EncounterArea3(116, 0, Encounter::Grass, {13, 10, 16, 43, 43, 63, 16, 43, 14, 63, 11, 63}, {7, 7, 11, 12, 13, 10, 13, 14, 8, 8, 8, 12}), // Route 24
        EncounterArea3(117, 0, Encounter::Grass, {13, 10, 16, 43, 43, 63, 16, 43, 14, 63, 11, 63}, {8, 8, 13, 14, 13, 11, 11, 12, 9, 9, 9, 13}), // Route 25
        EncounterArea3(118, 0, Encounter::Grass, {10, 13, 10, 13, 10, 13, 11, 14, 14, 25, 14, 25}, {4, 4, 5, 5, 3, 3, 5, 5, 4, 3, 6, 5}), // Viridian Forest
        EncounterArea3(119, 0, Encounter::Grass, {41, 41, 74, 41, 41, 74, 74, 46, 41, 41, 41, 35}, {7, 8, 7, 9, 10, 8, 9, 8, 7, 7, 7, 8}), // Mt. Moon 1F
        EncounterArea3(120, 0, Encounter::Grass, {46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46}, {7, 8, 5, 6, 9, 10, 7, 8, 5, 6, 9, 10}), // Mt. Moon B1F
        EncounterArea3(121, 0, Encounter::Grass, {41, 74, 41, 41, 74, 46, 46, 35, 41, 41, 41, 35}, {8, 9, 9, 10, 10, 10, 12, 10, 11, 11, 11, 12}), // Mt. Moon B2F
        EncounterArea3(123, 0, Encounter::Grass, {50, 50, 50, 50, 50, 50, 50, 50, 50, 51, 50, 51}, {18, 19, 17, 15, 16, 20, 21, 22, 17, 29, 17, 31}), // Diglett's Cave
        EncounterArea3(124, 0, Encounter::Grass, {66, 74, 95, 95, 95, 41, 24, 42, 105, 67, 67, 105}, {32, 32, 40, 43, 46, 32, 44, 44, 44, 44, 46, 46}), // Victory Road 1F
        EncounterArea3(125, 0, Encounter::Grass, {66, 74, 57, 95, 95, 41, 24, 42, 105, 67, 67, 105}, {34, 34, 42, 45, 48, 34, 46, 46, 46, 46, 48, 48}), // Victory Road 2F
        EncounterArea3(126, 0, Encounter::Grass, {66, 74, 95, 95, 95, 41, 24, 42, 105, 67, 67, 105}, {32, 32, 40, 43, 46, 32, 44, 44, 44, 44, 46, 46}), // Victory Road 3F
        EncounterArea3(127, 0, Encounter::Grass, {109, 20, 109, 20, 58, 19, 88, 110, 58, 19, 58, 19}, {28, 32, 30, 36, 30, 28, 28, 32, 32, 26, 32, 26}), // PokÃ©mon Mansion 1F-3F
        EncounterArea3(128, 0, Encounter::Grass, {109, 20, 109, 132, 58, 20, 88, 110, 58, 19, 58, 19}, {28, 34, 30, 30, 30, 38, 28, 34, 32, 26, 32, 26}), // PokÃ©mon Mansion B1F
        EncounterArea3(129, 0, Encounter::SafariZone, {111, 32, 102, 102, 48, 33, 30, 47, 48, 123, 48, 113}, {25, 22, 24, 25, 22, 31, 31, 30, 22, 23, 22, 23}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::SafariZone, {32, 84, 102, 102, 46, 33, 29, 47, 46, 115, 46, 123}, {24, 26, 23, 25, 22, 33, 24, 25, 22, 25, 22, 28}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::SafariZone, {111, 32, 102, 102, 46, 33, 30, 49, 46, 113, 46, 128}, {26, 30, 25, 27, 23, 30, 30, 32, 23, 26, 23, 28}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::SafariZone, {84, 32, 102, 102, 48, 33, 29, 49, 48, 128, 48, 115}, {26, 22, 25, 27, 23, 30, 30, 32, 23, 25, 23, 28}), // Safari Zone Area 3
        EncounterArea3(133, 0, Encounter::Grass, {41, 74, 56, 74, 41, 66, 56, 66, 74, 95, 74, 95}, {15, 16, 16, 17, 16, 16, 17, 17, 15, 13, 15, 15}), // Rock Tunnel 1F
        EncounterArea3(134, 0, Encounter::Grass, {41, 74, 56, 74, 41, 66, 56, 95, 74, 95, 74, 95}, {16, 17, 17, 16, 15, 17, 16, 13, 15, 15, 15, 17}), // Rock Tunnel B1F
        EncounterArea3(135, 0, Encounter::Grass, {54, 54, 54, 41, 41, 41, 42, 42, 54, 41, 54, 42}, {27, 29, 31, 22, 22, 24, 26, 28, 33, 26, 26, 30}), // Seafoam Islands 1F
        EncounterArea3(136, 0, Encounter::Grass, {54, 54, 86, 41, 41, 41, 42, 42, 55, 41, 55, 42}, {29, 31, 28, 22, 22, 24, 26, 28, 33, 26, 35, 30}), // Seafoam Islands B1F
        EncounterArea3(137, 0, Encounter::Grass, {54, 54, 86, 86, 41, 41, 42, 55, 55, 42, 55, 42}, {30, 32, 30, 32, 22, 24, 26, 34, 32, 28, 32, 30}), // Seafoam Islands B2F
        EncounterArea3(138, 0, Encounter::Grass, {86, 86, 54, 54, 55, 41, 42, 55, 87, 42, 87, 42}, {30, 32, 32, 30, 32, 24, 26, 34, 32, 28, 34, 30}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::Grass, {86, 86, 54, 86, 55, 42, 87, 55, 87, 42, 87, 42}, {30, 32, 32, 34, 32, 26, 34, 34, 36, 28, 36, 30}), // Seafoam Islands B4F
        EncounterArea3(140, 0, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 104, 92, 104, 92, 93}, {15, 16, 17, 13, 14, 18, 19, 15, 17, 17, 17, 20}), // PokÃ©mon Tower 3F
        EncounterArea3(141, 0, Encounter::Grass, {92, 92, 92, 92, 92, 92, 93, 104, 92, 104, 92, 92}, {15, 16, 17, 13, 14, 18, 20, 15, 17, 17, 17, 19}), // PokÃ©mon Tower 4F
        EncounterArea3(142, 0, Encounter::Grass, {92, 92, 92, 92, 92, 92, 93, 104, 92, 104, 92, 92}, {15, 16, 17, 13, 14, 18, 20, 15, 17, 17, 17, 19}), // PokÃ©mon Tower 5F
        EncounterArea3(143, 0, Encounter::Grass, {92, 92, 92, 92, 92, 92, 93, 104, 92, 104, 92, 93}, {16, 17, 18, 14, 15, 19, 21, 17, 18, 19, 18, 23}), // PokÃ©mon Tower 6F
        EncounterArea3(144, 0, Encounter::Grass, {92, 92, 92, 92, 92, 93, 104, 104, 92, 93, 92, 93}, {16, 17, 18, 15, 19, 23, 17, 19, 18, 23, 18, 25}), // PokÃ©mon Tower 7F
        EncounterArea3(145, 0, Encounter::Grass, {82, 47, 42, 67, 57, 132, 101, 47, 42, 202, 57, 132}, {49, 49, 46, 46, 52, 52, 58, 58, 55, 55, 61, 61}), // Cerulean Cave 1F
        EncounterArea3(146, 0, Encounter::Grass, {42, 67, 82, 47, 64, 132, 42, 202, 101, 47, 64, 132}, {49, 49, 52, 52, 55, 55, 58, 58, 61, 61, 64, 64}), // Cerulean Cave 2F
        EncounterArea3(147, 0, Encounter::Grass, {64, 132, 82, 47, 42, 67, 64, 132, 101, 47, 42, 202}, {58, 58, 55, 55, 52, 52, 67, 67, 64, 64, 61, 61}), // Cerulean Cave B1F
        EncounterArea3(148, 0, Encounter::Grass, {100, 81, 100, 81, 25, 25, 82, 82, 25, 125, 25, 125}, {22, 22, 25, 25, 22, 24, 31, 34, 26, 32, 26, 35}), // Power Plant
        EncounterArea3(152, 0, Encounter::Grass, {21, 77, 22, 77, 74, 52, 21, 54, 78, 53, 78, 53}, {32, 34, 36, 31, 31, 31, 30, 34, 37, 37, 40, 40}), // Kindle Road
        EncounterArea3(153, 0, Encounter::Grass, {21, 114, 21, 114, 22, 52, 22, 54, 22, 53, 22, 53}, {32, 33, 31, 35, 36, 31, 38, 31, 40, 37, 40, 40}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::Grass, {21, 43, 43, 44, 22, 52, 44, 54, 55, 53, 55, 53}, {31, 30, 32, 36, 36, 31, 38, 31, 37, 37, 40, 40}), // Cape Brink
        EncounterArea3(155, 0, Encounter::Grass, {16, 43, 16, 44, 17, 52, 48, 54, 17, 53, 17, 53}, {32, 31, 29, 36, 34, 31, 34, 31, 37, 37, 40, 40}), // Bond Bridge
        EncounterArea3(156, 0, Encounter::Grass, {206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206}, {15, 15, 10, 10, 20, 20, 25, 30, 25, 30, 5, 35}), // Three Isle Port
        EncounterArea3(159, 0, Encounter::Grass, {16, 161, 17, 187, 161, 52, 187, 54, 17, 53, 17, 53}, {44, 10, 48, 10, 15, 41, 15, 41, 50, 47, 50, 50}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::Grass, {187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187}, {10, 12, 8, 14, 10, 12, 16, 6, 8, 14, 8, 14}), // Memorial Pillar
        EncounterArea3(163, 0, Encounter::Grass, {21, 161, 43, 22, 161, 52, 44, 54, 22, 53, 22, 53}, {44, 10, 44, 48, 15, 41, 48, 41, 50, 47, 50, 50}), // Water Path
        EncounterArea3(164, 0, Encounter::Grass, {177, 21, 193, 194, 22, 52, 202, 54, 177, 53, 177, 53}, {15, 44, 18, 15, 49, 43, 25, 41, 20, 49, 20, 52}), // Ruin Valley
        EncounterArea3(166, 0, Encounter::Grass, {21, 161, 231, 22, 161, 52, 22, 54, 231, 53, 231, 53}, {44, 10, 10, 48, 15, 41, 50, 41, 15, 47, 15, 50}), // Canyon Entrance
        EncounterArea3(167, 0, Encounter::Grass, {74, 231, 104, 22, 105, 52, 95, 227, 246, 53, 246, 53}, {46, 15, 46, 50, 52, 43, 54, 30, 15, 49, 20, 52}), // Sevault Canyon
        EncounterArea3(169, 0, Encounter::Grass, {77, 22, 77, 21, 66, 74, 77, 22, 21, 78, 21, 78}, {30, 38, 33, 32, 35, 33, 36, 40, 30, 39, 30, 42}), // Mt. Ember
        EncounterArea3(170, 0, Encounter::Grass, {74, 66, 74, 74, 66, 66, 74, 66, 74, 66, 74, 66}, {33, 35, 29, 31, 31, 33, 35, 37, 37, 39, 37, 39}), // Mt. Ember Room 1
        EncounterArea3(171, 0, Encounter::Grass, {74, 66, 74, 74, 66, 66, 67, 67, 67, 67, 67, 67}, {34, 36, 30, 32, 32, 34, 38, 38, 40, 40, 40, 40}), // Mt. Ember Room 2
        EncounterArea3(172, 0, Encounter::Grass, {74, 66, 74, 74, 66, 66, 74, 66, 74, 66, 74, 66}, {33, 35, 29, 31, 31, 33, 35, 37, 37, 39, 37, 39}), // Mt. Ember Room 3
        EncounterArea3(173, 0, Encounter::Grass, {74, 66, 74, 74, 66, 66, 74, 67, 74, 67, 74, 67}, {36, 38, 32, 34, 34, 36, 38, 40, 40, 42, 40, 42}), // Mt. Ember 1F
        EncounterArea3(174, 0, Encounter::Grass, {74, 74, 74, 74, 218, 218, 74, 218, 74, 218, 74, 218}, {38, 36, 34, 40, 24, 26, 42, 28, 42, 30, 42, 30}), // Mt. Ember B1F
        EncounterArea3(175, 0, Encounter::Grass, {74, 218, 74, 218, 218, 218, 74, 218, 74, 218, 74, 218}, {40, 26, 42, 24, 28, 30, 44, 32, 44, 22, 44, 22}), // Mt. Ember B2F
        EncounterArea3(176, 0, Encounter::Grass, {218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218}, {26, 28, 30, 32, 24, 22, 20, 34, 36, 18, 36, 18}), // Mt. Ember B3F
        EncounterArea3(177, 0, Encounter::Grass, {74, 218, 74, 218, 218, 218, 74, 218, 74, 218, 74, 218}, {40, 26, 42, 24, 28, 30, 44, 32, 44, 22, 44, 22}), // Mt. Ember B4F
        EncounterArea3(178, 0, Encounter::Grass, {74, 74, 74, 74, 218, 218, 74, 218, 74, 218, 74, 218}, {38, 36, 34, 40, 24, 26, 42, 28, 42, 30, 42, 30}), // Mt. Ember B5F
        EncounterArea3(179, 0, Encounter::Grass, {17, 44, 16, 43, 48, 96, 102, 54, 49, 97, 49, 97}, {37, 35, 32, 30, 34, 34, 35, 31, 37, 37, 40, 40}), // Berry Forest
        EncounterArea3(180, 0, Encounter::Grass, {86, 42, 86, 86, 41, 87, 87, 54, 42, 87, 42, 87}, {43, 45, 45, 47, 40, 49, 51, 41, 48, 53, 48, 53}), // Icefall Cave
        EncounterArea3(181, 0, Encounter::Grass, {220, 42, 86, 220, 41, 220, 225, 220, 42, 220, 42, 220}, {25, 45, 45, 27, 40, 29, 30, 31, 48, 23, 48, 23}), // Icefall Cave 1F
        EncounterArea3(182, 0, Encounter::Grass, {220, 42, 86, 220, 41, 220, 225, 220, 42, 220, 42, 220}, {25, 45, 45, 27, 40, 29, 30, 31, 48, 23, 48, 23}), // Icefall Cave B1F
        EncounterArea3(183, 0, Encounter::Grass, {86, 42, 86, 86, 41, 87, 87, 54, 42, 87, 42, 87}, {43, 45, 45, 47, 40, 49, 51, 41, 48, 53, 48, 53}), // Icefall Cave Back
        EncounterArea3(184, 0, Encounter::Grass, {167, 14, 167, 10, 13, 214, 11, 214, 165, 214, 165, 214}, {9, 9, 14, 6, 6, 15, 9, 20, 9, 25, 14, 30}), // Pattern Bush
        EncounterArea3(185, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41}, {10, 12, 8, 14, 10, 12, 16, 6, 8, 14, 8, 14}), // Altering Cave
        EncounterArea3(186, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Monean Chamber
        EncounterArea3(187, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Liptoo Chamber
        EncounterArea3(188, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Weepth Chamber
        EncounterArea3(189, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Dilford Chamber
        EncounterArea3(190, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Scufib Chamber
        EncounterArea3(191, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Rixy Chamber
        EncounterArea3(192, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Viapois Chamber
        EncounterArea3(134, 0, Encounter::RockSmash, {74, 74, 74, 75, 75}, {5, 10, 15, 25, 30}, {20, 20, 30, 40, 40}), // Rock Tunnel B1F
        EncounterArea3(145, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {30, 40, 45, 40, 40}, {40, 50, 55, 50, 50}), // Cerulean Cave 1F
        EncounterArea3(146, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {35, 45, 50, 45, 45}, {45, 55, 60, 55, 55}), // Cerulean Cave 2F
        EncounterArea3(147, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {40, 50, 55, 50, 50}, {50, 60, 65, 60, 60}), // Cerulean Cave B1F
        EncounterArea3(152, 0, Encounter::RockSmash, {74, 74, 74, 75, 75}, {5, 10, 15, 25, 30}, {20, 20, 30, 40, 40}), // Kindle Road
        EncounterArea3(167, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Sevault Canyon
        EncounterArea3(169, 0, Encounter::RockSmash, {74, 74, 74, 75, 75}, {5, 10, 15, 25, 30}, {20, 20, 30, 40, 40}), // Mt. Ember
        EncounterArea3(171, 0, Encounter::RockSmash, {74, 74, 74, 75, 75}, {5, 10, 15, 25, 30}, {20, 20, 30, 40, 40}), // Mt. Ember Room 2
        EncounterArea3(173, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember 1F
        EncounterArea3(174, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember B1F
        EncounterArea3(175, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember B2F
        EncounterArea3(176, 0, Encounter::RockSmash, {218, 218, 219, 219, 219}, {15, 25, 40, 35, 25}, {25, 35, 45, 45, 35}), // Mt. Ember B3F
        EncounterArea3(177, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember B4F
        EncounterArea3(178, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember B5F
        EncounterArea3(86, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Pallet Town
        EncounterArea3(87, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Viridian City
        EncounterArea3(88, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Cerulean City
        EncounterArea3(89, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Vermilion City
        EncounterArea3(90, 0, Encounter::Surfing, {54, 54, 54, 54, 109}, {5, 10, 20, 30, 30}, {10, 20, 30, 40, 40}), // Celadon City
        EncounterArea3(91, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Fuchsia City
        EncounterArea3(92, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Cinnabar Island
        EncounterArea3(96, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 4
        EncounterArea3(98, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Route 6
        EncounterArea3(102, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 10
        EncounterArea3(103, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 11
        EncounterArea3(104, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 12
        EncounterArea3(105, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 13
        EncounterArea3(111, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 19
        EncounterArea3(112, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 20
        EncounterArea3(113, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 21
        EncounterArea3(114, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Route 22
        EncounterArea3(115, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Route 23
        EncounterArea3(116, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 24
        EncounterArea3(117, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Route 25
        EncounterArea3(122, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // S.S. Anne
        EncounterArea3(129, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::Surfing, {54, 54, 54, 54, 54}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Safari Zone Area 3
        EncounterArea3(138, 0, Encounter::Surfing, {86, 116, 87, 54, 55}, {25, 25, 35, 30, 35}, {35, 30, 40, 40, 40}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::Surfing, {86, 116, 87, 54, 55}, {25, 25, 35, 30, 35}, {35, 30, 40, 40, 40}), // Seafoam Islands B4F
        EncounterArea3(145, 0, Encounter::Surfing, {54, 55, 55, 54, 54}, {30, 40, 45, 40, 40}, {40, 50, 55, 50, 50}), // Cerulean Cave 1F
        EncounterArea3(147, 0, Encounter::Surfing, {54, 55, 55, 54, 54}, {40, 50, 55, 50, 50}, {50, 60, 65, 60, 60}), // Cerulean Cave B1F
        EncounterArea3(149, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // One Island
        EncounterArea3(150, 0, Encounter::Surfing, {194, 54, 194, 194, 194}, {5, 5, 15, 15, 15}, {15, 35, 25, 25, 25}), // Four Island
        EncounterArea3(151, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Five Island
        EncounterArea3(152, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Kindle Road
        EncounterArea3(153, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::Surfing, {54, 54, 54, 55, 55}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Cape Brink
        EncounterArea3(155, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Bond Bridge
        EncounterArea3(157, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Resort Gorgeous
        EncounterArea3(158, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {20, 15, 40, 40, 40}), // Water Labyrinth
        EncounterArea3(159, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Memorial Pillar
        EncounterArea3(161, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Outcast Island
        EncounterArea3(162, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Green Path
        EncounterArea3(163, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Water Path
        EncounterArea3(164, 0, Encounter::Surfing, {194, 194, 194, 194, 194}, {5, 10, 15, 20, 20}, {20, 20, 25, 25, 25}), // Ruin Valley
        EncounterArea3(165, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Trainer Tower (exterior)
        EncounterArea3(168, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Tanoby Ruins
        EncounterArea3(179, 0, Encounter::Surfing, {54, 54, 54, 55, 55}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Berry Forest
        EncounterArea3(180, 0, Encounter::Surfing, {86, 54, 87, 194, 194}, {5, 5, 35, 5, 5}, {35, 35, 40, 15, 15}), // Icefall Cave
        EncounterArea3(183, 0, Encounter::Surfing, {72, 72, 72, 73, 131}, {5, 20, 35, 35, 30}, {20, 35, 45, 45, 45}), // Icefall Cave Back
        EncounterArea3(86, 0, Encounter::OldRod, {129, 129}, {5, 5}, {10, 10}), // Pallet Town
        EncounterArea3(87, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Viridian City
        EncounterArea3(88, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cerulean City
        EncounterArea3(89, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Vermilion City
        EncounterArea3(90, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Celadon City
        EncounterArea3(91, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Fuchsia City
        EncounterArea3(92, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cinnabar Island
        EncounterArea3(96, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 4
        EncounterArea3(98, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 6
        EncounterArea3(102, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 10
        EncounterArea3(103, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 11
        EncounterArea3(104, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 12
        EncounterArea3(105, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 13
        EncounterArea3(111, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 19
        EncounterArea3(112, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 20
        EncounterArea3(113, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 21
        EncounterArea3(114, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 22
        EncounterArea3(115, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 23
        EncounterArea3(116, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 24
        EncounterArea3(117, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 25
        EncounterArea3(122, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // S.S. Anne
        EncounterArea3(129, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Safari Zone Area 3
        EncounterArea3(138, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Seafoam Islands B4F
        EncounterArea3(145, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cerulean Cave 1F
        EncounterArea3(147, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cerulean Cave B1F
        EncounterArea3(149, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // One Island
        EncounterArea3(150, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Four Island
        EncounterArea3(151, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Five Island
        EncounterArea3(152, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Kindle Road
        EncounterArea3(153, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cape Brink
        EncounterArea3(155, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Bond Bridge
        EncounterArea3(157, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Resort Gorgeous
        EncounterArea3(158, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Water Labyrinth
        EncounterArea3(159, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Memorial Pillar
        EncounterArea3(161, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Outcast Island
        EncounterArea3(162, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Green Path
        EncounterArea3(163, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Water Path
        EncounterArea3(164, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Ruin Valley
        EncounterArea3(165, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Trainer Tower (exterior)
        EncounterArea3(168, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Tanoby Ruins
        EncounterArea3(179, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Berry Forest
        EncounterArea3(180, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Icefall Cave
        EncounterArea3(183, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Icefall Cave Back
        EncounterArea3(86, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Pallet Town
        EncounterArea3(87, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Viridian City
        EncounterArea3(88, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Cerulean City
        EncounterArea3(89, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Vermilion City
        EncounterArea3(90, 0, Encounter::GoodRod, {129, 129, 129}, {5, 5, 5}, {15, 15, 15}), // Celadon City
        EncounterArea3(91, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Fuchsia City
        EncounterArea3(92, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Cinnabar Island
        EncounterArea3(96, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 4
        EncounterArea3(98, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Route 6
        EncounterArea3(102, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 10
        EncounterArea3(103, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 11
        EncounterArea3(104, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 12
        EncounterArea3(105, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 13
        EncounterArea3(111, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 19
        EncounterArea3(112, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 20
        EncounterArea3(113, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 21
        EncounterArea3(114, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Route 22
        EncounterArea3(115, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Route 23
        EncounterArea3(116, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Route 24
        EncounterArea3(117, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Route 25
        EncounterArea3(122, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // S.S. Anne
        EncounterArea3(129, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Safari Zone Area 3
        EncounterArea3(138, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::GoodRod, {116, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Seafoam Islands B4F
        EncounterArea3(145, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Cerulean Cave 1F
        EncounterArea3(147, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Cerulean Cave B1F
        EncounterArea3(149, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // One Island
        EncounterArea3(150, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Four Island
        EncounterArea3(151, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Five Island
        EncounterArea3(152, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Kindle Road
        EncounterArea3(153, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Cape Brink
        EncounterArea3(155, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Bond Bridge
        EncounterArea3(157, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Resort Gorgeous
        EncounterArea3(158, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Water Labyrinth
        EncounterArea3(159, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Memorial Pillar
        EncounterArea3(161, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Outcast Island
        EncounterArea3(162, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Green Path
        EncounterArea3(163, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Water Path
        EncounterArea3(164, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Ruin Valley
        EncounterArea3(165, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Trainer Tower (exterior)
        EncounterArea3(168, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Tanoby Ruins
        EncounterArea3(179, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Berry Forest
        EncounterArea3(180, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Icefall Cave
        EncounterArea3(183, 0, Encounter::GoodRod, {116, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Icefall Cave Back
        EncounterArea3(86, 0, Encounter::SuperRod, {116, 90, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Pallet Town
        EncounterArea3(87, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Viridian City
        EncounterArea3(88, 0, Encounter::SuperRod, {116, 116, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Cerulean City
        EncounterArea3(89, 0, Encounter::SuperRod, {116, 90, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Vermilion City
        EncounterArea3(90, 0, Encounter::SuperRod, {129, 129, 129, 129, 88}, {15, 15, 15, 25, 30}, {25, 25, 25, 35, 40}), // Celadon City
        EncounterArea3(91, 0, Encounter::SuperRod, {118, 119, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Fuchsia City
        EncounterArea3(92, 0, Encounter::SuperRod, {116, 90, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Cinnabar Island
        EncounterArea3(96, 0, Encounter::SuperRod, {116, 116, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 4
        EncounterArea3(98, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Route 6
        EncounterArea3(102, 0, Encounter::SuperRod, {116, 116, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 10
        EncounterArea3(103, 0, Encounter::SuperRod, {116, 116, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 11
        EncounterArea3(104, 0, Encounter::SuperRod, {116, 116, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 12
        EncounterArea3(105, 0, Encounter::SuperRod, {116, 116, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 13
        EncounterArea3(111, 0, Encounter::SuperRod, {116, 116, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 19
        EncounterArea3(112, 0, Encounter::SuperRod, {116, 116, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 20
        EncounterArea3(113, 0, Encounter::SuperRod, {116, 116, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 21
        EncounterArea3(114, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Route 22
        EncounterArea3(115, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Route 23
        EncounterArea3(116, 0, Encounter::SuperRod, {116, 116, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 24
        EncounterArea3(117, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Route 25
        EncounterArea3(122, 0, Encounter::SuperRod, {116, 90, 130, 116, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // S.S. Anne
        EncounterArea3(129, 0, Encounter::SuperRod, {118, 119, 147, 54, 148}, {15, 20, 15, 15, 25}, {25, 30, 25, 35, 35}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::SuperRod, {118, 119, 147, 54, 148}, {15, 20, 15, 15, 25}, {25, 30, 25, 35, 35}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::SuperRod, {118, 119, 147, 54, 148}, {15, 20, 15, 15, 25}, {25, 30, 25, 35, 35}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::SuperRod, {118, 119, 147, 54, 148}, {15, 20, 15, 15, 25}, {25, 30, 25, 35, 35}), // Safari Zone Area 3
        EncounterArea3(138, 0, Encounter::SuperRod, {116, 116, 130, 54, 130}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::SuperRod, {116, 116, 130, 54, 130}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Seafoam Islands B4F
        EncounterArea3(145, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Cerulean Cave 1F
        EncounterArea3(147, 0, Encounter::SuperRod, {60, 61, 130, 54, 130}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Cerulean Cave B1F
        EncounterArea3(149, 0, Encounter::SuperRod, {116, 90, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // One Island
        EncounterArea3(150, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Four Island
        EncounterArea3(151, 0, Encounter::SuperRod, {116, 90, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Five Island
        EncounterArea3(152, 0, Encounter::SuperRod, {116, 116, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Kindle Road
        EncounterArea3(153, 0, Encounter::SuperRod, {116, 116, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Cape Brink
        EncounterArea3(155, 0, Encounter::SuperRod, {116, 116, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Bond Bridge
        EncounterArea3(157, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Resort Gorgeous
        EncounterArea3(158, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Water Labyrinth
        EncounterArea3(159, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Memorial Pillar
        EncounterArea3(161, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Outcast Island
        EncounterArea3(162, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Green Path
        EncounterArea3(163, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Water Path
        EncounterArea3(164, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Ruin Valley
        EncounterArea3(165, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Trainer Tower (exterior)
        EncounterArea3(168, 0, Encounter::SuperRod, {116, 211, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Tanoby Ruins
        EncounterArea3(179, 0, Encounter::SuperRod, {118, 119, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Berry Forest
        EncounterArea3(180, 0, Encounter::SuperRod, {60, 61, 130, 54, 54}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Icefall Cave
        EncounterArea3(183, 0, Encounter::SuperRod, {116, 90, 130, 117, 54}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Icefall Cave Back
    };

    const QVector<EncounterArea3> encountersLeafGreen =
    {
        EncounterArea3(93, 0, Encounter::Grass, {16, 19, 16, 19, 16, 19, 16, 19, 16, 19, 16, 19}, {3, 3, 3, 3, 2, 2, 3, 3, 4, 4, 5, 4}), // Route 1
        EncounterArea3(94, 0, Encounter::Grass, {19, 16, 19, 16, 19, 16, 19, 16, 10, 13, 10, 13}, {3, 3, 4, 4, 2, 2, 5, 5, 4, 4, 5, 5}), // Route 2
        EncounterArea3(95, 0, Encounter::Grass, {21, 16, 21, 56, 29, 16, 21, 39, 29, 39, 32, 39}, {6, 6, 7, 7, 6, 7, 8, 3, 7, 5, 6, 7}), // Route 3
        EncounterArea3(96, 0, Encounter::Grass, {21, 19, 27, 27, 21, 19, 21, 19, 56, 27, 56, 27}, {10, 10, 6, 10, 8, 8, 12, 12, 10, 8, 12, 12}), // Route 4
        EncounterArea3(97, 0, Encounter::Grass, {52, 16, 69, 52, 69, 16, 69, 16, 16, 52, 16, 52}, {10, 13, 13, 12, 15, 15, 16, 16, 15, 14, 15, 16}), // Route 5
        EncounterArea3(98, 0, Encounter::Grass, {52, 16, 69, 52, 69, 16, 69, 16, 16, 52, 16, 52}, {10, 13, 13, 12, 15, 15, 16, 16, 15, 14, 15, 16}), // Route 6
        EncounterArea3(99, 0, Encounter::Grass, {16, 52, 69, 52, 16, 69, 37, 37, 52, 52, 52, 52}, {19, 17, 19, 18, 22, 22, 18, 20, 17, 19, 17, 20}), // Route 7
        EncounterArea3(100, 0, Encounter::Grass, {16, 52, 37, 16, 52, 27, 37, 27, 27, 37, 27, 37}, {18, 18, 16, 20, 20, 17, 17, 19, 17, 15, 17, 18}), // Route 8
        EncounterArea3(101, 0, Encounter::Grass, {21, 19, 27, 27, 21, 19, 21, 19, 19, 27, 19, 27}, {16, 16, 11, 15, 13, 14, 17, 17, 14, 13, 14, 17}), // Route 9
        EncounterArea3(102, 0, Encounter::Grass, {21, 100, 27, 27, 21, 100, 21, 100, 100, 27, 100, 27}, {16, 16, 11, 15, 13, 14, 17, 17, 14, 13, 14, 17}), // Route 10
        EncounterArea3(103, 0, Encounter::Grass, {27, 21, 27, 21, 96, 96, 27, 21, 27, 96, 27, 96}, {14, 15, 12, 13, 11, 13, 15, 17, 12, 15, 12, 15}), // Route 11
        EncounterArea3(104, 0, Encounter::Grass, {69, 48, 69, 16, 16, 48, 69, 16, 16, 70, 16, 70}, {24, 24, 22, 23, 25, 26, 26, 27, 23, 28, 23, 30}), // Route 12
        EncounterArea3(105, 0, Encounter::Grass, {69, 48, 69, 16, 16, 48, 69, 132, 17, 70, 17, 70}, {24, 24, 22, 27, 25, 26, 26, 25, 29, 28, 29, 30}), // Route 13
        EncounterArea3(106, 0, Encounter::Grass, {69, 48, 69, 132, 16, 48, 69, 70, 132, 17, 132, 17}, {24, 24, 22, 23, 27, 26, 26, 30, 23, 29, 23, 29}), // Route 14
        EncounterArea3(107, 0, Encounter::Grass, {69, 48, 69, 16, 16, 48, 69, 132, 17, 70, 17, 70}, {24, 24, 22, 27, 25, 26, 26, 25, 29, 28, 29, 30}), // Route 15
        EncounterArea3(108, 0, Encounter::Grass, {21, 84, 19, 19, 21, 84, 19, 84, 19, 20, 19, 20}, {20, 18, 18, 20, 22, 20, 22, 22, 18, 23, 18, 25}), // Route 16
        EncounterArea3(109, 0, Encounter::Grass, {21, 84, 21, 84, 20, 20, 84, 20, 19, 22, 19, 22}, {20, 24, 22, 26, 25, 27, 28, 29, 22, 25, 22, 27}), // Route 17
        EncounterArea3(110, 0, Encounter::Grass, {21, 84, 21, 84, 20, 22, 84, 20, 19, 22, 19, 22}, {20, 24, 22, 26, 25, 25, 28, 29, 22, 27, 22, 29}), // Route 18
        EncounterArea3(113, 0, Encounter::Grass, {114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114}, {22, 23, 24, 21, 25, 20, 19, 26, 18, 27, 17, 28}), // Route 21
        EncounterArea3(114, 0, Encounter::Grass, {19, 56, 19, 56, 19, 56, 21, 21, 19, 56, 19, 56}, {3, 3, 4, 4, 2, 2, 3, 5, 5, 5, 5, 5}), // Route 22
        EncounterArea3(115, 0, Encounter::Grass, {56, 22, 56, 21, 27, 27, 57, 28, 21, 22, 21, 22}, {32, 40, 34, 34, 32, 34, 42, 44, 32, 42, 32, 44}), // Route 23
        EncounterArea3(116, 0, Encounter::Grass, {13, 10, 16, 69, 69, 63, 16, 69, 11, 63, 14, 63}, {7, 7, 11, 12, 13, 10, 13, 14, 8, 8, 8, 12}), // Route 24
        EncounterArea3(117, 0, Encounter::Grass, {13, 10, 16, 69, 69, 63, 16, 69, 11, 63, 14, 63}, {8, 8, 13, 14, 13, 11, 11, 12, 9, 9, 9, 13}), // Route 25
        EncounterArea3(118, 0, Encounter::Grass, {10, 13, 10, 13, 10, 13, 14, 11, 11, 25, 11, 25}, {4, 4, 5, 5, 3, 3, 5, 5, 4, 3, 6, 5}), // Viridian Forest
        EncounterArea3(119, 0, Encounter::Grass, {41, 41, 74, 41, 41, 74, 74, 46, 41, 41, 41, 35}, {7, 8, 7, 9, 10, 8, 9, 8, 7, 7, 7, 8}), // Mt. Moon 1F
        EncounterArea3(120, 0, Encounter::Grass, {46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46}, {7, 8, 5, 6, 9, 10, 7, 8, 5, 6, 9, 10}), // Mt. Moon B1F
        EncounterArea3(121, 0, Encounter::Grass, {41, 74, 41, 41, 74, 46, 46, 35, 41, 41, 41, 35}, {8, 9, 9, 10, 10, 10, 12, 10, 11, 11, 11, 12}), // Mt. Moon B2F
        EncounterArea3(123, 0, Encounter::Grass, {50, 50, 50, 50, 50, 50, 50, 50, 50, 51, 50, 51}, {18, 19, 17, 15, 16, 20, 21, 22, 17, 29, 17, 31}), // Diglett's Cave
        EncounterArea3(124, 0, Encounter::Grass, {66, 74, 95, 95, 95, 41, 28, 42, 105, 67, 67, 105}, {32, 32, 40, 43, 46, 32, 44, 44, 44, 44, 46, 46}), // Victory Road 1F
        EncounterArea3(125, 0, Encounter::Grass, {66, 74, 57, 95, 95, 41, 28, 42, 105, 67, 67, 105}, {34, 34, 42, 45, 48, 34, 46, 46, 46, 46, 48, 48}), // Victory Road 2F
        EncounterArea3(126, 0, Encounter::Grass, {66, 74, 95, 95, 95, 41, 28, 42, 105, 67, 67, 105}, {32, 32, 40, 43, 46, 32, 44, 44, 44, 44, 46, 46}), // Victory Road 3F
        EncounterArea3(127, 0, Encounter::Grass, {88, 20, 88, 20, 37, 19, 109, 89, 37, 19, 37, 19}, {28, 32, 30, 36, 30, 28, 28, 32, 32, 26, 32, 26}), // PokÃ©mon Mansion 1F-3F
        EncounterArea3(128, 0, Encounter::Grass, {88, 20, 88, 132, 37, 20, 109, 89, 37, 19, 37, 19}, {28, 34, 30, 30, 30, 38, 28, 34, 32, 26, 32, 26}), // PokÃ©mon Mansion B1F
        EncounterArea3(129, 0, Encounter::SafariZone, {111, 29, 102, 102, 48, 30, 33, 47, 48, 127, 48, 113}, {25, 22, 24, 25, 22, 31, 31, 30, 22, 23, 22, 23}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::SafariZone, {29, 84, 102, 102, 46, 30, 32, 47, 46, 115, 46, 127}, {24, 26, 23, 25, 22, 33, 24, 25, 22, 25, 22, 28}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::SafariZone, {111, 29, 102, 102, 46, 30, 33, 49, 46, 113, 46, 128}, {26, 30, 25, 27, 23, 30, 30, 32, 23, 26, 23, 28}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::SafariZone, {84, 29, 102, 102, 48, 30, 32, 49, 48, 128, 48, 115}, {26, 22, 25, 27, 23, 30, 30, 32, 23, 25, 23, 28}), // Safari Zone Area 3
        EncounterArea3(133, 0, Encounter::Grass, {41, 74, 56, 74, 41, 66, 56, 66, 74, 95, 74, 95}, {15, 16, 16, 17, 16, 16, 17, 17, 15, 13, 15, 15}), // Rock Tunnel 1F
        EncounterArea3(134, 0, Encounter::Grass, {41, 74, 56, 74, 41, 66, 56, 95, 74, 95, 74, 95}, {16, 17, 17, 16, 15, 17, 16, 13, 15, 15, 15, 17}), // Rock Tunnel B1F
        EncounterArea3(135, 0, Encounter::Grass, {79, 79, 79, 41, 41, 41, 42, 42, 79, 41, 79, 42}, {27, 29, 31, 22, 22, 24, 26, 28, 33, 26, 26, 30}), // Seafoam Islands 1F
        EncounterArea3(136, 0, Encounter::Grass, {79, 79, 86, 41, 41, 41, 42, 42, 80, 41, 80, 42}, {29, 31, 28, 22, 22, 24, 26, 28, 33, 26, 35, 30}), // Seafoam Islands B1F
        EncounterArea3(137, 0, Encounter::Grass, {79, 79, 86, 86, 41, 41, 42, 80, 80, 42, 80, 42}, {30, 32, 30, 32, 22, 24, 26, 34, 32, 28, 32, 30}), // Seafoam Islands B2F
        EncounterArea3(138, 0, Encounter::Grass, {86, 86, 79, 79, 80, 41, 42, 80, 87, 42, 87, 42}, {30, 32, 32, 30, 32, 24, 26, 34, 32, 28, 34, 30}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::Grass, {86, 86, 79, 86, 80, 42, 87, 80, 87, 42, 87, 42}, {30, 32, 32, 34, 32, 26, 34, 34, 36, 28, 36, 30}), // Seafoam Islands B4F
        EncounterArea3(140, 0, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 104, 92, 104, 92, 93}, {15, 16, 17, 13, 14, 18, 19, 15, 17, 17, 17, 20}), // PokÃ©mon Tower 3F
        EncounterArea3(141, 0, Encounter::Grass, {92, 92, 92, 92, 92, 92, 93, 104, 92, 104, 92, 92}, {15, 16, 17, 13, 14, 18, 20, 15, 17, 17, 17, 19}), // PokÃ©mon Tower 4F
        EncounterArea3(142, 0, Encounter::Grass, {92, 92, 92, 92, 92, 92, 93, 104, 92, 104, 92, 92}, {15, 16, 17, 13, 14, 18, 20, 15, 17, 17, 17, 19}), // PokÃ©mon Tower 5F
        EncounterArea3(143, 0, Encounter::Grass, {92, 92, 92, 92, 92, 92, 93, 104, 92, 104, 92, 93}, {16, 17, 18, 14, 15, 19, 21, 17, 18, 19, 18, 23}), // PokÃ©mon Tower 6F
        EncounterArea3(144, 0, Encounter::Grass, {92, 92, 92, 92, 92, 93, 104, 104, 92, 93, 92, 93}, {16, 17, 18, 15, 19, 23, 17, 19, 18, 23, 18, 25}), // PokÃ©mon Tower 7F
        EncounterArea3(145, 0, Encounter::Grass, {82, 47, 42, 67, 57, 132, 101, 47, 42, 202, 57, 132}, {49, 49, 46, 46, 52, 52, 58, 58, 55, 55, 61, 61}), // Cerulean Cave 1F
        EncounterArea3(146, 0, Encounter::Grass, {42, 67, 82, 47, 64, 132, 42, 202, 101, 47, 64, 132}, {49, 49, 52, 52, 55, 55, 58, 58, 61, 61, 64, 64}), // Cerulean Cave 2F
        EncounterArea3(147, 0, Encounter::Grass, {64, 132, 82, 47, 42, 67, 64, 132, 101, 47, 42, 202}, {58, 58, 55, 55, 52, 52, 67, 67, 64, 64, 61, 61}), // Cerulean Cave B1F
        EncounterArea3(148, 0, Encounter::Grass, {100, 81, 100, 81, 25, 25, 82, 82, 25, 82, 25, 82}, {22, 22, 25, 25, 22, 24, 31, 34, 26, 31, 26, 34}), // Power Plant
        EncounterArea3(152, 0, Encounter::Grass, {21, 77, 22, 77, 74, 52, 21, 79, 78, 53, 78, 53}, {32, 34, 36, 31, 31, 31, 30, 34, 37, 37, 40, 40}), // Kindle Road
        EncounterArea3(153, 0, Encounter::Grass, {21, 114, 21, 114, 22, 52, 22, 79, 22, 53, 22, 53}, {32, 33, 31, 35, 36, 31, 38, 31, 40, 37, 40, 40}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::Grass, {21, 69, 69, 70, 22, 52, 70, 79, 80, 53, 80, 53}, {31, 30, 32, 36, 36, 31, 38, 31, 37, 37, 40, 40}), // Cape Brink
        EncounterArea3(155, 0, Encounter::Grass, {16, 69, 16, 70, 17, 52, 48, 79, 17, 53, 17, 53}, {32, 31, 29, 36, 34, 31, 34, 31, 37, 37, 40, 40}), // Bond Bridge
        EncounterArea3(156, 0, Encounter::Grass, {206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206}, {15, 15, 10, 10, 20, 20, 25, 30, 25, 30, 5, 35}), // Three Isle Port
        EncounterArea3(159, 0, Encounter::Grass, {16, 161, 17, 187, 161, 52, 187, 79, 17, 53, 17, 53}, {44, 10, 48, 10, 15, 41, 15, 41, 50, 47, 50, 50}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::Grass, {187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187}, {10, 12, 8, 14, 10, 12, 16, 6, 8, 14, 8, 14}), // Memorial Pillar
        EncounterArea3(163, 0, Encounter::Grass, {21, 161, 69, 22, 161, 52, 70, 79, 22, 53, 22, 53}, {44, 10, 44, 48, 15, 41, 48, 41, 50, 47, 50, 50}), // Water Path
        EncounterArea3(164, 0, Encounter::Grass, {177, 21, 193, 183, 22, 52, 202, 79, 177, 53, 177, 53}, {15, 44, 18, 15, 49, 43, 25, 41, 20, 49, 20, 52}), // Ruin Valley
        EncounterArea3(166, 0, Encounter::Grass, {21, 161, 231, 22, 161, 52, 22, 79, 231, 53, 231, 53}, {44, 10, 10, 48, 15, 41, 50, 41, 15, 47, 15, 50}), // Canyon Entrance
        EncounterArea3(167, 0, Encounter::Grass, {74, 231, 104, 22, 105, 52, 95, 22, 246, 53, 246, 53}, {46, 15, 46, 50, 52, 43, 54, 50, 15, 49, 20, 52}), // Sevault Canyon
        EncounterArea3(169, 0, Encounter::Grass, {77, 22, 77, 21, 66, 74, 77, 22, 126, 78, 126, 78}, {30, 38, 33, 32, 35, 33, 36, 40, 38, 39, 40, 42}), // Mt. Ember
        EncounterArea3(170, 0, Encounter::Grass, {74, 66, 74, 74, 66, 66, 74, 66, 74, 66, 74, 66}, {33, 35, 29, 31, 31, 33, 35, 37, 37, 39, 37, 39}), // Mt. Ember Room 1
        EncounterArea3(171, 0, Encounter::Grass, {74, 66, 74, 74, 66, 66, 67, 67, 67, 67, 67, 67}, {34, 36, 30, 32, 32, 34, 38, 38, 40, 40, 40, 40}), // Mt. Ember Room 2
        EncounterArea3(172, 0, Encounter::Grass, {74, 66, 74, 74, 66, 66, 74, 66, 74, 66, 74, 66}, {33, 35, 29, 31, 31, 33, 35, 37, 37, 39, 37, 39}), // Mt. Ember Room 3
        EncounterArea3(173, 0, Encounter::Grass, {74, 66, 74, 74, 66, 66, 74, 67, 74, 67, 74, 67}, {36, 38, 32, 34, 34, 36, 38, 40, 40, 42, 40, 42}), // Mt. Ember 1F
        EncounterArea3(174, 0, Encounter::Grass, {74, 74, 74, 74, 218, 218, 74, 218, 74, 218, 74, 218}, {38, 36, 34, 40, 24, 26, 42, 28, 42, 30, 42, 30}), // Mt. Ember B1F
        EncounterArea3(175, 0, Encounter::Grass, {74, 218, 74, 218, 218, 218, 74, 218, 74, 218, 74, 218}, {40, 26, 42, 24, 28, 30, 44, 32, 44, 22, 44, 22}), // Mt. Ember B2F
        EncounterArea3(176, 0, Encounter::Grass, {218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218}, {26, 28, 30, 32, 24, 22, 20, 34, 36, 18, 36, 18}), // Mt. Ember B3F
        EncounterArea3(177, 0, Encounter::Grass, {74, 218, 74, 218, 218, 218, 74, 218, 74, 218, 74, 218}, {40, 26, 42, 24, 28, 30, 44, 32, 44, 22, 44, 22}), // Mt. Ember B4F
        EncounterArea3(178, 0, Encounter::Grass, {74, 74, 74, 74, 218, 218, 74, 218, 74, 218, 74, 218}, {38, 36, 34, 40, 24, 26, 42, 28, 42, 30, 42, 30}), // Mt. Ember B5F
        EncounterArea3(179, 0, Encounter::Grass, {17, 70, 16, 69, 48, 96, 102, 79, 49, 97, 49, 97}, {37, 35, 32, 30, 34, 34, 35, 31, 37, 37, 40, 40}), // Berry Forest
        EncounterArea3(180, 0, Encounter::Grass, {86, 42, 86, 86, 41, 87, 87, 79, 42, 87, 42, 87}, {43, 45, 45, 47, 40, 49, 51, 41, 48, 53, 48, 53}), // Icefall Cave
        EncounterArea3(181, 0, Encounter::Grass, {220, 42, 86, 220, 41, 220, 215, 220, 42, 220, 42, 220}, {25, 45, 45, 27, 40, 29, 30, 31, 48, 23, 48, 23}), // Icefall Cave 1F
        EncounterArea3(182, 0, Encounter::Grass, {220, 42, 86, 220, 41, 220, 215, 220, 42, 220, 42, 220}, {25, 45, 45, 27, 40, 29, 30, 31, 48, 23, 48, 23}), // Icefall Cave B1F
        EncounterArea3(183, 0, Encounter::Grass, {86, 42, 86, 86, 41, 87, 87, 79, 42, 87, 42, 87}, {43, 45, 45, 47, 40, 49, 51, 41, 48, 53, 48, 53}), // Icefall Cave Back
        EncounterArea3(184, 0, Encounter::Grass, {165, 14, 165, 10, 13, 214, 11, 214, 167, 214, 167, 214}, {9, 9, 14, 6, 6, 15, 9, 20, 9, 25, 14, 30}), // Pattern Bush
        EncounterArea3(185, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41}, {10, 12, 8, 14, 10, 12, 16, 6, 8, 14, 8, 14}), // Altering Cave
        EncounterArea3(186, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Monean Chamber
        EncounterArea3(187, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Liptoo Chamber
        EncounterArea3(188, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Weepth Chamber
        EncounterArea3(189, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Dilford Chamber
        EncounterArea3(190, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Scufib Chamber
        EncounterArea3(191, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Rixy Chamber
        EncounterArea3(192, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}), // Viapois Chamber
        EncounterArea3(134, 0, Encounter::RockSmash, {74, 74, 74, 75, 75}, {5, 10, 15, 25, 30}, {20, 20, 30, 40, 40}), // Rock Tunnel B1F
        EncounterArea3(145, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {30, 40, 45, 40, 40}, {40, 50, 55, 50, 50}), // Cerulean Cave 1F
        EncounterArea3(146, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {35, 45, 50, 45, 45}, {45, 55, 60, 55, 55}), // Cerulean Cave 2F
        EncounterArea3(147, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {40, 50, 55, 50, 50}, {50, 60, 65, 60, 60}), // Cerulean Cave B1F
        EncounterArea3(152, 0, Encounter::RockSmash, {74, 74, 74, 75, 75}, {5, 10, 15, 25, 30}, {20, 20, 30, 40, 40}), // Kindle Road
        EncounterArea3(167, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Sevault Canyon
        EncounterArea3(169, 0, Encounter::RockSmash, {74, 74, 74, 75, 75}, {5, 10, 15, 25, 30}, {20, 20, 30, 40, 40}), // Mt. Ember
        EncounterArea3(171, 0, Encounter::RockSmash, {74, 74, 74, 75, 75}, {5, 10, 15, 25, 30}, {20, 20, 30, 40, 40}), // Mt. Ember Room 2
        EncounterArea3(173, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember 1F
        EncounterArea3(174, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember B1F
        EncounterArea3(175, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember B2F
        EncounterArea3(176, 0, Encounter::RockSmash, {218, 218, 219, 219, 219}, {15, 25, 40, 35, 25}, {25, 35, 45, 45, 35}), // Mt. Ember B3F
        EncounterArea3(177, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember B4F
        EncounterArea3(178, 0, Encounter::RockSmash, {74, 75, 75, 74, 74}, {25, 30, 35, 30, 30}, {35, 45, 50, 40, 40}), // Mt. Ember B5F
        EncounterArea3(86, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Pallet Town
        EncounterArea3(87, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Viridian City
        EncounterArea3(88, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Cerulean City
        EncounterArea3(89, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Vermilion City
        EncounterArea3(90, 0, Encounter::Surfing, {79, 79, 79, 79, 109}, {5, 10, 20, 30, 30}, {10, 20, 30, 40, 40}), // Celadon City
        EncounterArea3(91, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Fuchsia City
        EncounterArea3(92, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Cinnabar Island
        EncounterArea3(96, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 4
        EncounterArea3(98, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Route 6
        EncounterArea3(102, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 10
        EncounterArea3(103, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 11
        EncounterArea3(104, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 12
        EncounterArea3(105, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 13
        EncounterArea3(111, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 19
        EncounterArea3(112, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 20
        EncounterArea3(113, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 21
        EncounterArea3(114, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Route 22
        EncounterArea3(115, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Route 23
        EncounterArea3(116, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // Route 24
        EncounterArea3(117, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Route 25
        EncounterArea3(122, 0, Encounter::Surfing, {72, 72, 72, 72, 72}, {5, 10, 20, 30, 35}, {10, 20, 30, 35, 40}), // S.S. Anne
        EncounterArea3(129, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {20, 20, 25, 30, 35}, {25, 25, 30, 35, 40}), // Safari Zone Area 3
        EncounterArea3(138, 0, Encounter::Surfing, {86, 98, 87, 79, 80}, {25, 25, 35, 30, 35}, {35, 30, 40, 40, 40}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::Surfing, {86, 98, 87, 79, 80}, {25, 25, 35, 30, 35}, {35, 30, 40, 40, 40}), // Seafoam Islands B4F
        EncounterArea3(145, 0, Encounter::Surfing, {79, 80, 80, 79, 79}, {30, 40, 45, 40, 40}, {40, 50, 55, 50, 50}), // Cerulean Cave 1F
        EncounterArea3(147, 0, Encounter::Surfing, {79, 80, 80, 79, 79}, {40, 50, 55, 50, 50}, {50, 60, 65, 60, 60}), // Cerulean Cave B1F
        EncounterArea3(149, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // One Island
        EncounterArea3(150, 0, Encounter::Surfing, {183, 79, 183, 183, 183}, {5, 5, 15, 15, 15}, {15, 35, 25, 25, 25}), // Four Island
        EncounterArea3(151, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Five Island
        EncounterArea3(152, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Kindle Road
        EncounterArea3(153, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::Surfing, {79, 79, 79, 80, 80}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Cape Brink
        EncounterArea3(155, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Bond Bridge
        EncounterArea3(157, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Resort Gorgeous
        EncounterArea3(158, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Water Labyrinth
        EncounterArea3(159, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::Surfing, {72, 187, 72, 73, 73}, {5, 5, 35, 35, 35}, {35, 15, 40, 40, 40}), // Memorial Pillar
        EncounterArea3(161, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Outcast Island
        EncounterArea3(162, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Green Path
        EncounterArea3(163, 0, Encounter::Surfing, {72, 72, 72, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Water Path
        EncounterArea3(164, 0, Encounter::Surfing, {183, 183, 183, 183, 183}, {5, 10, 15, 20, 20}, {20, 20, 25, 25, 25}), // Ruin Valley
        EncounterArea3(165, 0, Encounter::Surfing, {72, 72, 226, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Trainer Tower (exterior)
        EncounterArea3(168, 0, Encounter::Surfing, {72, 72, 226, 73, 73}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Tanoby Ruins
        EncounterArea3(179, 0, Encounter::Surfing, {79, 79, 79, 80, 80}, {5, 20, 35, 35, 35}, {20, 35, 40, 40, 40}), // Berry Forest
        EncounterArea3(180, 0, Encounter::Surfing, {86, 79, 87, 183, 183}, {5, 5, 35, 5, 5}, {35, 35, 40, 15, 15}), // Icefall Cave
        EncounterArea3(183, 0, Encounter::Surfing, {72, 72, 72, 73, 131}, {5, 20, 35, 35, 30}, {20, 35, 45, 45, 45}), // Icefall Cave Back
        EncounterArea3(86, 0, Encounter::OldRod, {129, 129}, {5, 5}, {10, 10}), // Pallet Town
        EncounterArea3(87, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Viridian City
        EncounterArea3(88, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cerulean City
        EncounterArea3(89, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Vermilion City
        EncounterArea3(90, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Celadon City
        EncounterArea3(91, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Fuchsia City
        EncounterArea3(92, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cinnabar Island
        EncounterArea3(96, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 4
        EncounterArea3(98, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 6
        EncounterArea3(102, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 10
        EncounterArea3(103, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 11
        EncounterArea3(104, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 12
        EncounterArea3(105, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 13
        EncounterArea3(111, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 19
        EncounterArea3(112, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 20
        EncounterArea3(113, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 21
        EncounterArea3(114, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 22
        EncounterArea3(115, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 23
        EncounterArea3(116, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 24
        EncounterArea3(117, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Route 25
        EncounterArea3(122, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // S.S. Anne
        EncounterArea3(129, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Safari Zone Area 3
        EncounterArea3(138, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Seafoam Islands B4F
        EncounterArea3(145, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cerulean Cave 1F
        EncounterArea3(147, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cerulean Cave B1F
        EncounterArea3(149, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // One Island
        EncounterArea3(150, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Four Island
        EncounterArea3(151, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Five Island
        EncounterArea3(152, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Kindle Road
        EncounterArea3(153, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Cape Brink
        EncounterArea3(155, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Bond Bridge
        EncounterArea3(157, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Resort Gorgeous
        EncounterArea3(158, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Water Labyrinth
        EncounterArea3(159, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Memorial Pillar
        EncounterArea3(161, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Outcast Island
        EncounterArea3(162, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Green Path
        EncounterArea3(163, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Water Path
        EncounterArea3(164, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Ruin Valley
        EncounterArea3(165, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Trainer Tower (exterior)
        EncounterArea3(168, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Tanoby Ruins
        EncounterArea3(179, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Berry Forest
        EncounterArea3(180, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Icefall Cave
        EncounterArea3(183, 0, Encounter::OldRod, {129, 129}, {5, 5}, {5, 5}), // Icefall Cave Back
        EncounterArea3(86, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Pallet Town
        EncounterArea3(87, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Viridian City
        EncounterArea3(88, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Cerulean City
        EncounterArea3(89, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Vermilion City
        EncounterArea3(90, 0, Encounter::GoodRod, {129, 129, 129}, {5, 5, 5}, {15, 15, 15}), // Celadon City
        EncounterArea3(91, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Fuchsia City
        EncounterArea3(92, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Cinnabar Island
        EncounterArea3(96, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 4
        EncounterArea3(98, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Route 6
        EncounterArea3(102, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 10
        EncounterArea3(103, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 11
        EncounterArea3(104, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 12
        EncounterArea3(105, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 13
        EncounterArea3(111, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 19
        EncounterArea3(112, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 20
        EncounterArea3(113, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 21
        EncounterArea3(114, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Route 22
        EncounterArea3(115, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Route 23
        EncounterArea3(116, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Route 24
        EncounterArea3(117, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Route 25
        EncounterArea3(122, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // S.S. Anne
        EncounterArea3(129, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Safari Zone Area 3
        EncounterArea3(138, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::GoodRod, {98, 129, 116}, {5, 5, 5}, {15, 15, 15}), // Seafoam Islands B4F
        EncounterArea3(145, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Cerulean Cave 1F
        EncounterArea3(147, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Cerulean Cave B1F
        EncounterArea3(149, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // One Island
        EncounterArea3(150, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Four Island
        EncounterArea3(151, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Five Island
        EncounterArea3(152, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Kindle Road
        EncounterArea3(153, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Cape Brink
        EncounterArea3(155, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Bond Bridge
        EncounterArea3(157, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Resort Gorgeous
        EncounterArea3(158, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Water Labyrinth
        EncounterArea3(159, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Memorial Pillar
        EncounterArea3(161, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Outcast Island
        EncounterArea3(162, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Green Path
        EncounterArea3(163, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Water Path
        EncounterArea3(164, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Ruin Valley
        EncounterArea3(165, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Trainer Tower (exterior)
        EncounterArea3(168, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Tanoby Ruins
        EncounterArea3(179, 0, Encounter::GoodRod, {118, 129, 60}, {5, 5, 5}, {15, 15, 15}), // Berry Forest
        EncounterArea3(180, 0, Encounter::GoodRod, {60, 129, 118}, {5, 5, 5}, {15, 15, 15}), // Icefall Cave
        EncounterArea3(183, 0, Encounter::GoodRod, {98, 129, 98}, {5, 5, 5}, {15, 15, 15}), // Icefall Cave Back
        EncounterArea3(86, 0, Encounter::SuperRod, {98, 120, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Pallet Town
        EncounterArea3(87, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Viridian City
        EncounterArea3(88, 0, Encounter::SuperRod, {98, 98, 130, 98, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Cerulean City
        EncounterArea3(89, 0, Encounter::SuperRod, {98, 120, 130, 116, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Vermilion City
        EncounterArea3(90, 0, Encounter::SuperRod, {129, 129, 129, 129, 88}, {15, 15, 15, 25, 30}, {25, 25, 25, 35, 40}), // Celadon City
        EncounterArea3(91, 0, Encounter::SuperRod, {118, 119, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Fuchsia City
        EncounterArea3(92, 0, Encounter::SuperRod, {98, 120, 130, 80, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Cinnabar Island
        EncounterArea3(96, 0, Encounter::SuperRod, {98, 98, 130, 98, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 4
        EncounterArea3(98, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Route 6
        EncounterArea3(102, 0, Encounter::SuperRod, {98, 98, 130, 98, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 10
        EncounterArea3(103, 0, Encounter::SuperRod, {98, 98, 130, 98, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 11
        EncounterArea3(104, 0, Encounter::SuperRod, {98, 98, 130, 98, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 12
        EncounterArea3(105, 0, Encounter::SuperRod, {98, 98, 130, 98, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 13
        EncounterArea3(111, 0, Encounter::SuperRod, {98, 98, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 19
        EncounterArea3(112, 0, Encounter::SuperRod, {98, 98, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 20
        EncounterArea3(113, 0, Encounter::SuperRod, {98, 98, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 21
        EncounterArea3(114, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Route 22
        EncounterArea3(115, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Route 23
        EncounterArea3(116, 0, Encounter::SuperRod, {98, 98, 130, 98, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Route 24
        EncounterArea3(117, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Route 25
        EncounterArea3(122, 0, Encounter::SuperRod, {98, 120, 130, 98, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // S.S. Anne
        EncounterArea3(129, 0, Encounter::SuperRod, {118, 119, 147, 79, 148}, {15, 20, 15, 15, 25}, {25, 30, 25, 35, 35}), // Safari Zone Center
        EncounterArea3(130, 0, Encounter::SuperRod, {118, 119, 147, 79, 148}, {15, 20, 15, 15, 25}, {25, 30, 25, 35, 35}), // Safari Zone Area 1
        EncounterArea3(131, 0, Encounter::SuperRod, {118, 119, 147, 79, 148}, {15, 20, 15, 15, 25}, {25, 30, 25, 35, 35}), // Safari Zone Area 2
        EncounterArea3(132, 0, Encounter::SuperRod, {118, 119, 147, 79, 148}, {15, 20, 15, 15, 25}, {25, 30, 25, 35, 35}), // Safari Zone Area 3
        EncounterArea3(138, 0, Encounter::SuperRod, {98, 98, 130, 79, 130}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Seafoam Islands B3F
        EncounterArea3(139, 0, Encounter::SuperRod, {98, 98, 130, 79, 130}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Seafoam Islands B4F
        EncounterArea3(145, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Cerulean Cave 1F
        EncounterArea3(147, 0, Encounter::SuperRod, {60, 61, 130, 79, 130}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Cerulean Cave B1F
        EncounterArea3(149, 0, Encounter::SuperRod, {98, 120, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // One Island
        EncounterArea3(150, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Four Island
        EncounterArea3(151, 0, Encounter::SuperRod, {98, 120, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Five Island
        EncounterArea3(152, 0, Encounter::SuperRod, {98, 98, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Kindle Road
        EncounterArea3(153, 0, Encounter::SuperRod, {98, 98, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Treasure Beach
        EncounterArea3(154, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Cape Brink
        EncounterArea3(155, 0, Encounter::SuperRod, {98, 98, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Bond Bridge
        EncounterArea3(157, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Resort Gorgeous
        EncounterArea3(158, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Water Labyrinth
        EncounterArea3(159, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Five Isle Meadow
        EncounterArea3(160, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Memorial Pillar
        EncounterArea3(161, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Outcast Island
        EncounterArea3(162, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Green Path
        EncounterArea3(163, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Water Path
        EncounterArea3(164, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Ruin Valley
        EncounterArea3(165, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Trainer Tower (exterior)
        EncounterArea3(168, 0, Encounter::SuperRod, {98, 223, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Tanoby Ruins
        EncounterArea3(179, 0, Encounter::SuperRod, {118, 119, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Berry Forest
        EncounterArea3(180, 0, Encounter::SuperRod, {60, 61, 130, 79, 79}, {15, 20, 15, 15, 25}, {25, 30, 25, 25, 35}), // Icefall Cave
        EncounterArea3(183, 0, Encounter::SuperRod, {98, 120, 130, 99, 79}, {15, 15, 15, 25, 25}, {25, 25, 25, 35, 35}), // Icefall Cave Back
    };
};

#endif // ENCOUNTERAREA3_HPP
