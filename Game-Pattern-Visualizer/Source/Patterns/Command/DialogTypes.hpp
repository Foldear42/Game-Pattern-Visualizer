/**
 * @ Author: Foldear
 * @ Filename: DialogTypes.hpp
 * @ Modified time: 2025-06-30 11:07:30
 * @ Description:
 */

#pragma once

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

} // namespace GPV