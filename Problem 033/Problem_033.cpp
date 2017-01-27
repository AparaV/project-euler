/** Problem 033: Digit Cancelling Fractions
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <ctime>

using namespace std;

//	Only the following forms are possible:
//		(10n + i)/(10i + d) = n/d
//	Other forms do not satisfay the condition n < d or are contradicting
int answer() {
	int denProd = 1;
	int numProd = 1;

	for (int i = 1; i < 10; ++i) {
		for (int d = 2; d < i; ++d) {
			for (int n = 1; n < d; ++n) {
				// (10n + i)/(10i + d) = n/d
				// d*(10n + 1) = n*(10i + d)
				if (d * (10 * n + i) == n * (10 * i + d)) {
					denProd *= d;
					numProd *= n;
				}
			}
		}
	}

	return denProd / numProd;
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