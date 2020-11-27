#pragma once

#include "fraction.h"

class resfraction : public fraction
{
private:

	float* res = nullptr;

	char thisStr[30];

	void makeRes();

public:

	resfraction();
	resfraction(int Numerator, int Denominator);
	resfraction(const resfraction &F);
	~resfraction() override;

	char* get() override;

	float getRes();

	resfraction& operator = (const resfraction &F);
	resfraction operator + (const resfraction &F);
	resfraction operator - (const resfraction &F);
	resfraction operator * (const resfraction &F);
	resfraction operator / (const resfraction &F);

	friend std::ostream& operator << (std::ostream& out, resfraction &F);
	friend std::istream& operator >> (std::istream& in, resfraction &F);

	bool readBin(std::ifstream& in) override;
	void writeBin(std::ofstream& out) override;
};