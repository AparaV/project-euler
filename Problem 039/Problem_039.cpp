/** Problem 039: Integer Right Triangles
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

/*
	a^2 + b^2 = c^2
	a + b + c = p
	c = p - a - b
	a^2 + b^2 = p^2 + a^2 + b^2 - 2pa + 2ab - 2bp
	2b(a - p) = p(2p - a)
	b = p(a - 2p)/2(a - p)
	b is an integer
*/
int answer() {
	int maxPossibilities = 0;
	int solution = 0;
	for (int p = 3; p <= 1000; ++p) {
		int currPossibilities = 0;
		for (int a = 1; a < p / 3; ++a) {
			if ((p*(a - 2 * p)) % (2 * (a - p)) == 0) {
				currPossibilities++;
			}
		}
		if (maxPossibilities < currPossibilities) {
			maxPossibilities = currPossibilities;
			solution = p;
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