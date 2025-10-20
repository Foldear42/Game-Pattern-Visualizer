/**
 * @ Author: Foldear
 * @ Filename: Clicker.cpp
 * @ Modified time: 2025-10-20 11:20:52
 * @ Description:
 */

#ifndef CLICKER_CPP
#define CLICKER_CPP

#include "Clicker.hpp"

namespace GPV
{
Clicker::Clicker(const Context &context)
    : m_button(Components::Button({2.f, 2.f}, "", context.textureManager.get(TextureID::cookie),
                                  context.fontManager.get(FontID::Arial), sf::Color::Red, State::STATE_YES))
{
}

void Clicker::update(sf::Time delta)
{
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