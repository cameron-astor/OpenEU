#include "StateManager.h"

namespace BW {

    StateManager::StateManager(const sf::RenderWindow& window, AssetWarehouse& assets, CommandQueue& cq):
        m_Assets(assets), m_CQueue(cq),
        m_Window(&window)
    {
        m_CurrentState = new DefaultState;
        m_CurrentStateName = "Default";
    }

    StateManager::~StateManager()
    {

    }

    GameState* StateManager::getCurrentState()
    {
        return m_CurrentState;
    }

    void StateManager::setState(sf::String state)
    {
        delete m_CurrentState;
        if (state == "Default")
            m_CurrentState = new DefaultState;
        else if (state == "Loading")
            m_CurrentState = new LoadingState(*m_Window, this);
        else if (state == "Menu")
            m_CurrentState = new MenuState(*m_Window, this);
        else if (state == "Map")
            m_CurrentState = new MapState(*m_Window, this);
        m_CurrentStateName = state;
    }

    sf::String StateManager::getCurrentStateName()
    {
        return m_CurrentStateName;
    }


}
