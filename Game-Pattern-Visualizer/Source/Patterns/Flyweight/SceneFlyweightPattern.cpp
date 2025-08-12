/**
 * @ Author: Foldear
 * @ Filename: SceneFlyweightPattern.cpp
 * @ Modified time: 2025-07-07 15:26:41
 * @ Description:
 */

#include "SceneFlyweightPattern.hpp"

namespace GPV
{
SceneFlyweightPattern::SceneFlyweightPattern()
{
    m_rectShape.setSize({5.f, 5.f});
    std::cout << sizeof(sf::RectangleShape) << std::endl;
}
void SceneFlyweightPattern::update(Application &application, sf::Time delta) {}
void SceneFlyweightPattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_rectShape, states);
}
} // namespace GPV