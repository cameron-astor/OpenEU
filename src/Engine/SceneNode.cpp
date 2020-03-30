#include "SceneNode.h"

BW::SceneNode::SceneNode(): mChildren(), mParent(nullptr)
{
    //ctor
}

BW::SceneNode::~SceneNode()
{
    //dtor
}

void BW::SceneNode::attachChild(NodePtr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

BW::SceneNode::NodePtr BW::SceneNode::detachChild(const SceneNode& node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
                              [&] (NodePtr& p) -> bool { return p.get() == &node; });

    assert(found != mChildren.end());

    NodePtr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void BW::SceneNode::update(sf::Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}

void BW::SceneNode::updateCurrent(sf::Time dt)
{

}

void BW::SceneNode::updateChildren(sf::Time dt)
{
        for (const NodePtr& child : mChildren)
        {
            child->update(dt);
        }
}

sf::Transform BW::SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for (const BW::SceneNode* node = this; node != nullptr; node = node->mParent)
    {
        transform = node->getTransform() * transform;
    }

    return transform;
}


sf::Vector2f BW::SceneNode::getWorldPosition() const
{

    return getWorldTransform() * sf::Vector2f();

}
