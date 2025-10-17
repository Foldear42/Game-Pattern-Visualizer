/**
 * @ Author: Foldear
 * @ Filename: CommandPatternDemo.cpp
 * @ Modified time: 2025-10-17 11:30:14
 * @ Description: Implementation of the command pattern demo
 */

#include "CommandPatternDemo.hpp"

namespace GPV
{

CommandPatternDemo::CommandPatternDemo(const Context &context)
    : ApplicationState(context)
    , m_yesButton(Components::Button({0.5f, 0.5f}, "YES", context.textureManager.get(TextureID::wideButtonBackground),
                                     context.fontManager.get(FontID::Arial), sf::Color::Red, State::STATE_YES))
    , m_noButton(Components::Button({0.5f, 0.5f}, "NO", context.textureManager.get(TextureID::wideButtonBackground),
                                    context.fontManager.get(FontID::Arial), sf::Color::Blue, State::STATE_NO))
    , m_undoButton(Components::Button({0.5f, 0.5f}, "NO", context.textureManager.get(TextureID::wideButtonBackground),
                                      context.fontManager.get(FontID::Arial), sf::Color::Blue, State::STATE_NO))
    , m_nextStepButton(Components::Button({0.5f, 0.5f}, "NEXT STEP", context.textureManager.get(TextureID::wideButtonBackground),
                                          context.fontManager.get(FontID::Arial), sf ::Color::Cyan, State::STATE_NEXTSTEP))

{
    // Create the dialog tree object
    std::ifstream file("Resources/dialogTree.json");
    if (!file)
    {
        throw std::runtime_error("error file not found");
    }
    nlohmann::json j;
    file >> j;
    for (auto &[key, value] : j.items())
    {
        int step = std::stoi(key);
        m_dialogTree[step] = value.get<std::vector<Choice>>();
    }
    sf::Font &arialFont = context.fontManager.get(FontID::Arial);
    m_scene = std::make_unique<SceneCommandPattern>(context.textureManager, arialFont, m_dialogTree);
    // Yes button
    sf::Vector2f buttonSize = {100.f, 50.f};

    m_yesButton.setOrigin({m_yesButton.getSizeSprite().x / 2, m_yesButton.getSizeSprite().y / 2});
    // No button
    m_noButton.setOrigin({m_noButton.getSizeSprite().x / 2, m_noButton.getSizeSprite().y / 2});
    // Undo Button
    m_undoButton.setOrigin({m_undoButton.getSizeSprite().x / 2, m_undoButton.getSizeSprite().y / 2});
    // Create the first MakeChoiceCommand and push it onto the stack
    m_nextStepButton.setOrigin({m_nextStepButton.getSizeSprite().x / 2, m_nextStepButton.getSizeSprite().y / 2});
    std::unique_ptr<MakeChoiceCommand> command = std::make_unique<MakeChoiceCommand>(*m_scene, ChoiceState::None, 1);
    m_commandHistory.push(std::move(command));
}

void CommandPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event)
{
    m_yesButton.getButtonStatus(application.getWindow(), event);
    if (m_yesButton.isPressed)
    {
        m_scene->changeSpriteAnimation(ChoiceState::Yes);
        m_scene->startAnimation();
        // Create a new command
        std::unique_ptr<MakeChoiceCommand> command;
        command = std::make_unique<MakeChoiceCommand>(*m_scene, ChoiceState::Yes, m_scene->m_currentStep);
        command->execute();
        // Keep a trace of the pointer Command onto the stack
        m_commandHistory.push(std::move(command));
    }

    m_noButton.getButtonStatus(application.getWindow(), event);
    if (m_noButton.isPressed)
    {
        m_scene->changeSpriteAnimation(ChoiceState::No);
        m_scene->startAnimation();
        // Create a new command
        std::unique_ptr<MakeChoiceCommand> command;
        command = std::make_unique<MakeChoiceCommand>(*m_scene, ChoiceState::No, m_scene->m_currentStep);
        command->execute();
        // Keep a trace of the pointer Command onto the stack
        m_commandHistory.push(std::move(command));
    }

    m_undoButton.getButtonStatus(application.getWindow(), event);
    if (m_undoButton.isPressed)
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

    m_nextStepButton.getButtonStatus(application.getWindow(), event);
    // When the choice is made we wait for the animation to end and move to the next step by doing a command
    if (m_nextStepButton.isPressed)
    {
        std::unique_ptr<MakeChoiceCommand> command;
        command = std::make_unique<MakeChoiceCommand>(*m_scene, ChoiceState::None, m_scene->m_currentStep + 1);
        command->execute();
        m_commandHistory.push(std::move(command));
    }
}

void CommandPatternDemo::update(Application &application, sf::Time delta)
{
    float spacing = 20.f;
    m_yesButton.setPosition({(application.getWindow().getSize().x / 2.f), 800.f});
    m_noButton.setPosition({(m_yesButton.getPosition().x + m_yesButton.getSizeSprite().x + spacing), 800.f});
    m_undoButton.setPosition({(m_noButton.getPosition().x + m_noButton.getSizeSprite().x + spacing), 800.f});
    m_nextStepButton.setPosition({(m_undoButton.getPosition().x + m_undoButton.getSizeSprite().x + spacing), 800.f});

    m_yesButton.update(delta);
    m_noButton.update(delta);
    m_undoButton.update(delta);
    m_nextStepButton.update(delta);

    if (m_scene)
    {
        m_scene->update(application, delta);
        if (m_scene->isAnimating)
        {
            m_yesButton.deactivate();
            m_noButton.deactivate();
            m_undoButton.deactivate();
            m_nextStepButton.deactivate();
        }
        else
        {
            if (m_scene->m_currentChoiceState == ChoiceState::None)
            {
                m_yesButton.activate();
                m_noButton.activate();
                if (m_scene->m_currentStep > 1)
                {
                    m_undoButton.activate();
                }
                else
                {
                    m_undoButton.deactivate();
                }
                m_nextStepButton.deactivate();
            }
            else
            {
                m_yesButton.deactivate();
                m_noButton.deactivate();
                m_undoButton.activate();
                m_nextStepButton.activate();
            }
        }
    }
}

void CommandPatternDemo::render(sf::RenderWindow &window)
{
    if (m_scene)
        window.draw(*m_scene);

    //  Draw
    window.draw(m_undoButton);
    window.draw(m_noButton);
    window.draw(m_yesButton);
    window.draw(m_nextStepButton);
}

} // namespace GPV