/** Problem 027: Quadratic Primes
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>

using namespace std;

bool* primesieve(int size) {
	bool* prime = new bool[size + 1];

	for (int i = 0; i <= size; ++i) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= size; ++i) {
		if (prime[i] == false) {
			continue;
		}
		prime[i] = true;
		for (int j = 2; j <= size / i; ++j) {
			prime[i * j] = false;
		}
	}

	return prime;
}

inline int func(int n, int a, int b) { return n*n + a*n + b; }

int answer() {
	bool* prime = primesieve(100000);
	int nmax = 0;
	int prod = 0;

	for (int a = -999; a < 1000; ++a) {
		for (int b = 0; b <= 1000; ++b) {
			//n = 0 should yield a prime i.e., b should be a prime
			if (!prime[b] || nmax >= b) {
				continue;
			}
			int n = 0;
			int e = func(n, a, b);
			while (e > 1 && prime[e]) {
				n++;
				e = func(n, a, b);
			}
			if (n > nmax) {
				nmax = n;
				prod = a * b;
			}
		}
	}

	return prod;
}


int main() {

	cout << answer() << endl;

	return 0;
}