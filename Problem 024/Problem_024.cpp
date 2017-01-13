/** Problem 024: Lexicographic Permuations
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>

using namespace std;

const int NUMBER = 1000000;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		ans *= i;
	}
	return ans;
}

string answer(int number) {
	int remaining = number - 1;
	int size = 10;
	string solution = "";
	vector<int> options = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 1; i < size; ++i) {
		int j = remaining / factorial(size - i);
		remaining = remaining %  factorial(size - i);
		solution += to_string(options[j]);
		options.erase(options.begin() + j);
		if (remaining == 0) {
			break;
		}
	}

	for (int i = 0; i < options.size(); ++i) {
		solution += to_string(options[i]);
	}

	return solution;
}

int main() {

	cout << answer(NUMBER) << endl;

	return 0;
}