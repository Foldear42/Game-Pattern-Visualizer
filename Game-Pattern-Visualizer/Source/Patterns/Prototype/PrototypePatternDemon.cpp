/**
 * @ Author: Foldear
 * @ Filename: PrototypePatternDemo.cpp
 * @ Modified time: 2025-10-22 09:13:46
 * @ Description:
 */

#include "PrototypePatternDemo.hpp"

namespace GPV
{
PrototypePatternDemo::PrototypePatternDemo(const Context &context) : ApplicationState(context)
{
    std::cout << "Prototype" << std::endl;
}
void PrototypePatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event) {}
void PrototypePatternDemo::update(Application &application, sf::Time delta) {}
void PrototypePatternDemo::render(sf::RenderWindow &window) {}
} // namespace GPV