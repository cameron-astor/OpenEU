#include "TextNode.h"

namespace BW {

    TextNode::TextNode(sf::String text):m_Text()
    {
        m_Text.setString(text);
    }

    TextNode::~TextNode()
    {
        //dtor
    }

    void TextNode::setPosition(float x, float y)
    {
        m_Text.setPosition(x, y);
    }

    void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_Text);
    }

    void TextNode::setText(sf::String text)
    {
        m_Text.setString(text);
    }

    void TextNode::setFont(std::shared_ptr<sf::Font> f)
    {
        m_Text.setFont(*f);
    }

}
