/**
 * @ Author: Foldear
 * @ Filename: TextBox.hpp
 * @ Modified time: 2025-10-20 10:09:04
 * @ Description: TextBox Component
 */

#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

namespace GPV::Components
{

class TextBox : public sf::Drawable, public sf::Transformable
{
    const sf::Font &font;
    sf::Sprite m_sprite;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    TextBox(sf::Texture &texture, const sf::Font &font);
    void update(sf::Time delta);
    sf::FloatRect getSizeSprite() const;
};

} // namespace GPV::Components

#endif