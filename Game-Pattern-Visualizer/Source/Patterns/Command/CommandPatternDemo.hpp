/**
 * @ Author: Foldear
 * @ Filename: CommandPatternDemo
 * @ Modified time: 2025-05-27 11:44:33
 * @ Description: State of the application for the command pattern demo
 */

#ifndef COMMAND_PATTERN_DEMO_HPP
#define COMMAND_PATTERN_DEMO_HPP

#include "Application/Application.hpp"
#include "Components/Button/Button.hpp"
#include "DialogTypes.hpp"
#include "Interfaces/ApplicationState.hpp"
#include "MakeChoiceCommand.hpp"
#include "Manager/ResourceManager.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <memory>
#include <stack>

namespace GPV
{

class CommandPatternDemo : public ApplicationState
{
    sf::Font m_font;
    Components::Button m_yesButton;
    Components::Button m_noButton;
    Components::Button m_undoButton;
    std::unique_ptr<Scene> m_scene;
    std::stack<std::unique_ptr<MakeChoiceCommand>> m_commandHistory;
    ResourceManager<sf::Texture, TextureID> m_resourceManager;
    std::map<std::pair<int, ChoiceState>, std::vector<sf::String>> m_dialogMap;

  public:
    CommandPatternDemo();
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
    void loadResources();
};

} // namespace GPV

#endif