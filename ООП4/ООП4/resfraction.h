#pragma once

#include "fraction.h"

class resfraction : public fraction
{
private:

	float* res = nullptr;

	void makeRes();

public:

	resfraction();
	resfraction(int Numerator, int Denominator);
	resfraction(const resfraction &F);
	~resfraction();

	float getRes();

	resfraction& operator = (const resfraction &F);
	resfraction operator + (const resfraction &F);
	resfraction operator - (const resfraction &F);
	resfraction operator * (const resfraction &F);
	resfraction operator / (const resfraction &F);

	friend std::ostream& operator << (std::ostream& out, resfraction &F);
	friend std::istream& operator >> (std::istream& in, resfraction &F);
};