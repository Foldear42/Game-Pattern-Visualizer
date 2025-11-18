#ifndef TERRAIN_EXTRINSIC_CPP
#define TERRAIN_EXTRINSIC_CPP

#include "TerrainExtrinsic.hpp"

namespace GPV
{
TerrainExtrinsic::TerrainExtrinsic(TerrainIntrinsic& terrainIntrasic) : m_terrainIntrinsic(terrainIntrasic)
{
    m_bounds = terrainIntrasic.getSpriteGlobalBounds();
}

void TerrainExtrinsic::setPosition(sf::Vector2f position)
{
    m_position = position;
    m_bounds.position = m_position;
}

void TerrainExtrinsic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    m_terrainIntrinsic.setSpritePosition(m_position);
    target.draw(m_terrainIntrinsic, states);
}

const std::string TerrainExtrinsic::getInfos() const
{
    return "[Extrinsic State]\nx: " + std::to_string(m_position.x) + "\n" + "y: " + std::to_string(m_position.y) + "\n" +
           "Size of intrasic data : " + std::to_string(sizeof(TerrainIntrinsic)) + "\n";
}

}  // namespace GPV

#endif
