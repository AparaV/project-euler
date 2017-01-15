/** Problem 026: Reciprocal Cycles
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

int answer() {
	int maxdigits = 0;
	int maxdenom = 1;

	bool* prime = primesieve(1000);

	for (int i = 2; i < 1000; ++i) {
		if (prime[i] == false) {
			continue;
		}
		int remainder = 1;
		for (int j = 0; j < i; ++j) {
			remainder %= i;
			if (j != 0 && remainder == 1) {
				if (j > maxdigits) {
					maxdigits = j;
					maxdenom = i;
				}
				break;
			}
			remainder *= 10;
		}
	}
	
	return maxdenom;
}

int main() {

	cout << answer() << endl;

	return 0;
}