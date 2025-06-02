/**
 * @ Author: Foldear
 * @ Filename: Animation.hpp
 * @ Modified time: 2025-06-02 15:20:58
 * @ Description: Component to animate an image
 */

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

namespace GPV::Components
{

class Animation : public sf::Drawable, public sf::Transformable
{
    const int m_numFrames;
    const sf::Time m_frameTime;
    sf::Time m_frameTimeLeft;
    std::optional<sf::Sprite> m_sprite;
    sf::Time m_elaspedTime;
    int m_currentFrameIndex;
    bool m_active = true;
    sf::Vector2f m_zoomFactorVector;
    std::vector<sf::IntRect> m_sourceRectangles;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Animation(std::optional<sf::Sprite> sprite, int framesX, int framesY, sf::Time frameTime, float zoomFactor);
    void update(sf::Time delta);
    void start();
    void stop();
    void reset();
};

} // namespace GPV::Components

#endif