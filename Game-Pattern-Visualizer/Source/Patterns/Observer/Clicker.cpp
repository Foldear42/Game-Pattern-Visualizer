#ifndef CLICKER_CPP
#define CLICKER_CPP

#include "Clicker.hpp"

namespace GPV
{
Clicker::Clicker(const Context &context)
    : m_button(Components::Button({2.f, 2.f}, "", context.textureManager.get(TextureID::cookie),
                                  context.fontManager.get(FontID::Arial), sf::Color::Red))
{
}

void Clicker::update(sf::Time delta) {}

void Clicker::handleEvent(const sf::RenderWindow &window, const std::optional<sf::Event> &event)
{
    m_button.getButtonStatus(window, event);
    if (m_button.isPressed)
    {
        m_clickSubject.notify();
    }
}

void Clicker::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_button, states);
}

} // namespace GPV

#endif