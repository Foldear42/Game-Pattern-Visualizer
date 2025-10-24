
/**
 * @ Author: Foldear
 * @ Modified time: 2025-10-24 14:47:31
 * @ Modified time: 2025-10-24 14:54:56
 * @ Description:
 */

#ifndef DIALOGTREE_HPP
#define DIALOGTREE_HPP

#include "ChoiceState.hpp"
#include "Enums/TextureID.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <vector>

namespace GPV
{

NLOHMANN_JSON_SERIALIZE_ENUM(ChoiceState, {{ChoiceState::None, "None"}, {ChoiceState::Yes, "Yes"}, {ChoiceState::No, "No"}});

struct Choice
{
    ChoiceState choiceState;
    std::string spritePath;
    std::vector<std::string> listDialog;
};

class DialogTree
{
    std::map<int, std::vector<Choice>> m_map;

  public:
    DialogTree(std::string fileName);
    TextureID stringToTextureID(const std::string str);
    std::vector<std::string> getListDialogByState(int step, ChoiceState state);
    TextureID getAnimationSpriteIDByState(int step, ChoiceState state);
};

} // namespace GPV
#endif