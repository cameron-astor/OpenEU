#include "SpriteNode.h"

namespace BW {


    SpriteNode::SpriteNode(std::shared_ptr<sf::Texture> texture):m_Sprite()
    {
        m_Sprite.setTexture(*texture);
    }

    SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& rect):m_Sprite()
    {

    }

    void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_Sprite);
    }

    void SpriteNode::setPosition(float x, float y)
    {
        m_Sprite.setPosition(x, y);
    }

}
