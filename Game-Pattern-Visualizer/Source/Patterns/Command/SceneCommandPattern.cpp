#include "SceneCommandPattern.hpp"

namespace GPV
{

SceneCommandPattern::SceneCommandPattern(const TextureManager &textureManager, const sf::Font &font, const DialogTree &dialogTree)
    : textureManager(textureManager),
      m_stickmanSprite(textureManager.get(TextureID::stickman)),
      m_sceneAnimationSprite(textureManager.get(TextureID::sceneAnimationNo1)),
      m_sceneAnimation(m_sceneAnimationSprite, 9, 7, sf::seconds(0.1f), 4.f),
      font(font),
      m_dialogTree(dialogTree),
      m_currentStep(1),
      m_currentChoiceState(ChoiceState::None),
      m_dialogBox({""}, font)
{
    m_dialogBox.setListText(m_dialogTree.getListDialogByState(m_currentStep, m_currentChoiceState));
    sf::FloatRect bounds = m_stickmanSprite->getLocalBounds();
    m_stickmanSprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    m_dialogBox.setOrigin({m_dialogBox.getSizeRectangle().x / 2.f, m_dialogBox.getSizeRectangle().y / 2.f});
    m_dialogBox.startTypewriterAnimation();
    stopAnimation();
}

void SceneCommandPattern::update(Application &application, sf::Time delta)
{
    m_stickmanSprite->setPosition({application.getWindow().getSize().x / 2.f, 100.f});
    m_sceneAnimation.setPosition({application.getWindow().getSize().x / 2.f, 300.f});
    m_dialogBox.setPosition({application.getWindow().getSize().x / 2.f, 600.f});

    m_dialogBox.update(delta);
    m_sceneAnimation.update(delta);

    if (m_sceneAnimation.isFinished)
    {
        stopAnimation();
    }
}

void SceneCommandPattern::selectStep(int step)
{
    m_currentStep = step;
}

void SceneCommandPattern::selectChoice(ChoiceState choiceState)
{
    m_currentChoiceState = choiceState;
    m_dialogBox.resetIndexes();
    m_dialogBox.setListText(m_dialogTree.getListDialogByState(m_currentStep, m_currentChoiceState));
}

void SceneCommandPattern::resetScene()
{
    m_dialogBox.resetIndexes();
    m_sceneAnimation.reset();
}

void SceneCommandPattern::startAnimation()
{
    m_sceneAnimation.start();
    isAnimating = true;
}

void SceneCommandPattern::stopAnimation()
{
    m_sceneAnimation.stop();
    isAnimating = false;
}

void SceneCommandPattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sceneAnimation, states);
    target.draw(m_dialogBox, states);

    if (m_stickmanSprite)
    {
        target.draw(*m_stickmanSprite, states);
    }
}

void SceneCommandPattern::changeSpriteAnimation(ChoiceState choiceState)
{
    TextureID currentTextureID = m_dialogTree.getAnimationSpriteIDByState(m_currentStep, choiceState);
    m_sceneAnimationSprite->setTexture(textureManager.get(currentTextureID));
    // Set new animation
    m_sceneAnimation.setAnimationSprite(m_sceneAnimationSprite);
}
}  // namespace GPV