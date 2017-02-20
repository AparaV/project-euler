/** Problem 003: Largest Prime Factor
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int64_t largestPrimeFactor(int64_t num) {
	int64_t largestFactor = 0;
	int64_t sqrtNum = sqrt(num) + 1;

	for (int64_t i = 2; i < sqrtNum; ++i) {
		if (num % i == 0) {
			largestFactor = i;
			num /= i;
			while (num %i == 0) {
				num /= i;
			}
		}
	}

	return largestFactor;
}

int64_t answer() {
	return largestPrimeFactor(600851475143);
}

int main(){

	clock_t start = clock();
	int64_t solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

    return 0;
}


