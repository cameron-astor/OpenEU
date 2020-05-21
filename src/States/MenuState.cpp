#include "MenuState.h"
#include <Managers/StateManager.h>

namespace BW {

    MenuState::MenuState(const sf::RenderWindow& window, StateManager *sm):
        m_Window(window),
        m_SM(sm),
//        // scene objects
        m_Background(m_SM->m_Assets.getTexture("menu_background.png"))
//
//        m_SinglePlayer(
//                       "Single Player",
//                       *m_SM->m_Assets.getFont("arial.ttf"),
//                       *m_SM->m_Assets.getTexture("menu_button.png")
//        ),
//        m_Options("Options",
//                  *m_SM->m_Assets.getFont("arial.ttf"),
//                  *m_SM->m_Assets.getTexture("menu_button.png")
//        ),
//        m_Fuck(
//               "Fuck",
//                *m_SM->m_Assets.getFont("arial.ttf"),
//                *m_SM->m_Assets.getTexture("menu_button.png")
//        )

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
//       m_SinglePlayer.setPosition(700.f, 400.f);
//       m_Options.setPosition(700.f, 600.f);
//       m_Fuck.setPosition(700.f, 800.f);

       m_SceneRoot.attachChild(&m_Background);
//       m_SceneRoot.attachChild(&m_SinglePlayer);
//       m_SceneRoot.attachChild(&m_Options);
//       m_SceneRoot.attachChild(&m_Fuck);
    }

    void MenuState::handleInput(sf::Time dt)
    {
        while (!m_SM->m_CQueue.isEmpty())
        {
            m_SceneRoot.onCommand(m_SM->m_CQueue.pop(), dt);
        }
    }

}
