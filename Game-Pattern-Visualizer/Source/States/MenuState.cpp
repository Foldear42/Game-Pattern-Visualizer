/**
 * @ Author: Foldear
 * @ Filename: MenuState.cpp
 * @ Modified time: 2025-10-22 09:14:03
 * @ Description: Implementation for the main menu
 */

#include "MenuState.hpp"

namespace GPV
{

MenuState::MenuState(const Context &context)
    : ApplicationState(context)
    , m_buttons{{
          Components::Button({1.f, 1.f}, "Pattern Command", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red, State::COMMAND_P_STATE),
          Components::Button({1.f, 1.f}, "Pattern Flyweight", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red, State::FLYWEIGHT_P_STATE),
          Components::Button({1.f, 1.f}, "Pattern Observer", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red, State::OBSERVER_P_STATE),
          Components::Button({1.f, 1.f}, "Pattern Prototype", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red, State::PROTOTYPE_P_STATE),
          Components::Button({1.f, 1.f}, "Pattern Singleton", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red, State::SINGLETON_P_STATE),
          Components::Button({1.f, 1.f}, "Pattern State", context.textureManager.get(TextureID::wideButtonBackground),
                             context.fontManager.get(FontID::Arial), sf::Color::Red, State::STATE_P_STATE),
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
            switch (b.stateType)
            {
            case State::COMMAND_P_STATE:
                application.changeState(std::make_unique<CommandPatternDemo>(m_context));
                break;
            case State::FLYWEIGHT_P_STATE:
                application.changeState(std::make_unique<FlyweightPatternDemo>(m_context));
                break;
            case State::OBSERVER_P_STATE:
                application.changeState(std::make_unique<ObserverPatternDemo>(m_context));
                break;
            case State::PROTOTYPE_P_STATE:
                application.changeState(std::make_unique<PrototypePatternDemo>(m_context));
                break;
            default:
                break;
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

} // namespace GPV