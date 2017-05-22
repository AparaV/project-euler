/* Problem 063: Powerful Digit Counts
 * Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>

using namespace std;

int answer() {
	/*
		Upper bound for the base is 9
			10^n-1 <= base^n
			n - 1 / n <= log10(base)
			n <= 1 / (1 - log10(base))
	*/

	int solution = 0;
	for (int x = 1; x < 10; ++x) {
		solution += floor(1.0 / (1.0 - log10(x)));
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