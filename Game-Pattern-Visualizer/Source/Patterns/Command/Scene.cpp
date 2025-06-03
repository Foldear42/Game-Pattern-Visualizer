/**
 * @ Author: Foldear
 * @ Filename: Scene.cpp
 * @ Modified time: 2025-06-03 10:50:59
 * @ Description: Implementation of the Scene class
 */

#include "Scene.hpp"

namespace GPV
{

Scene::Scene() : font(font) {}

Scene::Scene(const ResourceManager<sf::Texture, TextureID> &resourceManager, const sf::Font &font, DialogMap &dialogMap)
    : m_stickmanSprite(resourceManager.get(TextureID::stickman))
    , m_sceneSpriteAnimation(resourceManager.get(TextureID::sceneAnimation))
    , m_sceneAnimation(std::in_place, m_sceneSpriteAnimation, 9, 7, sf::seconds(0.1f), 4.f)
    , font(font)
    , m_dialogMap(dialogMap)
{
    this->m_dialogBox = std::make_unique<Components::DialogBox>(this->m_dialogMap[{1, ChoiceState::None}], this->font);
    sf::FloatRect bounds = this->m_stickmanSprite->getLocalBounds();
    this->m_stickmanSprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    this->m_dialogBox->setOrigin({this->m_dialogBox->getSizeRectangle().x / 2.f, this->m_dialogBox->getSizeRectangle().y / 2.f});
    this->stopAnimation();
    m_dialogBox->startTypewriterAnimation();
}

void Scene::update(Application &application, sf::Time delta)
{
    this->m_stickmanSprite->setPosition({application.getWindow().getSize().x / 2.f, 100.f});
    this->m_sceneAnimation->setPosition({application.getWindow().getSize().x / 2.f, 300.f});
    this->m_dialogBox->setPosition({application.getWindow().getSize().x / 2.f, 600.f});
    if (this->m_dialogBox)
    {
        this->m_dialogBox->update(delta);
        this->m_dialogBox->setListText(this->m_dialogMap[{this->m_currentStep, this->m_currentChoiceState}]);
    }
    this->m_sceneAnimation->update(delta);
    if (m_sceneAnimation->isFinished)
    {
        this->stopAnimation();
    }
}

void Scene::selectStep(int step)
{
    this->m_currentStep = step;
}

void Scene::selectChoice(ChoiceState choiceState)
{
    this->m_currentChoiceState = choiceState;
}

void Scene::resetScene()
{
    this->m_dialogBox->resetIndexes();
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
    if (this->m_sceneAnimation)
    {
        target.draw(*this->m_sceneAnimation, states);
    }
    if (this->m_dialogBox)
    {
        target.draw(*this->m_dialogBox, states);
    }
    if (this->m_stickmanSprite)
    {
        target.draw(*this->m_stickmanSprite, states);
    }
}

} // namespace GPV