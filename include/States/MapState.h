#ifndef MAPSTATE_H
#define MAPSTATE_H

#include <Engine/GameState.h>
#include <Managers/TextureManager.h>

namespace BW {

class StateManager; // forward declaration

class MapState : public GameState
{
    public:
        MapState(const sf::RenderWindow& window, StateManager *sm);
        virtual ~MapState();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {

        }
        virtual void update(sf::Time dt);
        virtual void buildScene();


    private:
        // Reference to state manager parent
        StateManager *m_SM;

};

}

#endif // MAPSTATE_H
