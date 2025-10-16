/**
 * @ Author: Foldear
 * @ Filename: Clicker.hpp
 * @ Modified time: 2025-10-16 10:00:27
 * @ Description:
 */

#ifndef CLICKER_HPP
#define CLICKER_HPP

#include "Subject.hpp"
#include <SFML/Graphics.hpp>

namespace GPV
{

class Clicker : sf::Drawable
{
    Subject m_subject;

  public:
    Clicker();
};

} // namespace GPV

#endif