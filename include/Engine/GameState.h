#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <Engine/SceneNode.h>
#include <Engine/SpriteNode.h>
#include <Engine/TextNode.h>
#include <Managers/AssetManager.h>
#include <memory>
#include <map>

namespace BW {

/** An interface for game states
*   (roughly equivalent to a 'scene' in Unity, for instance)
*/

class GameState : public sf::Drawable, private sf::NonCopyable
{
    public:

        virtual ~GameState();

        /* Update game logic */
        virtual void update(sf::Time dt) = 0;

        /* Simply draw the scene graph root node */
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

        /* Set up the scene graph */
        virtual void buildScene() = 0;

};

}

#endif // GAMESTATE_H
