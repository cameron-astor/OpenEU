#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window/Event.hpp>
#include <Engine/CommandQueue.h>
#include <map>

// debug
#include <iostream>

namespace BW {

    class Player
    {
        public:
            // A list of abstract actions. Things that the player can do (ignorant of implementation)
            enum Action
            {
                ScrollRight,
                ScrollLeft,
                ScrollUp,
                ScrollDown
            };

        public:
            Player();
            virtual ~Player();

            void handleEvent(const sf::Event& event, CommandQueue* cq);
            void handleRealtimeInput(CommandQueue* cq);

        private:

            // Maps a key to an abstract action (see enum Action above)
            std::map<sf::Keyboard::Key, Action> m_KeyBinding;

            // Maps an abstract action to a concrete command to be sent to the command queue
            std::map<Action, Command> m_ActionBinding;
    };

}

#endif // PLAYER_H
