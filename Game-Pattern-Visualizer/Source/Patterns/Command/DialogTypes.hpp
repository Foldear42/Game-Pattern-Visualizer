/**
 * @ Author: Foldear
 * @ Filename: DialogTypes.hpp
 * @ Modified time: 2025-05-27 11:44:02
 * @ Description:
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

namespace GPV
{

enum class ChoiceState
{
    None,
    Yes,
    No
};

using DialogMap = std::map<std::pair<int, ChoiceState>, std::vector<sf::String>>;

} // namespace GPV