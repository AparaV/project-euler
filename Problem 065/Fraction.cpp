#include <iostream>
#include "Fraction.h"

Fraction::Fraction() {};

Fraction::Fraction(int n, int d) {
	if (d == 0) {
		cout << "Cannot divide by zero" << endl;
		d = 1;
	}
	num = n;
	den = d;
	simplify();
}

Fraction::~Fraction() {};

void Fraction::invert() {
	if (num == 0) {
		cout << "Cannot divide by zero" << endl;
		num = 1;
	}
	int temp = num;
	num = den;
	den = temp;
}

void Fraction::simplify() {
	int d = gcd(num, den);
	num /= d;
	den /= d;
}

void Fraction::add(Fraction f1) {
	num = num * f1.den + den * f1.num;
	den = den * f1.den;
	simplify();
}

void Fraction::add(int n) {
	Fraction f1(n, 1);
	add(f1);
}

int Fraction::gcd(int a, int b) {
	if (a == b) {
		return a;
	}
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (~a & 1) { //a is even
		if (b & 1) // b is odd
			return gcd(a >> 1, b);
		else // both a and b are even
			return gcd(a >> 1, b >> 1) << 1;
	}

	if (~b & 1) // a is odd, b is even
		return gcd(a, b >> 1);

	// reduce larger argument
	if (a > b)
		return gcd((a - b) >> 1, b);

	return gcd((b - a) >> 1, a);
}