#include "deque.h"
#include "mixfraction.h"
#include "resfraction.h"
#include "MyException.h"
#include <fstream>

deque::~deque()
{
	while (pEnd != nullptr)
		pop_front();
}

void deque::push_back(fraction * F)
{
	if (pEnd == nullptr) {
		pEnd = new Node;
		pEnd->pBase = F;
		pBegin = pEnd;
	}
	else {
		pEnd->pNext = new Node;
		pEnd = pEnd->pNext;
		pEnd->pBase = F;
	}
	size++;
}

void deque::push_front(fraction * F)
{
	if (pBegin == nullptr) {
		pBegin = new Node;
		pBegin->pBase = F;
		pEnd = pBegin;
	}
	else {
		Node* ptr = new Node;
		ptr->pNext = pBegin;
		pBegin = ptr;
		pBegin->pBase = F;
	}
	size++;
}

fraction* deque::pop_front()
{
	if (size == 0) throw deque_exception("Попытка удалить из пустого дэка");
	fraction* pF;
	if (pBegin != pEnd) {
		Node* ptr = pBegin->pNext;
		pF = pBegin->pBase;
		delete pBegin->pBase;
		delete pBegin;
		pBegin = ptr;
	}
	else {
		delete pBegin->pBase;
		pF = pBegin->pBase;
		delete pBegin;
		pBegin = nullptr;
		pEnd = nullptr;
	}
	size--;
	return pF;
}

int deque::Size()
{
	return size;
}

fraction * deque::getBeginPtr()
{
	if (pBegin == nullptr) throw deque_exception("Попытка получить доступ к пустому дэку");
	return pBegin->pBase;
}

fraction * deque::getEndPtr()
{
	if (pEnd == nullptr) throw deque_exception("Попытка получить доступ к пустому дэку");
	return pEnd->pBase;
}

bool deque::readBin(std::ifstream & in)
{
	if (in.tellg() <= 0) throw file_exception("Попытка считать дэк из пустого файла");
	bool b = true;
	while (!in.eof()) {
		char c;
		in.read((char*)&c, sizeof(c));
		switch (c)
		{
		case 1:
		{
			fraction F;
			b = F.readBin(in);
			if (b)
				push_back(new fraction(F));
			break;
		}
		case 2:
		{
			mixfraction F;
			b = F.readBin(in);
			if (b)
				push_back(new mixfraction(F));
			break;
		}
		case 3:
		{
			resfraction F;
			b = F.readBin(in);
			if (b)
				push_back(new resfraction(F));
			break;
		}
		default:
			break;
		}
	}

	return true;
}

void deque::writeBin(std::ofstream & out)
{
	Node* ptr = pBegin;
	for (int i = 0; i < size; i++) {
		ptr->pBase->writeBin(out);
		ptr = ptr->pNext;
	}
}

std::ostream & operator<<(std::ostream & out, const deque & D)
{
	deque::Node* ptr = D.pBegin;
	for (int i = 0; i < D.size; i++) {
		out << ptr->pBase->get() << ' ';
		ptr = ptr->pNext;
	}
	return out;
}
