/**
 * @ Author: Foldear
 * @ Filename: DialogBox.hpp
 * @ Modified time: 2025-06-03 09:47:33
 * @ Description: DialogBox Component
 */

#ifndef DIALOG_BOX_HPP
#define DIALOG_BOX_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

namespace GPV::Components
{

class DialogBox : public sf::Drawable, public sf::Transformable
{
    std::vector<sf::String> m_listText;
    sf::RectangleShape m_box;
    sf::Text m_currentText;
    sf::Time m_elapsedTime;
    bool m_typewriterActive;
    bool m_isTypewriterAnimationFinished = false;
    int m_currentTextIndex = 0;
    int m_charIndex = 0;
    int m_lengthListText = 0;
    const sf::Font &font;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    bool typewriterAnimation(sf::String s, sf::Time delta);

  public:
    DialogBox();
    DialogBox(std::vector<sf::String> listText, const sf::Font &font);
    void update(sf::Time delta);
    sf::Vector2f getSizeRectangle() const;
    void setListText(const std::vector<sf::String> listText);
    void resetIndexes();
    void startTypewriterAnimation();
    void stopTypewriterAnimation();
};

} // namespace GPV::Components

#endif