#include "MapState.h"
#include <Managers/StateManager.h>

namespace BW {

    MapState::MapState(const sf::RenderWindow& window, StateManager *sm):
        m_StateManager(sm),
        m_Map(m_StateManager->m_Assets.getTexture("test_map.png"))
    {
        buildScene();
    }

    MapState::~MapState()
    {
        //dtor
    }

    void MapState::update(sf::Time dt)
    {

    }

    void MapState::buildScene()
    {
        m_SceneRoot.attachChild(&m_Map);
    }

    void MapState::handleInput(sf::Time dt)
    {
        while (!m_StateManager->m_CQueue.isEmpty())
        {
            m_SceneRoot.onCommand(m_StateManager->m_CQueue.pop(), dt);
        }
    }

}
