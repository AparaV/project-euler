#include <iostream>
#include <cmath>

using namespace std;

const double PHI = 1.61803398875;

int fibonacci_index(int digit) {
	int n = (log(10) * (digit - 1) + 0.5 * log(5)) / log(PHI) + 1;
	return n;
}

int main() {

	cout << fibonacci_index(1000) << endl;

	return 0;
}