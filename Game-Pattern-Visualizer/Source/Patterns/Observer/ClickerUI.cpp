#include "ClickerUI.hpp"

namespace GPV
{

ClickerUI::ClickerUI(const Context& context)
    : m_textBox("", context.textureManager.get(TextureID::wideButtonBackground), context.fontManager.get(FontID::Arial)),
      m_buttonUpgradeCPC(Components::Button({0.5f, 0.5f}, "Upgrade CPC", context.textureManager.get(TextureID::wideButtonBackground),
                                            context.fontManager.get(FontID::Arial), sf::Color::Red)),
      m_buttonUpgradeCPS(Components::Button({0.5f, 0.5f}, "Upgrade CPS", context.textureManager.get(TextureID::wideButtonBackground),
                                            context.fontManager.get(FontID::Arial), sf::Color::Red)),
      m_elapsedTime(std::chrono::seconds(0))
{
    // Set position
    m_textBox.setPosition({200.f, 200.f});
    m_buttonUpgradeCPS.setPosition({200.f, 400.f});
    m_buttonUpgradeCPC.setPosition({200.f, 600.f});
}

void ClickerUI::onNotify()
{
    m_totalMoney += m_cookiePerClick;
}

void ClickerUI::handleEvent(const sf::RenderWindow& window, const std::optional<sf::Event>& event)
{
    m_buttonUpgradeCPC.getButtonStatus(window, event);
    if (m_buttonUpgradeCPC.isPressed)
    {
        m_cookiePerClick += 1;
    }
    m_buttonUpgradeCPS.getButtonStatus(window, event);
    if (m_buttonUpgradeCPS.isPressed)
    {
        m_cookiePerSecond += 1;
    }
}

void ClickerUI::update(sf::Time delta)
{
    m_buttonUpgradeCPC.update(delta);
    m_buttonUpgradeCPS.update(delta);
    m_elapsedTime += delta;

    if ((m_cookiePerSecond >= 1) && (m_elapsedTime >= std::chrono::seconds(1)))
    {
        m_totalMoney += m_cookiePerSecond;
        m_elapsedTime = sf::Time::Zero;
    }

    m_textBox.updateString("Money : " + std::to_string(m_totalMoney) + "\n" + "CPS : " + std::to_string(m_cookiePerSecond) + "\n" +
                           "CPC : " + std::to_string(m_cookiePerClick) + "\n");
}

void ClickerUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_textBox, states);
    target.draw(m_buttonUpgradeCPC, states);
    target.draw(m_buttonUpgradeCPS, states);
}
}  // namespace GPV