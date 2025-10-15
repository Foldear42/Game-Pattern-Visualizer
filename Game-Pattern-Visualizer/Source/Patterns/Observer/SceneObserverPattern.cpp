/**
 * @ Author: Foldear
 * @ Filename: SceneObserverPattern.cpp
 * @ Modified time: 2025-10-11 09:55:14
 * @ Description:
 */

#include "SceneObserverPattern.hpp"

namespace GPV
{
SceneObserverPattern::SceneObserverPattern(const TextureManager &textureManager) : textureManager(textureManager) {}
void SceneObserverPattern::update(Application &application, sf::Time delta) {}
void SceneObserverPattern::draw(sf::RenderTarget &target, sf::RenderStates states) const {}
} // namespace GPV