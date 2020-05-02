#ifndef COMMAND_H
#define COMMAND_H

/* A command for use in the engine messaging system. */

#include <Engine/Category.h>
#include <SFML/System/Time.hpp>
#include <functional>

namespace BW {

    class SceneNode;

    // A message which can be passed via the command queue to scene graph objects
    // Contains an empty function 'action' which can be replaced with whatever.
    struct Command
    {
        std::function<void(SceneNode&, sf::Time)> action;
        unsigned int                              category;

        // Constructor. Category defaults to none.
        Command():action(), category(Category::None)
        {

        }
    };

}

#endif
