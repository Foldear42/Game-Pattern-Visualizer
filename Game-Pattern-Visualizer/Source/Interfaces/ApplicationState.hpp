/**
 * @ Author: Foldear
 * @ Filename: ApplicationState.hpp
 * @ Modified time: 2025-05-26 15:12:21
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
    virtual ~ApplicationState() {}
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) {}
    virtual void update(Application &application, sf::Time delta) {}
    virtual void render(sf::RenderWindow &window) {}
};

} // namespace GPV
#endif