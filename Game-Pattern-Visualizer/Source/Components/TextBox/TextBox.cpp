#include "TextBox.hpp"

namespace GPV::Components
{

TextBox::TextBox(sf::String textContent, sf::Texture &texture, const sf::Font &font)
    : m_sprite(texture), font(font), m_textContent(textContent), m_graphicalText(font)
{
    m_graphicalText.setString(m_textContent);
    m_graphicalText.setCharacterSize(20);
    m_graphicalText.setFillColor(sf::Color::White);
}

void TextBox::update(sf::Time delta)
{
}

void TextBox::updateString(sf::String newString)
{
    m_graphicalText.setString(newString);
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_sprite, states);
    target.draw(m_graphicalText, states);
}

sf::FloatRect TextBox::getSizeSprite() const
{
    return m_sprite.getGlobalBounds();
}

}  // namespace GPV::Components