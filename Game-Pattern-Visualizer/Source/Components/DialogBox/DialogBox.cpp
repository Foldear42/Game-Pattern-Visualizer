/**
 * @ Author: Foldear
 * @ Filename: DialogBox.cpp
 * @ Modified time: 2025-05-26 16:27:47
 * @ Description: Implementation of the DialogBox class
 */

#include "DialogBox.hpp"

namespace GPV::Components
{

DialogBox::DialogBox() : font(font), m_currentText(font), m_elapsedTime(std::chrono::milliseconds(0)) {}

DialogBox::DialogBox(std::vector<sf::String> listText, const sf::Font &font)
    : m_listText(listText), font(font), m_currentText(font), m_elapsedTime(std::chrono::milliseconds(0))
{
    this->m_box.setSize({1000.f, 150.f});
    this->m_box.setFillColor(sf::Color::Blue);
    this->m_box.setOutlineColor(sf::Color::Red);
    this->m_currentText.setCharacterSize(24);
}

void DialogBox::animatingMachineType(sf::String s, sf::Time delta)
{
    m_elapsedTime += delta;

    // std::cout << m_elapsedTime.asMilliseconds() << std::endl;
    if (m_elapsedTime >= std::chrono::milliseconds(50))
    {

        m_elapsedTime = sf::Time::Zero;
    }
}

void DialogBox::update(sf::Time delta)
{
    for (sf::String &s : this->m_listText)
    {
        animatingMachineType(s, delta);
    }
}

void DialogBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    // target.clear();
    target.draw(this->m_box, states);
    target.draw(this->m_currentText, states);
}

sf::Vector2f DialogBox::getSizeRectangle() const
{
    return this->m_box.getSize();
}

} // namespace GPV::Components