/**
 * @ Author: Foldear
 * @ Filename: MenuState.cpp
 * @ Modified time: 2025-07-06 10:23:38
 * @ Description: Implementation for the main menu
 */

#include "MenuState.hpp"

namespace GPV
{

MenuState::MenuState()
{
    sf::Vector2f buttonSize = {500.f, 50.f};
    m_font.openFromFile("Resources/Fonts/ARIAL.ttf");
    Components::Button buttonPatternCommand(buttonSize, "Pattern Command", m_font, sf::Color::Red, State::COMMAND_P_STATE);
    Components::Button buttonPatternFlyweight(buttonSize, "Pattern Flyweight", m_font, sf::Color::Red, State::FLYWEIGHT_P_STATE);
    Components::Button buttonPatternObserver(buttonSize, "Pattern Observer", m_font, sf::Color::Red, State::OBSERVER_P_STATE);
    Components::Button buttonPatternPrototype(buttonSize, "Pattern Prototype", m_font, sf::Color::Red, State::PROTOTYPE_P_STATE);
    Components::Button buttonPatternSingleton(buttonSize, "Pattern Singleton", m_font, sf::Color::Red, State::SINGLETON_P_STATE);
    Components::Button buttonPatternState(buttonSize, "Pattern State", m_font, sf::Color::Red, State::STATE_P_STATE);

    push(buttonPatternCommand);
    push(buttonPatternFlyweight);
    push(buttonPatternObserver);
    push(buttonPatternPrototype);
    push(buttonPatternSingleton);
    push(buttonPatternState);
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
                application.changeState(std::make_unique<CommandPatternDemo>());
                break;
            case State::FLYWEIGHT_P_STATE:
                application.changeState(std::make_unique<FlyweightPatternDemo>());
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
        b.setOrigin({b.getSizeRectangle().x / 2, b.getSizeRectangle().y / 2});
        b.setPosition({windowMiddleWitdh, currentPosition.y});
        currentPosition.y += b.getSizeRectangle().y + spacingSize;
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

void MenuState::push(const Components::Button &button)
{
    m_buttons.push_back(button);
}

} // namespace GPV