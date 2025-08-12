/**
 * @ Author: Foldear
 * @ Filename: Enemy.cpp
 * @ Modified time: 2025-07-07 14:40:40
 * @ Description:
 */

#ifndef ENEMY_CPP
#define ENEMY_CPP

#include "Enemy.hpp"

namespace GPV
{
Enemy::Enemy(sf::Vector2f position, EnemyType enemyType) : m_position(position), m_enemyType(enemyType) {}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {}

} // namespace GPV

#endif