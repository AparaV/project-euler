/** Problem 035: Circular Primes
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <set>
#include <cmath>
#include <ctime>

using namespace std;

bool* primesieve(int64_t size) {
	bool* prime = new bool[size + 1];

	for (int64_t i = 0; i <= size; ++i) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for (int64_t i = 2; i <= size; ++i) {
		if (prime[i] == false) {
			continue;
		}
		prime[i] = true;
		for (int64_t j = 2; j <= size / i; ++j) {
			prime[i * j] = false;
		}
	}

	return prime;
}

int checkCircularPrime(int prime, bool primes[]) {
	if (!primes[prime]) {
		return 0;
	}
	if (prime < 10) {
		return 1;
	}
	int number = prime;
	int digits = 0;
	set<int> collection;
	collection.insert(prime);
	
	while (number > 0) {
		int d = number % 10;
		//Circular primes cannot contain digits 0,2,4,5,6,8
		if (d % 2 == 0 || d % 5 == 0) {
			return 0;
		}
		digits++;
		number /= 10;
	}

	int multiplier = pow(10, digits - 1);

	//Rotating the number
	for (int i = 0; i < digits; ++i) {
		if (primes[prime]) {
			collection.insert(prime);
			primes[prime] = false;
		}
		else if (collection.find(prime) == collection.end()) {
			return 0;
		}
		int temp = prime % 10;
		prime = temp * multiplier + prime / 10;
	}

	return collection.size();
}

int answer(int limit) {
	bool* primes = primesieve(limit);
	int count = 0;

	for (int i = 2; i <= limit; ++i) {
		count += checkCircularPrime(i, primes);
	}

	return count;
}

int main() {

	clock_t start = clock();
	int solution = answer(1000000);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}