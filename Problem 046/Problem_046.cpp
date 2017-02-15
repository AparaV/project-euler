/** Problem 046: Goldbach's Other Conjecture
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

bool isPerfectSquare(int64_t n) {
	double x = sqrt(n);
	return x == static_cast<int>(x);
}

//Much faster than a vector implementation
bool* primeSieve(int64_t size) {

	bool* prime = new bool[size + 1];
	memset(prime, true, size + 1);				//faster than loops and vectors
	prime[0] = false;
	prime[1] = false;

	for (int p = 2; p*p <= size; p++) {
		if (prime[p] == true) {
			for (int i = p * 2; i <= size; i += p) {
				prime[i] = false;
			}
		}
	}
	return prime;
}

int64_t answer() {
	int64_t n;
	bool notFound = true;
	bool* primes = primeSieve(10000);

	for (int64_t i = 5; notFound; i += 2) {
		if (primes[i]) {
			continue;
		}
		for (int64_t j = 1; j < 10000; ++j) {
			if (primes[j] && primes[j] < i) {
				if (!isPerfectSquare((i - j) / 2)) {
					n = i;
					notFound = false;
				}
				else {
					notFound = true;
					break;
				}
			}
		}
	}

	return n;
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