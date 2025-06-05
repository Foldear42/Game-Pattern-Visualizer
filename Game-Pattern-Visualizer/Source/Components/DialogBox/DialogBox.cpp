/**
 * @ Author: Foldear
 * @ Filename: DialogBox.cpp
 * @ Modified time: 2025-06-05 09:53:32
 * @ Description: Implementation of the DialogBox class
 */

#include "DialogBox.hpp"

namespace GPV::Components
{

DialogBox::DialogBox() : font(font), m_currentText(font), m_elapsedTime(std::chrono::milliseconds(0)) {}

DialogBox::DialogBox(std::vector<sf::String> listText, const sf::Font &font)
    : m_listText(listText), font(font), m_currentText(font), m_elapsedTime(std::chrono::milliseconds(0))
{
    m_box.setSize({1000.f, 150.f});
    m_box.setFillColor(sf::Color::Blue);
    m_box.setOutlineColor(sf::Color::Red);
    m_currentText.setCharacterSize(24);
}

bool DialogBox::typewriterAnimation(sf::String s, sf::Time delta)
{
    bool isFinished = false;
    if (s.getSize() >= m_charIndex)
    {
        m_elapsedTime += delta;
        if (m_elapsedTime >= std::chrono::milliseconds(50))
        {
            ++m_charIndex;
            m_currentText.setString(s.substring(0, m_charIndex));
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

    bool isFinished = typewriterAnimation(m_listText[m_currentTextIndex], delta);
    m_lengthListText = m_listText.size();
    // We continue until there are no strings lefy to animate
    if (isFinished && (m_currentTextIndex < (m_lengthListText - 1)))
    {
        m_charIndex = 0;
        m_currentTextIndex++;
    }
    // When all the strings are animated we reset indexes
    if (m_currentTextIndex == m_lengthListText)
    {
        resetIndexes();
    }
}

void DialogBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_box, states);
    target.draw(m_currentText, states);
}

sf::Vector2f DialogBox::getSizeRectangle() const
{
    return m_box.getSize();
}

void DialogBox::setListText(const std::vector<sf::String> listText)
{
    m_listText = listText;
}

void DialogBox::resetIndexes()
{
    m_charIndex = 0;
    m_currentTextIndex = 0;
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