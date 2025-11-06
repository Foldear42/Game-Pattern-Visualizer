#ifndef TERRAIN_EXTRINSIC_HPP
#define TERRAIN_EXTRINSIC_HPP

#include <SFML/Graphics.hpp>

#include "TerrainIntrinsic.hpp"

namespace GPV
{
class TerrainExtrinsic : public sf::Drawable
{
    sf::Vector2f m_position;
    TerrainIntrinsic &m_terrainIntrinsic;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   public:
    TerrainExtrinsic(TerrainIntrinsic &terrainIntrinsic);
    void setPosition(sf::Vector2f position);
    void setTerrainIntrinsic(TerrainIntrinsic &terrainIntrinsic);
};
}  // namespace GPV

#endif
