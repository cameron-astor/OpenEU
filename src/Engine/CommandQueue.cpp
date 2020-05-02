#include "CommandQueue.h"

namespace BW {

    CommandQueue::CommandQueue()
    {
        //ctor
    }

    CommandQueue::~CommandQueue()
    {
        //dtor
    }

    void CommandQueue::push(const Command& command)
    {
        m_Queue.push(command);
    }

    Command CommandQueue::pop()
    {
        Command val = m_Queue.front();
        m_Queue.pop();
        return val;
    }

    bool CommandQueue::isEmpty() const
    {
        return m_Queue.empty();
    }


}

