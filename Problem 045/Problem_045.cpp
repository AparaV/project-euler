/** Problem 045: Triangular, Pentagonal, and Hexagonal
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

bool isTriangular(int64_t n) {
	double temp = (sqrt(1 + 8 * n) - 1.0) / 2.0;
	return (temp == static_cast<int>(temp));
}

bool isPentagonal(int64_t n) {
	double x = (1.0 + sqrt(1 + 24 * n)) / 6.0;
	return x == static_cast<int>(x);
}

int64_t answer() {
	int64_t solution;
	bool notFound = true;

	for (int i = 1; notFound; ++i) {
		int64_t n = i*(2 * i - 1);
		//All triangular numbers are also hexagonal
		if (isPentagonal(n)) {
			if (n > 40755) {
				notFound = false;
			}
			solution = n;
		}
	}

	return solution;
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