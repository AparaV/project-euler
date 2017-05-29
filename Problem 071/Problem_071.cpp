/* Problem 070: Ordered Fractions
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>

using namespace std;

/*
	we want a fraction p/q  < a/b = 3/7
	p*b < a*q
	p*b < a*q - 1 (all are integers)
	p = floor((a*q - 1)/b)

	to make sure we find the greatest such p/q
	we start at r/s (= 0/1) and find the next
	possible fraction. then compare it and
	choose the largest such r/s as p/q
*/
int answer() {
	int64_t a = 3, b = 7, r = 0, s = 1;
	int limit = 1000000;

	for (int64_t q = limit; q > 2; --q) {
		int64_t p = (a * q - 1) / b;
		if (p * s > r * q) {
			s = q;
			r = p;
		}
	}
	cout << "The fraction we found is " << r << "/" << s << endl;

	return r;
}

int main() {

	clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;

	return 0;
}