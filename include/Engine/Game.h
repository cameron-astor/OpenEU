#ifndef GAME_H
#define GAME_H

/**
* A materialist Europa Universalis (hopefully!)
*
* The Game class is the highest level interface of the application.
* It contains the rendering window, the game loop, and startup and shutdown procedures.
*/

/*
    TODO:
        - Initialization process:
            . Create resource managers
            . Add resource managers to manager map
            . Create other managers
            . Begin game loop

        - States need a way to reset themselves (or take a look at book's version of state stack)
        - Read window attributes from config file.
*/

// C++ lib
#include <map>
#include <memory>

// Engine
#include <Engine/FpsCounter.h>
#include <Engine/CommandQueue.h>
#include <Managers/Manager.h>
#include <Managers/StateManager.h>
#include <Managers/TextureManager.h>
#include <Managers/FontManager.h>
#include <States/MenuState.h>
#include <Engine/Player.h>



namespace BW { // Brainwerk Engine

class Game
{

    public:
        Game();
        ~Game();

        /*
            Initializes game, starts loop, closes game when done.
            Returns an exit code.
        */
        void run();


    private:

        /*
            Window default values (in absence of config file)
        */
        static const unsigned int DEFAULT_VIDEO_WIDTH = 800;
        static const unsigned int DEFAULT_VIDEO_HEIGHT = 600;
        static const unsigned int DEFAULT_VIDEO_BPP = 32;
        static const unsigned int FRAMERATE_LIMIT = 120;
        const sf::String DEFAULT_TITLE;

        sf::RenderWindow m_Window; // A window on which to render
        sf::RenderStates rs; // render states for window
        bool m_isInFocus; // flag for if the app window is selected in the OS

        FpsCounter counter; // FPS counter for the window

        /*
            The main game loop.
        */
        void gameLoop();

        /* Game loop components */
        sf::Time timePerUpdateTick;

        void processEvents(); // Handles window/OS events, user input
        void update(); // Updates game logic
        void render(); // Renders graphics to the window


        /* MANAGERS */

        /* Asset managers */
        TextureManager *m_Textures;
        FontManager *m_Fonts;

        /* State manager */
        StateManager *m_States;

        /* COMMAND QUEUE */
        CommandQueue *m_CQueue;

        /* PLAYER CLASS */
        Player m_Player;

        /* INITIALIZATION FUNCTIONS */

        // bootstrap loading and splash screen resources
        // This is necessary due to the fact the rest of the textures
        // are not loaded until the loading screen, which itself
        // requires resources
        void loadFirstResources();

};

}

#endif // GAME_H
