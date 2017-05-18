/* Problem 060: Prime Pair Sets
 * Author: Aparajithan Venkateswaran
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> primeList(int upperLimit);
int concat(int a, int b);
bool isPrime(int64_t n);
set<int> makePairs(int k, vector<int> primes);

int answer() {
	/*
		First finds all primes
		Then creates a set of all primes that can be concatenated with to produce another prime
		Then intersections of these sets are created to produce sets with carinality >= 5
		The minimum sum is then found
		Adapted from www.mathblog.dk
	*/

	vector<int> primes = primeList(10000);
	vector<set<int>> sets;
	sets.resize(primes.size());
	int result = INT32_MAX;

	for (int a = 0; a < primes.size(); ++a) {
		if (primes[a] * 5 >= result) break;
		if (sets[a].empty()) sets[a] = makePairs(a, primes);

		for (int b = a + 1; b < primes.size(); ++b) {
			if (primes[a] + primes[b] * 4 >= result) break;
			if (sets[a].find(primes[b]) == sets[a].end()) continue;
			if (sets[b].empty()) sets[b] = makePairs(b, primes);
			set<int> I1;
			set_intersection(sets[a].begin(), sets[a].end(), sets[b].begin(), sets[b].end(), std::inserter(I1, I1.begin()));
			if (I1.empty()) {
				continue;
			}

			for (int c = b + 1; c < primes.size(); ++c) {
				if (primes[a] + primes[b] + primes[c] * 3 >= result) break;
				if (I1.find(primes[c]) == I1.end()) continue;
				if (sets[c].empty()) sets[c] = makePairs(c, primes);
				set<int> I2;
				set_intersection(I1.begin(), I1.end(), sets[c].begin(), sets[c].end(), std::inserter(I2, I2.begin()));
				if (I2.empty()) {
					continue;
				}

				for (int d = c + 1; d < primes.size(); ++d) {
					if (primes[a] + primes[b] + primes[c] + primes[d] * 2 >= result) break;
					if (I2.find(primes[d]) == I2.end()) continue;
					if (sets[d].empty()) sets[d] = makePairs(d, primes);
					set<int> I3;
					set_intersection(I2.begin(), I2.end(), sets[d].begin(), sets[d].end(), std::inserter(I3, I3.begin()));
					if (I3.empty()) continue;

					if ( primes[a] + primes[b] + primes[c] + primes[d] + *I3.begin() < result) {
						result = primes[a] + primes[b] + primes[c] + primes[d] + *I3.begin();
					}
				}
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

vector<int> primeList(int upperLimit) {
	vector<int> primes;
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

int concat(int a, int b) {
	int temp = b;
	while (temp > 0) {
		a *= 10;
		temp /= 10;
	}
	return a + b;
}

bool isPrime(int64_t n) {
	if (n <= 1) {
		return false;
	}
	for (int64_t i = 2; i * i <= n; ++i) {
		if (n %i == 0) {
			return false;
		}
	}
	return true;
}


set<int> makePairs(int k, vector<int> primes) {
	set<int> pairs;
	for (int i = k + 1; i < primes.size(); ++i) {
		if (isPrime(concat(primes[i], primes[k])) && isPrime(concat(primes[k], primes[i]))) {
			pairs.insert(primes[i]);
		}
	}
	return pairs;
}
