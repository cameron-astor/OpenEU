#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <Engine/GameState.h>
#include <Entity/MenuButton.h>

namespace BW {

/**
* Main menu scene
*/

/* TODO
    - Fix blurry menu button fonts (maybe change font or use bitmap)
    - Fix alignment of background image
    - ensure that everything is properly scaled and aligned at different resolutions
    - custom assets (at some point)
*/

class StateManager; // forward declaration

class MenuState : public GameState
{
    public:
        MenuState(const sf::RenderWindow& window, StateManager *sm);
        virtual ~MenuState();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(m_SceneRoot);
        }
        virtual void update(sf::Time dt);

    private:
        virtual void buildScene();

        // Handle clicks on the menu buttons
        void handleInput();

        // Reference to state manager parent
        StateManager *m_SM;
        TextureManager *m_Textures;

        SceneNode m_SceneRoot;

        // Scene objects
        SpriteNode m_Background; // background sprite
        MenuButton m_SinglePlayer; // single player button
        MenuButton m_Options; // options button
        MenuButton m_Fuck;

};

}

#endif // MENUSTATE_H
