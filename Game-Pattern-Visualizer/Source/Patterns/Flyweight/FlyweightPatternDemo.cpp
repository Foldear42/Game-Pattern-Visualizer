#include "FlyweightPatternDemo.hpp"

namespace GPV
{
FlyweightPatternDemo::FlyweightPatternDemo(const Context &context)
    : ApplicationState(context),
      m_waterTerrain(context.textureManager.get(TextureID::waterterrain)),
      m_grassTerrain(context.textureManager.get(TextureID::grassterrain)),
      m_dirtTerrain(context.textureManager.get(TextureID::dirtterrain)),
      m_textBox("Start", context.textureManager.get(TextureID::wideButtonBackground), context.fontManager.get(FontID::Arial))
{
    m_textBox.setPosition({1500.f, 200.f});
    // Get the size of one of the tile to determine the cell size
    sf::Vector2f cellSize = m_waterTerrain.getSpriteGlobalBounds().size;
    // Numbers of cols and rows
    m_cols = m_containerSize.x / cellSize.x;
    m_rows = m_containerSize.y / cellSize.y;
    generateMap(m_rows, m_cols);
}

void FlyweightPatternDemo::handleEvent(Application &application, const std::optional<sf::Event> &event)
{
    // relative to the window
    sf::Vector2i mouseLocalPosition = sf::Mouse::getPosition(application.getWindow());
    // relative to the "world"
    sf::Vector2f mousePosView = application.getWindow().mapPixelToCoords(mouseLocalPosition);

    auto gridX = static_cast<int>((mousePosView.x - m_containerPosition.x) / 16.f);
    auto gridY = static_cast<int>((mousePosView.y - m_containerPosition.y) / 16.f);

    if (event->getIf<sf::Event::MouseButtonPressed>())
    {
        if ((mousePosView.x >= m_containerPosition.x) && (mousePosView.y >= m_containerPosition.y))
        {
            m_textBox.updateString(m_vecExtrinsicStates[gridX][gridY].getInfos());
        }
    }
}

void FlyweightPatternDemo::update(Application &application, sf::Time delta)
{
}

void FlyweightPatternDemo::render(sf::RenderWindow &window)
{
    for (int x = 0; x < m_rows; x++)
    {
        for (int y = 0; y < m_cols; y++)
        {
            window.draw(m_vecExtrinsicStates[x][y]);
        }
    }
    window.draw(m_textBox);
}

void FlyweightPatternDemo::generateMap(int rows, int cols)
{
    for (int x = 0; x < rows; x++)
    {
        m_vecExtrinsicStates.emplace_back(std::vector<TerrainExtrinsic>());
        for (int y = 0; y < cols; y++)
        {
            if ((rand() % 10) == 0)
            {
                m_vecExtrinsicStates[x].emplace_back(m_dirtTerrain);
            }
            else
            {
                m_vecExtrinsicStates[x].emplace_back(m_grassTerrain);
            }
            m_vecExtrinsicStates[x][y].setPosition(sf::Vector2f(m_containerPosition.x + (x * 16), m_containerPosition.y + (y * 16)));
        }
    }
}

}  // namespace GPV