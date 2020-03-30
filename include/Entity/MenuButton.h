#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <Engine/Entity.h>


class MenuButton : public BW::Entity
{
    public:
        explicit MenuButton(sf::String text, const BW::TextureManager& textures);
        virtual ~MenuButton();
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Font m_Font; // text font
        sf::Text m_Text; // text of the button
        sf::Sprite m_Sprite; // button sprite


};

#endif // MENUBUTTON_H
