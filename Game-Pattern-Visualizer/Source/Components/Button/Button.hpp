#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Application/Application.hpp"
#include "Enums/State.hpp"
#include "Patterns/Command/Command.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace GPV::Components
{

class Button : public sf::Drawable, public sf::Transformable
{
    sf::Sprite m_sprite;
    sf::Vector2f m_spriteScale;
    sf::String m_textContent;
    sf::Color m_color;
    sf::RectangleShape m_rectangle;
    sf::Text m_text;
    sf::Vector2f m_position;
    sf::Font m_font;
    std::unique_ptr<Command> p_command;
    bool m_activated;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Button(sf::Vector2f spriteScale, sf::String textContent, sf::Texture &texture, const sf::Font &font, sf::Color color);
    void getButtonStatus(const sf::RenderWindow &window, const std::optional<sf::Event> &e);
    void update(sf::Time delta);
    void setColor(sf::Color color);
    void setCommand(std::unique_ptr<Command> command);
    sf::Vector2f getPosition();
    sf::FloatRect getSizeSprite() const;
    const sf::String &getTextContent() const;
    void activate();
    void deactivate();
    bool isHover = false;
    bool isPressed = false;
};

} // namespace GPV::Components
#endif