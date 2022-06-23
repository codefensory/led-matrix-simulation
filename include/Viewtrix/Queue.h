#ifndef Queue_h
#define Queue_h

#include <cstdint>

template <class T>
class Queue
{
public:
	struct Item
	{
		T value;
		Item *next;
	};

	uint8_t count;

	Queue() : start(nullptr), end(nullptr), count(0)
	{
	}

	~Queue()
	{
		while (start != nullptr)
		{
			Item *aux = start;

			if (start == end)
			{
				start == nullptr;
				end == nullptr;
			}
			else
			{
				start = start->next;
			}

			delete aux;
		}
	}

	void add(T value)
	{
		Item *nItem = new Item();
		nItem->value = value;
		nItem->next = nullptr;

		if (start == nullptr)
			start = nItem;
		else
			end->next = nItem;

		end = nItem;
		count++;
	}

	Item *getStart() { return start; }

private:
	Item *start = nullptr, *end = nullptr;
};

#endif // !Queue_h
