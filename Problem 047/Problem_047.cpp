/** Problem 047: Distinct prime factors
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <map>
#include <cmath>
#include <ctime>

using namespace std;

map<int, int> primeFactorization(int n) {
	map<int, int> factors;
	int size = sqrt(n) + 1;

	for (int i = 2; i <= size; ++i) {
		if (n % i == 0) {
			factors[i] = 1;
			n /= i;
			while (n % i == 0) {
				factors[i]++;
				n /= i;
			}
		}
	}

	if (n > 2) {
		factors[n] = 1;
	}

	return factors;
}

int answer() {
	int n = -1;
	bool notFound = true;

	for (int i = 2; notFound; ++i) {
		int temp = i;
		map<int, int> factors = primeFactorization(temp);
		while (factors.size() == 4 && temp < 4 + i) {
			temp++;
			factors = primeFactorization(temp);
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