#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <Managers/Manager.h>
#include <Engine/GameState.h>
#include <States/MenuState.h>
#include <States/LoadingState.h>
#include <States/MapState.h>
#include <States/DefaultState.h>

#include <vector>
#include <map>

namespace BW {

/* TODO
    - use a stack instead of a vector
*/

class StateManager : public Manager
{
    public:

        StateManager(const sf::RenderWindow& window, TextureManager* tptr, FontManager* fptr);
        virtual ~StateManager();

        /* Returns a pointer to the
           state at the current state index. */
        GameState* getCurrentState();

        /* Sets the current state to a new instance of
           the requested state. */
        void setState(sf::String state);

        // References to resource managers
        TextureManager *m_Textures;
        FontManager *m_Fonts;
        // Audio
        // etc

    private:
        // Container of game states
        std::vector<GameState*> states;
        // Index of current state
        unsigned int stateIndex;

        // Reference to the render window
        const sf::RenderWindow *m_Window;

        // Default state
        DefaultState m_Default;
        // Loading state
        LoadingState m_LoadingState;

};

}

#endif // STATEMANAGER_H
