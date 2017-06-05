/* Problem 075: Singular integer right triangles
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b);

int answer() {
	int result = 0, limit = 1500000;
	vector<int> permutations(limit + 1, 0);
	int mLimit = sqrt(limit / 2) + 1;

	for (int m = 2; m < mLimit; ++m) {
		for (int n = 1; n < m; ++n) {
			if ((n + m) % 2 == 0 || gcd(n, m) != 1) continue;
			int a = m * m - n * n;
			int b = 2 * m * n;
			int c = m * m + n * n;
			int L = a + b + c;
			while (L <= limit) {
				permutations[L]++;
				if (permutations[L] == 1) result++;
				if (permutations[L] == 2) result--;
				L += a + b + c;
			}
		}
	}

	return result;
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