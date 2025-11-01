#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <vector>

#include "Components/TextBox/TextBox.hpp"
#include "Observer.hpp"
#include "iostream"

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

}  // namespace GPV

#endif