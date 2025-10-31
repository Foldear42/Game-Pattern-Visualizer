#include "Button.hpp"

namespace GPV::Components
{

Button::Button(sf::Vector2f spriteScale, sf::String textContent, sf::Texture &texture, const sf::Font &font, sf::Color color)
    : m_sprite(texture), m_spriteScale(spriteScale), m_textContent(textContent), m_color(color), m_text(font), m_activated(true)
{
    m_sprite.setScale(m_spriteScale);
    m_rectangle.setFillColor(m_color);
    m_text.setCharacterSize(20);
    m_text.setString(m_textContent);
    m_text.setFillColor(sf::Color::White);
}

void Button::setCommand(std::unique_ptr<Command> command)
{
    p_command = std::move(command);
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
    sf::FloatRect bounds = getTransform().transformRect(this->m_sprite.getGlobalBounds());
    isHover = false;
    isPressed = false;
    if (m_activated)
    {
        if (bounds.contains(mousePosView))
        {
            isHover = true;
            if (event->getIf<sf::Event::MouseButtonPressed>())
            {
                isPressed = true;
            }
        }
    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_sprite, states);
    // target.draw(m_rectangle, states);
    target.draw(m_text, states);
}

sf::Vector2f Button::getPosition()
{
    return sf::Transformable::getPosition();
}

const sf::String &Button::getTextContent() const
{
    return m_textContent;
}

sf::FloatRect Button::getSizeSprite() const
{
    return m_sprite.getGlobalBounds();
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