/** Problem 052: Permuted multiples
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>

using namespace std;

bool isPermutation(int n, int m) {
	int* map = new int[10];
	int temp = n;
	while (temp > 0) {
		map[temp % 10]++;
		temp /= 10;
	}
	temp = m;
	while (temp > 0) {
		map[temp % 10]--;
		temp /= 10;
	}
	for (int i = 0; i < 10; ++i) {
		if (map[i] != 0) {
			return false;
		}
	}
	return true;
}

int64_t answer() {
	int64_t n = -1;
	bool found = false;
	int tens = 10;
	while (!found) {
		for (int i = tens; i < tens * 10 / 6; ++i) {
			int64_t temp = i;
			found = true;
			for (int j = 2; j < 7; ++j) {
				temp = j * i;
				if (!isPermutation(temp, i)) {
					found = false;
					break;
				}
			}
			if (found) {
				n = i;
				break;
			}
		}
		tens *= 10;
	}

	return n;
}

int main() {

	clock_t start = clock();
	int64_t solution = answer();
	clock_t end = clock();
	float time = static_cast<float>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;

	return 0;
}