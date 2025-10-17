/**
 * @ Author: Foldear
 * @ Filename: Clicker.cpp
 * @ Modified time: 2025-10-17 11:36:02
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

void Clicker::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_button, states);
}

} // namespace GPV

#endif