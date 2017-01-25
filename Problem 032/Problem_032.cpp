/** Problem 032: Pandigital Products
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <set>
#include <ctime>

using namespace std;

//method borrowed from http://stackoverflow.com/a/2485016/5055644
bool isPandigital(int n) {
	if (n > 987654321 || n < 123456789) {
		return false;
	}
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

int64_t concat_int(int64_t a, int64_t b) {
	int temp;
	if (a > b) {
		temp = b;
		while (temp > 0) {
			a *= 10;
			temp /= 10;
		}
		return a + b;
	}
	else {
		temp = a;
		while (temp > 0) {
			b *= 10;
			temp /= 10;
		}
		return a + b;
	}
}

int64_t answer() {
	set<int> products;

	for (int a = 2; a < 100; ++a) {
		int begin = (a > 9) ? 100 : 1000;
		int end = 10000 / a + 1;
		for (int b = begin; b < end; ++b) {
			int64_t prod = a * b;
			int64_t compiled = concat_int(prod, concat_int(a, b));
			if (isPandigital(compiled)) {
				products.insert(prod);
			}
		}
	}

	int64_t sum = 0;
	for (set<int>::iterator it = products.begin(); it != products.end(); ++it) {
		sum += *it;
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