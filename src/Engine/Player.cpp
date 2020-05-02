#include "Player.h"

namespace BW {


    // Test functor for command queue system
//    struct TestAction {
//        TestAction(int x)
//    };

    Player::Player()
    {
        //ctor
    }

    Player::~Player()
    {
        //dtor
    }

    void Player::handleEvent(const sf::Event& event, CommandQueue* cq)
    {

    }

    void Player::handleRealtimeInput(CommandQueue* cq)
    {

    }

}
