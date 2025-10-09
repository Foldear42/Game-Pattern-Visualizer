/**
 * @ Author: Foldear
 * @ Filename: Terrain.hpp
 * @ Modified time: 2025-10-09 16:27:49
 * @ Description:
 */

#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <SFML/Graphics.hpp>

namespace GPV
{
class Terrain : public sf::Drawable
{
    sf::Sprite m_sprite;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Terrain(const sf::Texture &texture);
    void SetPosition(sf::Vector2f position);
};
} // namespace GPV

#endif