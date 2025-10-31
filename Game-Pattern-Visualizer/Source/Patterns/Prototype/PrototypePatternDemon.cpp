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