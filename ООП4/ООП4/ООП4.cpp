﻿/*
•	 класс, в котором есть поле-результат вычисления дроби;
•	 класс смешанная дробь.
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "fraction.h"
#include "mixfraction.h"
#include "resfraction.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	vector < fraction > v;
	vector < resfraction > vres;
	vector < mixfraction > vmix;

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

		cout << endl;

		cout << "11. Добавить дробь с результатом" << endl;
		cout << "12. Сложить дроби с результатом" << endl;
		cout << "13. Вычесть из первой вторую с результатом" << endl;
		cout << "14. Умножить дроби с результатом" << endl;
		cout << "15. Разделить первую на вторую с результатом" << endl;
		cout << "16. Вывести список всех дробей с результатом" << endl;

		cout << endl;

		cout << "17. Добавить смешанную дробь" << endl;
		cout << "18. Сложить  смешанные дроби" << endl;
		cout << "19. Вычесть из  смешанной первой вторую смешанную" << endl;
		cout << "20. Умножить смешанные дроби" << endl;
		cout << "21. Вывести список всех смешанных дробей" << endl;

		int a, b, c;

		cin >> c;
		system("cls");

		switch (c)
		{
		case 0: return 0;
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
		case 11: {
			cout << "ВВОД ДРОБИ\n";
			resfraction F;
			cin >> F;
			vres.push_back(F);
			break;
		}
		case 12:
			cout << "СЛОЖЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			vres.push_back(vres[a] + vres[b]);
			cout << vres.back().getStr();
			cout << endl;
			break;
		case 13:
			cout << "ВЫЧИТАНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			vres.push_back(vres[a] - vres[b]);
			cout << vres.back().getStr();
			cout << endl;
			break;
		case 14:
			cout << "УМНОЖЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			vres.push_back(vres[a] * vres[b]);
			cout << vres.back().getStr();
			cout << endl;
			break;
		case 15:
			cout << "ДЕЛЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			vres.push_back(vres[a] / vres[b]);
			cout << vres.back().getStr();
			cout << endl;
			break;
		case 16:
			for (auto i : vres) cout << i << endl;
			cout << endl;
			break;
		case 17: {
			cout << "ВВОД ДРОБИ\n";
			mixfraction F;
			cin >> F;
			vmix.push_back(F);
			break;
		}
		case 18:
			cout << "СЛОЖЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			vmix.push_back(vmix[a] + vmix[b]);
			cout << vmix.back().getUnit() << ' ' << vmix.back().getStr();
			cout << endl;
			break;
		case 19:
			cout << "ВЫЧИТАНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			vmix.push_back(vmix[a] - vmix[b]);
			cout << vmix.back().getUnit() << ' ' << vmix.back().getStr();
			cout << endl;
			break;
		case 20:
			cout << "УМНОЖЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			vmix.push_back(vmix[a] * vmix[b]);
			cout << vmix.back().getUnit() << ' ' << vmix.back().getStr();
			cout << endl;
			break;
		case 21:
			for (auto i : vmix) cout << i << endl;
			cout << endl;
			break;
		default:
			break;
		}
		system("Pause");
	}
}