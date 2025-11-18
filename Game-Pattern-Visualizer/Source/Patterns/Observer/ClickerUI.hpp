#ifndef CLICKER_UI_HPP
#define CLICKER_UI_HPP

#include <vector>

#include "Components/Button/Button.hpp"
#include "Components/TextBox/TextBox.hpp"
#include "Observer.hpp"
#include "iostream"

namespace GPV
{

class ClickerUI : public sf::Drawable, public Observer
{
    Components::TextBox m_textBox;
    Components::Button m_buttonUpgradeCPC;
    Components::Button m_buttonUpgradeCPS;
    sf::Time m_elapsedTime;
    int m_totalMoney = 0;
    int m_cookiePerClick = 1;
    int m_cookiePerSecond = 0;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   public:
    ClickerUI(const Context &context);
    void onNotify();
    void handleEvent(const sf::RenderWindow &window, const std::optional<sf::Event> &event);
    void update(sf::Time delta);
};

}  // namespace GPV

#endif