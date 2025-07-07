/**
 * @ Author: Foldear
 * @ Filename: SceneFlyweightPattern.cpp
 * @ Modified time: 2025-07-06 10:29:25
 * @ Description:
 */

#include "SceneFlyweightPattern.hpp"

namespace GPV
{
SceneFlyweightPattern::SceneFlyweightPattern()
{
    m_rectShape.setSize({100.f, 100.f});
}
void SceneFlyweightPattern::update(Application &application, sf::Time delta) {}
void SceneFlyweightPattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_rectShape, states);
}
} // namespace GPV