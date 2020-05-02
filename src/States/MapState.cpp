#include "MapState.h"
#include <Managers/StateManager.h>

namespace BW {

    MapState::MapState(const sf::RenderWindow& window, StateManager *sm):
        m_SM(sm),
        m_Textures(sm->m_Textures)
    {
        //ctor
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

    }



}
