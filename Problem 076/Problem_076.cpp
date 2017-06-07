/* Problem 076: Counting sums
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <vector>

using namespace std;

int answer() {
	vector<int> partitions(101, 0);
	partitions[0] = 1;

	for (int i = 1; i <= 99; ++i) {
		for (int j = i; j <= 100; ++j) {
			partitions[j] += partitions[j - i];
		}
	}

	return partitions[100];
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