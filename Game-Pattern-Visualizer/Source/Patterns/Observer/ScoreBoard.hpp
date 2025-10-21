/**
 * @ Author: Foldear
 * @ Filename: ScoreBoard.hpp
 * @ Modified time: 2025-10-21 10:30:44
 * @ Description:
 */

#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include "Components/TextBox/TextBox.hpp"
#include "Observer.hpp"
#include "iostream"
#include <vector>

namespace GPV
{

class ScoreBoard : public sf::Drawable, public Observer
{
    Components::TextBox m_textBox;
    int m_totalScore = 0;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    ScoreBoard(const Context &context);
    void onNotify();
};

} // namespace GPV

#endif