/*
•	ввод с клавиатуры объекта и вывод на экран;
•	запись объектов в текстовый файл и загрузка из текстового файла;
•	запись объектов в двоичный файл и загрузка из двоичного файла.
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "fraction.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	vector < fraction > v;
	
	for (;;) {
		system("cls");
		cout << "1. Добавить дробь" << endl;
		cout << "2. Сложить дроби" << endl;
		cout << "3. Вычесть из первой вторую" << endl;
		cout << "4. Умножить дроби" << endl;
		cout << "5. Разделить первую на вторую" << endl;
		cout << "6. Вывести список всех дробей" << endl;
		cout << "7. Загрузить дроби из файла" << endl;
		cout << "8. Вывести все дроби в файл" << endl;
		cout << "9. Вывести все дроби в двоичный файл" << endl;
		cout << "10. ВВести дроби из двоичного файла" << endl;

		int a, b, c;

		cin >> c;
		system("cls");

		switch (c)
		{
		case 1: {
			cout << "ВВОД ДРОБИ\n";
			fraction F;
			cin >> F;
			v.push_back(F);
			break;
		}
		case 2:
			cout << "СЛОЖЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			v.push_back(v[a] + v[b]);
			cout << v.back().getStr();
			cout << endl;
			break;
		case 3:
			cout << "ВЫЧИТАНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			v.push_back(v[a] - v[b]);
			cout << v.back().getStr();
			cout << endl;
			break;
		case 4:
			cout << "УМНОЖЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			v.push_back(v[a] * v[b]);
			cout << v.back().getStr();
			cout << endl;
			break;
		case 5:
			cout << "ДЕЛЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			v.push_back(v[a] / v[b]);
			cout << v.back().getStr();
			cout << endl;
			break;
		case 6:
			for (auto i : v) cout << i << endl;
			cout << endl;
			break;
		case 7: {
			ifstream fin("in.txt", ios::in);

			if (!fin) {
				cout << "Input file stream error!" << endl;
				return 1;
			}

			while (!fin.eof()) {
				fraction F;
				fin >> F;
				v.push_back(F);
			}
			fin.close();
			break;
		}
		case 8: {
			ofstream fout("out.txt", ios::out | ios::binary);

			if (!fout) {
				cout << "Output file stream error!" << endl;
				return 1;
			}

			for (auto i : v) fout << i << endl;
			fout.close();
			break;
		}
		case 9: {
			ofstream bin("out.bin", std::ios::binary);
			for (auto i : v) i.writeBin(bin);
			bin.close();
			break;
		}
		case 10: {
			ifstream bin("out.bin", std::ios::binary);
			fraction F;
			while (F.readBin(bin)) v.push_back(F);
			bin.close();
			break;
		}
		default:
			break;
		}
		system("Pause");
	}
}