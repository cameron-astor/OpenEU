#include "FontManager.h"

namespace BW {

    FontManager::FontManager():m_FontMap()
    {
        //ctor
    }

    FontManager::~FontManager()
    {
        //dtor
    }


    bool FontManager::load(const std::string& filename)
    {
        std::shared_ptr<sf::Font> ptr(new sf::Font());
        if (!ptr->loadFromFile(filename)) // attempt load font from file
        {
            return false; // return early if failed to load
        }

        std::filesystem::path p(filename);
        std::string newFilename = p.filename().string();
        m_FontMap[newFilename] = ptr; // insert into map

        std::cout << "Loaded: " << filename << std::endl; // debug

        return true;
    }

    bool FontManager::loadAll()
    {
        std::filesystem::path p("assets/gfx/fonts");
        for (const auto& entry : std::filesystem::directory_iterator(p)) {
            auto filename = entry.path().filename();
            this->load(entry.path().string());
        }
        return true;
    }

    std::shared_ptr<sf::Font> FontManager::get(std::string filename) const
    {
        auto it = m_FontMap.find(filename);
        if (it != m_FontMap.end())
            return it->second;
        else
            throw std::invalid_argument("invalid font");
    }

}
