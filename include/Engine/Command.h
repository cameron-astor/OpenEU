#ifndef COMMAND_H
#define COMMAND_H

/* A command for use in the engine messaging system. */

#include <SFML/System/Time.hpp>
#include <functional>

namespace BW {

    class SceneNode;

    // Enumeration of possible command types, based on type of scene graph object.
    enum Category {
        None  = 0,
        Scene = 1 << 0
    };

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

    // Adapter to prevent excessive downcasting of SceneNode to lower forms.
    // Takes a function
    template <typename GameObject, typename Function>
    std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
    {
        return [=] (SceneNode& node, sf::Time dt)
        {
        // Check if cast is safe
        assert(dynamic_cast<GameObject*>(&node) != nullptr);
        // Downcast node and invoke function on it
        fn(static_cast<GameObject&>(node), dt);
        };
    }

}

#endif
