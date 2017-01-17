/** Problem 028: Number Spiral Diagonals
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>

using namespace std;

int answer(int size) {
	int step = 2, counter = 1, current = 3;
	int sum = 1;

	while (current <= size * size) {
		sum += current;
		if (counter % 4 == 0) {
			step += 2;
		}
		current += step;
		counter++;
	}

	return sum;
}

int main() {

	cout << answer(1001) << endl;

	return 0;
}