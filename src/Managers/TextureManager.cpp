#include "TextureManager.h"

namespace BW {

    TextureManager::TextureManager():m_TextureMap() { }

    TextureManager::~TextureManager() { }

    bool TextureManager::load(const std::string& filename)
    {
        std::shared_ptr<sf::Texture> ptr(new sf::Texture());
        if (!ptr->loadFromFile(filename)) // load texture from file
        {
            return false;
        }

        std::filesystem::path p(filename);
        std::string newFilename = p.filename().string();
        m_TextureMap[newFilename] = ptr; // insert into map

        std::cout << "Loaded: " << filename << std::endl; // debug

        return true;
    }

    bool TextureManager::loadAll()
    {
        std::filesystem::path p("assets/gfx/textures");
        for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(p)) {
            if (!std::filesystem::is_directory(dirEntry)) {
                auto filename = dirEntry.path().filename();
                this->load(dirEntry.path().string());
            }
        }
        return true;
    }

    std::shared_ptr<sf::Texture> TextureManager::get(std::string filename) const
    {
        auto it = m_TextureMap.find(filename);
        if (it != m_TextureMap.end())
            return it->second;
        else
            throw std::invalid_argument("invalid texture");
    }

    void TextureManager::printDiagnostics()
    {
        for(auto it = m_TextureMap.cbegin(); it != m_TextureMap.cend(); ++it)
        {
            std::cout << "diagnostics: " << it->first << "\n";
        }
    }

}
