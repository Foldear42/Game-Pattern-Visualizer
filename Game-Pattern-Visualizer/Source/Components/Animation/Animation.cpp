/**
 * @ Author: Foldear
 * @ Filename: Animation.cpp
 * @ Modified time: 2025-09-14 14:08:10
 * @ Description:
 */

#include "Animation.hpp"

namespace GPV::Components
{

Animation::Animation(std::optional<sf::Sprite> sprite, int framesX, int framesY, sf::Time frameTime, float zoomFactor)
    : m_sprite(sprite)
    , m_frameX(framesX)
    , m_frameY(framesY)
    , m_numFrames(framesX * framesY)
    , m_frameTime(frameTime)
    , m_frameTimeLeft(frameTime)
    , m_elaspedTime(sf::Time::Zero)
    , m_currentFrameIndex(0)
    , m_active(true)
    , m_zoomFactorVector(zoomFactor, zoomFactor)
    , isFinished(false)
{
    init();
}

void Animation::init()
{
    int frameWidth = m_sprite->getTexture().getSize().x / m_frameX;
    int frameHeight = m_sprite->getTexture().getSize().y / m_frameY;

    if (!m_sourceRectangles.empty())
    {
    }

    for (int y = 0; y < m_frameY; y++)
    {
        for (int x = 0; x < m_frameX; x++)
        {
            sf::IntRect frameDimension = sf::IntRect({x * frameWidth, y * frameHeight}, {frameWidth, frameHeight});
            m_sourceRectangles.emplace_back(frameDimension);
        }
    }
    if (!m_sourceRectangles.empty())
    {
        m_sprite->setTextureRect(m_sourceRectangles[0]);
        m_sprite->setScale(m_zoomFactorVector);
        float originX = static_cast<float>(m_sourceRectangles[0].size.x) / 2.f;
        float originY = static_cast<float>(m_sourceRectangles[0].size.y) / 2.f;
        m_sprite->setOrigin(sf::Vector2f(originX, originY));
    }
}

void Animation::update(sf::Time delta)
{
    if (!m_active || !m_sprite || m_sourceRectangles.empty())
    {
        return;
    }
    m_frameTimeLeft -= delta;

    if (m_frameTimeLeft <= sf::Time::Zero)
    {
        m_currentFrameIndex = (m_currentFrameIndex + 1) % m_numFrames;
        m_sprite->setTextureRect(m_sourceRectangles[m_currentFrameIndex]);
        m_frameTimeLeft += m_frameTime;
    }
    // Stop the animation when it reaches the last frame
    if ((m_numFrames - 1) == m_currentFrameIndex)
    {
        isFinished = true;
    }
}

void Animation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*m_sprite, states);
}

void Animation::setAnimationSprite(std::optional<sf::Sprite> &sprite)
{
    m_sprite = sprite;
    init();
}

void Animation::start()
{
    m_active = true;
}

void Animation::stop()
{
    m_active = false;
}

void Animation::reset()
{
    m_currentFrameIndex = 0;
    m_frameTimeLeft = m_frameTime;
    isFinished = false;
}

} // namespace GPV::Components