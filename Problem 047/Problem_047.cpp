/** Problem 047: Distinct prime factors
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int64_t numberOfPrimeFactors(int64_t n) {
	int64_t factors = 0;

	for (int64_t i = 2; i <= sqrt(n) + 1; ++i) {
		if (n % i == 0) {
			factors++;
			n /= i;
			while (n % i == 0) {
				n /= i;
			}
		}
	}

	if (n > 2) {
		factors++;
	}

	return factors;
}

int answer() {
	int n = -1;
	bool notFound = true;

	for (int i = 2; notFound; ++i) {
		int temp = i;
		int factors = numberOfPrimeFactors(temp);
		while (factors == 4 && temp < 4 + i) {
			temp++;
			factors = numberOfPrimeFactors(temp);
		}
		if (temp == 4 + i) {
			n = i;
			notFound = false;
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