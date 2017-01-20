/** Problem 030: Digit Fifth Powers
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int UPPER_BOUND = 6 * pow(9, 5);

vector<int> digitize(unsigned int n) {
	vector<int> digits;

	while (n != 0) {
		digits.push_back(n % 10);
		n /= 10;
	}

	reverse(digits.begin(), digits.end());

	return digits;
}

int answer() {
	unsigned int sum = 0;
	vector<int> powers;

	//Caching powers
	for (int i = 0; i < 10; ++i) {
		powers.push_back(pow(i, 5));
	}

	for (unsigned int i = 2; i <= UPPER_BOUND; ++i) {
		
		//skipping process if a power of 10
		int temp = i;
		while (temp % 10 == 0) {
			temp /= 10;
		}
		if (temp == 1) {
			continue;
		}

		//digitizing and checking condition
		vector<int> digits = digitize(temp);
		int power_sum = 0;
		for (int i = 0; i < digits.size(); ++i) {
			power_sum += powers[digits[i]];
		}
		if (power_sum == i) {
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