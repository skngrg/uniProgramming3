#pragma once

class fraction {
private:
	int *numerator = nullptr,
		*denominator = nullptr;
	char *str = nullptr;
	static int count;

	inline int abs(int a);
	int NOD(int a, int b);
	int NOK(int a, int b);

	void str1();
	void str2();
	void MakeStr();

	fraction *sum(const fraction *B);
	fraction *dif(const fraction *B);
	fraction *multi(const fraction *B);
	fraction *div(const fraction *B);

public:
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

	fraction& operator = (const fraction &F);
	fraction operator + (const fraction &F);
	fraction operator - (const fraction &F);
	fraction operator * (const fraction &F);
	fraction operator / (const fraction &F);
	
	operator float();

	friend fraction operator + (const fraction F, const int A);
	friend fraction operator + (const int A, const fraction F);
	friend fraction operator - (const fraction F, const int A);
	friend fraction operator - (const int A, const fraction F);
	friend fraction operator * (const fraction F, const int A);
	friend fraction operator * (const int A, const fraction F);
	friend fraction operator / (const fraction F, const int A);
	friend fraction operator / (const int A, const fraction F);
};