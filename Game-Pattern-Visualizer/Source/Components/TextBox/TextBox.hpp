#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Application/Application.hpp"

namespace GPV::Components
{

class TextBox : public sf::Drawable, public sf::Transformable
{
    const sf::Font &font;
    sf::Sprite m_sprite;
    sf::String m_textContent;
    sf::Text m_graphicalText;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   public:
    TextBox(sf::String textContent, sf::Texture &texture, const sf::Font &font);
    void update(sf::Time delta);
    void updateString(sf::String newString);
    sf::FloatRect getSizeSprite() const;
};

}  // namespace GPV::Components

#endif