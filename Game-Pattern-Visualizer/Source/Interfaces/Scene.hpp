/**
 * @ Author: Foldear
 * @ Filename:
 * @ Modified time: 2025-07-04 13:10:13
 * @ Description:
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>

namespace GPV
{

class Scene : public sf::Drawable
{
  public:
    virtual ~Scene() = default;
    virtual void update(Application &application, sf::Time delta) = 0;
};
} // namespace GPV

#endif