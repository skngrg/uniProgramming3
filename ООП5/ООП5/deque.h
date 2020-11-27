#pragma once

#include <iostream>
#include "fraction.h"

class deque
{
private:

	static int size;

	struct Node
	{
		fraction* pBase = nullptr;
		Node* pNext = nullptr;
	} *pBegin = nullptr, *pEnd = nullptr;

public:

	~deque();

	void push_back(fraction* F);
	void push_front(fraction* F);
	fraction* pop_front();
	int Size();
	
	fraction* getBeginPtr();
	fraction* getEndPtr();

	friend std::ostream& operator << (std::ostream& out, const deque& D);

	bool readBin(std::ifstream& in);
	void writeBin(std::ofstream& out);
};