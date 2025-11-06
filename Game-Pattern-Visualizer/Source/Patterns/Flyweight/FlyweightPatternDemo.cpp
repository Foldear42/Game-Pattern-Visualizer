#include "FlyweightPatternDemo.hpp"

namespace GPV
{
FlyweightPatternDemo::FlyweightPatternDemo(const Context &context)
    : ApplicationState(context),
      m_waterTerrain(context.textureManager.get(TextureID::waterterrain)),
      m_grassTerrain(context.textureManager.get(TextureID::grassterrain)),
      m_dirtTerrain(context.textureManager.get(TextureID::dirtterrain))
{
    generateMap();
}
void FlyweightPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event)
{
}
void FlyweightPatternDemo::update(Application &application, sf::Time delta)
{
}
void FlyweightPatternDemo::render(sf::RenderWindow &window)
{
    for (int x = 0; x < ROWS; x++)
    {
        for (int y = 0; y < COLS; y++)
        {
            window.draw(m_vecExtrinsicStates[x][y]);
        }
    }
}

void FlyweightPatternDemo::generateMap()
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