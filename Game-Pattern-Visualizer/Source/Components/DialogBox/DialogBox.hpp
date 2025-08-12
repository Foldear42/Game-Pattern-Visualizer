/**
 * @ Author: Foldear
 * @ Filename: DialogBox.hpp
 * @ Modified time: 2025-07-09 20:41:47
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
    std::vector<std::string> m_listText;
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
    bool typewriterAnimation(std::string s, sf::Time delta);

  public:
    DialogBox(std::vector<std::string> listText, const sf::Font &font);
    void update(sf::Time delta);
    sf::Vector2f getSizeRectangle() const;
    void setListText(const std::vector<std::string> listText);
    void resetIndexes();
    void startTypewriterAnimation();
    void stopTypewriterAnimation();
};

} // namespace GPV::Components

#endif