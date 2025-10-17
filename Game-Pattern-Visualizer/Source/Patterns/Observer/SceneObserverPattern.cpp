/**
 * @ Author: Foldear
 * @ Filename: SceneObserverPattern.cpp
 * @ Modified time: 2025-10-17 10:05:59
 * @ Description:
 */

#include "SceneObserverPattern.hpp"

namespace GPV
{
SceneObserverPattern::SceneObserverPattern(const Context &context) : m_clicker(context) {}
void SceneObserverPattern::update(Application &application, sf::Time delta) {}
void SceneObserverPattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_clicker, states);
}
} // namespace GPV