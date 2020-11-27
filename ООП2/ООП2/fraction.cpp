#include "pch.h"
#include "fraction.h"

int fraction::count = 0;

inline int fraction::abs(int a)
{
	return a = a >= 0 ? a : -a;
}

int fraction::NOD(int a, int b)
{
	a = abs(a);
	b = abs(b);
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

void fraction::str1()
{
	int a = abs(*numerator),
		b = abs(*denominator);
	int len = 0, p;
	for (int i = 0; a != 0; str[i++] = a % 10 + '0', a /= 10, len++); //������ �����
	int pos = len;
	for (int i = 0; i < len; p = str[i], str[i++] = str[len - 1], str[len-- - 1] = p); //��������� ������� �����
	str[pos] = '/';
	len = 0;
	for (int i = pos + 1/*,len = 0*/; b != 0; str[i++] = b % 10 + '0', b /= 10, len++); //������ �����
	len += pos + 1;
	str[len] = '\0';
	for (int i = pos + 1; i < len; p = str[i], str[i++] = str[len - 1], str[len-- - 1] = p); //��������� ������� �����
}

void fraction::str2()
{
	int a = abs(*numerator),
		b = abs(*denominator);
	int len = 0, p;
	for (int i = 1; a != 0; str[i++] = a % 10 + '0', a /= 10, len++); //������ �����
	int pos = len + 1;
	for (int i = 1; i <= len; p = str[i], str[i++] = str[len], str[len--] = p); //��������� ������� �����
	str[pos] = '/';
	len = 0;
	for (int i = pos + 1/*,len = 0*/; b != 0; str[i++] = b % 10 + '0', b /= 10, len++); //������ �����
	len += pos + 1;
	str[len] = '\0';
	for (int i = pos + 1; i < len; p = str[i], str[i++] = str[len - 1], str[len-- - 1] = p); //��������� ������� �����
	str[0] = '-';
}

void fraction::MakeStr()
{
	if (*numerator > 0) str1(); else str2();
}

fraction* fraction::sum(const fraction *B)
{
	int nok = NOK(*((*this).denominator), *((*B).denominator)); //������ ���

	int mn1 = nok / *((*this).denominator), //������ ���������
		mn2 = nok / *((*B).denominator);

	int num = *((*this).numerator) * mn1 + *((*B).numerator) * mn2; //�������� ����������, ��� - �����������

	int nod = NOD(num, nok); //���������� �����
	num /= nod;
	nok /= nod;

	fraction *C = new fraction(num, nok);

	return C;
}

fraction* fraction::dif(const fraction *B)
{
	int nok = NOK(*((*this).denominator), *((*B).denominator)); //������ ���

	int mn1 = nok / *((*this).denominator), //������ ���������
		mn2 = nok / *((*B).denominator);

	int num = *((*this).numerator) * mn1 - *((*B).numerator) * mn2; //�������� ����������, ��� - �����������

	int nod = NOD(num, nok); //���������� �����
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

	if (*denominator < 0) {
		*numerator = -*numerator;
		*denominator = -*denominator;
	}

	int nod = NOD(*numerator, *denominator);

	*numerator /= nod;
	*denominator /= nod;

	str = new char[22];
	MakeStr();
	count++;
}

fraction::fraction(const fraction &F)
{
	numerator = new int(*(F.numerator));
	denominator = new int(*(F.denominator));
	str = new char[22];
	MakeStr();
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
		if (*denominator < 0) {
			*numerator = -*numerator;
			*denominator = -*denominator;
		}

		int nod = NOD(*numerator, *denominator);

		*numerator /= nod;
		*denominator /= nod;

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
		if (*denominator < 0) {
			*numerator = -*numerator;
			*denominator = -*denominator;
		}

		int nod = NOD(*numerator, *denominator);

		*numerator /= nod;
		*denominator /= nod;

		if (str == nullptr) {
			str = new char[22];
		}
		MakeStr();
	}
}

fraction& fraction::operator = (const fraction &F)
{
	numerator = new int(*(F.numerator));
	denominator = new int(*(F.denominator));
	str = new char[22];
	MakeStr();
	return *this;
}

fraction fraction::operator + (const fraction &F)
{
	return *sum(&F);
}

fraction fraction::operator - (const fraction &F)
{
	return *dif(&F);
}

fraction fraction::operator * (const fraction &F)
{
	return *multi(&F);
}

fraction fraction::operator / (const fraction &F)
{
	return *div(&F);
}

fraction::operator float()
{
	return float(*numerator) / *denominator;
}

fraction operator+(const fraction F, const int A)
{
	return fraction(*F.numerator + A * *F.denominator, *F.denominator);
}

fraction operator+(const int A, const fraction F)
{
	return fraction(*F.numerator + A * *F.denominator, *F.denominator);
}

fraction operator-(const fraction F, const int A)
{
	return fraction(*F.numerator - A * *F.denominator, *F.denominator);
}

fraction operator-(const int A, const fraction F)
{
	return fraction(A * *F.denominator - *F.numerator, *F.denominator);
}

fraction operator*(const fraction F, const int A)
{
	return fraction(*F.numerator * A, *F.denominator);
}

fraction operator*(const int A, const fraction F)
{
	return fraction(*F.numerator * A, *F.denominator);
}

fraction operator/(const fraction F, const int A)
{
	return fraction(*F.numerator, *F.denominator * A);
}

fraction operator/(const int A, const fraction F)
{
	return fraction(A * *F.denominator, *F.numerator);
}