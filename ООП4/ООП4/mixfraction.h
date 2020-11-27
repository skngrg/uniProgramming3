#pragma once

#include "fraction.h"

class mixfraction : public fraction
{
private:

	int* unit = nullptr;
	
	void makeUnit();

public:

	mixfraction();
	mixfraction(int Unit, int Numerator, int Denominator);
	mixfraction(const mixfraction &F);
	~mixfraction();

	int getUnit();
	void SetUnit(int Unit);

	mixfraction& operator = (const mixfraction &F);
	mixfraction operator + (const mixfraction &F);
	mixfraction operator - (const mixfraction &F);
	mixfraction operator * (const mixfraction &F);

	friend std::ostream& operator << (std::ostream& out, mixfraction &F);
	friend std::istream& operator >> (std::istream& in, mixfraction &F);
};