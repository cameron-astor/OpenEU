#ifndef MAPSTATE_H
#define MAPSTATE_H

#include <Engine/GameState.h>
#include <Managers/TextureManager.h>

namespace BW {

class StateManager; // forward declaration

class MapState : public GameState
{
    public:
        MapState(const sf::RenderWindow& window, StateManager* sm);
        virtual ~MapState();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(m_SceneRoot);
        }
        virtual void update(sf::Time dt);
        virtual void buildScene();
        virtual void handleInput(sf::Time dt);


    private:
        // Reference to state manager parent
        StateManager *m_StateManager;

        SceneNode m_SceneRoot;

        // Map
        SpriteNode m_Map;

};

}

#endif // MAPSTATE_H
