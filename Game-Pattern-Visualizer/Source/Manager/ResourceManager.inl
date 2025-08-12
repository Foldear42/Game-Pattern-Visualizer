/**
 * @ Author: Foldear
 * @ Filename: ResourceManager.inl
 * @ Modified time: 2025-07-09 18:09:52
 * @ Description: Templates for the ResourceManager
 */

namespace GPV
{

template <typename Resource, typename Identifier>

void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string &filename)
{
    std::unique_ptr<Resource> resource = std::make_unique<Resource>();
    if constexpr (std::is_same_v<Resource, sf::Font>)
    {
        resource->openFromFile(filename);
    }
    else
    {
        resource->loadFromFile(filename);
    }

    auto inserted = m_resourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template <typename Resource, typename Identifier>

Resource &ResourceManager<Resource, Identifier>::get(Identifier id)
{
    auto found = m_resourceMap.find(id);
    assert(found != m_resourceMap.end());

    return *found->second;
}

template <typename Resource, typename Identifier>

const Resource &ResourceManager<Resource, Identifier>::get(Identifier id) const
{
    auto found = m_resourceMap.find(id);
    assert(found != m_resourceMap.end());
    return *found->second;
}

} // namespace GPV