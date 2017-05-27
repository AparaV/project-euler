/* Problem 070: Totient Permutation
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int64_t> primeList(int upperLimit);
vector<int> sortInt(int n);
bool isPermutation(int a, int b);

int answer() {
	int result = 0, limit = 10000000;
	double bestRatio = INT32_MAX;
	vector<int64_t> primes = primeList(limit);

	for (int i = 0; i < primes.size(); ++i) {
		for (int j = i + 1; j < primes.size(); ++j) {
			int64_t n = primes[i] * primes[j];
			if (n > limit) break;
			int phi = (primes[i] - 1) * (primes[j] - 1);
			double ratio = static_cast<double>(n) / phi;
			if (isPermutation(phi, n) && ratio < bestRatio) {
				bestRatio = ratio;
				result = n;
			}
		}
	}

	return result;
}

int main() {

	clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;

	return 0;
}

vector<int64_t> primeList(int upperLimit) {
	vector<int64_t> primes;
	primes.push_back(2);
	for (int64_t i = 3; i <= upperLimit; i += 2) {
		bool prime = true;
		for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; ++j) {
			if (i % primes[j] == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			primes.push_back(i);
		}
	}
	return primes;
}

vector<int> sortInt(int n) {
	vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	sort(digits.begin(), digits.end());
	return digits;
}

bool isPermutation(int a, int b) {
	vector<int> digitsA = sortInt(a);
	vector<int> digitsB = sortInt(b);
	if (digitsA.size() != digitsB.size()) return false;
	for (int i = 0; i < digitsA.size(); ++i)
		if (digitsA[i] != digitsB[i]) return false;
	return true;
}