#include "ScoreBoard.hpp"

namespace GPV
{

ScoreBoard::ScoreBoard(const Context &context)
    : m_textBox("Score : ", context.textureManager.get(TextureID::wideButtonBackground),
                context.fontManager.get(FontID::Arial))
{
    // Set position
    m_textBox.setPosition({200.f, 200.f});
}

void ScoreBoard::onNotify()
{
    std::cout << "Coucou" << std::endl;
    m_totalScore += 1;
    m_textBox.updateString(std::to_string(m_totalScore));
}

void ScoreBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_textBox, states);
}
}  // namespace GPV