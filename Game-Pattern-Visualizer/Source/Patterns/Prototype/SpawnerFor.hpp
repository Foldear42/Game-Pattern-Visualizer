#ifndef SPAWNER_FOR_HPP
#define SPAWNER_FOR_HPP

#include <memory>

#include "Spawner.hpp"

namespace GPV
{

template <class T>
class SpawnerFor : public Spawner
{
   public:
    /* virtual std::auto_ptr<Enemy> spawnEnemy()
     {
         return new T();
     }*/
};

}  // namespace GPV

#endif