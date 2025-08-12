/**
 * @ Author: Foldear
 * @ Filename: Map.hpp
 * @ Modified time: 2025-07-07 15:25:29
 * @ Description:
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

namespace GPV
{
class Map : public sf::Drawable
{
    static constexpr std::size_t COLS = 100;
    static constexpr std::size_t ROWS = 100;

    std::array<std::array<sf::RectangleShape, COLS>, ROWS> m_map;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Map();
};
} // namespace GPV

#endif