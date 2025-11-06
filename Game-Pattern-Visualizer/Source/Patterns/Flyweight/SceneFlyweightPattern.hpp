#ifndef SCENE_FLYWEIGHT_PATTERN_HPP
#define SCENE_FLYWEIGHT_PATTERN_HPP

#include <iostream>
#include <vector>

#include "Application/Application.hpp"
#include "Interfaces/Scene.hpp"
#include "TerrainExtrinsic.hpp"
#include "TerrainIntrinsic.hpp"

namespace GPV
{
class SceneFlyweightPattern : public Scene
{
    static constexpr std::size_t COLS = 100;
    static constexpr std::size_t ROWS = 100;
    const TextureManager &textureManager;
    TerrainIntrinsic m_waterTerrain;
    TerrainIntrinsic m_grassTerrain;
    TerrainIntrinsic m_dirtTerrain;
    std::vector<std::vector<TerrainExtrinsic>> m_vecExtrinsicStates;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void generateMap();

   public:
    SceneFlyweightPattern(const TextureManager &textureManager);
    void update(Application &application, sf::Time delta) override;
};
}  // namespace GPV

#endif