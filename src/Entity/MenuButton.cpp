#include "MenuButton.h"

namespace BW {

    MenuButton::MenuButton(sf::String text, sf::Font font, sf::Texture texture):
        m_Font(), m_Text()
    {
        m_Text.setFont(font);
        m_Text.setCharacterSize(8);
        m_Text.setColor(sf::Color::Black);
        m_Text.setStyle(sf::Text::Regular);
        m_Text.setString(text);
        m_Text.setPosition(0.f, 0.f);

        m_Sprite.setTexture(texture); // setup sprite

        // Align sprite transform axis to center (make this operation available to all entities at some point)
        sf::FloatRect bounds = m_Sprite.getLocalBounds();
        m_Sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        // likewise for text
        sf::FloatRect tbounds = m_Text.getLocalBounds();
        m_Text.setOrigin(tbounds.width / 2.f, tbounds.height / 2.f);

    }

    MenuButton::~MenuButton()
    {
        //dtor
    }

    void MenuButton::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_Sprite, states);
        target.draw(m_Text, states);
    }

}
