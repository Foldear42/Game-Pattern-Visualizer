/**
 * @ Author: Foldear
 * @ Filename: Scene.cpp
 * @ Modified time: 2025-06-30 11:03:43
 * @ Description: Implementation of the Scene class
 */

#include "Scene.hpp"

namespace GPV
{

Scene::Scene() : font(font) {}

Scene::Scene(const ResourceManager<sf::Texture, TextureID> &resourceManager, const sf::Font &font, DialogTree &dialogTree)
    : m_stickmanSprite(resourceManager.get(TextureID::stickman))
    , m_sceneAnimationSprite(resourceManager.get(TextureID::sceneAnimation))
    , m_sceneAnimation(std::in_place, m_sceneAnimationSprite, 9, 7, sf::seconds(0.1f), 4.f)
    , font(font)
    , m_dialogTree(dialogTree)
    , m_currentStep(1)
    , m_currentChoiceState(ChoiceState::None)
{
    m_dialogBox =
        std::make_unique<Components::DialogBox>(getListDialogByState(m_dialogTree, m_currentStep, m_currentChoiceState), font);
    sf::FloatRect bounds = m_stickmanSprite->getLocalBounds();
    m_stickmanSprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    m_dialogBox->setOrigin({m_dialogBox->getSizeRectangle().x / 2.f, m_dialogBox->getSizeRectangle().y / 2.f});
    m_dialogBox->startTypewriterAnimation();
    stopAnimation();
}

void Scene::update(Application &application, sf::Time delta)
{
    m_stickmanSprite->setPosition({application.getWindow().getSize().x / 2.f, 100.f});
    m_sceneAnimation->setPosition({application.getWindow().getSize().x / 2.f, 300.f});
    m_dialogBox->setPosition({application.getWindow().getSize().x / 2.f, 600.f});
    if (m_dialogBox)
    {
        m_dialogBox->update(delta);
        m_dialogBox->setListText(getListDialogByState(m_dialogTree, m_currentStep, m_currentChoiceState));
    }
    m_sceneAnimation->update(delta);
    if (m_sceneAnimation->isFinished)
    {
        stopAnimation();
    }
}

void Scene::selectStep(int step)
{
    m_currentStep = step;
}

void Scene::selectChoice(ChoiceState choiceState)
{
    m_currentChoiceState = choiceState;
}

void Scene::resetScene()
{
    m_dialogBox->resetIndexes();
    m_sceneAnimation->reset();
}

void Scene::startAnimation()
{
    m_sceneAnimation->start();
    isAnimating = true;
}

void Scene::stopAnimation()
{
    m_sceneAnimation->stop();
    isAnimating = false;
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (m_sceneAnimation)
    {
        target.draw(*m_sceneAnimation, states);
    }
    if (m_dialogBox)
    {
        target.draw(*m_dialogBox, states);
    }
    if (m_stickmanSprite)
    {
        target.draw(*m_stickmanSprite, states);
    }
}

} // namespace GPV