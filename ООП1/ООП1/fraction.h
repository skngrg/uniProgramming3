#pragma once

class fraction {
private:
	int *numerator = nullptr,
		*denominator = nullptr;
	char *str = nullptr;
	static int count;

	int NOD(int a, int b);

	int NOK(int a, int b);
	void MakeStr();

public:
	fraction *sum(const fraction *B);

	fraction *dif(const fraction *B);

	fraction *multi(const fraction *B);

	fraction *div(const fraction *B);

	fraction();

	fraction(int Numerator, int Denominator);

	fraction(const fraction &F);

	~fraction();

	char* getStr();

	int getNumerator();

	int getDenominator();

	static int getCount();

	void setNumerator(int Numerator);

	void setDenominator(int Denominator);
};