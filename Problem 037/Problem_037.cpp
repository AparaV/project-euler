/** Problem 037: Truncatable Primes
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <ctime>

using namespace std;

bool* primesieve(int64_t size) {
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
	int sum = 0;
	int truncatablePrimes = 0;
	bool* primes = primesieve(999999);
	int n = 10;

	//adapted from http://www.mathblog.dk/project-euler-37-truncatable-primes/
	while (truncatablePrimes < 11) {
		n++;
		if (!primes[n]) {
			continue;
		}
		int right = n;
		int left = 0;
		int multiplier = 1;
		bool isTruncatable = true;
		while (right > 0 && isTruncatable) {
			left += multiplier * (right % 10);
			isTruncatable = primes[left] && primes[right];
			right /= 10;
			multiplier *= 10;
		}
		if (isTruncatable) {
			truncatablePrimes++;
			sum += n;
		}
	}

	return sum;
}

int main() {

	clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}