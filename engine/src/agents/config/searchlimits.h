/*
  CrazyAra, a deep learning chess variant engine
  Copyright (C) 2018       Johannes Czech, Moritz Willig, Alena Beyer
  Copyright (C) 2019-2020  Johannes Czech

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
 * @file: searchlimits.h
 * Created on 12.06.2019
 * @author: queensgambit
 *
 * Struct which stores information about when to stop the search
 */

#include <chrono>
#include <ostream>
#include "uci/optionsuci.h"

#ifndef SEARCHLIMITS_H
#define SEARCHLIMITS_H

typedef std::chrono::milliseconds::rep TimePoint; // A value in milliseconds

struct SearchLimits
{
public:
    TimePoint movetime;
    size_t nodes;
    size_t simulations;
    int movestogo;
    int depth;
    int minMovetime;
    int time[2];
    int inc[2];
    TimePoint npmsec;
    TimePoint startTime;
    int moveOverhead;
    bool infinite;
    bool ponder;

    SearchLimits();

    /**
     * @brief reset Resets all search limits
     */
    void reset();

    /**
     * @brief init_new_search Initializes the struct according to the given OptionsMap for a new search
     * @param options UCI Options struct
     */
    void init_new_search(OptionsMap &options);
};

/**
 * @brief is_game_sceneario Checks if the searchLimits comply to a game scenario
 * @param searchLimits object handle
 * @return True if in game situation else false
 */
bool is_game_sceneario(const SearchLimits* searchLimits);

extern std::ostream& operator<<(std::ostream& os, const SearchLimits& searchLimits);

#endif // SEARCHLIMITS_H
