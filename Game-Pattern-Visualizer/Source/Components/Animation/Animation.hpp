/**
 * @ Author: Foldear
 * @ Filename: Animation.hpp
 * @ Modified time: 2025-05-29 13:28:14
 * @ Description: Component to animate an image
 */

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>

namespace GPV::Components
{

class Animation : public sf::Drawable
{
    const int m_numFrames;
    const sf::Time m_frameTime;
    std::optional<sf::Sprite> m_sprite;
    sf::Time m_elaspedTime;
    std::vector<sf::IntRect> m_sourceRectangles;
    sf::Time m_frameTimeLeft;
    int m_currentFrameIndex;
    bool m_active = true;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Animation(std::optional<sf::Sprite> sprite, int framesX, int framesY, sf::Time frameTime, int row = 1);
    void update(sf::Time delta);
    void start();
    void stop();
    void reset();
};

} // namespace GPV::Components

#endif