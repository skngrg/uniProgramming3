#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <ctime>
#include "fraction.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	
	//для int
	cout << "для int" << endl << endl;
	ofstream fout("QueueInt.txt");

	for (int n = 0; n < 1000000; n += 100000) {
		queue < int > q;
		
		cout << "Для " << n << " элементов" << endl;
		fout << n << ' ';

		clock_t start = clock();
		for (int i = 0; i < n; i++) { //добавление
			q.push(rand());
		}
		float t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Добавление: " <<  t << endl;
		fout << t << ' ';

		start = clock();
		for (int i = 0; i < n; i++) { //удаление
			q.pop();
		}
		t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Удаление: " << t << endl;
		fout << t << endl;
	}
	
	fout.close();
	ofstream fout;
	fout.open("MapInt.txt");

	for (int n = 0; n < 1000000; n += 100000) {
		map < int, char > m;
		
		cout << "Для " << n << " элементов" << endl;
		fout << n << ' ';

		clock_t start = clock();
		for (int i = 0; i < n; i++) { //добавление
			m.insert(pair< int, char >(i, rand() % 256));
		}
		float t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Добавление: " << t << endl;
		fout << t << ' ';

		start = clock();
		for (int i = 0; i < n; i++) {
			m.find(rand() % 256); //поиск
		}
		t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Поиск: " << t << endl;
		fout << t << endl;

		start = clock();
		for (int i = 0; i < n; i++) { //удаление
			m.erase(i);
		}
		t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Удаление: " << t << endl;
		fout << t << endl;
	}
	
	fout.close();

	cout << "----------------------------" << endl;
	//для fraction
	cout << "для fraction" << endl << endl;
	
	fout.open("QueueFraction.txt");

	for (int n = 0; n < 1000000; n += 100000) {
		queue < fraction > q;

		cout << "Для " << n << " элементов" << endl;
		fout << n << ' ';

		clock_t start = clock();
		for (int i = 0; i < n; i++) { //добавление
			int r = rand();
			q.push(fraction(rand(), r == 0 ? 1 : r));
		}
		float t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Добавление: " << t << endl;
		fout << t << ' ';

		start = clock();
		for (int i = 0; i < n; i++) { //удаление
			q.pop();
		}
		t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Удаление: " << t << endl;
		fout << t << endl;
	}

	fout.close();

	fout.open("MapFraction.txt");

	for (int n = 0; n < 1000000; n += 100000) {
		map < int, fraction > m;

		cout << "Для " << n << " элементов" << endl;
		fout << n << ' ';

		clock_t start = clock();
		for (int i = 0; i < n; i++) { //добавление
			int r = rand();
			m.insert(pair< int, fraction >(i, fraction(rand(), r == 0 ? 1 : r)));
		}
		float t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Добавление: " << t << endl;
		fout << t << ' ';

		start = clock();
		for (int i = 0; i < n; i++) {
			int r = rand();
			m.find(fraction(rand(), r == 0 ? 1 : r)); //поиск
		}
		t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Поиск: " << t << endl;
		fout << t << endl;

		start = clock();
		for (int i = 0; i < n; i++) { //удаление
			m.erase(i);
		}
		t = float(clock() - start) / CLOCKS_PER_SEC;
		cout << "	Удаление: " << t << endl;
		fout << t << endl;
	}

	fout.close();

	system("Pause");
}