namespace GPV
{

template <typename Resource, typename Identifier>

void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string &filename)
{
    std::unique_ptr<Resource> resource = std::make_unique<Resource>();
    
    std::string fullPath = RESOURCES_PATH + filename;
    if constexpr (std::is_same_v<Resource, sf::Font>)
    {
        resource->openFromFile(fullPath);
    }
    else
    {
        resource->loadFromFile(fullPath);
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