#ifndef SCENE_FLYWEIGHT_PATTERN_HPP
#define SCENE_FLYWEIGHT_PATTERN_HPP

#include "Application/Application.hpp"
#include "Interfaces/Scene.hpp"
#include "Terrain.hpp"
#include <iostream>

namespace GPV
{
class SceneFlyweightPattern : public Scene
{
    static constexpr std::size_t COLS = 100;
    static constexpr std::size_t ROWS = 100;
    const TextureManager &textureManager;
    // sf::RectangleShape m_rectShape;
    Terrain m_waterTerrain;
    Terrain m_grassTerrain;
    Terrain m_dirtTerrain;
    Terrain *m_map[COLS][ROWS];
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void generateMap();

  public:
    SceneFlyweightPattern(const TextureManager &textureManager);
    void update(Application &application, sf::Time delta) override;
};
} // namespace GPV

#endif