#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <memory>
#include <exception>

//DEBUG
#include <iostream>

namespace BW {

/* Interface for classes which load heavyweight graphical and audio assets
   from disk and keep track of them for use during runtime. */

class AssetManager
{
    public:
        AssetManager();
        virtual ~AssetManager();

        /* Loads a single asset from the
           specified file path.
           Returns true if operation is successful. */
        virtual bool load(const std::string& filename) = 0;

        /* Loads all assets of its particular type */
        virtual bool loadAll() = 0;


    private:


};

}

#endif // ASSETMANAGER_H
