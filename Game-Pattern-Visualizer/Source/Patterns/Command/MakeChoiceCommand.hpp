/**
 * @ Author: Foldear
 * @ Filename: MakeChoiceCommand.hpp
 * @ Modified time: 2025-06-09 10:08:32
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
    MakeChoiceCommand(Scene &scene, ChoiceState Choice, int Step) : scene(scene), currentChoice(Choice), currentStep(Step) {}
    virtual void execute()
    {
        // Keep track of the previous values
        previousStep = currentStep;
        previousChoice = currentChoice;
        // Select choice (this will trigger the animation and following text)
        scene.selectChoice(currentChoice);
        // Select step (after the end of the animation the next step should be selected)
        scene.selectStep(currentStep);
        scene.resetScene();
    }

    virtual void undo()
    {
        // If we undo the choice should be set to NO_CHOICE
        scene.selectChoice(previousChoice);
        // Then we select the previous step
        scene.selectStep(previousStep);
        scene.resetScene();
    }
};

} // namespace GPV
#endif