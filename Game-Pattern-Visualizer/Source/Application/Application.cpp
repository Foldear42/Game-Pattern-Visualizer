/**
 * @ Author: Foldear
 * @ Filename: Application.hpp
 * @ Modified time: 2025-05-26 09:55:42
 * @ Description: Main application implementation
 */

#include "Application.hpp"
#include "States/MenuState.hpp"

namespace GPV
{

Application::Application(std::unique_ptr<ApplicationState> initialState, sf::RenderWindow &window) : renderWindow(window)
{
    state_ = std::move(initialState);
}

void Application::run()
{
    sf::Clock clock;
    this->renderWindow.setPosition({0, 0});
    //  Game loop
    while (renderWindow.isOpen())
    {
        sf::Time delta = clock.restart();
        // Event loop
        while (const std::optional event = renderWindow.pollEvent())
        {
            this->handleEvent(event);
            if (event->is<sf::Event::Closed>())
                renderWindow.close();
            if (const auto *resized = event->getIf<sf::Event::Resized>())
            {
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                renderWindow.setView(sf::View(visibleArea));
            }
        }
        // Update
        this->update(delta);
        // Render
        this->render(renderWindow);
    }
}

void Application::handleEvent(const std::optional<sf::Event> &event)
{
    state_->handleEvent(*this, event);
}

void Application::changeState(std::unique_ptr<ApplicationState> state)
{
    state_ = std::move(state);
}

void Application::update(sf::Time delta)
{
    state_->update(*this, delta);
}

void Application::render(sf::RenderWindow &window)
{
    renderWindow.clear();
    state_->render(window);
    renderWindow.display();
}

const sf::RenderWindow &Application::getWindow() const
{
    return renderWindow;
}

} // namespace GPV