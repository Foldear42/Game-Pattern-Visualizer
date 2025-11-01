#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

#include "Enums/FontID.hpp"
#include "Enums/TextureID.hpp"
#include "Interfaces/ApplicationState.hpp"
#include "Manager/ResourceManager.hpp"

namespace GPV
{

class Application
{
    std::unique_ptr<ApplicationState> p_state;
    sf::RenderWindow &renderWindow;
    TextureManager m_textureManager;
    FontManager m_fontManager;
    Context m_context;

   public:
    Application(sf::RenderWindow &window);
    void run();
    void handleEvent(const std::optional<sf::Event> &event);
    void changeState(std::unique_ptr<ApplicationState> state);
    void update(sf::Time delta);
    void render(sf::RenderWindow &window);
    void loadAllResources();
    const sf::RenderWindow &getWindow() const;
};

}  // namespace GPV

#endif