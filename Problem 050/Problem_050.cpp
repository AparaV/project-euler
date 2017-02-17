/** Problem 050: Consecutive prime sum
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> primeList(int upperLimit) {
	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i <= upperLimit; i += 2) {
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

int answer() {
	int upperLimit = 1000000;
	vector<int> primes = primeList(upperLimit);
	vector<int> sum;
	int max = -1;
	int maxCount = 0;
	sum.push_back(primes[0]);

	for (int i = 1; i < primes.size(); ++i) {
		int currentSum = sum[i - 1] + primes[i];
		if (currentSum > upperLimit) {
			break;
		}
		sum.push_back(currentSum);
	}

	for (int i = sum.size() - 1; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			int count = i - j;
			if (count > maxCount) {
				int currSum = sum[i] - sum[j];
				vector<int>::iterator it = find(primes.begin(), primes.end(), currSum);
				if (it != primes.end()) {
					max = currSum;
					maxCount = count;
				}
			}
		}
	}

	return max;
}


int main() {

	clock_t start = clock();
	int64_t solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}