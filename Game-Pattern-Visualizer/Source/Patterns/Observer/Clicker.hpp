/**
 * @ Author: Foldear
 * @ Filename: Clicker.hpp
 * @ Modified time: 2025-10-17 10:10:36
 * @ Description:
 */

#ifndef CLICKER_HPP
#define CLICKER_HPP

#include "Components/Button/Button.hpp"
#include "Subject.hpp"
#include <SFML/Graphics.hpp>

namespace GPV
{

class Clicker : public sf::Drawable, public sf::Transformable
{
    Subject m_clickSubject;
    Components::Button m_button;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Clicker(const Context &context);
    Subject &clickSubject()
    {
        return m_clickSubject;
    }
};

} // namespace GPV

#endif