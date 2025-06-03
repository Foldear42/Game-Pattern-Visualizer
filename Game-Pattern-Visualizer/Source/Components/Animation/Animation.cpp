/**
 * @ Author: Foldear
 * @ Filename: Animation.cpp
 * @ Modified time: 2025-06-03 10:39:52
 * @ Description:
 */

#include "Animation.hpp"

namespace GPV::Components
{

Animation::Animation(std::optional<sf::Sprite> sprite, int framesX, int framesY, sf::Time frameTime, float zoomFactor)
    : m_sprite(sprite)
    , m_numFrames(framesX * framesY)
    , m_frameTime(frameTime)
    , m_frameTimeLeft(frameTime)
    , m_elaspedTime(sf::Time::Zero)
    , m_currentFrameIndex(0)
    , m_active(true)
    , m_zoomFactorVector(zoomFactor, zoomFactor)
    , isFinished(false)
{
    int frameWidth = m_sprite->getTexture().getSize().x / framesX;
    int frameHeight = m_sprite->getTexture().getSize().y / framesY;
    for (int y = 0; y < framesY; y++)
    {
        for (int x = 0; x < framesX; x++)
        {
            sf::IntRect frameDimension = sf::IntRect({x * frameWidth, y * frameHeight}, {frameWidth, frameHeight});
            this->m_sourceRectangles.emplace_back(frameDimension);
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
    target.draw(*this->m_sprite, states);
}

void Animation::start()
{
    this->m_active = true;
}

void Animation::stop()
{
    this->m_active = false;
}

void Animation::reset()
{
    this->m_currentFrameIndex = 0;
    this->m_frameTimeLeft = m_frameTime;
}

} // namespace GPV::Components