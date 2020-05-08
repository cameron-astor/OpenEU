#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <SFML/Graphics.hpp>
#include <Engine/GameState.h>
#include <States/MenuState.h>
#include <States/LoadingState.h>
#include <States/MapState.h>
#include <States/DefaultState.h>
#include <Engine/CommandQueue.h>

namespace BW {

/**
* Manages storing and switching between the game's states.
* States are not saved when swapped (i.e. a new instance is created upon switching)
*
*/

/* TODO
    - Perhaps replace bloated constructor parameters with set() functions (nvm gonna make asset warehouse)
    - Replace string state assignment with an enum of possible states
*/

class StateManager
{
    public:

        StateManager(const sf::RenderWindow& window, TextureManager& tptr, FontManager& fptr, CommandQueue& cq);
        virtual ~StateManager();

        /* Returns a pointer to the
           current state */
        GameState* getCurrentState();

        /* Sets the current state to a new instance of
           the requested state. Deletes the previous state. */
        void setState(sf::String state);

    public:
        // References to resource managers
        TextureManager& m_Textures;
        FontManager& m_Fonts;
        // Audio
        // etc

        // Reference to command queue
        CommandQueue& m_CQueue;

    private:
        // Pointer to the current game state
        GameState *currentState;

        // Reference to the render window

        // TODO convert to reference
        const sf::RenderWindow *m_Window;

};

}

#endif // STATEMANAGER_H
