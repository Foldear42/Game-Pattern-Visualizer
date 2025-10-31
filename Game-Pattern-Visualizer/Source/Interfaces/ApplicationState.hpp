#ifndef APPLICATION_STATE_HPP
#define APPLICATION_STATE_HPP

#include "Manager/ResourceManager.hpp"
#include <SFML/Graphics.hpp>

namespace GPV
{

class Application; // forward declaration : no need to include the file

struct Context
{
    Context(TextureManager &tm, FontManager &fm) : textureManager(tm), fontManager(fm) {}
    TextureManager &textureManager;
    FontManager &fontManager;
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

} // namespace GPV
#endif