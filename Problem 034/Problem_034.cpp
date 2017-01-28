/** Problem 034: Digit Factorials
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const int UPPER_BOUND = 2540160;

vector<int> factorialSieve(unsigned int n) {
	vector<int> factorials;
	factorials.push_back(1);

	for (int i = 1; i <= n; ++i) {
		factorials.push_back(i * factorials[i - 1]);
	}

	return factorials;
}

int64_t answer() {
	vector<int> factorials = factorialSieve(9);
	int64_t sum = 0;

	for (int i = 3; i < UPPER_BOUND; ++i) {
		int csum = 0;
		int number = i;
		while (number > 0) {
			int d = number % 10;
			number /= 10;
			csum += factorials[d];
		}
		if (csum == i) {
			sum += i;
		}
	}

	return sum;
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