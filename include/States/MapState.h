#ifndef MAPSTATE_H
#define MAPSTATE_H

#include <Engine/GameState.h>

namespace BW {

class MapState : public GameState
{
    public:
        MapState(sf::RenderWindow& window);
        virtual ~MapState();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {

        }
        virtual void update(sf::Time dt);
        virtual void buildScene();


    private:

};

}

#endif // MAPSTATE_H
