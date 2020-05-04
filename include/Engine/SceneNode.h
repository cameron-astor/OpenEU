#ifndef SCENENODE_H
#define SCENENODE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>
#include <Engine/Command.h>

namespace BW {

/**
* Building block of the scene graph
*/

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> NodePtr;

    public:
        SceneNode();
        ~SceneNode();

        /* Attaches a node to this node as a child */
        void attachChild(NodePtr child);

        /* Detaches one of this node's children */
        NodePtr detachChild(const SceneNode& node);

        void update(sf::Time dt);

        /* Obtains the absolute transform of a node (i.e. relative to the whole world) */
        sf::Transform getWorldTransform() const;
        sf::Vector2f getWorldPosition() const;

        /* Message system functions */
        virtual unsigned int getCategory();
        void onCommand(const Command& command, sf::Time dt);

    private:
        std::vector<NodePtr> mChildren;
        SceneNode *mParent;
        virtual void updateCurrent(sf::Time dt);
        void updateChildren(sf::Time dt);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            drawCurrent(target, states);
            for (const NodePtr& child : mChildren)
            {
                child->draw(target, states);
            }
        }

        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
        {

        }

};

}

#endif // SCENENODE_H
