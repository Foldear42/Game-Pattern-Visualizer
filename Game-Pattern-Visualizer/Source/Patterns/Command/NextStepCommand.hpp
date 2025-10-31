#ifndef NEXT_STEP_COMMAND_HPP
#define NEXT_STEP_COMMAND_HPP

#include "Command.hpp"
#include "SceneCommandPattern.hpp"

namespace GPV
{

class NextStepCommand : public Command
{
    SceneCommandPattern &scene;
    int currentStep, previousStep;

  public:
    NextStepCommand(SceneCommandPattern &scene) : scene(scene)
    {
        currentStep = scene.m_currentStep;
    }
    virtual void execute()
    {
        previousStep = currentStep;
        currentStep = currentStep + 1;
        // Select step (after the end of the animation the next step should be selected)
        scene.selectStep(currentStep);
        scene.resetScene();
    }

    virtual void undo()
    {
        scene.selectStep(previousStep);
        scene.resetScene();
    }
};

} // namespace GPV
#endif