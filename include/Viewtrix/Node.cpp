#include <cstdint>

#include "Node.h"
#include "Vector2.h"
#include "Viewtrix.h"

namespace vtrx
{
    void Node::init()
    {
    }

    void Node::update(float dt)
    {
    }

    void Node::draw()
    {
        Viewtrix *v = Viewtrix::getInstance();
        draw(v->getRender(), v->getWidth(), v->getHeight(), v->getMatrixCount());

        Queue<Node *>::Item *current = childs.getStart();

        while (current != nullptr)
        {
            Node *child = current->value;

            child->draw();

            current = current->next;
        }
    }

    void Node::draw(uint8_t *render, const uint8_t width, const uint8_t height, const uint8_t mcount)
    {
    }

    Node *Node::create()
    {
        Node *node = new Node();
        node->init();
        return node;
    }

    void Node::setPosition(Vector2 vector)
    {
        Vector2 diference = vector - position;

        position.x = vector.x;
        position.y = vector.y;

        Queue<Node *>::Item *current = childs.getStart();

        while (current != nullptr)
        {
            Node *child = current->value;

            Vector2 nChildPosition = child->position + diference;

            child->setPosition(nChildPosition);

            current = current->next;
        }
    }

    void Node::setPositionX(int8_t x)
    {
        setPosition(Vector2(x, position.y));
    }

    void Node::setPositionY(int8_t y)
    {
        setPosition(Vector2(position.x, y));
    }

    void Node::addChild(Node *child)
    {
        childs.add(child);
    }

} // namespace vtrx