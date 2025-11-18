#ifndef TERRAIN_INTRINSIC_CPP
#define TERRAIN_INTRINSIC_CPP

#include "TerrainIntrinsic.hpp"

namespace GPV
{
TerrainIntrinsic::TerrainIntrinsic(const sf::Texture &texture) : m_sprite(texture)
{
    std::cout << std::to_string(sizeof(TerrainIntrinsic)) << std::endl;
}

void TerrainIntrinsic::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}

void TerrainIntrinsic::setSpritePosition(sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

const sf::FloatRect TerrainIntrinsic::getSpriteGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}

}  // namespace GPV

#endif