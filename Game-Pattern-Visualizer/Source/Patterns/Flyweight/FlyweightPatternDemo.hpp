#ifndef FLYWEIGHT_PATTERN_DEMO_HPP
#define FLYWEIGHT_PATTERN_DEMO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "Application/Application.hpp"
#include "Interfaces/Scene.hpp"
#include "TerrainExtrinsic.hpp"
#include "TerrainIntrinsic.hpp"

namespace GPV
{
class FlyweightPatternDemo : public ApplicationState
{
    static constexpr std::size_t COLS = 100;
    static constexpr std::size_t ROWS = 100;
    TerrainIntrinsic m_waterTerrain;
    TerrainIntrinsic m_grassTerrain;
    TerrainIntrinsic m_dirtTerrain;
    std::vector<std::vector<TerrainExtrinsic>> m_vecExtrinsicStates;
    void generateMap();

   public:
    explicit FlyweightPatternDemo(const Context &context);
    virtual void handleEvent(Application &application, const std::optional<sf::Event> &event) override;
    virtual void update(Application &application, sf::Time delta) override;
    virtual void render(sf::RenderWindow &window) override;
};
}  // namespace GPV

#endif