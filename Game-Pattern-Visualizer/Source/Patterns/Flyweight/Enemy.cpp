/**
 * @ Author: Foldear
 * @ Filename: Enemy.cpp
 * @ Modified time: 2025-07-06 14:20:59
 * @ Description:
 */

#ifndef ENEMY_CPP
#define ENEMY_CPP

#include "Enemy.hpp"

namespace GPV
{
Enemy::Enemy(sf::Vector2f position, EnemyType enemyType) : m_position(position), m_enemyType(enemyType) {}
} // namespace GPV

#endif