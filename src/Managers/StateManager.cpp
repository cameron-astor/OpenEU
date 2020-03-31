#include "StateManager.h"

namespace BW {

    StateManager::StateManager(const sf::RenderWindow& window, TextureManager* tptr, FontManager* fptr):
        m_Textures(tptr), m_Fonts(fptr),
        m_Window(&window)
    {
        currentState = new DefaultState;
    }

    StateManager::~StateManager()
    {
        //dtor
    }

    GameState* StateManager::getCurrentState()
    {
        return currentState;
    }

    void StateManager::setState(sf::String state)
    {
        delete currentState;
        if (state == "Default")
            currentState = new DefaultState;
        else if (state == "Loading")
            currentState = new LoadingState(*m_Window, this);
    }

}
