#ifndef FLYWEIGHT_PATTERN_DEMO_HPP
#define FLYWEIGHT_PATTERN_DEMO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "Application/Application.hpp"
#include "Components/TextBox/TextBox.hpp"
#include "Interfaces/Scene.hpp"
#include "TerrainExtrinsic.hpp"
#include "TerrainIntrinsic.hpp"

namespace GPV
{
class FlyweightPatternDemo : public ApplicationState
{
    int m_cols, m_rows;
    TerrainIntrinsic m_waterTerrain;
    TerrainIntrinsic m_grassTerrain;
    TerrainIntrinsic m_dirtTerrain;
    std::vector<std::vector<TerrainExtrinsic>> m_vecExtrinsicStates;
    sf::Vector2f m_containerSize{600.f, 1000.f};
    sf::Vector2f m_containerPosition{200.f, 200.f};
    Components::TextBox m_textBox;

    void generateMap(int rows, int cols);

   public:
    explicit FlyweightPatternDemo(const Context &context);
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
};
}  // namespace GPV

#endif