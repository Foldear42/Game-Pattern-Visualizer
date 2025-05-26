/**
 * @ Author: Foldear
 * @ Filename: MenuState.hpp
 * @ Modified time: 2025-05-26 09:57:51
 * @ Description: Main menu for navigation
 */

#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "Components/Button/Button.hpp"
#include "Interfaces/ApplicationState.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

namespace GPV
{

class MenuState : public ApplicationState
{
    std::vector<Components::Button> m_buttons;
    sf::Font m_font;

  public:
    MenuState();
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
    void dispatchButtons(const sf::RenderWindow &window);
    void push(const Components::Button &button);
    void pop();
};

} // namespace GPV

#endif