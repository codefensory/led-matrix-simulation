#ifndef Display_h
#define Display_h

#include "Node.h"

namespace vtrx
{
	class Display : public Node
	{
	private:
		bool animatingPosition;

	public:
		void exit()
		{
			delete this;
		}

		Display() {}
		~Display() {}
	};
} // namespace vtrx
#endif