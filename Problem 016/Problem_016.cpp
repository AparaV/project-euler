#include <iostream>

using std::cout;
using std::endl;

int answer() {
	int size = 500;
	int* ar = new int[size];
	int sum = 0;

	ar[0] = 1;

	for (int i = 1; i < size; ++i) {
		ar[i] = 0;
	}

	for (int i = 0; i < 1000; ++i) {
		ar[0] *= 2;
		for (int j = 1; j < size; ++i) {
			ar[j] = 2 * ar[j] + ar[j - 1] / 10;
		}
		for (int k = 0; k < size; ++k) {
			ar[k] %= 10;
		}
	}

	for (int i = 0; i < size; ++i) {
		sum += ar[i];
	}

	return sum;
}

int main() {

	cout << answer() << endl;

	return 0;
}