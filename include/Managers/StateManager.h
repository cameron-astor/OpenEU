#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <Managers/Manager.h>
#include <Engine/GameState.h>
#include <States/MenuState.h>
#include <States/LoadingState.h>
#include <States/MapState.h>
#include <States/DefaultState.h>

namespace BW {

/**
* Manages storing and switching between the game's states.
* States are not saved when swapped (i.e. a new instance is created upon switching)
*
* @param the window on which to render, various resource managers
*/

/* TODO
    - use a stack instead of a vector
*/

class StateManager : public Manager
{
    public:

        StateManager(const sf::RenderWindow& window, TextureManager* tptr, FontManager* fptr);
        virtual ~StateManager();

        /* Returns a pointer to the
           current state */
        GameState* getCurrentState();

        /* Sets the current state to a new instance of
           the requested state. Deletes the previous state. */
        void setState(sf::String state);

        // References to resource managers
        TextureManager *m_Textures;
        FontManager *m_Fonts;
        // Audio
        // etc

    private:
        // Pointer to the current game state
        GameState *currentState;

        // Reference to the render window
        const sf::RenderWindow *m_Window;


};

}

#endif // STATEMANAGER_H
