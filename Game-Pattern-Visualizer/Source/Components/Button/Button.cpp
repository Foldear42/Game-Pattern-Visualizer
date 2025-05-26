/**
 * @ Author: Foldear
 * @ Filename: Button.cpp
 * @ Modified time: 2025-05-26 16:26:33
 * @ Description: Implementation of the Button class
 */

#include "Button.hpp"

namespace GPV::Components
{

Button::Button() : m_text(m_font) {}

Button::Button(sf::Vector2f sizeRectangle, sf::String textContent, const sf::Font &font, sf::Color color, State stateType)
    : m_sizeRectangle(sizeRectangle), m_textContent(textContent), m_color(color), m_text(font), stateType(stateType)
{
    this->m_rectangle.setSize({m_sizeRectangle});
    this->m_rectangle.setFillColor(m_color);
    this->m_text.setFont(font);
    this->m_text.setCharacterSize(20);
    this->m_text.setString(m_textContent);
    this->m_text.setFillColor(sf::Color::White);
}

void Button::getButtonStatus(const sf::RenderWindow &window, const std::optional<sf::Event> &event)
{
    // relative to the window
    sf::Vector2i mouseLocalPosition = sf::Mouse::getPosition(window);
    // relative to the "world"
    sf::Vector2f mousePosView = window.mapPixelToCoords(mouseLocalPosition);
    // apply the transformation
    sf::FloatRect bounds = getTransform().transformRect(this->m_rectangle.getGlobalBounds());
    this->isHover = false;
    this->isPressed = false;
    if (bounds.contains(mousePosView))
    {
        this->isHover = true;
        if (event->getIf<sf::Event::MouseButtonPressed>())
        {
            this->isPressed = true;
        }
    }

    if (this->isHover == true)
    {
        this->m_rectangle.setFillColor(sf::Color::Green);
    }
    else
    {
        this->m_rectangle.setFillColor(this->m_color);
    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_rectangle, states);
    target.draw(m_text, states);
}

sf::Vector2f Button::getPosition()
{
    return sf::Transformable::getPosition();
}

sf::String Button::getTextContent()
{
    return this->m_textContent;
}

sf::Vector2f Button::getSizeRectangle() const
{
    return this->m_sizeRectangle;
}

}