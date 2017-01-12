/** Problem 023: Non-abundant sums
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int LIMIT = 28123;

int64_t sum_proper_divisors(int n) {
	int64_t sum = 1; //1 is a factor
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			sum += i;
			if (i != sqrt(n)) {
				sum += n / i;
			}
		}
	}
	return sum;
}

vector<int> find_abundant_numbers(int limit) {
	vector<int> abundant;
	for (int i = 2; i <= limit; ++i) {
		if (sum_proper_divisors(i) > i) {
			abundant.push_back(i);
		}
	}
	return abundant;
}

int64_t answer() {
	vector<int> abundant = find_abundant_numbers(LIMIT);
	bool* numbers = new bool[LIMIT + 1];
	for (int i = 0; i <= LIMIT; ++i) {
		numbers[i] = false;
	}
	for (int i = 0; i < abundant.size(); ++i) {
		for (int j = i; j < abundant.size(); ++j) {
			int64_t sum = (abundant[i] + abundant[j]);
			if (sum <= LIMIT) {
				//cout << sum << endl;
				numbers[sum] = true;
			}
		}
	}
	int64_t answer = 0;
	for (int i = 1; i <= LIMIT; ++i) {
		if (numbers[i] == false) {
			answer += i;
		}
	}
	return answer;
}

int main() {

	cout << answer() << endl;

	return 0;
}