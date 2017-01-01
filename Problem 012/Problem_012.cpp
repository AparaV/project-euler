/**Problem 012: Highest Triangular Number
 **Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>

inline int triangle(int n) { return n * (n + 1) / 2; }

int factors(int n) {
	int count = 0;

	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			count++;
			if (i != n / i) {
				count++;
			}
		}
	}

	return count;
}

int answer(int limit) {
	int fact = 0, number = 0;

	for (int i = 1; fact <= limit; ++i) {
		number = triangle(i);
		fact = factors(number);
	}

	return number;
}

int main() {

	std::cout << answer(500) << std::endl;
	return 0;
}