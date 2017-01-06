/** Problem 021: Amicable Numbers
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> non_amicable;
vector<int> amicable;

int64_t sum_properdivisors(int64_t n) {
	int64_t sum = 1;
	for (int i = 2; i < sqrt(n); ++i) {
		if (n % i == 0) {
			sum += i;
			sum += n / i;
		}
	}
	return sum;
}

void find_numbers(int limit) {

	for (int64_t count = 2; count < limit; count++) {

		if (find(amicable.begin(), amicable.end(), count) != amicable.end()) {
			continue;
		}
		if (find(non_amicable.begin(), non_amicable.end(), count) != non_amicable.end()) {
			continue;
		}

		int64_t complement = sum_properdivisors(count);
		if (count == sum_properdivisors(complement) && count != complement) {
			amicable.push_back(count);
			amicable.push_back(complement);
		}
		else {
			non_amicable.push_back(count);
			non_amicable.push_back(complement);
		}
	}
}

int64_t sumvector() {
	int64_t sum = 0;
	for (int i = 0; i < amicable.size(); ++i) {
		sum += amicable[i];
	}
	return sum;
}

int main() {

	find_numbers(10000);
	cout << sumvector() << endl;

	return 0;
}