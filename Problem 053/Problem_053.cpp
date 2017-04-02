/** Problem 053: Combinatoric Selections
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>

using namespace std;

// Use a pascal triangle
// If the sum of adjacent numbers in previous row is greater than 1,000,000, set it to 1,000,000
// This makes sure that we do not run into the problem of needing big integers

int answer() {
	int counts = 0;
	int** pascalTriangle = new int*[101];
	for (int i = 0; i <= 100; ++i) {
		pascalTriangle[i] = new int[101];
		pascalTriangle[i][0] = 1;
	}
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= i; ++j) {
			pascalTriangle[i][j] = pascalTriangle[i - 1][j] + pascalTriangle[i - 1][j - 1];
			if (pascalTriangle[i][j] > 1000000) {
				pascalTriangle[i][j] = 1000000;
				counts++;
			}
		}
	}
	return counts;
}

int main() {

	clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	float time = static_cast<float>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;

	return 0;
}