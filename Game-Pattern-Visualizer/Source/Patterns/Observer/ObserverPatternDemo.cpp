/**
 * @ Author: Foldear
 * @ Filename: ObserverPatternDemo.cpp
 * @ Modified time: 2025-10-11 09:48:06
 * @ Description:
 */

#include "ObserverPatternDemo.hpp"

namespace GPV
{
ObserverPatternDemo::ObserverPatternDemo(const Context &context)
    : ApplicationState(context), m_sceneObserverPattern(context.textureManager)
{
}
void ObserverPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event) {}
void ObserverPatternDemo::update(Application &application, sf::Time delta) {}
void ObserverPatternDemo::render(sf::RenderWindow &window)
{
    window.draw(m_sceneObserverPattern);
}
} // namespace GPV