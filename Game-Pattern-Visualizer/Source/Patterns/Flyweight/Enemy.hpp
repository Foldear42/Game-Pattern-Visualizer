/**
 * @ Author: Foldear
 * @ Filename: Enemy.hpp
 * @ Modified time: 2025-07-06 14:18:53
 * @ Description:
 */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Data/EnemyType.hpp"
#include <SFML/Graphics.hpp>

namespace GPV
{
class Enemy : public sf::Drawable
{
    sf::Vector2f m_position;
    EnemyType m_enemyType;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    Enemy(sf::Vector2f position, EnemyType enemyType);
};
} // namespace GPV

#endif