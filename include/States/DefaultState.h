#ifndef DEFAULTSTATE_H
#define DEFAULTSTATE_H

#include <Engine/GameState.h>

namespace BW {

    /**
    * DefaultState is an empty GameState which does not require any
    * resources.
    */

    class DefaultState : public GameState
    {
        public:
            DefaultState();
            virtual ~DefaultState();


            virtual void update(sf::Time dt);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
            {

            }
            virtual void buildScene();

        private:
    };

}

#endif // DEFAULTSTATE_H
