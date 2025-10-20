/**
 * @ Author: Foldear
 * @ Filename: SceneObserverPattern.hpp
 * @ Modified time: 2025-10-20 10:18:28
 * @ Description:
 */

#ifndef SCENE_OBSERVER_PATTERN_HPP
#define SCENE_OBSERVER_PATTERN_HPP

#include "Application/Application.hpp"
#include "Clicker.hpp"
#include "Interfaces/Scene.hpp"
#include "ScoreBoard.hpp"
#include <iostream>

namespace GPV
{
class SceneObserverPattern : public Scene
{
    Clicker m_clicker;
    ScoreBoard m_scoreBoard;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    SceneObserverPattern(const Context &context);
    void update(Application &application, sf::Time delta) override;
};
} // namespace GPV

#endif