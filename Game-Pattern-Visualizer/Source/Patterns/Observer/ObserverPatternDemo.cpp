#include "ObserverPatternDemo.hpp"

namespace GPV
{
ObserverPatternDemo::ObserverPatternDemo(const Context &context)
    : ApplicationState(context), m_clicker(context), m_scoreBoard(context)
{
    m_clicker.clickSubject().addObserver(&m_scoreBoard);
}
void ObserverPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event)
{
    m_clicker.handleEvent(application.getWindow(), event);
}
void ObserverPatternDemo::update(Application &application, sf::Time delta)
{
    m_clicker.update(delta);
}
void ObserverPatternDemo::render(sf::RenderWindow &window)
{
    window.draw(m_clicker);
    window.draw(m_scoreBoard);
}
} // namespace GPV