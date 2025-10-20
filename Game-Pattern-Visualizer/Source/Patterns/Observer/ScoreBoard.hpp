/**
 * @ Author: Foldear
 * @ Filename: ScoreBoard.hpp
 * @ Modified time: 2025-10-20 10:16:55
 * @ Description:
 */

#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include "Observer.hpp"
#include "iostream"
#include <vector>

namespace GPV
{

class ScoreBoard : public Observer
{
  public:
    ScoreBoard();
    void onNotify();
};

} // namespace GPV

#endif