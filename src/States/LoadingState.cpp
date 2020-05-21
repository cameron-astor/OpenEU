#include "LoadingState.h"
#include <Managers/StateManager.h>

namespace BW {

    LoadingState::LoadingState(const sf::RenderWindow& window, StateManager *sm):
        sm(sm),
        m_SceneRoot(),
        m_Background(sm->m_Assets.getTexture("loading_screen.png")),
        m_Text("Loading"),
        m_ld(sm->m_Assets)
    {
       buildScene();
       m_ld.run();
    }

    LoadingState::~LoadingState()
    {

    }

    void LoadingState::update(sf::Time dt)
    {
        if (m_ld.isFinished()) {
            m_ld.joinThread();
            sm->setState("Menu");
        }
    }

    void LoadingState::buildScene()
    {
        m_Text.setFont(sm->m_Assets.getFont("arial.ttf"));
        m_Text.setPosition(500.f, 600.f);

        m_SceneRoot.attachChild(&m_Background);
        m_SceneRoot.attachChild(&m_Text);
    }

}
