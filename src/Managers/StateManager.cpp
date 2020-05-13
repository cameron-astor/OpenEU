#include "StateManager.h"

namespace BW {

    StateManager::StateManager(const sf::RenderWindow& window, AssetWarehouse& assets, CommandQueue& cq):
        m_Assets(assets), m_CQueue(cq),
        m_Window(&window)
    {
        currentState = new DefaultState;
    }

    StateManager::~StateManager()
    {

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
        else if (state == "Menu")
            currentState = new MenuState(*m_Window, this);
        else if (state == "Map")
            currentState = new MapState(*m_Window, this);
    }

}
