/**
 * @ Author: Foldear
 * @ Filename: Scene.hpp
 * @ Modified time: 2025-05-26 15:55:27
 * @ Description: This file handles the scene in which the consequences of the player's actions will be seen
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Application/Application.hpp"
#include "ChoiceState.hpp"
#include "Components/DialogBox/DialogBox.hpp"
#include "Manager/ResourceManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

namespace GPV
{

class Scene : public sf::Drawable
{
    std::vector<sf::String> m_listText;
    sf::Texture m_sceneTexture;
    std::optional<sf::Sprite> m_sceneSprite;
    sf::Texture m_stickmanTexture;
    std::optional<sf::Sprite> m_stickmanSprite;
    std::vector<int> m_steps;
    std::unique_ptr<Components::DialogBox> m_dialogBox;
    ChoiceState m_currentChoiceState;
    const sf::Font &font;
    int m_currentStep = 0;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Scene();
    Scene(const ResourceManager<sf::Texture, TextureID> &resourceManager, const sf::Font &font);
    void update(Application &application, sf::Time delta);
    void selectChoice(ChoiceState choiceState);
    void selectStep(int step);
    bool isAnimating = false;
};

} // namespace GPV

#endif