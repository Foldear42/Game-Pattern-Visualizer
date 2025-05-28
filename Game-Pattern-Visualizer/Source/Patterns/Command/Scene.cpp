/**
 * @ Author: Foldear
 * @ Filename: Scene.cpp
 * @ Modified time: 2025-05-28 09:10:16
 * @ Description: Implementation of the Scene class
 */

#include "Scene.hpp"

namespace GPV
{

Scene::Scene() : font(font) {}

Scene::Scene(const ResourceManager<sf::Texture, TextureID> &resourceManager, const sf::Font &font, DialogMap &dialogMap)
    : m_sceneSprite(resourceManager.get(TextureID::scene))
    , m_stickmanSprite(resourceManager.get(TextureID::stickman))
    , font(font)
    , m_dialogMap(dialogMap)
{
    this->m_dialogBox = std::make_unique<Components::DialogBox>(this->m_dialogMap[{1, ChoiceState::None}], this->font);
    sf::FloatRect bounds = this->m_stickmanSprite->getLocalBounds();
    this->m_stickmanSprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    bounds = this->m_sceneSprite->getLocalBounds();
    this->m_sceneSprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    this->m_dialogBox->setOrigin({this->m_dialogBox->getSizeRectangle().x / 2.f, this->m_dialogBox->getSizeRectangle().y / 2.f});
}

void Scene::update(Application &application, sf::Time delta)
{
    this->m_stickmanSprite->setPosition({application.getWindow().getSize().x / 2.f, 100.f});
    this->m_sceneSprite->setPosition({application.getWindow().getSize().x / 2.f, 300.f});
    this->m_dialogBox->setPosition({application.getWindow().getSize().x / 2.f, 600.f});
    if (this->m_dialogBox)
    {
        this->m_dialogBox->update(delta);
        this->m_dialogBox->setListText(this->m_dialogMap[{this->m_currentStep, this->m_currentChoiceState}]);
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
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (this->m_sceneSprite)
    {
        target.draw(*this->m_sceneSprite, states);
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