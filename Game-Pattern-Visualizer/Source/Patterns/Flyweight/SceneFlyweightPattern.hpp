/**
 * @ Author: Foldear
 * @ Filename: SceneFlyweightPattern.hpp
 * @ Modified time: 2025-07-09 14:16:48
 * @ Description:
 */

#ifndef SCENE_FLYWIEGHT_PATTERN_HPP
#define SCENE_FLYWIEGHT_PATTERN_HPP

#include "Application/Application.hpp"
#include "Interfaces/Scene.hpp"
#include <iostream>

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