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
            explicit TextNode(sf::String text);
            virtual ~TextNode();
            void setPosition(float x, float y);
            void setText(sf::String text);
            void setFont(std::shared_ptr<sf::Font> f);

        private:
            virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
            sf::Text m_Text;

    };

}

#endif // TEXTNODE_H
