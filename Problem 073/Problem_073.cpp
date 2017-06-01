/* Problem 073: Counting Fractions in a range
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b);

int answer() {
	int count = 0, limit = 12000;

	for (int i = limit; i > 2; --i) {
		for (int j = i / 3 + 1; j < (i - 1) / 2 + 1; ++j) {
			if (gcd(i, j) == 1) {
				count++;
			}
		}
	}

	return count;
}

int main() {

	clock_t start = clock();
	uint64_t solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;

	return 0;
}

int gcd(int a, int b) {
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