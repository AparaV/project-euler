/* Problem 064: Odd period square roots
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Triplet {
	int m;
	int d;
	int a;
	Triplet() { m = 0; d = 0; a = 0; }
};

bool operator== (Triplet a, Triplet b) {
	if (a.m == b.m && a.a == b.a && a.d == b.d) {
		return true;
	}
	return false;
}

int answer() {
	/* Algorithm from https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion */

	int odds = 0;

	for (int i = 1; i <= 10000; ++i) {
		double temp = sqrt(i);
		if (temp == static_cast<int>(temp)) {
			continue;
		}
		vector<Triplet> sequence;
		int S = floor(sqrt(i));
		Triplet n, n1;
		n.a = S;
		n.m = 0;
		n.d = 1;
		while (true) {
			bool found = false;
			n1.m = n.d * n.a - n.m;
			n1.d = (i - n1.m * n1.m) / n.d;
			n1.a = floor((S + n1.m) / n1.d);
			if (find(sequence.begin(),sequence.end(), n1) != sequence.end()) {
				break;
			}
			else {
				sequence.push_back(n1);
				n.a = n1.a;
				n.d = n1.d;
				n.m = n1.m;
			}
		}
		if (sequence.size() % 2 == 1) {
			odds++;
		}
	}

	return odds;
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