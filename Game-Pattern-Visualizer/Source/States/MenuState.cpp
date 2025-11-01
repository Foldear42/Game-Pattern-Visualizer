#include "MenuState.hpp"

namespace GPV
{

MenuState::MenuState(const Context &context)
    : ApplicationState(context),
      m_buttons{{
          Components::Button({1.f, 1.f}, "Pattern Command", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red),
          Components::Button({1.f, 1.f}, "Pattern Flyweight", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red),
          Components::Button({1.f, 1.f}, "Pattern Observer", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red),
          Components::Button({1.f, 1.f}, "Pattern Prototype", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red),
          Components::Button({1.f, 1.f}, "Pattern Singleton", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red),
          Components::Button({1.f, 1.f}, "Pattern State", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red),
      }}
{
}

void MenuState::handleEvent(Application &application, const std::optional<sf::Event> &event)
{
    for (Components::Button &b : m_buttons)
    {
        b.getButtonStatus(application.getWindow(), event);
        if (b.isPressed)
        {
            if (b.getTextContent() == "Pattern Command")
            {
                application.changeState(std::make_unique<CommandPatternDemo>(m_context));
            }
            else if (b.getTextContent() == "Pattern Flyweight")
            {
                application.changeState(std::make_unique<FlyweightPatternDemo>(m_context));
            }
            else if (b.getTextContent() == "Pattern Observer")
            {
                application.changeState(std::make_unique<ObserverPatternDemo>(m_context));
            }
            else if (b.getTextContent() == "Pattern Prototype")
            {
                application.changeState(std::make_unique<PrototypePatternDemo>(m_context));
            }
        }
    }
}

void MenuState::update(Application &application, sf::Time delta)
{
    for (Components::Button &b : m_buttons)
    {
        b.update(delta);
    }
}

void MenuState::dispatchButtons(const sf::RenderWindow &window)
{
    float spacingSize = 60.f;
    sf::Vector2f currentPosition = {400.f, 100.f};
    sf::Vector2u windowSize = window.getSize();
    float windowMiddleWitdh = windowSize.x / 2.f;
    for (Components::Button &b : m_buttons)
    {
        b.setOrigin(b.getSizeSprite().getCenter());
        b.setPosition({windowMiddleWitdh, currentPosition.y});
        currentPosition.y += b.getSizeSprite().size.y + spacingSize;
    }
}

void MenuState::render(sf::RenderWindow &window)
{
    this->dispatchButtons(window);
    for (Components::Button &b : m_buttons)
    {
        window.draw(b);
    }
}

}  // namespace GPV