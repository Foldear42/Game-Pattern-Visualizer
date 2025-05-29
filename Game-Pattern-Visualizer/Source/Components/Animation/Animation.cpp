/**
 * @ Author: Foldear
 * @ Filename: Animation.cpp
 * @ Modified time: 2025-05-29 13:30:47
 * @ Description:
 */

#include "Animation.hpp"

namespace GPV::Components
{

Animation::Animation(std::optional<sf::Sprite> sprite, int framesX, int framesY, sf::Time frameTime, int row)
    : m_sprite(sprite)
    , m_numFrames(framesX * framesY)
    , m_frameTime(frameTime)
    , m_frameTimeLeft(frameTime)
    , m_elaspedTime(sf::Time::Zero)
    , m_currentFrameIndex(0)
    , m_active(true)
{
    auto frameWidth = m_sprite->getTexture().getSize().x / framesX;
    auto frameHeight = m_sprite->getTexture().getSize().y / framesY;
    for (size_t y = 0; y < framesY; y++)
    {
        for (size_t x = 0; x < framesX; x++)
        {
            sf::IntRect frameDimension = sf::IntRect({x * frameWidth, y * frameHeight}, {frameWidth, frameHeight});
            this->m_sourceRectangles.emplace_back(frameDimension);
        }
    }

    if (!m_sourceRectangles.empty())
    {
        m_sprite->setTextureRect(m_sourceRectangles[0]);
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
}

void Animation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
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