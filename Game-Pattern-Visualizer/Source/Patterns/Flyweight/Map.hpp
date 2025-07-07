/**
 * @ Author: Foldear
 * @ Filename: Map.hpp
 * @ Modified time: 2025-07-06 11:30:36
 * @ Description:
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

namespace GPV
{
class Map : public sf::Drawable
{
    // std::vector<std::vector<>> m_map;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
};
} // namespace GPV

#endif