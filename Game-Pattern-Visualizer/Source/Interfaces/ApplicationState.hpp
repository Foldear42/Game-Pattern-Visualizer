#ifndef APPLICATION_STATE_HPP
#define APPLICATION_STATE_HPP

#include <SFML/Graphics.hpp>

#include "Manager/ResourceManager.hpp"

namespace GPV
{

class Application;  // forward declaration : no need to include the file

struct Context
{
    Context(TextureManager &tm, FontManager &fm, sf::RenderWindow &rw) : textureManager(tm), fontManager(fm), window(rw)
    {
    }
    TextureManager &textureManager;
    FontManager &fontManager;
    sf::RenderWindow &window;
};

class ApplicationState
{
   public:
    virtual ~ApplicationState() = default;
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) = 0;
    virtual void update(Application &application, sf::Time delta) = 0;
    virtual void render(sf::RenderWindow &window) = 0;

   protected:
    explicit ApplicationState(const Context &context) : m_context(context) {};
    const Context &m_context;
};

}  // namespace GPV
#endif