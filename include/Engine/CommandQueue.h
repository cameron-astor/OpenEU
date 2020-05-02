#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <Engine/SceneNode.h>
#include <Engine/Command.h>
#include <queue>

namespace BW {

    /* A queue of Commands. Intended to be global. */

    class CommandQueue
    {
        public:
            CommandQueue();
            virtual ~CommandQueue();

            void push(const Command& command);
            Command pop();
            bool isEmpty() const;

        private:
            std::queue<Command> m_Queue;
    };

}


#endif // COMMANDQUEUE_H
