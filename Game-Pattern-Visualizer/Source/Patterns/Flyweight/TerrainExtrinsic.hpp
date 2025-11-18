#ifndef TERRAIN_EXTRINSIC_HPP
#define TERRAIN_EXTRINSIC_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

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
    const std::string getInfos() const;
    sf::FloatRect m_bounds;
};
}  // namespace GPV

#endif
