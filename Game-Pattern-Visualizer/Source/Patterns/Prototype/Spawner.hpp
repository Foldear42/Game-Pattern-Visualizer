#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <memory>

#include "Enemy.hpp"

namespace GPV
{

class Spawner
{
   public:
    ~Spawner()
    {
    }
    // virtual std::auto_ptr<Enemy> spawnEnemy() = 0;
};

}  // namespace GPV

#endif