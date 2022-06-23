#ifndef Node_h
#define Node_h

#include "Vector2.h"
#include "Queue.h"

namespace vtrx
{
	class MatrixDirector;
	class Display;

	class Node
	{
	private:
		Vector2 position;
		Node *parent;
		Queue<Node *> childs;
		virtual void preupdate(float dt) { update(dt); }

	protected:
		Node() : position(Vector2(0, 0)),
				 parent(nullptr),
				 childs(Queue<Node *>()) {}

		virtual void init();
		virtual void update(float dt);

		virtual void draw() final;
		virtual void draw(uint8_t *render, uint8_t width, uint8_t height, uint8_t mcount);

	public:
		friend class MatrixDirector;
		friend class Display;

		static Node *create();

		void setPosition(Vector2 vector);
		void setPositionX(int8_t x);
		void setPositionY(int8_t y);

		void addChild(Node *child);

		Vector2 getPosition()
		{
			return position;
		}

		~Node()
		{
		}
	};
} // namespace vtrx

#endif