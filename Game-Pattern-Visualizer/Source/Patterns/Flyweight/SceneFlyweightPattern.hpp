/**
 * @ Author: Foldear
 * @ Filename: SceneFlyweightPattern.hpp
 * @ Modified time: 2025-07-06 10:31:31
 * @ Description:
 */

#ifndef SCENE_FLYWIEGHT_PATTERN_HPP
#define SCENE_FLYWIEGHT_PATTERN_HPP

#include "Application/Application.hpp"
#include "Interfaces/Scene.hpp"

namespace GPV
{
class SceneFlyweightPattern : public Scene
{
    sf::RectangleShape m_rectShape;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    SceneFlyweightPattern();
    void update(Application &application, sf::Time delta) override;
};
} // namespace GPV

#endif