#include "Player.h"

namespace BW {

    Player::Player(StateManager& sm):
        m_StateManager(sm)
    {
        // Set default keybinds
        m_KeyBinding[sf::Keyboard::Key::S] = ScrollRight;
        m_KeyBinding[sf::Keyboard::Key::A] = ScrollLeft;
        m_KeyBinding[sf::Keyboard::Key::W] = ScrollUp;
        m_KeyBinding[sf::Keyboard::Key::D] = ScrollDown;
    }

    Player::~Player()
    {
        //dtor
    }

    void Player::handleEvent(const sf::Event& event, CommandQueue& cq)
    {
        // test event
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {

            Command print; // declare command
            print.category = Category::Scene; // command category

            // lambda expression defining the function contained in the command
            print.action = [] (SceneNode& node, sf::Time dt)
            {
                std::cout << "Pressed enter" << std::endl;
            };
            cq.push(print); // add to command queue
        }

        // test scene event
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
            if (m_StateManager.getCurrentStateName() == "Menu")
                m_StateManager.setState("Map");
        }
    }

    void Player::handleRealtimeInput(CommandQueue& cq)
    {

    }

}
