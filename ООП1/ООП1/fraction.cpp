#include "pch.h"
#include "fraction.h"
#include <iostream>

int fraction::count = 0;

int fraction::NOD(int a, int b)
{
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

int fraction::NOK(int a, int b)
{
	return a * b / fraction::NOD(a, b);
}

void fraction::MakeStr()
{
	int a = *numerator,
		b = *denominator;
	int len = 0, p;
	for (int i = 0; a != 0; str[i++] = a % 10 + '0', a /= 10, len++); //первое число
	int pos = len;
	for (int i = 0; i < len; p = str[i], str[i++] = str[len - 1], str[len-- - 1] = p); //переворот первого числа
	str[pos] = '/';
	len = 0;
	for (int i = pos + 1/*,len = 0*/; b != 0; str[i++] = b % 10 + '0', b /= 10, len++); //второе число
	len += pos + 1;
	str[len] = '\0';
	for (int i = pos + 1; i < len; p = str[i], str[i++] = str[len - 1], str[len-- - 1] = p); //переворот второго числа
}

fraction* fraction::sum(const fraction *B)
{
	int nok = NOK(*((*this).denominator), *((*B).denominator)); //нахожу нок

	int mn1 = nok / *((*this).denominator), //нахожу множители
		mn2 = nok / *((*B).denominator);

	int num = *((*this).numerator) * mn1 + *((*B).numerator) * mn2; //сложение числителей, нок - знаменатель

	int nod = NOD(num, nok); //сокращение дроби
	num /= nod;
	nok /= nod;

	fraction *C = new fraction(num, nok);

	return C;
}

fraction* fraction::dif(const fraction *B)
{
	int nok = NOK(*((*this).denominator), *((*B).denominator)); //нахожу нок

	int mn1 = nok / *((*this).denominator), //нахожу множители
		mn2 = nok / *((*B).denominator);

	int num = *((*this).numerator) * mn1 - *((*B).numerator) * mn2; //сложение числителей, нок - знаменатель

	int nod = NOD(num, nok); //сокращение дроби
	num /= nod;
	nok /= nod;

	fraction *C = new fraction(num, nok);

	return C;
}

fraction* fraction::multi(const fraction *B)
{
	int num = *((*this).numerator) * *((*B).numerator),
		den = *((*this).denominator) * *((*B).denominator);

	int nod = NOD(num, den);
	num /= nod;
	den /= nod;

	fraction *C = new fraction(num, den);

	return C;
}

fraction* fraction::div(const fraction *B)
{
	int num = *((*this).numerator) * *((*B).denominator),
		den = *((*this).denominator) * *((*B).numerator);

	int nod = NOD(num, den);
	num /= nod;
	den /= nod;

	fraction *C = new fraction(num, den);

	return C;
}

fraction::fraction()
{
	count++;
}

fraction::fraction(int Numerator, int Denominator)
{
	numerator = new int(Numerator);
	denominator = new int(Denominator);
	str = new char[22];
	MakeStr();
	count++;
}

fraction::fraction(const fraction &F)
{
	numerator = new int(*(F.numerator));
	denominator = new int(*(F.denominator));
	str = new char[22];
	std::cout << "я конструктор копирования" << std::endl;
	MakeStr();
	std::cout << str << std::endl;
}

fraction::~fraction()
{
	delete numerator;
	delete denominator;
	delete[]str;
	count--;
}

char* fraction::getStr()
{
	return str;
}

int fraction::getNumerator()
{
	return *numerator;
}

int fraction::getDenominator()
{
	return *denominator;
}

int fraction::getCount()
{
	return count;
}

void fraction::setNumerator(int Numerator)
{
	if (numerator == nullptr) {
		numerator = new int(Numerator);
	}
	if (denominator != nullptr) {
		if (str == nullptr) {
			str = new char[22];
		}
		MakeStr();
	}
}

void fraction::setDenominator(int Denominator)
{
	if (denominator == nullptr) {
		denominator = new int(Denominator);
	}
	if (numerator != nullptr) {
		if (str == nullptr) {
			str = new char[22];
		}
		MakeStr();
	}
}
