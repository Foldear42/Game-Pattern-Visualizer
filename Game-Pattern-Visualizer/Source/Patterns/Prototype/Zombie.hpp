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