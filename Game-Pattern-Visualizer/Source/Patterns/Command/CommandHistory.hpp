#ifndef COMMAND_HISTORY_HPP
#define COMMAND_HISTORY_HPP

#include "Command.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>

namespace GPV
{

class CommandHistory : public sf::Drawable
{
    struct CommandData
    {
        sf::RectangleShape shape;
        std::unique_ptr<Command> p_command;
    };

    std::vector<CommandData> m_commandHistory;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    CommandHistory();
    void pushCommand(std::unique_ptr<Command> command);
    void popCommand();
};

} // namespace GPV

#endif