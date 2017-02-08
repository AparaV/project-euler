/** Problem 038: Pandigital multiples
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

//adapted from http://stackoverflow.com/a/2485016/5055644
bool isPandigital(int n) {
	int count = 0, digits = 0, temp;

	while (n > 0) {
		temp = digits;
		digits |= (1 << (int)((n % 10) - 1));
		if (temp == digits) {
			return false;
		}
		count++;
		n /= 10;
	}

	return digits == (1 << count) - 1;
}

int64_t concat_int(int64_t first, int64_t second) {
	int temp;
	temp = second;
	while (temp > 0) {
		first *= 10;
		temp /= 10;
	}
	return first + second;
}

int answer() {
	int maxPan = 0;
	for (int i = 2; i < 10000; ++i) {
		int current = i;
		for (int j = 2; j < 5; ++j) {
			int temp = i * j;
			current = concat_int(current, temp);
			if (isPandigital(current)) {
				maxPan = max(current, maxPan);
				break;
			}
			if (current > 987654321) {
				break;
			}
			j++;
		}
	}
	return maxPan;
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