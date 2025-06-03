/**
 * @ Author: Foldear
 * @ Filename: DialogBox.cpp
 * @ Modified time: 2025-06-03 09:48:22
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
    if (!m_typewriterActive)
    {
        return;
    }

    bool isFinished = typewriterAnimation(this->m_listText[this->m_currentTextIndex], delta);
    this->m_lengthListText = this->m_listText.size();
    // We continue until there are no strings lefy to animate
    if (isFinished && (this->m_currentTextIndex < (this->m_lengthListText - 1)))
    {
        this->m_charIndex = 0;
        this->m_currentTextIndex++;
    }
    // When all the strings are animated we reset indexes
    if (this->m_currentTextIndex == this->m_lengthListText)
    {
        this->resetIndexes();
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

void DialogBox::setListText(const std::vector<sf::String> listText)
{
    this->m_listText = listText;
}

void DialogBox::resetIndexes()
{
    this->m_charIndex = 0;
    this->m_currentTextIndex = 0;
}

void DialogBox::startTypewriterAnimation()
{
    m_typewriterActive = true;
}

void DialogBox::stopTypewriterAnimation()
{
    m_typewriterActive = false;
}

} // namespace GPV::Components