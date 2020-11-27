#pragma once

#include <iostream>

class fraction
{
private:
	int *numerator = nullptr,
		*denominator = nullptr;
	char *str = nullptr;
	static int count;

	inline long long int abs(long long int a);
	long long int NOD(long long int a, long long int b);
	long long int NOK(long long int a, long long int b);

	void str1();
	void str2();
	void MakeStr();

	fraction sum(const fraction&);
	fraction dif(const fraction&);
	fraction multi(const fraction&);
	fraction div(const fraction&);

public:
	fraction();
	fraction(int Numerator, int Denominator);
	fraction(const fraction &F);
	virtual ~fraction();

	virtual char* get();
	char* getStr();
	int getNumerator();
	int getDenominator();
	static int getCount();

	void setNumerator(int Numerator);
	void setDenominator(int Denominator);

	fraction& operator = (const fraction&);
	fraction operator + (const fraction&);
	fraction operator - (const fraction&);
	fraction operator * (const fraction&);
	fraction operator / (const fraction&);

	operator float();

	friend fraction operator + (const fraction F, const int A);
	friend fraction operator + (const int A, const fraction F);
	friend fraction operator - (const fraction F, const int A);
	friend fraction operator - (const int A, const fraction F);
	friend fraction operator * (const fraction F, const int A);
	friend fraction operator * (const int A, const fraction F);
	friend fraction operator / (const fraction F, const int A);
	friend fraction operator / (const int A, const fraction F);

	friend std::ostream& operator << (std::ostream& out, const fraction &F);
	friend std::istream& operator >> (std::istream& in, fraction &F);

	virtual bool readBin(std::ifstream& in);
	virtual void writeBin(std::ofstream& out);

};