/** Problem 043: Substring Divisibility
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

bool checkConditions(int* number) {
	//divisible by 17
	if ((number[7] * 100 + number[8] * 10 + number[9]) % 17 != 0) {
		return false;
	}
	//divisible by 13
	else if ((number[6] * 100 + number[7] * 10 + number[8]) % 13 != 0) {
		return false;
	}
	//divisible by 11
	else if ((number[5] * 100 + number[6] * 10 + number[7]) % 11 != 0) {
		return false;
	}
	//divisible by 7
	else if ((number[4] * 100 + number[5] * 10 + number[6]) % 7 != 0) {
		return false;
	}
	//divisible by 5
	else if ((number[3] * 100 + number[4] * 10 + number[5]) % 5 != 0) {
		return false;
	}
	//divisible by 3
	else if ((number[2] * 100 + number[3] * 10 + number[4]) % 3 != 0) {
		return false;
	}
	//divisible by 2
	else if ((number[1] * 100 + number[2] * 10 + number[3]) % 2 != 0) {
		return false;
	}

	return true;
}

int64_t convertToInt(int* number) {
	int64_t sum = 0;
	int64_t multiplier = 1;
	for (int i = 9; i >= 0; --i) {
		sum += number[i] * multiplier;
		multiplier *= 10;
	}
	return sum;
}

int64_t answer() {
	int64_t sum = 0;
	int numbers[] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };

	while (next_permutation(numbers, numbers + 10)) {
		if (checkConditions(numbers)) {
			sum += convertToInt(numbers);
		}
	}

	return sum;
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