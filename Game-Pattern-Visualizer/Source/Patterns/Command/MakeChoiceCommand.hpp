/**
 * @ Author: Foldear
 * @ Filename: MakeChoiceCommand.hpp
 * @ Modified time: 2025-05-28 09:10:26
 * @ Description: Command to handle the player's choice
 */

#ifndef MAKE_CHOICE_COMMAND_HPP
#define MAKE_CHOICE_COMMAND_HPP

#include "Command.hpp"
#include "Scene.hpp"

namespace GPV
{

class MakeChoiceCommand : public Command
{
    Scene &scene;
    ChoiceState currentChoice = ChoiceState::None, previousChoice = ChoiceState::None;
    int currentStep = 1, previousStep = 1;

  public:
    MakeChoiceCommand(Scene &scene, ChoiceState Choice) : scene(scene), currentChoice(Choice) {}
    virtual void execute()
    {
        scene.resetScene();
        // Keep track of the previous values
        this->previousStep = currentStep;
        this->previousChoice = currentChoice;
        // Select choice (this will trigger the animation and following text)
        scene.selectChoice(currentChoice);
        // Select step (after the end of the animation the next step should be selected)
        scene.selectStep(currentStep);
    }

    virtual void undo()
    {
        // If we undo the choice should be set to NO_CHOICE
        scene.selectChoice(previousChoice);
        // Then we select the previous step
        scene.selectStep(previousStep);
    }
};

} // namespace GPV
#endif