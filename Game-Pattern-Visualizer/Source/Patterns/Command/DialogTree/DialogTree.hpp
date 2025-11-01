#ifndef DIALOGTREE_HPP
#define DIALOGTREE_HPP

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <vector>

#include "ChoiceState.hpp"
#include "Enums/TextureID.hpp"

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
    const TextureID stringToTextureID(const std::string str) const;

   public:
    DialogTree(std::string fileName);
    const std::vector<std::string> getListDialogByState(int step, ChoiceState state) const;
    const TextureID getAnimationSpriteIDByState(int step, ChoiceState state) const;
};

}  // namespace GPV
#endif