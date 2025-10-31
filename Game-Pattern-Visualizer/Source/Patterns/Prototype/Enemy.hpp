#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <memory>

namespace GPV
{

class Enemy : public sf::Drawable
{
  public:
    ~Enemy();
    virtual void followPlayer() = 0;
};

} // namespace GPV

#endif