/** Problem 058: Sprial Primes
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>

using namespace std;

bool isPrime(int64_t n) {
	if (n <= 1) {
		return false;
	}
	for (int64_t i = 2; i * i <= n; ++i) {
		if (n %i == 0) {
			return false;
		}
	}
	return true;
}

int answer() {
	int64_t size = 700000000;
	int* spiral = new int[size + 1];
	for (int i = 0; i <= size; ++i) {
		spiral[i] = i;
	}
	int totalPrimes = 0, current = 3, corner = 1, side = 2;

	while (current <= size) {
		if (isPrime(current)) {
			totalPrimes++;
		}
		if (corner == 4) {
			int diagonals = 2 * side - 1;
			float ratio = static_cast<float>(totalPrimes) / diagonals;
			if (ratio < 0.1) {
				side--;
				break;
			}
			side += 2;
			corner = 0;
		}
		current += side;
		corner++;
	}

	return side;
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