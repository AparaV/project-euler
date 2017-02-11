/** Problem 041: Pandigital Prime
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

//Much faster than a vector implementation
bool* primeSieve(int64_t size) {

	bool* prime = new bool[size + 1];
	memset(prime, true, size + 1);				//faster than loops and vectors
	prime[0] = false;
	prime[1] = false;

	for (int p = 2; p*p <= size; p++) {
		if (prime[p] == true) {
			for (int i = p * 2; i <= size; i += p) {
				prime[i] = false;
			}
		}
	}
	return prime;
}

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

int answer() {
	bool* primes = primeSieve(7654321);			//98.. and 87.. are divisible by 3

	for (int i = 7654321; i >= 0; --i) {		//Start from end to get result faster
		if (primes[i] && isPandigital(i)) {
			return i;
		}
	}

	return 0;
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