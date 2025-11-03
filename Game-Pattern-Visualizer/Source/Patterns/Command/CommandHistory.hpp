#ifndef COMMAND_HISTORY_HPP
#define COMMAND_HISTORY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>

#include "Command.hpp"
#include "Enums/FontID.hpp"
#include "Interfaces/ApplicationState.hpp"

namespace GPV
{

class CommandHistory : public sf::Drawable
{
    struct CommandData
    {
        sf::RectangleShape shape;
        sf::Text text;
        Command* p_command;
    };
    const sf::Font& m_font;
    sf::Vector2f m_initialPosition{0.f, 100.f};
    std::vector<CommandData> m_commandVector;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

   public:
    CommandHistory(Context context);
    void pushCommand(Command* command);
    Command* popCommand();
};

}  // namespace GPV

#endif