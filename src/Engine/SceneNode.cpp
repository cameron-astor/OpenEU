#include "SceneNode.h"

namespace BW {

    SceneNode::SceneNode(): mChildren(), mParent(nullptr)
    {
        //ctor
    }

    SceneNode::~SceneNode()
    {
        //dtor
    }

    void SceneNode::attachChild(NodePtr child)
    {
        child->mParent = this;
        mChildren.push_back(std::move(child));
    }

    SceneNode::NodePtr SceneNode::detachChild(const SceneNode& node)
    {
        auto found = std::find_if(mChildren.begin(), mChildren.end(),
                                  [&] (NodePtr& p) -> bool { return p.get() == &node; });

        assert(found != mChildren.end());

        NodePtr result = std::move(*found);
        result->mParent = nullptr;
        mChildren.erase(found);
        return result;
    }

    void SceneNode::update(sf::Time dt)
    {
        updateCurrent(dt);
        updateChildren(dt);
    }

    void SceneNode::updateCurrent(sf::Time dt)
    {

    }

    void SceneNode::updateChildren(sf::Time dt)
    {
            for (const NodePtr& child : mChildren)
            {
                child->update(dt);
            }
    }

    sf::Transform SceneNode::getWorldTransform() const
    {
        sf::Transform transform = sf::Transform::Identity;

        for (const SceneNode* node = this; node != nullptr; node = node->mParent)
        {
            transform = node->getTransform() * transform;
        }

        return transform;
    }


    sf::Vector2f SceneNode::getWorldPosition() const
    {

        return getWorldTransform() * sf::Vector2f();

    }

    unsigned int SceneNode::getCategory()
    {
        return Category::Scene;
    }

}


