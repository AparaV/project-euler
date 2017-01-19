/** Problem 029: Distinct Powers
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <ctime>
#include <cmath>
#include <map>
#include <set>

using namespace std;

map<int, int> prime_factorization(int n) {
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

int answer(int start, int end) {
	set<map<int, int>> powers;

	for (int i = start; i <= end; ++i) {
		map<int, int> factors = prime_factorization(i);
		for (int i = start; i <= end; ++i) {
			map<int, int> temp(factors);
			for (auto &p : temp) {
				p.second *= i;
			}
			powers.insert(temp);
		}
	}

	return powers.size();
}

int main() {

	clock_t start = clock();
	int solution = answer(2, 100);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}