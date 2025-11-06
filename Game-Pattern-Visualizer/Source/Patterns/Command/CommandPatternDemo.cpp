#include "CommandPatternDemo.hpp"

namespace GPV
{

CommandPatternDemo::CommandPatternDemo(const Context &context)
    : ApplicationState(context),
      m_buttons{{Components::Button({0.5f, 0.5f}, "YES", context.textureManager.get(TextureID::wideButtonBackground),
                                    context.fontManager.get(FontID::Arial), sf::Color::Red),
                 Components::Button({0.5f, 0.5f}, "NO", context.textureManager.get(TextureID::wideButtonBackground),
                                    context.fontManager.get(FontID::Arial), sf::Color::Blue),
                 Components::Button({0.5f, 0.5f}, "UNDO", context.textureManager.get(TextureID::wideButtonBackground),
                                    context.fontManager.get(FontID::Arial), sf::Color::Blue),
                 Components::Button({0.5f, 0.5f}, "NEXT STEP", context.textureManager.get(TextureID::wideButtonBackground),
                                    context.fontManager.get(FontID::Arial), sf ::Color::Cyan)}},

      m_dialogTree("dialogTree.json"),
      m_scene(context.textureManager, context.fontManager.get(FontID::Arial), m_dialogTree),
      m_commandHistory(context)
{
    // Yes button
    m_buttons[0].setOrigin(m_buttons[0].getSizeSprite().getCenter());
    m_buttons[0].registerCallback([this]() { executeCommand(new MakeChoiceCommand(m_scene, ChoiceState::Yes)); });
    // No button
    m_buttons[1].setOrigin(m_buttons[1].getSizeSprite().getCenter());
    m_buttons[1].registerCallback([this]() { executeCommand(new MakeChoiceCommand(m_scene, ChoiceState::No)); });
    // Undo Button
    m_buttons[2].setOrigin(m_buttons[2].getSizeSprite().getCenter());
    m_buttons[2].registerCallback([this]() { undoCommand(); });
    // Next step button
    m_buttons[3].setOrigin(m_buttons[3].getSizeSprite().getCenter());
    m_buttons[3].registerCallback([this]() { executeCommand(new NextStepCommand(m_scene)); });
}

void CommandPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event)
{
    for (auto &button : m_buttons)
    {
        button.getButtonStatus(application.getWindow(), event);
        if (button.isPressed)
        {
            button.invokeCallback();
        }
    }
}

void CommandPatternDemo::executeCommand(Command *command)
{
    std::cout << "Execute !" << std::endl;
    command->execute();
    m_commandHistory.pushCommand(command);
}

void CommandPatternDemo::undoCommand()
{
    Command *command = m_commandHistory.popCommand();
    command->undo();
    delete command;
}

void CommandPatternDemo::update(Application &application, sf::Time delta)
{
    m_buttons[0].setPosition({(application.getWindow().getSize().x / 2.f), 800.f});
    m_buttons[1].setPosition({(m_buttons[0].getPosition().x + m_buttons[0].getSizeSprite().size.x + 20.f), 800.f});
    m_buttons[2].setPosition({(m_buttons[1].getPosition().x + m_buttons[1].getSizeSprite().size.x + 20.f), 800.f});
    m_buttons[3].setPosition({(m_buttons[2].getPosition().x + m_buttons[2].getSizeSprite().size.x + 20.f), 800.f});

    m_buttons[0].update(delta);
    m_buttons[1].update(delta);
    m_buttons[2].update(delta);
    m_buttons[3].update(delta);

    m_scene.update(application, delta);
    if (m_scene.isAnimating)
    {
        m_buttons[0].deactivate();
        m_buttons[1].deactivate();
        m_buttons[2].deactivate();
        m_buttons[3].deactivate();
    }
    else
    {
        if (m_scene.m_currentChoiceState == ChoiceState::None)
        {
            m_buttons[0].activate();
            m_buttons[1].activate();
            if (m_scene.m_currentStep > 1)
            {
                m_buttons[2].activate();
            }
            else
            {
                m_buttons[2].deactivate();
            }
            m_buttons[3].deactivate();
        }
        else
        {
            m_buttons[0].deactivate();
            m_buttons[1].deactivate();
            m_buttons[2].activate();
            m_buttons[3].activate();
        }
    }
}

void CommandPatternDemo::render(sf::RenderWindow &window)
{
    window.draw(m_scene);
    window.draw(m_buttons[0]);
    window.draw(m_buttons[1]);
    window.draw(m_buttons[2]);
    window.draw(m_buttons[3]);
    window.draw(m_commandHistory);
}

}  // namespace GPV