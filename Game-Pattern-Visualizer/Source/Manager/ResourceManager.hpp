/**
 * @ Author: Foldear
 * @ Filename: ResourceManager.hpp
 * @ Modified time: 2025-05-26 15:12:57
 * @ Description: Abstraction to handle resources (sprites, font...)
 */

#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "Enums/TextureID.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include <map>
#include <memory>
#include <string>

namespace GPV
{

template <typename Resource, typename Identifier>

class ResourceManager
{
    std::map<Identifier, std::unique_ptr<Resource>> m_resourceMap;

  public:
    void load(Identifier id, const std::string &filename);
    Resource &get(Identifier id);
    const Resource &get(Identifier id) const;
};

} // namespace GPV
#include "ResourceManager.inl"
#endif