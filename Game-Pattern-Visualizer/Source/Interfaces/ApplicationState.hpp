/**
 * @ Author: Foldear
 * @ Filename: ApplicationState.hpp
 * @ Modified time: 2025-07-03 15:44:32
 * @ Description: Interface for state dependent entities
 */

#ifndef APPLICATION_STATE_HPP
#define APPLICATION_STATE_HPP

#include <SFML/Graphics.hpp>

namespace GPV
{

class Application; // forward declaration : no need to include the file

class ApplicationState
{
  public:
    virtual ~ApplicationState() = default;
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) = 0;
    virtual void update(Application &application, sf::Time delta) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
};

} // namespace GPV
#endif