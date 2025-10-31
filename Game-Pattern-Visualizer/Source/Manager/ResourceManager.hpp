#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

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

using TextureManager = ResourceManager<sf::Texture, TextureID>;
using FontManager = ResourceManager<sf::Font, FontID>;

} // namespace GPV
#include "ResourceManager.inl"
#endif