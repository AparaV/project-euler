/** Problem 049: Prime Permutations
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

bool isPermutation(int n, int m) {
	int A = 0, B = 0, temp;
	while (n > 0) {
		temp = A;
		A |= (1 << static_cast<int>((n % 10) - 1));
		n /= 10;
	}
	while (m > 0) {
		temp = B;
		B |= (1 << static_cast<int>((m % 10) - 1));
		m /= 10;
	}
	return A == B;
}

vector<int> primeList(int upperLimit) {
	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i <= upperLimit; i += 2) {
		bool prime = true;
		for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; ++j) {
			if (i % primes[j] == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			primes.push_back(i);
		}
	}

	return primes;
}

int64_t concat_int(int64_t a, int64_t b) {
	int temp = b;
	while (temp > 0) {
		a *= 10;
		temp /= 10;
	}
	return a + b;
}

int64_t answer() {
	vector<int> primes = primeList(10000);
	int64_t result = 0;

	for (int i = 0; i < primes.size(); ++i) {
		if (primes[i] >= 1000) {
			for (int j = i + 1; j < primes.size(); ++j) {
				int k = 2 * primes[j] - primes[i];
				if (isPermutation(primes[i], k) && isPermutation(primes[j], k)) {
					vector<int>::iterator it = find(primes.begin(), primes.end(), k);
					if (it != primes.end()) {
						result = concat_int(primes[i], primes[j]);
						result = concat_int(result, k);
						break;
					}
				}
			}
		}
	}

	return result;
}

int main() {

	clock_t start = clock();
	int64_t solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}