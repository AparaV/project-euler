/** Problem 048: Self Powers
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <ctime>

using namespace std;

int64_t answer() {
	int64_t result = 0;
	int64_t digits = 10000000000;

	for (int64_t i = 1; i <= 1000; ++i) {
		int64_t temp = i;
		for (int64_t j = 1; j < i; ++j) {
			temp *= i;
			temp %= digits;
		}
		result += temp;
		result %= digits;
	}

	return result;
}

int main() {

	clock_t start = clock();
	int64_t solution = answer();
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}