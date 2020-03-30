#ifndef ENTITY_H
#define ENTITY_H

#include <Engine/SceneNode.h>
#include <Managers/TextureManager.h>

namespace BW {

/**
* An entity represents any object in the scene.
* Extends SceneNode so that it can be plugged into a
* scene graph.
*/

class Entity : public BW::SceneNode
{
    public:
        Entity();
        virtual ~Entity();

    private:
};

}

#endif // ENTITY_H
