/**
 * @ Author: Foldear
 * @ Filename: DialogBox.hpp
 * @ Modified time: 2025-05-26 16:27:20
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
    const sf::Font &font;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void animatingMachineType(sf::String s, sf::Time delta);

  public:
    DialogBox();
    DialogBox(std::vector<sf::String> listText, const sf::Font &font);
    void update(sf::Time delta);
    sf::Vector2f getSizeRectangle() const;
};

} // namespace GPV::Components

#endif