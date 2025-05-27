/**
 * @ Author: Foldear
 * @ Filename: DialogBox.cpp
 * @ Modified time: 2025-05-27 15:22:05
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

bool DialogBox::typewriterAnimation(sf::String s, sf::Time delta)
{
    bool isFinished = false;
    if (s.getSize() >= this->m_charIndex)
    {
        m_elapsedTime += delta;
        if (m_elapsedTime >= std::chrono::milliseconds(50))
        {
            ++m_charIndex;
            this->m_currentText.setString(s.substring(0, this->m_charIndex));
            m_elapsedTime = sf::Time::Zero;
        }
    }
    else
    {
        isFinished = true;
    }
    return isFinished;
}

void DialogBox::update(sf::Time delta)
{
    bool isFinished = typewriterAnimation(this->m_listText[this->m_currentTextIndex], delta);
    int lengthListText = this->m_listText.size();
    if (isFinished && (this->m_currentTextIndex < (lengthListText - 1)))
    {
        this->m_charIndex = 0;
        this->m_currentTextIndex++;
    }
}

void DialogBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(this->m_box, states);
    target.draw(this->m_currentText, states);
}

sf::Vector2f DialogBox::getSizeRectangle() const
{
    return this->m_box.getSize();
}

} // namespace GPV::Components