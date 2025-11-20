#include "ObserverPatternDemo.hpp"

namespace GPV
{
ObserverPatternDemo::ObserverPatternDemo(const Context &context)
    : ApplicationState(context),
      m_clicker(context),
      m_clickerUI(context),
      m_backMenuButton(Components::Button({0.5f, 0.5f}, "Back", context.textureManager.get(TextureID::wideButtonBackground),
                                          context.fontManager.get(FontID::Arial), sf::Color::Red))

{
    m_backMenuButton.setPosition({1700.f, 50.f});
    m_clicker.clickSubject().addObserver(&m_clickerUI);
}
void ObserverPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event)
{
    m_clicker.handleEvent(application.getWindow(), event);
    m_clickerUI.handleEvent(application.getWindow(), event);
    m_backMenuButton.getButtonStatus(application.getWindow(), event);
    if (m_backMenuButton.isPressed)
    {
        application.changeState(std::make_unique<MenuState>(m_context));
    }
}
void ObserverPatternDemo::update(Application &application, sf::Time delta)
{
    m_clicker.update(delta);
    m_clickerUI.update(delta);
    m_backMenuButton.update(delta);
}
void ObserverPatternDemo::render(sf::RenderWindow &window)
{
    window.draw(m_clicker);
    window.draw(m_clickerUI);
    window.draw(m_backMenuButton);
}
}  // namespace GPV