#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <memory>

#include "Application/Application.hpp"
#include "Components/Button/Button.hpp"
#include "Interfaces/ApplicationState.hpp"
#include "Patterns/Command/CommandPatternDemo.hpp"
#include "Patterns/Flyweight/FlyweightPatternDemo.hpp"
#include "Patterns/Observer/ObserverPatternDemo.hpp"
#include "Patterns/Prototype/PrototypePatternDemo.hpp"

namespace GPV
{

class MenuState : public ApplicationState
{
    std::array<Components::Button, 6> m_buttons;
    sf::Font m_font;

   public:
    explicit MenuState(const Context &context);
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
    void dispatchButtons(const sf::RenderWindow &window);
};

}  // namespace GPV

#endif