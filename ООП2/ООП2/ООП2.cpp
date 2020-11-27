/*
Перегрузить следующие операции:
•	сложение/ вычитание дробей;
•	сложение/вычитание числа;
•	приведение к типу float;
•	операцию присваивания.
*/

#include "pch.h"
#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
	fraction A(-35, 98);
	fraction B;
	B.setNumerator(228);
	B.setDenominator(950);
	fraction C = A + B;
	
	cout << "count: " << fraction::getCount() << endl << endl;
	cout << A.getStr() << " + " << B.getStr() << " = " << C.getStr() << " = " << float(C) << endl;
	cout << A.getStr() << " - " << B.getStr() << " = " << (A - B).getStr() << endl;
	cout << A.getStr() << " * " << B.getStr() << " = " << (A * B).getStr() << endl;
	cout << A.getStr() << " / " << B.getStr() << " = " << (A / B).getStr() << endl << endl;

	cout << A.getStr() << " + " << 2 << " = " << (A + 2).getStr() << endl;
	cout << 2 << " + " << A.getStr() << " = " << (2 + A).getStr() << endl;
	cout << A.getStr() << " - " << 2 << " = " << (A - 2).getStr() << endl;
	cout << 2 << " - " << A.getStr() << " = " << (2 - A).getStr() << endl;
	cout << A.getStr() << " * " << 2 << " = " << (A * 2).getStr() << endl;
	cout << 2 << " * " << A.getStr() << " = " << (2 * A).getStr() << endl;
	cout << A.getStr() << " / " << 2 << " = " << (A / 2).getStr() << endl;
	cout << 2 << " / " << A.getStr() << " = " << (2 / A).getStr() << endl;
}

