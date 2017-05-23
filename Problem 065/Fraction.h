#pragma once

#include <iostream>

using namespace std;

class Fraction {
public:
	int num;
	int den;
	Fraction();
	Fraction(int n, int d);
	~Fraction();
	void invert();
	void simplify();
	void add(Fraction f1);
	void add(int n);
private:
	int gcd(int a, int b);
};
