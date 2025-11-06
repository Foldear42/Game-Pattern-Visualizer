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
    // relative to the window
    sf::Vector2i mouseLocalPosition = sf::Mouse::getPosition(application.getWindow());
    // relative to the "world"
    sf::Vector2f mousePosView = application.getWindow().mapPixelToCoords(mouseLocalPosition);

    // Find if there is a Terrain
}

void SceneFlyweightPattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (int x = 0; x < ROWS; x++)
    {
        for (int y = 0; y < COLS; y++)
        {
            target.draw(m_vecExtrinsicStates[x][y], states);
        }
    }
}

void SceneFlyweightPattern::generateMap()
{
    for (int x = 0; x < ROWS; x++)
    {
        m_vecExtrinsicStates.emplace_back(std::vector<TerrainExtrinsic>());
        for (int y = 0; y < COLS; y++)
        {
            if ((rand() % 10) == 0)
            {
                m_vecExtrinsicStates[x].emplace_back(m_dirtTerrain);
            }
            else
            {
                m_vecExtrinsicStates[x].emplace_back(m_grassTerrain);
            }
            m_vecExtrinsicStates[x][y].setPosition(sf::Vector2f(x * 16, y * 16));
        }
    }
    int x = rand() % ROWS;
    for (int y = 0; y < COLS; y++)
    {
        // m_vecExtrinsicStates[x][y].setTerrainIntrinsic(m_waterTerrain);
        // m_vecExtrinsicStates[x][y].setPosition(sf::Vector2f(x * 16, y * 16));
    }
}

}  // namespace GPV