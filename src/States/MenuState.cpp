#include "MenuState.h"
#include <Managers/StateManager.h>

namespace BW {

    MenuState::MenuState(const sf::RenderWindow& window, StateManager *sm):
        m_SM(sm),
        m_Textures(sm->m_Textures),
        // scene objects
        m_Background(*m_Textures->get("assets/gfx/textures/main_menu/frontend_backdrop.png")),
        m_SinglePlayer("Single Player", *m_Textures),
        m_Options("Options", *m_Textures),
        m_Fuck("Fuck", *m_Textures)

    {
        buildScene();
    }

    MenuState::~MenuState()
    {
        //dtor
    }

    void MenuState::update(sf::Time dt)
    {
        handleInput();
    }

    void MenuState::buildScene()
    {
       // set positions
       m_SinglePlayer.setPosition(700.f, 400.f);
       m_Options.setPosition(700.f, 500.f);
       m_Fuck.setPosition(700.f, 600.f);

       m_SceneRoot.attachChild(std::unique_ptr<SpriteNode>(&m_Background));
       m_SceneRoot.attachChild(std::unique_ptr<MenuButton>(&m_SinglePlayer));
       m_SceneRoot.attachChild(std::unique_ptr<MenuButton>(&m_Options));
       m_SceneRoot.attachChild(std::unique_ptr<MenuButton>(&m_Fuck));
    }

    void MenuState::handleInput()
    {
        // keyboard controls until mouse is implemented
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            m_SM->setState("Map");

        // if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            // stuff
    }

}
