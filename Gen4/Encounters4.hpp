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

#ifndef ENCOUNTERS4_HPP
#define ENCOUNTERS4_HPP

#include <PokeFinderCore/Gen4/EncounterArea4.hpp>

namespace Encounters4
{
    QVector<EncounterArea4> getEncounters(Encounter type, Game game, int time);

    const QVector<EncounterArea4> encountersDiamond
    {
        EncounterArea4(0, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Twinleaf Town
        EncounterArea4(1, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::SuperRod, {130, 341, 340, 342, 342}, {30, 30, 40, 35, 35}, {40, 40, 55, 55, 55}), // Celestic Town
        EncounterArea4(2, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::SuperRod, {130, 457, 120, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Canalave City
        EncounterArea4(3, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Eterna City
        EncounterArea4(4, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::SuperRod, {130, 224, 130, 224, 224}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Pastoria City
        EncounterArea4(5, 0, Game::Blank, Encounter::Surfing, {73, 279, 458, 458, 458}, {35, 35, 30, 30, 35}, {45, 45, 40, 40, 45}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::SuperRod, {130, 224, 120, 224, 224}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Sunyshore City
        EncounterArea4(6, 0, Game::Blank, Encounter::Surfing, {279, 73, 279, 73, 73}, {35, 35, 40, 40, 40}, {40, 40, 45, 45, 45}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::SuperRod, {130, 224, 370, 224, 224}, {30, 30, 20, 20, 20}, {40, 40, 30, 50, 50}), // Pokï¿½mon League
        EncounterArea4(7, 1, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 2, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 3, Game::Blank, Encounter::Grass, {396, 399, 399, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::FireRed, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 58, 58, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::Blank, Encounter::Swarm, {84, 84, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 396, 399, 29, 29, 396, 399, 396, 399, 32, 32}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(8, 1, Game::Blank, Encounter::Grass, {403, 399, 396, 401, 396, 403, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 2, Game::Blank, Encounter::Grass, {403, 399, 396, 396, 396, 403, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 3, Game::Blank, Encounter::Grass, {403, 399, 401, 401, 396, 403, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::FireRed, Encounter::Grass, {403, 399, 396, 401, 396, 403, 396, 399, 58, 58, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::Blank, Encounter::Swarm, {263, 263, 396, 401, 396, 403, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::Blank, Encounter::PokeRadar, {403, 399, 396, 401, 161, 161, 396, 399, 396, 399, 161, 161}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(9, 1, Game::Blank, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 2, Game::Blank, Encounter::Grass, {396, 403, 396, 396, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 3, Game::Blank, Encounter::Grass, {396, 403, 41, 401, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Ruby, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 273, 273, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Sapphire, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 270, 270, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Emerald, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 204, 204, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::Swarm, {104, 104, 396, 401, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::PokeRadar, {396, 403, 396, 401, 280, 280, 63, 403, 396, 399, 280, 281}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(10, 1, Game::Blank, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 2, Game::Blank, Encounter::Grass, {396, 399, 406, 396, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 3, Game::Blank, Encounter::Grass, {396, 399, 41, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Ruby, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 273, 273, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Sapphire, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 270, 270, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Emerald, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 204, 204, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::FireRed, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 10, 10, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 406, 401, 280, 280, 406, 403, 396, 399, 280, 281}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(11, 1, Game::Blank, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 2, Game::Blank, Encounter::Grass, {396, 399, 406, 396, 406, 403, 406, 403, 396, 399, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 3, Game::Blank, Encounter::Grass, {396, 399, 41, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Ruby, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 273, 273, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Sapphire, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 270, 270, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Emerald, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 204, 204, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 406, 401, 191, 191, 406, 403, 396, 399, 191, 191}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(12, 0, Game::Blank, Encounter::Grass, {418, 422, 418, 422, 399, 422, 417, 417, 418, 422, 418, 422}, {8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10}), // Route 205 (South)
        EncounterArea4(12, 0, Game::FireRed, Encounter::Grass, {418, 422, 418, 422, 399, 422, 417, 417, 239, 239, 418, 422}, {8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::PokeRadar, {418, 422, 418, 422, 187, 187, 417, 417, 418, 422, 187, 187}, {8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10}), // Route 205 (South)
        EncounterArea4(13, 0, Game::Blank, Encounter::Grass, {418, 399, 418, 399, 422, 399, 417, 417, 418, 399, 418, 399}, {10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Sapphire, Encounter::Grass, {418, 399, 418, 399, 422, 399, 417, 417, 270, 270, 418, 399}, {10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::PokeRadar, {418, 399, 418, 399, 187, 187, 417, 417, 418, 399, 188, 188}, {10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12}), // Route 205 (North)
        EncounterArea4(14, 1, Game::Blank, Encounter::Grass, {77, 434, 77, 401, 74, 402, 436, 436, 77, 434, 77, 434}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 2, Game::Blank, Encounter::Grass, {77, 434, 77, 77, 74, 402, 436, 436, 77, 434, 77, 434}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 3, Game::Blank, Encounter::Grass, {77, 434, 41, 402, 74, 402, 436, 436, 77, 434, 77, 434}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 0, Game::Emerald, Encounter::Grass, {77, 434, 77, 401, 74, 402, 436, 436, 207, 207, 77, 434}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 0, Game::Blank, Encounter::Swarm, {299, 299, 77, 401, 74, 402, 436, 436, 77, 434, 77, 434}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 0, Game::Blank, Encounter::PokeRadar, {77, 434, 77, 401, 343, 343, 436, 436, 77, 434, 343, 343}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(15, 1, Game::Blank, Encounter::Grass, {66, 74, 66, 401, 74, 74, 74, 74, 66, 74, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 2, Game::Blank, Encounter::Grass, {66, 74, 66, 66, 74, 74, 74, 74, 66, 74, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 3, Game::Blank, Encounter::Grass, {66, 74, 41, 401, 74, 74, 74, 74, 66, 74, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 0, Game::Emerald, Encounter::Grass, {66, 74, 66, 401, 74, 74, 74, 74, 207, 207, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 0, Game::Blank, Encounter::Swarm, {231, 231, 66, 401, 74, 74, 74, 74, 66, 74, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 0, Game::Blank, Encounter::PokeRadar, {66, 74, 66, 401, 246, 246, 74, 74, 66, 74, 246, 246}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(16, 1, Game::Blank, Encounter::Grass, {54, 399, 307, 66, 307, 66, 54, 400, 54, 400, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 2, Game::Blank, Encounter::Grass, {54, 399, 307, 66, 307, 66, 54, 400, 54, 400, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 3, Game::Blank, Encounter::Grass, {54, 399, 41, 41, 307, 66, 54, 400, 54, 400, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 0, Game::Ruby, Encounter::Grass, {54, 399, 307, 66, 307, 66, 54, 400, 335, 335, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 0, Game::Sapphire, Encounter::Grass, {54, 399, 307, 66, 307, 66, 54, 400, 336, 336, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::Swarm, {206, 206, 307, 66, 307, 66, 54, 400, 54, 400, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::PokeRadar, {54, 399, 307, 66, 236, 236, 54, 400, 54, 400, 236, 236}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(17, 1, Game::Blank, Encounter::Grass, {396, 400, 439, 439, 400, 397, 400, 397, 113, 439, 113, 439}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(17, 2, Game::Blank, Encounter::Grass, {396, 400, 397, 400, 400, 397, 400, 397, 113, 439, 113, 439}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(17, 3, Game::Blank, Encounter::Grass, {396, 400, 92, 41, 400, 397, 400, 397, 113, 439, 113, 439}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::Swarm, {209, 209, 439, 439, 400, 397, 400, 397, 113, 439, 113, 439}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::PokeRadar, {396, 400, 439, 439, 128, 128, 400, 397, 113, 439, 241, 241}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(18, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 41}, {16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18}), // Lost Tower 1F
        EncounterArea4(18, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 41}, {16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18}), // Lost Tower 1F
        EncounterArea4(18, 3, Game::Blank, Encounter::Grass, {92, 41, 198, 198, 92, 41, 92, 41, 92, 41, 92, 41}, {16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18}), // Lost Tower 1F
        EncounterArea4(19, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 41}, {17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19}), // Lost Tower 2F
        EncounterArea4(19, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 41}, {17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19}), // Lost Tower 2F
        EncounterArea4(19, 3, Game::Blank, Encounter::Grass, {92, 41, 198, 198, 92, 41, 92, 41, 92, 41, 92, 41}, {17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19}), // Lost Tower 2F
        EncounterArea4(20, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 42}, {18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 20, 19}), // Lost Tower 3F
        EncounterArea4(20, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 42}, {18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 20, 19}), // Lost Tower 3F
        EncounterArea4(20, 3, Game::Blank, Encounter::Grass, {92, 41, 198, 198, 92, 41, 92, 41, 92, 41, 92, 42}, {18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 20, 19}), // Lost Tower 3F
        EncounterArea4(21, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 42, 92, 42}, {19, 19, 20, 20, 20, 20, 21, 21, 21, 20, 21, 21}), // Lost Tower 4F
        EncounterArea4(21, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 42, 92, 42}, {19, 19, 20, 20, 20, 20, 21, 21, 21, 20, 21, 21}), // Lost Tower 4F
        EncounterArea4(21, 3, Game::Blank, Encounter::Grass, {92, 41, 198, 198, 92, 41, 92, 41, 92, 42, 92, 42}, {19, 19, 20, 20, 20, 20, 21, 21, 21, 20, 21, 21}), // Lost Tower 4F
        EncounterArea4(22, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 42, 92, 42, 92, 42}, {20, 20, 21, 21, 21, 21, 22, 21, 22, 22, 22, 23}), // Lost Tower 5F
        EncounterArea4(22, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 42, 92, 42, 92, 42}, {20, 20, 21, 21, 21, 21, 22, 21, 22, 22, 22, 23}), // Lost Tower 5F
        EncounterArea4(22, 3, Game::Blank, Encounter::Grass, {92, 41, 198, 198, 92, 41, 92, 42, 92, 42, 92, 42}, {20, 20, 21, 21, 21, 21, 22, 21, 22, 22, 22, 23}), // Lost Tower 5F
        EncounterArea4(23, 1, Game::Blank, Encounter::Grass, {77, 74, 439, 439, 74, 402, 77, 77, 113, 439, 113, 439}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 2, Game::Blank, Encounter::Grass, {77, 74, 77, 77, 74, 402, 77, 77, 113, 439, 113, 439}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 3, Game::Blank, Encounter::Grass, {77, 74, 402, 402, 74, 402, 77, 77, 113, 439, 113, 439}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Ruby, Encounter::Grass, {77, 74, 439, 439, 74, 402, 77, 77, 273, 274, 113, 439}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Emerald, Encounter::Grass, {77, 74, 439, 439, 74, 402, 77, 77, 204, 204, 113, 439}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Blank, Encounter::PokeRadar, {77, 74, 439, 439, 128, 128, 77, 77, 113, 439, 241, 241}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(24, 1, Game::Blank, Encounter::Grass, {54, 400, 307, 66, 307, 66, 67, 307, 67, 307, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 2, Game::Blank, Encounter::Grass, {54, 400, 307, 66, 307, 66, 67, 307, 67, 307, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 3, Game::Blank, Encounter::Grass, {54, 400, 163, 164, 307, 66, 67, 307, 67, 307, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Ruby, Encounter::Grass, {54, 400, 307, 66, 307, 66, 67, 307, 335, 335, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Sapphire, Encounter::Grass, {54, 400, 307, 66, 307, 66, 67, 307, 336, 336, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::PokeRadar, {54, 400, 307, 66, 352, 352, 67, 307, 67, 307, 352, 352}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(25, 1, Game::Blank, Encounter::Grass, {307, 399, 307, 399, 74, 77, 433, 433, 399, 307, 399, 307}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(25, 2, Game::Blank, Encounter::Grass, {307, 399, 307, 399, 74, 77, 433, 433, 399, 307, 399, 307}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(25, 3, Game::Blank, Encounter::Grass, {307, 399, 41, 163, 74, 77, 433, 433, 399, 307, 399, 307}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(25, 0, Game::Emerald, Encounter::Grass, {307, 399, 307, 399, 74, 77, 433, 433, 216, 216, 399, 307}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(25, 0, Game::Blank, Encounter::PokeRadar, {307, 399, 307, 399, 236, 236, 433, 433, 399, 307, 236, 236}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(26, 1, Game::Blank, Encounter::Grass, {307, 75, 77, 67, 67, 307, 433, 433, 307, 77, 307, 77}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(26, 2, Game::Blank, Encounter::Grass, {307, 75, 77, 67, 67, 307, 433, 433, 307, 77, 307, 77}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(26, 3, Game::Blank, Encounter::Grass, {307, 75, 41, 164, 67, 307, 433, 433, 307, 77, 307, 77}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(26, 0, Game::Emerald, Encounter::Grass, {307, 75, 77, 67, 67, 307, 433, 433, 216, 216, 307, 77}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(26, 0, Game::Blank, Encounter::PokeRadar, {307, 75, 77, 67, 333, 333, 433, 433, 307, 77, 333, 333}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(27, 1, Game::Blank, Encounter::Grass, {396, 406, 397, 402, 315, 406, 315, 397, 402, 402, 402, 402}, {16, 16, 17, 17, 16, 16, 17, 18, 17, 17, 18, 18}), // Route 212 (North)
        EncounterArea4(27, 2, Game::Blank, Encounter::Grass, {396, 406, 397, 397, 315, 406, 315, 397, 402, 402, 402, 402}, {16, 16, 17, 17, 16, 16, 17, 18, 17, 17, 18, 18}), // Route 212 (North)
        EncounterArea4(27, 3, Game::Blank, Encounter::Grass, {396, 406, 402, 402, 315, 406, 315, 397, 402, 402, 402, 402}, {16, 16, 17, 17, 16, 16, 17, 18, 17, 17, 18, 18}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::PokeRadar, {396, 406, 397, 402, 235, 235, 315, 397, 402, 402, 235, 235}, {16, 16, 17, 17, 16, 16, 17, 18, 17, 17, 18, 18}), // Route 212 (North)
        EncounterArea4(28, 1, Game::Blank, Encounter::Grass, {194, 400, 315, 400, 402, 315, 315, 194, 400, 194, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 2, Game::Blank, Encounter::Grass, {194, 400, 315, 400, 402, 315, 315, 194, 400, 194, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 3, Game::Blank, Encounter::Grass, {194, 400, 402, 402, 402, 315, 315, 194, 400, 194, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Sapphire, Encounter::Grass, {194, 400, 315, 400, 402, 315, 315, 194, 271, 270, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 0, Game::FireRed, Encounter::Grass, {194, 400, 315, 400, 402, 315, 315, 194, 23, 23, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::PokeRadar, {194, 400, 315, 400, 88, 88, 315, 194, 400, 194, 88, 88}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(29, 1, Game::Blank, Encounter::Grass, {418, 422, 418, 278, 422, 278, 419, 422, 419, 422, 419, 422}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(29, 2, Game::Blank, Encounter::Grass, {418, 422, 418, 278, 422, 278, 419, 422, 419, 422, 419, 422}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(29, 3, Game::Blank, Encounter::Grass, {418, 422, 418, 422, 422, 278, 419, 422, 419, 422, 419, 422}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::SuperRod, {130, 224, 319, 224, 224}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::Swarm, {359, 359, 418, 278, 422, 278, 419, 422, 419, 422, 419, 422}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::PokeRadar, {418, 422, 418, 278, 277, 277, 419, 422, 419, 422, 277, 277}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(30, 1, Game::Blank, Encounter::Grass, {77, 74, 77, 75, 434, 203, 402, 77, 434, 75, 434, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 2, Game::Blank, Encounter::Grass, {77, 74, 77, 75, 434, 203, 402, 77, 434, 75, 434, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 3, Game::Blank, Encounter::Grass, {77, 74, 402, 402, 434, 203, 402, 77, 434, 75, 434, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 0, Game::Emerald, Encounter::Grass, {77, 74, 77, 75, 434, 203, 402, 77, 207, 207, 434, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::Swarm, {325, 325, 77, 75, 434, 203, 402, 77, 434, 75, 434, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::PokeRadar, {77, 74, 77, 75, 262, 262, 402, 77, 434, 75, 262, 262}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(31, 1, Game::Blank, Encounter::Grass, {77, 74, 77, 74, 63, 402, 64, 64, 74, 64, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 2, Game::Blank, Encounter::Grass, {77, 74, 77, 77, 63, 402, 64, 64, 74, 64, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 3, Game::Blank, Encounter::Grass, {77, 74, 402, 402, 63, 402, 64, 64, 74, 64, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 0, Game::Emerald, Encounter::Grass, {77, 74, 77, 74, 63, 402, 64, 64, 207, 207, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 0, Game::Blank, Encounter::Swarm, {96, 96, 77, 74, 63, 402, 64, 64, 74, 64, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 0, Game::Blank, Encounter::PokeRadar, {77, 74, 77, 74, 262, 262, 64, 64, 74, 64, 262, 262}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(32, 1, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 307, 67, 459, 215, 75, 75, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 2, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 307, 67, 459, 215, 75, 75, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 3, Game::Blank, Encounter::Grass, {459, 215, 41, 164, 307, 67, 459, 215, 75, 75, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 0, Game::Emerald, Encounter::Grass, {459, 215, 307, 67, 307, 67, 459, 215, 217, 217, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 0, Game::Blank, Encounter::Swarm, {225, 225, 307, 67, 307, 67, 459, 215, 75, 75, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 0, Game::Blank, Encounter::PokeRadar, {459, 215, 307, 67, 361, 361, 459, 215, 75, 75, 361, 361}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(33, 1, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 2, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 3, Game::Blank, Encounter::Grass, {459, 215, 41, 164, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 0, Game::Emerald, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 217, 217, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 0, Game::Blank, Encounter::Swarm, {220, 220, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 0, Game::Blank, Encounter::PokeRadar, {459, 215, 307, 67, 361, 361, 459, 215, 308, 308, 361, 361}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(34, 0, Game::Blank, Encounter::Grass, {419, 422, 419, 423, 122, 278, 419, 423, 122, 423, 122, 423}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::SuperRod, {130, 457, 130, 457, 457}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::Swarm, {100, 100, 419, 423, 122, 278, 419, 423, 122, 423, 122, 423}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::PokeRadar, {419, 422, 419, 423, 132, 132, 419, 423, 122, 423, 132, 132}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 218
        EncounterArea4(35, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::SuperRod, {130, 457, 366, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 30, 50, 50}), // Route 219
        EncounterArea4(36, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::SuperRod, {130, 170, 457, 171, 171}, {30, 15, 30, 20, 20}, {40, 25, 40, 45, 45}), // Route 220
        EncounterArea4(37, 0, Game::Blank, Encounter::Grass, {419, 434, 315, 422, 435, 278, 419, 423, 435, 423, 435, 423}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::SuperRod, {130, 457, 366, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 30, 50, 50}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::Swarm, {83, 83, 315, 422, 435, 278, 419, 423, 435, 423, 435, 423}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::PokeRadar, {419, 434, 315, 422, 30, 30, 419, 423, 435, 423, 33, 33}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 221
        EncounterArea4(38, 1, Game::Blank, Encounter::Grass, {419, 423, 441, 441, 122, 278, 419, 423, 122, 423, 122, 423}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(38, 2, Game::Blank, Encounter::Grass, {419, 423, 441, 441, 122, 278, 419, 423, 122, 423, 122, 423}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(38, 3, Game::Blank, Encounter::Grass, {419, 423, 419, 423, 122, 278, 419, 423, 122, 423, 122, 423}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::SuperRod, {130, 224, 319, 224, 224}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::Swarm, {300, 300, 441, 441, 122, 278, 419, 423, 122, 423, 122, 423}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::PokeRadar, {419, 423, 441, 441, 180, 180, 419, 423, 122, 423, 180, 180}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(39, 0, Game::Blank, Encounter::Surfing, {73, 279, 458, 458, 458}, {35, 35, 30, 30, 35}, {45, 45, 40, 40, 45}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::SuperRod, {130, 320, 224, 321, 321}, {30, 30, 40, 35, 35}, {40, 40, 55, 55, 55}), // Route 223
        EncounterArea4(40, 1, Game::Blank, Encounter::Grass, {419, 423, 441, 441, 315, 315, 44, 70, 418, 267, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 2, Game::Blank, Encounter::Grass, {419, 423, 441, 441, 315, 315, 44, 70, 418, 267, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 3, Game::Blank, Encounter::Grass, {419, 423, 419, 423, 315, 315, 44, 70, 418, 267, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 0, Game::Emerald, Encounter::Grass, {419, 423, 441, 441, 315, 315, 44, 70, 213, 213, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::Surfing, {279, 73, 279, 73, 73}, {40, 40, 45, 45, 45}, {50, 50, 55, 55, 55}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::SuperRod, {130, 224, 370, 224, 224}, {30, 30, 20, 20, 20}, {40, 40, 30, 50, 50}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::Swarm, {177, 177, 441, 441, 315, 315, 44, 70, 418, 267, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::PokeRadar, {419, 423, 441, 441, 356, 356, 44, 70, 418, 267, 355, 355}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(41, 1, Game::Blank, Encounter::Grass, {22, 20, 22, 22, 20, 435, 67, 315, 21, 19, 21, 19}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(41, 2, Game::Blank, Encounter::Grass, {22, 20, 22, 22, 20, 435, 67, 315, 21, 19, 21, 19}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(41, 3, Game::Blank, Encounter::Grass, {22, 20, 354, 354, 20, 435, 67, 315, 21, 19, 21, 19}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::Surfing, {55, 61, 55, 55, 55}, {40, 40, 45, 45, 45}, {50, 50, 55, 55, 55}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::GoodRod, {129, 60, 129, 60, 60}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::SuperRod, {130, 61, 130, 61, 61}, {30, 30, 40, 35, 35}, {40, 40, 55, 55, 55}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::Swarm, {296, 296, 22, 22, 20, 435, 67, 315, 21, 19, 21, 19}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::PokeRadar, {22, 20, 22, 22, 57, 57, 67, 315, 21, 19, 56, 56}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(42, 1, Game::Blank, Encounter::Grass, {22, 20, 22, 22, 20, 67, 55, 55, 21, 19, 21, 19}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(42, 2, Game::Blank, Encounter::Grass, {22, 20, 22, 22, 20, 67, 55, 55, 21, 19, 21, 19}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(42, 3, Game::Blank, Encounter::Grass, {22, 20, 354, 354, 20, 67, 55, 55, 21, 19, 21, 19}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::Surfing, {279, 86, 73, 87, 87}, {40, 35, 40, 40, 40}, {55, 45, 55, 55, 55}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::GoodRod, {129, 116, 129, 116, 116}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::SuperRod, {130, 117, 369, 117, 117}, {30, 30, 40, 35, 35}, {40, 40, 50, 55, 55}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::Swarm, {98, 98, 22, 22, 20, 67, 55, 55, 21, 19, 21, 19}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::PokeRadar, {22, 20, 22, 22, 57, 57, 55, 55, 21, 19, 56, 56}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(43, 1, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 2, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 3, Game::Blank, Encounter::Grass, {323, 112, 354, 42, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 0, Game::Emerald, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 207, 207, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::Surfing, {61, 60, 61, 61, 61}, {40, 20, 45, 45, 45}, {50, 30, 55, 55, 55}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::Swarm, {327, 327, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::PokeRadar, {323, 112, 22, 75, 324, 324, 227, 75, 322, 111, 324, 324}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(44, 1, Game::Blank, Encounter::Grass, {51, 332, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(44, 2, Game::Blank, Encounter::Grass, {51, 332, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(44, 3, Game::Blank, Encounter::Grass, {51, 332, 332, 332, 112, 450, 51, 51, 50, 331, 50, 331}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::Surfing, {61, 60, 61, 61, 61}, {40, 20, 45, 45, 45}, {50, 30, 55, 55, 55}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::Swarm, {374, 374, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::PokeRadar, {51, 332, 450, 112, 329, 329, 51, 51, 50, 331, 328, 328}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(45, 1, Game::Blank, Encounter::Grass, {70, 44, 166, 166, 314, 315, 123, 313, 69, 43, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 2, Game::Blank, Encounter::Grass, {70, 44, 70, 44, 314, 315, 123, 313, 69, 43, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 3, Game::Blank, Encounter::Grass, {70, 44, 168, 168, 314, 315, 123, 313, 69, 43, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Ruby, Encounter::Grass, {70, 44, 166, 166, 314, 315, 123, 313, 274, 274, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Sapphire, Encounter::Grass, {70, 44, 166, 166, 314, 315, 123, 313, 271, 271, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Emerald, Encounter::Grass, {70, 44, 166, 166, 314, 315, 123, 313, 204, 204, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::Surfing, {278, 279, 278, 278, 278}, {40, 45, 45, 45, 45}, {50, 55, 55, 55, 55}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::SuperRod, {130, 130, 130, 130, 130}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::Swarm, {16, 16, 166, 166, 314, 315, 123, 313, 69, 43, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::PokeRadar, {70, 44, 166, 166, 49, 49, 123, 313, 69, 43, 48, 48}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(46, 0, Game::Blank, Encounter::Grass, {70, 44, 55, 267, 69, 43, 419, 423, 419, 419, 69, 43}, {50, 50, 52, 51, 18, 18, 51, 51, 52, 50, 23, 23}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::Surfing, {279, 86, 73, 87, 87}, {40, 35, 40, 40, 40}, {55, 45, 55, 55, 55}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::SuperRod, {130, 320, 224, 321, 321}, {30, 30, 40, 35, 35}, {40, 40, 55, 55, 55}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::Swarm, {222, 222, 55, 267, 69, 43, 419, 423, 419, 419, 69, 43}, {50, 50, 52, 51, 18, 18, 51, 51, 52, 50, 23, 23}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::PokeRadar, {70, 44, 55, 267, 175, 175, 419, 423, 419, 419, 175, 175}, {50, 50, 52, 51, 18, 18, 51, 51, 52, 50, 23, 23}), // Route 230
        EncounterArea4(47, 0, Game::Blank, Encounter::Grass, {74, 74, 41, 41, 74, 74, 95, 95, 74, 74, 74, 74}, {6, 6, 7, 7, 7, 7, 8, 8, 9, 9, 5, 5}), // Oreburgh Mine 1F
        EncounterArea4(48, 0, Game::Blank, Encounter::Grass, {74, 74, 41, 41, 74, 74, 95, 95, 74, 74, 74, 74}, {7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 6, 6}), // Oreburgh Mine B1F
        EncounterArea4(49, 0, Game::Blank, Encounter::Grass, {418, 417, 418, 422, 399, 422, 422, 417, 418, 422, 418, 422}, {7, 7, 8, 8, 8, 7, 9, 8, 9, 9, 9, 9}), // Valley Windworks
        EncounterArea4(49, 0, Game::FireRed, Encounter::Grass, {418, 417, 418, 422, 399, 422, 422, 417, 239, 239, 418, 422}, {7, 7, 8, 8, 8, 7, 9, 8, 9, 9, 9, 9}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 30, 30}, {40, 40, 40, 50, 50}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::Swarm, {309, 309, 418, 422, 399, 422, 422, 417, 418, 422, 418, 422}, {7, 7, 8, 8, 8, 7, 9, 8, 9, 9, 9, 9}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::PokeRadar, {418, 417, 418, 422, 179, 179, 422, 417, 418, 422, 179, 179}, {7, 7, 8, 8, 8, 7, 9, 8, 9, 9, 9, 9}), // Valley Windworks
        EncounterArea4(50, 1, Game::Blank, Encounter::Grass, {265, 266, 265, 406, 427, 406, 427, 406, 406, 427, 267, 267}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 2, Game::Blank, Encounter::Grass, {265, 266, 265, 406, 427, 406, 427, 406, 406, 427, 267, 267}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 3, Game::Blank, Encounter::Grass, {265, 266, 198, 198, 427, 406, 427, 406, 406, 427, 267, 267}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::Ruby, Encounter::Grass, {265, 266, 265, 406, 427, 406, 427, 406, 273, 273, 267, 267}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::Emerald, Encounter::Grass, {265, 266, 265, 406, 427, 406, 427, 406, 204, 204, 267, 267}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::FireRed, Encounter::Grass, {265, 266, 265, 406, 427, 406, 427, 406, 11, 11, 267, 267}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::Blank, Encounter::Swarm, {287, 287, 265, 406, 427, 406, 427, 406, 406, 427, 267, 267}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::Blank, Encounter::PokeRadar, {265, 266, 265, 406, 290, 290, 427, 406, 406, 427, 290, 290}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(51, 0, Game::Blank, Encounter::Grass, {419, 422, 403, 278, 404, 423, 417, 417, 419, 423, 419, 423}, {29, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::Swarm, {81, 81, 403, 278, 404, 423, 417, 417, 419, 423, 419, 423}, {29, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::PokeRadar, {419, 422, 403, 278, 304, 304, 417, 417, 419, 423, 304, 304}, {29, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30}), // Fuego Ironworks
        EncounterArea4(52, 1, Game::Blank, Encounter::Grass, {66, 74, 173, 173, 307, 41, 433, 433, 66, 173, 66, 173}, {15, 15, 14, 14, 15, 15, 15, 15, 16, 14, 16, 14}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 2, Game::Blank, Encounter::Grass, {66, 74, 74, 41, 307, 41, 433, 433, 66, 173, 66, 173}, {15, 15, 14, 14, 15, 15, 15, 15, 16, 14, 16, 14}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 3, Game::Blank, Encounter::Grass, {66, 74, 74, 41, 307, 41, 433, 433, 66, 173, 66, 173}, {15, 15, 14, 14, 15, 15, 15, 15, 16, 14, 16, 14}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(53, 1, Game::Blank, Encounter::Grass, {307, 74, 173, 173, 66, 41, 433, 433, 307, 173, 307, 173}, {13, 13, 12, 12, 13, 13, 13, 13, 14, 12, 14, 12}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(53, 2, Game::Blank, Encounter::Grass, {307, 74, 74, 41, 66, 41, 433, 433, 307, 173, 307, 173}, {13, 13, 12, 12, 13, 13, 13, 13, 14, 12, 14, 12}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(53, 3, Game::Blank, Encounter::Grass, {307, 74, 74, 41, 66, 41, 433, 433, 307, 173, 307, 173}, {13, 13, 12, 12, 13, 13, 13, 13, 14, 12, 14, 12}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(54, 0, Game::Blank, Encounter::Grass, {307, 75, 35, 42, 67, 42, 433, 433, 307, 35, 307, 35}, {31, 31, 30, 32, 31, 31, 30, 30, 32, 31, 32, 32}), // Mt. Coronet (Route 216 Entrance)
        EncounterArea4(55, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 436, 35, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 2F
        EncounterArea4(55, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 338, 338, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 2F
        EncounterArea4(55, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 337, 337, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 2F
        EncounterArea4(56, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 436, 35, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 3F
        EncounterArea4(56, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 338, 338, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 3F
        EncounterArea4(56, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 337, 337, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 3F
        EncounterArea4(57, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 437, 35, 437, 35}, {40, 38, 39, 38, 39, 39, 39, 40, 38, 39, 39, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 338, 338, 437, 35}, {40, 38, 39, 38, 39, 39, 39, 40, 38, 39, 39, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 337, 337, 437, 35}, {40, 38, 39, 38, 39, 39, 39, 40, 38, 39, 39, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::SuperRod, {130, 147, 130, 148, 148}, {30, 15, 40, 15, 15}, {40, 20, 55, 35, 40}), // Mt. Coronet 4F
        EncounterArea4(58, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 358, 437, 35, 437, 35}, {40, 38, 39, 38, 39, 39, 40, 40, 38, 39, 39, 40}), // Mt. Coronet 5F
        EncounterArea4(58, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 358, 338, 338, 437, 35}, {40, 38, 39, 38, 39, 39, 40, 40, 38, 39, 39, 40}), // Mt. Coronet 5F
        EncounterArea4(58, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 358, 337, 337, 437, 35}, {40, 38, 39, 38, 39, 39, 40, 40, 38, 39, 39, 40}), // Mt. Coronet 5F
        EncounterArea4(59, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 437, 35, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 6F
        EncounterArea4(59, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 338, 338, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 6F
        EncounterArea4(59, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 337, 337, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 6F
        EncounterArea4(60, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 437, 35, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 7F
        EncounterArea4(60, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 338, 338, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 7F
        EncounterArea4(60, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 337, 337, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 7F
        EncounterArea4(61, 0, Game::Blank, Encounter::Grass, {307, 75, 35, 42, 67, 42, 433, 433, 307, 35, 307, 35}, {31, 31, 30, 32, 31, 31, 30, 30, 32, 31, 32, 32}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Mt. Coronet B1F
        EncounterArea4(62, 1, Game::Blank, Encounter::Grass, {459, 460, 308, 67, 308, 67, 433, 433, 437, 35, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 2, Game::Blank, Encounter::Grass, {459, 460, 308, 67, 308, 67, 433, 433, 437, 35, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 3, Game::Blank, Encounter::Grass, {459, 460, 42, 164, 308, 67, 433, 433, 437, 35, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Ruby, Encounter::Grass, {459, 460, 308, 67, 308, 67, 433, 433, 338, 338, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Sapphire, Encounter::Grass, {459, 460, 308, 67, 308, 67, 433, 433, 337, 337, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Blank, Encounter::PokeRadar, {459, 460, 308, 67, 294, 294, 433, 433, 437, 35, 294, 294}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(63, 0, Game::Blank, Encounter::Grass, {75, 75, 67, 35, 308, 42, 433, 433, 437, 35, 437, 35}, {40, 39, 40, 38, 40, 39, 38, 40, 40, 39, 39, 40}), // Mt. Coronet	Top Cave
        EncounterArea4(63, 0, Game::Ruby, Encounter::Grass, {75, 75, 67, 35, 308, 42, 433, 433, 338, 338, 437, 35}, {40, 39, 40, 38, 40, 39, 38, 40, 40, 39, 39, 40}), // Mt. Coronet	Top Cave
        EncounterArea4(63, 0, Game::Sapphire, Encounter::Grass, {75, 75, 67, 35, 308, 42, 433, 433, 337, 337, 437, 35}, {40, 39, 40, 38, 40, 39, 38, 40, 40, 39, 39, 40}), // Mt. Coronet	Top Cave
        EncounterArea4(64, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 1
        EncounterArea4(64, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 1
        EncounterArea4(64, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 164, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 1
        EncounterArea4(65, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 2
        EncounterArea4(65, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 2
        EncounterArea4(65, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 164, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 2
        EncounterArea4(66, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 3
        EncounterArea4(66, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 3
        EncounterArea4(66, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 3
        EncounterArea4(67, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 4
        EncounterArea4(67, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 4
        EncounterArea4(67, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 4
        EncounterArea4(68, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 399, 298, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 5
        EncounterArea4(68, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 399, 298, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 5
        EncounterArea4(68, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 183, 195, 183, 195, 399, 298, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 5
        EncounterArea4(68, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 5
        EncounterArea4(69, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 6
        EncounterArea4(69, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 6
        EncounterArea4(69, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 183, 195, 183, 195, 54, 54, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 6
        EncounterArea4(70, 0, Game::Blank, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {19, 20, 18, 21, 17, 22, 16, 23, 15, 24, 14, 25}), // Solaceon Ruins
        EncounterArea4(71, 0, Game::Blank, Encounter::Grass, {67, 75, 308, 42, 95, 208, 42, 42, 67, 308, 67, 308}, {45, 45, 45, 45, 44, 46, 46, 44, 46, 46, 44, 44}), // Victory Road 1F
        EncounterArea4(72, 0, Game::Blank, Encounter::Grass, {64, 75, 308, 42, 95, 208, 42, 42, 64, 308, 64, 308}, {46, 46, 46, 46, 45, 47, 47, 45, 47, 47, 45, 45}), // Victory Road 2F
        EncounterArea4(73, 0, Game::Blank, Encounter::Grass, {67, 419, 308, 42, 419, 208, 42, 42, 67, 308, 67, 308}, {45, 45, 45, 45, 44, 46, 46, 44, 46, 46, 44, 44}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::Surfing, {42, 42, 42, 42, 42}, {35, 35, 40, 40, 40}, {45, 45, 50, 50, 50}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::SuperRod, {130, 130, 130, 130, 130}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Victory Road B1F
        EncounterArea4(74, 0, Game::Blank, Encounter::Grass, {67, 419, 308, 42, 419, 208, 42, 42, 67, 308, 67, 308}, {51, 51, 51, 51, 50, 52, 52, 50, 52, 52, 50, 50}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::Surfing, {42, 42, 131, 131, 131}, {40, 45, 40, 45, 50}, {50, 55, 50, 55, 60}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::SuperRod, {130, 130, 130, 130, 130}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Victory Road Back Room 1
        EncounterArea4(75, 0, Game::Blank, Encounter::Grass, {67, 75, 308, 42, 95, 208, 42, 42, 67, 308, 67, 308}, {51, 51, 51, 51, 50, 52, 52, 50, 52, 52, 50, 50}), // Victory Road Back Room 2
        EncounterArea4(76, 0, Game::Blank, Encounter::Grass, {67, 75, 308, 42, 95, 208, 42, 42, 67, 308, 67, 308}, {51, 51, 51, 51, 50, 52, 52, 50, 52, 52, 50, 50}), // Victory Road Back Room 3
        EncounterArea4(77, 0, Game::Blank, Encounter::Grass, {41, 41, 74, 74, 41, 41, 41, 41, 41, 41, 54, 54}, {4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 5, 5}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::Surfing, {41, 54, 42, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Ravaged Path
        EncounterArea4(78, 0, Game::Blank, Encounter::Grass, {74, 74, 41, 41, 74, 74, 74, 74, 74, 74, 74, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 8, 8, 4, 4}), // Oreburgh Gate 1F
        EncounterArea4(79, 0, Game::Blank, Encounter::Grass, {41, 41, 54, 74, 54, 41, 54, 54, 41, 41, 41, 41}, {8, 8, 8, 9, 9, 9, 8, 10, 10, 10, 10, 10}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::Surfing, {41, 54, 42, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Oreburgh Gate B1F
        EncounterArea4(80, 1, Game::Blank, Encounter::Grass, {400, 400, 397, 397, 55, 55, 358, 358, 400, 397, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 2, Game::Blank, Encounter::Grass, {400, 400, 397, 397, 55, 55, 358, 358, 400, 397, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 3, Game::Blank, Encounter::Grass, {400, 400, 164, 164, 55, 55, 358, 358, 400, 397, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Ruby, Encounter::Grass, {400, 400, 397, 397, 55, 55, 358, 358, 338, 338, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Sapphire, Encounter::Grass, {400, 400, 397, 397, 55, 55, 358, 358, 337, 337, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::Surfing, {55, 55, 55, 55, 55}, {40, 40, 45, 45, 45}, {50, 50, 55, 55, 55}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 10}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Sendoff Spring
        EncounterArea4(81, 0, Game::Blank, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 436, 437, 436, 437}, {45, 46, 45, 46, 46, 45, 44, 44, 44, 46, 44, 46}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::Ruby, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 338, 338, 436, 437}, {45, 46, 45, 46, 46, 45, 44, 44, 44, 46, 44, 46}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::Sapphire, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 337, 337, 436, 437}, {45, 46, 45, 46, 46, 45, 44, 44, 44, 46, 44, 46}), // Turnback Cave Entrance
        EncounterArea4(82, 0, Game::Blank, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 436, 437, 436, 437}, {55, 56, 55, 56, 56, 55, 54, 54, 54, 56, 54, 56}), // Turnback Cave 1st Pillar
        EncounterArea4(82, 0, Game::Ruby, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 338, 338, 436, 437}, {55, 56, 55, 56, 56, 55, 54, 54, 54, 56, 54, 56}), // Turnback Cave 1st Pillar
        EncounterArea4(82, 0, Game::Sapphire, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 337, 337, 436, 437}, {55, 56, 55, 56, 56, 55, 54, 54, 54, 56, 54, 56}), // Turnback Cave 1st Pillar
        EncounterArea4(83, 0, Game::Blank, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 436, 437, 436, 437}, {65, 66, 65, 66, 66, 65, 64, 64, 64, 66, 64, 66}), // Turnback Cave 2nd Pillar
        EncounterArea4(83, 0, Game::Ruby, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 338, 338, 436, 437}, {65, 66, 65, 66, 66, 65, 64, 64, 64, 66, 64, 66}), // Turnback Cave 2nd Pillar
        EncounterArea4(83, 0, Game::Sapphire, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 337, 337, 436, 437}, {65, 66, 65, 66, 66, 65, 64, 64, 64, 66, 64, 66}), // Turnback Cave 2nd Pillar
        EncounterArea4(84, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 95, 215, 208, 95, 42, 95, 42}, {51, 51, 52, 52, 52, 51, 50, 52, 52, 50, 50, 50}), // Snowpoint Temple 1F
        EncounterArea4(85, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 95, 42, 95, 42}, {53, 53, 54, 54, 54, 53, 52, 54, 53, 52, 52, 52}), // Snowpoint Temple B1F
        EncounterArea4(86, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 95, 42, 95, 42}, {53, 53, 54, 54, 54, 53, 52, 54, 53, 52, 52, 52}), // Snowpoint Temple B2F
        EncounterArea4(87, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 95, 42, 95, 42}, {53, 53, 54, 54, 54, 53, 52, 54, 53, 52, 52, 52}), // Snowpoint Temple B3F
        EncounterArea4(88, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 208, 42, 208, 42}, {55, 55, 56, 56, 56, 55, 54, 56, 54, 54, 54, 54}), // Snowpoint Temple B4F
        EncounterArea4(89, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 208, 42, 208, 42}, {55, 55, 56, 56, 56, 55, 54, 56, 54, 54, 54, 54}), // Snowpoint Temple B5F
        EncounterArea4(90, 0, Game::Blank, Encounter::Grass, {436, 41, 74, 41, 436, 41, 436, 436, 74, 41, 74, 41}, {14, 14, 15, 15, 15, 15, 16, 14, 16, 16, 16, 16}), // Wayward Cave
        EncounterArea4(91, 0, Game::Blank, Encounter::Grass, {436, 41, 74, 41, 436, 443, 436, 436, 443, 41, 443, 41}, {15, 15, 16, 16, 16, 15, 15, 17, 16, 17, 17, 17}), // Wayward Cave (Secret)
        EncounterArea4(92, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 74, 74, 74, 74, 449, 74, 449}, {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23}), // Ruin Maniac Cave (< 10 Unown)
        EncounterArea4(93, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 74, 74, 449, 74, 449, 74, 449}, {23, 23, 23, 23, 23, 23, 23, 22, 23, 23, 23, 24}), // Ruin Maniac Cave (> 10 Unown)
        EncounterArea4(94, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 449, 74, 449, 74, 449, 74, 449}, {24, 24, 24, 24, 24, 22, 24, 23, 24, 24, 24, 25}), // Maniac Cave
        EncounterArea4(95, 1, Game::Blank, Encounter::Grass, {397, 315, 172, 172, 315, 402, 25, 172, 25, 172, 25, 172}, {17, 16, 16, 16, 17, 17, 18, 16, 18, 16, 18, 16}), // Trophy Garden
        EncounterArea4(95, 2, Game::Blank, Encounter::Grass, {397, 315, 397, 397, 315, 402, 25, 172, 25, 172, 25, 172}, {17, 16, 16, 16, 17, 17, 18, 16, 18, 16, 18, 16}), // Trophy Garden
        EncounterArea4(95, 3, Game::Blank, Encounter::Grass, {397, 315, 402, 402, 315, 402, 25, 172, 25, 172, 25, 172}, {17, 16, 16, 16, 17, 17, 18, 16, 18, 16, 18, 16}), // Trophy Garden
        EncounterArea4(96, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::SuperRod, {130, 457, 211, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Iron Island
        EncounterArea4(97, 0, Game::Blank, Encounter::Grass, {74, 75, 41, 42, 74, 75, 95, 95, 74, 75, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island 1F
        EncounterArea4(98, 0, Game::Blank, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 75, 75, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B1F
        EncounterArea4(98, 0, Game::Ruby, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 303, 303, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B1F
        EncounterArea4(98, 0, Game::Sapphire, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 302, 302, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B1F
        EncounterArea4(99, 0, Game::Blank, Encounter::Grass, {75, 95, 42, 42, 75, 75, 95, 95, 75, 75, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B2F (Left)
        EncounterArea4(99, 0, Game::Ruby, Encounter::Grass, {75, 95, 42, 42, 75, 75, 95, 95, 303, 303, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B2F (Left)
        EncounterArea4(99, 0, Game::Sapphire, Encounter::Grass, {75, 95, 42, 42, 75, 75, 95, 95, 302, 302, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B2F (Left)
        EncounterArea4(100, 0, Game::Blank, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 75, 75, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B2F (Right)
        EncounterArea4(100, 0, Game::Ruby, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 303, 303, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B2F (Right)
        EncounterArea4(100, 0, Game::Sapphire, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 302, 302, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B2F (Right)
        EncounterArea4(101, 0, Game::Blank, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 75, 75, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B3F
        EncounterArea4(101, 0, Game::Ruby, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 303, 303, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B3F
        EncounterArea4(101, 0, Game::Sapphire, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 302, 302, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B3F
        EncounterArea4(102, 0, Game::Blank, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(102, 0, Game::Ruby, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(102, 0, Game::Sapphire, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(102, 0, Game::Emerald, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(102, 0, Game::FireRed, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(103, 0, Game::Blank, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Ruby, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Sapphire, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Emerald, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::FireRed, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(104, 1, Game::Blank, Encounter::Grass, {203, 74, 397, 75, 400, 203, 402, 397, 400, 75, 400, 75}, {21, 20, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22}), // Valor Lakefront
        EncounterArea4(104, 2, Game::Blank, Encounter::Grass, {203, 74, 397, 75, 400, 203, 402, 397, 400, 75, 400, 75}, {21, 20, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22}), // Valor Lakefront
        EncounterArea4(104, 3, Game::Blank, Encounter::Grass, {203, 74, 402, 402, 400, 203, 402, 397, 400, 75, 400, 75}, {21, 20, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22}), // Valor Lakefront
        EncounterArea4(104, 0, Game::Blank, Encounter::PokeRadar, {203, 74, 397, 75, 30, 30, 402, 397, 400, 75, 33, 33}, {21, 20, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22}), // Valor Lakefront
        EncounterArea4(105, 1, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(105, 2, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(105, 3, Game::Blank, Encounter::Grass, {459, 215, 41, 164, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(105, 0, Game::Emerald, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 216, 216, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(105, 0, Game::Blank, Encounter::PokeRadar, {459, 215, 307, 67, 361, 361, 459, 215, 308, 308, 361, 361}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(106, 1, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 2, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 3, Game::Blank, Encounter::Grass, {396, 399, 399, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Ruby, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 338, 338, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Sapphire, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 337, 337, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Emerald, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 400, 397, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::FireRed, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 400, 397, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 10}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::Swarm, {283, 283, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 396, 399, 202, 202, 396, 399, 396, 399, 202, 202}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(107, 1, Game::Blank, Encounter::Grass, {400, 400, 397, 397, 54, 54, 433, 433, 400, 397, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 2, Game::Blank, Encounter::Grass, {400, 400, 397, 397, 54, 54, 433, 433, 400, 397, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 3, Game::Blank, Encounter::Grass, {400, 400, 164, 164, 54, 54, 433, 433, 400, 397, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Ruby, Encounter::Grass, {400, 400, 397, 397, 54, 54, 433, 433, 338, 338, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Sapphire, Encounter::Grass, {400, 400, 397, 397, 54, 54, 433, 433, 337, 337, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 10}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::Swarm, {108, 108, 397, 397, 54, 54, 433, 433, 400, 397, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::PokeRadar, {400, 400, 397, 397, 202, 202, 433, 433, 400, 397, 202, 202}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(108, 1, Game::Blank, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 400, 215, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 2, Game::Blank, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 400, 215, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 3, Game::Blank, Encounter::Grass, {400, 215, 164, 164, 54, 54, 433, 433, 400, 215, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Ruby, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 338, 338, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Sapphire, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 337, 337, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Emerald, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 217, 217, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 10}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::Swarm, {238, 238, 400, 54, 54, 54, 433, 433, 400, 215, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::PokeRadar, {400, 215, 400, 54, 202, 202, 433, 433, 400, 215, 202, 202}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(109, 0, Game::Blank, Encounter::Surfing, {55, 55, 55, 55, 55}, {40, 40, 45, 45, 45}, {50, 50, 55, 55, 55}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Resort Area
        EncounterArea4(110, 1, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(110, 2, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(110, 3, Game::Blank, Encounter::Grass, {323, 112, 354, 42, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(110, 0, Game::Emerald, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 207, 207, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(110, 0, Game::Blank, Encounter::PokeRadar, {323, 112, 22, 75, 324, 324, 227, 75, 322, 111, 324, 324}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(111, 0, Game::Blank, Encounter::Grass, {75, 219, 42, 67, 219, 110, 95, 323, 74, 218, 74, 218}, {55, 55, 54, 56, 56, 56, 54, 56, 25, 25, 27, 27}), // Stark Mountain Entrance
        EncounterArea4(112, 0, Game::Blank, Encounter::Grass, {75, 219, 42, 67, 219, 110, 95, 323, 74, 218, 74, 218}, {57, 57, 56, 58, 58, 58, 56, 58, 27, 27, 29, 29}), // Stark Mountain Interior
    };

    const QVector<EncounterArea4> encountersPearl
    {
        EncounterArea4(0, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Twinleaf Town
        EncounterArea4(1, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::SuperRod, {130, 341, 340, 342, 342}, {30, 30, 40, 35, 35}, {40, 40, 55, 55, 55}), // Celestic Town
        EncounterArea4(2, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::SuperRod, {130, 457, 120, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Canalave City
        EncounterArea4(3, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Eterna City
        EncounterArea4(4, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::SuperRod, {130, 224, 130, 224, 224}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Pastoria City
        EncounterArea4(5, 0, Game::Blank, Encounter::Surfing, {73, 279, 458, 458, 458}, {35, 35, 30, 30, 35}, {45, 45, 40, 40, 45}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::SuperRod, {130, 224, 120, 224, 224}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Sunyshore City
        EncounterArea4(6, 0, Game::Blank, Encounter::Surfing, {279, 73, 279, 73, 73}, {35, 35, 40, 40, 40}, {40, 40, 45, 45, 45}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::SuperRod, {130, 224, 370, 224, 224}, {30, 30, 20, 20, 20}, {40, 40, 30, 50, 50}), // Pokï¿½mon League
        EncounterArea4(7, 1, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 2, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 3, Game::Blank, Encounter::Grass, {396, 399, 399, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::FireRed, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 58, 58, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::Blank, Encounter::Swarm, {84, 84, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 396, 399, 32, 32, 396, 399, 396, 399, 29, 29}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(8, 1, Game::Blank, Encounter::Grass, {403, 399, 396, 401, 396, 403, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 2, Game::Blank, Encounter::Grass, {403, 399, 396, 396, 396, 403, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 3, Game::Blank, Encounter::Grass, {403, 399, 401, 401, 396, 403, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::FireRed, Encounter::Grass, {403, 399, 396, 401, 396, 403, 396, 399, 58, 58, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::Blank, Encounter::Swarm, {263, 263, 396, 401, 396, 403, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::Blank, Encounter::PokeRadar, {403, 399, 396, 401, 161, 161, 396, 399, 396, 399, 161, 161}, {3, 3, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(9, 1, Game::Blank, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 2, Game::Blank, Encounter::Grass, {396, 403, 396, 396, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 3, Game::Blank, Encounter::Grass, {396, 403, 41, 401, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Ruby, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 273, 273, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Sapphire, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 270, 270, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Emerald, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 204, 204, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::Swarm, {104, 104, 396, 401, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::PokeRadar, {396, 403, 396, 401, 280, 280, 63, 403, 396, 399, 280, 281}, {4, 4, 5, 4, 4, 5, 4, 5, 5, 5, 6, 6}), // Route 203
        EncounterArea4(10, 1, Game::Blank, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 2, Game::Blank, Encounter::Grass, {396, 399, 406, 396, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 3, Game::Blank, Encounter::Grass, {396, 399, 41, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Ruby, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 273, 273, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Sapphire, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 270, 270, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Emerald, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 204, 204, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::FireRed, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 10, 10, 396, 399}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 406, 401, 280, 280, 406, 403, 396, 399, 280, 281}, {4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6}), // Route 204 (South)
        EncounterArea4(11, 1, Game::Blank, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 2, Game::Blank, Encounter::Grass, {396, 399, 406, 396, 406, 403, 406, 403, 396, 399, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 3, Game::Blank, Encounter::Grass, {396, 399, 41, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Ruby, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 273, 273, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Sapphire, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 270, 270, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Emerald, Encounter::Grass, {396, 399, 406, 401, 406, 403, 406, 403, 204, 204, 396, 399}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 406, 401, 191, 191, 406, 403, 396, 399, 191, 191}, {6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8}), // Route 204 (North)
        EncounterArea4(12, 0, Game::Blank, Encounter::Grass, {418, 422, 418, 422, 399, 422, 417, 417, 418, 422, 418, 422}, {8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10}), // Route 205 (South)
        EncounterArea4(12, 0, Game::FireRed, Encounter::Grass, {418, 422, 418, 422, 399, 422, 417, 417, 239, 239, 418, 422}, {8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::PokeRadar, {418, 422, 418, 422, 187, 187, 417, 417, 418, 422, 187, 187}, {8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10}), // Route 205 (South)
        EncounterArea4(13, 0, Game::Blank, Encounter::Grass, {418, 399, 418, 399, 422, 399, 417, 417, 418, 399, 418, 399}, {10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Sapphire, Encounter::Grass, {418, 399, 418, 399, 422, 399, 417, 417, 270, 270, 418, 399}, {10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::PokeRadar, {418, 399, 418, 399, 79, 79, 417, 417, 418, 399, 79, 79}, {10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12}), // Route 205 (North)
        EncounterArea4(14, 1, Game::Blank, Encounter::Grass, {77, 74, 77, 401, 74, 402, 436, 436, 77, 74, 77, 74}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 2, Game::Blank, Encounter::Grass, {77, 74, 77, 77, 74, 402, 436, 436, 77, 74, 77, 74}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 3, Game::Blank, Encounter::Grass, {77, 74, 41, 402, 74, 402, 436, 436, 77, 74, 77, 74}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 0, Game::Emerald, Encounter::Grass, {77, 74, 77, 401, 74, 402, 436, 436, 207, 207, 77, 74}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 0, Game::Blank, Encounter::Swarm, {299, 299, 77, 401, 74, 402, 436, 436, 77, 74, 77, 74}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(14, 0, Game::Blank, Encounter::PokeRadar, {77, 74, 77, 401, 343, 343, 436, 436, 77, 74, 343, 343}, {14, 14, 15, 14, 14, 15, 15, 15, 15, 15, 16, 16}), // Route 206
        EncounterArea4(15, 1, Game::Blank, Encounter::Grass, {66, 74, 66, 401, 74, 74, 74, 74, 66, 74, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 2, Game::Blank, Encounter::Grass, {66, 74, 66, 66, 74, 74, 74, 74, 66, 74, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 3, Game::Blank, Encounter::Grass, {66, 74, 41, 401, 74, 74, 74, 74, 66, 74, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 0, Game::Emerald, Encounter::Grass, {66, 74, 66, 401, 74, 74, 74, 74, 207, 207, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 0, Game::Blank, Encounter::Swarm, {231, 231, 66, 401, 74, 74, 74, 74, 66, 74, 66, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 0, Game::Blank, Encounter::PokeRadar, {66, 74, 66, 401, 234, 234, 74, 74, 66, 74, 234, 234}, {5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7}), // Route 207
        EncounterArea4(16, 1, Game::Blank, Encounter::Grass, {54, 399, 307, 66, 307, 66, 54, 400, 54, 400, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 2, Game::Blank, Encounter::Grass, {54, 399, 307, 66, 307, 66, 54, 400, 54, 400, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 3, Game::Blank, Encounter::Grass, {54, 399, 41, 41, 307, 66, 54, 400, 54, 400, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 0, Game::Ruby, Encounter::Grass, {54, 399, 307, 66, 307, 66, 54, 400, 335, 335, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 0, Game::Sapphire, Encounter::Grass, {54, 399, 307, 66, 307, 66, 54, 400, 336, 336, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::Swarm, {206, 206, 307, 66, 307, 66, 54, 400, 54, 400, 54, 400}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::PokeRadar, {54, 399, 307, 66, 236, 236, 54, 400, 54, 400, 236, 236}, {16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18}), // Route 208
        EncounterArea4(17, 1, Game::Blank, Encounter::Grass, {396, 400, 438, 438, 400, 397, 400, 397, 113, 438, 113, 438}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(17, 2, Game::Blank, Encounter::Grass, {396, 400, 397, 400, 400, 397, 400, 397, 113, 438, 113, 438}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(17, 3, Game::Blank, Encounter::Grass, {396, 400, 92, 41, 400, 397, 400, 397, 113, 438, 113, 438}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::Swarm, {209, 209, 438, 438, 400, 397, 400, 397, 113, 438, 113, 438}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::PokeRadar, {396, 400, 438, 438, 241, 241, 400, 397, 113, 438, 128, 128}, {16, 16, 16, 16, 17, 17, 18, 18, 16, 16, 16, 16}), // Route 209
        EncounterArea4(18, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 41}, {16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18}), // Lost Tower 1F
        EncounterArea4(18, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 41}, {16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18}), // Lost Tower 1F
        EncounterArea4(18, 3, Game::Blank, Encounter::Grass, {92, 41, 200, 200, 92, 41, 92, 41, 92, 41, 92, 41}, {16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18}), // Lost Tower 1F
        EncounterArea4(19, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 41}, {17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19}), // Lost Tower 2F
        EncounterArea4(19, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 41}, {17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19}), // Lost Tower 2F
        EncounterArea4(19, 3, Game::Blank, Encounter::Grass, {92, 41, 200, 200, 92, 41, 92, 41, 92, 41, 92, 41}, {17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19}), // Lost Tower 2F
        EncounterArea4(20, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 42}, {18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 20, 19}), // Lost Tower 3F
        EncounterArea4(20, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 41, 92, 42}, {18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 20, 19}), // Lost Tower 3F
        EncounterArea4(20, 3, Game::Blank, Encounter::Grass, {92, 41, 200, 200, 92, 41, 92, 41, 92, 41, 92, 42}, {18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 20, 19}), // Lost Tower 3F
        EncounterArea4(21, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 42, 92, 42}, {19, 19, 20, 20, 20, 20, 21, 21, 21, 20, 21, 21}), // Lost Tower 4F
        EncounterArea4(21, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 41, 92, 42, 92, 42}, {19, 19, 20, 20, 20, 20, 21, 21, 21, 20, 21, 21}), // Lost Tower 4F
        EncounterArea4(21, 3, Game::Blank, Encounter::Grass, {92, 41, 200, 200, 92, 41, 92, 41, 92, 42, 92, 42}, {19, 19, 20, 20, 20, 20, 21, 21, 21, 20, 21, 21}), // Lost Tower 4F
        EncounterArea4(22, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 42, 92, 42, 92, 42}, {20, 20, 21, 21, 21, 21, 22, 21, 22, 22, 22, 23}), // Lost Tower 5F
        EncounterArea4(22, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 41, 92, 41, 92, 42, 92, 42, 92, 42}, {20, 20, 21, 21, 21, 21, 22, 21, 22, 22, 22, 23}), // Lost Tower 5F
        EncounterArea4(22, 3, Game::Blank, Encounter::Grass, {92, 41, 200, 200, 92, 41, 92, 42, 92, 42, 92, 42}, {20, 20, 21, 21, 21, 21, 22, 21, 22, 22, 22, 23}), // Lost Tower 5F
        EncounterArea4(23, 1, Game::Blank, Encounter::Grass, {77, 74, 438, 438, 74, 402, 77, 77, 113, 438, 113, 438}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 2, Game::Blank, Encounter::Grass, {77, 74, 77, 77, 74, 402, 77, 77, 113, 438, 113, 438}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 3, Game::Blank, Encounter::Grass, {77, 74, 402, 402, 74, 402, 77, 77, 113, 438, 113, 438}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Ruby, Encounter::Grass, {77, 74, 438, 438, 74, 402, 77, 77, 273, 274, 113, 438}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Emerald, Encounter::Grass, {77, 74, 438, 438, 74, 402, 77, 77, 204, 204, 113, 438}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Blank, Encounter::PokeRadar, {77, 74, 438, 438, 241, 241, 77, 77, 113, 438, 128, 128}, {19, 19, 18, 18, 19, 19, 18, 20, 18, 20, 20, 20}), // Route 210 (South)
        EncounterArea4(24, 1, Game::Blank, Encounter::Grass, {54, 400, 307, 66, 307, 66, 67, 307, 67, 307, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 2, Game::Blank, Encounter::Grass, {54, 400, 307, 66, 307, 66, 67, 307, 67, 307, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 3, Game::Blank, Encounter::Grass, {54, 400, 163, 164, 307, 66, 67, 307, 67, 307, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Ruby, Encounter::Grass, {54, 400, 307, 66, 307, 66, 67, 307, 335, 335, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Sapphire, Encounter::Grass, {54, 400, 307, 66, 307, 66, 67, 307, 336, 336, 67, 307}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::PokeRadar, {54, 400, 307, 66, 371, 371, 67, 307, 67, 307, 371, 371}, {25, 24, 24, 25, 25, 26, 26, 25, 26, 26, 26, 26}), // Route 210 (North)
        EncounterArea4(25, 1, Game::Blank, Encounter::Grass, {307, 399, 307, 399, 74, 77, 433, 433, 399, 307, 399, 307}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(25, 2, Game::Blank, Encounter::Grass, {307, 399, 307, 399, 74, 77, 433, 433, 399, 307, 399, 307}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(25, 3, Game::Blank, Encounter::Grass, {307, 399, 41, 163, 74, 77, 433, 433, 399, 307, 399, 307}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(25, 0, Game::Emerald, Encounter::Grass, {307, 399, 307, 399, 74, 77, 433, 433, 216, 216, 399, 307}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(25, 0, Game::Blank, Encounter::PokeRadar, {307, 399, 307, 399, 236, 236, 433, 433, 399, 307, 236, 236}, {13, 13, 12, 14, 13, 13, 13, 13, 12, 14, 12, 14}), // Route 211 (West)
        EncounterArea4(26, 1, Game::Blank, Encounter::Grass, {307, 75, 77, 67, 67, 307, 433, 433, 307, 77, 307, 77}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(26, 2, Game::Blank, Encounter::Grass, {307, 75, 77, 67, 67, 307, 433, 433, 307, 77, 307, 77}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(26, 3, Game::Blank, Encounter::Grass, {307, 75, 41, 164, 67, 307, 433, 433, 307, 77, 307, 77}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(26, 0, Game::Emerald, Encounter::Grass, {307, 75, 77, 67, 67, 307, 433, 433, 216, 216, 307, 77}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(26, 0, Game::Blank, Encounter::PokeRadar, {307, 75, 77, 67, 333, 333, 433, 433, 307, 77, 333, 333}, {27, 27, 26, 28, 27, 28, 27, 28, 28, 27, 28, 28}), // Route 211 (East)
        EncounterArea4(27, 1, Game::Blank, Encounter::Grass, {396, 406, 397, 402, 315, 406, 315, 397, 402, 402, 402, 402}, {16, 16, 17, 17, 16, 16, 17, 18, 17, 17, 18, 18}), // Route 212 (North)
        EncounterArea4(27, 2, Game::Blank, Encounter::Grass, {396, 406, 397, 397, 315, 406, 315, 397, 402, 402, 402, 402}, {16, 16, 17, 17, 16, 16, 17, 18, 17, 17, 18, 18}), // Route 212 (North)
        EncounterArea4(27, 3, Game::Blank, Encounter::Grass, {396, 406, 402, 402, 315, 406, 315, 397, 402, 402, 402, 402}, {16, 16, 17, 17, 16, 16, 17, 18, 17, 17, 18, 18}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::PokeRadar, {396, 406, 397, 402, 235, 235, 315, 397, 402, 402, 235, 235}, {16, 16, 17, 17, 16, 16, 17, 18, 17, 17, 18, 18}), // Route 212 (North)
        EncounterArea4(28, 1, Game::Blank, Encounter::Grass, {194, 400, 315, 400, 402, 315, 315, 194, 400, 194, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 2, Game::Blank, Encounter::Grass, {194, 400, 315, 400, 402, 315, 315, 194, 400, 194, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 3, Game::Blank, Encounter::Grass, {194, 400, 402, 402, 402, 315, 315, 194, 400, 194, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Sapphire, Encounter::Grass, {194, 400, 315, 400, 402, 315, 315, 194, 271, 270, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 0, Game::FireRed, Encounter::Grass, {194, 400, 315, 400, 402, 315, 315, 194, 23, 23, 400, 194}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::PokeRadar, {194, 400, 315, 400, 88, 88, 315, 194, 400, 194, 88, 88}, {18, 18, 19, 19, 18, 18, 20, 18, 20, 18, 20, 18}), // Route 212 (South)
        EncounterArea4(29, 1, Game::Blank, Encounter::Grass, {418, 422, 418, 278, 422, 278, 419, 422, 419, 422, 419, 422}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(29, 2, Game::Blank, Encounter::Grass, {418, 422, 418, 278, 422, 278, 419, 422, 419, 422, 419, 422}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(29, 3, Game::Blank, Encounter::Grass, {418, 422, 418, 422, 422, 278, 419, 422, 419, 422, 419, 422}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::SuperRod, {130, 224, 319, 224, 224}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::Swarm, {359, 359, 418, 278, 422, 278, 419, 422, 419, 422, 419, 422}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::PokeRadar, {418, 422, 418, 278, 277, 277, 419, 422, 419, 422, 277, 277}, {20, 20, 21, 20, 21, 20, 22, 22, 22, 22, 22, 22}), // Route 213
        EncounterArea4(30, 1, Game::Blank, Encounter::Grass, {77, 74, 77, 75, 185, 203, 402, 77, 185, 75, 185, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 2, Game::Blank, Encounter::Grass, {77, 74, 77, 75, 185, 203, 402, 77, 185, 75, 185, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 3, Game::Blank, Encounter::Grass, {77, 74, 402, 402, 185, 203, 402, 77, 185, 75, 185, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 0, Game::Emerald, Encounter::Grass, {77, 74, 77, 75, 185, 203, 402, 77, 207, 207, 185, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::Swarm, {325, 325, 77, 75, 185, 203, 402, 77, 185, 75, 185, 75}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::PokeRadar, {77, 74, 77, 75, 229, 229, 402, 77, 185, 75, 229, 229}, {23, 22, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24}), // Route 214
        EncounterArea4(31, 1, Game::Blank, Encounter::Grass, {77, 74, 77, 74, 63, 402, 64, 64, 74, 64, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 2, Game::Blank, Encounter::Grass, {77, 74, 77, 77, 63, 402, 64, 64, 74, 64, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 3, Game::Blank, Encounter::Grass, {77, 74, 402, 402, 63, 402, 64, 64, 74, 64, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 0, Game::Emerald, Encounter::Grass, {77, 74, 77, 74, 63, 402, 64, 64, 207, 207, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 0, Game::Blank, Encounter::Swarm, {96, 96, 77, 74, 63, 402, 64, 64, 74, 64, 74, 64}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 0, Game::Blank, Encounter::PokeRadar, {77, 74, 77, 74, 229, 229, 64, 64, 74, 64, 229, 229}, {21, 20, 22, 21, 20, 20, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(32, 1, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 307, 67, 459, 215, 75, 75, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 2, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 307, 67, 459, 215, 75, 75, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 3, Game::Blank, Encounter::Grass, {459, 215, 41, 164, 307, 67, 459, 215, 75, 75, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 0, Game::Emerald, Encounter::Grass, {459, 215, 307, 67, 307, 67, 459, 215, 217, 217, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 0, Game::Blank, Encounter::Swarm, {225, 225, 307, 67, 307, 67, 459, 215, 75, 75, 75, 75}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(32, 0, Game::Blank, Encounter::PokeRadar, {459, 215, 307, 67, 361, 361, 459, 215, 75, 75, 361, 361}, {32, 32, 33, 33, 34, 34, 33, 33, 33, 34, 33, 34}), // Route 216
        EncounterArea4(33, 1, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 2, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 3, Game::Blank, Encounter::Grass, {459, 215, 41, 164, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 0, Game::Emerald, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 217, 217, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 0, Game::Blank, Encounter::Swarm, {220, 220, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(33, 0, Game::Blank, Encounter::PokeRadar, {459, 215, 307, 67, 361, 361, 459, 215, 308, 308, 361, 361}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Route 217
        EncounterArea4(34, 0, Game::Blank, Encounter::Grass, {419, 422, 419, 423, 431, 278, 419, 423, 431, 423, 431, 423}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::SuperRod, {130, 457, 130, 457, 457}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::Swarm, {100, 100, 419, 423, 431, 278, 419, 423, 431, 423, 431, 423}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::PokeRadar, {419, 422, 419, 423, 132, 132, 419, 423, 431, 423, 132, 132}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 218
        EncounterArea4(35, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::SuperRod, {130, 457, 366, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 30, 50, 50}), // Route 219
        EncounterArea4(36, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::SuperRod, {130, 170, 457, 171, 171}, {30, 15, 30, 20, 20}, {40, 25, 40, 45, 45}), // Route 220
        EncounterArea4(37, 0, Game::Blank, Encounter::Grass, {419, 423, 315, 422, 185, 278, 419, 423, 185, 423, 185, 423}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::SuperRod, {130, 457, 366, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 30, 50, 50}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::Swarm, {83, 83, 315, 422, 185, 278, 419, 423, 185, 423, 185, 423}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::PokeRadar, {419, 423, 315, 422, 33, 33, 419, 423, 185, 423, 30, 30}, {28, 28, 29, 28, 29, 29, 30, 29, 30, 30, 30, 30}), // Route 221
        EncounterArea4(38, 1, Game::Blank, Encounter::Grass, {419, 431, 441, 441, 432, 278, 419, 423, 432, 423, 432, 423}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(38, 2, Game::Blank, Encounter::Grass, {419, 431, 441, 441, 432, 278, 419, 423, 432, 423, 432, 423}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(38, 3, Game::Blank, Encounter::Grass, {419, 431, 419, 423, 432, 278, 419, 423, 432, 423, 432, 423}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::SuperRod, {130, 224, 319, 224, 224}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::Swarm, {300, 300, 441, 441, 432, 278, 419, 423, 432, 423, 432, 423}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::PokeRadar, {419, 431, 441, 441, 180, 180, 419, 423, 432, 423, 180, 180}, {40, 40, 41, 40, 41, 41, 42, 41, 42, 42, 42, 42}), // Route 222
        EncounterArea4(39, 0, Game::Blank, Encounter::Surfing, {73, 279, 458, 458, 458}, {35, 35, 30, 30, 35}, {45, 45, 40, 40, 45}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::SuperRod, {130, 320, 224, 321, 321}, {30, 30, 40, 35, 35}, {40, 40, 55, 55, 55}), // Route 223
        EncounterArea4(40, 1, Game::Blank, Encounter::Grass, {419, 423, 441, 441, 315, 315, 44, 70, 418, 267, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 2, Game::Blank, Encounter::Grass, {419, 423, 441, 441, 315, 315, 44, 70, 418, 267, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 3, Game::Blank, Encounter::Grass, {419, 423, 419, 423, 315, 315, 44, 70, 418, 267, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 0, Game::Emerald, Encounter::Grass, {419, 423, 441, 441, 315, 315, 44, 70, 213, 213, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::Surfing, {279, 73, 279, 73, 73}, {40, 40, 45, 45, 45}, {50, 50, 55, 55, 55}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::SuperRod, {130, 224, 370, 224, 224}, {30, 30, 20, 20, 20}, {40, 40, 30, 50, 50}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::Swarm, {177, 177, 441, 441, 315, 315, 44, 70, 418, 267, 422, 267}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::PokeRadar, {419, 423, 441, 441, 356, 356, 44, 70, 418, 267, 355, 355}, {53, 53, 54, 52, 52, 54, 53, 53, 23, 23, 23, 23}), // Route 224
        EncounterArea4(41, 1, Game::Blank, Encounter::Grass, {22, 20, 22, 22, 20, 315, 67, 315, 21, 19, 21, 19}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(41, 2, Game::Blank, Encounter::Grass, {22, 20, 22, 22, 20, 315, 67, 315, 21, 19, 21, 19}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(41, 3, Game::Blank, Encounter::Grass, {22, 20, 354, 354, 20, 315, 67, 315, 21, 19, 21, 19}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::Surfing, {55, 61, 55, 55, 55}, {40, 40, 45, 45, 45}, {50, 50, 55, 55, 55}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::GoodRod, {129, 60, 129, 60, 60}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::SuperRod, {130, 61, 130, 61, 61}, {30, 30, 40, 35, 35}, {40, 40, 55, 55, 55}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::Swarm, {296, 296, 22, 22, 20, 315, 67, 315, 21, 19, 21, 19}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::PokeRadar, {22, 20, 22, 22, 57, 57, 67, 315, 21, 19, 56, 56}, {51, 50, 50, 52, 52, 51, 51, 51, 20, 20, 22, 22}), // Route 225
        EncounterArea4(42, 1, Game::Blank, Encounter::Grass, {22, 20, 22, 22, 20, 67, 55, 55, 21, 19, 21, 19}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(42, 2, Game::Blank, Encounter::Grass, {22, 20, 22, 22, 20, 67, 55, 55, 21, 19, 21, 19}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(42, 3, Game::Blank, Encounter::Grass, {22, 20, 354, 354, 20, 67, 55, 55, 21, 19, 21, 19}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::Surfing, {279, 363, 73, 364, 364}, {40, 35, 40, 40, 40}, {55, 45, 55, 55, 55}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::GoodRod, {129, 116, 129, 116, 116}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::SuperRod, {130, 117, 369, 117, 117}, {30, 30, 40, 35, 35}, {40, 40, 50, 55, 55}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::Swarm, {98, 98, 22, 22, 20, 67, 55, 55, 21, 19, 21, 19}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::PokeRadar, {22, 20, 22, 22, 57, 57, 55, 55, 21, 19, 56, 56}, {52, 52, 53, 51, 51, 53, 53, 51, 20, 20, 22, 22}), // Route 226
        EncounterArea4(43, 1, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 2, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 3, Game::Blank, Encounter::Grass, {323, 112, 354, 42, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 0, Game::Emerald, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 207, 207, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::Surfing, {61, 60, 61, 61, 61}, {40, 20, 45, 45, 45}, {50, 30, 55, 55, 55}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::Swarm, {327, 327, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::PokeRadar, {323, 112, 22, 75, 324, 324, 227, 75, 322, 111, 324, 324}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Route 227
        EncounterArea4(44, 1, Game::Blank, Encounter::Grass, {51, 332, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(44, 2, Game::Blank, Encounter::Grass, {51, 332, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(44, 3, Game::Blank, Encounter::Grass, {51, 332, 332, 332, 112, 450, 51, 51, 50, 331, 50, 331}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::Surfing, {61, 60, 61, 61, 61}, {40, 20, 45, 45, 45}, {50, 30, 55, 55, 55}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::Swarm, {374, 374, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::PokeRadar, {51, 332, 450, 112, 329, 329, 51, 51, 50, 331, 328, 328}, {53, 53, 52, 52, 53, 54, 52, 54, 23, 23, 25, 25}), // Route 228
        EncounterArea4(45, 1, Game::Blank, Encounter::Grass, {70, 44, 166, 166, 313, 432, 127, 314, 69, 43, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 2, Game::Blank, Encounter::Grass, {70, 44, 70, 44, 313, 432, 127, 314, 69, 43, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 3, Game::Blank, Encounter::Grass, {70, 44, 168, 168, 313, 432, 127, 314, 69, 43, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Ruby, Encounter::Grass, {70, 44, 166, 166, 313, 432, 127, 314, 274, 274, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Sapphire, Encounter::Grass, {70, 44, 166, 166, 313, 432, 127, 314, 271, 271, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Emerald, Encounter::Grass, {70, 44, 166, 166, 313, 432, 127, 314, 204, 204, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::Surfing, {278, 279, 278, 278, 278}, {40, 45, 45, 45, 45}, {50, 55, 55, 55, 55}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::SuperRod, {130, 130, 130, 130, 130}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::Swarm, {16, 16, 166, 166, 313, 432, 127, 314, 69, 43, 69, 43}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::PokeRadar, {70, 44, 166, 166, 49, 49, 127, 314, 69, 43, 48, 48}, {51, 51, 52, 52, 50, 50, 52, 50, 20, 20, 22, 22}), // Route 229
        EncounterArea4(46, 0, Game::Blank, Encounter::Grass, {70, 44, 55, 269, 69, 43, 419, 423, 419, 419, 69, 43}, {50, 50, 52, 51, 18, 18, 51, 51, 52, 50, 23, 23}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::Surfing, {279, 363, 73, 364, 364}, {40, 35, 40, 40, 40}, {55, 45, 55, 55, 55}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::SuperRod, {130, 320, 224, 321, 321}, {30, 30, 40, 35, 35}, {40, 40, 55, 55, 55}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::Swarm, {222, 222, 55, 269, 69, 43, 419, 423, 419, 419, 69, 43}, {50, 50, 52, 51, 18, 18, 51, 51, 52, 50, 23, 23}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::PokeRadar, {70, 44, 55, 269, 175, 175, 419, 423, 419, 419, 175, 175}, {50, 50, 52, 51, 18, 18, 51, 51, 52, 50, 23, 23}), // Route 230
        EncounterArea4(47, 0, Game::Blank, Encounter::Grass, {74, 74, 41, 41, 74, 74, 95, 95, 74, 74, 74, 74}, {6, 6, 7, 7, 7, 7, 8, 8, 9, 9, 5, 5}), // Oreburgh Mine 1F
        EncounterArea4(48, 0, Game::Blank, Encounter::Grass, {74, 74, 41, 41, 74, 74, 95, 95, 74, 74, 74, 74}, {7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 6, 6}), // Oreburgh Mine B1F
        EncounterArea4(49, 0, Game::Blank, Encounter::Grass, {418, 417, 418, 422, 399, 422, 422, 417, 418, 422, 418, 422}, {7, 7, 8, 8, 8, 7, 9, 8, 9, 9, 9, 9}), // Valley Windworks
        EncounterArea4(49, 0, Game::FireRed, Encounter::Grass, {418, 417, 418, 422, 399, 422, 422, 417, 239, 239, 418, 422}, {7, 7, 8, 8, 8, 7, 9, 8, 9, 9, 9, 9}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 30, 30}, {40, 40, 40, 50, 50}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::Swarm, {309, 309, 418, 422, 399, 422, 422, 417, 418, 422, 418, 422}, {7, 7, 8, 8, 8, 7, 9, 8, 9, 9, 9, 9}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::PokeRadar, {418, 417, 418, 422, 179, 179, 422, 417, 418, 422, 179, 179}, {7, 7, 8, 8, 8, 7, 9, 8, 9, 9, 9, 9}), // Valley Windworks
        EncounterArea4(50, 1, Game::Blank, Encounter::Grass, {265, 268, 265, 406, 427, 406, 427, 406, 406, 427, 269, 269}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 2, Game::Blank, Encounter::Grass, {265, 268, 265, 406, 427, 406, 427, 406, 406, 427, 269, 269}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 3, Game::Blank, Encounter::Grass, {265, 268, 200, 200, 427, 406, 427, 406, 406, 427, 269, 269}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::Ruby, Encounter::Grass, {265, 268, 265, 406, 427, 406, 427, 406, 273, 273, 269, 269}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::Emerald, Encounter::Grass, {265, 268, 265, 406, 427, 406, 427, 406, 204, 204, 269, 269}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::FireRed, Encounter::Grass, {265, 268, 265, 406, 427, 406, 427, 406, 11, 11, 269, 269}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::Blank, Encounter::Swarm, {287, 287, 265, 406, 427, 406, 427, 406, 406, 427, 269, 269}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(50, 0, Game::Blank, Encounter::PokeRadar, {265, 268, 265, 406, 290, 290, 427, 406, 406, 427, 290, 290}, {10, 10, 11, 10, 10, 11, 11, 12, 12, 12, 12, 12}), // Eterna Forest
        EncounterArea4(51, 0, Game::Blank, Encounter::Grass, {419, 422, 403, 278, 404, 423, 417, 417, 419, 423, 419, 423}, {29, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::Swarm, {81, 81, 403, 278, 404, 423, 417, 417, 419, 423, 419, 423}, {29, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::PokeRadar, {419, 422, 403, 278, 187, 187, 417, 417, 419, 423, 188, 188}, {29, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30}), // Fuego Ironworks
        EncounterArea4(52, 1, Game::Blank, Encounter::Grass, {66, 74, 173, 173, 307, 41, 433, 433, 66, 173, 66, 173}, {15, 15, 14, 14, 15, 15, 15, 15, 16, 14, 16, 14}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 2, Game::Blank, Encounter::Grass, {66, 74, 74, 41, 307, 41, 433, 433, 66, 173, 66, 173}, {15, 15, 14, 14, 15, 15, 15, 15, 16, 14, 16, 14}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 3, Game::Blank, Encounter::Grass, {66, 74, 74, 41, 307, 41, 433, 433, 66, 173, 66, 173}, {15, 15, 14, 14, 15, 15, 15, 15, 16, 14, 16, 14}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(53, 1, Game::Blank, Encounter::Grass, {307, 74, 173, 173, 66, 41, 433, 433, 307, 173, 307, 173}, {13, 13, 12, 12, 13, 13, 13, 13, 14, 12, 14, 12}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(53, 2, Game::Blank, Encounter::Grass, {307, 74, 74, 41, 66, 41, 433, 433, 307, 173, 307, 173}, {13, 13, 12, 12, 13, 13, 13, 13, 14, 12, 14, 12}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(53, 3, Game::Blank, Encounter::Grass, {307, 74, 74, 41, 66, 41, 433, 433, 307, 173, 307, 173}, {13, 13, 12, 12, 13, 13, 13, 13, 14, 12, 14, 12}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(54, 0, Game::Blank, Encounter::Grass, {307, 75, 35, 42, 67, 42, 433, 433, 307, 35, 307, 35}, {31, 31, 30, 32, 31, 31, 30, 30, 32, 31, 32, 32}), // Mt. Coronet (Route 216 Entrance)
        EncounterArea4(55, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 436, 35, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 2F
        EncounterArea4(55, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 338, 338, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 2F
        EncounterArea4(55, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 337, 337, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 2F
        EncounterArea4(56, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 436, 35, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 3F
        EncounterArea4(56, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 338, 338, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 3F
        EncounterArea4(56, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 337, 337, 436, 35}, {38, 36, 37, 36, 37, 37, 37, 38, 36, 37, 36, 38}), // Mt. Coronet 3F
        EncounterArea4(57, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 437, 35, 437, 35}, {40, 38, 39, 38, 39, 39, 39, 40, 38, 39, 39, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 338, 338, 437, 35}, {40, 38, 39, 38, 39, 39, 39, 40, 38, 39, 39, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 433, 337, 337, 437, 35}, {40, 38, 39, 38, 39, 39, 39, 40, 38, 39, 39, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::SuperRod, {130, 147, 130, 148, 148}, {30, 15, 40, 15, 15}, {40, 20, 55, 35, 40}), // Mt. Coronet 4F
        EncounterArea4(58, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 358, 437, 35, 437, 35}, {40, 38, 39, 38, 39, 39, 40, 40, 38, 39, 39, 40}), // Mt. Coronet 5F
        EncounterArea4(58, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 358, 338, 338, 437, 35}, {40, 38, 39, 38, 39, 39, 40, 40, 38, 39, 39, 40}), // Mt. Coronet 5F
        EncounterArea4(58, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 433, 358, 337, 337, 437, 35}, {40, 38, 39, 38, 39, 39, 40, 40, 38, 39, 39, 40}), // Mt. Coronet 5F
        EncounterArea4(59, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 437, 35, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 6F
        EncounterArea4(59, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 338, 338, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 6F
        EncounterArea4(59, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 337, 337, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 6F
        EncounterArea4(60, 0, Game::Blank, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 437, 35, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 7F
        EncounterArea4(60, 0, Game::Ruby, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 338, 338, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 7F
        EncounterArea4(60, 0, Game::Sapphire, Encounter::Grass, {437, 75, 67, 35, 308, 42, 358, 358, 337, 337, 437, 35}, {42, 40, 41, 40, 41, 41, 41, 42, 40, 41, 41, 42}), // Mt. Coronet 7F
        EncounterArea4(61, 0, Game::Blank, Encounter::Grass, {307, 75, 35, 42, 67, 42, 433, 433, 307, 35, 307, 35}, {31, 31, 30, 32, 31, 31, 30, 30, 32, 31, 32, 32}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Mt. Coronet B1F
        EncounterArea4(62, 1, Game::Blank, Encounter::Grass, {459, 460, 308, 67, 308, 67, 433, 433, 437, 35, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 2, Game::Blank, Encounter::Grass, {459, 460, 308, 67, 308, 67, 433, 433, 437, 35, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 3, Game::Blank, Encounter::Grass, {459, 460, 42, 164, 308, 67, 433, 433, 437, 35, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Ruby, Encounter::Grass, {459, 460, 308, 67, 308, 67, 433, 433, 338, 338, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Sapphire, Encounter::Grass, {459, 460, 308, 67, 308, 67, 433, 433, 337, 337, 437, 35}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Blank, Encounter::PokeRadar, {459, 460, 308, 67, 294, 294, 433, 433, 437, 35, 294, 294}, {38, 40, 39, 39, 40, 40, 39, 40, 39, 38, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(63, 0, Game::Blank, Encounter::Grass, {75, 75, 67, 35, 308, 42, 433, 433, 437, 35, 437, 35}, {40, 39, 40, 38, 40, 39, 38, 40, 40, 39, 39, 40}), // Mt. Coronet	Top Cave
        EncounterArea4(63, 0, Game::Ruby, Encounter::Grass, {75, 75, 67, 35, 308, 42, 433, 433, 338, 338, 437, 35}, {40, 39, 40, 38, 40, 39, 38, 40, 40, 39, 39, 40}), // Mt. Coronet	Top Cave
        EncounterArea4(63, 0, Game::Sapphire, Encounter::Grass, {75, 75, 67, 35, 308, 42, 433, 433, 337, 337, 437, 35}, {40, 39, 40, 38, 40, 39, 38, 40, 40, 39, 39, 40}), // Mt. Coronet	Top Cave
        EncounterArea4(64, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 1
        EncounterArea4(64, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 1
        EncounterArea4(64, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 164, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 1
        EncounterArea4(65, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 2
        EncounterArea4(65, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 2
        EncounterArea4(65, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 164, 183, 195, 183, 195, 54, 54, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {24, 25, 24, 26, 25, 25, 26, 26, 26, 24, 26, 24}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 2
        EncounterArea4(66, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 3
        EncounterArea4(66, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 3
        EncounterArea4(66, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 3
        EncounterArea4(67, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 4
        EncounterArea4(67, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 4
        EncounterArea4(67, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 183, 195, 183, 195, 54, 54, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {22, 23, 22, 24, 23, 23, 24, 24, 24, 22, 24, 22}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 4
        EncounterArea4(68, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 399, 298, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 5
        EncounterArea4(68, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 399, 298, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 5
        EncounterArea4(68, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 183, 195, 183, 195, 399, 298, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 5
        EncounterArea4(68, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 5
        EncounterArea4(69, 1, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 6
        EncounterArea4(69, 2, Game::Blank, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 54, 54, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 6
        EncounterArea4(69, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 183, 195, 183, 195, 54, 54, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::FireRed, Encounter::Grass, {194, 400, 406, 396, 183, 195, 183, 195, 24, 24, 399, 298}, {20, 21, 20, 22, 21, 21, 22, 22, 22, 20, 22, 20}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::Surfing, {194, 183, 195, 54, 54}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 130, 130}, {15, 15, 10, 15, 15}, {20, 20, 25, 30, 30}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::SuperRod, {340, 318, 130, 318, 318}, {30, 15, 40, 15, 15}, {55, 20, 55, 30, 30}), // Great Marsh Area 6
        EncounterArea4(70, 0, Game::Blank, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {19, 20, 18, 21, 17, 22, 16, 23, 15, 24, 14, 25}), // Solaceon Ruins
        EncounterArea4(71, 0, Game::Blank, Encounter::Grass, {67, 75, 308, 42, 95, 208, 42, 42, 67, 308, 67, 308}, {45, 45, 45, 45, 44, 46, 46, 44, 46, 46, 44, 44}), // Victory Road 1F
        EncounterArea4(72, 0, Game::Blank, Encounter::Grass, {64, 75, 308, 42, 95, 208, 42, 42, 64, 308, 64, 308}, {46, 46, 46, 46, 45, 47, 47, 45, 47, 47, 45, 45}), // Victory Road 2F
        EncounterArea4(73, 0, Game::Blank, Encounter::Grass, {67, 419, 308, 42, 419, 208, 42, 42, 67, 308, 67, 308}, {45, 45, 45, 45, 44, 46, 46, 44, 46, 46, 44, 44}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::Surfing, {42, 42, 42, 42, 42}, {35, 35, 40, 40, 40}, {45, 45, 50, 50, 50}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::SuperRod, {130, 130, 130, 130, 130}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Victory Road B1F
        EncounterArea4(74, 0, Game::Blank, Encounter::Grass, {67, 419, 308, 42, 419, 208, 42, 42, 67, 308, 67, 308}, {51, 51, 51, 51, 50, 52, 52, 50, 52, 52, 50, 50}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::Surfing, {42, 42, 131, 131, 131}, {40, 45, 40, 45, 50}, {50, 55, 50, 55, 60}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::SuperRod, {130, 130, 130, 130, 130}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Victory Road Back Room 1
        EncounterArea4(75, 0, Game::Blank, Encounter::Grass, {67, 75, 308, 42, 95, 208, 42, 42, 67, 308, 67, 308}, {51, 51, 51, 51, 50, 52, 52, 50, 52, 52, 50, 50}), // Victory Road Back Room 2
        EncounterArea4(76, 0, Game::Blank, Encounter::Grass, {67, 75, 308, 42, 95, 208, 42, 42, 67, 308, 67, 308}, {51, 51, 51, 51, 50, 52, 52, 50, 52, 52, 50, 50}), // Victory Road Back Room 3
        EncounterArea4(77, 0, Game::Blank, Encounter::Grass, {41, 41, 74, 74, 41, 41, 41, 41, 41, 41, 54, 54}, {4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 5, 5}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::Surfing, {41, 54, 42, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Ravaged Path
        EncounterArea4(78, 0, Game::Blank, Encounter::Grass, {74, 74, 41, 41, 74, 74, 74, 74, 74, 74, 74, 74}, {5, 5, 6, 6, 6, 6, 7, 7, 8, 8, 4, 4}), // Oreburgh Gate 1F
        EncounterArea4(79, 0, Game::Blank, Encounter::Grass, {41, 41, 54, 74, 54, 41, 54, 54, 41, 41, 41, 41}, {8, 8, 8, 9, 9, 9, 8, 10, 10, 10, 10, 10}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::Surfing, {41, 54, 42, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Oreburgh Gate B1F
        EncounterArea4(80, 1, Game::Blank, Encounter::Grass, {400, 400, 397, 397, 55, 55, 358, 358, 400, 397, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 2, Game::Blank, Encounter::Grass, {400, 400, 397, 397, 55, 55, 358, 358, 400, 397, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 3, Game::Blank, Encounter::Grass, {400, 400, 164, 164, 55, 55, 358, 358, 400, 397, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Ruby, Encounter::Grass, {400, 400, 397, 397, 55, 55, 358, 358, 338, 338, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Sapphire, Encounter::Grass, {400, 400, 397, 397, 55, 55, 358, 358, 337, 337, 400, 397}, {53, 54, 53, 54, 53, 54, 52, 54, 52, 52, 52, 52}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::Surfing, {55, 55, 55, 55, 55}, {40, 40, 45, 45, 45}, {50, 50, 55, 55, 55}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 10}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Sendoff Spring
        EncounterArea4(81, 0, Game::Blank, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 436, 437, 436, 437}, {45, 46, 45, 46, 46, 45, 44, 44, 44, 46, 44, 46}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::Ruby, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 338, 338, 436, 437}, {45, 46, 45, 46, 46, 45, 44, 44, 44, 46, 44, 46}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::Sapphire, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 337, 337, 436, 437}, {45, 46, 45, 46, 46, 45, 44, 44, 44, 46, 44, 46}), // Turnback Cave Entrance
        EncounterArea4(82, 0, Game::Blank, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 436, 437, 436, 437}, {55, 56, 55, 56, 56, 55, 54, 54, 54, 56, 54, 56}), // Turnback Cave 1st Pillar
        EncounterArea4(82, 0, Game::Ruby, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 338, 338, 436, 437}, {55, 56, 55, 56, 56, 55, 54, 54, 54, 56, 54, 56}), // Turnback Cave 1st Pillar
        EncounterArea4(82, 0, Game::Sapphire, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 337, 337, 436, 437}, {55, 56, 55, 56, 56, 55, 54, 54, 54, 56, 54, 56}), // Turnback Cave 1st Pillar
        EncounterArea4(83, 0, Game::Blank, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 436, 437, 436, 437}, {65, 66, 65, 66, 66, 65, 64, 64, 64, 66, 64, 66}), // Turnback Cave 2nd Pillar
        EncounterArea4(83, 0, Game::Ruby, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 338, 338, 436, 437}, {65, 66, 65, 66, 66, 65, 64, 64, 64, 66, 64, 66}), // Turnback Cave 2nd Pillar
        EncounterArea4(83, 0, Game::Sapphire, Encounter::Grass, {42, 437, 93, 42, 93, 437, 93, 93, 337, 337, 436, 437}, {65, 66, 65, 66, 66, 65, 64, 64, 64, 66, 64, 66}), // Turnback Cave 2nd Pillar
        EncounterArea4(84, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 95, 215, 208, 95, 42, 95, 42}, {51, 51, 52, 52, 52, 51, 50, 52, 52, 50, 50, 50}), // Snowpoint Temple 1F
        EncounterArea4(85, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 95, 42, 95, 42}, {53, 53, 54, 54, 54, 53, 52, 54, 53, 52, 52, 52}), // Snowpoint Temple B1F
        EncounterArea4(86, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 95, 42, 95, 42}, {53, 53, 54, 54, 54, 53, 52, 54, 53, 52, 52, 52}), // Snowpoint Temple B2F
        EncounterArea4(87, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 95, 42, 95, 42}, {53, 53, 54, 54, 54, 53, 52, 54, 53, 52, 52, 52}), // Snowpoint Temple B3F
        EncounterArea4(88, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 208, 42, 208, 42}, {55, 55, 56, 56, 56, 55, 54, 56, 54, 54, 54, 54}), // Snowpoint Temple B4F
        EncounterArea4(89, 0, Game::Blank, Encounter::Grass, {42, 215, 75, 42, 215, 208, 215, 208, 208, 42, 208, 42}, {55, 55, 56, 56, 56, 55, 54, 56, 54, 54, 54, 54}), // Snowpoint Temple B5F
        EncounterArea4(90, 0, Game::Blank, Encounter::Grass, {436, 41, 74, 41, 436, 41, 436, 436, 74, 41, 74, 41}, {14, 14, 15, 15, 15, 15, 16, 14, 16, 16, 16, 16}), // Wayward Cave
        EncounterArea4(91, 0, Game::Blank, Encounter::Grass, {436, 41, 74, 41, 436, 443, 436, 436, 443, 41, 443, 41}, {15, 15, 16, 16, 16, 15, 15, 17, 16, 17, 17, 17}), // Wayward Cave (Secret)
        EncounterArea4(92, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 74, 74, 74, 74, 449, 74, 449}, {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23}), // Ruin Maniac Cave (< 10 Unown)
        EncounterArea4(93, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 74, 74, 449, 74, 449, 74, 449}, {23, 23, 23, 23, 23, 23, 23, 22, 23, 23, 23, 24}), // Ruin Maniac Cave (> 10 Unown)
        EncounterArea4(94, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 449, 74, 449, 74, 449, 74, 449}, {24, 24, 24, 24, 24, 22, 24, 23, 24, 24, 24, 25}), // Maniac Cave
        EncounterArea4(95, 1, Game::Blank, Encounter::Grass, {397, 315, 172, 172, 315, 402, 25, 172, 25, 172, 25, 172}, {17, 16, 16, 16, 17, 17, 18, 16, 18, 16, 18, 16}), // Trophy Garden
        EncounterArea4(95, 2, Game::Blank, Encounter::Grass, {397, 315, 397, 397, 315, 402, 25, 172, 25, 172, 25, 172}, {17, 16, 16, 16, 17, 17, 18, 16, 18, 16, 18, 16}), // Trophy Garden
        EncounterArea4(95, 3, Game::Blank, Encounter::Grass, {397, 315, 402, 402, 315, 402, 25, 172, 25, 172, 25, 172}, {17, 16, 16, 16, 17, 17, 18, 16, 18, 16, 18, 16}), // Trophy Garden
        EncounterArea4(96, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 279, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::SuperRod, {130, 457, 211, 457, 457}, {30, 30, 20, 20, 20}, {40, 40, 40, 50, 50}), // Iron Island
        EncounterArea4(97, 0, Game::Blank, Encounter::Grass, {74, 75, 41, 42, 74, 75, 95, 95, 74, 75, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island 1F
        EncounterArea4(98, 0, Game::Blank, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 75, 75, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B1F
        EncounterArea4(98, 0, Game::Ruby, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 303, 303, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B1F
        EncounterArea4(98, 0, Game::Sapphire, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 302, 302, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B1F
        EncounterArea4(99, 0, Game::Blank, Encounter::Grass, {75, 95, 42, 42, 75, 75, 95, 95, 75, 75, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B2F (Left)
        EncounterArea4(99, 0, Game::Ruby, Encounter::Grass, {75, 95, 42, 42, 75, 75, 95, 95, 303, 303, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B2F (Left)
        EncounterArea4(99, 0, Game::Sapphire, Encounter::Grass, {75, 95, 42, 42, 75, 75, 95, 95, 302, 302, 74, 75}, {30, 31, 30, 31, 29, 32, 32, 33, 31, 33, 31, 33}), // Iron Island B2F (Left)
        EncounterArea4(100, 0, Game::Blank, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 75, 75, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B2F (Right)
        EncounterArea4(100, 0, Game::Ruby, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 303, 303, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B2F (Right)
        EncounterArea4(100, 0, Game::Sapphire, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 302, 302, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B2F (Right)
        EncounterArea4(101, 0, Game::Blank, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 75, 75, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B3F
        EncounterArea4(101, 0, Game::Ruby, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 303, 303, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B3F
        EncounterArea4(101, 0, Game::Sapphire, Encounter::Grass, {75, 95, 42, 42, 75, 95, 208, 208, 302, 302, 74, 75}, {31, 32, 31, 32, 30, 33, 33, 34, 32, 34, 32, 34}), // Iron Island B3F
        EncounterArea4(102, 0, Game::Blank, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(102, 0, Game::Ruby, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(102, 0, Game::Sapphire, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(102, 0, Game::Emerald, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(102, 0, Game::FireRed, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau
        EncounterArea4(103, 0, Game::Blank, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Ruby, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Sapphire, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Emerald, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::FireRed, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 93, 92, 92}, {12, 12, 14, 14, 13, 13, 13, 13, 16, 16, 15, 15}), // Old Chateau Room 5
        EncounterArea4(104, 1, Game::Blank, Encounter::Grass, {203, 74, 397, 75, 400, 203, 402, 397, 400, 75, 400, 75}, {21, 20, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22}), // Valor Lakefront
        EncounterArea4(104, 2, Game::Blank, Encounter::Grass, {203, 74, 397, 75, 400, 203, 402, 397, 400, 75, 400, 75}, {21, 20, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22}), // Valor Lakefront
        EncounterArea4(104, 3, Game::Blank, Encounter::Grass, {203, 74, 402, 402, 400, 203, 402, 397, 400, 75, 400, 75}, {21, 20, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22}), // Valor Lakefront
        EncounterArea4(104, 0, Game::Blank, Encounter::PokeRadar, {203, 74, 397, 75, 33, 33, 402, 397, 400, 75, 30, 30}, {21, 20, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22}), // Valor Lakefront
        EncounterArea4(105, 1, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(105, 2, Game::Blank, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(105, 3, Game::Blank, Encounter::Grass, {459, 215, 41, 164, 308, 67, 459, 215, 308, 308, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(105, 0, Game::Emerald, Encounter::Grass, {459, 215, 307, 67, 308, 67, 459, 215, 216, 216, 308, 308}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(105, 0, Game::Blank, Encounter::PokeRadar, {459, 215, 307, 67, 361, 361, 459, 215, 308, 308, 361, 361}, {34, 34, 35, 35, 35, 36, 35, 35, 36, 36, 36, 36}), // Acuity Lakefront
        EncounterArea4(106, 1, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 2, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 3, Game::Blank, Encounter::Grass, {396, 399, 399, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Ruby, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 338, 338, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Sapphire, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 337, 337, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Emerald, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 400, 397, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::FireRed, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 400, 397, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 10}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::Swarm, {283, 283, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 396, 399, 202, 202, 396, 399, 396, 399, 202, 202}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(107, 1, Game::Blank, Encounter::Grass, {400, 400, 397, 397, 54, 54, 433, 433, 400, 397, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 2, Game::Blank, Encounter::Grass, {400, 400, 397, 397, 54, 54, 433, 433, 400, 397, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 3, Game::Blank, Encounter::Grass, {400, 400, 164, 164, 54, 54, 433, 433, 400, 397, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Ruby, Encounter::Grass, {400, 400, 397, 397, 54, 54, 433, 433, 338, 338, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Sapphire, Encounter::Grass, {400, 400, 397, 397, 54, 54, 433, 433, 337, 337, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 10}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::Swarm, {108, 108, 397, 397, 54, 54, 433, 433, 400, 397, 400, 397}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::PokeRadar, {400, 400, 397, 397, 202, 202, 433, 433, 400, 397, 202, 202}, {34, 36, 34, 36, 35, 36, 35, 36, 35, 35, 35, 35}), // Lake Valor
        EncounterArea4(108, 1, Game::Blank, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 400, 215, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 2, Game::Blank, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 400, 215, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 3, Game::Blank, Encounter::Grass, {400, 215, 164, 164, 54, 54, 433, 433, 400, 215, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Ruby, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 338, 338, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Sapphire, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 337, 337, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Emerald, Encounter::Grass, {400, 215, 400, 54, 54, 54, 433, 433, 217, 217, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 30, 30, 20}, {30, 40, 40, 40, 40}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 10}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::Swarm, {238, 238, 400, 54, 54, 54, 433, 433, 400, 215, 400, 215}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::PokeRadar, {400, 215, 400, 54, 202, 202, 433, 433, 400, 215, 202, 202}, {35, 35, 34, 36, 34, 35, 34, 36, 34, 36, 34, 36}), // Lake Acuity
        EncounterArea4(109, 0, Game::Blank, Encounter::Surfing, {55, 55, 55, 55, 55}, {40, 40, 45, 45, 45}, {50, 50, 55, 55, 55}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 10}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 20, 20}, {40, 40, 55, 50, 50}), // Resort Area
        EncounterArea4(110, 1, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(110, 2, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(110, 3, Game::Blank, Encounter::Grass, {323, 112, 354, 42, 22, 110, 227, 75, 322, 111, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(110, 0, Game::Emerald, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 207, 207, 322, 111}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(110, 0, Game::Blank, Encounter::PokeRadar, {323, 112, 22, 75, 324, 324, 227, 75, 322, 111, 324, 324}, {55, 55, 54, 54, 55, 55, 56, 56, 22, 22, 24, 24}), // Stark Mountain
        EncounterArea4(111, 0, Game::Blank, Encounter::Grass, {75, 219, 42, 67, 219, 110, 95, 323, 74, 218, 74, 218}, {55, 55, 54, 56, 56, 56, 54, 56, 25, 25, 27, 27}), // Stark Mountain Entrance
        EncounterArea4(112, 0, Game::Blank, Encounter::Grass, {75, 219, 42, 67, 219, 110, 95, 323, 74, 218, 74, 218}, {57, 57, 56, 58, 58, 58, 56, 58, 27, 27, 29, 29}), // Stark Mountain Interior
    };

    const QVector<EncounterArea4> encountersPlatinum
    {
        EncounterArea4(0, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Twinleaf Town
        EncounterArea4(0, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Twinleaf Town
        EncounterArea4(1, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Celestic Town
        EncounterArea4(1, 0, Game::Blank, Encounter::SuperRod, {130, 341, 342, 119, 119}, {30, 30, 40, 40, 40}, {55, 40, 55, 55, 55}), // Celestic Town
        EncounterArea4(2, 0, Game::Blank, Encounter::Surfing, {72, 422, 73, 73, 423}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Canalave City
        EncounterArea4(2, 0, Game::Blank, Encounter::SuperRod, {130, 457, 120, 457, 457}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Canalave City
        EncounterArea4(3, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Eterna City
        EncounterArea4(3, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Eterna City
        EncounterArea4(4, 0, Game::Blank, Encounter::Surfing, {72, 422, 73, 278, 423}, {20, 20, 20, 20, 20}, {30, 30, 40, 30, 40}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Pastoria City
        EncounterArea4(4, 0, Game::Blank, Encounter::SuperRod, {130, 224, 130, 224, 224}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Pastoria City
        EncounterArea4(5, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 73, 279}, {30, 30, 30, 30, 30}, {40, 40, 50, 50, 50}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Sunyshore City
        EncounterArea4(5, 0, Game::Blank, Encounter::SuperRod, {130, 224, 120, 224, 224}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Sunyshore City
        EncounterArea4(6, 0, Game::Blank, Encounter::Surfing, {278, 279, 279, 73, 73}, {30, 30, 30, 30, 30}, {40, 50, 50, 50, 50}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Pokï¿½mon League
        EncounterArea4(6, 0, Game::Blank, Encounter::SuperRod, {130, 224, 370, 224, 224}, {30, 30, 20, 40, 40}, {55, 40, 30, 55, 55}), // Pokï¿½mon League
        EncounterArea4(7, 1, Game::Blank, Encounter::Grass, {396, 399, 396, 401, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 2, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 3, Game::Blank, Encounter::Grass, {396, 399, 401, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::FireRed, Encounter::Grass, {396, 399, 396, 401, 396, 399, 396, 399, 58, 58, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::Blank, Encounter::Swarm, {84, 84, 396, 401, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(7, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 396, 401, 32, 29, 396, 399, 396, 399, 32, 29}, {2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}), // Route 201
        EncounterArea4(8, 1, Game::Blank, Encounter::Grass, {403, 399, 396, 401, 403, 399, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 4, 3, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 2, Game::Blank, Encounter::Grass, {403, 399, 396, 399, 403, 399, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 4, 3, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 3, Game::Blank, Encounter::Grass, {403, 399, 401, 399, 403, 399, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 4, 3, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::FireRed, Encounter::Grass, {403, 399, 396, 401, 403, 399, 396, 399, 58, 58, 396, 399}, {3, 3, 4, 3, 4, 3, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::Blank, Encounter::Swarm, {263, 263, 396, 401, 403, 399, 396, 399, 396, 399, 396, 399}, {3, 3, 4, 3, 4, 3, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(8, 0, Game::Blank, Encounter::PokeRadar, {403, 399, 396, 401, 161, 161, 396, 399, 396, 399, 161, 161}, {3, 3, 4, 3, 4, 3, 4, 4, 2, 2, 2, 2}), // Route 202
        EncounterArea4(9, 1, Game::Blank, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 5, 4, 5, 5, 6, 6, 7, 7}), // Route 203
        EncounterArea4(9, 2, Game::Blank, Encounter::Grass, {396, 403, 396, 399, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 5, 4, 5, 5, 6, 6, 7, 7}), // Route 203
        EncounterArea4(9, 3, Game::Blank, Encounter::Grass, {396, 403, 401, 41, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 5, 4, 5, 5, 6, 6, 7, 7}), // Route 203
        EncounterArea4(9, 0, Game::Ruby, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 273, 273, 396, 399}, {4, 4, 5, 4, 5, 4, 5, 5, 6, 6, 7, 7}), // Route 203
        EncounterArea4(9, 0, Game::Sapphire, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 270, 270, 396, 399}, {4, 4, 5, 4, 5, 4, 5, 5, 6, 6, 7, 7}), // Route 203
        EncounterArea4(9, 0, Game::Emerald, Encounter::Grass, {396, 403, 396, 401, 399, 63, 63, 403, 204, 204, 396, 399}, {4, 4, 5, 4, 5, 4, 5, 5, 6, 6, 7, 7}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 203
        EncounterArea4(9, 0, Game::Blank, Encounter::Swarm, {104, 104, 396, 401, 399, 63, 63, 403, 396, 399, 396, 399}, {4, 4, 5, 4, 5, 4, 5, 5, 6, 6, 7, 7}), // Route 203
        EncounterArea4(10, 1, Game::Blank, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 3, 4, 4, 5, 5, 5, 5, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 2, Game::Blank, Encounter::Grass, {396, 399, 265, 406, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 3, 4, 4, 5, 5, 5, 5, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 3, Game::Blank, Encounter::Grass, {396, 399, 401, 41, 406, 403, 406, 403, 396, 399, 396, 399}, {4, 4, 4, 3, 4, 4, 5, 5, 5, 5, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Ruby, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 273, 273, 396, 399}, {4, 4, 4, 3, 4, 4, 5, 5, 5, 5, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Sapphire, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 270, 270, 396, 399}, {4, 4, 4, 3, 4, 4, 5, 5, 5, 5, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Emerald, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 204, 204, 396, 399}, {4, 4, 4, 3, 4, 4, 5, 5, 5, 5, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::FireRed, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 10, 10, 396, 399}, {4, 4, 4, 3, 4, 4, 5, 5, 5, 5, 6, 6}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 204 (South)
        EncounterArea4(10, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 204 (South)
        EncounterArea4(11, 1, Game::Blank, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 396, 399, 396, 399}, {9, 9, 9, 8, 9, 9, 10, 10, 10, 10, 11, 11}), // Route 204 (North)
        EncounterArea4(11, 2, Game::Blank, Encounter::Grass, {396, 399, 265, 406, 406, 403, 406, 403, 396, 399, 396, 399}, {9, 9, 9, 8, 9, 9, 10, 10, 10, 10, 11, 11}), // Route 204 (North)
        EncounterArea4(11, 3, Game::Blank, Encounter::Grass, {396, 399, 401, 41, 406, 403, 406, 403, 396, 399, 396, 399}, {9, 9, 9, 8, 9, 9, 10, 10, 10, 10, 11, 11}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Ruby, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 273, 273, 396, 399}, {9, 9, 9, 8, 9, 9, 10, 10, 10, 10, 11, 11}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Sapphire, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 270, 270, 396, 399}, {9, 9, 9, 8, 9, 9, 10, 10, 10, 10, 11, 11}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Emerald, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 204, 204, 396, 399}, {9, 9, 9, 8, 9, 9, 10, 10, 10, 10, 11, 11}), // Route 204 (North)
        EncounterArea4(11, 0, Game::FireRed, Encounter::Grass, {396, 399, 265, 401, 406, 403, 406, 403, 10, 10, 396, 399}, {9, 9, 9, 8, 9, 9, 10, 10, 10, 10, 11, 11}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 204 (North)
        EncounterArea4(11, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 265, 401, 191, 191, 406, 403, 396, 399, 191, 191}, {9, 9, 9, 8, 9, 9, 10, 10, 10, 10, 11, 11}), // Route 204 (North)
        EncounterArea4(12, 0, Game::Blank, Encounter::Grass, {422, 422, 418, 422, 399, 422, 417, 417, 418, 422, 418, 422}, {10, 11, 10, 9, 10, 11, 9, 11, 11, 12, 11, 12}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::Surfing, {422, 72, 423, 423, 73}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Route 205 (South)
        EncounterArea4(12, 0, Game::Blank, Encounter::PokeRadar, {422, 422, 418, 422, 187, 187, 417, 417, 418, 422, 187, 187}, {10, 11, 10, 9, 10, 11, 9, 11, 11, 12, 11, 12}), // Route 205 (South)
        EncounterArea4(13, 1, Game::Blank, Encounter::Grass, {399, 406, 265, 401, 266, 268, 399, 399, 406, 406, 267, 269}, {12, 12, 13, 12, 14, 14, 13, 14, 13, 14, 15, 15}), // Route 205 (North)
        EncounterArea4(13, 2, Game::Blank, Encounter::Grass, {399, 406, 265, 406, 266, 268, 399, 399, 406, 406, 267, 269}, {12, 12, 13, 12, 14, 14, 13, 14, 13, 14, 15, 15}), // Route 205 (North)
        EncounterArea4(13, 3, Game::Blank, Encounter::Grass, {399, 406, 401, 163, 266, 268, 399, 399, 406, 406, 267, 269}, {12, 12, 13, 12, 14, 14, 13, 14, 13, 14, 15, 15}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Sapphire, Encounter::Grass, {399, 406, 265, 401, 266, 268, 399, 399, 270, 270, 267, 269}, {12, 12, 13, 12, 14, 14, 13, 14, 13, 14, 15, 15}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 205 (North)
        EncounterArea4(13, 0, Game::Blank, Encounter::PokeRadar, {399, 406, 265, 401, 79, 79, 399, 399, 406, 406, 79, 79}, {12, 12, 13, 12, 14, 14, 13, 14, 13, 14, 15, 15}), // Route 205 (North)
        EncounterArea4(14, 1, Game::Blank, Encounter::Grass, {77, 74, 207, 402, 207, 66, 66, 74, 66, 74, 66, 74}, {16, 16, 18, 17, 16, 17, 18, 18, 19, 18, 19, 18}), // Route 206
        EncounterArea4(14, 2, Game::Blank, Encounter::Grass, {77, 74, 207, 77, 207, 66, 66, 74, 66, 74, 66, 74}, {16, 16, 18, 17, 16, 17, 18, 18, 19, 18, 19, 18}), // Route 206
        EncounterArea4(14, 3, Game::Blank, Encounter::Grass, {77, 74, 402, 41, 207, 66, 66, 74, 66, 74, 66, 74}, {16, 16, 18, 17, 16, 17, 18, 18, 19, 18, 19, 18}), // Route 206
        EncounterArea4(14, 0, Game::Blank, Encounter::Swarm, {246, 246, 207, 402, 207, 66, 66, 74, 66, 74, 66, 74}, {16, 16, 18, 17, 16, 17, 18, 18, 19, 18, 19, 18}), // Route 206
        EncounterArea4(14, 0, Game::Blank, Encounter::PokeRadar, {77, 74, 207, 402, 343, 343, 66, 74, 66, 74, 343, 343}, {16, 16, 18, 17, 16, 17, 18, 18, 19, 18, 19, 18}), // Route 206
        EncounterArea4(15, 1, Game::Blank, Encounter::Grass, {66, 74, 77, 401, 77, 66, 66, 74, 77, 74, 77, 74}, {7, 5, 6, 5, 5, 6, 8, 6, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 2, Game::Blank, Encounter::Grass, {66, 74, 77, 66, 77, 66, 66, 74, 77, 74, 77, 74}, {7, 5, 6, 5, 5, 6, 8, 6, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 3, Game::Blank, Encounter::Grass, {66, 74, 401, 41, 77, 66, 66, 74, 77, 74, 77, 74}, {7, 5, 6, 5, 5, 6, 8, 6, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 0, Game::Blank, Encounter::Swarm, {231, 231, 77, 401, 77, 66, 66, 74, 77, 74, 77, 74}, {7, 5, 6, 5, 5, 6, 8, 6, 7, 7, 7, 7}), // Route 207
        EncounterArea4(15, 0, Game::Blank, Encounter::PokeRadar, {66, 74, 77, 401, 234, 234, 66, 74, 77, 74, 234, 234}, {7, 5, 6, 5, 5, 6, 8, 6, 7, 7, 7, 7}), // Route 207
        EncounterArea4(16, 1, Game::Blank, Encounter::Grass, {406, 399, 406, 280, 315, 400, 280, 400, 315, 400, 315, 400}, {18, 18, 19, 17, 19, 18, 18, 19, 20, 20, 20, 20}), // Route 208
        EncounterArea4(16, 2, Game::Blank, Encounter::Grass, {406, 399, 406, 280, 315, 400, 280, 400, 315, 400, 315, 400}, {18, 18, 19, 17, 19, 18, 18, 19, 20, 20, 20, 20}), // Route 208
        EncounterArea4(16, 3, Game::Blank, Encounter::Grass, {406, 399, 41, 280, 315, 400, 280, 400, 315, 400, 315, 400}, {18, 18, 19, 17, 19, 18, 18, 19, 20, 20, 20, 20}), // Route 208
        EncounterArea4(16, 0, Game::Ruby, Encounter::Grass, {406, 399, 406, 280, 315, 400, 280, 400, 335, 335, 315, 400}, {18, 18, 19, 17, 19, 18, 18, 19, 20, 20, 20, 20}), // Route 208
        EncounterArea4(16, 0, Game::Sapphire, Encounter::Grass, {406, 399, 406, 280, 315, 400, 280, 400, 336, 336, 315, 400}, {18, 18, 19, 17, 19, 18, 18, 19, 20, 20, 20, 20}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {20, 20, 40, 40, 40}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::Swarm, {206, 206, 406, 280, 315, 400, 280, 400, 315, 400, 315, 400}, {18, 18, 19, 17, 19, 18, 18, 19, 20, 20, 20, 20}), // Route 208
        EncounterArea4(16, 0, Game::Blank, Encounter::PokeRadar, {406, 399, 406, 280, 235, 235, 280, 400, 315, 400, 235, 235}, {18, 18, 19, 17, 19, 18, 18, 19, 20, 20, 20, 20}), // Route 208
        EncounterArea4(17, 1, Game::Blank, Encounter::Grass, {315, 400, 397, 280, 397, 400, 280, 315, 280, 113, 280, 113}, {19, 18, 19, 17, 18, 19, 18, 20, 19, 17, 19, 19}), // Route 209
        EncounterArea4(17, 2, Game::Blank, Encounter::Grass, {315, 400, 397, 280, 397, 400, 280, 315, 280, 113, 280, 113}, {19, 18, 19, 17, 18, 19, 18, 20, 19, 17, 19, 19}), // Route 209
        EncounterArea4(17, 3, Game::Blank, Encounter::Grass, {315, 400, 41, 355, 397, 400, 280, 315, 280, 113, 280, 113}, {19, 18, 19, 17, 18, 19, 18, 20, 19, 17, 19, 19}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::Swarm, {209, 209, 397, 280, 397, 400, 280, 315, 280, 113, 280, 113}, {19, 18, 19, 17, 18, 19, 18, 20, 19, 17, 19, 19}), // Route 209
        EncounterArea4(17, 0, Game::Blank, Encounter::PokeRadar, {315, 400, 397, 280, 281, 281, 280, 315, 280, 113, 281, 281}, {19, 18, 19, 17, 18, 19, 18, 20, 19, 17, 19, 19}), // Route 209
        EncounterArea4(18, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 92, 92, 92, 92, 92}, {18, 17, 19, 17, 18, 17, 19, 20, 20, 20, 20, 20}), // Lost Tower 1F
        EncounterArea4(18, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 92, 92, 92, 92, 92}, {18, 17, 19, 17, 18, 17, 19, 20, 20, 20, 20, 20}), // Lost Tower 1F
        EncounterArea4(18, 3, Game::Blank, Encounter::Grass, {92, 41, 355, 355, 41, 92, 41, 92, 92, 92, 92, 92}, {18, 17, 19, 17, 18, 17, 19, 20, 20, 20, 20, 20}), // Lost Tower 1F
        EncounterArea4(19, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 92, 92, 92, 92, 92}, {18, 17, 19, 17, 18, 17, 19, 20, 20, 20, 20, 20}), // Lost Tower 2F
        EncounterArea4(19, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 92, 92, 92, 92, 92}, {18, 17, 19, 17, 18, 17, 19, 20, 20, 20, 20, 20}), // Lost Tower 2F
        EncounterArea4(19, 3, Game::Blank, Encounter::Grass, {92, 41, 355, 355, 41, 92, 41, 92, 92, 92, 92, 92}, {18, 17, 19, 17, 18, 17, 19, 20, 20, 20, 20, 20}), // Lost Tower 2F
        EncounterArea4(20, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 92, 92, 92, 92, 42}, {19, 18, 20, 18, 19, 18, 20, 21, 21, 21, 21, 21}), // Lost Tower 3F
        EncounterArea4(20, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 92, 92, 92, 92, 42}, {19, 18, 20, 18, 19, 18, 20, 21, 21, 21, 21, 21}), // Lost Tower 3F
        EncounterArea4(20, 3, Game::Blank, Encounter::Grass, {92, 41, 355, 355, 41, 92, 41, 92, 92, 92, 92, 42}, {19, 18, 20, 18, 19, 18, 20, 21, 21, 21, 21, 21}), // Lost Tower 3F
        EncounterArea4(21, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 92, 92, 42, 92, 42}, {19, 18, 20, 18, 19, 18, 20, 21, 21, 21, 21, 21}), // Lost Tower 4F
        EncounterArea4(21, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 92, 92, 42, 92, 42}, {19, 18, 20, 18, 19, 18, 20, 21, 21, 21, 21, 21}), // Lost Tower 4F
        EncounterArea4(21, 3, Game::Blank, Encounter::Grass, {92, 41, 355, 355, 41, 92, 41, 92, 92, 42, 92, 42}, {19, 18, 20, 18, 19, 18, 20, 21, 21, 21, 21, 21}), // Lost Tower 4F
        EncounterArea4(22, 1, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 42, 92, 42, 92, 42}, {20, 19, 21, 19, 20, 19, 21, 22, 22, 22, 22, 22}), // Lost Tower 5F
        EncounterArea4(22, 2, Game::Blank, Encounter::Grass, {92, 41, 92, 92, 41, 92, 41, 42, 92, 42, 92, 42}, {20, 19, 21, 19, 20, 19, 21, 22, 22, 22, 22, 22}), // Lost Tower 5F
        EncounterArea4(22, 3, Game::Blank, Encounter::Grass, {92, 41, 355, 355, 41, 92, 41, 42, 92, 42, 92, 42}, {20, 19, 21, 19, 20, 19, 21, 22, 22, 22, 22, 22}), // Lost Tower 5F
        EncounterArea4(23, 1, Game::Blank, Encounter::Grass, {397, 74, 123, 77, 315, 77, 123, 315, 77, 113, 77, 113}, {19, 18, 21, 20, 20, 19, 19, 21, 21, 19, 21, 21}), // Route 210 (South)
        EncounterArea4(23, 2, Game::Blank, Encounter::Grass, {397, 74, 77, 77, 315, 77, 123, 315, 77, 113, 77, 113}, {19, 18, 21, 20, 20, 19, 19, 21, 21, 19, 21, 21}), // Route 210 (South)
        EncounterArea4(23, 3, Game::Blank, Encounter::Grass, {397, 74, 164, 163, 315, 77, 123, 315, 77, 113, 77, 113}, {19, 18, 21, 20, 20, 19, 19, 21, 21, 19, 21, 21}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Ruby, Encounter::Grass, {397, 74, 123, 77, 315, 77, 123, 315, 273, 274, 77, 113}, {19, 18, 21, 20, 20, 19, 19, 21, 21, 19, 21, 21}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Emerald, Encounter::Grass, {397, 74, 123, 77, 315, 77, 123, 315, 204, 204, 77, 113}, {19, 18, 21, 20, 20, 19, 19, 21, 21, 19, 21, 21}), // Route 210 (South)
        EncounterArea4(23, 0, Game::Blank, Encounter::PokeRadar, {397, 74, 123, 77, 241, 128, 123, 315, 77, 113, 241, 128}, {19, 18, 21, 20, 20, 19, 19, 21, 21, 19, 21, 21}), // Route 210 (South)
        EncounterArea4(24, 1, Game::Blank, Encounter::Grass, {333, 400, 123, 307, 307, 66, 123, 67, 66, 67, 66, 67}, {27, 28, 27, 27, 29, 28, 29, 29, 29, 30, 29, 30}), // Route 210 (North)
        EncounterArea4(24, 2, Game::Blank, Encounter::Grass, {333, 400, 333, 307, 307, 66, 123, 67, 66, 67, 66, 67}, {27, 28, 27, 27, 29, 28, 29, 29, 29, 30, 29, 30}), // Route 210 (North)
        EncounterArea4(24, 3, Game::Blank, Encounter::Grass, {333, 400, 164, 163, 307, 66, 123, 67, 66, 67, 66, 67}, {27, 28, 27, 27, 29, 28, 29, 29, 29, 30, 29, 30}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Ruby, Encounter::Grass, {333, 400, 123, 307, 307, 66, 123, 67, 335, 335, 66, 67}, {27, 28, 27, 27, 29, 28, 29, 29, 29, 30, 29, 30}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Sapphire, Encounter::Grass, {333, 400, 123, 307, 307, 66, 123, 67, 336, 336, 66, 67}, {27, 28, 27, 27, 29, 28, 29, 29, 29, 30, 29, 30}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 340, 340}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 210 (North)
        EncounterArea4(24, 0, Game::Blank, Encounter::PokeRadar, {333, 400, 123, 307, 371, 371, 123, 67, 66, 67, 371, 371}, {27, 28, 27, 27, 29, 28, 29, 29, 29, 30, 29, 30}), // Route 210 (North)
        EncounterArea4(25, 1, Game::Blank, Encounter::Grass, {307, 399, 307, 307, 433, 66, 433, 436, 66, 436, 66, 436}, {13, 14, 14, 15, 14, 14, 16, 14, 15, 16, 15, 16}), // Route 211 (West)
        EncounterArea4(25, 2, Game::Blank, Encounter::Grass, {307, 399, 307, 307, 433, 66, 433, 436, 66, 436, 66, 436}, {13, 14, 14, 15, 14, 14, 16, 14, 15, 16, 15, 16}), // Route 211 (West)
        EncounterArea4(25, 3, Game::Blank, Encounter::Grass, {307, 399, 41, 163, 433, 66, 433, 436, 66, 436, 66, 436}, {13, 14, 14, 15, 14, 14, 16, 14, 15, 16, 15, 16}), // Route 211 (West)
        EncounterArea4(25, 0, Game::Emerald, Encounter::Grass, {307, 399, 307, 307, 433, 66, 433, 436, 216, 216, 66, 436}, {13, 14, 14, 15, 14, 14, 16, 14, 15, 16, 15, 16}), // Route 211 (West)
        EncounterArea4(25, 0, Game::Blank, Encounter::PokeRadar, {307, 399, 307, 307, 236, 236, 433, 436, 66, 436, 236, 236}, {13, 14, 14, 15, 14, 14, 16, 14, 15, 16, 15, 16}), // Route 211 (West)
        EncounterArea4(26, 1, Game::Blank, Encounter::Grass, {307, 75, 307, 307, 433, 67, 433, 436, 67, 436, 67, 436}, {27, 28, 28, 29, 28, 29, 30, 29, 30, 29, 30, 29}), // Route 211 (East)
        EncounterArea4(26, 2, Game::Blank, Encounter::Grass, {307, 75, 307, 307, 433, 67, 433, 436, 67, 436, 67, 436}, {27, 28, 28, 29, 28, 29, 30, 29, 30, 29, 30, 29}), // Route 211 (East)
        EncounterArea4(26, 3, Game::Blank, Encounter::Grass, {307, 75, 41, 164, 433, 67, 433, 436, 67, 436, 67, 436}, {27, 28, 28, 29, 28, 29, 30, 29, 30, 29, 30, 29}), // Route 211 (East)
        EncounterArea4(27, 1, Game::Blank, Encounter::Grass, {315, 183, 397, 281, 315, 397, 281, 281, 315, 183, 315, 183}, {23, 21, 23, 22, 22, 21, 24, 24, 24, 23, 24, 23}), // Route 212 (North)
        EncounterArea4(27, 2, Game::Blank, Encounter::Grass, {315, 183, 397, 280, 315, 397, 281, 281, 315, 183, 315, 183}, {23, 21, 23, 22, 22, 21, 24, 24, 24, 23, 24, 23}), // Route 212 (North)
        EncounterArea4(27, 3, Game::Blank, Encounter::Grass, {315, 183, 183, 183, 315, 397, 281, 281, 315, 183, 315, 183}, {23, 21, 23, 22, 22, 21, 24, 24, 24, 23, 24, 23}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 212 (North)
        EncounterArea4(27, 0, Game::Blank, Encounter::PokeRadar, {315, 183, 397, 281, 235, 235, 281, 281, 315, 183, 235, 235}, {23, 21, 23, 22, 22, 21, 24, 24, 24, 23, 24, 23}), // Route 212 (North)
        EncounterArea4(28, 0, Game::Blank, Encounter::Grass, {422, 195, 418, 422, 195, 422, 453, 453, 418, 422, 418, 422}, {23, 24, 25, 24, 26, 25, 24, 25, 23, 26, 23, 26}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Sapphire, Encounter::Grass, {422, 195, 418, 422, 195, 422, 453, 453, 271, 270, 418, 422}, {23, 24, 25, 24, 26, 25, 24, 25, 23, 26, 23, 26}), // Route 212 (South)
        EncounterArea4(28, 0, Game::FireRed, Encounter::Grass, {422, 195, 418, 422, 195, 422, 453, 453, 23, 23, 418, 422}, {23, 24, 25, 24, 26, 25, 24, 25, 23, 26, 23, 26}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::Surfing, {422, 72, 423, 423, 73}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::SuperRod, {130, 224, 130, 224, 224}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 212 (South)
        EncounterArea4(28, 0, Game::Blank, Encounter::PokeRadar, {422, 195, 418, 422, 88, 88, 453, 453, 418, 422, 88, 88}, {23, 24, 25, 24, 26, 25, 24, 25, 23, 26, 23, 26}), // Route 212 (South)
        EncounterArea4(29, 1, Game::Blank, Encounter::Grass, {422, 418, 441, 441, 278, 422, 278, 278, 418, 422, 418, 422}, {24, 23, 23, 25, 25, 25, 24, 26, 25, 26, 25, 26}), // Route 213
        EncounterArea4(29, 2, Game::Blank, Encounter::Grass, {422, 418, 441, 441, 278, 422, 278, 278, 418, 422, 418, 422}, {24, 23, 23, 25, 25, 25, 24, 26, 25, 26, 25, 26}), // Route 213
        EncounterArea4(29, 3, Game::Blank, Encounter::Grass, {422, 418, 422, 418, 278, 422, 278, 278, 418, 422, 418, 422}, {24, 23, 23, 25, 25, 25, 24, 26, 25, 26, 25, 26}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 422, 423}, {20, 20, 20, 20, 20}, {30, 30, 40, 30, 40}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::SuperRod, {130, 224, 130, 224, 224}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 213
        EncounterArea4(29, 0, Game::Blank, Encounter::PokeRadar, {422, 418, 441, 441, 277, 277, 278, 278, 418, 422, 277, 277}, {24, 23, 23, 25, 25, 25, 24, 26, 25, 26, 25, 26}), // Route 213
        EncounterArea4(30, 1, Game::Blank, Encounter::Grass, {75, 74, 75, 111, 228, 111, 75, 111, 228, 111, 228, 111}, {23, 21, 22, 22, 23, 23, 24, 21, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 2, Game::Blank, Encounter::Grass, {75, 74, 75, 111, 228, 111, 75, 111, 228, 111, 228, 111}, {23, 21, 22, 22, 23, 23, 24, 21, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 3, Game::Blank, Encounter::Grass, {75, 74, 228, 41, 228, 111, 75, 111, 228, 111, 228, 111}, {23, 21, 22, 22, 23, 23, 24, 21, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::Swarm, {325, 325, 75, 111, 228, 111, 75, 111, 228, 111, 228, 111}, {23, 21, 22, 22, 23, 23, 24, 21, 24, 24, 24, 24}), // Route 214
        EncounterArea4(30, 0, Game::Blank, Encounter::PokeRadar, {75, 74, 75, 111, 261, 261, 75, 111, 228, 111, 261, 261}, {23, 21, 22, 22, 23, 23, 24, 21, 24, 24, 24, 24}), // Route 214
        EncounterArea4(31, 1, Game::Blank, Encounter::Grass, {397, 183, 123, 397, 108, 63, 123, 64, 183, 64, 183, 64}, {19, 20, 22, 21, 20, 19, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 2, Game::Blank, Encounter::Grass, {397, 183, 397, 397, 108, 63, 123, 64, 183, 64, 183, 64}, {19, 20, 22, 21, 20, 19, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 3, Game::Blank, Encounter::Grass, {397, 183, 183, 183, 108, 63, 123, 64, 183, 64, 183, 64}, {19, 20, 22, 21, 20, 19, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(31, 0, Game::Blank, Encounter::Swarm, {96, 96, 123, 397, 108, 63, 123, 64, 183, 64, 183, 64}, {19, 20, 22, 21, 20, 19, 20, 21, 22, 22, 22, 22}), // Route 215
        EncounterArea4(32, 1, Game::Blank, Encounter::Grass, {459, 215, 307, 459, 307, 215, 459, 215, 75, 459, 75, 459}, {32, 33, 32, 33, 33, 34, 34, 35, 35, 35, 35, 35}), // Route 216
        EncounterArea4(32, 2, Game::Blank, Encounter::Grass, {459, 215, 307, 459, 307, 215, 459, 215, 75, 459, 75, 459}, {32, 33, 32, 33, 33, 34, 34, 35, 35, 35, 35, 35}), // Route 216
        EncounterArea4(32, 3, Game::Blank, Encounter::Grass, {459, 215, 41, 361, 307, 215, 459, 215, 75, 459, 75, 459}, {32, 33, 32, 33, 33, 34, 34, 35, 35, 35, 35, 35}), // Route 216
        EncounterArea4(32, 0, Game::Emerald, Encounter::Grass, {459, 215, 307, 459, 307, 215, 459, 215, 217, 217, 75, 459}, {32, 33, 32, 33, 33, 34, 34, 35, 35, 35, 35, 35}), // Route 216
        EncounterArea4(33, 1, Game::Blank, Encounter::Grass, {459, 220, 215, 459, 215, 220, 459, 220, 215, 459, 215, 459}, {32, 33, 33, 33, 34, 34, 34, 32, 35, 35, 35, 35}), // Route 217
        EncounterArea4(33, 2, Game::Blank, Encounter::Grass, {459, 220, 215, 459, 215, 220, 459, 220, 215, 459, 215, 459}, {32, 33, 33, 33, 34, 34, 34, 32, 35, 35, 35, 35}), // Route 217
        EncounterArea4(33, 3, Game::Blank, Encounter::Grass, {459, 220, 361, 361, 215, 220, 459, 220, 215, 459, 215, 459}, {32, 33, 33, 33, 34, 34, 34, 32, 35, 35, 35, 35}), // Route 217
        EncounterArea4(33, 0, Game::Emerald, Encounter::Grass, {459, 220, 215, 459, 215, 220, 459, 220, 217, 217, 215, 459}, {32, 33, 33, 33, 34, 34, 34, 32, 35, 35, 35, 35}), // Route 217
        EncounterArea4(33, 0, Game::Blank, Encounter::Swarm, {225, 225, 215, 459, 215, 220, 459, 220, 215, 459, 215, 459}, {32, 33, 33, 33, 34, 34, 34, 32, 35, 35, 35, 35}), // Route 217
        EncounterArea4(33, 0, Game::Blank, Encounter::PokeRadar, {459, 220, 215, 459, 221, 221, 459, 220, 215, 459, 221, 221}, {32, 33, 33, 33, 34, 34, 34, 32, 35, 35, 35, 35}), // Route 217
        EncounterArea4(34, 1, Game::Blank, Encounter::Grass, {423, 419, 441, 441, 122, 122, 419, 122, 419, 423, 419, 423}, {28, 29, 28, 30, 29, 30, 30, 31, 31, 30, 31, 30}), // Route 218
        EncounterArea4(34, 2, Game::Blank, Encounter::Grass, {423, 419, 441, 441, 122, 122, 419, 122, 419, 423, 419, 423}, {28, 29, 28, 30, 29, 30, 30, 31, 31, 30, 31, 30}), // Route 218
        EncounterArea4(34, 3, Game::Blank, Encounter::Grass, {423, 419, 423, 419, 122, 122, 419, 122, 419, 423, 419, 423}, {28, 29, 28, 30, 29, 30, 30, 31, 31, 30, 31, 30}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::Surfing, {72, 422, 73, 73, 423}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::SuperRod, {130, 457, 130, 457, 457}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 218
        EncounterArea4(34, 0, Game::Blank, Encounter::Swarm, {100, 100, 441, 441, 122, 122, 419, 122, 419, 423, 419, 423}, {28, 29, 28, 30, 29, 30, 30, 31, 31, 30, 31, 30}), // Route 218
        EncounterArea4(35, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 73, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 457, 457}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Route 219
        EncounterArea4(35, 0, Game::Blank, Encounter::SuperRod, {130, 457, 130, 457, 457}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 219
        EncounterArea4(36, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 73, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 457, 457}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Route 220
        EncounterArea4(36, 0, Game::Blank, Encounter::SuperRod, {130, 457, 170, 457, 457}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Route 220
        EncounterArea4(37, 1, Game::Blank, Encounter::Grass, {419, 203, 315, 315, 185, 185, 203, 185, 419, 315, 419, 315}, {29, 28, 28, 29, 31, 30, 30, 29, 31, 30, 31, 30}), // Route 221
        EncounterArea4(37, 2, Game::Blank, Encounter::Grass, {419, 203, 315, 315, 185, 185, 203, 185, 419, 315, 419, 315}, {29, 28, 28, 29, 31, 30, 30, 29, 31, 30, 31, 30}), // Route 221
        EncounterArea4(37, 3, Game::Blank, Encounter::Grass, {419, 203, 419, 315, 185, 185, 203, 185, 419, 315, 419, 315}, {29, 28, 28, 29, 31, 30, 30, 29, 31, 30, 31, 30}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 73, 279}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 457, 457}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::SuperRod, {130, 457, 130, 457, 457}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::Swarm, {83, 83, 315, 315, 185, 185, 203, 185, 419, 315, 419, 315}, {29, 28, 28, 29, 31, 30, 30, 29, 31, 30, 31, 30}), // Route 221
        EncounterArea4(37, 0, Game::Blank, Encounter::PokeRadar, {419, 203, 315, 315, 33, 30, 203, 185, 419, 315, 33, 30}, {29, 28, 28, 29, 31, 30, 30, 29, 31, 30, 31, 30}), // Route 221
        EncounterArea4(38, 1, Game::Blank, Encounter::Grass, {125, 419, 125, 441, 278, 81, 404, 404, 279, 82, 279, 82}, {39, 40, 41, 38, 38, 39, 38, 40, 40, 41, 40, 41}), // Route 222
        EncounterArea4(38, 2, Game::Blank, Encounter::Grass, {125, 419, 125, 441, 278, 81, 404, 404, 279, 82, 279, 82}, {39, 40, 41, 38, 38, 39, 38, 40, 40, 41, 40, 41}), // Route 222
        EncounterArea4(38, 3, Game::Blank, Encounter::Grass, {125, 419, 419, 419, 278, 81, 404, 404, 279, 82, 279, 82}, {39, 40, 41, 38, 38, 39, 38, 40, 40, 41, 40, 41}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::Surfing, {72, 278, 73, 73, 279}, {30, 30, 30, 30, 30}, {40, 40, 50, 50, 50}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::SuperRod, {130, 224, 130, 224, 224}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::Swarm, {300, 300, 125, 441, 278, 81, 404, 404, 279, 82, 279, 82}, {39, 40, 41, 38, 38, 39, 38, 40, 40, 41, 40, 41}), // Route 222
        EncounterArea4(38, 0, Game::Blank, Encounter::PokeRadar, {125, 419, 125, 441, 180, 180, 404, 404, 279, 82, 180, 180}, {39, 40, 41, 38, 38, 39, 38, 40, 40, 41, 40, 41}), // Route 222
        EncounterArea4(39, 0, Game::Blank, Encounter::Surfing, {73, 279, 458, 458, 458}, {30, 30, 30, 30, 30}, {50, 50, 40, 40, 40}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 224, 224}, {15, 15, 10, 25, 25}, {20, 25, 25, 35, 35}), // Route 223
        EncounterArea4(39, 0, Game::Blank, Encounter::SuperRod, {130, 320, 224, 321, 321}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Route 223
        EncounterArea4(40, 1, Game::Blank, Encounter::Grass, {419, 315, 69, 69, 279, 423, 44, 70, 267, 269, 267, 269}, {50, 50, 49, 49, 51, 49, 51, 51, 52, 52, 52, 52}), // Route 224
        EncounterArea4(40, 2, Game::Blank, Encounter::Grass, {419, 315, 69, 69, 279, 423, 44, 70, 267, 269, 267, 269}, {50, 50, 49, 49, 51, 49, 51, 51, 52, 52, 52, 52}), // Route 224
        EncounterArea4(40, 3, Game::Blank, Encounter::Grass, {419, 315, 43, 43, 279, 423, 44, 70, 267, 269, 267, 269}, {50, 50, 49, 49, 51, 49, 51, 51, 52, 52, 52, 52}), // Route 224
        EncounterArea4(40, 0, Game::Emerald, Encounter::Grass, {419, 315, 69, 69, 279, 423, 44, 70, 213, 213, 267, 269}, {50, 50, 49, 49, 51, 49, 51, 51, 52, 52, 52, 52}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::Surfing, {279, 73, 423, 423, 423}, {35, 35, 35, 35, 35}, {55, 55, 55, 55, 55}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 25, 25, 25, 25}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::SuperRod, {130, 224, 370, 224, 224}, {30, 30, 20, 40, 40}, {55, 40, 30, 55, 55}), // Route 224
        EncounterArea4(40, 0, Game::Blank, Encounter::Swarm, {177, 177, 69, 69, 279, 423, 44, 70, 267, 269, 267, 269}, {50, 50, 49, 49, 51, 49, 51, 51, 52, 52, 52, 52}), // Route 224
        EncounterArea4(41, 1, Game::Blank, Encounter::Grass, {67, 75, 22, 22, 22, 20, 67, 20, 21, 19, 21, 19}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 225
        EncounterArea4(41, 2, Game::Blank, Encounter::Grass, {67, 75, 22, 22, 22, 20, 67, 20, 21, 19, 21, 19}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 225
        EncounterArea4(41, 3, Game::Blank, Encounter::Grass, {67, 75, 354, 354, 22, 20, 67, 20, 21, 19, 21, 19}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::Surfing, {55, 55, 54, 54, 54}, {35, 35, 35, 35, 35}, {55, 55, 45, 45, 45}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::Swarm, {296, 296, 22, 22, 22, 20, 67, 20, 21, 19, 21, 19}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 225
        EncounterArea4(41, 0, Game::Blank, Encounter::PokeRadar, {67, 75, 22, 22, 57, 57, 67, 20, 21, 19, 56, 56}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 225
        EncounterArea4(42, 1, Game::Blank, Encounter::Grass, {67, 75, 22, 22, 278, 20, 67, 20, 278, 19, 278, 19}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 226
        EncounterArea4(42, 2, Game::Blank, Encounter::Grass, {67, 75, 22, 22, 278, 20, 67, 20, 278, 19, 278, 19}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 226
        EncounterArea4(42, 3, Game::Blank, Encounter::Grass, {67, 75, 354, 354, 278, 20, 67, 20, 278, 19, 278, 19}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::Surfing, {278, 279, 73, 73, 73}, {35, 35, 35, 35, 35}, {45, 55, 55, 55, 55}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::GoodRod, {129, 116, 129, 116, 116}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::SuperRod, {130, 117, 369, 117, 117}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::Swarm, {98, 98, 22, 22, 278, 20, 67, 20, 278, 19, 278, 19}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 226
        EncounterArea4(42, 0, Game::Blank, Encounter::PokeRadar, {67, 75, 22, 22, 57, 57, 67, 20, 278, 19, 56, 56}, {48, 49, 48, 50, 49, 50, 50, 49, 47, 47, 47, 47}), // Route 226
        EncounterArea4(43, 1, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Route 227
        EncounterArea4(43, 2, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Route 227
        EncounterArea4(43, 3, Game::Blank, Encounter::Grass, {323, 112, 42, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::Surfing, {61, 60, 61, 61, 61}, {35, 35, 35, 35, 35}, {55, 45, 55, 55, 55}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::Swarm, {327, 327, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Route 227
        EncounterArea4(43, 0, Game::Blank, Encounter::PokeRadar, {323, 112, 22, 75, 324, 324, 227, 75, 322, 111, 324, 324}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Route 227
        EncounterArea4(44, 1, Game::Blank, Encounter::Grass, {51, 332, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {51, 52, 50, 50, 52, 51, 52, 50, 49, 50, 49, 50}), // Route 228
        EncounterArea4(44, 2, Game::Blank, Encounter::Grass, {51, 332, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {51, 52, 50, 50, 52, 51, 52, 50, 49, 50, 49, 50}), // Route 228
        EncounterArea4(44, 3, Game::Blank, Encounter::Grass, {51, 332, 332, 332, 112, 450, 51, 51, 50, 331, 50, 331}, {51, 52, 50, 50, 52, 51, 52, 50, 49, 50, 49, 50}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::Surfing, {61, 60, 61, 61, 61}, {35, 35, 35, 35, 35}, {55, 45, 55, 55, 55}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 340, 340}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 228
        EncounterArea4(44, 0, Game::Blank, Encounter::Swarm, {374, 374, 450, 112, 112, 450, 51, 51, 50, 331, 50, 331}, {51, 52, 50, 50, 52, 51, 52, 50, 49, 50, 49, 50}), // Route 228
        EncounterArea4(45, 1, Game::Blank, Encounter::Grass, {315, 315, 166, 166, 313, 314, 16, 315, 267, 269, 267, 269}, {48, 49, 50, 50, 49, 49, 47, 50, 48, 48, 48, 48}), // Route 229
        EncounterArea4(45, 2, Game::Blank, Encounter::Grass, {315, 315, 16, 16, 313, 314, 16, 315, 267, 269, 267, 269}, {48, 49, 50, 50, 49, 49, 47, 50, 48, 48, 48, 48}), // Route 229
        EncounterArea4(45, 3, Game::Blank, Encounter::Grass, {315, 315, 168, 168, 313, 314, 16, 315, 267, 269, 267, 269}, {48, 49, 50, 50, 49, 49, 47, 50, 48, 48, 48, 48}), // Route 229
        EncounterArea4(45, 0, Game::Ruby, Encounter::Grass, {315, 315, 166, 166, 313, 314, 16, 315, 274, 274, 267, 269}, {48, 49, 50, 50, 49, 49, 47, 50, 48, 48, 48, 48}), // Route 229
        EncounterArea4(45, 0, Game::Sapphire, Encounter::Grass, {315, 315, 166, 166, 313, 314, 16, 315, 271, 271, 267, 269}, {48, 49, 50, 50, 49, 49, 47, 50, 48, 48, 48, 48}), // Route 229
        EncounterArea4(45, 0, Game::Emerald, Encounter::Grass, {315, 315, 166, 166, 313, 314, 16, 315, 204, 204, 267, 269}, {48, 49, 50, 50, 49, 49, 47, 50, 48, 48, 48, 48}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::Surfing, {283, 283, 283, 284, 284}, {35, 35, 35, 35, 35}, {45, 45, 45, 55, 55}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::Swarm, {127, 127, 166, 166, 313, 314, 16, 315, 267, 269, 267, 269}, {48, 49, 50, 50, 49, 49, 47, 50, 48, 48, 48, 48}), // Route 229
        EncounterArea4(45, 0, Game::Blank, Encounter::PokeRadar, {315, 315, 166, 166, 49, 49, 16, 315, 267, 269, 48, 48}, {48, 49, 50, 50, 49, 49, 47, 50, 48, 48, 48, 48}), // Route 229
        EncounterArea4(46, 1, Game::Blank, Encounter::Grass, {279, 419, 69, 69, 315, 279, 44, 70, 278, 419, 278, 419}, {48, 48, 47, 47, 49, 50, 49, 49, 48, 50, 48, 50}), // Route 230
        EncounterArea4(46, 2, Game::Blank, Encounter::Grass, {279, 419, 69, 69, 315, 279, 44, 70, 278, 419, 278, 419}, {48, 48, 47, 47, 49, 50, 49, 49, 48, 50, 48, 50}), // Route 230
        EncounterArea4(46, 3, Game::Blank, Encounter::Grass, {279, 419, 43, 43, 315, 279, 44, 70, 278, 419, 278, 419}, {48, 48, 47, 47, 49, 50, 49, 49, 48, 50, 48, 50}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::Surfing, {364, 279, 73, 73, 73}, {35, 35, 35, 35, 35}, {55, 55, 55, 55, 55}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::GoodRod, {129, 223, 129, 223, 223}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::SuperRod, {130, 320, 224, 321, 321}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::Swarm, {222, 222, 69, 69, 315, 279, 44, 70, 278, 419, 278, 419}, {48, 48, 47, 47, 49, 50, 49, 49, 48, 50, 48, 50}), // Route 230
        EncounterArea4(46, 0, Game::Blank, Encounter::PokeRadar, {279, 419, 69, 69, 175, 175, 44, 70, 278, 419, 175, 175}, {48, 48, 47, 47, 49, 50, 49, 49, 48, 50, 48, 50}), // Route 230
        EncounterArea4(47, 0, Game::Blank, Encounter::Grass, {74, 74, 41, 41, 74, 74, 95, 95, 74, 41, 74, 41}, {5, 6, 5, 6, 4, 7, 6, 8, 8, 7, 8, 7}), // Oreburgh Mine 1F
        EncounterArea4(48, 0, Game::Blank, Encounter::Grass, {74, 74, 41, 41, 74, 74, 95, 95, 74, 41, 74, 41}, {6, 7, 6, 7, 5, 8, 7, 9, 9, 8, 9, 8}), // Oreburgh Mine B1F
        EncounterArea4(49, 0, Game::Blank, Encounter::Grass, {422, 403, 418, 422, 418, 422, 417, 417, 418, 422, 418, 422}, {9, 10, 9, 10, 10, 11, 9, 11, 11, 12, 11, 12}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::Surfing, {422, 72, 423, 423, 73}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::Swarm, {309, 309, 418, 422, 418, 422, 417, 417, 418, 422, 418, 422}, {9, 10, 9, 10, 10, 11, 9, 11, 11, 12, 11, 12}), // Valley Windworks
        EncounterArea4(49, 0, Game::Blank, Encounter::PokeRadar, {422, 403, 418, 422, 179, 179, 417, 417, 418, 422, 179, 179}, {9, 10, 9, 10, 10, 11, 9, 11, 11, 12, 11, 12}), // Valley Windworks
        EncounterArea4(50, 1, Game::Blank, Encounter::Grass, {427, 406, 265, 401, 406, 399, 266, 268, 427, 92, 267, 269}, {11, 10, 10, 12, 11, 12, 12, 12, 13, 13, 14, 14}), // Eterna Forest
        EncounterArea4(50, 2, Game::Blank, Encounter::Grass, {427, 406, 265, 406, 406, 399, 266, 268, 427, 92, 267, 269}, {11, 10, 10, 12, 11, 12, 12, 12, 13, 13, 14, 14}), // Eterna Forest
        EncounterArea4(50, 3, Game::Blank, Encounter::Grass, {427, 406, 401, 163, 406, 399, 266, 268, 427, 92, 267, 269}, {11, 10, 10, 12, 11, 12, 12, 12, 13, 13, 14, 14}), // Eterna Forest
        EncounterArea4(50, 0, Game::Ruby, Encounter::Grass, {427, 406, 265, 401, 406, 399, 266, 268, 273, 273, 267, 269}, {11, 10, 10, 12, 11, 12, 12, 12, 13, 13, 14, 14}), // Eterna Forest
        EncounterArea4(50, 0, Game::Emerald, Encounter::Grass, {427, 406, 265, 401, 406, 399, 266, 268, 204, 204, 267, 269}, {11, 10, 10, 12, 11, 12, 12, 12, 13, 13, 14, 14}), // Eterna Forest
        EncounterArea4(50, 0, Game::FireRed, Encounter::Grass, {427, 406, 265, 401, 406, 399, 266, 268, 10, 11, 267, 269}, {11, 10, 10, 12, 11, 12, 12, 12, 13, 13, 14, 14}), // Eterna Forest
        EncounterArea4(50, 0, Game::Blank, Encounter::Swarm, {287, 287, 265, 401, 406, 399, 266, 268, 427, 92, 267, 269}, {11, 10, 10, 12, 11, 12, 12, 12, 13, 13, 14, 14}), // Eterna Forest
        EncounterArea4(50, 0, Game::Blank, Encounter::PokeRadar, {427, 406, 265, 401, 290, 290, 266, 268, 427, 92, 290, 290}, {11, 10, 10, 12, 11, 12, 12, 12, 13, 13, 14, 14}), // Eterna Forest
        EncounterArea4(51, 1, Game::Blank, Encounter::Grass, {126, 81, 126, 419, 419, 423, 81, 81, 419, 423, 419, 423}, {28, 29, 29, 29, 30, 30, 28, 30, 31, 31, 31, 31}), // Fuego Ironworks
        EncounterArea4(51, 2, Game::Blank, Encounter::Grass, {126, 81, 126, 419, 419, 423, 81, 81, 419, 423, 419, 423}, {28, 29, 29, 29, 30, 30, 28, 30, 31, 31, 31, 31}), // Fuego Ironworks
        EncounterArea4(51, 3, Game::Blank, Encounter::Grass, {126, 81, 423, 419, 419, 423, 81, 81, 419, 423, 419, 423}, {28, 29, 29, 29, 30, 30, 28, 30, 31, 31, 31, 31}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::Surfing, {72, 422, 73, 73, 423}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::SuperRod, {130, 457, 90, 457, 457}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Fuego Ironworks
        EncounterArea4(51, 0, Game::Blank, Encounter::PokeRadar, {126, 81, 126, 419, 304, 304, 81, 81, 419, 423, 304, 304}, {28, 29, 29, 29, 30, 30, 28, 30, 31, 31, 31, 31}), // Fuego Ironworks
        EncounterArea4(52, 1, Game::Blank, Encounter::Grass, {436, 74, 307, 35, 66, 307, 433, 299, 41, 433, 41, 433}, {18, 19, 18, 17, 20, 20, 17, 18, 19, 19, 19, 19}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 2, Game::Blank, Encounter::Grass, {436, 74, 307, 74, 66, 307, 433, 299, 41, 433, 41, 433}, {18, 19, 18, 17, 20, 20, 17, 18, 19, 19, 19, 19}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 3, Game::Blank, Encounter::Grass, {436, 74, 41, 35, 66, 307, 433, 299, 41, 433, 41, 433}, {18, 19, 18, 17, 20, 20, 17, 18, 19, 19, 19, 19}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(52, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 20, 40, 40}, {55, 40, 55, 55, 55}), // Mt. Coronet (Route 207/208 Entrance)
        EncounterArea4(53, 1, Game::Blank, Encounter::Grass, {436, 74, 307, 173, 66, 307, 433, 299, 41, 433, 41, 433}, {14, 15, 14, 13, 16, 16, 13, 14, 15, 15, 15, 15}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(53, 2, Game::Blank, Encounter::Grass, {436, 74, 307, 74, 66, 307, 433, 299, 41, 433, 41, 433}, {14, 15, 14, 13, 16, 16, 13, 14, 15, 15, 15, 15}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(53, 3, Game::Blank, Encounter::Grass, {436, 74, 41, 173, 66, 307, 433, 299, 41, 433, 41, 433}, {14, 15, 14, 13, 16, 16, 13, 14, 15, 15, 15, 15}), // Mt. Coronet (Route 211 Entrance)
        EncounterArea4(54, 1, Game::Blank, Encounter::Grass, {436, 75, 307, 35, 67, 307, 433, 299, 42, 433, 42, 433}, {33, 34, 33, 32, 35, 35, 32, 33, 34, 34, 34, 34}), // Mt. Coronet (Route 216 Entrance)
        EncounterArea4(54, 2, Game::Blank, Encounter::Grass, {436, 75, 307, 75, 67, 307, 433, 299, 42, 433, 42, 433}, {33, 34, 33, 32, 35, 35, 32, 33, 34, 34, 34, 34}), // Mt. Coronet (Route 216 Entrance)
        EncounterArea4(54, 3, Game::Blank, Encounter::Grass, {436, 75, 42, 35, 67, 307, 433, 299, 42, 433, 42, 433}, {33, 34, 33, 32, 35, 35, 32, 33, 34, 34, 34, 34}), // Mt. Coronet (Route 216 Entrance)
        EncounterArea4(55, 1, Game::Blank, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 2F
        EncounterArea4(55, 2, Game::Blank, Encounter::Grass, {437, 75, 308, 75, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 2F
        EncounterArea4(55, 3, Game::Blank, Encounter::Grass, {437, 75, 42, 35, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 2F
        EncounterArea4(55, 0, Game::Ruby, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 338, 338, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 2F
        EncounterArea4(55, 0, Game::Sapphire, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 337, 337, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 2F
        EncounterArea4(56, 1, Game::Blank, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 42, 433, 308, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 3F
        EncounterArea4(56, 2, Game::Blank, Encounter::Grass, {437, 75, 308, 75, 67, 308, 433, 299, 42, 433, 308, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 3F
        EncounterArea4(56, 3, Game::Blank, Encounter::Grass, {437, 75, 42, 35, 67, 308, 433, 299, 42, 433, 308, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 3F
        EncounterArea4(56, 0, Game::Ruby, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 338, 338, 308, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 3F
        EncounterArea4(56, 0, Game::Sapphire, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 337, 337, 308, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 3F
        EncounterArea4(57, 1, Game::Blank, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 4F
        EncounterArea4(57, 2, Game::Blank, Encounter::Grass, {437, 75, 308, 75, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 4F
        EncounterArea4(57, 3, Game::Blank, Encounter::Grass, {437, 75, 42, 35, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Ruby, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 338, 338, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Sapphire, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 337, 337, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet 4F
        EncounterArea4(57, 0, Game::Blank, Encounter::SuperRod, {130, 147, 340, 148, 148}, {30, 15, 20, 20, 35}, {55, 25, 50, 40, 55}), // Mt. Coronet 4F
        EncounterArea4(58, 1, Game::Blank, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 42, 433, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 39}), // Mt. Coronet 5F
        EncounterArea4(58, 2, Game::Blank, Encounter::Grass, {437, 75, 308, 75, 67, 308, 433, 299, 42, 433, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 39}), // Mt. Coronet 5F
        EncounterArea4(58, 3, Game::Blank, Encounter::Grass, {437, 75, 42, 35, 67, 308, 433, 299, 42, 433, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 39}), // Mt. Coronet 5F
        EncounterArea4(58, 0, Game::Ruby, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 338, 338, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 39}), // Mt. Coronet 5F
        EncounterArea4(58, 0, Game::Sapphire, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 337, 337, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 39}), // Mt. Coronet 5F
        EncounterArea4(59, 1, Game::Blank, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 42, 358, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 39, 38, 40}), // Mt. Coronet 6F
        EncounterArea4(59, 2, Game::Blank, Encounter::Grass, {437, 75, 308, 75, 67, 308, 433, 299, 42, 358, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 39, 38, 40}), // Mt. Coronet 6F
        EncounterArea4(59, 3, Game::Blank, Encounter::Grass, {437, 75, 42, 35, 67, 308, 433, 299, 42, 358, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 39, 38, 40}), // Mt. Coronet 6F
        EncounterArea4(59, 0, Game::Ruby, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 338, 338, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 39, 38, 40}), // Mt. Coronet 6F
        EncounterArea4(59, 0, Game::Sapphire, Encounter::Grass, {437, 75, 308, 35, 67, 308, 433, 299, 337, 337, 42, 358}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 39, 38, 40}), // Mt. Coronet 6F
        EncounterArea4(60, 1, Game::Blank, Encounter::Grass, {437, 75, 308, 35, 67, 308, 358, 299, 42, 358, 42, 358}, {37, 38, 37, 36, 39, 39, 39, 37, 38, 40, 38, 41}), // Mt. Coronet 7F
        EncounterArea4(60, 2, Game::Blank, Encounter::Grass, {437, 75, 308, 75, 67, 308, 358, 299, 42, 358, 42, 358}, {37, 38, 37, 36, 39, 39, 39, 37, 38, 40, 38, 41}), // Mt. Coronet 7F
        EncounterArea4(60, 3, Game::Blank, Encounter::Grass, {437, 75, 42, 35, 67, 308, 358, 299, 42, 358, 42, 358}, {37, 38, 37, 36, 39, 39, 39, 37, 38, 40, 38, 41}), // Mt. Coronet 7F
        EncounterArea4(60, 0, Game::Ruby, Encounter::Grass, {437, 75, 308, 35, 67, 308, 358, 299, 338, 338, 42, 358}, {37, 38, 37, 36, 39, 39, 39, 37, 38, 40, 38, 41}), // Mt. Coronet 7F
        EncounterArea4(60, 0, Game::Sapphire, Encounter::Grass, {437, 75, 308, 35, 67, 308, 358, 299, 337, 337, 42, 358}, {37, 38, 37, 36, 39, 39, 39, 37, 38, 40, 38, 41}), // Mt. Coronet 7F
        EncounterArea4(61, 1, Game::Blank, Encounter::Grass, {436, 75, 307, 35, 67, 307, 433, 299, 42, 433, 42, 433}, {33, 34, 33, 32, 35, 35, 32, 33, 34, 34, 34, 34}), // Mt. Coronet B1F
        EncounterArea4(61, 2, Game::Blank, Encounter::Grass, {436, 75, 307, 75, 67, 307, 433, 299, 42, 433, 42, 433}, {33, 34, 33, 32, 35, 35, 32, 33, 34, 34, 34, 34}), // Mt. Coronet B1F
        EncounterArea4(61, 3, Game::Blank, Encounter::Grass, {436, 75, 42, 35, 67, 307, 433, 299, 42, 433, 42, 433}, {33, 34, 33, 32, 35, 35, 32, 33, 34, 34, 34, 34}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::Surfing, {41, 41, 42, 42, 42}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 15}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Mt. Coronet B1F
        EncounterArea4(61, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Mt. Coronet B1F
        EncounterArea4(62, 1, Game::Blank, Encounter::Grass, {459, 460, 308, 460, 67, 308, 433, 299, 359, 433, 359, 433}, {36, 38, 38, 39, 40, 40, 37, 38, 38, 39, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 2, Game::Blank, Encounter::Grass, {459, 460, 308, 460, 67, 308, 433, 299, 359, 433, 359, 433}, {36, 38, 38, 39, 40, 40, 37, 38, 38, 39, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 3, Game::Blank, Encounter::Grass, {459, 460, 42, 164, 67, 308, 433, 299, 359, 433, 359, 433}, {36, 38, 38, 39, 40, 40, 37, 38, 38, 39, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Ruby, Encounter::Grass, {459, 460, 308, 460, 67, 308, 433, 299, 338, 338, 359, 433}, {36, 38, 38, 39, 40, 40, 37, 38, 38, 39, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Sapphire, Encounter::Grass, {459, 460, 308, 460, 67, 308, 433, 299, 337, 337, 359, 433}, {36, 38, 38, 39, 40, 40, 37, 38, 38, 39, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(62, 0, Game::Blank, Encounter::PokeRadar, {459, 460, 308, 460, 294, 294, 433, 299, 359, 433, 294, 294}, {36, 38, 38, 39, 40, 40, 37, 38, 38, 39, 40, 39}), // Mt. Coronet Snow
        EncounterArea4(63, 1, Game::Blank, Encounter::Grass, {75, 75, 308, 35, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet	Top Cave
        EncounterArea4(63, 2, Game::Blank, Encounter::Grass, {75, 75, 308, 75, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet	Top Cave
        EncounterArea4(63, 3, Game::Blank, Encounter::Grass, {75, 75, 42, 35, 67, 308, 433, 299, 42, 433, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet	Top Cave
        EncounterArea4(63, 0, Game::Ruby, Encounter::Grass, {75, 75, 308, 35, 67, 308, 433, 299, 338, 338, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet	Top Cave
        EncounterArea4(63, 0, Game::Sapphire, Encounter::Grass, {75, 75, 308, 35, 67, 308, 433, 299, 337, 337, 42, 433}, {37, 38, 37, 36, 39, 39, 36, 37, 38, 38, 38, 38}), // Mt. Coronet	Top Cave
        EncounterArea4(64, 1, Game::Blank, Encounter::Grass, {194, 400, 357, 357, 194, 195, 194, 194, 193, 114, 193, 114}, {28, 28, 28, 30, 29, 30, 28, 30, 30, 30, 31, 31}), // Great Marsh Area 1
        EncounterArea4(64, 2, Game::Blank, Encounter::Grass, {194, 400, 357, 357, 194, 195, 194, 194, 193, 114, 193, 114}, {28, 28, 28, 30, 29, 30, 28, 30, 30, 30, 31, 31}), // Great Marsh Area 1
        EncounterArea4(64, 3, Game::Blank, Encounter::Grass, {194, 400, 164, 164, 194, 195, 194, 194, 193, 114, 193, 114}, {28, 28, 28, 30, 29, 30, 28, 30, 30, 30, 31, 31}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::FireRed, Encounter::Grass, {194, 400, 357, 357, 194, 195, 194, 194, 24, 24, 193, 114}, {28, 28, 28, 30, 29, 30, 28, 30, 30, 30, 31, 31}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 15}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Great Marsh Area 1
        EncounterArea4(64, 0, Game::Blank, Encounter::SuperRod, {130, 318, 340, 318, 318}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Great Marsh Area 1
        EncounterArea4(65, 1, Game::Blank, Encounter::Grass, {194, 400, 357, 357, 194, 195, 194, 194, 193, 114, 193, 114}, {28, 28, 28, 30, 29, 30, 28, 30, 30, 30, 31, 31}), // Great Marsh Area 2
        EncounterArea4(65, 2, Game::Blank, Encounter::Grass, {194, 400, 357, 357, 194, 195, 194, 194, 193, 114, 193, 114}, {28, 28, 28, 30, 29, 30, 28, 30, 30, 30, 31, 31}), // Great Marsh Area 2
        EncounterArea4(65, 3, Game::Blank, Encounter::Grass, {194, 400, 164, 164, 194, 195, 194, 194, 193, 114, 193, 114}, {28, 28, 28, 30, 29, 30, 28, 30, 30, 30, 31, 31}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::FireRed, Encounter::Grass, {194, 400, 357, 357, 194, 195, 194, 194, 24, 24, 193, 114}, {28, 28, 28, 30, 29, 30, 28, 30, 30, 30, 31, 31}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 15}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Great Marsh Area 2
        EncounterArea4(65, 0, Game::Blank, Encounter::SuperRod, {130, 318, 340, 318, 318}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Great Marsh Area 2
        EncounterArea4(66, 1, Game::Blank, Encounter::Grass, {194, 400, 400, 114, 114, 195, 194, 194, 193, 114, 193, 114}, {27, 27, 28, 27, 28, 29, 28, 29, 29, 29, 30, 30}), // Great Marsh Area 3
        EncounterArea4(66, 2, Game::Blank, Encounter::Grass, {194, 400, 400, 114, 114, 195, 194, 194, 193, 114, 193, 114}, {27, 27, 28, 27, 28, 29, 28, 29, 29, 29, 30, 30}), // Great Marsh Area 3
        EncounterArea4(66, 3, Game::Blank, Encounter::Grass, {194, 400, 164, 163, 114, 195, 194, 194, 193, 114, 193, 114}, {27, 27, 28, 27, 28, 29, 28, 29, 29, 29, 30, 30}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::FireRed, Encounter::Grass, {194, 400, 400, 114, 114, 195, 194, 194, 24, 24, 193, 114}, {27, 27, 28, 27, 28, 29, 28, 29, 29, 29, 30, 30}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 15}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Great Marsh Area 3
        EncounterArea4(66, 0, Game::Blank, Encounter::SuperRod, {130, 318, 340, 318, 318}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Great Marsh Area 3
        EncounterArea4(67, 1, Game::Blank, Encounter::Grass, {194, 400, 400, 114, 114, 195, 194, 194, 193, 114, 193, 114}, {27, 27, 28, 27, 28, 29, 28, 29, 29, 29, 30, 30}), // Great Marsh Area 4
        EncounterArea4(67, 2, Game::Blank, Encounter::Grass, {194, 400, 400, 114, 114, 195, 194, 194, 193, 114, 193, 114}, {27, 27, 28, 27, 28, 29, 28, 29, 29, 29, 30, 30}), // Great Marsh Area 4
        EncounterArea4(67, 3, Game::Blank, Encounter::Grass, {194, 400, 164, 163, 114, 195, 194, 194, 193, 114, 193, 114}, {27, 27, 28, 27, 28, 29, 28, 29, 29, 29, 30, 30}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::FireRed, Encounter::Grass, {194, 400, 400, 114, 114, 195, 194, 194, 24, 24, 193, 114}, {27, 27, 28, 27, 28, 29, 28, 29, 29, 29, 30, 30}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 15}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Great Marsh Area 4
        EncounterArea4(67, 0, Game::Blank, Encounter::SuperRod, {130, 318, 340, 318, 318}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Great Marsh Area 4
        EncounterArea4(68, 1, Game::Blank, Encounter::Grass, {194, 400, 400, 193, 193, 195, 194, 194, 193, 114, 193, 114}, {26, 26, 27, 26, 27, 28, 27, 28, 28, 28, 29, 29}), // Great Marsh Area 5
        EncounterArea4(68, 2, Game::Blank, Encounter::Grass, {194, 400, 400, 193, 193, 195, 194, 194, 193, 114, 193, 114}, {26, 26, 27, 26, 27, 28, 27, 28, 28, 28, 29, 29}), // Great Marsh Area 5
        EncounterArea4(68, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 193, 195, 194, 194, 193, 114, 193, 114}, {26, 26, 27, 26, 27, 28, 27, 28, 28, 28, 29, 29}), // Great Marsh Area 5
        EncounterArea4(68, 0, Game::FireRed, Encounter::Grass, {194, 400, 400, 193, 193, 195, 194, 194, 24, 24, 193, 114}, {26, 26, 27, 26, 27, 28, 27, 28, 28, 28, 29, 29}), // Great Marsh Area 5
        EncounterArea4(68, 0, Game::Blank, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 5
        EncounterArea4(68, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 15}), // Great Marsh Area 5
        EncounterArea4(68, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Great Marsh Area 5
        EncounterArea4(68, 0, Game::Blank, Encounter::SuperRod, {130, 318, 340, 318, 318}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Great Marsh Area 5
        EncounterArea4(69, 1, Game::Blank, Encounter::Grass, {194, 400, 400, 193, 193, 195, 194, 194, 193, 114, 193, 114}, {26, 26, 27, 26, 27, 28, 27, 28, 28, 28, 29, 29}), // Great Marsh Area 6
        EncounterArea4(69, 2, Game::Blank, Encounter::Grass, {194, 400, 400, 193, 193, 195, 194, 194, 193, 114, 193, 114}, {26, 26, 27, 26, 27, 28, 27, 28, 28, 28, 29, 29}), // Great Marsh Area 6
        EncounterArea4(69, 3, Game::Blank, Encounter::Grass, {194, 400, 163, 163, 193, 195, 194, 194, 193, 114, 193, 114}, {26, 26, 27, 26, 27, 28, 27, 28, 28, 28, 29, 29}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::FireRed, Encounter::Grass, {194, 400, 400, 193, 193, 195, 194, 194, 24, 24, 193, 114}, {26, 26, 27, 26, 27, 28, 27, 28, 28, 28, 29, 29}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {3, 4, 5, 5, 5}, {6, 7, 10, 10, 15}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Great Marsh Area 6
        EncounterArea4(69, 0, Game::Blank, Encounter::SuperRod, {130, 318, 340, 318, 318}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Great Marsh Area 6
        EncounterArea4(70, 0, Game::Blank, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 30}), // Solaceon Ruins
        EncounterArea4(71, 1, Game::Blank, Encounter::Grass, {75, 111, 75, 95, 95, 112, 42, 112, 208, 444, 208, 444}, {40, 41, 42, 41, 42, 41, 43, 43, 42, 41, 42, 41}), // Victory Road 1F
        EncounterArea4(71, 2, Game::Blank, Encounter::Grass, {75, 111, 75, 95, 95, 112, 42, 112, 208, 444, 208, 444}, {40, 41, 42, 41, 42, 41, 43, 43, 42, 41, 42, 41}), // Victory Road 1F
        EncounterArea4(71, 3, Game::Blank, Encounter::Grass, {75, 111, 42, 95, 95, 112, 42, 112, 208, 444, 208, 444}, {40, 41, 42, 41, 42, 41, 43, 43, 42, 41, 42, 41}), // Victory Road 1F
        EncounterArea4(72, 1, Game::Blank, Encounter::Grass, {82, 208, 75, 208, 208, 82, 42, 75, 95, 444, 95, 444}, {41, 42, 41, 42, 44, 43, 44, 43, 42, 43, 42, 43}), // Victory Road 2F
        EncounterArea4(72, 2, Game::Blank, Encounter::Grass, {82, 208, 75, 208, 208, 82, 42, 75, 95, 444, 95, 444}, {41, 42, 41, 42, 44, 43, 44, 43, 42, 43, 42, 43}), // Victory Road 2F
        EncounterArea4(72, 3, Game::Blank, Encounter::Grass, {82, 208, 42, 208, 208, 82, 42, 75, 95, 444, 95, 444}, {41, 42, 41, 42, 44, 43, 44, 43, 42, 43, 42, 43}), // Victory Road 2F
        EncounterArea4(73, 1, Game::Blank, Encounter::Grass, {419, 184, 75, 184, 95, 419, 42, 75, 208, 444, 208, 444}, {42, 41, 41, 43, 42, 44, 44, 43, 44, 43, 44, 43}), // Victory Road B1F
        EncounterArea4(73, 2, Game::Blank, Encounter::Grass, {419, 184, 75, 184, 95, 419, 42, 75, 208, 444, 208, 444}, {42, 41, 41, 43, 42, 44, 44, 43, 44, 43, 44, 43}), // Victory Road B1F
        EncounterArea4(73, 3, Game::Blank, Encounter::Grass, {419, 184, 42, 184, 95, 419, 42, 75, 208, 444, 208, 444}, {42, 41, 41, 43, 42, 44, 44, 43, 44, 43, 44, 43}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::Surfing, {419, 419, 42, 42, 42}, {30, 30, 30, 30, 30}, {50, 50, 50, 50, 50}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Victory Road B1F
        EncounterArea4(73, 0, Game::Blank, Encounter::SuperRod, {130, 130, 130, 130, 130}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Victory Road B1F
        EncounterArea4(74, 1, Game::Blank, Encounter::Grass, {419, 184, 75, 184, 87, 419, 42, 75, 87, 444, 87, 444}, {48, 47, 47, 49, 48, 50, 50, 49, 50, 49, 50, 49}), // Victory Road Back Room 1
        EncounterArea4(74, 2, Game::Blank, Encounter::Grass, {419, 184, 75, 184, 87, 419, 42, 75, 87, 444, 87, 444}, {48, 47, 47, 49, 48, 50, 50, 49, 50, 49, 50, 49}), // Victory Road Back Room 1
        EncounterArea4(74, 3, Game::Blank, Encounter::Grass, {419, 184, 42, 184, 87, 419, 42, 75, 87, 444, 87, 444}, {48, 47, 47, 49, 48, 50, 50, 49, 50, 49, 50, 49}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::Surfing, {419, 87, 131, 131, 131}, {35, 35, 35, 35, 35}, {55, 55, 55, 55, 55}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Victory Road Back Room 1
        EncounterArea4(74, 0, Game::Blank, Encounter::SuperRod, {130, 130, 130, 130, 130}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Victory Road Back Room 1
        EncounterArea4(75, 1, Game::Blank, Encounter::Grass, {75, 419, 75, 95, 95, 419, 42, 419, 208, 444, 208, 444}, {47, 47, 49, 48, 50, 48, 50, 49, 50, 50, 50, 50}), // Victory Road Back Room 2
        EncounterArea4(75, 2, Game::Blank, Encounter::Grass, {75, 419, 75, 95, 95, 419, 42, 419, 208, 444, 208, 444}, {47, 47, 49, 48, 50, 48, 50, 49, 50, 50, 50, 50}), // Victory Road Back Room 2
        EncounterArea4(75, 3, Game::Blank, Encounter::Grass, {75, 419, 42, 95, 95, 419, 42, 419, 208, 444, 208, 444}, {47, 47, 49, 48, 50, 48, 50, 49, 50, 50, 50, 50}), // Victory Road Back Room 2
        EncounterArea4(76, 1, Game::Blank, Encounter::Grass, {75, 419, 75, 95, 95, 419, 42, 419, 208, 444, 208, 444}, {47, 47, 49, 48, 50, 48, 49, 49, 50, 50, 50, 50}), // Victory Road Back Room 3
        EncounterArea4(76, 2, Game::Blank, Encounter::Grass, {75, 419, 75, 95, 95, 419, 42, 419, 208, 444, 208, 444}, {47, 47, 49, 48, 50, 48, 49, 49, 50, 50, 50, 50}), // Victory Road Back Room 3
        EncounterArea4(76, 3, Game::Blank, Encounter::Grass, {75, 419, 42, 95, 95, 419, 42, 419, 208, 444, 208, 444}, {47, 47, 49, 48, 50, 48, 49, 49, 50, 50, 50, 50}), // Victory Road Back Room 3
        EncounterArea4(77, 0, Game::Blank, Encounter::Grass, {41, 54, 41, 54, 41, 41, 54, 41, 41, 41, 41, 41}, {4, 4, 5, 5, 3, 3, 6, 6, 6, 6, 6, 6}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::Surfing, {54, 41, 55, 42, 42}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Ravaged Path
        EncounterArea4(77, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {55, 40, 55, 55, 55}), // Ravaged Path
        EncounterArea4(78, 0, Game::Blank, Encounter::Grass, {41, 54, 41, 54, 74, 41, 54, 74, 41, 41, 41, 41}, {5, 5, 6, 6, 5, 5, 7, 7, 7, 8, 7, 8}), // Oreburgh Gate 1F
        EncounterArea4(79, 0, Game::Blank, Encounter::Grass, {41, 54, 41, 54, 74, 41, 54, 74, 41, 42, 41, 42}, {6, 8, 7, 9, 6, 8, 10, 8, 9, 10, 9, 10}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::Surfing, {54, 41, 55, 42, 42}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::GoodRod, {129, 339, 129, 339, 339}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Oreburgh Gate B1F
        EncounterArea4(79, 0, Game::Blank, Encounter::SuperRod, {130, 340, 130, 340, 340}, {30, 30, 40, 40, 40}, {55, 40, 55, 55, 55}), // Oreburgh Gate B1F
        EncounterArea4(80, 1, Game::Blank, Encounter::Grass, {75, 400, 75, 397, 400, 397, 75, 433, 356, 433, 356, 433}, {38, 37, 39, 38, 38, 40, 37, 37, 40, 39, 40, 39}), // Sendoff Spring
        EncounterArea4(80, 2, Game::Blank, Encounter::Grass, {75, 400, 75, 397, 400, 397, 75, 433, 356, 433, 356, 433}, {38, 37, 39, 38, 38, 40, 37, 37, 40, 39, 40, 39}), // Sendoff Spring
        EncounterArea4(80, 3, Game::Blank, Encounter::Grass, {75, 400, 356, 42, 400, 397, 75, 433, 356, 433, 356, 433}, {38, 37, 39, 38, 38, 40, 37, 37, 40, 39, 40, 39}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Ruby, Encounter::Grass, {75, 400, 75, 397, 400, 397, 75, 433, 338, 338, 356, 433}, {38, 37, 39, 38, 38, 40, 37, 37, 40, 39, 40, 39}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Sapphire, Encounter::Grass, {75, 400, 75, 397, 400, 397, 75, 433, 337, 337, 356, 433}, {38, 37, 39, 38, 38, 40, 37, 37, 40, 39, 40, 39}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::Surfing, {55, 55, 55, 55, 55}, {20, 20, 20, 20, 20}, {40, 40, 40, 40, 40}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 118, 118}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Sendoff Spring
        EncounterArea4(80, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Sendoff Spring
        EncounterArea4(81, 1, Game::Blank, Encounter::Grass, {92, 436, 92, 42, 92, 42, 42, 433, 355, 433, 355, 433}, {15, 15, 16, 17, 17, 17, 18, 16, 18, 18, 18, 18}), // Turnback Cave Entrance
        EncounterArea4(81, 2, Game::Blank, Encounter::Grass, {92, 436, 92, 42, 92, 42, 42, 433, 355, 433, 355, 433}, {15, 15, 16, 17, 17, 17, 18, 16, 18, 18, 18, 18}), // Turnback Cave Entrance
        EncounterArea4(81, 3, Game::Blank, Encounter::Grass, {92, 436, 356, 42, 92, 42, 42, 433, 355, 433, 355, 433}, {15, 15, 16, 17, 17, 17, 18, 16, 18, 18, 18, 18}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::Ruby, Encounter::Grass, {92, 436, 92, 42, 92, 42, 42, 433, 338, 338, 355, 433}, {15, 15, 16, 17, 17, 17, 18, 16, 18, 18, 18, 18}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::Sapphire, Encounter::Grass, {92, 436, 92, 42, 92, 42, 42, 433, 337, 337, 355, 433}, {15, 15, 16, 17, 17, 17, 18, 16, 18, 18, 18, 18}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::Emerald, Encounter::Grass, {92, 436, 92, 42, 92, 42, 42, 433, 356, 433, 355, 433}, {15, 15, 16, 17, 17, 17, 18, 16, 18, 18, 18, 18}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::FireRed, Encounter::Grass, {92, 436, 92, 42, 92, 42, 42, 433, 356, 433, 355, 433}, {15, 15, 16, 17, 17, 17, 18, 16, 18, 18, 18, 18}), // Turnback Cave Entrance
        EncounterArea4(81, 0, Game::Blank, Encounter::PokeRadar, {92, 436, 92, 42, 92, 42, 42, 433, 355, 433, 356, 433}, {15, 15, 16, 17, 17, 17, 18, 16, 18, 18, 18, 18}), // Turnback Cave Entrance
        EncounterArea4(82, 1, Game::Blank, Encounter::Grass, {93, 436, 93, 42, 93, 42, 42, 433, 355, 433, 356, 358}, {25, 25, 26, 27, 27, 27, 25, 26, 28, 28, 28, 28}), // Turnback Cave 1st Pillar
        EncounterArea4(82, 2, Game::Blank, Encounter::Grass, {93, 436, 93, 42, 93, 42, 42, 433, 355, 433, 356, 358}, {25, 25, 26, 27, 27, 27, 25, 26, 28, 28, 28, 28}), // Turnback Cave 1st Pillar
        EncounterArea4(82, 3, Game::Blank, Encounter::Grass, {93, 436, 356, 42, 93, 42, 42, 433, 355, 433, 356, 358}, {25, 25, 26, 27, 27, 27, 25, 26, 28, 28, 28, 28}), // Turnback Cave 1st Pillar
        EncounterArea4(82, 0, Game::Ruby, Encounter::Grass, {93, 436, 93, 42, 93, 42, 42, 433, 338, 338, 356, 358}, {25, 25, 26, 27, 27, 27, 25, 26, 28, 28, 28, 28}), // Turnback Cave 1st Pillar
        EncounterArea4(82, 0, Game::Sapphire, Encounter::Grass, {93, 436, 93, 42, 93, 42, 42, 433, 337, 337, 356, 358}, {25, 25, 26, 27, 27, 27, 25, 26, 28, 28, 28, 28}), // Turnback Cave 1st Pillar
        EncounterArea4(83, 1, Game::Blank, Encounter::Grass, {93, 437, 93, 42, 93, 42, 42, 358, 356, 358, 356, 358}, {35, 35, 36, 37, 37, 37, 38, 36, 38, 38, 38, 38}), // Turnback Cave 2nd Pillar
        EncounterArea4(83, 2, Game::Blank, Encounter::Grass, {93, 437, 93, 42, 93, 42, 42, 358, 356, 358, 356, 358}, {35, 35, 36, 37, 37, 37, 38, 36, 38, 38, 38, 38}), // Turnback Cave 2nd Pillar
        EncounterArea4(83, 3, Game::Blank, Encounter::Grass, {93, 437, 356, 42, 93, 42, 42, 358, 356, 358, 356, 358}, {35, 35, 36, 37, 37, 37, 38, 36, 38, 38, 38, 38}), // Turnback Cave 2nd Pillar
        EncounterArea4(83, 0, Game::Ruby, Encounter::Grass, {93, 437, 93, 42, 93, 42, 42, 358, 338, 338, 356, 358}, {35, 35, 36, 37, 37, 37, 38, 36, 38, 38, 38, 38}), // Turnback Cave 2nd Pillar
        EncounterArea4(83, 0, Game::Sapphire, Encounter::Grass, {93, 437, 93, 42, 93, 42, 42, 358, 337, 337, 356, 358}, {35, 35, 36, 37, 37, 37, 38, 36, 38, 38, 38, 38}), // Turnback Cave 2nd Pillar
        EncounterArea4(84, 0, Game::Blank, Encounter::Grass, {42, 42, 42, 42, 42, 215, 238, 42, 238, 42, 238, 42}, {47, 48, 49, 50, 48, 49, 47, 49, 49, 47, 49, 47}), // Snowpoint Temple 1F
        EncounterArea4(85, 0, Game::Blank, Encounter::Grass, {42, 42, 42, 42, 42, 215, 124, 42, 124, 42, 124, 42}, {47, 48, 49, 50, 48, 49, 47, 49, 49, 47, 49, 47}), // Snowpoint Temple B1F
        EncounterArea4(86, 0, Game::Blank, Encounter::Grass, {42, 42, 42, 42, 42, 215, 124, 42, 124, 42, 124, 42}, {47, 48, 49, 50, 48, 50, 48, 49, 50, 47, 50, 47}), // Snowpoint Temple B2F
        EncounterArea4(87, 0, Game::Blank, Encounter::Grass, {42, 42, 42, 42, 42, 215, 124, 42, 124, 42, 124, 42}, {47, 48, 49, 50, 48, 50, 48, 49, 50, 47, 50, 47}), // Snowpoint Temple B3F
        EncounterArea4(88, 0, Game::Blank, Encounter::Grass, {42, 42, 42, 42, 42, 215, 124, 42, 124, 42, 124, 42}, {47, 48, 49, 50, 48, 51, 49, 49, 51, 47, 51, 47}), // Snowpoint Temple B4F
        EncounterArea4(89, 0, Game::Blank, Encounter::Grass, {42, 42, 42, 42, 42, 215, 124, 42, 124, 42, 124, 42}, {47, 48, 49, 50, 48, 51, 49, 49, 51, 47, 51, 47}), // Snowpoint Temple B5F
        EncounterArea4(90, 0, Game::Blank, Encounter::Grass, {436, 74, 74, 41, 436, 95, 74, 74, 41, 95, 41, 95}, {18, 18, 17, 19, 20, 20, 19, 20, 17, 18, 17, 18}), // Wayward Cave
        EncounterArea4(91, 0, Game::Blank, Encounter::Grass, {436, 74, 443, 41, 436, 95, 443, 74, 443, 95, 443, 95}, {18, 18, 17, 19, 20, 20, 19, 20, 20, 18, 20, 18}), // Wayward Cave (Secret)
        EncounterArea4(92, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 74, 74, 74, 74, 449, 74, 449}, {23, 22, 21, 23, 23, 23, 23, 23, 23, 22, 23, 24}), // Ruin Maniac Cave (< 10 Unown)
        EncounterArea4(93, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 74, 74, 449, 74, 449, 74, 449}, {24, 23, 22, 24, 24, 24, 24, 24, 24, 23, 24, 25}), // Ruin Maniac Cave (> 10 Unown)
        EncounterArea4(94, 0, Game::Blank, Encounter::Grass, {74, 74, 74, 74, 74, 449, 74, 449, 74, 449, 74, 449}, {25, 24, 23, 25, 25, 25, 25, 25, 25, 24, 25, 26}), // Maniac Cave
        EncounterArea4(95, 1, Game::Blank, Encounter::Grass, {172, 315, 397, 402, 315, 397, 25, 172, 25, 172, 25, 172}, {21, 22, 22, 23, 23, 24, 22, 22, 24, 22, 24, 22}), // Trophy Garden
        EncounterArea4(95, 2, Game::Blank, Encounter::Grass, {172, 315, 397, 397, 315, 397, 25, 172, 25, 172, 25, 172}, {21, 22, 22, 23, 23, 24, 22, 22, 24, 22, 24, 22}), // Trophy Garden
        EncounterArea4(95, 3, Game::Blank, Encounter::Grass, {172, 315, 402, 402, 315, 397, 25, 172, 25, 172, 25, 172}, {21, 22, 22, 23, 23, 24, 22, 22, 24, 22, 24, 22}), // Trophy Garden
        EncounterArea4(96, 0, Game::Blank, Encounter::Surfing, {278, 72, 279, 279, 73}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::GoodRod, {129, 456, 129, 456, 456}, {15, 15, 10, 10, 10}, {20, 20, 25, 25, 25}), // Iron Island
        EncounterArea4(96, 0, Game::Blank, Encounter::SuperRod, {130, 457, 211, 457, 457}, {30, 30, 20, 40, 40}, {55, 40, 50, 55, 55}), // Iron Island
        EncounterArea4(97, 0, Game::Blank, Encounter::Grass, {74, 75, 41, 42, 74, 75, 95, 95, 74, 75, 74, 75}, {31, 32, 30, 32, 32, 33, 31, 33, 30, 31, 30, 31}), // Iron Island 1F
        EncounterArea4(98, 0, Game::Blank, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 75, 75, 75, 75}, {31, 32, 30, 32, 32, 33, 31, 33, 30, 31, 30, 31}), // Iron Island B1F
        EncounterArea4(98, 0, Game::Ruby, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 303, 303, 75, 75}, {31, 32, 30, 32, 32, 33, 31, 33, 30, 31, 30, 31}), // Iron Island B1F
        EncounterArea4(98, 0, Game::Sapphire, Encounter::Grass, {75, 75, 42, 42, 75, 75, 95, 95, 302, 302, 75, 75}, {31, 32, 30, 32, 32, 33, 31, 33, 30, 31, 30, 31}), // Iron Island B1F
        EncounterArea4(99, 0, Game::Blank, Encounter::Grass, {95, 75, 42, 42, 75, 75, 208, 208, 75, 75, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B2F (Left)
        EncounterArea4(99, 0, Game::Ruby, Encounter::Grass, {95, 75, 42, 42, 75, 75, 208, 208, 303, 303, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B2F (Left)
        EncounterArea4(99, 0, Game::Sapphire, Encounter::Grass, {95, 75, 42, 42, 75, 75, 208, 208, 302, 302, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B2F (Left)
        EncounterArea4(100, 0, Game::Blank, Encounter::Grass, {95, 75, 42, 42, 75, 75, 208, 208, 75, 75, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B2F (Right)
        EncounterArea4(100, 0, Game::Ruby, Encounter::Grass, {95, 75, 42, 42, 75, 75, 208, 208, 303, 303, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B2F (Right)
        EncounterArea4(100, 0, Game::Sapphire, Encounter::Grass, {95, 75, 42, 42, 75, 75, 208, 208, 302, 302, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B2F (Right)
        EncounterArea4(101, 0, Game::Blank, Encounter::Grass, {208, 75, 42, 42, 75, 75, 208, 208, 75, 75, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B3F
        EncounterArea4(101, 0, Game::Ruby, Encounter::Grass, {208, 75, 42, 42, 75, 75, 208, 208, 303, 303, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B3F
        EncounterArea4(101, 0, Game::Sapphire, Encounter::Grass, {208, 75, 42, 42, 75, 75, 208, 208, 302, 302, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B3F
        EncounterArea4(101, 0, Game::Blank, Encounter::Swarm, {95, 75, 42, 42, 75, 75, 208, 208, 75, 75, 75, 75}, {32, 33, 31, 33, 33, 34, 33, 35, 31, 32, 31, 32}), // Iron Island B3F
        EncounterArea4(102, 0, Game::Blank, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92}, {14, 15, 14, 15, 16, 17, 16, 17, 17, 17, 17, 17}), // Old Chateau
        EncounterArea4(103, 0, Game::Blank, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92}, {14, 15, 14, 15, 16, 17, 16, 17, 17, 17, 17, 17}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Ruby, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 92, 92, 92}, {14, 15, 14, 15, 16, 17, 16, 17, 17, 17, 17, 17}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Sapphire, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 92, 92, 92}, {14, 15, 14, 15, 16, 17, 16, 17, 17, 17, 17, 17}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::Emerald, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 92, 92, 92}, {14, 15, 14, 15, 16, 17, 16, 17, 17, 17, 17, 17}), // Old Chateau Room 5
        EncounterArea4(103, 0, Game::FireRed, Encounter::Grass, {92, 92, 92, 92, 92, 92, 92, 92, 94, 92, 92, 92}, {14, 15, 14, 15, 16, 17, 16, 17, 17, 17, 17, 17}), // Old Chateau Room 5
        EncounterArea4(104, 1, Game::Blank, Encounter::Grass, {203, 400, 397, 402, 397, 228, 397, 400, 203, 400, 203, 400}, {26, 25, 26, 27, 27, 28, 28, 26, 28, 27, 28, 27}), // Valor Lakefront
        EncounterArea4(104, 2, Game::Blank, Encounter::Grass, {203, 400, 397, 397, 397, 228, 397, 400, 203, 400, 203, 400}, {26, 25, 26, 27, 27, 28, 28, 26, 28, 27, 28, 27}), // Valor Lakefront
        EncounterArea4(104, 3, Game::Blank, Encounter::Grass, {203, 400, 402, 228, 397, 228, 397, 400, 203, 400, 203, 400}, {26, 25, 26, 27, 27, 28, 28, 26, 28, 27, 28, 27}), // Valor Lakefront
        EncounterArea4(104, 0, Game::Blank, Encounter::PokeRadar, {203, 400, 397, 402, 33, 30, 397, 400, 203, 400, 33, 30}, {26, 25, 26, 27, 27, 28, 28, 26, 28, 27, 28, 27}), // Valor Lakefront
        EncounterArea4(105, 1, Game::Blank, Encounter::Grass, {459, 220, 215, 459, 215, 220, 459, 220, 215, 459, 215, 459}, {33, 32, 33, 32, 35, 34, 34, 32, 35, 35, 35, 35}), // Acuity Lakefront
        EncounterArea4(105, 2, Game::Blank, Encounter::Grass, {459, 220, 215, 459, 215, 220, 459, 220, 215, 459, 215, 459}, {33, 32, 33, 32, 35, 34, 34, 32, 35, 35, 35, 35}), // Acuity Lakefront
        EncounterArea4(105, 3, Game::Blank, Encounter::Grass, {459, 220, 361, 361, 215, 220, 459, 220, 215, 459, 215, 459}, {33, 32, 33, 32, 35, 34, 34, 32, 35, 35, 35, 35}), // Acuity Lakefront
        EncounterArea4(105, 0, Game::Emerald, Encounter::Grass, {459, 220, 215, 459, 215, 220, 459, 220, 217, 217, 215, 459}, {33, 32, 33, 32, 35, 34, 34, 32, 35, 35, 35, 35}), // Acuity Lakefront
        EncounterArea4(106, 0, Game::Blank, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 396, 399, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Ruby, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 338, 338, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Sapphire, Encounter::Grass, {396, 399, 396, 399, 396, 399, 396, 399, 337, 337, 396, 399}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 119, 119}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Lake Verity
        EncounterArea4(106, 0, Game::Blank, Encounter::PokeRadar, {396, 399, 396, 399, 202, 202, 396, 399, 396, 399, 202, 202}, {2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4}), // Lake Verity
        EncounterArea4(107, 0, Game::Blank, Encounter::Grass, {397, 400, 397, 400, 55, 54, 55, 54, 397, 400, 397, 400}, {38, 39, 40, 41, 40, 38, 41, 39, 40, 41, 40, 41}), // Lake Valor
        EncounterArea4(107, 0, Game::Ruby, Encounter::Grass, {397, 400, 397, 400, 55, 54, 55, 54, 338, 338, 397, 400}, {38, 39, 40, 41, 40, 38, 41, 39, 40, 41, 40, 41}), // Lake Valor
        EncounterArea4(107, 0, Game::Sapphire, Encounter::Grass, {397, 400, 397, 400, 55, 54, 55, 54, 337, 337, 397, 400}, {38, 39, 40, 41, 40, 38, 41, 39, 40, 41, 40, 41}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 119, 119}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Lake Valor
        EncounterArea4(107, 0, Game::Blank, Encounter::PokeRadar, {397, 400, 397, 400, 202, 202, 55, 54, 397, 400, 202, 202}, {38, 39, 40, 41, 40, 38, 41, 39, 40, 41, 40, 41}), // Lake Valor
        EncounterArea4(108, 1, Game::Blank, Encounter::Grass, {459, 400, 459, 459, 55, 215, 55, 54, 459, 400, 459, 400}, {38, 39, 39, 40, 40, 41, 39, 38, 41, 40, 41, 40}), // Lake Acuity
        EncounterArea4(108, 2, Game::Blank, Encounter::Grass, {459, 400, 459, 459, 55, 215, 55, 54, 459, 400, 459, 400}, {38, 39, 39, 40, 40, 41, 39, 38, 41, 40, 41, 40}), // Lake Acuity
        EncounterArea4(108, 3, Game::Blank, Encounter::Grass, {459, 400, 361, 361, 55, 215, 55, 54, 459, 400, 459, 400}, {38, 39, 39, 40, 40, 41, 39, 38, 41, 40, 41, 40}), // Lake Acuity
        EncounterArea4(108, 0, Game::Ruby, Encounter::Grass, {459, 400, 459, 459, 55, 215, 55, 54, 338, 338, 459, 400}, {38, 39, 39, 40, 40, 41, 39, 38, 41, 40, 41, 40}), // Lake Acuity
        EncounterArea4(108, 0, Game::Sapphire, Encounter::Grass, {459, 400, 459, 459, 55, 215, 55, 54, 337, 337, 459, 400}, {38, 39, 39, 40, 40, 41, 39, 38, 41, 40, 41, 40}), // Lake Acuity
        EncounterArea4(108, 0, Game::Emerald, Encounter::Grass, {459, 400, 459, 459, 55, 215, 55, 54, 216, 216, 459, 400}, {38, 39, 39, 40, 40, 41, 39, 38, 41, 40, 41, 40}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::Surfing, {54, 54, 55, 55, 55}, {20, 20, 20, 20, 20}, {30, 30, 40, 40, 40}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::GoodRod, {129, 118, 129, 119, 119}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Lake Acuity
        EncounterArea4(108, 0, Game::Blank, Encounter::SuperRod, {130, 119, 130, 119, 119}, {30, 30, 40, 40, 40}, {40, 40, 55, 55, 55}), // Lake Acuity
        EncounterArea4(109, 0, Game::Blank, Encounter::Surfing, {55, 55, 54, 54, 54}, {35, 35, 35, 35, 35}, {55, 55, 45, 45, 45}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::OldRod, {129, 129, 129, 129, 129}, {4, 3, 5, 5, 5}, {6, 7, 10, 10, 15}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::GoodRod, {129, 129, 129, 129, 129}, {15, 15, 10, 25, 25}, {20, 20, 25, 35, 35}), // Resort Area
        EncounterArea4(109, 0, Game::Blank, Encounter::SuperRod, {129, 129, 129, 129, 129}, {40, 30, 20, 10, 1}, {60, 70, 80, 90, 100}), // Resort Area
        EncounterArea4(110, 1, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Stark Mountain
        EncounterArea4(110, 2, Game::Blank, Encounter::Grass, {323, 112, 22, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Stark Mountain
        EncounterArea4(110, 3, Game::Blank, Encounter::Grass, {323, 112, 42, 75, 22, 110, 227, 75, 322, 111, 322, 111}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Stark Mountain
        EncounterArea4(110, 0, Game::Blank, Encounter::PokeRadar, {323, 112, 22, 75, 324, 324, 227, 75, 322, 111, 324, 324}, {53, 54, 51, 51, 53, 52, 53, 53, 51, 52, 51, 52}), // Stark Mountain
        EncounterArea4(111, 0, Game::Blank, Encounter::Grass, {219, 112, 42, 75, 42, 110, 110, 75, 218, 111, 218, 111}, {54, 54, 52, 51, 52, 53, 51, 53, 52, 52, 52, 52}), // Stark Mountain Entrance
        EncounterArea4(112, 0, Game::Blank, Encounter::Grass, {219, 219, 42, 75, 112, 110, 110, 75, 218, 109, 218, 109}, {53, 55, 53, 52, 55, 54, 52, 54, 53, 53, 53, 53}), // Stark Mountain Interior
    };

    const QVector<EncounterArea4> encountersHeartGold
    {
        EncounterArea4(113, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // New Bark Town
        EncounterArea4(113, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // New Bark Town
        EncounterArea4(113, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // New Bark Town
        EncounterArea4(113, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // New Bark Town
        EncounterArea4(114, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Cherrygrove City
        EncounterArea4(114, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cherrygrove City
        EncounterArea4(114, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cherrygrove City
        EncounterArea4(114, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cherrygrove City
        EncounterArea4(115, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Violet City
        EncounterArea4(115, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Violet City
        EncounterArea4(115, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Violet City
        EncounterArea4(115, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Violet City
        EncounterArea4(116, 0, 0, Encounter::RockSmash, {98, 213}, {15, 23}, {24, 28}), // Cianwood City
        EncounterArea4(116, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Cianwood City
        EncounterArea4(116, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cianwood City
        EncounterArea4(116, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cianwood City
        EncounterArea4(116, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cianwood City
        EncounterArea4(117, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Olivine City
        EncounterArea4(117, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Olivine City
        EncounterArea4(117, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Olivine City
        EncounterArea4(117, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Olivine City
        EncounterArea4(118, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Ecruteak City
        EncounterArea4(118, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Ecruteak City
        EncounterArea4(118, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Ecruteak City
        EncounterArea4(118, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Ecruteak City
        EncounterArea4(119, 0, 0, Encounter::Surfing, {129, 129, 130, 130, 130}, {10, 5, 10, 10, 10}, {20, 15, 20, 20, 20}), // Lake of Rage
        EncounterArea4(119, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Lake of Rage
        EncounterArea4(119, 0, 0, Encounter::GoodRod, {129, 129, 129, 130, 129}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Lake of Rage
        EncounterArea4(119, 0, 0, Encounter::SuperRod, {129, 130, 129, 129, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Lake of Rage
        EncounterArea4(120, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {10, 5, 2, 2, 2}, {20, 15, 10, 10, 10}), // Blackthorn City
        EncounterArea4(120, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Blackthorn City
        EncounterArea4(120, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Blackthorn City
        EncounterArea4(120, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Blackthorn City
        EncounterArea4(121, 1, 1, Encounter::Grass, {114, 77, 114, 77, 232, 232, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 2, 2, Encounter::Grass, {114, 77, 114, 77, 232, 232, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 3, 3, Encounter::Grass, {114, 77, 114, 77, 232, 232, 78, 78, 215, 215, 215, 215}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::Grass, {114, 77, 293, 293, 264, 264, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::Grass, {114, 77, 418, 418, 399, 399, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::Surfing, {61, 61, 60, 60, 61}, {30, 35, 30, 30, 48}, {40, 45, 40, 40, 48}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver
        EncounterArea4(122, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Pallet Town
        EncounterArea4(122, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Pallet Town
        EncounterArea4(122, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Pallet Town
        EncounterArea4(122, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Pallet Town
        EncounterArea4(123, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Viridian City
        EncounterArea4(123, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Viridian City
        EncounterArea4(123, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Viridian City
        EncounterArea4(123, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Viridian City
        EncounterArea4(124, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Cerulean City
        EncounterArea4(124, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cerulean City
        EncounterArea4(124, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cerulean City
        EncounterArea4(124, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cerulean City
        EncounterArea4(125, 0, 0, Encounter::RockSmash, {50, 213}, {24, 32}, {37, 35}), // Vermilion City
        EncounterArea4(125, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Vermilion City
        EncounterArea4(125, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Vermilion City
        EncounterArea4(125, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Vermilion City
        EncounterArea4(125, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Vermilion City
        EncounterArea4(126, 0, 0, Encounter::Surfing, {88, 88, 89, 89, 89}, {20, 15, 15, 15, 15}, {20, 15, 15, 15, 15}), // Celadon City
        EncounterArea4(127, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {20, 15, 10, 10, 10}, {20, 15, 10, 10, 10}), // Fuchsia City
        EncounterArea4(127, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Fuchsia City
        EncounterArea4(127, 0, 0, Encounter::GoodRod, {129, 129, 129, 130, 129}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Fuchsia City
        EncounterArea4(127, 0, 0, Encounter::SuperRod, {129, 130, 129, 129, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Fuchsia City
        EncounterArea4(128, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Cinnabar Island
        EncounterArea4(128, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cinnabar Island
        EncounterArea4(128, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cinnabar Island
        EncounterArea4(128, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cinnabar Island
        EncounterArea4(129, 1, 1, Encounter::Grass, {16, 19, 16, 19, 161, 161, 16, 16, 162, 16, 162, 16}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(129, 2, 2, Encounter::Grass, {16, 19, 16, 19, 161, 161, 16, 16, 162, 16, 162, 16}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(129, 3, 3, Encounter::Grass, {163, 19, 163, 19, 19, 19, 163, 163, 19, 163, 19, 163}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(129, 0, 0, Encounter::Grass, {16, 19, 311, 311, 312, 312, 16, 16, 162, 16, 162, 16}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(129, 0, 0, Encounter::Grass, {16, 19, 403, 403, 403, 403, 16, 16, 162, 16, 162, 16}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(130, 1, 1, Encounter::Grass, {10, 16, 10, 16, 11, 11, 12, 12, 17, 167, 17, 10}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(130, 2, 2, Encounter::Grass, {10, 16, 10, 16, 16, 16, 12, 12, 17, 17, 17, 10}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(130, 3, 3, Encounter::Grass, {163, 167, 163, 167, 163, 163, 164, 164, 168, 164, 168, 167}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(130, 0, 0, Encounter::Grass, {10, 16, 311, 311, 312, 312, 12, 12, 17, 167, 17, 10}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(130, 0, 0, Encounter::Grass, {10, 16, 403, 403, 403, 403, 12, 12, 17, 167, 17, 10}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(131, 1, 1, Encounter::Grass, {10, 16, 10, 16, 11, 11, 12, 12, 17, 167, 17, 10}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(131, 2, 2, Encounter::Grass, {10, 16, 10, 16, 11, 11, 16, 16, 17, 17, 17, 10}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(131, 3, 3, Encounter::Grass, {163, 167, 163, 167, 163, 163, 164, 164, 168, 164, 168, 167}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(131, 0, 0, Encounter::Grass, {10, 16, 311, 311, 312, 312, 12, 12, 17, 167, 17, 10}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(131, 0, 0, Encounter::Grass, {10, 16, 403, 403, 403, 403, 12, 12, 17, 167, 17, 10}, {3, 3, 3, 3, 5, 5, 7, 8, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(132, 1, 1, Encounter::Grass, {21, 19, 21, 19, 21, 21, 39, 39, 19, 21, 19, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(132, 2, 2, Encounter::Grass, {21, 19, 21, 19, 21, 21, 39, 39, 19, 21, 19, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(132, 3, 3, Encounter::Grass, {19, 41, 19, 41, 19, 19, 39, 39, 19, 19, 19, 19}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(132, 0, 0, Encounter::Grass, {21, 19, 311, 311, 312, 312, 39, 39, 19, 21, 19, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(132, 0, 0, Encounter::Grass, {21, 19, 403, 403, 403, 403, 39, 39, 19, 21, 19, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(133, 1, 1, Encounter::Grass, {21, 19, 21, 19, 21, 21, 39, 39, 19, 21, 19, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 2, 2, Encounter::Grass, {21, 19, 21, 19, 21, 21, 39, 39, 19, 21, 19, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 3, 3, Encounter::Grass, {21, 41, 21, 41, 19, 19, 39, 39, 19, 19, 19, 19}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::Grass, {21, 19, 293, 293, 264, 264, 39, 39, 19, 21, 19, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::Grass, {21, 19, 418, 418, 399, 399, 39, 39, 19, 21, 19, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 4
        EncounterArea4(134, 1, 1, Encounter::Grass, {16, 69, 16, 69, 16, 16, 16, 16, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(134, 2, 2, Encounter::Grass, {16, 69, 16, 69, 16, 16, 16, 16, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(134, 3, 3, Encounter::Grass, {43, 43, 43, 43, 69, 69, 44, 44, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(134, 0, 0, Encounter::Grass, {16, 69, 311, 311, 312, 312, 16, 16, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(134, 0, 0, Encounter::Grass, {16, 69, 403, 403, 403, 403, 16, 16, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(135, 1, 1, Encounter::Grass, {16, 69, 16, 69, 16, 16, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 2, 2, Encounter::Grass, {16, 69, 16, 69, 16, 16, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 3, 3, Encounter::Grass, {43, 43, 43, 43, 69, 69, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::Grass, {16, 69, 293, 293, 264, 264, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::Grass, {16, 69, 418, 418, 399, 399, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 6
        EncounterArea4(136, 1, 1, Encounter::Grass, {19, 21, 19, 21, 58, 58, 20, 20, 19, 19, 19, 19}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(136, 2, 2, Encounter::Grass, {19, 21, 19, 21, 58, 58, 20, 20, 19, 58, 19, 58}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(136, 3, 3, Encounter::Grass, {19, 198, 19, 198, 58, 58, 20, 20, 198, 228, 198, 228}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(136, 0, 0, Encounter::Grass, {19, 21, 311, 311, 312, 312, 20, 20, 19, 19, 19, 19}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(136, 0, 0, Encounter::Grass, {19, 21, 403, 403, 403, 403, 20, 20, 19, 19, 19, 19}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(137, 1, 1, Encounter::Grass, {17, 17, 17, 17, 63, 63, 58, 58, 17, 64, 17, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(137, 2, 2, Encounter::Grass, {17, 17, 17, 17, 63, 63, 58, 58, 17, 64, 17, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(137, 3, 3, Encounter::Grass, {164, 93, 164, 93, 63, 63, 164, 164, 58, 64, 58, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(137, 0, 0, Encounter::Grass, {17, 17, 311, 311, 312, 312, 58, 58, 17, 64, 17, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(137, 0, 0, Encounter::Grass, {17, 17, 403, 403, 403, 403, 58, 58, 17, 64, 17, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(138, 1, 1, Encounter::Grass, {56, 19, 56, 19, 21, 21, 20, 20, 22, 57, 22, 57}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 2, 2, Encounter::Grass, {56, 19, 56, 19, 21, 21, 20, 20, 22, 57, 22, 57}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 3, 3, Encounter::Grass, {56, 19, 56, 19, 20, 20, 19, 19, 20, 57, 20, 57}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::Grass, {56, 19, 293, 293, 264, 264, 20, 20, 22, 57, 22, 57}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::Grass, {56, 19, 418, 418, 399, 399, 20, 20, 22, 57, 22, 57}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {15, 10, 15, 15, 15}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 9
        EncounterArea4(139, 1, 1, Encounter::Grass, {21, 100, 21, 100, 20, 20, 22, 22, 20, 125, 20, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 2, 2, Encounter::Grass, {21, 100, 21, 100, 20, 20, 22, 22, 125, 125, 125, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 3, 3, Encounter::Grass, {195, 100, 195, 100, 20, 20, 195, 195, 20, 125, 20, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::Grass, {21, 100, 293, 293, 264, 264, 22, 22, 20, 125, 20, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::Grass, {21, 100, 418, 418, 399, 399, 22, 22, 20, 125, 20, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {15, 10, 15, 15, 15}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 10
        EncounterArea4(140, 0, 0, Encounter::Grass, {96, 19, 96, 19, 81, 81, 96, 96, 97, 97, 97, 97}, {14, 15, 14, 15, 15, 15, 16, 16, 16, 16, 16, 16}), // Route 11
        EncounterArea4(140, 0, 0, Encounter::Grass, {96, 19, 311, 311, 312, 312, 96, 96, 97, 97, 97, 97}, {14, 15, 14, 15, 15, 15, 16, 16, 16, 16, 16, 16}), // Route 11
        EncounterArea4(140, 0, 0, Encounter::Grass, {96, 19, 403, 403, 403, 403, 96, 96, 97, 97, 97, 97}, {14, 15, 14, 15, 15, 15, 16, 16, 16, 16, 16, 16}), // Route 11
        EncounterArea4(141, 0, 0, Encounter::Surfing, {72, 195, 73, 73, 73}, {25, 25, 25, 25, 25}, {25, 25, 25, 25, 25}), // Route 12
        EncounterArea4(141, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 12
        EncounterArea4(141, 0, 0, Encounter::GoodRod, {129, 72, 72, 72, 72}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 12
        EncounterArea4(141, 0, 0, Encounter::SuperRod, {72, 72, 129, 211, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 12
        EncounterArea4(142, 1, 1, Encounter::Grass, {30, 33, 30, 33, 17, 17, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 2, 2, Encounter::Grass, {30, 33, 30, 33, 17, 17, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 3, 3, Encounter::Grass, {30, 33, 30, 33, 164, 164, 195, 195, 195, 195, 195, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::Grass, {30, 33, 293, 293, 264, 264, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::Grass, {30, 33, 418, 418, 399, 399, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::Surfing, {72, 195, 73, 73, 73}, {25, 25, 25, 25, 25}, {25, 25, 25, 25, 25}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::GoodRod, {129, 72, 72, 72, 72}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::SuperRod, {72, 72, 129, 211, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 13
        EncounterArea4(143, 1, 1, Encounter::Grass, {30, 33, 30, 33, 17, 17, 187, 187, 188, 188, 188, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(143, 2, 2, Encounter::Grass, {30, 33, 30, 33, 17, 17, 187, 187, 188, 188, 188, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(143, 3, 3, Encounter::Grass, {30, 33, 30, 33, 164, 164, 195, 195, 195, 195, 195, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(143, 0, 0, Encounter::Grass, {30, 33, 311, 311, 312, 312, 187, 187, 188, 188, 188, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(143, 0, 0, Encounter::Grass, {30, 33, 403, 403, 403, 403, 187, 187, 188, 188, 188, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(144, 1, 1, Encounter::Grass, {30, 33, 30, 33, 17, 17, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(144, 2, 2, Encounter::Grass, {30, 33, 30, 33, 17, 17, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(144, 3, 3, Encounter::Grass, {30, 33, 30, 33, 164, 164, 195, 195, 195, 195, 195, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(144, 0, 0, Encounter::Grass, {30, 33, 311, 311, 312, 312, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(144, 0, 0, Encounter::Grass, {30, 33, 403, 403, 403, 403, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(145, 1, 1, Encounter::Grass, {88, 22, 88, 22, 88, 88, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(145, 2, 2, Encounter::Grass, {88, 22, 88, 22, 88, 88, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(145, 3, 3, Encounter::Grass, {88, 88, 88, 88, 88, 88, 198, 198, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(145, 0, 0, Encounter::Grass, {88, 22, 311, 311, 312, 312, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(145, 0, 0, Encounter::Grass, {88, 22, 403, 403, 403, 403, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(146, 1, 1, Encounter::Grass, {22, 88, 22, 88, 88, 88, 22, 22, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(146, 2, 2, Encounter::Grass, {22, 218, 22, 218, 88, 88, 22, 22, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(146, 3, 3, Encounter::Grass, {88, 88, 88, 88, 88, 88, 89, 89, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(146, 0, 0, Encounter::Grass, {22, 88, 311, 311, 312, 312, 22, 22, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(146, 0, 0, Encounter::Grass, {22, 88, 403, 403, 403, 403, 22, 22, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(147, 1, 1, Encounter::Grass, {88, 22, 88, 22, 88, 88, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(147, 2, 2, Encounter::Grass, {88, 22, 88, 22, 88, 88, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(147, 3, 3, Encounter::Grass, {88, 88, 88, 88, 88, 88, 89, 89, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(147, 0, 0, Encounter::Grass, {88, 22, 311, 311, 312, 312, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(147, 0, 0, Encounter::Grass, {88, 22, 403, 403, 403, 403, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(148, 0, 0, Encounter::RockSmash, {99, 98}, {28, 24}, {31, 27}), // Route 19
        EncounterArea4(148, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Route 19
        EncounterArea4(148, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 19
        EncounterArea4(148, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 19
        EncounterArea4(148, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 19
        EncounterArea4(149, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Route 20
        EncounterArea4(149, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 20
        EncounterArea4(149, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 20
        EncounterArea4(149, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 20
        EncounterArea4(150, 1, 1, Encounter::Grass, {114, 114, 114, 114, 114, 114, 114, 114, 114, 122, 114, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 2, 2, Encounter::Grass, {114, 114, 114, 114, 114, 114, 114, 114, 122, 122, 122, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 3, 3, Encounter::Grass, {114, 114, 114, 114, 114, 114, 114, 114, 114, 122, 114, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::Grass, {114, 114, 293, 293, 264, 264, 114, 114, 114, 122, 114, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::Grass, {114, 114, 418, 418, 399, 399, 114, 114, 114, 122, 114, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 21
        EncounterArea4(151, 1, 1, Encounter::Grass, {19, 21, 19, 21, 21, 21, 84, 84, 77, 22, 77, 22}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 2, 2, Encounter::Grass, {19, 21, 19, 21, 21, 21, 84, 84, 77, 22, 77, 22}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 3, 3, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 77, 19, 77, 19}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::Grass, {19, 21, 293, 293, 264, 264, 84, 84, 77, 22, 77, 22}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::Grass, {19, 21, 418, 418, 399, 399, 84, 84, 77, 22, 77, 22}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 22
        EncounterArea4(152, 1, 1, Encounter::Grass, {69, 69, 69, 69, 63, 63, 70, 70, 48, 70, 48, 70}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 2, 2, Encounter::Grass, {69, 191, 69, 191, 63, 63, 70, 70, 69, 70, 69, 70}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 3, 3, Encounter::Grass, {48, 43, 48, 43, 63, 63, 70, 70, 69, 49, 69, 49}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::Grass, {69, 69, 293, 293, 264, 264, 70, 70, 48, 70, 48, 70}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::Grass, {69, 69, 418, 418, 399, 399, 70, 70, 48, 70, 48, 70}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 24
        EncounterArea4(153, 1, 1, Encounter::Grass, {16, 69, 16, 69, 48, 48, 63, 63, 17, 70, 17, 70}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 2, 2, Encounter::Grass, {16, 69, 16, 69, 16, 16, 63, 63, 17, 70, 17, 70}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 3, 3, Encounter::Grass, {48, 43, 48, 43, 49, 49, 63, 63, 70, 69, 70, 69}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::Grass, {16, 69, 293, 293, 264, 264, 63, 63, 17, 70, 17, 70}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::Grass, {16, 69, 418, 418, 399, 399, 63, 63, 17, 70, 17, 70}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 25
        EncounterArea4(154, 1, 1, Encounter::Grass, {84, 28, 84, 28, 77, 77, 84, 84, 20, 85, 20, 85}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 2, 2, Encounter::Grass, {84, 28, 84, 28, 77, 77, 84, 84, 20, 85, 20, 85}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 3, 3, Encounter::Grass, {20, 28, 20, 28, 77, 77, 20, 20, 195, 195, 195, 195}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::Grass, {84, 28, 293, 293, 264, 264, 84, 84, 20, 85, 20, 85}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::Grass, {84, 28, 418, 418, 399, 399, 84, 84, 20, 85, 20, 85}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {30, 25, 30, 30, 30}, {30, 25, 30, 30, 30}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 26
        EncounterArea4(155, 1, 1, Encounter::Grass, {84, 20, 84, 20, 84, 84, 20, 20, 77, 28, 77, 28}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 2, 2, Encounter::Grass, {84, 20, 84, 20, 84, 84, 20, 20, 77, 28, 77, 28}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 3, 3, Encounter::Grass, {195, 20, 195, 20, 195, 195, 20, 20, 77, 28, 77, 28}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::Grass, {84, 20, 293, 293, 264, 264, 20, 20, 77, 28, 77, 28}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::Grass, {84, 20, 418, 418, 399, 399, 20, 20, 77, 28, 77, 28}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {20, 15, 20, 20, 20}, {20, 15, 20, 20, 20}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 27
        EncounterArea4(156, 1, 1, Encounter::Grass, {114, 77, 114, 77, 232, 232, 78, 78, 84, 85, 84, 85}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 2, 2, Encounter::Grass, {114, 77, 114, 77, 232, 232, 78, 78, 84, 85, 84, 85}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 3, 3, Encounter::Grass, {114, 77, 114, 77, 232, 232, 215, 215, 78, 78, 78, 78}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::Grass, {114, 77, 293, 293, 264, 264, 78, 78, 84, 85, 84, 85}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::Grass, {114, 77, 418, 418, 399, 399, 78, 78, 84, 85, 84, 85}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {40, 35, 40, 40, 40}, {40, 35, 40, 40, 40}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 28
        EncounterArea4(157, 1, 1, Encounter::Grass, {16, 161, 16, 161, 16, 16, 161, 161, 19, 16, 19, 16}, {2, 3, 2, 3, 3, 3, 2, 2, 4, 4, 4, 4}), // Route 29
        EncounterArea4(157, 2, 2, Encounter::Grass, {16, 161, 16, 161, 16, 16, 161, 161, 19, 16, 19, 16}, {2, 3, 2, 3, 3, 3, 2, 2, 4, 4, 4, 4}), // Route 29
        EncounterArea4(157, 3, 3, Encounter::Grass, {163, 163, 163, 163, 163, 163, 19, 19, 19, 163, 19, 163}, {2, 3, 2, 3, 3, 3, 2, 2, 4, 4, 4, 4}), // Route 29
        EncounterArea4(157, 0, 0, Encounter::Grass, {16, 161, 311, 311, 312, 312, 161, 161, 19, 16, 19, 16}, {2, 3, 2, 3, 3, 3, 2, 2, 4, 4, 4, 4}), // Route 29
        EncounterArea4(157, 0, 0, Encounter::Grass, {16, 161, 403, 403, 403, 403, 161, 161, 19, 16, 19, 16}, {2, 3, 2, 3, 3, 3, 2, 2, 4, 4, 4, 4}), // Route 29
        EncounterArea4(158, 1, 1, Encounter::Grass, {16, 10, 16, 10, 10, 10, 11, 11, 16, 16, 16, 16}, {2, 3, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 2, 2, Encounter::Grass, {16, 10, 16, 10, 16, 16, 11, 11, 10, 11, 10, 11}, {2, 3, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 3, 3, Encounter::Grass, {167, 19, 167, 19, 163, 163, 19, 19, 163, 163, 163, 163}, {2, 3, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::Grass, {16, 10, 293, 293, 264, 264, 11, 11, 16, 16, 16, 16}, {2, 3, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::Grass, {16, 10, 418, 418, 399, 399, 11, 11, 16, 16, 16, 16}, {2, 3, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {15, 10, 15, 15, 32}, {25, 20, 25, 25, 32}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 30
        EncounterArea4(159, 1, 1, Encounter::Grass, {16, 10, 16, 10, 69, 69, 11, 11, 10, 11, 10, 11}, {3, 4, 3, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 2, 2, Encounter::Grass, {16, 10, 16, 10, 69, 69, 11, 11, 10, 11, 10, 11}, {3, 4, 3, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 3, 3, Encounter::Grass, {167, 19, 167, 19, 69, 69, 19, 19, 163, 163, 163, 163}, {3, 4, 3, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::Grass, {16, 10, 293, 293, 264, 264, 11, 11, 10, 11, 10, 11}, {3, 4, 3, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::Grass, {16, 10, 418, 418, 399, 399, 11, 11, 10, 11, 10, 11}, {3, 4, 3, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {15, 10, 15, 15, 32}, {25, 20, 25, 25, 32}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 31
        EncounterArea4(160, 1, 1, Encounter::Grass, {69, 19, 69, 19, 179, 179, 187, 187, 19, 41, 19, 41}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 2, 2, Encounter::Grass, {69, 19, 69, 19, 179, 179, 187, 187, 19, 19, 19, 19}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 3, 3, Encounter::Grass, {194, 19, 194, 19, 69, 69, 179, 179, 194, 41, 194, 41}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::Grass, {69, 19, 293, 293, 264, 264, 187, 187, 19, 41, 19, 41}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::Grass, {69, 19, 418, 418, 399, 399, 187, 187, 19, 41, 19, 41}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::Surfing, {72, 195, 73, 73, 73}, {10, 15, 15, 15, 36}, {20, 25, 25, 25, 36}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::GoodRod, {129, 72, 72, 72, 211}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::SuperRod, {72, 72, 129, 211, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 32
        EncounterArea4(161, 1, 1, Encounter::Grass, {187, 19, 187, 19, 21, 21, 19, 19, 187, 41, 187, 41}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(161, 2, 2, Encounter::Grass, {187, 19, 187, 19, 21, 21, 19, 19, 187, 19, 187, 19}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(161, 3, 3, Encounter::Grass, {41, 19, 41, 19, 19, 19, 19, 19, 41, 41, 41, 41}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(161, 0, 0, Encounter::Grass, {187, 19, 311, 311, 312, 312, 19, 19, 187, 41, 187, 41}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(161, 0, 0, Encounter::Grass, {187, 19, 403, 403, 403, 403, 19, 19, 187, 41, 187, 41}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(162, 0, 0, Encounter::Grass, {96, 19, 96, 19, 96, 96, 63, 63, 19, 132, 19, 132}, {10, 11, 10, 11, 12, 12, 10, 10, 13, 10, 13, 10}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::Grass, {96, 19, 293, 293, 264, 264, 63, 63, 19, 132, 19, 132}, {10, 11, 10, 11, 12, 12, 10, 10, 13, 10, 13, 10}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::Grass, {96, 19, 418, 418, 399, 399, 63, 63, 19, 132, 19, 132}, {10, 11, 10, 11, 12, 12, 10, 10, 13, 10, 13, 10}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 29}, {25, 20, 25, 25, 29}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 34
        EncounterArea4(163, 1, 1, Encounter::Grass, {32, 29, 32, 29, 96, 96, 63, 63, 16, 132, 16, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 2, 2, Encounter::Grass, {32, 29, 32, 29, 96, 96, 63, 63, 16, 132, 16, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 3, 3, Encounter::Grass, {32, 29, 32, 29, 96, 96, 63, 63, 163, 132, 163, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::Grass, {32, 29, 293, 293, 264, 264, 63, 63, 16, 132, 16, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::Grass, {32, 29, 418, 418, 399, 399, 63, 63, 16, 132, 16, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {15, 10, 15, 15, 31}, {25, 20, 25, 25, 31}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 35
        EncounterArea4(164, 1, 1, Encounter::Grass, {32, 29, 32, 29, 16, 16, 58, 58, 234, 16, 234, 16}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(164, 2, 2, Encounter::Grass, {32, 29, 32, 29, 16, 16, 58, 58, 234, 58, 234, 58}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(164, 3, 3, Encounter::Grass, {32, 29, 32, 29, 163, 163, 58, 58, 234, 163, 234, 163}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(164, 0, 0, Encounter::Grass, {32, 29, 311, 311, 312, 312, 58, 58, 234, 16, 234, 16}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(164, 0, 0, Encounter::Grass, {32, 29, 403, 403, 403, 403, 58, 58, 234, 16, 234, 16}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(165, 1, 1, Encounter::Grass, {16, 234, 16, 234, 16, 16, 58, 58, 16, 16, 16, 16}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(165, 2, 2, Encounter::Grass, {16, 234, 16, 234, 16, 16, 58, 58, 17, 58, 17, 58}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(165, 3, 3, Encounter::Grass, {167, 234, 167, 234, 163, 163, 58, 58, 167, 167, 167, 167}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(165, 0, 0, Encounter::Grass, {16, 234, 311, 311, 312, 312, 58, 58, 16, 16, 16, 16}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(165, 0, 0, Encounter::Grass, {16, 234, 403, 403, 403, 403, 58, 58, 16, 16, 16, 16}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(166, 1, 1, Encounter::Grass, {19, 20, 19, 20, 81, 81, 83, 83, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(166, 2, 2, Encounter::Grass, {19, 20, 19, 20, 81, 81, 83, 83, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(166, 3, 3, Encounter::Grass, {19, 20, 19, 20, 81, 81, 19, 19, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(166, 0, 0, Encounter::Grass, {19, 20, 311, 311, 312, 312, 83, 83, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(166, 0, 0, Encounter::Grass, {19, 20, 403, 403, 403, 403, 83, 83, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(167, 1, 1, Encounter::Grass, {19, 20, 19, 20, 81, 81, 83, 83, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(167, 2, 2, Encounter::Grass, {19, 20, 19, 20, 81, 81, 83, 83, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(167, 3, 3, Encounter::Grass, {19, 20, 19, 20, 81, 81, 19, 19, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(167, 0, 0, Encounter::Grass, {19, 20, 311, 311, 312, 312, 83, 83, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(167, 0, 0, Encounter::Grass, {19, 20, 403, 403, 403, 403, 83, 83, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(168, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Route 40
        EncounterArea4(168, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 40
        EncounterArea4(168, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 40
        EncounterArea4(168, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 40
        EncounterArea4(169, 0, 0, Encounter::Surfing, {72, 73, 226, 226, 226}, {15, 15, 15, 15, 15}, {25, 25, 25, 25, 25}), // Route 41
        EncounterArea4(169, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 41
        EncounterArea4(169, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 41
        EncounterArea4(169, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 41
        EncounterArea4(170, 1, 1, Encounter::Grass, {56, 179, 56, 179, 21, 21, 21, 21, 180, 180, 180, 180}, {15, 13, 15, 13, 14, 14, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 2, 2, Encounter::Grass, {56, 179, 56, 179, 21, 21, 21, 21, 180, 180, 180, 180}, {15, 13, 15, 13, 14, 14, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 3, 3, Encounter::Grass, {56, 179, 56, 179, 41, 41, 41, 41, 180, 180, 180, 180}, {15, 13, 15, 13, 14, 14, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::Grass, {56, 179, 293, 293, 264, 264, 21, 21, 180, 180, 180, 180}, {15, 13, 15, 13, 14, 14, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::Grass, {56, 179, 418, 418, 399, 399, 21, 21, 180, 180, 180, 180}, {15, 13, 15, 13, 14, 14, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 42
        EncounterArea4(171, 1, 1, Encounter::Grass, {180, 203, 180, 203, 17, 17, 179, 179, 48, 17, 48, 17}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 2, 2, Encounter::Grass, {180, 203, 180, 203, 17, 17, 179, 179, 180, 180, 180, 180}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 3, 3, Encounter::Grass, {180, 203, 180, 203, 164, 164, 48, 48, 179, 48, 179, 48}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::Grass, {180, 203, 293, 293, 264, 264, 179, 179, 48, 17, 48, 17}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::Grass, {180, 203, 418, 418, 399, 399, 179, 179, 48, 17, 48, 17}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {15, 10, 5, 5, 50}, {25, 20, 15, 15, 50}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 43
        EncounterArea4(172, 0, 0, Encounter::Grass, {114, 70, 114, 70, 69, 69, 108, 108, 70, 108, 70, 108}, {23, 22, 23, 22, 22, 22, 24, 24, 24, 26, 24, 26}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::Grass, {114, 70, 293, 293, 264, 264, 108, 108, 70, 108, 70, 108}, {23, 22, 23, 22, 22, 22, 24, 24, 24, 26, 24, 26}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::Grass, {114, 70, 418, 418, 399, 399, 108, 108, 70, 108, 70, 108}, {23, 22, 23, 22, 22, 22, 24, 24, 24, 26, 24, 26}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {20, 15, 20, 20, 20}, {30, 25, 30, 30, 30}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 223}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::SuperRod, {60, 60, 129, 223, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 44
        EncounterArea4(173, 0, 0, Encounter::Grass, {74, 75, 74, 75, 207, 207, 231, 231, 75, 75, 75, 75}, {23, 23, 23, 23, 24, 24, 20, 20, 25, 27, 25, 27}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::Grass, {74, 75, 293, 293, 264, 264, 231, 231, 75, 75, 75, 75}, {23, 23, 23, 23, 24, 24, 20, 20, 25, 27, 25, 27}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::Grass, {74, 75, 418, 418, 399, 399, 231, 231, 75, 75, 75, 75}, {23, 23, 23, 23, 24, 24, 20, 20, 25, 27, 25, 27}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {15, 10, 2, 2, 2}, {25, 20, 10, 10, 10}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 45
        EncounterArea4(174, 1, 1, Encounter::Grass, {74, 21, 74, 21, 19, 19, 74, 74, 21, 19, 21, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(174, 2, 2, Encounter::Grass, {74, 21, 74, 21, 19, 19, 74, 74, 21, 19, 21, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(174, 3, 3, Encounter::Grass, {74, 19, 74, 19, 19, 19, 74, 74, 74, 19, 74, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(174, 0, 0, Encounter::Grass, {74, 21, 311, 311, 312, 312, 74, 74, 21, 19, 21, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(174, 0, 0, Encounter::Grass, {74, 21, 403, 403, 403, 403, 74, 74, 21, 19, 21, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(175, 1, 1, Encounter::Grass, {83, 241, 132, 132, 132, 132, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 2, 2, Encounter::Grass, {83, 241, 132, 132, 132, 132, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 3, 3, Encounter::Grass, {164, 241, 132, 132, 132, 132, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::Grass, {83, 241, 293, 293, 264, 264, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::Grass, {83, 241, 418, 418, 399, 399, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::Surfing, {72, 86, 120, 120, 120}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 47
        EncounterArea4(176, 1, 1, Encounter::Grass, {83, 128, 187, 22, 44, 44, 58, 203, 50, 58, 187, 128}, {25, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(176, 2, 2, Encounter::Grass, {83, 128, 187, 22, 44, 44, 58, 203, 50, 58, 187, 128}, {25, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(176, 3, 3, Encounter::Grass, {58, 128, 187, 22, 44, 44, 58, 203, 50, 58, 187, 128}, {25, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(176, 0, 0, Encounter::Grass, {83, 128, 311, 311, 312, 312, 58, 203, 50, 58, 187, 128}, {25, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(176, 0, 0, Encounter::Grass, {83, 128, 403, 403, 403, 403, 58, 203, 50, 58, 187, 128}, {25, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(177, 0, 0, Encounter::Grass, {50, 50, 50, 50, 50, 50, 50, 50, 51, 51, 51, 51}, {15, 17, 15, 17, 19, 19, 13, 13, 19, 24, 19, 29}), // Diglettï¿½s Cave
        EncounterArea4(177, 0, 0, Encounter::Grass, {50, 50, 359, 359, 296, 296, 50, 50, 51, 51, 51, 51}, {15, 17, 15, 17, 19, 19, 13, 13, 19, 24, 19, 29}), // Diglettï¿½s Cave
        EncounterArea4(177, 0, 0, Encounter::Grass, {50, 50, 436, 436, 433, 433, 50, 50, 51, 51, 51, 51}, {15, 17, 15, 17, 19, 19, 13, 13, 19, 24, 19, 29}), // Diglettï¿½s Cave
        EncounterArea4(178, 0, 0, Encounter::Grass, {41, 74, 41, 74, 27, 27, 46, 46, 28, 35, 28, 35}, {6, 8, 6, 8, 8, 8, 12, 12, 10, 8, 10, 8}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::Grass, {41, 74, 359, 359, 296, 296, 46, 46, 28, 35, 28, 35}, {6, 8, 6, 8, 8, 8, 12, 12, 10, 8, 10, 8}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::Grass, {41, 74, 436, 436, 433, 433, 46, 46, 28, 35, 28, 35}, {6, 8, 6, 8, 8, 8, 12, 12, 10, 8, 10, 8}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::Surfing, {60, 129, 129, 129, 129}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::GoodRod, {129, 129, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::SuperRod, {60, 60, 60, 60, 60}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Moon
        EncounterArea4(179, 0, 0, Encounter::Surfing, {60, 60, 60, 60, 60}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Mt. Moon (Clefairy)
        EncounterArea4(179, 0, 0, Encounter::OldRod, {60, 60, 60, 129, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Moon (Clefairy)
        EncounterArea4(179, 0, 0, Encounter::GoodRod, {60, 60, 60, 129, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Moon (Clefairy)
        EncounterArea4(179, 0, 0, Encounter::SuperRod, {60, 60, 60, 129, 60}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Moon (Clefairy)
        EncounterArea4(180, 1, 1, Encounter::Grass, {67, 47, 42, 57, 82, 132, 101, 202, 57, 67, 82, 132}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 2, 2, Encounter::Grass, {67, 47, 42, 57, 82, 132, 101, 202, 57, 67, 82, 132}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 3, 3, Encounter::Grass, {42, 42, 42, 47, 82, 132, 101, 202, 57, 67, 67, 67}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::Grass, {67, 47, 359, 359, 296, 296, 101, 202, 57, 67, 82, 132}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::Grass, {67, 47, 436, 436, 433, 433, 101, 202, 57, 67, 82, 132}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::RockSmash, {74, 75}, {22, 26}, {24, 30}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {40, 35, 40, 40, 40}, {40, 35, 40, 40, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::GoodRod, {60, 118, 129, 118, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::SuperRod, {60, 61, 130, 130, 130}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cerulean Cave 1F
        EncounterArea4(181, 1, 1, Encounter::Grass, {64, 47, 42, 67, 82, 132, 101, 202, 67, 67, 67, 67}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 2, 2, Encounter::Grass, {64, 47, 42, 67, 82, 132, 101, 202, 67, 67, 67, 67}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 3, 3, Encounter::Grass, {64, 47, 42, 67, 82, 132, 101, 202, 42, 42, 42, 42}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::Grass, {64, 47, 359, 359, 296, 296, 101, 202, 67, 67, 67, 67}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::Grass, {64, 47, 436, 436, 433, 433, 101, 202, 67, 67, 67, 67}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {40, 35, 40, 40, 40}, {40, 35, 40, 40, 40}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::GoodRod, {60, 118, 129, 118, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::SuperRod, {60, 61, 130, 130, 130}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cerulean Cave 2F
        EncounterArea4(182, 0, 0, Encounter::Grass, {64, 47, 42, 67, 82, 132, 101, 82, 47, 202, 47, 202}, {46, 45, 47, 45, 45, 45, 46, 47, 47, 49, 47, 49}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::Grass, {64, 47, 359, 359, 296, 296, 101, 82, 47, 202, 47, 202}, {46, 45, 47, 45, 45, 45, 46, 47, 47, 49, 47, 49}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::Grass, {64, 47, 436, 436, 433, 433, 101, 82, 47, 202, 47, 202}, {46, 45, 47, 45, 45, 45, 46, 47, 47, 49, 47, 49}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::RockSmash, {74, 75}, {22, 26}, {24, 30}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {40, 35, 40, 40, 40}, {40, 35, 40, 40, 40}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::GoodRod, {60, 118, 129, 118, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::SuperRod, {60, 61, 130, 130, 130}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cerulean Cave B1F
        EncounterArea4(183, 0, 0, Encounter::Grass, {104, 74, 104, 74, 66, 66, 41, 41, 67, 104, 67, 104}, {10, 10, 10, 10, 12, 12, 8, 8, 14, 13, 14, 13}), // Rock Tunnel 1F
        EncounterArea4(183, 0, 0, Encounter::Grass, {104, 74, 359, 359, 296, 296, 41, 41, 67, 104, 67, 104}, {10, 10, 10, 10, 12, 12, 8, 8, 14, 13, 14, 13}), // Rock Tunnel 1F
        EncounterArea4(183, 0, 0, Encounter::Grass, {104, 74, 436, 436, 433, 433, 41, 41, 67, 104, 67, 104}, {10, 10, 10, 10, 12, 12, 8, 8, 14, 13, 14, 13}), // Rock Tunnel 1F
        EncounterArea4(184, 0, 0, Encounter::Grass, {104, 74, 104, 74, 95, 95, 41, 41, 105, 115, 105, 115}, {12, 12, 12, 12, 16, 16, 10, 10, 14, 14, 14, 14}), // Rock Tunnel B1F
        EncounterArea4(184, 0, 0, Encounter::Grass, {104, 74, 359, 359, 296, 296, 41, 41, 105, 115, 105, 115}, {12, 12, 12, 12, 16, 16, 10, 10, 14, 14, 14, 14}), // Rock Tunnel B1F
        EncounterArea4(184, 0, 0, Encounter::Grass, {104, 74, 436, 436, 433, 433, 41, 41, 105, 115, 105, 115}, {12, 12, 12, 12, 16, 16, 10, 10, 14, 14, 14, 14}), // Rock Tunnel B1F
        EncounterArea4(184, 0, 0, Encounter::RockSmash, {74, 74}, {12, 17}, {16, 21}), // Rock Tunnel B1F
        EncounterArea4(185, 0, 0, Encounter::Grass, {41, 42, 54, 54, 42, 55, 41, 41, 54, 54, 54, 54}, {28, 32, 28, 29, 30, 32, 27, 26, 27, 26, 27, 26}), // Seafoam Islands 1F
        EncounterArea4(185, 0, 0, Encounter::Grass, {41, 42, 359, 359, 296, 296, 41, 41, 54, 54, 54, 54}, {28, 32, 28, 29, 30, 32, 27, 26, 27, 26, 27, 26}), // Seafoam Islands 1F
        EncounterArea4(185, 0, 0, Encounter::Grass, {41, 42, 436, 436, 433, 433, 41, 41, 54, 54, 54, 54}, {28, 32, 28, 29, 30, 32, 27, 26, 27, 26, 27, 26}), // Seafoam Islands 1F
        EncounterArea4(186, 0, 0, Encounter::Grass, {86, 42, 54, 86, 42, 55, 41, 41, 55, 54, 54, 54}, {32, 34, 28, 34, 32, 34, 29, 28, 32, 28, 27, 26}), // Seafoam Islands B1F
        EncounterArea4(186, 0, 0, Encounter::Grass, {86, 42, 359, 359, 296, 296, 41, 41, 55, 54, 54, 54}, {32, 34, 28, 34, 32, 34, 29, 28, 32, 28, 27, 26}), // Seafoam Islands B1F
        EncounterArea4(186, 0, 0, Encounter::Grass, {86, 42, 436, 436, 433, 433, 41, 41, 55, 54, 54, 54}, {32, 34, 28, 34, 32, 34, 29, 28, 32, 28, 27, 26}), // Seafoam Islands B1F
        EncounterArea4(187, 0, 0, Encounter::Grass, {86, 42, 54, 86, 42, 55, 41, 41, 55, 54, 54, 54}, {33, 35, 30, 35, 33, 35, 30, 29, 33, 29, 28, 27}), // Seafoam Islands B2F
        EncounterArea4(187, 0, 0, Encounter::Grass, {86, 42, 359, 359, 296, 296, 41, 41, 55, 54, 54, 54}, {33, 35, 30, 35, 33, 35, 30, 29, 33, 29, 28, 27}), // Seafoam Islands B2F
        EncounterArea4(187, 0, 0, Encounter::Grass, {86, 42, 436, 436, 433, 433, 41, 41, 55, 54, 54, 54}, {33, 35, 30, 35, 33, 35, 30, 29, 33, 29, 28, 27}), // Seafoam Islands B2F
        EncounterArea4(188, 0, 0, Encounter::Grass, {87, 42, 54, 86, 42, 55, 41, 41, 55, 87, 54, 54}, {35, 36, 32, 34, 34, 36, 32, 31, 34, 36, 32, 31}), // Seafoam Islands B3F
        EncounterArea4(188, 0, 0, Encounter::Grass, {87, 42, 359, 359, 296, 296, 41, 41, 55, 87, 54, 54}, {35, 36, 32, 34, 34, 36, 32, 31, 34, 36, 32, 31}), // Seafoam Islands B3F
        EncounterArea4(188, 0, 0, Encounter::Grass, {87, 42, 436, 436, 433, 433, 41, 41, 55, 87, 54, 54}, {35, 36, 32, 34, 34, 36, 32, 31, 34, 36, 32, 31}), // Seafoam Islands B3F
        EncounterArea4(189, 0, 0, Encounter::Grass, {87, 42, 54, 86, 124, 55, 42, 42, 55, 87, 124, 124}, {37, 40, 34, 34, 38, 38, 39, 38, 37, 38, 40, 40}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::Grass, {87, 42, 359, 359, 296, 296, 42, 42, 55, 87, 124, 124}, {37, 40, 34, 34, 38, 38, 39, 38, 37, 38, 40, 40}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::Grass, {87, 42, 436, 436, 433, 433, 42, 42, 55, 87, 124, 124}, {37, 40, 34, 34, 38, 38, 39, 38, 37, 38, 40, 40}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::Surfing, {86, 116, 80, 80, 80}, {30, 30, 35, 50, 35}, {40, 40, 45, 50, 45}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::GoodRod, {129, 54, 98, 116, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::SuperRod, {130, 116, 99, 117, 117}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Seafoam Islands B4F
        EncounterArea4(190, 1, 1, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(190, 2, 2, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(190, 3, 3, Encounter::Grass, {92, 92, 92, 92, 92, 92, 19, 19, 92, 19, 92, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(190, 0, 0, Encounter::Grass, {19, 19, 263, 263, 327, 327, 19, 19, 19, 19, 19, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(190, 0, 0, Encounter::Grass, {19, 19, 441, 441, 307, 307, 19, 19, 19, 19, 19, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(191, 1, 1, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(191, 2, 2, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(191, 3, 3, Encounter::Grass, {92, 92, 92, 92, 92, 92, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(191, 0, 0, Encounter::Grass, {19, 19, 263, 263, 327, 327, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(191, 0, 0, Encounter::Grass, {19, 19, 441, 441, 307, 307, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(192, 0, 0, Encounter::Grass, {19, 109, 19, 109, 19, 19, 41, 41, 109, 20, 109, 20}, {13, 14, 13, 14, 15, 15, 14, 14, 16, 15, 16, 15}), // Burned Tower 1F
        EncounterArea4(192, 0, 0, Encounter::Grass, {19, 109, 263, 263, 327, 327, 41, 41, 109, 20, 109, 20}, {13, 14, 13, 14, 15, 15, 14, 14, 16, 15, 16, 15}), // Burned Tower 1F
        EncounterArea4(192, 0, 0, Encounter::Grass, {19, 109, 441, 441, 307, 307, 41, 41, 109, 20, 109, 20}, {13, 14, 13, 14, 15, 15, 14, 14, 16, 15, 16, 15}), // Burned Tower 1F
        EncounterArea4(193, 1, 1, Encounter::Grass, {19, 109, 19, 109, 109, 109, 19, 19, 41, 126, 41, 126}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(193, 2, 2, Encounter::Grass, {19, 109, 19, 109, 109, 109, 126, 126, 41, 19, 41, 19}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(193, 3, 3, Encounter::Grass, {19, 109, 19, 109, 109, 109, 19, 19, 41, 126, 41, 126}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(193, 0, 0, Encounter::Grass, {19, 109, 263, 263, 327, 327, 19, 19, 41, 126, 41, 126}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(193, 0, 0, Encounter::Grass, {19, 109, 441, 441, 307, 307, 19, 19, 41, 126, 41, 126}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(194, 1, 1, Encounter::Grass, {10, 11, 10, 11, 10, 10, 16, 16, 16, 16, 16, 16}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(194, 2, 2, Encounter::Grass, {10, 11, 10, 11, 191, 191, 16, 16, 191, 16, 191, 16}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(194, 3, 3, Encounter::Grass, {163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(194, 0, 0, Encounter::Grass, {10, 11, 311, 311, 312, 312, 16, 16, 16, 16, 16, 16}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(194, 0, 0, Encounter::Grass, {10, 11, 403, 403, 403, 403, 16, 16, 16, 16, 16, 16}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(195, 0, 0, Encounter::Grass, {177, 177, 177, 177, 177, 177, 177, 177, 235, 235, 235, 235}, {20, 22, 20, 22, 18, 18, 24, 24, 20, 22, 20, 22}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::Grass, {177, 177, 293, 293, 264, 264, 177, 177, 235, 235, 235, 235}, {20, 22, 20, 22, 18, 18, 24, 24, 20, 22, 20, 22}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::Grass, {177, 177, 418, 418, 399, 399, 177, 177, 235, 235, 235, 235}, {20, 22, 20, 22, 18, 18, 24, 24, 20, 22, 20, 22}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::RockSmash, {74, 74}, {8, 3}, {14, 6}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::Surfing, {194, 195, 195, 195, 195}, {10, 15, 10, 10, 10}, {20, 25, 20, 20, 20}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Ruins of Alph (Outside)
        EncounterArea4(196, 0, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}), // Ruins of Alph (Inside)
        EncounterArea4(197, 0, 0, Encounter::Grass, {74, 27, 74, 27, 41, 41, 19, 19, 41, 95, 41, 95}, {6, 6, 6, 6, 5, 5, 4, 4, 7, 6, 7, 6}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::Grass, {74, 27, 359, 359, 296, 296, 19, 19, 41, 95, 41, 95}, {6, 6, 6, 6, 5, 5, 4, 4, 7, 6, 7, 6}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::Grass, {74, 27, 436, 436, 433, 433, 19, 19, 41, 95, 41, 95}, {6, 6, 6, 6, 5, 5, 4, 4, 7, 6, 7, 6}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::Surfing, {194, 195, 195, 195, 195}, {10, 15, 10, 10, 10}, {20, 25, 20, 20, 20}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Union Cave 1F
        EncounterArea4(198, 0, 0, Encounter::Grass, {74, 27, 74, 27, 41, 41, 95, 95, 41, 19, 41, 19}, {8, 8, 8, 8, 7, 7, 8, 8, 9, 6, 9, 6}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::Grass, {74, 27, 359, 359, 296, 296, 95, 95, 41, 19, 41, 19}, {8, 8, 8, 8, 7, 7, 8, 8, 9, 6, 9, 6}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::Grass, {74, 27, 436, 436, 433, 433, 95, 95, 41, 19, 41, 19}, {8, 8, 8, 8, 7, 7, 8, 8, 9, 6, 9, 6}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::Surfing, {194, 195, 195, 195, 195}, {10, 15, 10, 10, 10}, {20, 25, 20, 20, 20}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Union Cave B1F
        EncounterArea4(199, 0, 0, Encounter::Grass, {41, 20, 41, 20, 42, 42, 74, 74, 19, 95, 19, 95}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::Grass, {41, 20, 359, 359, 296, 296, 74, 74, 19, 95, 19, 95}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::Grass, {41, 20, 436, 436, 433, 433, 74, 74, 19, 95, 19, 95}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::Surfing, {72, 195, 73, 73, 73}, {10, 15, 15, 15, 15}, {20, 25, 25, 25, 25}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Union Cave B2F
        EncounterArea4(200, 0, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 79, 79, 41, 79, 41, 79}, {5, 6, 5, 6, 7, 7, 6, 6, 8, 8, 8, 8}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::Grass, {41, 41, 359, 359, 296, 296, 79, 79, 41, 79, 41, 79}, {5, 6, 5, 6, 7, 7, 6, 6, 8, 8, 8, 8}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::Grass, {41, 41, 436, 436, 433, 433, 79, 79, 41, 79, 41, 79}, {5, 6, 5, 6, 7, 7, 6, 6, 8, 8, 8, 8}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {10, 15, 5, 5, 5}, {20, 25, 15, 15, 15}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Slowpoke Well 1F
        EncounterArea4(201, 0, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 79, 79, 42, 79, 42, 79}, {21, 23, 21, 23, 19, 19, 21, 21, 23, 23, 23, 23}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::Grass, {41, 41, 359, 359, 296, 296, 79, 79, 42, 79, 42, 79}, {21, 23, 21, 23, 19, 19, 21, 21, 23, 23, 23, 23}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::Grass, {41, 41, 436, 436, 433, 433, 79, 79, 42, 79, 42, 79}, {21, 23, 21, 23, 19, 19, 21, 21, 23, 23, 23, 23}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::Surfing, {79, 79, 80, 80, 80}, {10, 15, 15, 15, 30}, {20, 25, 25, 25, 30}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Slowpoke Well B1F
        EncounterArea4(202, 1, 1, Encounter::Grass, {10, 11, 10, 11, 10, 10, 46, 46, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 2, 2, Encounter::Grass, {10, 10, 10, 10, 11, 11, 11, 11, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 3, 3, Encounter::Grass, {43, 43, 43, 43, 41, 41, 46, 46, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::Grass, {10, 11, 325, 325, 322, 322, 46, 46, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::Grass, {10, 11, 406, 406, 455, 455, 46, 46, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {10, 5, 10, 10, 10}, {20, 15, 20, 20, 20}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Ilex Forest
        EncounterArea4(203, 0, 0, Encounter::Grass, {41, 41, 41, 41, 66, 66, 19, 19, 74, 19, 74, 183}, {13, 15, 13, 15, 14, 14, 14, 14, 14, 16, 14, 15}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::Grass, {41, 41, 359, 359, 296, 296, 19, 19, 74, 19, 74, 183}, {13, 15, 13, 15, 14, 14, 14, 14, 14, 16, 14, 15}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::Grass, {41, 41, 436, 436, 433, 433, 19, 19, 74, 19, 74, 183}, {13, 15, 13, 15, 14, 14, 14, 14, 14, 16, 14, 15}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Mortar 1F
        EncounterArea4(204, 0, 0, Encounter::Grass, {74, 66, 74, 66, 74, 74, 19, 19, 66, 41, 66, 41}, {13, 13, 13, 13, 15, 15, 14, 14, 15, 14, 15, 14}), // Mt. Mortar 1F (Back)
        EncounterArea4(204, 0, 0, Encounter::Grass, {74, 66, 359, 359, 296, 296, 19, 19, 66, 41, 66, 41}, {13, 13, 13, 13, 15, 15, 14, 14, 15, 14, 15, 14}), // Mt. Mortar 1F (Back)
        EncounterArea4(204, 0, 0, Encounter::Grass, {74, 66, 436, 436, 433, 433, 19, 19, 66, 41, 66, 41}, {13, 13, 13, 13, 15, 15, 14, 14, 15, 14, 15, 14}), // Mt. Mortar 1F (Back)
        EncounterArea4(205, 0, 0, Encounter::Grass, {75, 67, 75, 67, 74, 74, 20, 20, 66, 42, 66, 42}, {31, 32, 31, 32, 31, 31, 30, 30, 28, 30, 28, 30}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::Grass, {75, 67, 359, 359, 296, 296, 20, 20, 66, 42, 66, 42}, {31, 32, 31, 32, 31, 31, 30, 30, 28, 30, 28, 30}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::Grass, {75, 67, 436, 436, 433, 433, 20, 20, 66, 42, 66, 42}, {31, 32, 31, 32, 31, 31, 30, 30, 28, 30, 28, 30}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 20, 20, 20, 20}, {25, 30, 30, 30, 30}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Mortar 2F
        EncounterArea4(206, 0, 0, Encounter::Grass, {41, 41, 41, 41, 19, 19, 66, 66, 74, 20, 74, 20}, {15, 17, 15, 17, 16, 16, 16, 16, 16, 16, 16, 16}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::Grass, {41, 41, 359, 359, 296, 296, 66, 66, 74, 20, 74, 20}, {15, 17, 15, 17, 16, 16, 16, 16, 16, 16, 16, 16}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::Grass, {41, 41, 436, 436, 433, 433, 66, 66, 74, 20, 74, 20}, {15, 17, 15, 17, 16, 16, 16, 16, 16, 16, 16, 16}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Mortar B1F
        EncounterArea4(207, 1, 1, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(207, 2, 2, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 124, 124, 124, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(207, 3, 3, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(207, 0, 0, Encounter::Grass, {220, 42, 359, 359, 296, 296, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(207, 0, 0, Encounter::Grass, {220, 42, 436, 436, 433, 433, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(208, 1, 1, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(208, 2, 2, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 124, 124, 124, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(208, 3, 3, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(208, 0, 0, Encounter::Grass, {220, 42, 359, 359, 296, 296, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(208, 0, 0, Encounter::Grass, {220, 42, 436, 436, 433, 433, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(209, 1, 1, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(209, 2, 2, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 124, 124, 124, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(209, 3, 3, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(209, 0, 0, Encounter::Grass, {220, 42, 359, 359, 296, 296, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(209, 0, 0, Encounter::Grass, {220, 42, 436, 436, 433, 433, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(210, 1, 1, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(210, 2, 2, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 124, 124, 124, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(210, 3, 3, Encounter::Grass, {220, 42, 220, 42, 41, 41, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(210, 0, 0, Encounter::Grass, {220, 42, 359, 359, 296, 296, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(210, 0, 0, Encounter::Grass, {220, 42, 436, 436, 433, 433, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(211, 0, 0, Encounter::Grass, {98, 41, 98, 41, 98, 98, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::Grass, {98, 41, 359, 359, 296, 296, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::Grass, {98, 41, 436, 436, 433, 433, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::Surfing, {72, 116, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::GoodRod, {129, 98, 98, 116, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::SuperRod, {98, 116, 99, 117, 99}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Whirl Islands 1F
        EncounterArea4(212, 0, 0, Encounter::Grass, {98, 41, 98, 41, 98, 98, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B1F
        EncounterArea4(212, 0, 0, Encounter::Grass, {98, 41, 359, 359, 296, 296, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B1F
        EncounterArea4(212, 0, 0, Encounter::Grass, {98, 41, 436, 436, 433, 433, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B1F
        EncounterArea4(213, 0, 0, Encounter::Grass, {98, 41, 98, 41, 98, 98, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::Grass, {98, 41, 359, 359, 296, 296, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::Grass, {98, 41, 436, 436, 433, 433, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::Surfing, {116, 73, 117, 117, 117}, {15, 15, 15, 15, 30}, {25, 25, 25, 25, 30}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::GoodRod, {129, 98, 98, 116, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::SuperRod, {98, 116, 99, 117, 99}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Whirl Islands B2F
        EncounterArea4(214, 0, 0, Encounter::Grass, {98, 41, 98, 41, 98, 98, 86, 86, 42, 86, 42, 86}, {23, 24, 23, 24, 25, 25, 23, 23, 24, 25, 24, 25}), // Whirl Islands B3F
        EncounterArea4(214, 0, 0, Encounter::Grass, {98, 41, 359, 359, 296, 296, 86, 86, 42, 86, 42, 86}, {23, 24, 23, 24, 25, 25, 23, 23, 24, 25, 24, 25}), // Whirl Islands B3F
        EncounterArea4(214, 0, 0, Encounter::Grass, {98, 41, 436, 436, 433, 433, 86, 86, 42, 86, 42, 86}, {23, 24, 23, 24, 25, 25, 23, 23, 24, 25, 24, 25}), // Whirl Islands B3F
        EncounterArea4(215, 1, 1, Encounter::Grass, {114, 77, 114, 74, 232, 232, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 2, 2, Encounter::Grass, {114, 77, 114, 74, 232, 232, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 3, 3, Encounter::Grass, {114, 77, 114, 74, 232, 232, 78, 78, 215, 215, 215, 215}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::Grass, {114, 77, 293, 293, 232, 232, 264, 264, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::Grass, {114, 77, 114, 418, 418, 399, 399, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::Surfing, {61, 61, 60, 60, 61}, {30, 35, 30, 30, 48}, {40, 45, 40, 40, 48}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver
        EncounterArea4(216, 1, 1, Encounter::Grass, {195, 208, 195, 55, 232, 232, 195, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 2, 2, Encounter::Grass, {195, 208, 195, 55, 232, 232, 195, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 3, 3, Encounter::Grass, {195, 208, 195, 55, 232, 232, 200, 200, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::Grass, {195, 208, 359, 359, 296, 296, 195, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::Grass, {195, 208, 436, 436, 433, 433, 195, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 118}, {30, 35, 30, 30, 30}, {40, 45, 40, 40, 40}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver 1F
        EncounterArea4(217, 1, 1, Encounter::Grass, {195, 215, 231, 55, 232, 232, 195, 195, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 2, 2, Encounter::Grass, {195, 215, 231, 55, 232, 232, 195, 195, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 3, 3, Encounter::Grass, {195, 215, 231, 55, 232, 232, 200, 200, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::Grass, {195, 215, 359, 359, 296, 296, 195, 195, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::Grass, {195, 215, 436, 436, 433, 433, 195, 195, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 118}, {30, 35, 30, 30, 30}, {40, 45, 40, 40, 40}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver 1F Top
        EncounterArea4(218, 0, 0, Encounter::Grass, {95, 232, 95, 232, 231, 75, 75, 75, 42, 246, 42, 246}, {42, 44, 42, 44, 43, 43, 42, 41, 45, 20, 45, 15}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::Grass, {95, 232, 359, 359, 296, 296, 75, 75, 42, 246, 42, 246}, {42, 44, 42, 44, 43, 43, 42, 41, 45, 20, 45, 15}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::Grass, {95, 232, 436, 436, 433, 433, 75, 75, 42, 246, 42, 246}, {42, 44, 42, 44, 43, 43, 42, 41, 45, 20, 45, 15}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 119}, {30, 35, 30, 30, 50}, {40, 45, 40, 40, 50}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::GoodRod, {129, 118, 119, 129, 119}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::SuperRod, {130, 119, 119, 130, 119}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver 2F
        EncounterArea4(219, 1, 1, Encounter::Grass, {195, 55, 195, 231, 232, 232, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(219, 2, 2, Encounter::Grass, {195, 55, 195, 231, 232, 232, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(219, 3, 3, Encounter::Grass, {200, 55, 200, 231, 232, 232, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(219, 0, 0, Encounter::Grass, {195, 55, 359, 359, 296, 296, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(219, 0, 0, Encounter::Grass, {195, 55, 436, 436, 433, 433, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(220, 1, 1, Encounter::Grass, {215, 55, 195, 55, 232, 232, 195, 195, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 2, 2, Encounter::Grass, {215, 55, 195, 55, 232, 232, 195, 195, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 3, 3, Encounter::Grass, {215, 55, 195, 55, 232, 232, 200, 200, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::Grass, {215, 55, 359, 359, 296, 296, 195, 195, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::Grass, {215, 55, 436, 436, 433, 433, 195, 195, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 118}, {30, 35, 30, 30, 30}, {40, 45, 40, 40, 40}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver 4F
        EncounterArea4(221, 0, 0, Encounter::Grass, {42, 95, 42, 95, 231, 42, 232, 232, 55, 246, 55, 246}, {51, 48, 51, 48, 48, 48, 50, 50, 51, 20, 51, 15}), // Mt. Silver Mountainside
        EncounterArea4(221, 0, 0, Encounter::Grass, {42, 95, 359, 359, 296, 296, 232, 232, 55, 246, 55, 246}, {51, 48, 51, 48, 48, 48, 50, 50, 51, 20, 51, 15}), // Mt. Silver Mountainside
        EncounterArea4(221, 0, 0, Encounter::Grass, {42, 95, 436, 436, 433, 433, 232, 232, 55, 246, 55, 246}, {51, 48, 51, 48, 48, 48, 50, 50, 51, 20, 51, 15}), // Mt. Silver Mountainside
        EncounterArea4(222, 1, 1, Encounter::Grass, {215, 55, 195, 55, 232, 232, 246, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 2, 2, Encounter::Grass, {215, 55, 195, 55, 232, 232, 246, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 3, 3, Encounter::Grass, {215, 55, 195, 200, 232, 232, 246, 200, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::Grass, {215, 55, 359, 359, 296, 296, 246, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::Grass, {215, 55, 436, 436, 433, 433, 246, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 118}, {30, 35, 30, 30, 30}, {40, 45, 40, 40, 40}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver Top
        EncounterArea4(223, 0, 0, Encounter::Grass, {74, 41, 74, 41, 74, 74, 74, 74, 41, 41, 41, 206}, {3, 2, 3, 2, 2, 2, 4, 4, 3, 4, 3, 4}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::Grass, {74, 41, 359, 359, 296, 296, 74, 74, 41, 41, 41, 206}, {3, 2, 3, 2, 2, 2, 4, 4, 3, 4, 3, 4}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::Grass, {74, 41, 436, 436, 433, 433, 74, 74, 41, 41, 41, 206}, {3, 2, 3, 2, 2, 2, 4, 4, 3, 4, 3, 4}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::RockSmash, {206, 74}, {4, 8}, {8, 14}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {10, 5, 2, 2, 2}, {20, 15, 10, 10, 10}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Dark Cave (Route 31)
        EncounterArea4(224, 0, 0, Encounter::Grass, {74, 41, 74, 41, 75, 75, 202, 202, 202, 42, 202, 42}, {23, 23, 23, 23, 25, 25, 20, 20, 25, 23, 25, 23}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::Grass, {74, 41, 359, 359, 296, 296, 202, 202, 202, 42, 202, 42}, {23, 23, 23, 23, 25, 25, 20, 20, 25, 23, 25, 23}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::Grass, {74, 41, 436, 436, 433, 433, 202, 202, 202, 42, 202, 42}, {23, 23, 23, 23, 25, 25, 20, 20, 25, 23, 25, 23}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {10, 5, 2, 2, 2}, {20, 15, 10, 10, 10}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Dark Cave (Route 45)
        EncounterArea4(225, 0, 0, Encounter::Grass, {75, 42, 75, 42, 232, 232, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 1F
        EncounterArea4(225, 0, 0, Encounter::Grass, {75, 42, 359, 359, 296, 296, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 1F
        EncounterArea4(225, 0, 0, Encounter::Grass, {75, 42, 436, 436, 433, 433, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 1F
        EncounterArea4(226, 0, 0, Encounter::Grass, {75, 42, 75, 42, 232, 232, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 2F
        EncounterArea4(226, 0, 0, Encounter::Grass, {75, 42, 359, 359, 296, 296, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 2F
        EncounterArea4(226, 0, 0, Encounter::Grass, {75, 42, 436, 436, 433, 433, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 2F
        EncounterArea4(227, 0, 0, Encounter::Grass, {75, 42, 75, 42, 232, 232, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 3F
        EncounterArea4(227, 0, 0, Encounter::Grass, {75, 42, 359, 359, 296, 296, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 3F
        EncounterArea4(227, 0, 0, Encounter::Grass, {75, 42, 436, 436, 433, 433, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 3F
        EncounterArea4(227, 0, 0, Encounter::RockSmash, {74, 75}, {24, 30}, {32, 33}), // Victory Road 3F
        EncounterArea4(228, 0, 0, Encounter::Surfing, {129, 129, 147, 147, 147}, {10, 5, 5, 5, 5}, {20, 15, 15, 15, 15}), // Dragonï¿½s Den
        EncounterArea4(228, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Dragonï¿½s Den
        EncounterArea4(228, 0, 0, Encounter::GoodRod, {129, 129, 129, 147, 129}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Dragonï¿½s Den
        EncounterArea4(228, 0, 0, Encounter::SuperRod, {129, 147, 129, 148, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Dragonï¿½s Den
        EncounterArea4(229, 0, 0, Encounter::Grass, {41, 20, 41, 20, 42, 42, 79, 79, 19, 79, 19, 79}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::Grass, {41, 20, 359, 359, 296, 296, 79, 79, 19, 79, 19, 79}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::Grass, {41, 20, 436, 436, 433, 433, 79, 79, 19, 79, 19, 79}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::Surfing, {118, 79, 119, 119, 119}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Tohjo Falls
        EncounterArea4(230, 1, 1, Encounter::Grass, {10, 10, 11, 16, 11, 11, 12, 12, 17, 25, 25, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(230, 2, 2, Encounter::Grass, {10, 10, 11, 16, 11, 11, 16, 17, 17, 25, 25, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(230, 3, 3, Encounter::Grass, {163, 163, 163, 163, 163, 163, 164, 164, 164, 25, 164, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(230, 0, 0, Encounter::Grass, {10, 10, 325, 325, 322, 322, 12, 12, 17, 25, 25, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(230, 0, 0, Encounter::Grass, {10, 10, 406, 406, 455, 455, 12, 12, 17, 25, 25, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(231, 1, 1, Encounter::Grass, {42, 74, 98, 99, 66, 95, 194, 195, 75, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 2, 2, Encounter::Grass, {42, 74, 98, 99, 66, 95, 194, 195, 75, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 3, 3, Encounter::Grass, {42, 74, 98, 99, 66, 95, 41, 200, 42, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 0, 0, Encounter::Grass, {42, 74, 359, 359, 296, 296, 194, 195, 75, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 0, 0, Encounter::Grass, {42, 74, 436, 436, 433, 433, 194, 195, 75, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 0, 0, Encounter::RockSmash, {98, 99}, {20, 28}, {26, 31}), // Cliff Cave
        EncounterArea4(232, 0, 0, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 30, 30, 30}, {30, 30, 40, 40, 40}), // Cliff Edge Gate
        EncounterArea4(232, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cliff Edge Gate
        EncounterArea4(232, 0, 0, Encounter::GoodRod, {129, 129, 129, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cliff Edge Gate
        EncounterArea4(232, 0, 0, Encounter::SuperRod, {129, 129, 60, 60, 60}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cliff Edge Gate
    };

    const QVector<EncounterArea4> encountersSoulSilver
    {
        EncounterArea4(113, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // New Bark Town
        EncounterArea4(113, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // New Bark Town
        EncounterArea4(113, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // New Bark Town
        EncounterArea4(113, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // New Bark Town
        EncounterArea4(114, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Cherrygrove City
        EncounterArea4(114, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cherrygrove City
        EncounterArea4(114, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cherrygrove City
        EncounterArea4(114, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cherrygrove City
        EncounterArea4(115, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Violet City
        EncounterArea4(115, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Violet City
        EncounterArea4(115, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Violet City
        EncounterArea4(115, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Violet City
        EncounterArea4(116, 0, 0, Encounter::RockSmash, {98, 213}, {15, 23}, {24, 28}), // Cianwood City
        EncounterArea4(116, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Cianwood City
        EncounterArea4(116, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cianwood City
        EncounterArea4(116, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cianwood City
        EncounterArea4(116, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cianwood City
        EncounterArea4(117, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Olivine City
        EncounterArea4(117, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Olivine City
        EncounterArea4(117, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Olivine City
        EncounterArea4(117, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Olivine City
        EncounterArea4(118, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Ecruteak City
        EncounterArea4(118, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Ecruteak City
        EncounterArea4(118, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Ecruteak City
        EncounterArea4(118, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Ecruteak City
        EncounterArea4(119, 0, 0, Encounter::Surfing, {129, 129, 130, 130, 130}, {10, 5, 10, 10, 10}, {20, 15, 20, 20, 20}), // Lake of Rage
        EncounterArea4(119, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Lake of Rage
        EncounterArea4(119, 0, 0, Encounter::GoodRod, {129, 129, 129, 130, 129}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Lake of Rage
        EncounterArea4(119, 0, 0, Encounter::SuperRod, {129, 130, 129, 129, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Lake of Rage
        EncounterArea4(120, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {10, 5, 2, 2, 2}, {20, 15, 10, 10, 10}), // Blackthorn City
        EncounterArea4(120, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Blackthorn City
        EncounterArea4(120, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Blackthorn City
        EncounterArea4(120, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Blackthorn City
        EncounterArea4(121, 1, 1, Encounter::Grass, {114, 77, 114, 77, 217, 217, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 2, 2, Encounter::Grass, {114, 77, 114, 77, 217, 217, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 3, 3, Encounter::Grass, {114, 77, 114, 77, 217, 217, 78, 78, 215, 215, 215, 215}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::Grass, {114, 77, 293, 293, 264, 264, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::Grass, {114, 77, 418, 418, 399, 399, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::Surfing, {61, 61, 60, 60, 61}, {30, 35, 30, 30, 48}, {40, 45, 40, 40, 48}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver
        EncounterArea4(121, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver
        EncounterArea4(122, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Pallet Town
        EncounterArea4(122, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Pallet Town
        EncounterArea4(122, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Pallet Town
        EncounterArea4(122, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Pallet Town
        EncounterArea4(123, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Viridian City
        EncounterArea4(123, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Viridian City
        EncounterArea4(123, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Viridian City
        EncounterArea4(123, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Viridian City
        EncounterArea4(124, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Cerulean City
        EncounterArea4(124, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cerulean City
        EncounterArea4(124, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cerulean City
        EncounterArea4(124, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cerulean City
        EncounterArea4(125, 0, 0, Encounter::RockSmash, {50, 213}, {24, 32}, {37, 35}), // Vermilion City
        EncounterArea4(125, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Vermilion City
        EncounterArea4(125, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Vermilion City
        EncounterArea4(125, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Vermilion City
        EncounterArea4(125, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Vermilion City
        EncounterArea4(126, 0, 0, Encounter::Surfing, {88, 88, 89, 89, 89}, {20, 15, 15, 15, 15}, {20, 15, 15, 15, 15}), // Celadon City
        EncounterArea4(127, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {20, 15, 10, 10, 10}, {20, 15, 10, 10, 10}), // Fuchsia City
        EncounterArea4(127, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Fuchsia City
        EncounterArea4(127, 0, 0, Encounter::GoodRod, {129, 129, 129, 130, 129}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Fuchsia City
        EncounterArea4(127, 0, 0, Encounter::SuperRod, {129, 130, 129, 129, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Fuchsia City
        EncounterArea4(128, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Cinnabar Island
        EncounterArea4(128, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cinnabar Island
        EncounterArea4(128, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cinnabar Island
        EncounterArea4(128, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cinnabar Island
        EncounterArea4(129, 1, 1, Encounter::Grass, {16, 19, 16, 19, 161, 161, 16, 16, 162, 16, 162, 16}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(129, 2, 2, Encounter::Grass, {16, 19, 16, 19, 161, 161, 16, 16, 162, 16, 162, 16}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(129, 3, 3, Encounter::Grass, {163, 19, 163, 19, 19, 19, 163, 163, 19, 163, 19, 163}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(129, 0, 0, Encounter::Grass, {16, 19, 311, 311, 312, 312, 16, 16, 162, 16, 162, 16}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(129, 0, 0, Encounter::Grass, {16, 19, 403, 403, 403, 403, 16, 16, 162, 16, 162, 16}, {2, 2, 2, 2, 3, 3, 3, 3, 6, 4, 6, 4}), // Route 1
        EncounterArea4(130, 1, 1, Encounter::Grass, {165, 16, 13, 165, 14, 14, 15, 15, 166, 166, 166, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(130, 2, 2, Encounter::Grass, {13, 16, 13, 16, 14, 14, 16, 16, 17, 165, 17, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(130, 3, 3, Encounter::Grass, {163, 163, 14, 163, 163, 13, 164, 164, 164, 15, 14, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(130, 0, 0, Encounter::Grass, {165, 16, 311, 311, 312, 312, 15, 15, 166, 166, 166, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(130, 0, 0, Encounter::Grass, {165, 16, 403, 403, 403, 403, 15, 15, 166, 166, 166, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (North)
        EncounterArea4(131, 1, 1, Encounter::Grass, {165, 16, 13, 165, 14, 14, 15, 15, 166, 166, 166, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(131, 2, 2, Encounter::Grass, {13, 16, 13, 16, 14, 14, 16, 16, 17, 165, 17, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(131, 3, 3, Encounter::Grass, {163, 163, 14, 163, 163, 13, 164, 164, 164, 15, 14, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(131, 0, 0, Encounter::Grass, {165, 16, 311, 311, 312, 312, 15, 15, 166, 166, 166, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(131, 0, 0, Encounter::Grass, {165, 16, 403, 403, 403, 403, 15, 15, 166, 166, 166, 13}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 10, 7, 4}), // Route 2 (South)
        EncounterArea4(132, 1, 1, Encounter::Grass, {21, 19, 21, 19, 23, 23, 39, 39, 24, 21, 24, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(132, 2, 2, Encounter::Grass, {21, 19, 21, 19, 23, 23, 39, 39, 24, 21, 24, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(132, 3, 3, Encounter::Grass, {19, 41, 19, 41, 23, 23, 39, 39, 24, 19, 24, 19}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(132, 0, 0, Encounter::Grass, {21, 19, 311, 311, 312, 312, 39, 39, 24, 21, 24, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(132, 0, 0, Encounter::Grass, {21, 19, 403, 403, 403, 403, 39, 39, 24, 21, 24, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 3
        EncounterArea4(133, 1, 1, Encounter::Grass, {21, 19, 21, 19, 23, 23, 39, 39, 24, 21, 24, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 2, 2, Encounter::Grass, {21, 19, 21, 19, 23, 23, 39, 39, 24, 21, 24, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 3, 3, Encounter::Grass, {19, 41, 19, 41, 23, 23, 39, 39, 24, 19, 24, 19}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::Grass, {21, 19, 293, 293, 264, 264, 39, 39, 24, 21, 24, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::Grass, {21, 19, 418, 418, 399, 399, 39, 39, 24, 21, 24, 21}, {5, 5, 5, 5, 8, 8, 6, 6, 10, 8, 10, 8}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 4
        EncounterArea4(133, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 4
        EncounterArea4(134, 1, 1, Encounter::Grass, {16, 69, 16, 69, 52, 52, 16, 16, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(134, 2, 2, Encounter::Grass, {16, 69, 16, 69, 52, 52, 16, 16, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(134, 3, 3, Encounter::Grass, {43, 52, 43, 52, 69, 69, 44, 44, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(134, 0, 0, Encounter::Grass, {16, 69, 311, 311, 312, 312, 16, 16, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(134, 0, 0, Encounter::Grass, {16, 69, 403, 403, 403, 403, 16, 16, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 5
        EncounterArea4(135, 1, 1, Encounter::Grass, {16, 69, 16, 69, 52, 52, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 2, 2, Encounter::Grass, {16, 69, 16, 69, 52, 52, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 3, 3, Encounter::Grass, {43, 52, 43, 52, 69, 69, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::Grass, {16, 69, 293, 293, 264, 264, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::Grass, {16, 69, 418, 418, 399, 399, 81, 81, 63, 63, 63, 63}, {13, 13, 13, 13, 14, 14, 15, 15, 12, 14, 12, 14}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 6
        EncounterArea4(135, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 6
        EncounterArea4(136, 1, 1, Encounter::Grass, {52, 21, 52, 21, 37, 37, 20, 20, 53, 19, 53, 19}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(136, 2, 2, Encounter::Grass, {52, 21, 52, 21, 37, 37, 20, 20, 53, 37, 53, 37}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(136, 3, 3, Encounter::Grass, {52, 198, 52, 198, 37, 37, 20, 20, 53, 228, 53, 228}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(136, 0, 0, Encounter::Grass, {52, 21, 311, 311, 312, 312, 20, 20, 53, 19, 53, 19}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(136, 0, 0, Encounter::Grass, {52, 21, 403, 403, 403, 403, 20, 20, 53, 19, 53, 19}, {17, 17, 17, 17, 18, 18, 19, 19, 19, 15, 19, 15}), // Route 7
        EncounterArea4(137, 1, 1, Encounter::Grass, {52, 17, 52, 17, 63, 63, 37, 37, 17, 64, 17, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(137, 2, 2, Encounter::Grass, {52, 17, 52, 17, 63, 63, 37, 37, 17, 64, 17, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(137, 3, 3, Encounter::Grass, {52, 93, 52, 93, 63, 63, 164, 164, 37, 64, 37, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(137, 0, 0, Encounter::Grass, {52, 17, 311, 311, 312, 312, 37, 37, 17, 64, 17, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(137, 0, 0, Encounter::Grass, {52, 17, 403, 403, 403, 403, 37, 37, 17, 64, 17, 64}, {17, 19, 17, 19, 15, 15, 18, 18, 17, 15, 17, 15}), // Route 8
        EncounterArea4(138, 1, 1, Encounter::Grass, {19, 21, 19, 21, 21, 21, 20, 20, 22, 20, 22, 20}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 2, 2, Encounter::Grass, {19, 21, 19, 21, 21, 21, 20, 20, 22, 20, 22, 20}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 3, 3, Encounter::Grass, {19, 19, 19, 19, 20, 20, 19, 19, 20, 20, 20, 20}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::Grass, {19, 21, 293, 293, 264, 264, 20, 20, 22, 20, 22, 20}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::Grass, {19, 21, 418, 418, 399, 399, 20, 20, 22, 20, 22, 20}, {13, 15, 13, 15, 13, 13, 15, 15, 15, 15, 15, 15}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {15, 10, 15, 15, 15}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 9
        EncounterArea4(138, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 9
        EncounterArea4(139, 1, 1, Encounter::Grass, {21, 100, 21, 100, 20, 20, 22, 22, 20, 125, 20, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 2, 2, Encounter::Grass, {21, 100, 21, 100, 20, 20, 22, 22, 125, 125, 125, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 3, 3, Encounter::Grass, {195, 100, 195, 100, 20, 20, 195, 195, 20, 125, 20, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::Grass, {21, 100, 293, 293, 264, 264, 22, 22, 20, 125, 20, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::Grass, {21, 100, 418, 418, 399, 399, 22, 22, 20, 125, 20, 125}, {16, 17, 16, 17, 16, 16, 18, 18, 18, 15, 18, 15}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {15, 10, 15, 15, 15}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 10
        EncounterArea4(139, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 10
        EncounterArea4(140, 0, 0, Encounter::Grass, {96, 19, 96, 19, 81, 81, 96, 96, 97, 97, 97, 97}, {14, 15, 14, 15, 15, 15, 16, 16, 16, 16, 16, 16}), // Route 11
        EncounterArea4(140, 0, 0, Encounter::Grass, {96, 19, 311, 311, 312, 312, 96, 96, 97, 97, 97, 97}, {14, 15, 14, 15, 15, 15, 16, 16, 16, 16, 16, 16}), // Route 11
        EncounterArea4(140, 0, 0, Encounter::Grass, {96, 19, 403, 403, 403, 403, 96, 96, 97, 97, 97, 97}, {14, 15, 14, 15, 15, 15, 16, 16, 16, 16, 16, 16}), // Route 11
        EncounterArea4(141, 0, 0, Encounter::Surfing, {72, 195, 73, 73, 73}, {25, 25, 25, 25, 25}, {25, 25, 25, 25, 25}), // Route 12
        EncounterArea4(141, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 12
        EncounterArea4(141, 0, 0, Encounter::GoodRod, {129, 72, 72, 72, 72}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 12
        EncounterArea4(141, 0, 0, Encounter::SuperRod, {72, 72, 129, 211, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 12
        EncounterArea4(142, 1, 1, Encounter::Grass, {33, 30, 33, 30, 17, 17, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 2, 2, Encounter::Grass, {33, 30, 33, 30, 17, 17, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 3, 3, Encounter::Grass, {33, 30, 33, 30, 164, 164, 195, 195, 195, 195, 195, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::Grass, {33, 30, 293, 293, 264, 264, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::Grass, {33, 30, 418, 418, 399, 399, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::Surfing, {72, 195, 73, 73, 73}, {25, 25, 25, 25, 25}, {25, 25, 25, 25, 25}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::GoodRod, {129, 72, 72, 72, 72}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 13
        EncounterArea4(142, 0, 0, Encounter::SuperRod, {72, 72, 129, 211, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 13
        EncounterArea4(143, 1, 1, Encounter::Grass, {33, 30, 33, 30, 17, 17, 187, 187, 188, 188, 188, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(143, 2, 2, Encounter::Grass, {33, 30, 33, 30, 17, 17, 187, 187, 188, 188, 188, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(143, 3, 3, Encounter::Grass, {33, 30, 33, 30, 164, 164, 195, 195, 195, 195, 195, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(143, 0, 0, Encounter::Grass, {33, 30, 311, 311, 312, 312, 187, 187, 188, 188, 188, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(143, 0, 0, Encounter::Grass, {33, 30, 403, 403, 403, 403, 187, 187, 188, 188, 188, 113}, {23, 23, 23, 23, 25, 25, 24, 24, 26, 26, 26, 25}), // Route 14
        EncounterArea4(144, 1, 1, Encounter::Grass, {33, 30, 33, 30, 17, 17, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(144, 2, 2, Encounter::Grass, {33, 30, 33, 30, 17, 17, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(144, 3, 3, Encounter::Grass, {33, 30, 33, 30, 164, 164, 195, 195, 195, 195, 195, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(144, 0, 0, Encounter::Grass, {33, 30, 311, 311, 312, 312, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(144, 0, 0, Encounter::Grass, {33, 30, 403, 403, 403, 403, 187, 187, 187, 187, 187, 113}, {23, 23, 23, 23, 25, 25, 22, 22, 24, 24, 24, 25}), // Route 15
        EncounterArea4(145, 1, 1, Encounter::Grass, {88, 22, 88, 22, 88, 88, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(145, 2, 2, Encounter::Grass, {88, 22, 88, 22, 88, 88, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(145, 3, 3, Encounter::Grass, {88, 88, 88, 88, 88, 88, 198, 198, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(145, 0, 0, Encounter::Grass, {88, 22, 311, 311, 312, 312, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(145, 0, 0, Encounter::Grass, {88, 22, 403, 403, 403, 403, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 16
        EncounterArea4(146, 1, 1, Encounter::Grass, {22, 88, 22, 88, 88, 88, 22, 22, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(146, 2, 2, Encounter::Grass, {22, 218, 22, 218, 88, 88, 22, 22, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(146, 3, 3, Encounter::Grass, {88, 88, 88, 88, 88, 88, 89, 89, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(146, 0, 0, Encounter::Grass, {22, 88, 311, 311, 312, 312, 22, 22, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(146, 0, 0, Encounter::Grass, {22, 88, 403, 403, 403, 403, 22, 22, 218, 89, 218, 89}, {28, 27, 28, 27, 29, 29, 30, 30, 29, 32, 29, 32}), // Route 17
        EncounterArea4(147, 1, 1, Encounter::Grass, {88, 22, 88, 22, 88, 88, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(147, 2, 2, Encounter::Grass, {88, 22, 88, 22, 88, 88, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(147, 3, 3, Encounter::Grass, {88, 88, 88, 88, 88, 88, 89, 89, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(147, 0, 0, Encounter::Grass, {88, 22, 311, 311, 312, 312, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(147, 0, 0, Encounter::Grass, {88, 22, 403, 403, 403, 403, 22, 22, 218, 89, 218, 89}, {26, 27, 26, 27, 28, 28, 29, 29, 27, 30, 27, 30}), // Route 18
        EncounterArea4(148, 0, 0, Encounter::RockSmash, {99, 98}, {28, 24}, {31, 27}), // Route 19
        EncounterArea4(148, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Route 19
        EncounterArea4(148, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 19
        EncounterArea4(148, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 19
        EncounterArea4(148, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 19
        EncounterArea4(149, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Route 20
        EncounterArea4(149, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 20
        EncounterArea4(149, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 20
        EncounterArea4(149, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 20
        EncounterArea4(150, 1, 1, Encounter::Grass, {114, 114, 114, 114, 114, 114, 114, 114, 114, 122, 114, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 2, 2, Encounter::Grass, {114, 114, 114, 114, 114, 114, 114, 114, 122, 122, 122, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 3, 3, Encounter::Grass, {114, 114, 114, 114, 114, 114, 114, 114, 114, 122, 114, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::Grass, {114, 114, 293, 293, 264, 264, 114, 114, 114, 122, 114, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::Grass, {114, 114, 418, 418, 399, 399, 114, 114, 114, 122, 114, 122}, {30, 25, 30, 25, 35, 35, 20, 20, 30, 28, 30, 28}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 21
        EncounterArea4(150, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 21
        EncounterArea4(151, 1, 1, Encounter::Grass, {19, 21, 19, 21, 21, 21, 84, 84, 77, 22, 77, 22}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 2, 2, Encounter::Grass, {19, 21, 19, 21, 21, 21, 84, 84, 77, 22, 77, 22}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 3, 3, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 77, 19, 77, 19}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::Grass, {19, 21, 293, 293, 264, 264, 84, 84, 77, 22, 77, 22}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::Grass, {19, 21, 418, 418, 399, 399, 84, 84, 77, 22, 77, 22}, {3, 3, 3, 3, 5, 5, 4, 4, 6, 7, 6, 7}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 22
        EncounterArea4(151, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 22
        EncounterArea4(152, 1, 1, Encounter::Grass, {69, 69, 69, 69, 63, 63, 70, 70, 48, 70, 48, 70}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 2, 2, Encounter::Grass, {69, 191, 69, 191, 63, 63, 70, 70, 69, 70, 69, 70}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 3, 3, Encounter::Grass, {48, 43, 48, 43, 63, 63, 70, 70, 69, 49, 69, 49}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::Grass, {69, 69, 293, 293, 264, 264, 70, 70, 48, 70, 48, 70}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::Grass, {69, 69, 418, 418, 399, 399, 70, 70, 48, 70, 48, 70}, {8, 10, 8, 10, 9, 9, 12, 12, 8, 14, 8, 14}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 24
        EncounterArea4(152, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 24
        EncounterArea4(153, 1, 1, Encounter::Grass, {16, 69, 16, 69, 48, 48, 63, 63, 17, 70, 17, 70}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 2, 2, Encounter::Grass, {16, 69, 16, 69, 16, 16, 63, 63, 17, 70, 17, 70}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 3, 3, Encounter::Grass, {48, 43, 48, 43, 49, 49, 63, 63, 70, 69, 70, 69}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::Grass, {16, 69, 293, 293, 264, 264, 63, 63, 17, 70, 17, 70}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::Grass, {16, 69, 418, 418, 399, 399, 63, 63, 17, 70, 17, 70}, {8, 10, 8, 10, 8, 8, 9, 9, 10, 14, 10, 14}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {10, 5, 10, 10, 10}, {10, 5, 10, 10, 10}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 25
        EncounterArea4(153, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 25
        EncounterArea4(154, 1, 1, Encounter::Grass, {84, 20, 84, 20, 77, 77, 84, 84, 20, 24, 20, 24}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 2, 2, Encounter::Grass, {84, 20, 84, 20, 77, 77, 84, 84, 20, 24, 20, 24}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 3, 3, Encounter::Grass, {20, 20, 20, 20, 77, 77, 84, 84, 195, 24, 195, 24}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::Grass, {84, 20, 293, 293, 264, 264, 84, 84, 20, 24, 20, 24}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::Grass, {84, 20, 418, 418, 399, 399, 84, 84, 20, 24, 20, 24}, {28, 28, 28, 28, 32, 32, 30, 30, 30, 30, 30, 30}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {30, 25, 30, 30, 30}, {30, 25, 30, 30, 30}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 26
        EncounterArea4(154, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 26
        EncounterArea4(155, 1, 1, Encounter::Grass, {84, 24, 84, 24, 20, 20, 84, 84, 77, 85, 77, 85}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 2, 2, Encounter::Grass, {84, 24, 84, 24, 20, 20, 84, 84, 77, 85, 77, 85}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 3, 3, Encounter::Grass, {195, 24, 195, 24, 195, 195, 20, 20, 77, 195, 77, 195}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::Grass, {84, 24, 293, 293, 264, 264, 84, 84, 77, 85, 77, 85}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::Grass, {84, 24, 418, 418, 399, 399, 84, 84, 77, 85, 77, 85}, {28, 28, 28, 28, 30, 30, 30, 30, 32, 30, 32, 30}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {20, 15, 20, 20, 20}, {20, 15, 20, 20, 20}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 27
        EncounterArea4(155, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 27
        EncounterArea4(156, 1, 1, Encounter::Grass, {114, 77, 114, 77, 217, 217, 78, 78, 84, 85, 84, 85}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 2, 2, Encounter::Grass, {114, 77, 114, 77, 217, 217, 78, 78, 84, 85, 84, 85}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 3, 3, Encounter::Grass, {114, 77, 114, 77, 217, 217, 215, 215, 78, 78, 78, 78}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::Grass, {114, 77, 293, 293, 264, 264, 78, 78, 84, 85, 84, 85}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::Grass, {114, 77, 418, 418, 399, 399, 78, 78, 84, 85, 84, 85}, {39, 40, 39, 40, 40, 40, 42, 42, 41, 43, 41, 43}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {40, 35, 40, 40, 40}, {40, 35, 40, 40, 40}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 28
        EncounterArea4(156, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 28
        EncounterArea4(157, 1, 1, Encounter::Grass, {16, 161, 16, 161, 16, 16, 161, 19, 161, 16, 161, 16}, {2, 3, 2, 3, 3, 3, 2, 4, 2, 4, 2, 4}), // Route 29
        EncounterArea4(157, 2, 2, Encounter::Grass, {16, 161, 16, 161, 16, 16, 161, 161, 19, 16, 19, 16}, {2, 3, 2, 3, 3, 3, 2, 4, 2, 4, 2, 4}), // Route 29
        EncounterArea4(157, 3, 3, Encounter::Grass, {163, 163, 163, 163, 163, 163, 19, 19, 19, 163, 19, 163}, {2, 3, 2, 3, 3, 3, 2, 4, 2, 4, 2, 4}), // Route 29
        EncounterArea4(157, 0, 0, Encounter::Grass, {16, 161, 311, 311, 312, 312, 161, 19, 161, 16, 161, 16}, {2, 3, 2, 3, 3, 3, 2, 4, 2, 4, 2, 4}), // Route 29
        EncounterArea4(157, 0, 0, Encounter::Grass, {16, 161, 403, 403, 403, 403, 161, 19, 161, 16, 161, 16}, {2, 3, 2, 3, 3, 3, 2, 4, 2, 4, 2, 4}), // Route 29
        EncounterArea4(158, 1, 1, Encounter::Grass, {165, 13, 165, 13, 13, 13, 14, 14, 16, 16, 16, 16}, {3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 2, 2, Encounter::Grass, {16, 13, 16, 13, 16, 16, 14, 14, 13, 14, 13, 14}, {3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 3, 3, Encounter::Grass, {163, 19, 163, 19, 163, 163, 19, 19, 163, 163, 163, 163}, {3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::Grass, {165, 13, 293, 293, 264, 264, 14, 14, 16, 16, 16, 16}, {3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::Grass, {165, 13, 418, 418, 399, 399, 14, 14, 16, 16, 16, 16}, {3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {15, 10, 15, 15, 32}, {25, 20, 25, 25, 32}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 30
        EncounterArea4(158, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 30
        EncounterArea4(159, 1, 1, Encounter::Grass, {165, 13, 165, 13, 69, 69, 14, 14, 16, 16, 16, 16}, {4, 4, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 2, 2, Encounter::Grass, {16, 13, 16, 13, 69, 69, 14, 14, 13, 14, 13, 14}, {4, 4, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 3, 3, Encounter::Grass, {163, 19, 163, 19, 69, 69, 19, 19, 163, 163, 163, 163}, {4, 4, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::Grass, {165, 13, 293, 293, 264, 264, 14, 14, 16, 16, 16, 16}, {4, 4, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::Grass, {165, 13, 418, 418, 399, 399, 14, 14, 16, 16, 16, 16}, {4, 4, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {15, 10, 15, 15, 32}, {25, 20, 25, 25, 32}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 31
        EncounterArea4(159, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 31
        EncounterArea4(160, 1, 1, Encounter::Grass, {69, 23, 69, 23, 179, 179, 187, 187, 19, 41, 19, 41}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 2, 2, Encounter::Grass, {69, 23, 69, 23, 179, 179, 187, 187, 19, 19, 19, 19}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 3, 3, Encounter::Grass, {194, 23, 194, 23, 69, 69, 179, 179, 194, 41, 194, 41}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::Grass, {69, 23, 293, 293, 264, 264, 187, 187, 19, 41, 19, 41}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::Grass, {69, 23, 418, 418, 399, 399, 187, 187, 19, 41, 19, 41}, {6, 4, 6, 4, 6, 6, 6, 6, 6, 4, 6, 4}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::Surfing, {72, 195, 73, 73, 73}, {10, 15, 15, 15, 36}, {20, 25, 25, 25, 36}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::GoodRod, {129, 72, 72, 72, 211}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 32
        EncounterArea4(160, 0, 0, Encounter::SuperRod, {72, 72, 129, 211, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 32
        EncounterArea4(161, 1, 1, Encounter::Grass, {187, 23, 187, 23, 21, 21, 19, 19, 187, 41, 187, 41}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(161, 2, 2, Encounter::Grass, {187, 23, 187, 23, 21, 21, 19, 19, 187, 19, 187, 19}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(161, 3, 3, Encounter::Grass, {41, 23, 41, 23, 19, 19, 19, 19, 41, 41, 41, 41}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(161, 0, 0, Encounter::Grass, {187, 23, 311, 311, 312, 312, 19, 19, 187, 41, 187, 41}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(161, 0, 0, Encounter::Grass, {187, 23, 403, 403, 403, 403, 19, 19, 187, 41, 187, 41}, {6, 7, 6, 7, 6, 6, 6, 6, 8, 4, 8, 4}), // Route 33
        EncounterArea4(162, 0, 0, Encounter::Grass, {96, 19, 96, 19, 96, 96, 63, 63, 19, 132, 19, 132}, {10, 11, 10, 11, 12, 12, 10, 10, 13, 10, 13, 10}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::Grass, {96, 19, 293, 293, 264, 264, 63, 63, 19, 132, 19, 132}, {10, 11, 10, 11, 12, 12, 10, 10, 13, 10, 13, 10}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::Grass, {96, 19, 418, 418, 399, 399, 63, 63, 19, 132, 19, 132}, {10, 11, 10, 11, 12, 12, 10, 10, 13, 10, 13, 10}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 29}, {25, 20, 25, 25, 29}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 34
        EncounterArea4(162, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 34
        EncounterArea4(163, 1, 1, Encounter::Grass, {29, 32, 29, 32, 96, 96, 63, 63, 16, 132, 16, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 2, 2, Encounter::Grass, {29, 32, 29, 32, 96, 96, 63, 63, 16, 132, 16, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 3, 3, Encounter::Grass, {29, 32, 29, 32, 96, 96, 63, 63, 163, 132, 163, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::Grass, {29, 32, 293, 293, 264, 264, 63, 63, 16, 132, 16, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::Grass, {29, 32, 418, 418, 399, 399, 63, 63, 16, 132, 16, 193}, {12, 12, 12, 12, 14, 14, 10, 10, 14, 10, 14, 12}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {15, 10, 15, 15, 31}, {25, 20, 25, 25, 31}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 35
        EncounterArea4(163, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 35
        EncounterArea4(164, 1, 1, Encounter::Grass, {29, 32, 16, 16, 29, 32, 37, 37, 234, 16, 234, 16}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(164, 2, 2, Encounter::Grass, {29, 32, 29, 32, 16, 16, 37, 37, 234, 37, 234, 37}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(164, 3, 3, Encounter::Grass, {29, 32, 29, 32, 163, 163, 37, 37, 234, 163, 234, 163}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(164, 0, 0, Encounter::Grass, {29, 32, 311, 311, 312, 312, 37, 37, 234, 16, 234, 16}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(164, 0, 0, Encounter::Grass, {29, 32, 403, 403, 403, 403, 37, 37, 234, 16, 234, 16}, {12, 12, 12, 12, 13, 13, 13, 13, 13, 15, 13, 15}), // Route 36
        EncounterArea4(165, 1, 1, Encounter::Grass, {165, 234, 165, 234, 16, 16, 37, 37, 165, 165, 165, 165}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(165, 2, 2, Encounter::Grass, {16, 234, 16, 234, 16, 16, 37, 37, 17, 37, 17, 37}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(165, 3, 3, Encounter::Grass, {163, 234, 163, 234, 163, 163, 37, 37, 163, 163, 163, 163}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(165, 0, 0, Encounter::Grass, {165, 234, 311, 311, 312, 312, 37, 37, 165, 165, 165, 165}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(165, 0, 0, Encounter::Grass, {165, 234, 403, 403, 403, 403, 37, 37, 165, 165, 165, 165}, {13, 15, 13, 15, 15, 15, 14, 14, 15, 15, 15, 15}), // Route 37
        EncounterArea4(166, 1, 1, Encounter::Grass, {52, 20, 83, 20, 81, 81, 52, 52, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(166, 2, 2, Encounter::Grass, {52, 20, 52, 20, 81, 81, 83, 83, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(166, 3, 3, Encounter::Grass, {52, 20, 52, 20, 81, 81, 52, 52, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(166, 0, 0, Encounter::Grass, {52, 20, 311, 311, 312, 312, 52, 52, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(166, 0, 0, Encounter::Grass, {52, 20, 403, 403, 403, 403, 52, 52, 241, 128, 241, 209}, {16, 16, 16, 16, 16, 16, 16, 16, 13, 13, 13, 13}), // Route 38
        EncounterArea4(167, 1, 1, Encounter::Grass, {52, 20, 83, 20, 81, 81, 52, 52, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(167, 2, 2, Encounter::Grass, {52, 20, 52, 20, 81, 81, 83, 83, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(167, 3, 3, Encounter::Grass, {52, 20, 52, 20, 81, 81, 52, 52, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(167, 0, 0, Encounter::Grass, {52, 20, 311, 311, 312, 312, 52, 52, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(167, 0, 0, Encounter::Grass, {52, 20, 403, 403, 403, 403, 52, 52, 241, 128, 241, 128}, {16, 17, 16, 17, 16, 16, 16, 16, 15, 15, 15, 15}), // Route 39
        EncounterArea4(168, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Route 40
        EncounterArea4(168, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 40
        EncounterArea4(168, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 40
        EncounterArea4(168, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 40
        EncounterArea4(169, 0, 0, Encounter::Surfing, {72, 72, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Route 41
        EncounterArea4(169, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 41
        EncounterArea4(169, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 41
        EncounterArea4(169, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 41
        EncounterArea4(170, 1, 1, Encounter::Grass, {179, 21, 179, 21, 179, 179, 21, 21, 180, 180, 180, 180}, {13, 14, 13, 14, 15, 15, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 2, 2, Encounter::Grass, {179, 21, 179, 21, 179, 179, 21, 21, 180, 180, 180, 180}, {13, 14, 13, 14, 15, 15, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 3, 3, Encounter::Grass, {179, 41, 179, 41, 179, 179, 41, 41, 180, 180, 180, 180}, {13, 14, 13, 14, 15, 15, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::Grass, {179, 21, 293, 293, 264, 264, 21, 21, 180, 180, 180, 180}, {13, 14, 13, 14, 15, 15, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::Grass, {179, 21, 418, 418, 399, 399, 21, 21, 180, 180, 180, 180}, {13, 14, 13, 14, 15, 15, 16, 16, 15, 17, 15, 17}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 42
        EncounterArea4(170, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 42
        EncounterArea4(171, 1, 1, Encounter::Grass, {180, 203, 180, 203, 17, 17, 179, 179, 48, 17, 48, 17}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 2, 2, Encounter::Grass, {180, 203, 180, 203, 17, 17, 179, 179, 180, 180, 180, 180}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 3, 3, Encounter::Grass, {180, 203, 180, 203, 164, 164, 48, 48, 179, 48, 179, 48}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::Grass, {180, 203, 293, 293, 264, 264, 179, 179, 48, 17, 48, 17}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::Grass, {180, 203, 418, 418, 399, 399, 179, 179, 48, 17, 48, 17}, {15, 15, 15, 15, 17, 17, 15, 15, 16, 17, 16, 17}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {15, 10, 5, 5, 50}, {25, 20, 15, 15, 50}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 43
        EncounterArea4(171, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 43
        EncounterArea4(172, 0, 0, Encounter::Grass, {114, 70, 114, 70, 69, 69, 108, 108, 70, 108, 70, 108}, {23, 22, 23, 22, 22, 22, 24, 24, 24, 26, 24, 26}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::Grass, {114, 70, 293, 293, 264, 264, 108, 108, 70, 108, 70, 108}, {23, 22, 23, 22, 22, 22, 24, 24, 24, 26, 24, 26}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::Grass, {114, 70, 418, 418, 399, 399, 108, 108, 70, 108, 70, 108}, {23, 22, 23, 22, 22, 22, 24, 24, 24, 26, 24, 26}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::Surfing, {60, 60, 61, 61, 61}, {20, 15, 20, 20, 20}, {30, 25, 30, 30, 30}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 223}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 44
        EncounterArea4(172, 0, 0, Encounter::SuperRod, {60, 60, 129, 223, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 44
        EncounterArea4(173, 0, 0, Encounter::Grass, {74, 75, 74, 75, 75, 75, 216, 216, 75, 227, 75, 227}, {23, 23, 23, 23, 24, 24, 20, 20, 25, 27, 25, 27}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::Grass, {74, 75, 293, 293, 264, 264, 216, 216, 75, 227, 75, 227}, {23, 23, 23, 23, 24, 24, 20, 20, 25, 27, 25, 27}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::Grass, {74, 75, 418, 418, 399, 399, 216, 216, 75, 227, 75, 227}, {23, 23, 23, 23, 24, 24, 20, 20, 25, 27, 25, 27}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {15, 10, 2, 2, 2}, {25, 20, 10, 10, 10}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 45
        EncounterArea4(173, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 45
        EncounterArea4(174, 1, 1, Encounter::Grass, {74, 21, 74, 21, 19, 19, 74, 74, 21, 19, 21, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(174, 2, 2, Encounter::Grass, {74, 21, 74, 21, 19, 19, 74, 74, 21, 19, 21, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(174, 3, 3, Encounter::Grass, {74, 19, 74, 19, 19, 19, 74, 74, 74, 19, 74, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(174, 0, 0, Encounter::Grass, {74, 21, 311, 311, 312, 312, 74, 74, 21, 19, 21, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(174, 0, 0, Encounter::Grass, {74, 21, 403, 403, 403, 403, 74, 74, 21, 19, 21, 19}, {3, 2, 3, 2, 2, 2, 2, 2, 3, 4, 3, 4}), // Route 46
        EncounterArea4(175, 1, 1, Encounter::Grass, {83, 241, 132, 132, 132, 132, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 2, 2, Encounter::Grass, {83, 241, 132, 132, 132, 132, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 3, 3, Encounter::Grass, {164, 241, 132, 132, 132, 132, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::Grass, {83, 241, 293, 293, 264, 264, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::Grass, {83, 241, 418, 418, 399, 399, 44, 21, 22, 20, 20, 132}, {35, 35, 34, 33, 32, 31, 32, 31, 34, 31, 33, 40}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::Surfing, {72, 86, 120, 120, 120}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::OldRod, {129, 129, 129, 72, 72}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::GoodRod, {129, 72, 170, 90, 170}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Route 47
        EncounterArea4(175, 0, 0, Encounter::SuperRod, {170, 90, 73, 171, 73}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Route 47
        EncounterArea4(176, 1, 1, Encounter::Grass, {83, 128, 187, 22, 44, 44, 37, 203, 50, 37, 187, 128}, {24, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(176, 2, 2, Encounter::Grass, {83, 128, 187, 22, 44, 44, 37, 203, 50, 37, 187, 128}, {24, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(176, 3, 3, Encounter::Grass, {37, 128, 187, 22, 44, 44, 37, 203, 50, 37, 187, 128}, {24, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(176, 0, 0, Encounter::Grass, {83, 128, 311, 311, 312, 312, 37, 203, 50, 37, 187, 128}, {24, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(176, 0, 0, Encounter::Grass, {83, 128, 403, 403, 403, 403, 37, 203, 50, 37, 187, 128}, {24, 20, 20, 21, 22, 24, 21, 20, 20, 22, 22, 24}), // Route 48
        EncounterArea4(177, 0, 0, Encounter::Grass, {50, 50, 50, 50, 50, 50, 50, 50, 51, 51, 51, 51}, {15, 17, 15, 17, 19, 19, 13, 13, 19, 24, 19, 29}), // Diglettï¿½s Cave
        EncounterArea4(177, 0, 0, Encounter::Grass, {50, 50, 359, 359, 296, 296, 50, 50, 51, 51, 51, 51}, {15, 17, 15, 17, 19, 19, 13, 13, 19, 24, 19, 29}), // Diglettï¿½s Cave
        EncounterArea4(177, 0, 0, Encounter::Grass, {50, 50, 436, 436, 433, 433, 50, 50, 51, 51, 51, 51}, {15, 17, 15, 17, 19, 19, 13, 13, 19, 24, 19, 29}), // Diglettï¿½s Cave
        EncounterArea4(178, 0, 0, Encounter::Grass, {41, 74, 41, 74, 41, 41, 46, 46, 74, 35, 74, 35}, {6, 8, 6, 8, 8, 8, 12, 12, 10, 8, 10, 8}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::Grass, {41, 74, 359, 359, 296, 296, 46, 46, 74, 35, 74, 35}, {6, 8, 6, 8, 8, 8, 12, 12, 10, 8, 10, 8}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::Grass, {41, 74, 436, 436, 433, 433, 46, 46, 74, 35, 74, 35}, {6, 8, 6, 8, 8, 8, 12, 12, 10, 8, 10, 8}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::Surfing, {60, 129, 129, 129, 129}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::GoodRod, {129, 129, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Moon
        EncounterArea4(178, 0, 0, Encounter::SuperRod, {60, 60, 60, 60, 60}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Moon
        EncounterArea4(179, 0, 0, Encounter::Surfing, {60, 60, 60, 60, 60}, {35, 30, 35, 35, 35}, {35, 30, 35, 35, 35}), // Mt. Moon (Clefairy)
        EncounterArea4(179, 0, 0, Encounter::OldRod, {60, 60, 60, 129, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Moon (Clefairy)
        EncounterArea4(179, 0, 0, Encounter::GoodRod, {60, 60, 60, 129, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Moon (Clefairy)
        EncounterArea4(179, 0, 0, Encounter::SuperRod, {60, 60, 60, 129, 60}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Moon (Clefairy)
        EncounterArea4(180, 1, 1, Encounter::Grass, {67, 47, 42, 53, 82, 132, 101, 202, 53, 67, 82, 132}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 2, 2, Encounter::Grass, {67, 47, 42, 53, 82, 132, 101, 202, 53, 67, 82, 132}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 3, 3, Encounter::Grass, {42, 42, 42, 47, 82, 132, 101, 202, 53, 67, 67, 67}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::Grass, {67, 47, 359, 359, 296, 296, 101, 202, 53, 67, 82, 132}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::Grass, {67, 47, 436, 436, 433, 433, 101, 202, 53, 67, 82, 132}, {39, 38, 38, 38, 40, 39, 40, 37, 39, 40, 39, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::RockSmash, {74, 75}, {22, 26}, {24, 30}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {40, 35, 40, 40, 40}, {40, 35, 40, 40, 40}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::GoodRod, {60, 118, 129, 118, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cerulean Cave 1F
        EncounterArea4(180, 0, 0, Encounter::SuperRod, {60, 61, 130, 130, 130}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cerulean Cave 1F
        EncounterArea4(181, 1, 1, Encounter::Grass, {64, 47, 42, 67, 82, 132, 101, 202, 67, 67, 67, 67}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 2, 2, Encounter::Grass, {64, 47, 42, 67, 82, 132, 101, 202, 67, 67, 67, 67}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 3, 3, Encounter::Grass, {64, 47, 42, 67, 82, 132, 101, 202, 42, 42, 42, 42}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::Grass, {64, 47, 359, 359, 296, 296, 101, 202, 67, 67, 67, 67}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::Grass, {64, 47, 436, 436, 433, 433, 101, 202, 67, 67, 67, 67}, {42, 40, 41, 39, 41, 42, 41, 42, 41, 42, 41, 42}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {40, 35, 40, 40, 40}, {40, 35, 40, 40, 40}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::GoodRod, {60, 118, 129, 118, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cerulean Cave 2F
        EncounterArea4(181, 0, 0, Encounter::SuperRod, {60, 61, 130, 130, 130}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cerulean Cave 2F
        EncounterArea4(182, 0, 0, Encounter::Grass, {64, 47, 42, 67, 82, 132, 101, 82, 47, 202, 47, 202}, {46, 45, 47, 45, 45, 45, 46, 47, 47, 49, 47, 49}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::Grass, {64, 47, 359, 359, 296, 296, 101, 82, 47, 202, 47, 202}, {46, 45, 47, 45, 45, 45, 46, 47, 47, 49, 47, 49}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::Grass, {64, 47, 436, 436, 433, 433, 101, 82, 47, 202, 47, 202}, {46, 45, 47, 45, 45, 45, 46, 47, 47, 49, 47, 49}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::RockSmash, {74, 75}, {22, 26}, {24, 30}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {40, 35, 40, 40, 40}, {40, 35, 40, 40, 40}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::GoodRod, {60, 118, 129, 118, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cerulean Cave B1F
        EncounterArea4(182, 0, 0, Encounter::SuperRod, {60, 61, 130, 130, 130}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cerulean Cave B1F
        EncounterArea4(183, 0, 0, Encounter::Grass, {104, 74, 104, 74, 95, 95, 41, 41, 105, 115, 105, 115}, {12, 12, 12, 12, 16, 16, 10, 10, 14, 14, 14, 14}), // Rock Tunnel 1F
        EncounterArea4(183, 0, 0, Encounter::Grass, {104, 74, 359, 359, 296, 296, 41, 41, 105, 115, 105, 115}, {12, 12, 12, 12, 16, 16, 10, 10, 14, 14, 14, 14}), // Rock Tunnel 1F
        EncounterArea4(183, 0, 0, Encounter::Grass, {104, 74, 436, 436, 433, 433, 41, 41, 105, 115, 105, 115}, {12, 12, 12, 12, 16, 16, 10, 10, 14, 14, 14, 14}), // Rock Tunnel 1F
        EncounterArea4(183, 0, 0, Encounter::RockSmash, {74, 74}, {12, 17}, {16, 21}), // Rock Tunnel 1F
        EncounterArea4(184, 0, 0, Encounter::Grass, {104, 74, 104, 74, 66, 66, 41, 41, 67, 104, 67, 104}, {10, 10, 10, 10, 12, 12, 8, 8, 14, 13, 14, 13}), // Rock Tunnel B1F
        EncounterArea4(184, 0, 0, Encounter::Grass, {104, 74, 359, 359, 296, 296, 41, 41, 67, 104, 67, 104}, {10, 10, 10, 10, 12, 12, 8, 8, 14, 13, 14, 13}), // Rock Tunnel B1F
        EncounterArea4(184, 0, 0, Encounter::Grass, {104, 74, 436, 436, 433, 433, 41, 41, 67, 104, 67, 104}, {10, 10, 10, 10, 12, 12, 8, 8, 14, 13, 14, 13}), // Rock Tunnel B1F
        EncounterArea4(185, 0, 0, Encounter::Grass, {41, 42, 54, 54, 42, 55, 41, 41, 54, 54, 54, 54}, {28, 32, 28, 29, 30, 32, 27, 26, 27, 26, 27, 26}), // Seafoam Islands 1F
        EncounterArea4(185, 0, 0, Encounter::Grass, {41, 42, 359, 359, 296, 296, 41, 41, 54, 54, 54, 54}, {28, 32, 28, 29, 30, 32, 27, 26, 27, 26, 27, 26}), // Seafoam Islands 1F
        EncounterArea4(185, 0, 0, Encounter::Grass, {41, 42, 436, 436, 433, 433, 41, 41, 54, 54, 54, 54}, {28, 32, 28, 29, 30, 32, 27, 26, 27, 26, 27, 26}), // Seafoam Islands 1F
        EncounterArea4(186, 0, 0, Encounter::Grass, {86, 42, 54, 86, 42, 55, 41, 41, 55, 54, 54, 54}, {32, 34, 28, 34, 32, 34, 29, 28, 32, 28, 27, 26}), // Seafoam Islands B1F
        EncounterArea4(186, 0, 0, Encounter::Grass, {86, 42, 359, 359, 296, 296, 41, 41, 55, 54, 54, 54}, {32, 34, 28, 34, 32, 34, 29, 28, 32, 28, 27, 26}), // Seafoam Islands B1F
        EncounterArea4(186, 0, 0, Encounter::Grass, {86, 42, 436, 436, 433, 433, 41, 41, 55, 54, 54, 54}, {32, 34, 28, 34, 32, 34, 29, 28, 32, 28, 27, 26}), // Seafoam Islands B1F
        EncounterArea4(187, 0, 0, Encounter::Grass, {86, 42, 54, 86, 42, 55, 41, 41, 55, 54, 54, 54}, {33, 35, 30, 35, 33, 35, 30, 29, 33, 29, 28, 27}), // Seafoam Islands B2F
        EncounterArea4(187, 0, 0, Encounter::Grass, {86, 42, 359, 359, 296, 296, 41, 41, 55, 54, 54, 54}, {33, 35, 30, 35, 33, 35, 30, 29, 33, 29, 28, 27}), // Seafoam Islands B2F
        EncounterArea4(187, 0, 0, Encounter::Grass, {86, 42, 436, 436, 433, 433, 41, 41, 55, 54, 54, 54}, {33, 35, 30, 35, 33, 35, 30, 29, 33, 29, 28, 27}), // Seafoam Islands B2F
        EncounterArea4(188, 0, 0, Encounter::Grass, {87, 42, 54, 86, 42, 55, 41, 41, 55, 87, 54, 54}, {35, 36, 32, 34, 34, 36, 32, 31, 34, 36, 32, 31}), // Seafoam Islands B3F
        EncounterArea4(188, 0, 0, Encounter::Grass, {87, 42, 359, 359, 296, 296, 41, 41, 55, 87, 54, 54}, {35, 36, 32, 34, 34, 36, 32, 31, 34, 36, 32, 31}), // Seafoam Islands B3F
        EncounterArea4(188, 0, 0, Encounter::Grass, {87, 42, 436, 436, 433, 433, 41, 41, 55, 87, 54, 54}, {35, 36, 32, 34, 34, 36, 32, 31, 34, 36, 32, 31}), // Seafoam Islands B3F
        EncounterArea4(189, 0, 0, Encounter::Grass, {87, 42, 54, 86, 124, 55, 42, 42, 55, 87, 124, 124}, {37, 40, 34, 34, 38, 38, 39, 38, 37, 38, 40, 40}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::Grass, {87, 42, 359, 359, 296, 296, 42, 42, 55, 87, 124, 124}, {37, 40, 34, 34, 38, 38, 39, 38, 37, 38, 40, 40}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::Grass, {87, 42, 436, 436, 433, 433, 42, 42, 55, 87, 124, 124}, {37, 40, 34, 34, 38, 38, 39, 38, 37, 38, 40, 40}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::Surfing, {86, 116, 80, 80, 80}, {30, 30, 35, 50, 35}, {40, 40, 45, 50, 45}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::GoodRod, {129, 54, 98, 116, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Seafoam Islands B4F
        EncounterArea4(189, 0, 0, Encounter::SuperRod, {130, 116, 99, 117, 117}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Seafoam Islands B4F
        EncounterArea4(190, 1, 1, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(190, 2, 2, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(190, 3, 3, Encounter::Grass, {92, 92, 92, 92, 92, 92, 19, 19, 92, 19, 92, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(190, 0, 0, Encounter::Grass, {19, 19, 263, 263, 327, 327, 19, 19, 19, 19, 19, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(190, 0, 0, Encounter::Grass, {19, 19, 441, 441, 307, 307, 19, 19, 19, 19, 19, 19}, {3, 4, 3, 4, 5, 5, 3, 3, 6, 5, 6, 5}), // Sprout Tower
        EncounterArea4(191, 1, 1, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(191, 2, 2, Encounter::Grass, {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(191, 3, 3, Encounter::Grass, {92, 92, 92, 92, 92, 92, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(191, 0, 0, Encounter::Grass, {19, 19, 263, 263, 327, 327, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(191, 0, 0, Encounter::Grass, {19, 19, 441, 441, 307, 307, 19, 19, 19, 19, 19, 19}, {20, 21, 20, 21, 22, 22, 22, 22, 23, 24, 23, 24}), // Bell Tower
        EncounterArea4(192, 0, 0, Encounter::Grass, {19, 109, 19, 109, 19, 19, 41, 41, 109, 20, 109, 20}, {13, 14, 13, 14, 15, 15, 14, 14, 16, 15, 16, 15}), // Burned Tower 1F
        EncounterArea4(192, 0, 0, Encounter::Grass, {19, 109, 263, 263, 327, 327, 41, 41, 109, 20, 109, 20}, {13, 14, 13, 14, 15, 15, 14, 14, 16, 15, 16, 15}), // Burned Tower 1F
        EncounterArea4(192, 0, 0, Encounter::Grass, {19, 109, 441, 441, 307, 307, 41, 41, 109, 20, 109, 20}, {13, 14, 13, 14, 15, 15, 14, 14, 16, 15, 16, 15}), // Burned Tower 1F
        EncounterArea4(193, 1, 1, Encounter::Grass, {19, 109, 19, 109, 109, 109, 19, 19, 41, 126, 41, 126}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(193, 2, 2, Encounter::Grass, {19, 109, 19, 109, 109, 109, 126, 126, 41, 19, 41, 19}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(193, 3, 3, Encounter::Grass, {19, 109, 19, 109, 109, 109, 19, 19, 41, 126, 41, 126}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(193, 0, 0, Encounter::Grass, {19, 109, 263, 263, 327, 327, 19, 19, 41, 126, 41, 126}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(193, 0, 0, Encounter::Grass, {19, 109, 441, 441, 307, 307, 19, 19, 41, 126, 41, 126}, {14, 14, 14, 14, 16, 16, 16, 16, 15, 14, 15, 14}), // Burned Tower B1F
        EncounterArea4(194, 1, 1, Encounter::Grass, {13, 14, 13, 14, 13, 13, 16, 16, 16, 16, 16, 16}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(194, 2, 2, Encounter::Grass, {13, 14, 13, 14, 191, 191, 16, 16, 191, 16, 191, 16}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(194, 3, 3, Encounter::Grass, {163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(194, 0, 0, Encounter::Grass, {13, 14, 311, 311, 312, 312, 16, 16, 16, 16, 16, 16}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(194, 0, 0, Encounter::Grass, {13, 14, 403, 403, 403, 403, 16, 16, 16, 16, 16, 16}, {10, 10, 10, 10, 12, 12, 12, 12, 10, 14, 10, 14}), // National Park
        EncounterArea4(195, 0, 0, Encounter::Grass, {177, 177, 177, 177, 177, 177, 177, 177, 235, 235, 235, 235}, {20, 22, 20, 22, 18, 18, 24, 24, 20, 22, 20, 22}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::Grass, {177, 177, 293, 293, 264, 264, 177, 177, 235, 235, 235, 235}, {20, 22, 20, 22, 18, 18, 24, 24, 20, 22, 20, 22}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::Grass, {177, 177, 418, 418, 399, 399, 177, 177, 235, 235, 235, 235}, {20, 22, 20, 22, 18, 18, 24, 24, 20, 22, 20, 22}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::RockSmash, {74, 74}, {8, 3}, {14, 6}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::Surfing, {194, 195, 195, 195, 195}, {10, 15, 10, 10, 10}, {20, 25, 20, 20, 20}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Ruins of Alph (Outside)
        EncounterArea4(195, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Ruins of Alph (Outside)
        EncounterArea4(196, 0, 0, Encounter::Grass, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201}, {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}), // Ruins of Alph (Inside)
        EncounterArea4(197, 0, 0, Encounter::Grass, {74, 19, 74, 19, 41, 41, 19, 19, 41, 95, 41, 95}, {6, 6, 6, 6, 5, 5, 4, 4, 7, 6, 7, 6}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::Grass, {74, 19, 359, 359, 296, 296, 19, 19, 41, 95, 41, 95}, {6, 6, 6, 6, 5, 5, 4, 4, 7, 6, 7, 6}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::Grass, {74, 19, 436, 436, 433, 433, 19, 19, 41, 95, 41, 95}, {6, 6, 6, 6, 5, 5, 4, 4, 7, 6, 7, 6}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::Surfing, {194, 195, 195, 195, 195}, {10, 15, 10, 10, 10}, {20, 25, 20, 20, 20}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Union Cave 1F
        EncounterArea4(197, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Union Cave 1F
        EncounterArea4(198, 0, 0, Encounter::Grass, {74, 19, 74, 19, 41, 41, 95, 95, 41, 19, 41, 19}, {8, 8, 8, 8, 7, 7, 8, 8, 9, 6, 9, 6}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::Grass, {74, 19, 359, 359, 296, 296, 95, 95, 41, 19, 41, 19}, {8, 8, 8, 8, 7, 7, 8, 8, 9, 6, 9, 6}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::Grass, {74, 19, 436, 436, 433, 433, 95, 95, 41, 19, 41, 19}, {8, 8, 8, 8, 7, 7, 8, 8, 9, 6, 9, 6}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::Surfing, {194, 195, 195, 195, 195}, {10, 15, 10, 10, 10}, {20, 25, 20, 20, 20}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Union Cave B1F
        EncounterArea4(198, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Union Cave B1F
        EncounterArea4(199, 0, 0, Encounter::Grass, {41, 20, 41, 20, 42, 42, 74, 74, 19, 95, 19, 95}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::Grass, {41, 20, 359, 359, 296, 296, 74, 74, 19, 95, 19, 95}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::Grass, {41, 20, 436, 436, 433, 433, 74, 74, 19, 95, 19, 95}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::Surfing, {72, 195, 73, 73, 73}, {10, 15, 15, 15, 15}, {20, 25, 25, 25, 25}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::GoodRod, {129, 98, 98, 222, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Union Cave B2F
        EncounterArea4(199, 0, 0, Encounter::SuperRod, {98, 222, 98, 99, 98}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Union Cave B2F
        EncounterArea4(200, 0, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 79, 79, 41, 79, 41, 79}, {5, 6, 5, 6, 7, 7, 6, 6, 8, 8, 8, 8}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::Grass, {41, 41, 359, 359, 296, 296, 79, 79, 41, 79, 41, 79}, {5, 6, 5, 6, 7, 7, 6, 6, 8, 8, 8, 8}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::Grass, {41, 41, 436, 436, 433, 433, 79, 79, 41, 79, 41, 79}, {5, 6, 5, 6, 7, 7, 6, 6, 8, 8, 8, 8}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::Surfing, {79, 79, 79, 79, 79}, {10, 15, 5, 5, 5}, {20, 25, 15, 15, 15}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Slowpoke Well 1F
        EncounterArea4(200, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Slowpoke Well 1F
        EncounterArea4(201, 0, 0, Encounter::Grass, {41, 41, 41, 41, 41, 41, 79, 79, 42, 79, 42, 79}, {21, 23, 21, 23, 19, 19, 21, 21, 23, 23, 23, 23}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::Grass, {41, 41, 359, 359, 296, 296, 79, 79, 42, 79, 42, 79}, {21, 23, 21, 23, 19, 19, 21, 21, 23, 23, 23, 23}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::Grass, {41, 41, 436, 436, 433, 433, 79, 79, 42, 79, 42, 79}, {21, 23, 21, 23, 19, 19, 21, 21, 23, 23, 23, 23}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::Surfing, {79, 79, 80, 80, 80}, {10, 15, 15, 15, 30}, {20, 25, 25, 25, 30}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Slowpoke Well B1F
        EncounterArea4(201, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Slowpoke Well B1F
        EncounterArea4(202, 1, 1, Encounter::Grass, {13, 14, 13, 14, 13, 13, 46, 46, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 2, 2, Encounter::Grass, {13, 13, 13, 13, 14, 14, 14, 14, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 3, 3, Encounter::Grass, {43, 43, 43, 43, 41, 41, 46, 46, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::Grass, {13, 14, 325, 325, 322, 322, 46, 46, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::Grass, {13, 14, 406, 406, 455, 455, 46, 46, 41, 46, 41, 46}, {5, 6, 5, 6, 6, 6, 5, 5, 5, 6, 5, 6}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::Surfing, {54, 54, 55, 55, 55}, {10, 5, 10, 10, 10}, {20, 15, 20, 20, 20}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Ilex Forest
        EncounterArea4(202, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Ilex Forest
        EncounterArea4(203, 0, 0, Encounter::Grass, {41, 41, 41, 41, 66, 66, 19, 19, 74, 19, 74, 183}, {13, 15, 13, 15, 14, 14, 14, 14, 14, 16, 14, 15}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::Grass, {41, 41, 359, 359, 296, 296, 19, 19, 74, 19, 74, 183}, {13, 15, 13, 15, 14, 14, 14, 14, 14, 16, 14, 15}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::Grass, {41, 41, 436, 436, 433, 433, 19, 19, 74, 19, 74, 183}, {13, 15, 13, 15, 14, 14, 14, 14, 14, 16, 14, 15}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Mortar 1F
        EncounterArea4(203, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Mortar 1F
        EncounterArea4(204, 0, 0, Encounter::Grass, {74, 66, 74, 66, 74, 74, 19, 19, 66, 41, 66, 41}, {13, 13, 13, 13, 15, 15, 14, 14, 15, 14, 15, 14}), // Mt. Mortar 1F (Back)
        EncounterArea4(204, 0, 0, Encounter::Grass, {74, 66, 359, 359, 296, 296, 19, 19, 66, 41, 66, 41}, {13, 13, 13, 13, 15, 15, 14, 14, 15, 14, 15, 14}), // Mt. Mortar 1F (Back)
        EncounterArea4(204, 0, 0, Encounter::Grass, {74, 66, 436, 436, 433, 433, 19, 19, 66, 41, 66, 41}, {13, 13, 13, 13, 15, 15, 14, 14, 15, 14, 15, 14}), // Mt. Mortar 1F (Back)
        EncounterArea4(205, 0, 0, Encounter::Grass, {75, 67, 75, 67, 74, 74, 20, 20, 66, 42, 66, 42}, {31, 32, 31, 32, 31, 31, 30, 30, 28, 30, 28, 30}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::Grass, {75, 67, 359, 359, 296, 296, 20, 20, 66, 42, 66, 42}, {31, 32, 31, 32, 31, 31, 30, 30, 28, 30, 28, 30}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::Grass, {75, 67, 436, 436, 433, 433, 20, 20, 66, 42, 66, 42}, {31, 32, 31, 32, 31, 31, 30, 30, 28, 30, 28, 30}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 20, 20, 20, 20}, {25, 30, 30, 30, 30}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Mortar 2F
        EncounterArea4(205, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Mortar 2F
        EncounterArea4(206, 0, 0, Encounter::Grass, {41, 41, 41, 41, 19, 19, 66, 66, 74, 20, 74, 20}, {15, 17, 15, 17, 16, 16, 16, 16, 16, 16, 16, 16}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::Grass, {41, 41, 359, 359, 296, 296, 66, 66, 74, 20, 74, 20}, {15, 17, 15, 17, 16, 16, 16, 16, 16, 16, 16, 16}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::Grass, {41, 41, 436, 436, 433, 433, 66, 66, 74, 20, 74, 20}, {15, 17, 15, 17, 16, 16, 16, 16, 16, 16, 16, 16}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::Surfing, {118, 118, 119, 119, 119}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Mortar B1F
        EncounterArea4(206, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Mortar B1F
        EncounterArea4(207, 1, 1, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(207, 2, 2, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 124, 124, 124, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(207, 3, 3, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(207, 0, 0, Encounter::Grass, {220, 42, 359, 359, 296, 296, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(207, 0, 0, Encounter::Grass, {220, 42, 436, 436, 433, 433, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path 1F
        EncounterArea4(208, 1, 1, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(208, 2, 2, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 124, 124, 124, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(208, 3, 3, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(208, 0, 0, Encounter::Grass, {220, 42, 359, 359, 296, 296, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(208, 0, 0, Encounter::Grass, {220, 42, 436, 436, 433, 433, 220, 220, 41, 124, 41, 124}, {21, 22, 21, 22, 22, 22, 23, 23, 22, 22, 22, 22}), // Ice Path B1F
        EncounterArea4(209, 1, 1, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(209, 2, 2, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 124, 124, 124, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(209, 3, 3, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(209, 0, 0, Encounter::Grass, {220, 42, 359, 359, 296, 296, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(209, 0, 0, Encounter::Grass, {220, 42, 436, 436, 433, 433, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B2F
        EncounterArea4(210, 1, 1, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(210, 2, 2, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 124, 124, 124, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(210, 3, 3, Encounter::Grass, {220, 42, 220, 42, 225, 225, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(210, 0, 0, Encounter::Grass, {220, 42, 359, 359, 296, 296, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(210, 0, 0, Encounter::Grass, {220, 42, 436, 436, 433, 433, 220, 220, 41, 124, 41, 124}, {22, 23, 22, 23, 23, 23, 24, 24, 23, 23, 23, 23}), // Ice Path B3F
        EncounterArea4(211, 0, 0, Encounter::Grass, {98, 41, 98, 41, 98, 98, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::Grass, {98, 41, 359, 359, 296, 296, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::Grass, {98, 41, 436, 436, 433, 433, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::Surfing, {72, 116, 73, 73, 73}, {15, 10, 15, 15, 15}, {25, 20, 25, 25, 25}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::GoodRod, {129, 98, 98, 116, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Whirl Islands 1F
        EncounterArea4(211, 0, 0, Encounter::SuperRod, {98, 116, 99, 117, 99}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Whirl Islands 1F
        EncounterArea4(212, 0, 0, Encounter::Grass, {98, 41, 98, 41, 98, 98, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B1F
        EncounterArea4(212, 0, 0, Encounter::Grass, {98, 41, 359, 359, 296, 296, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B1F
        EncounterArea4(212, 0, 0, Encounter::Grass, {98, 41, 436, 436, 433, 433, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B1F
        EncounterArea4(213, 0, 0, Encounter::Grass, {98, 41, 98, 41, 98, 98, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::Grass, {98, 41, 359, 359, 296, 296, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::Grass, {98, 41, 436, 436, 433, 433, 86, 86, 42, 86, 42, 86}, {22, 23, 22, 23, 24, 24, 22, 22, 23, 24, 23, 24}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::Surfing, {116, 73, 117, 117, 117}, {15, 15, 15, 15, 30}, {25, 25, 25, 25, 30}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::OldRod, {129, 129, 129, 98, 98}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::GoodRod, {129, 98, 98, 116, 98}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Whirl Islands B2F
        EncounterArea4(213, 0, 0, Encounter::SuperRod, {98, 116, 99, 117, 99}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Whirl Islands B2F
        EncounterArea4(214, 0, 0, Encounter::Grass, {98, 41, 98, 41, 98, 98, 86, 86, 42, 86, 42, 86}, {23, 24, 23, 24, 25, 25, 23, 23, 24, 25, 24, 25}), // Whirl Islands B3F
        EncounterArea4(214, 0, 0, Encounter::Grass, {98, 41, 359, 359, 296, 296, 86, 86, 42, 86, 42, 86}, {23, 24, 23, 24, 25, 25, 23, 23, 24, 25, 24, 25}), // Whirl Islands B3F
        EncounterArea4(214, 0, 0, Encounter::Grass, {98, 41, 436, 436, 433, 433, 86, 86, 42, 86, 42, 86}, {23, 24, 23, 24, 25, 25, 23, 23, 24, 25, 24, 25}), // Whirl Islands B3F
        EncounterArea4(215, 1, 1, Encounter::Grass, {114, 77, 114, 77, 217, 217, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 2, 2, Encounter::Grass, {114, 77, 114, 77, 217, 217, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 3, 3, Encounter::Grass, {114, 77, 114, 77, 217, 217, 78, 78, 215, 215, 215, 215}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::Grass, {114, 77, 293, 293, 264, 264, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::Grass, {114, 77, 418, 418, 399, 399, 78, 78, 84, 85, 84, 85}, {41, 42, 41, 42, 42, 42, 44, 44, 41, 43, 41, 43}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::Surfing, {61, 61, 60, 60, 61}, {30, 35, 30, 30, 48}, {40, 45, 40, 40, 48}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::OldRod, {129, 129, 129, 60, 60}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::GoodRod, {129, 60, 60, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver
        EncounterArea4(215, 0, 0, Encounter::SuperRod, {60, 60, 129, 60, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver
        EncounterArea4(216, 1, 1, Encounter::Grass, {195, 208, 195, 55, 217, 217, 195, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 2, 2, Encounter::Grass, {195, 208, 195, 55, 217, 217, 195, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 3, 3, Encounter::Grass, {195, 208, 195, 55, 217, 217, 200, 200, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::Grass, {195, 208, 359, 359, 296, 296, 195, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::Grass, {195, 208, 436, 436, 433, 433, 195, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 48, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 118}, {30, 35, 30, 30, 30}, {40, 45, 40, 40, 40}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver 1F
        EncounterArea4(216, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver 1F
        EncounterArea4(217, 1, 1, Encounter::Grass, {195, 215, 216, 55, 217, 217, 195, 195, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 2, 2, Encounter::Grass, {195, 215, 216, 55, 217, 217, 195, 195, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 3, 3, Encounter::Grass, {195, 215, 216, 55, 217, 217, 200, 200, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::Grass, {195, 215, 359, 359, 296, 296, 195, 195, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::Grass, {195, 215, 436, 436, 433, 433, 195, 195, 42, 246, 42, 246}, {45, 48, 46, 48, 48, 50, 45, 45, 48, 20, 48, 15}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 118}, {30, 35, 30, 30, 30}, {40, 45, 40, 40, 40}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver 1F Top
        EncounterArea4(217, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver 1F Top
        EncounterArea4(218, 0, 0, Encounter::Grass, {95, 217, 95, 217, 216, 75, 75, 75, 42, 246, 42, 246}, {42, 44, 42, 44, 43, 43, 42, 41, 45, 20, 45, 15}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::Grass, {95, 217, 359, 359, 296, 296, 75, 75, 42, 246, 42, 246}, {42, 44, 42, 44, 43, 43, 42, 41, 45, 20, 45, 15}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::Grass, {95, 217, 436, 436, 433, 433, 75, 75, 42, 246, 42, 246}, {42, 44, 42, 44, 43, 43, 42, 41, 45, 20, 45, 15}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 119}, {30, 35, 30, 30, 50}, {40, 45, 40, 40, 50}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::GoodRod, {129, 118, 119, 129, 119}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver 2F
        EncounterArea4(218, 0, 0, Encounter::SuperRod, {130, 119, 119, 130, 119}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver 2F
        EncounterArea4(219, 1, 1, Encounter::Grass, {195, 55, 195, 216, 217, 217, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(219, 2, 2, Encounter::Grass, {195, 55, 195, 216, 217, 217, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(219, 3, 3, Encounter::Grass, {200, 55, 200, 216, 217, 217, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(219, 0, 0, Encounter::Grass, {195, 55, 359, 359, 296, 296, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(219, 0, 0, Encounter::Grass, {195, 55, 436, 436, 433, 433, 247, 195, 42, 246, 42, 246}, {45, 48, 45, 46, 48, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver 3F
        EncounterArea4(220, 1, 1, Encounter::Grass, {215, 55, 195, 55, 217, 217, 195, 195, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 2, 2, Encounter::Grass, {215, 55, 195, 55, 217, 217, 195, 195, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 3, 3, Encounter::Grass, {215, 55, 195, 55, 217, 217, 200, 200, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::Grass, {215, 55, 359, 359, 296, 296, 195, 195, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::Grass, {215, 55, 436, 436, 433, 433, 195, 195, 42, 246, 42, 246}, {50, 48, 45, 48, 47, 47, 45, 45, 48, 20, 48, 15}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 118}, {30, 35, 30, 30, 30}, {40, 45, 40, 40, 40}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver 4F
        EncounterArea4(220, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver 4F
        EncounterArea4(221, 0, 0, Encounter::Grass, {42, 95, 42, 95, 216, 42, 217, 217, 55, 246, 55, 246}, {51, 48, 51, 48, 48, 48, 50, 50, 51, 20, 51, 15}), // Mt. Silver Mountainside
        EncounterArea4(221, 0, 0, Encounter::Grass, {42, 95, 359, 359, 296, 296, 217, 217, 55, 246, 55, 246}, {51, 48, 51, 48, 48, 48, 50, 50, 51, 20, 51, 15}), // Mt. Silver Mountainside
        EncounterArea4(221, 0, 0, Encounter::Grass, {42, 95, 436, 436, 433, 433, 217, 217, 55, 246, 55, 246}, {51, 48, 51, 48, 48, 48, 50, 50, 51, 20, 51, 15}), // Mt. Silver Mountainside
        EncounterArea4(222, 1, 1, Encounter::Grass, {215, 55, 195, 55, 217, 217, 246, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 2, 2, Encounter::Grass, {215, 55, 195, 55, 217, 217, 246, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 3, 3, Encounter::Grass, {215, 55, 195, 200, 217, 217, 246, 200, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::Grass, {215, 55, 359, 359, 296, 296, 246, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::Grass, {215, 55, 436, 436, 433, 433, 246, 195, 42, 246, 42, 246}, {45, 48, 45, 48, 47, 47, 30, 45, 48, 20, 48, 15}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::Surfing, {119, 119, 118, 118, 118}, {30, 35, 30, 30, 30}, {40, 45, 40, 40, 40}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Mt. Silver Top
        EncounterArea4(222, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Mt. Silver Top
        EncounterArea4(223, 0, 0, Encounter::Grass, {74, 41, 74, 41, 74, 74, 74, 74, 41, 41, 41, 206}, {3, 2, 3, 2, 2, 2, 4, 4, 3, 4, 3, 4}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::Grass, {74, 41, 359, 359, 296, 296, 74, 74, 41, 41, 41, 206}, {3, 2, 3, 2, 2, 2, 4, 4, 3, 4, 3, 4}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::Grass, {74, 41, 436, 436, 433, 433, 74, 74, 41, 41, 41, 206}, {3, 2, 3, 2, 2, 2, 4, 4, 3, 4, 3, 4}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::RockSmash, {206, 74}, {4, 8}, {8, 14}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {10, 5, 2, 2, 2}, {20, 15, 10, 10, 10}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Dark Cave (Route 31)
        EncounterArea4(223, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Dark Cave (Route 31)
        EncounterArea4(224, 0, 0, Encounter::Grass, {74, 41, 74, 41, 75, 75, 202, 202, 202, 42, 202, 42}, {23, 23, 23, 23, 25, 25, 20, 20, 25, 23, 25, 23}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::Grass, {74, 41, 359, 359, 296, 296, 202, 202, 202, 42, 202, 42}, {23, 23, 23, 23, 25, 25, 20, 20, 25, 23, 25, 23}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::Grass, {74, 41, 436, 436, 433, 433, 202, 202, 202, 42, 202, 42}, {23, 23, 23, 23, 25, 25, 20, 20, 25, 23, 25, 23}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::Surfing, {129, 129, 129, 129, 129}, {10, 5, 2, 2, 2}, {20, 15, 10, 10, 10}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Dark Cave (Route 45)
        EncounterArea4(224, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Dark Cave (Route 45)
        EncounterArea4(225, 0, 0, Encounter::Grass, {75, 42, 75, 42, 217, 217, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 1F
        EncounterArea4(225, 0, 0, Encounter::Grass, {75, 42, 359, 359, 296, 296, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 1F
        EncounterArea4(225, 0, 0, Encounter::Grass, {75, 42, 436, 436, 433, 433, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 1F
        EncounterArea4(226, 0, 0, Encounter::Grass, {75, 42, 75, 42, 217, 217, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 2F
        EncounterArea4(226, 0, 0, Encounter::Grass, {75, 42, 359, 359, 296, 296, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 2F
        EncounterArea4(226, 0, 0, Encounter::Grass, {75, 42, 436, 436, 433, 433, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 2F
        EncounterArea4(227, 0, 0, Encounter::Grass, {75, 42, 75, 42, 217, 217, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 3F
        EncounterArea4(227, 0, 0, Encounter::Grass, {75, 42, 359, 359, 296, 296, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 3F
        EncounterArea4(227, 0, 0, Encounter::Grass, {75, 42, 436, 436, 433, 433, 95, 95, 95, 111, 95, 111}, {32, 32, 32, 32, 33, 33, 34, 34, 36, 35, 36, 35}), // Victory Road 3F
        EncounterArea4(227, 0, 0, Encounter::RockSmash, {74, 75}, {24, 30}, {32, 33}), // Victory Road 3F
        EncounterArea4(228, 0, 0, Encounter::Surfing, {129, 129, 147, 147, 147}, {10, 5, 5, 5, 5}, {20, 15, 15, 15, 15}), // Dragonï¿½s Den
        EncounterArea4(228, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Dragonï¿½s Den
        EncounterArea4(228, 0, 0, Encounter::GoodRod, {129, 129, 129, 147, 129}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Dragonï¿½s Den
        EncounterArea4(228, 0, 0, Encounter::SuperRod, {129, 147, 129, 148, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Dragonï¿½s Den
        EncounterArea4(229, 0, 0, Encounter::Grass, {41, 20, 41, 20, 42, 42, 79, 79, 19, 79, 19, 79}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::Grass, {41, 20, 359, 359, 296, 296, 79, 79, 19, 79, 19, 79}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::Grass, {41, 20, 436, 436, 433, 433, 79, 79, 19, 79, 19, 79}, {22, 22, 22, 22, 22, 22, 21, 21, 20, 23, 20, 23}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::Surfing, {118, 79, 119, 119, 119}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::OldRod, {129, 129, 129, 118, 118}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::GoodRod, {129, 118, 118, 118, 118}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Tohjo Falls
        EncounterArea4(229, 0, 0, Encounter::SuperRod, {118, 118, 129, 119, 129}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Tohjo Falls
        EncounterArea4(230, 1, 1, Encounter::Grass, {13, 13, 14, 16, 14, 14, 15, 15, 17, 25, 25, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(230, 2, 2, Encounter::Grass, {13, 13, 14, 16, 14, 14, 16, 17, 17, 25, 25, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(230, 3, 3, Encounter::Grass, {163, 163, 163, 163, 163, 163, 164, 164, 164, 25, 164, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(230, 0, 0, Encounter::Grass, {13, 13, 325, 325, 322, 322, 15, 15, 17, 25, 25, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(230, 0, 0, Encounter::Grass, {13, 13, 406, 406, 455, 455, 15, 15, 17, 25, 25, 25}, {3, 3, 3, 3, 5, 5, 7, 7, 7, 4, 7, 4}), // Viridian Forest
        EncounterArea4(231, 1, 1, Encounter::Grass, {42, 74, 98, 99, 66, 95, 194, 195, 75, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 2, 2, Encounter::Grass, {42, 74, 98, 99, 66, 95, 194, 195, 75, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 3, 3, Encounter::Grass, {42, 74, 98, 99, 66, 95, 41, 200, 42, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 0, 0, Encounter::Grass, {42, 74, 359, 359, 296, 296, 194, 195, 75, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 0, 0, Encounter::Grass, {42, 74, 436, 436, 433, 433, 194, 195, 75, 67, 208, 208}, {22, 19, 20, 22, 19, 20, 18, 20, 20, 22, 23, 23}), // Cliff Cave
        EncounterArea4(231, 0, 0, Encounter::RockSmash, {98, 99}, {20, 28}, {26, 31}), // Cliff Cave
        EncounterArea4(232, 0, 0, Encounter::Surfing, {194, 194, 195, 195, 195}, {20, 20, 30, 30, 30}, {30, 30, 40, 40, 40}), // Cliff Edge Gate
        EncounterArea4(232, 0, 0, Encounter::OldRod, {129, 129, 129, 129, 129}, {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10}), // Cliff Edge Gate
        EncounterArea4(232, 0, 0, Encounter::GoodRod, {129, 129, 129, 60, 60}, {20, 20, 20, 20, 20}, {20, 20, 20, 20, 20}), // Cliff Edge Gate
        EncounterArea4(232, 0, 0, Encounter::SuperRod, {129, 129, 60, 60, 60}, {40, 40, 40, 40, 40}, {40, 40, 40, 40, 40}), // Cliff Edge Gate
    };
};

#endif // ENCOUNTERS4_HPP
