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
        // convert window pointer to reference
*/

class StateManager
{
    public:

        StateManager(const sf::RenderWindow& window, AssetWarehouse& assets, CommandQueue& cq);
        virtual ~StateManager();

        /* Returns a pointer to the
           current state */
        GameState* getCurrentState();

        /* Sets the current state to a new instance of
           the requested state. Deletes the previous state. */
        void setState(sf::String state);

        /* Returns the name of the currently active state
           as an sf::String */
        sf::String getCurrentStateName();

    public:

        // Reference to asset managers
        AssetWarehouse& m_Assets;

        // Reference to command queue
        CommandQueue& m_CQueue;

    private:
        // Pointer to the current game state
        GameState *m_CurrentState;

        // Name of current state
        sf::String m_CurrentStateName;

        // Reference to the render window

        const sf::RenderWindow *m_Window;

};

}

#endif // STATEMANAGER_H
