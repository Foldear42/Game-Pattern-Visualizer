#ifndef TERRAIN_INTRASIC_CPP
#define TERRAIN_INTRASIC_CPP

#include "TerrainIntrinsic.hpp"

namespace GPV
{
TerrainIntrinsic::TerrainIntrinsic(const sf::Texture &texture) : m_sprite(texture)
{
}

void TerrainIntrinsic::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}

void TerrainIntrinsic::setSpritePosition(sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

}  // namespace GPV

#endif