/**
 * @ Author: Foldear
 * @ Filename: Terrain.cpp
 * @ Modified time: 2025-10-09 16:28:06
 * @ Description:
 */

#ifndef TERRAIN_CPP
#define TERRAIN_CPP

#include "Terrain.hpp"

namespace GPV
{
Terrain::Terrain(const sf::Texture &texture) : m_sprite(texture) {}

void Terrain::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    target.draw(m_sprite, states);
}

void Terrain::SetPosition(sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

} // namespace GPV

#endif