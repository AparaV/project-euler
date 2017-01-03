/** Problem 014: Largest Collatz Sequence
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>

using std::cout;
using std::endl;

int64_t nextnumber(int64_t a) {
	if (a % 2 == 0) {
		return a / 2;
	}
	return 3 * a + 1;
}

int64_t collatzsequence_len(int64_t n) {
	int64_t count = 1;
	
	while (n != 1) {
		n = nextnumber(n);
		count++;
	}

	return count;
}

int64_t answer() {
	int64_t max;
	int64_t number;
	for (int64_t i = 1; i <= 1000000; ++i) {
		int64_t curr = collatzsequence_len(i);
		if (i == 1 || curr > max) {
			max = curr;
			number = i;
		}
	}
	return number;
}

int main() {
	
	std::cout << answer() << std::endl;

	return 0;
}