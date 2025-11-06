#ifndef COMMAND_HISTORY_CPP
#define COMMAND_HISTORY_CPP

#include "CommandHistory.hpp"

namespace GPV
{
CommandHistory::CommandHistory(Context context) : m_font(context.fontManager.get(FontID::Arial))
{
}

void CommandHistory::pushCommand(Command *command)
{
    sf::RectangleShape newVisualShape(m_sizeRectangle);
    sf::String commandInfoStr;
    sf::Text visualText(m_font);
    commandInfoStr = command->getInfo();
    // Set visual text
    visualText.setString(commandInfoStr);
    visualText.setCharacterSize(15);
    visualText.setPosition({m_initialPosition.x, m_initialPosition.y});
    // Set visual shape
    newVisualShape.setOutlineColor(sf::Color::White);
    newVisualShape.setOutlineThickness(2);
    newVisualShape.setFillColor(sf::Color::Black);
    newVisualShape.setPosition({m_initialPosition.x, m_initialPosition.y});
    // No transformation so we can use the rectangle size directly
    m_initialPosition.y += m_sizeRectangle.y + m_spacing;
    m_commandVector.emplace_back(CommandData{newVisualShape, visualText, command});
}

Command *CommandHistory::popCommand()
{
    Command *p_lastCommand = nullptr;
    if (!m_commandVector.empty())
    {
        p_lastCommand = m_commandVector.back().p_command;
        m_initialPosition.y -= m_sizeRectangle.y + m_spacing;
        // Delete from the vector
        m_commandVector.pop_back();
    }
    return p_lastCommand;
}

void CommandHistory::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &it : m_commandVector)
    {
        target.draw(it.shape);
        target.draw(it.text);
    }
}
}  // namespace GPV

#endif