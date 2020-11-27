#include "pch.h"
#include "mixfraction.h"

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

std::ostream & operator<<(std::ostream & out, mixfraction & F)
{
	out << F.getUnit() << ' ' << F.getStr();
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
