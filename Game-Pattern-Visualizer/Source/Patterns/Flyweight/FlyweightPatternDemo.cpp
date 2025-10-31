#include "FlyweightPatternDemo.hpp"

namespace GPV
{
FlyweightPatternDemo::FlyweightPatternDemo(const Context &context)
    : ApplicationState(context), m_sceneFlyweightPattern(context.textureManager)
{
}
void FlyweightPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event) {}
void FlyweightPatternDemo::update(Application &application, sf::Time delta) {}
void FlyweightPatternDemo::render(sf::RenderWindow &window)
{
    window.draw(m_sceneFlyweightPattern);
}
} // namespace GPV