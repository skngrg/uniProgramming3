#pragma once
#include <iostream>
#include "fraction.h"

template <typename T>
class Deque
{
private:

	struct Node
	{
		T value;
		Node* next = nullptr;
	} *pBegin = nullptr, *pEnd = nullptr;

	int Size;

public:

	~Deque();

	void push_back(T value);
	void push_front(T value);
	void pop_front();

	int size();

	friend std::ostream& operator << (std::ostream& out, const Deque<T> & D)
	{
		Node* ptr = D.pBegin;

		while (ptr != nullptr) {
			std::cout << ptr->value << ' ';
			ptr = ptr->next;
		}

		return out;
	}

	void writeBin(std::ofstream& out);
	void readBin(std::ifstream& out);
};

template<typename T>
Deque<T>::~Deque()
{
	while (pBegin != nullptr) pop_front();
}

template<typename T>
void Deque<T>::push_back(T value)
{
	if (pEnd == nullptr) {
		pEnd = new Node;
		pEnd->value = value;
		pBegin = pEnd;
	}
	else {
		pEnd->next = new Node;
		pEnd->next->value = value;
		pEnd = pEnd->next;
	}
	Size++;
}

template<typename T>
void Deque<T>::push_front(T value)
{
	if (pBegin == nullptr) {
		pBegin = new Node;
		pBegin->value = value;
		pEnd = pBegin;
	}
	else {
		Node* ptr = pBegin;
		pBegin = new Node;
		pBegin->next = ptr;
		pBegin->value = value;
	}
	Size++;
}

template<typename T>
void Deque<T>::pop_front()
{
	if (pBegin == nullptr) throw std::exception("Попытка удалить из пустого дэка");
	
	Node* ptr = pBegin->next;
	delete pBegin;
	pBegin = ptr;

	if (pBegin == nullptr) pEnd = nullptr;
	
	Size--;
}

template<typename T>
int Deque<T>::size()
{
	return Size;
}

template<typename T>
void Deque<T>::writeBin(std::ofstream & out)
{
	out.write((char*)&Size, sizeof(Size));
	Node* ptr = pBegin;
	while (ptr) {
		out.write((char*)&ptr->value, sizeof(T));
		ptr = ptr->next;
	}
}

template<typename T>
void Deque<T>::readBin(std::ifstream & out)
{
	int s;
	out.read((char*)&s, sizeof(s));
	T val;
	for (int i = 0; i < s; i++) {
		out.read((char*)&val, sizeof(val));
		push_back(val);
	}
}

void Deque<fraction>::writeBin(std::ofstream & out)
{
	out.write((char*)&Size, sizeof(Size));
	Node* ptr = pBegin;
	while (ptr) {
		ptr->value.writeBin(out);
		ptr = ptr->next;
	}
}

void Deque<fraction>::readBin(std::ifstream & out)
{
	int s;
	out.read((char*)&s, sizeof(s));
	fraction val;
	for (int i = 0; i < s; i++) {
		val.readBin(out);
		push_back(val);
	}
}