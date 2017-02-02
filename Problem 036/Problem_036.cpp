/** Problem 036: Double base palindromes
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int BASE_10 = 10;
const int BASE_02 = 2;

bool isPalindrome(int number, int base) {
	int reversed = 0;
	int temp = number;
	
	while (temp > 0) {
		reversed = base * reversed + temp % base;
		temp /= base;
	}

	return number == reversed;
}

int answer() {
	int sum = 0;

	for (int i = 1; i < 1000000; ++i) {
		if (isPalindrome(i, BASE_10) && isPalindrome(i, BASE_02)) {
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