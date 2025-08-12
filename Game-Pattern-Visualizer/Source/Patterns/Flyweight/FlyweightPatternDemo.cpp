/**
 * @ Author: Foldear
 * @ Filename: FlyweightPatternDemo.cpp
 * @ Modified time: 2025-07-09 17:31:10
 * @ Description:
 */

#include "FlyweightPatternDemo.hpp"

namespace GPV
{
FlyweightPatternDemo::FlyweightPatternDemo(const Context &context) : ApplicationState(context) {}
void FlyweightPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event) {}
void FlyweightPatternDemo::update(Application &application, sf::Time delta) {}
void FlyweightPatternDemo::render(sf::RenderWindow &window)
{
    window.draw(m_sceneFlyweightPattern);
}
} // namespace GPV