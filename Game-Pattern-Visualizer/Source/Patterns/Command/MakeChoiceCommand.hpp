#ifndef MAKE_CHOICE_COMMAND_HPP
#define MAKE_CHOICE_COMMAND_HPP

#include "Command.hpp"
#include "SceneCommandPattern.hpp"

namespace GPV
{

class MakeChoiceCommand : public Command
{
    SceneCommandPattern &scene;
    ChoiceState currentChoice = ChoiceState::None, previousChoice = ChoiceState::None;

  public:
    MakeChoiceCommand(SceneCommandPattern &scene, ChoiceState Choice) : scene(scene), currentChoice(Choice) {}
    virtual void execute()
    {
        previousChoice = currentChoice;
        // Select choice (this will trigger the animation and following text)
        scene.selectChoice(currentChoice);
        scene.changeSpriteAnimation(currentChoice);
        scene.startAnimation();
    }

    virtual void undo()
    {
        scene.selectChoice(previousChoice);
    }
};

} // namespace GPV
#endif