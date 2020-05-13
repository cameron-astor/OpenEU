#include "AssetWarehouse.h"

namespace BW {

    AssetWarehouse::AssetWarehouse():m_Textures(), m_Fonts()
    {
        //ctor
    }

    AssetWarehouse::~AssetWarehouse()
    {
        //dtor
    }

    void AssetWarehouse::loadTexture(std::string filename)
    {
        m_Textures.load(filename);
    }

    void AssetWarehouse::loadAllTextures()
    {
        m_Textures.loadAll();
    }

    void AssetWarehouse::loadFont(std::string filename)
    {
        m_Fonts.load(filename);
    }

    void AssetWarehouse::loadAllFonts()
    {
        m_Fonts.loadAll();
    }

    std::shared_ptr<sf::Texture> AssetWarehouse::getTexture(std::string filename)
    {
        return m_Textures.get(filename);
    }

    std::shared_ptr<sf::Font> AssetWarehouse::getFont(std::string filename)
    {
        return m_Fonts.get(filename);
    }


}
