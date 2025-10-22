/**
 * @ Author: Foldear
 * @ Filename: Spawner.hpp
 * @ Modified time: 2025-10-22 09:50:13
 * @ Description:
 */

#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include "Enemy.hpp"
#include <memory>

namespace GPV
{

class Spawner
{
  public:
    ~Spawner() {}
    virtual std::auto_ptr<Enemy> spawnEnemy() = 0;
};

} // namespace GPV

#endif