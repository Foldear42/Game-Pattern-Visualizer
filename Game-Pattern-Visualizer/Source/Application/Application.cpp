/**
 * @ Author: Foldear
 * @ Filename: Application.cpp
 * @ Modified time: 2025-10-16 10:55:23
 * @ Description: Main application implementation
 */

#include "Application.hpp"
#include "States/MenuState.hpp"

namespace GPV
{

Application::Application(sf::RenderWindow &window) : renderWindow(window), m_context(m_textureManager, m_fontManager) {}

void Application::run()
{
    sf::Clock clock;
    this->renderWindow.setPosition({0, 0});
    loadAllResources();
    // Create the first state
    p_state = std::move(std::make_unique<MenuState>(m_context));
    // Game loop
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
    p_state->handleEvent(*this, event);
}

void Application::changeState(std::unique_ptr<ApplicationState> state)
{
    p_state = std::move(state);
}

void Application::update(sf::Time delta)
{
    p_state->update(*this, delta);
}

void Application::render(sf::RenderWindow &window)
{
    renderWindow.clear();
    p_state->render(window);
    renderWindow.display();
}

void Application::loadAllResources()
{

    m_fontManager.load(FontID::Arial, "Resources/Fonts/ARIAL.TTF");
    // Command demo
    m_textureManager.load(TextureID::stickman, "Resources/Images/Stickman.png");
    m_textureManager.load(TextureID::sceneAnimationYes1, "Resources/Images/Animation_Yes_1.png");
    m_textureManager.load(TextureID::sceneAnimationNo1, "Resources/Images/Animation_No_1.png");
    // Lightweight demo
    m_textureManager.load(TextureID::waterterrain, "Resources/Images/tiles/waterterrain.png");
    m_textureManager.load(TextureID::grassterrain, "Resources/Images/tiles/grassterrain.png");
    m_textureManager.load(TextureID::dirtterrain, "Resources/Images/tiles/dirtterrain.png");

    m_textureManager.load(TextureID::dummy, "Resources/Images/dummy.png");
    m_textureManager.load(TextureID::dummy2, "Resources/Images/dummy2.png");
}

const sf::RenderWindow &Application::getWindow() const
{
    return renderWindow;
}

} // namespace GPV