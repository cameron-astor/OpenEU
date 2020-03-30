#include "TextNode.h"

namespace BW {

    TextNode::TextNode(sf::Text& text):m_Text(&text)
    {

    }

    TextNode::~TextNode()
    {
        //dtor
    }

    void TextNode::setPosition(float x, float y)
    {
        m_Text->setPosition(x, y);
    }

    void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(*m_Text);
    }

    void TextNode::setText(sf::String text)
    {
        m_Text->setString(text);
    }

}
