#include "StateManager.h"

namespace BW {

    StateManager::StateManager(const sf::RenderWindow& window, TextureManager* tptr, FontManager* fptr):
        m_Textures(tptr), m_Fonts(fptr),
        states(), stateIndex(0), m_Window(&window), m_Default(),
        m_LoadingState(window, this)
    {
        // GameState *ptr = &m_Default;
        GameState* loadingPtr = &m_LoadingState;
        states.push_back(loadingPtr);
    }

    StateManager::~StateManager()
    {
        //dtor
    }

    GameState* StateManager::getCurrentState()
    {
        return states[stateIndex];
    }

    void StateManager::setState(sf::String state)
    {

    }

}
