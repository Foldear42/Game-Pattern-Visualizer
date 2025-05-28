/**
 * @ Author: Foldear
 * @ Filename: Scene.hpp
 * @ Modified time: 2025-05-28 09:09:40
 * @ Description: This file handles the scene in which the consequences of the player's actions will be seen
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Application/Application.hpp"
#include "Components/DialogBox/DialogBox.hpp"
#include "DialogTypes.hpp"
#include "Manager/ResourceManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

namespace GPV
{

class Scene : public sf::Drawable
{
    DialogMap m_dialogMap;
    sf::Texture m_sceneTexture;
    std::optional<sf::Sprite> m_sceneSprite;
    sf::Texture m_stickmanTexture;
    std::optional<sf::Sprite> m_stickmanSprite;
    std::unique_ptr<Components::DialogBox> m_dialogBox;
    ChoiceState m_currentChoiceState = ChoiceState::None;
    const sf::Font &font;
    int m_currentStep = 1;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Scene();
    Scene(const ResourceManager<sf::Texture, TextureID> &resourceManager, const sf::Font &font, DialogMap &dialogMap);
    void update(Application &application, sf::Time delta);
    void selectChoice(ChoiceState choiceState);
    void selectStep(int step);
    void resetScene();
    bool isAnimating = false;
};

} // namespace GPV

#endif