/**
 * @ Author: Foldear
 * @ Filename: Button.hpp
 * @ Modified time: 2025-06-03 10:10:14
 * @ Description: Button Component
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Enums/State.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace GPV::Components
{

class Button : public sf::Drawable, public sf::Transformable
{
    sf::Vector2f m_sizeRectangle;
    sf::String m_textContent;
    sf::Color m_color;
    sf::RectangleShape m_rectangle;
    sf::Text m_text;
    sf::Vector2f m_position;
    sf::Font m_font;
    bool m_activated;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Button();
    Button(sf::Vector2f sizeRectangle, sf::String textContent, const sf::Font &font, sf::Color color, State stateType);
    void getButtonStatus(const sf::RenderWindow &window, const std::optional<sf::Event> &e);
    void update(sf::Time delta);
    void setColor(sf::Color color);
    sf::Vector2f getPosition();
    sf::Vector2f getSizeRectangle() const;
    sf::String getTextContent();
    void activate();
    void deactivate();
    bool isHover = false;
    bool isPressed = false;
    // TODO: instead of using state type, bind a command to each new button
    State stateType;
};

} // namespace GPV::Components
#endif