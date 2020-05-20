#include "Engine/Game.h"

namespace BW {

    Game::Game():DEFAULT_TITLE("Brainwerk Engine"), // title of window (in absence of definition)
                     m_Window(sf::VideoMode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, DEFAULT_VIDEO_BPP), DEFAULT_TITLE), rs(), m_isInFocus(true),
                     counter(), timePerUpdateTick(sf::seconds(1.f/60.f)), // 60hz
                     // m_Textures(), m_Fonts(), // initialize asset managers
                     m_Assets(),
                     m_CQueue(), // initialize command queue
                     m_States(m_Window, m_Assets, m_CQueue), // state manager reference (to be assigned in initialization)
                     m_Player(m_States)
    {
        m_Window.setFramerateLimit(FRAMERATE_LIMIT); // Limit rendering fps
        m_Window.setKeyRepeatEnabled(false);
    }

    Game::~Game()
    {

    }

    void Game::run()
    {
        // initialization procedure

        loadFirstResources(); // load resources necessary for loading screen

        m_States.setState("Loading"); // loading screen (during which resources are loaded)

        gameLoop(); // start the game loop

        // shutdown procedure goes here
    }

    void Game::gameLoop()
    {
        sf::Clock updateClock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;

        while (m_Window.isOpen())
        {
            counter.startCounter(); // fps counter

            timeSinceLastUpdate += updateClock.restart();
            while (timeSinceLastUpdate > timePerUpdateTick)
            {
                timeSinceLastUpdate -= timePerUpdateTick;
                processEvents();
                update();
            }
            render();

            counter.stopAndPost(); // fps counter
        }
    }


    void Game::processEvents()
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            m_Player.handleEvent(event, m_CQueue);

            switch (event.type)
            {
                case sf::Event::Closed:
                    m_Window.close();
                    break;
                case sf::Event::Resized: // So it doesn't stretch when resized
                    m_Window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                    break;
                case sf::Event::GainedFocus: // user selects app window in OS
                    m_isInFocus = true;
                    break;
                case sf::Event::LostFocus: // user deselects app window
                    m_isInFocus = false;
                    break;
            }

            m_Player.handleRealtimeInput(m_CQueue);
        }
    }

    void Game::update()
    {
        m_States.getCurrentState()->update(timePerUpdateTick); // update current state
    }

    void Game::render()
    {
        m_Window.clear();
        m_States.getCurrentState()->draw(m_Window, rs); // draw the current state
        m_Window.draw(*counter.getFpsCounter()); // draw fps counter
        m_Window.display();
    }

    // INITIALIZATION FUNCTIONS
    void Game::loadFirstResources()
    {
        /* Loading screen resources*/
        m_Assets.loadTexture("assets/init_resources/loading_screen.png");
        m_Assets.loadFont("assets/init_resources/Px437_IBM_BIOS.ttf");
        m_Assets.loadFont("assets/init_resources/arial.ttf");
    }


}
