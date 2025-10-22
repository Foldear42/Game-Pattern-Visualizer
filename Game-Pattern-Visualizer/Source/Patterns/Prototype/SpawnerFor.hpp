/**
 * @ Author: Foldear
 * @ Filename: SpawnerFor.hpp
 * @ Modified time: 2025-10-22 10:29:51
 * @ Description:
 */

#ifndef SPAWNER_FOR_HPP
#define SPAWNER_FOR_HPP

#include "Spawner.hpp"
#include <memory>

namespace GPV
{

template <class T> class SpawnerFor : public Spawner
{
  public:
    virtual std::auto_ptr<Enemy> spawnEnemy()
    {
        return new T();
    }
};

} // namespace GPV

#endif