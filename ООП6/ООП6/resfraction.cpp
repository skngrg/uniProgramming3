#include "resfraction.h"
#include <fstream>

void resfraction::makeRes()
{
	if (res == nullptr) {
		res = new float;
	}
	*res = float(getNumerator()) / getDenominator();
}

resfraction::resfraction()
{

}

resfraction::resfraction(int Numerator, int Denominator) : fraction(Numerator, Denominator)
{
	res = new float(float(Numerator) / Denominator);
}

resfraction::resfraction(const resfraction & F) : fraction(F)
{
	delete res;
	res = new float;
	*res = *F.res;
}

resfraction::~resfraction()
{
	delete res;
}

char * resfraction::get()
{
	char* s = getStr();

	int i = 0;
	for (int j = 0; s[j] != '\0'; thisStr[i++] = s[j++]);
	thisStr[i++] = '=';

	char buffer[9];
	snprintf(buffer, sizeof buffer, "%f", *res);

	for (int j = 0; buffer[j] != '\0'; thisStr[i++] = buffer[j++]);

	return thisStr;
}

float resfraction::getRes()
{
	return *res;
}

resfraction & resfraction::operator=(const resfraction & F)
{
	delete res;
	fraction::operator=(F);
	res = new float;
	*res = *F.res;
	return *this;
}

resfraction resfraction::operator+(const resfraction & F)
{
	fraction F1 = fraction::operator+(F);
	return resfraction(F1.getNumerator(), F1.getDenominator());
}

resfraction resfraction::operator-(const resfraction & F)
{
	fraction F1 = fraction::operator-(F);
	return resfraction(F1.getNumerator(), F1.getDenominator());
}

resfraction resfraction::operator*(const resfraction & F)
{
	fraction F1 = fraction::operator*(F);
	return resfraction(F1.getNumerator(), F1.getDenominator());
}

resfraction resfraction::operator/(const resfraction & F)
{
	fraction F1 = fraction::operator/(F);
	return resfraction(F1.getNumerator(), F1.getDenominator());
}

bool resfraction::readBin(std::ifstream & in)
{
	char c;
	in.read((char*)&c, sizeof(c));
	bool b = fraction::readBin(in);
	makeRes();
	return b;
}

void resfraction::writeBin(std::ofstream & out)
{
	char c = 3;
	out.write((char*)&c, 1);
	fraction::writeBin(out);
}

std::ostream & operator<<(std::ostream & out, resfraction &F)
{
	out << F.get();
	return out;
}

std::istream & operator>>(std::istream & in, resfraction & F)
{
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

	F.makeRes();

	return in;
}