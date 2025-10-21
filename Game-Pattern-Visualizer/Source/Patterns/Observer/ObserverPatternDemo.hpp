/**
 * @ Author: Foldear
 * @ Filename: ObserverPatternDemo.hpp
 * @ Modified time: 2025-10-21 09:14:17
 * @ Description:
 */

#ifndef OBSERVER_PATTERN_DEMO_HPP
#define OBSERVER_PATTERN_DEMO_HPP

#include "Application/Application.hpp"
#include "Clicker.hpp"
#include "ScoreBoard.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

namespace GPV
{
class ObserverPatternDemo : public ApplicationState
{
    Clicker m_clicker;
    ScoreBoard m_scoreBoard;

  public:
    explicit ObserverPatternDemo(const Context &context);
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
};
} // namespace GPV

#endif