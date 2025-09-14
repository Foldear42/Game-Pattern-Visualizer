/**
 * @ Author: Foldear
 * @ Filename: DialogTypes.hpp
 * @ Modified time: 2025-09-08 19:12:59
 * @ Description:
 */

#pragma once

#include "Enums/TextureID.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include <nlohmann/json.hpp>
#include <vector>

namespace GPV
{

enum class ChoiceState
{
    None,
    Yes,
    No
};

NLOHMANN_JSON_SERIALIZE_ENUM(ChoiceState, {{ChoiceState::None, "None"}, {ChoiceState::Yes, "Yes"}, {ChoiceState::No, "No"}});

struct Choice
{
    ChoiceState choiceState;
    std::string spritePath;
    std::vector<std::string> listDialog;
};

inline void from_json(const nlohmann::json &j, Choice &c)
{
    j.at("choiceState").get_to(c.choiceState);
    j.at("spritePath").get_to(c.spritePath);
    j.at("dialog").get_to(c.listDialog);
};

using DialogTree = std::map<int, std::vector<Choice>>;

inline std::vector<std::string> getListDialogByState(const DialogTree &tree, int step, ChoiceState state)
{
    auto it = tree.find(step);
    std::vector<std::string> retList = {};

    if (it != tree.end())
    {
        auto choiceIt =
            std::find_if(it->second.begin(), it->second.end(), [state](const Choice &c) { return c.choiceState == state; });

        if (choiceIt != it->second.end())
        {
            retList = choiceIt->listDialog;
        }
    }
    return retList;
}

inline TextureID stringToTextureID(const std::string str)
{
    if (str == "Animation_Yes_1.png")
        return TextureID::sceneAnimationYes1;
    else if (str == "Animation_No_1.png")
        return TextureID::sceneAnimationNo1;
    else
        return TextureID::sceneAnimationNo1;
}

inline TextureID getAnimationSpriteIDByState(const DialogTree &tree, int step, ChoiceState state)
{
    TextureID animationSpriteID;
    auto it = tree.find(step);

    if (it != tree.end())
    {
        auto choiceIt =
            std::find_if(it->second.begin(), it->second.end(), [state](const Choice &c) { return c.choiceState == state; });

        if (choiceIt != it->second.end())
        {
            animationSpriteID = stringToTextureID(choiceIt->spritePath);
            std::cout << choiceIt->spritePath << std::endl;
        }
    }

    return animationSpriteID;
}

} // namespace GPV