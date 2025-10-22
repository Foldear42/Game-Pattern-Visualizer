/**
 * @ Author: Foldear
 * @ Filename: PrototypePatternDemo.hpp
 * @ Modified time: 2025-10-22 09:17:28
 * @ Description:
 */

#ifndef PROTOTYPE_PATTERN_DEMO_HPP
#define PROTOTYPE_PATTERN_DEMO_HPP

#include "Application/Application.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

namespace GPV
{
class PrototypePatternDemo : public ApplicationState
{
  public:
    explicit PrototypePatternDemo(const Context &context);
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
};
} // namespace GPV

#endif