/** Problem 044: Pentagon numbers
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

inline bool isPentagonal(int64_t n) {
	double x = (1.0 + sqrt(1 + 24 * n)) / 6.0;
	return x == static_cast<int>(x);
}

int64_t answer() {
	int64_t D = 0;
	bool notFound = true;

	for (int64_t i = 2; notFound; ++i) {
		int64_t n = i * (3 * i - 1) / 2;
		for (int64_t j = 1; j < i; ++j) {
			int64_t m = j*(3 * j - 1) / 2;
			if (isPentagonal(n + m) && isPentagonal(n - m)) {
				D = n - m;
				notFound = false;
				break;
			}
		}
	}

	return D;
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