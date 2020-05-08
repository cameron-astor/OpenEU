#include "LoadingState.h"
#include <Managers/StateManager.h>

namespace BW {

    LoadingState::LoadingState(const sf::RenderWindow& window, StateManager *sm):
        sm(sm),
        m_SceneRoot(),
        m_Background(sm->m_Textures.get("assets/gfx/textures/loadingscreens/loading_screen.png")),
        m_Text("Loading"),
        m_ld(sm->m_Textures, sm->m_Fonts)
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
            sm->setState("Menu");
        }
    }

    void LoadingState::buildScene()
    {
        // TODO: improve state manager api so that this call just has to be "sm->getFont( ... ):"
        m_Text.setFont(sm->m_Fonts.get("assets/gfx/fonts/arial.ttf"));
        m_Text.setPosition(500.f, 600.f);

        m_SceneRoot.attachChild(&m_Background);
        m_SceneRoot.attachChild(&m_Text);
    }

}
