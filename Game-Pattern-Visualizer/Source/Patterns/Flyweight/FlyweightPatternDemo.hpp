/**
 * @ Author: Foldear
 * @ Filename: FlyweightPatternDemo.hpp
 * @ Modified time: 2025-07-09 17:30:38
 * @ Description:
 */

#ifndef FLYWEIGHT_PATTERN_DEMO_HPP
#define FLYWEIGHT_PATTERN_DEMO_HPP

#include "Application/Application.hpp"
#include "SceneFlyweightPattern.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

namespace GPV
{
class FlyweightPatternDemo : public ApplicationState
{
    SceneFlyweightPattern m_sceneFlyweightPattern;

  public:
    explicit FlyweightPatternDemo(const Context &context);
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
};
} // namespace GPV

#endif