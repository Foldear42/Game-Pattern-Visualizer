#ifndef CLICKER_CPP
#define CLICKER_CPP

#include "Clicker.hpp"

namespace GPV
{
Clicker::Clicker(const Context &context)
    : m_button(
          Components::Button({2.f, 2.f}, "", context.textureManager.get(TextureID::cookie), context.fontManager.get(FontID::Arial), sf::Color::Red)),
      m_notifyText(context.fontManager.get(FontID::Arial))
{
    m_notifyText.setString("notify()");
    float windowX = context.window.getSize().x / 2;
    float windowY = context.window.getSize().y / 2;
    m_button.setPosition({windowX, windowY});
    m_button.setOrigin(m_button.getSizeSprite().getCenter());
    m_button.setScale({2, 2});
}

void Clicker::update(sf::Time delta)
{
    sf::Time elapsedTime;
    elapsedTime += delta;
    int opac = 255;
    if (elapsedTime >= std::chrono::seconds(1))
    {
        m_notifyText.setFillColor(sf::Color(255, 255, 255, 255));
    }
}

void Clicker::handleEvent(const sf::RenderWindow &window, const std::optional<sf::Event> &event)
{
    m_button.getButtonStatus(window, event);
    if (m_button.isPressed)
    {
        m_clickSubject.notify();
    }
}

void Clicker::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_button, states);
    target.draw(m_notifyText, states);
}

}  // namespace GPV

#endif