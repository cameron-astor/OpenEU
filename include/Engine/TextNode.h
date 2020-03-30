#ifndef TEXTNODE_H
#define TEXTNODE_H

#include <Engine/SceneNode.h>

namespace BW {

/**
* Container for a piece of text that can be inserted into scene graph
*/

    class TextNode : public SceneNode
    {
        public:
            explicit TextNode(sf::Text& text);
            virtual ~TextNode();
            void setPosition(float x, float y);
            void setText(sf::String text);

        private:
            virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
            sf::Text *m_Text;

    };

}

#endif // TEXTNODE_H
