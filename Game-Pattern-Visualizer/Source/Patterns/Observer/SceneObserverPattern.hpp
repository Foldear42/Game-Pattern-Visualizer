/**
 * @ Author: Foldear
 * @ Filename: SceneObserverPattern.hpp
 * @ Modified time: 2025-10-15 09:33:52
 * @ Description:
 */

#ifndef SCENE_OBSERVER_PATTERN_HPP
#define SCENE_OBSERVER_PATTERN_HPP

#include "Application/Application.hpp"
#include "Interfaces/Scene.hpp"
#include <iostream>

namespace GPV
{
class SceneObserverPattern : public Scene
{
    const TextureManager &textureManager;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    SceneObserverPattern(const TextureManager &textureManager);
    void update(Application &application, sf::Time delta) override;
};
} // namespace GPV

#endif