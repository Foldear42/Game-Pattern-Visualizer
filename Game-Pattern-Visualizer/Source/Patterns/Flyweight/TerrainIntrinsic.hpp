#ifndef TERRAIN_INTRINSIC_HPP
#define TERRAIN_INTRINSIC_HPP

#include <SFML/Graphics.hpp>

namespace GPV
{
class TerrainIntrinsic : public sf::Drawable
{
    sf::Sprite m_sprite;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   public:
    TerrainIntrinsic(const sf::Texture &texture);
    void setSpritePosition(sf::Vector2f position);
};
}  // namespace GPV

#endif