#include "LoadingState.h"
#include <Managers/StateManager.h>

namespace BW {

    LoadingState::LoadingState(const sf::RenderWindow& window, StateManager *sm):
        sm(sm),
        m_SceneRoot(),
        m_Background(*sm->m_Textures->get("assets/gfx/textures/loadingscreens/loading_screen.png")),
        m_LoadingText(), m_Text(m_LoadingText)
    {
       buildScene();
    }

    LoadingState::~LoadingState()
    {
        //dtor
    }

    void LoadingState::update(sf::Time dt)
    {

    }

    void LoadingState::buildScene()
    {
        m_LoadingText.setFont(*sm->m_Fonts->get("assets/gfx/fonts/arial.ttf"));
        m_LoadingText.setString("Loading");
        m_Text.setPosition(500.f, 500.f);

        m_SceneRoot.attachChild(std::unique_ptr<SpriteNode>(&m_Background));
        m_SceneRoot.attachChild(std::unique_ptr<TextNode>(&m_Text));
    }

}
