#include "StateManager.h"

namespace BW {

    StateManager::StateManager(const sf::RenderWindow& window, TextureManager* tptr, FontManager* fptr, CommandQueue* cq):
        m_Textures(tptr), m_Fonts(fptr), m_CQueue(cq),
        m_Window(&window)
    {
        currentState = new DefaultState;
    }

    StateManager::~StateManager()
    {
        delete currentState;
    }

    GameState* StateManager::getCurrentState()
    {
        return currentState;
    }

    void StateManager::setState(sf::String state)
    {
        GameState *oldState = currentState;
        if (state == "Default")
            currentState = new DefaultState;
        else if (state == "Loading")
            currentState = new LoadingState(*m_Window, this);
        else if (state == "Menu")
            currentState = new MenuState(*m_Window, this);
        else if (state == "Map")
            currentState = new MapState(*m_Window, this);
        delete oldState;
    }

}
