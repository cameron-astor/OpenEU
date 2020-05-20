#ifndef ASSETWAREHOUSE_H
#define ASSETWAREHOUSE_H

#include <Managers/TextureManager.h>
#include <Managers/FontManager.h>
// likewise for audio, etc.

namespace BW {

/* Holds all of the various asset managers giving controlled access to them
   from a single source. */
    class AssetWarehouse
    {
        public:
            AssetWarehouse();
            virtual ~AssetWarehouse();

            // Textures
            void loadTexture(std::string filename);
            void loadAllTextures();
            std::shared_ptr<sf::Texture> getTexture(std::string filename);

            // Fonts
            void loadFont(std::string filename);
            void loadAllFonts();
            std::shared_ptr<sf::Font> getFont(std::string filename);

        private:
            TextureManager m_Textures;
            FontManager m_Fonts;

    };

}

#endif // ASSETWAREHOUSE_H
