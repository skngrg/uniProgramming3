#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h> 
#include <iostream>
#include <fstream>
#include "Deque.h"
#include "fraction.h"

using namespace std;

template <typename T>
int menu()
{
	Deque <T> D_Int;
	//Deque <float> D_Float;
	//Deque <fraction> D_Fraction;

	for (;;) {
		system("cls");

		cout << "1. Добавить в начало дэка" << endl;
		cout << "2. Добавить в конец дэка" << endl;
		cout << "3. Удалить из начала дэка" << endl;
		cout << "4. Вывести дэк в консоль" << endl;
		cout << "5. Вывести дэк в файл" << endl;
		cout << "6. Ввести дэк из файла" << endl;

		int a;
		cin >> a;
		system("cls");
		switch (a)
		{
		case 0:
			return 0;
		case 1:
		{
			cout << "Введите INT:" << endl;
			T val;
			cin >> val;
			D_Int.push_front(val);
			break;
		}
		case 2:
		{
			cout << "Введите INT:" << endl;
			T val;
			cin >> val;
			D_Int.push_back(val);
			break;
		}
		case 3:
			D_Int.pop_front();
			break;
		case 4:
			cout << D_Int << endl;
			break;
		case 5:
		{
			ofstream bin("file.bin", ios::binary);
			D_Int.writeBin(bin);
			bin.close();
			break;
		}
		case 6:
		{
			ifstream bin("file.bin", ios::binary);
			D_Int.readBin(bin);
			bin.close();
			break;
		}
		default:
			break;
		}
		system("Pause");
	}
	return 0;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	setlocale(LC_ALL, "Rus");

	return menu<fraction>();
}