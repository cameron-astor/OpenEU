#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include <Engine/GameState.h>
#include <Engine/LoadingTask.h>
#include <Managers/AssetManager.h>
#include <Managers/TextureManager.h>
#include <Managers/FontManager.h>

namespace BW {

/**
* Initial loading screen
*/

class StateManager; // forward declaration

class LoadingState : public GameState
{
    public:
        LoadingState(const sf::RenderWindow& window, StateManager *sm);
        virtual ~LoadingState();

        virtual void update(sf::Time dt);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(m_SceneRoot);
        }
        virtual void buildScene();

    private:

        // state manager parent
        StateManager *sm;

        SceneNode m_SceneRoot;

        // scene objects

        // test background
        // SpriteNode m_Background;
        // sf::Text m_LoadingText;
        // TextNode m_Text;


        // loading task (parallel thread)
        LoadingTask m_ld;


};

}

#endif // LOADINGSTATE_H
