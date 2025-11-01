#include "SceneFlyweightPattern.hpp"

namespace GPV
{
SceneFlyweightPattern::SceneFlyweightPattern(const TextureManager &textureManager)
    : textureManager(textureManager),
      m_waterTerrain(textureManager.get(TextureID::waterterrain)),
      m_grassTerrain(textureManager.get(TextureID::grassterrain)),
      m_dirtTerrain(textureManager.get(TextureID::dirtterrain))
{
    generateMap();
}
void SceneFlyweightPattern::update(Application &application, sf::Time delta)
{
}
void SceneFlyweightPattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (int x = 0; x < ROWS; x++)
    {
        for (int y = 0; y < COLS; y++)
        {
            m_map[x][y]->SetPosition(sf::Vector2f(x * 16, y * 16));
            target.draw(*m_map[x][y], states);
        }
    }
}

void SceneFlyweightPattern::generateMap()
{
    for (int x = 0; x < ROWS; x++)
    {
        for (int y = 0; y < COLS; y++)
        {
            if ((rand() % 10) == 0)
            {
                m_map[x][y] = &m_dirtTerrain;
            }
            else
            {
                m_map[x][y] = &m_grassTerrain;
            }
        }
    }
    int x = rand() % COLS;
    for (int y = 0; y < ROWS; y++)
    {
        m_map[x][y] = &m_waterTerrain;
    }
}

}  // namespace GPV