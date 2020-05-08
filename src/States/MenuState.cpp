#include "MenuState.h"
#include <Managers/StateManager.h>

namespace BW {

    MenuState::MenuState(const sf::RenderWindow& window, StateManager *sm):
        m_Window(window),
        m_SM(sm),
        m_Textures(sm->m_Textures),
        // scene objects
        m_Background(m_Textures.get("assets/gfx/textures/main_menu/frontend_backdrop.png")),
        m_SinglePlayer("Single Player", m_Textures),
        m_Options("Options", m_Textures),
        m_Fuck("Fuck", m_Textures)

    {
        buildScene();
    }

    MenuState::~MenuState()
    {
        //dtor
    }

    void MenuState::update(sf::Time dt)
    {
        handleInput(dt);
    }

    void MenuState::buildScene()
    {
       // set positions
       m_SinglePlayer.setPosition(700.f, 400.f);
       m_Options.setPosition(700.f, 500.f);
       m_Fuck.setPosition(700.f, 600.f);

       m_SceneRoot.attachChild(&m_Background);
       m_SceneRoot.attachChild(&m_SinglePlayer);
       m_SceneRoot.attachChild(&m_Options);
       m_SceneRoot.attachChild(&m_Fuck);
    }

    void MenuState::handleInput(sf::Time dt)
    {
        while (!m_SM->m_CQueue.isEmpty())
        {
            m_SceneRoot.onCommand(m_SM->m_CQueue.pop(), dt);
        }
    }

}
