/**
 * @ Author: Foldear
 * @ Filename: Button.cpp
 * @ Modified time: 2025-06-03 10:28:43
 * @ Description: Implementation of the Button class
 */

#include "Button.hpp"

namespace GPV::Components
{

Button::Button() : m_text(m_font) {}

Button::Button(sf::Vector2f sizeRectangle, sf::String textContent, const sf::Font &font, sf::Color color, State stateType)
    : m_sizeRectangle(sizeRectangle)
    , m_textContent(textContent)
    , m_color(color)
    , m_text(font)
    , stateType(stateType)
    , m_activated(true)
{
    this->m_rectangle.setSize({m_sizeRectangle});
    this->m_rectangle.setFillColor(m_color);
    this->m_text.setFont(font);
    this->m_text.setCharacterSize(20);
    this->m_text.setString(m_textContent);
    this->m_text.setFillColor(sf::Color::White);
}

void Button::update(sf::Time delta)
{
    if (m_activated)
    {
        if (isHover == true)
        {
            m_rectangle.setFillColor(sf::Color::Green);
        }
        else
        {
            m_rectangle.setFillColor(this->m_color);
        }
    }
    else
    {
        m_rectangle.setFillColor(sf::Color(255, 255, 255, 128));
    }
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
    if (m_activated)
    {
        if (bounds.contains(mousePosView))
        {
            this->isHover = true;
            if (event->getIf<sf::Event::MouseButtonPressed>())
            {
                this->isPressed = true;
            }
        }
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

void Button::activate()
{
    m_activated = true;
}

void Button::deactivate()
{
    m_activated = false;
}

} // namespace GPV::Components