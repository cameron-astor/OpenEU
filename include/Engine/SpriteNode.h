#ifndef SPRITENODE_H
#define SPRITENODE_H

#include <Engine/SceneNode.h>

namespace BW {

/**
* Container for rendering a single sprite which can be
* inserted into a scene graph.
*/

    class SpriteNode : public SceneNode
    {
        public:
            explicit SpriteNode(std::shared_ptr<sf::Texture> texture);
            SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);
            void setPosition(float x, float y);

        private:
            virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
            sf::Sprite m_Sprite;
    };

}

#endif // SPRITENODE_H
