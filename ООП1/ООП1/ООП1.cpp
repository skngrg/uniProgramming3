/*Вариант  5.
Постpоить класс для pаботы с дробями. Класс должен включать соответствующие поля:
числитель, знаменатель, строковое представление дроби.
Класс должен обеспечивать пpостейшие функции для pаботы с данными класса:
сложение, вычитание, умножение, деление, вывод дро-би в удобной форме и т.д.
*/

#include "pch.h"
#include <iostream>
#include "fraction.h"
#include <vector>

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

		int a, b, c;

		cin >> c;
		
		switch (c)
		{
		case 1:
			system("cls");
			int num, det;
			cout << "ВВОД ДРОБИ\nВведите числитель: ";
			cin >> num;
			cout << "Введите знаменатель: ";
			cin >> det;
			v.push_back(fraction(num, det));
			break;
		case 2:
			system("cls");
			cout << "СЛОЖЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			v.push_back(*v[a].sum(&v[b]));
			cout << v.back().getStr();
			cout << endl;
			system("Pause");
			break;
		case 3:
			system("cls");
			cout << "ВЫЧИТАНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			v.push_back(*v[a].dif(&v[b]));
			cout << v.back().getStr();
			cout << endl;
			system("Pause");
			break;
		case 4:
			system("cls");
			cout << "УМНОЖЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			v.push_back(*v[a].multi(&v[b]));
			cout << v.back().getStr();
			cout << endl;
			system("Pause");
			break;
		case 5:
			system("cls");
			cout << "ДЕЛЕНИЕ\nВведите номера дробей через пробел: ";
			cin >> a >> b;
			v.push_back(*v[a].div(&v[b]));
			cout << v.back().getStr();
			cout << endl;
			system("Pause");
			break;
		case 6:
			system("cls");
			for (auto i : v) cout << i.getStr() << ' ';
			cout << endl;
			system("Pause");
			break;
		default:
			break;
		}
	}
}