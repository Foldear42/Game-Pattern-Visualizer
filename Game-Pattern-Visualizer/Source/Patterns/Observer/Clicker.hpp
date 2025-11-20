#ifndef CLICKER_HPP
#define CLICKER_HPP

#include <SFML/Graphics.hpp>

#include "Components/Button/Button.hpp"
#include "Subject.hpp"

namespace GPV
{

class Clicker : public sf::Drawable, public sf::Transformable
{
    Subject m_clickSubject;
    sf::Text m_notifyText;
    Components::Button m_button;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   public:
    Clicker(const Context &context);
    // This object should not outlive the parent
    Subject &clickSubject()
    {
        return m_clickSubject;
    }
    void update(sf::Time delta);
    void handleEvent(const sf::RenderWindow &window, const std::optional<sf::Event> &event);
};

}  // namespace GPV

#endif