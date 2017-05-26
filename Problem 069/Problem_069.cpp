/* Problem 069: Totient Maximum
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> primeList(int upperLimit);

int answer() {
	int n = 1, limit = 1000000, i = 0;
	vector<int> primes = primeList(limit);

	while (primes[i] * n < limit) {
		n *= primes[i];
		i++;
	}
	
	return n;
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

vector<int> primeList(int upperLimit) {
	vector<int> primes;
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