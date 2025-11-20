#ifndef OBSERVER_PATTERN_DEMO_HPP
#define OBSERVER_PATTERN_DEMO_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

#include "Application/Application.hpp"
#include "Clicker.hpp"
#include "ClickerUI.hpp"
#include "Components/Button/Button.hpp"
#include "States/MenuState.hpp"

namespace GPV
{
class ObserverPatternDemo : public ApplicationState
{
    Clicker m_clicker;
    ClickerUI m_clickerUI;
    Components::Button m_backMenuButton;

   public:
    explicit ObserverPatternDemo(const Context &context);
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
};
}  // namespace GPV

#endif