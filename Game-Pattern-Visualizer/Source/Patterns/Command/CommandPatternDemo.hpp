#ifndef COMMAND_PATTERN_DEMO_HPP
#define COMMAND_PATTERN_DEMO_HPP

#include <SFML/Graphics/Rect.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <stack>

#include "Application/Application.hpp"
#include "CommandHistory.hpp"
#include "Components/Button/Button.hpp"
#include "DialogTree/DialogTree.hpp"
#include "Interfaces/ApplicationState.hpp"
#include "MakeChoiceCommand.hpp"
#include "Manager/ResourceManager.hpp"
#include "NextStepCommand.hpp"
#include "States/MenuState.hpp"

namespace GPV
{

class CommandPatternDemo : public ApplicationState
{
    std::array<Components::Button, 4> m_buttons;
    Components::Button m_backMenuButton;
    DialogTree m_dialogTree;
    SceneCommandPattern m_scene;
    CommandHistory m_commandHistory;

   public:
    explicit CommandPatternDemo(const Context &context);
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
    void executeCommand(Command *command);
    void undoCommand();
};

}  // namespace GPV

#endif