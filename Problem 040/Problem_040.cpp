/** Problem 040: Champernowne's Constant
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

/*
	Find the number n such that the number of digits of all numbers
	from 1 through n is greater than maxDigits.
	For a number with i digits, there are 10^i - 1 numbers
	Hence there are i * (10^i - 1) digits contained
*/
int upperLimit(int maxDigits) {
	int digits = 1;
	int multiper = 1;
	int number = 0;
	while (number < maxDigits) {
		multiper *= 10;
		number += digits * (multiper - 1);
		digits++;
	}
	return multiper - 1;
}

int answer() {
	int n = upperLimit(1000000);

	stringstream ss;
	for (int i = 1; i <= n; ++i) {
		ss << i;
	}
	string champernowne = ss.str();

	n = 1;
	int total = 1;
	for (int i = 0; i < 6; ++i) {
		total *= champernowne[n - 1] - '0';
		n *= 10;
	}
	return total;
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