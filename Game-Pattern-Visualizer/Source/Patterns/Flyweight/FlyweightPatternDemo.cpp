/**
 * @ Author: Foldear
 * @ Filename: FlyweightPatternDemo.cpp
 * @ Modified time: 2025-07-06 10:19:53
 * @ Description:
 */

#include "FlyweightPatternDemo.hpp"

namespace GPV
{
FlyweightPatternDemo::FlyweightPatternDemo() {}
void FlyweightPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event) {}
void FlyweightPatternDemo::update(Application &application, sf::Time delta) {}
void FlyweightPatternDemo::render(sf::RenderWindow &window)
{
    window.draw(m_sceneFlyweightPattern);
}
} // namespace GPV