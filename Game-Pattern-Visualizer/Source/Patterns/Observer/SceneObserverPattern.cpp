/**
 * @ Author: Foldear
 * @ Filename: SceneObserverPattern.cpp
 * @ Modified time: 2025-10-20 11:06:05
 * @ Description:
 */

#include "SceneObserverPattern.hpp"

namespace GPV
{
SceneObserverPattern::SceneObserverPattern(const Context &context) : m_clicker(context)
{
    m_clicker.clickSubject().addObserver(&m_scoreBoard);
}
void SceneObserverPattern::update(Application &application, sf::Time delta)
{
    m_clicker.update(delta);
}
void SceneObserverPattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_clicker, states);
}
} // namespace GPV