#include "MenuState.h"

namespace BW {

    MenuState::MenuState(const sf::RenderWindow& window, TextureManager& textures):
        m_Textures(&textures),

        // scene objects
        m_Background(*textures.get("assets/gfx/textures/main_menu/frontend_backdrop.png")),
        m_SinglePlayer("Single Player", textures),
        m_Options("Options", textures),
        m_Fuck("Fuck", textures)

    {
        buildScene();
    }

    MenuState::~MenuState()
    {
        //dtor
    }

    void MenuState::update(sf::Time dt)
    {

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
}
