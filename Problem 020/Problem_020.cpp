/** Problem 020: Sum of digits of factorial
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>

using namespace std;

unsigned int factorialandsum(int size) {
	unsigned int fact[10000], first = 0, last = 0, sum = 0;

	//Find factorial
	fact[0] = 1;
	for (int n = 2; n <= size; n++) {
		int carry = 0;
		for (int i = first; i <= last; ++i) {
			carry = fact[i] * n + carry;
			fact[i] = carry % 100000;
			if (i == first && !(carry % 100000)) {
				first++;
			}
			carry /= 100000;
		}
		if (carry != 0) {
			last++;
			fact[last] = carry;
		}
	}

	//Sum array
	for (int i = first; i <= last; ++i) {
		sum += (fact[i] % 10) + ((fact[i] / 10) % 10) + ((fact[i] / 100) % 10) + ((fact[i] / 1000) % 10) + ((fact[i] / 10000) % 10);
	}

	return sum;
}



int main() {

	cout << factorialandsum(100) << endl;

	return 0;
}