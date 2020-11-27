#include "mixfraction.h"
#include <fstream>

void mixfraction::makeUnit()
{
	if (unit == nullptr) {
		unit = new int(0);
	}

	*unit += this->getNumerator() / this->getDenominator();
	this->setNumerator(this->getNumerator() - this->getNumerator() / this->getDenominator() * this->getDenominator());
}

mixfraction::mixfraction() : fraction()
{

}

mixfraction::mixfraction(int Unit, int Numerator, int Denominator) : fraction(Numerator, Denominator)
{
	unit = new int(Unit);
	makeUnit();
}

mixfraction::mixfraction(const mixfraction & F) : fraction(F)
{
	delete unit;
	unit = new int(*F.unit);
}

mixfraction::~mixfraction()
{
	delete unit;
}

char * mixfraction::get()
{
	int i = 0;
	for (int a = *unit; a != 0; thisStr[i] = a % 10 + '0', a /= 10, i++);

	for (int j = 0, a; j != i / 2; a = thisStr[j], thisStr[j] = thisStr[i - j - 1], thisStr[i - j - 1] = a, j++);

	char* s = getStr();

	thisStr[i++] = ' ';

	for (int j = 0; j != 22; thisStr[i++] = s[j++]);

	return thisStr;
}

int mixfraction::getUnit()
{
	return *unit;
}

void mixfraction::SetUnit(int Unit)
{
	if (unit == nullptr) {
		unit = new int;
	}
	*unit = Unit;
}

mixfraction & mixfraction::operator=(const mixfraction & F)
{
	delete unit;
	fraction::operator=(F);
	unit = new int(*F.unit);
	return *this;
}

mixfraction mixfraction::operator+(const mixfraction & F)
{
	fraction F1 = fraction::operator+(F);
	return mixfraction(*unit + *F.unit, F1.getNumerator(), F1.getDenominator());
}

mixfraction mixfraction::operator-(const mixfraction & F)
{
	fraction F1 = fraction::operator-(F);
	return mixfraction(*unit - *F.unit, F1.getNumerator(), F1.getDenominator());
}

mixfraction mixfraction::operator*(const mixfraction & F)
{
	fraction F1 = fraction::operator*(F);
	return mixfraction(*unit * *F.unit, F1.getNumerator(), F1.getDenominator());
}

bool mixfraction::readBin(std::ifstream & in)
{
	if (unit == nullptr) unit = new int;
	in.read((char*)unit, sizeof(*unit));
	char c;
	in.read((char*)&c, sizeof(c));
	return fraction::readBin(in);
}

void mixfraction::writeBin(std::ofstream &out)
{
	char c = 2;
	out.write((char*)&c, 1);
	out.write((char*)unit, sizeof(*unit));
	fraction::writeBin(out);
}

std::ostream & operator<<(std::ostream & out, mixfraction & F)
{
	out << F.get();
	return out;
}

std::istream & operator>>(std::istream & in, mixfraction & F)
{
	int unit;
	in >> unit;
	F.SetUnit(unit);

	char c[22];
	in >> c;

	int Num, Den;

	char Buf[11];

	int i = 0;
	for (; c[i] != '/' && c[i] != '\0'; Buf[i] = c[i++]);
	Buf[i++] = '\0';

	Num = atoi(Buf);

	int j = 0;
	for (; c[i] != '\0'; Buf[j++] = c[i++]);
	Buf[j] = '\0';
	Den = atoi(Buf);

	F.setNumerator(Num);
	F.setDenominator(Den);
	return in;
}
