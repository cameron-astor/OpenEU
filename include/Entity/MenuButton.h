#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <Engine/Entity.h>
#include <AssetWarehouse.h>
#include <SFML/Graphics.hpp>

namespace BW {

    class MenuButton : public Entity
    {
        public:
            explicit MenuButton(sf::String text, sf::Font font, sf::Texture texture);
            virtual ~MenuButton();
            virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

        private:
            sf::Font m_Font; // text font
            sf::Text m_Text; // text of the button
            sf::Sprite m_Sprite; // button sprite


    };

}

#endif // MENUBUTTON_H
