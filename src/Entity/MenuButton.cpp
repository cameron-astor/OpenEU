#include "MenuButton.h"

namespace BW {

    MenuButton::MenuButton(sf::String text, const TextureManager& textures):
        m_Font(), m_Text()
    {
        if (m_Font.loadFromFile("assets/init_resources/Px437_IBM_BIOS.ttf")) { // setup text (refactor once font manager is created)
            m_Text.setFont(m_Font);
            m_Text.setCharacterSize(8);
            m_Text.setColor(sf::Color::Black);
            m_Text.setStyle(sf::Text::Regular);
            m_Text.setString(text);
            m_Text.setPosition(0.f, 0.f);
        }

        m_Sprite.setTexture(*textures.get("menu_button.png")); // setup sprite

        // Align sprite transform axis to center (make this operation available to all entities at some point)
        sf::FloatRect bounds = m_Sprite.getLocalBounds();
        m_Sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
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
