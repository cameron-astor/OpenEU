#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <Managers/AssetManager.h>

namespace BW {

    class FontManager : public AssetManager
    {
        public:
            FontManager();
            virtual ~FontManager();

            virtual bool load(const std::string& filename);
            virtual bool loadAll();

            /* Retrieves the loaded font using the original filename */
            std::shared_ptr<sf::Font> get(std::string filename) const;

        private:

            /* filename is the key, font pointer is the value. */
            std::map<std::string, std::shared_ptr<sf::Font>> m_FontMap;

    };

}

#endif // FONTMANAGER_H
