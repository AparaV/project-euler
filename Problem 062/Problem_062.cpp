/* Problem 062: Cubic Permutations
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cube {
	int64_t sorted;
	vector<int> numbers;
};

int64_t sort(int64_t cube);

int64_t answer() {
	vector<Cube> cubes;
	int64_t n = 300;
	int64_t result = -1;
	bool found = false;
	while (!found) {
		int64_t perm = sort(n*n*n);
		bool present = false;
		for (int i = 0; i < cubes.size(); ++i) {
			if (cubes[i].sorted == perm) {
				present = true;
				cubes[i].numbers.push_back(n);
				if (cubes[i].numbers.size() == 5) {
					n = cubes[i].numbers[0];
					result = n*n*n;
					found = true;
				}
				break;
			}
		}
		if (!present) {
			Cube newC;
			newC.sorted = perm;
			newC.numbers.push_back(n);
			cubes.push_back(newC);
		}
		n++;
	}
	return result;
}

int main() {

	clock_t start = clock();
	int64_t solution = answer();
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}

int64_t sort(int64_t cube) {
	vector<int> list;
	while (cube > 0) {
		list.push_back(cube % 10);
		cube /= 10;
	}
	sort(list.begin(), list.end());
	cube = 0;
	for (int i = list.size() - 1; i >= 0; --i) {
		cube = cube * 10 + list[i];
	}
	return cube;
}