/**
 * @ Author: Foldear
 * @ Filename: CommandPatternDemo.cpp
 * @ Modified time: 2025-06-02 08:50:25
 * @ Description: Implementation of the command pattern demo
 */

#include "CommandPatternDemo.hpp"

namespace GPV
{

CommandPatternDemo::CommandPatternDemo()
{
    // Load resources before creating an instance of scene
    loadResources();
    this->m_dialogMap[{1, ChoiceState::None}] = {"This is a test", "This seems to work"};
    this->m_dialogMap[{1, ChoiceState::Yes}] = {"You choose YES :)"};
    this->m_dialogMap[{1, ChoiceState::No}] = {"You choose NO :("};
    this->m_scene = std::make_unique<Scene>(m_resourceManager, this->m_font, this->m_dialogMap);
    // Yes button
    sf::Vector2f buttonSize = {100.f, 50.f};
    this->m_yesButton = Components::Button(buttonSize, "YES", this->m_font, sf::Color::Red, State::STATE_YES);
    this->m_yesButton.setOrigin({this->m_yesButton.getSizeRectangle().x / 2, this->m_yesButton.getSizeRectangle().y / 2});
    // No button
    this->m_noButton = Components::Button(buttonSize, "NO", this->m_font, sf::Color::Blue, State::STATE_NO);
    this->m_noButton.setOrigin({this->m_noButton.getSizeRectangle().x / 2, this->m_noButton.getSizeRectangle().y / 2});
    // Undo Button
    this->m_undoButton = Components::Button(buttonSize, "UNDO", this->m_font, sf::Color::Cyan, State::STATE_UNDO);
    this->m_undoButton.setOrigin({this->m_undoButton.getSizeRectangle().x / 2, this->m_undoButton.getSizeRectangle().y / 2});
    // Create the first MakeChoiceCommand and push it onto the stack
    std::unique_ptr<MakeChoiceCommand> command = std::make_unique<MakeChoiceCommand>(*this->m_scene, ChoiceState::None);
    m_commandHistory.push(std::move(command));
}

void CommandPatternDemo::loadResources()
{
    this->m_font.openFromFile("Resources/Fonts/ARIAL.ttf");
    m_resourceManager.load(TextureID::stickman, "Resources/Images/Stickman.png");
    m_resourceManager.load(TextureID::sceneAnimation, "Resources/Images/tram.png");
}

void CommandPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event)
{
    this->m_yesButton.getButtonStatus(application.getWindow(), event);
    if (this->m_yesButton.isPressed)
    {
        // Create a new command
        std::unique_ptr<MakeChoiceCommand> command;
        command = std::make_unique<MakeChoiceCommand>(*this->m_scene, ChoiceState::Yes);
        command->execute();
        // Keep a trace of the pointer Command onto the stack
        m_commandHistory.push(std::move(command));
    }

    this->m_noButton.getButtonStatus(application.getWindow(), event);
    if (this->m_noButton.isPressed)
    {
        // Create a new command
        std::unique_ptr<MakeChoiceCommand> command;
        command = std::make_unique<MakeChoiceCommand>(*this->m_scene, ChoiceState::No);
        command->execute();
        // Keep a trace of the pointer Command onto the stack
        m_commandHistory.push(std::move(command));
    }

    this->m_undoButton.getButtonStatus(application.getWindow(), event);
    if (this->m_undoButton.isPressed)
    {
        std::unique_ptr<MakeChoiceCommand> command;
        // We remove the last element from the stack
        if (m_commandHistory.size() > 1)
        {
            m_commandHistory.pop();
            // We move the pointer to the previous element
            auto &command = m_commandHistory.top();
            command->undo();
        }
    }
}

void CommandPatternDemo::update(Application &application, sf::Time delta)
{
    float spacing = 20.f;
    this->m_yesButton.setPosition({(application.getWindow().getSize().x / 2.f), 800.f});
    this->m_noButton.setPosition({(m_yesButton.getPosition().x + m_yesButton.getSizeRectangle().x + spacing), 800.f});
    this->m_undoButton.setPosition({(m_noButton.getPosition().x + m_noButton.getSizeRectangle().x + spacing), 800.f});
    if (this->m_scene)
    {
        this->m_scene->update(application, delta);
    }
}

void CommandPatternDemo::render(sf::RenderWindow &window)
{
    if (this->m_scene)
        window.draw(*this->m_scene);

    //  Draw
    window.draw(this->m_undoButton);
    window.draw(this->m_noButton);
    window.draw(this->m_yesButton);
}

} // namespace GPV