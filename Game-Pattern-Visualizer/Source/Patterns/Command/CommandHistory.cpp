#ifndef COMMAND_HISTORY_CPP
#define COMMAND_HISTORY_CPP

#include "CommandHistory.hpp"

namespace GPV
{
CommandHistory::CommandHistory()
{
}

void CommandHistory::pushCommand(std::unique_ptr<Command> command)
{
    sf::RectangleShape newVisualShape({200.f, 100.f});
    newVisualShape.setOutlineColor(sf::Color::White);
    newVisualShape.setFillColor(sf::Color::Black);
    newVisualShape.setPosition({100.f, 100.f});
    m_commandHistory.emplace_back(CommandData{newVisualShape, std::move(command)});
}
void CommandHistory::popCommand()
{
}

void CommandHistory::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &it : m_commandHistory)
    {
        target.draw(it.shape);
    }
}
}  // namespace GPV

#endif