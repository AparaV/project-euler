/* Problem 072: Counting Fractions
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <vector>

using namespace std;

uint64_t answer() {
	uint64_t count = 0, limit = 1000000;
	vector<uint64_t> phi(limit + 1, 0);

	for (uint64_t i = 2; i <= limit; ++i) {
		phi[i] = i;
	}
	for (uint64_t i = 2; i <= limit; ++i) {
		if (phi[i] == i) {
			for (uint64_t j = i; j <= limit; j += i) {
				phi[j] = phi[j] * (i - 1) / i;
			}
		}
		count += phi[i];
	}


	return count;
}

int main() {

	clock_t start = clock();
	uint64_t solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;
 
	return 0;
}