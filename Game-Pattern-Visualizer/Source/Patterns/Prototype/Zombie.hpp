/**
 * @ Author: Foldear
 * @ Filename: Zombie.hpp
 * @ Modified time: 2025-10-22 10:42:02
 * @ Description:
 */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Enemy.hpp"

namespace GPV
{

class Zombie : public Enemy
{
  public:
    Zombie();
    void followPlayer();
};

} // namespace GPV

#endif