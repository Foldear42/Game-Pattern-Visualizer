#ifndef TERRAIN_EXTRINSIC_CPP
#define TERRAIN_EXTRINSIC_CPP

#include "TerrainExtrinsic.hpp"

namespace GPV
{
TerrainExtrinsic::TerrainExtrinsic(TerrainIntrinsic& terrainIntrasic) : m_terrainIntrinsic(terrainIntrasic)
{
}

void TerrainExtrinsic::setPosition(sf::Vector2f position)
{
    m_position = position;
}

void TerrainExtrinsic::setTerrainIntrinsic(TerrainIntrinsic& terrainIntrinsic)
{
    m_terrainIntrinsic = terrainIntrinsic;
}

void TerrainExtrinsic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    m_terrainIntrinsic.setSpritePosition(m_position);
    target.draw(m_terrainIntrinsic, states);
}

}  // namespace GPV

#endif
