/* Problem 074: Digit Factorial Chains
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int64_t> fact(int64_t n);
int64_t sumFac(int64_t n);

vector<int64_t> f = fact(9);

int answer() {
	int result = 0, limit = 1000000;
	vector<int> counts(limit + 1, 0);

	for (int i = 1; i <= limit; ++i) {
		vector<int64_t> cache;
		int64_t sum = sumFac(i), count = 1;

		while (sum != i) {
			// check if this number was already encountered in the chain
			if (find(cache.begin(), cache.end(), sum) != cache.end()) {
				break;
			}
			// check if the count for this sum has already been calculated
			if (sum <= limit && counts[sum] != 0) {
				count += counts[sum];
				break;
			}
			cache.push_back(sum);
			sum = sumFac(sum);
			count++;
		}

		counts[i] = count;
		if (count >= 60) {
			result++;
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

vector<int64_t> fact(int64_t n) {
	vector<int64_t> out;
	out.push_back(1);
	out.push_back(1);
	for (int64_t i = 2; i <= n; ++i) {
		out.push_back(i * out[i - 1]);
	}
	return out;
}

int64_t sumFac(int64_t n) {
	int64_t sum = 0;
	while (n > 0) {
		sum += f[n % 10];
		n /= 10;
	}
	return sum;
}