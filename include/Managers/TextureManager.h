#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <Managers/AssetManager.h>
#include <SFML/Graphics/Texture.hpp>

namespace BW {

/*
    TODO:
        - Get rid of debug loading code in constructor
*/

class TextureManager : public BW::AssetManager
{
    public:
        TextureManager();
        virtual ~TextureManager();

        virtual bool load(const std::string& filename);
        virtual bool loadAll();

        /* Retrieves the loaded texture using the original filename */
        std::shared_ptr<sf::Texture> get(std::string filename) const;

        // DEBUG
        void printDiagnostics();

    private:

        /* filename is the key, texture pointer is the value. */
        std::map<std::string, std::shared_ptr<sf::Texture>> m_TextureMap;

};

}

#endif // TEXTUREMANAGER_H
