#include "TextureManager.h"

namespace BW {

    TextureManager::TextureManager():m_TextureMap()
    {
        /* Test of TextureManager, to be put into loading state later */
        // this->load("assets/gfx/textures/main_menu/menu_button.png");
        // this->load("assets/gfx/textures/main_menu/frontend_backdrop.png");
    }

    TextureManager::~TextureManager()
    {
        //dtor
    }

    bool TextureManager::load(const std::string& filename)
    {
        std::shared_ptr<sf::Texture> ptr(new sf::Texture());
        if (!ptr->loadFromFile(filename)) // load texture from file
        {
            throw std::invalid_argument("file not found");
            return false;
        }

        m_TextureMap[filename] = ptr; // insert into map

        std::cout << "Loaded: " << filename << std::endl; // debug

        return true;
    }

    bool TextureManager::loadAll()
    {
        throw std::invalid_argument("not yet implemented");
        return false;
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
