/**
 * @ Author: Foldear
 * @ Filename: DialogTree.cpp
 * @ Modified time: 2025-10-24 14:54:43
 * @ Description:
 */

#ifndef DIALOGTREE_CPP
#define DIALOGTREE_CPP

#include "DialogTree.hpp"

namespace GPV
{

void from_json(const nlohmann::json &j, Choice &c)
{
    j.at("choiceState").get_to(c.choiceState);
    j.at("spritePath").get_to(c.spritePath);
    j.at("dialog").get_to(c.listDialog);
};

DialogTree::DialogTree(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file)
    {
        throw std::runtime_error("error file not found");
    }
    nlohmann::json j;

    file >> j;
    for (auto &[key, value] : j.items())
    {
        int step = std::stoi(key);
        m_map[step] = value.get<std::vector<Choice>>();
    }
}

TextureID DialogTree::stringToTextureID(const std::string str)
{
    if (str == "Animation_Yes_1.png")
        return TextureID::sceneAnimationYes1;
    else if (str == "Animation_No_1.png")
        return TextureID::sceneAnimationNo1;
    else
        return TextureID::sceneAnimationNo1;
}

std::vector<std::string> DialogTree::getListDialogByState(int step, ChoiceState state)
{
    auto it = m_map.find(step);
    std::vector<std::string> retList = {};

    if (it != m_map.end())
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

TextureID DialogTree::getAnimationSpriteIDByState(int step, ChoiceState state)
{
    TextureID animationSpriteID;
    auto it = m_map.find(step);

    if (it != m_map.end())
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

#endif