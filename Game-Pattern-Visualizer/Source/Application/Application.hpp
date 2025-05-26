/**
 * @ Author: Foldear
 * @ Filename: Appliction.hpp
 * @ Modified time: 2025-05-26 09:55:24
 * @ Description: Main application header
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Interfaces/ApplicationState.hpp"
#include <memory>

namespace GPV
{

class Application
{
    std::unique_ptr<ApplicationState> state_;
    sf::RenderWindow &renderWindow;

  public:
    Application(std::unique_ptr<ApplicationState> initialState, sf::RenderWindow &window);
    void run();
    void handleEvent(const std::optional<sf::Event> &event);
    void changeState(std::unique_ptr<ApplicationState> state);
    void update(sf::Time delta);
    void render(sf::RenderWindow &window);
    const sf::RenderWindow &getWindow() const;
};

} // namespace GPV

#endif