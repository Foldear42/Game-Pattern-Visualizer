/**
 * @ Author: Foldear
 * @ Filename: Scene.hpp
 * @ Modified time: 2025-07-04 14:35:45
 * @ Description: This file handles the scene in which the consequences of the player's actions will be seen
 */

#ifndef SCENE_COMMAND_PATTERN_HPP
#define SCENE_COMMAND_PATTERN_HPP

#include "Application/Application.hpp"
#include "Components/Animation/Animation.hpp"
#include "Components/DialogBox/DialogBox.hpp"
#include "DialogTypes.hpp"
#include "Interfaces/Scene.hpp"
#include "Manager/ResourceManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

namespace GPV
{

class SceneCommandPattern : public Scene
{
    const sf::Font &font;
    DialogTree m_dialogTree;
    std::optional<sf::Sprite> m_stickmanSprite;
    std::optional<sf::Sprite> m_sceneAnimationSprite;
    std::unique_ptr<Components::DialogBox> m_dialogBox;
    std::optional<Components::Animation> m_sceneAnimation;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    SceneCommandPattern();
    SceneCommandPattern(const ResourceManager<sf::Texture, TextureID> &resourceManager, const sf::Font &font,
                        DialogTree &dialogTree);
    void update(Application &application, sf::Time delta) override;
    void selectChoice(ChoiceState choiceState);
    void selectStep(int step);
    void resetScene();
    void startAnimation();
    void stopAnimation();
    void nextStep();
    int m_currentStep;
    bool isAnimating = false;
    bool isStepFinished = false;
    ChoiceState m_currentChoiceState = ChoiceState::None;
};

} // namespace GPV

#endif