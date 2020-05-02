#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window/Event.hpp>
#include <Engine/CommandQueue.h>

namespace BW {

    class Player
    {
        public:
            Player();
            virtual ~Player();

            void handleEvent(const sf::Event& event, CommandQueue* cq);
            void handleRealtimeInput(CommandQueue* cq);

        private:
    };

}

#endif // PLAYER_H
