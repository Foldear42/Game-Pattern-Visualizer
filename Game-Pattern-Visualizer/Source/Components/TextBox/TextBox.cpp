/**
 * @ Author: Foldear
 * @ Filename: TextBox.cpp
 * @ Modified time: 2025-10-20 10:10:00
 * @ Description: Implementation of the TextBox class
 */

#include "TextBox.hpp"

namespace GPV::Components
{

TextBox::TextBox(sf::Texture &texture, const sf::Font &font) : m_sprite(texture), font(font) {}

void TextBox::update(sf::Time delta) {}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
}

sf::FloatRect TextBox::getSizeSprite() const
{
    return m_sprite.getGlobalBounds();
}

} // namespace GPV::Components