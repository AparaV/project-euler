/** Problem 051: Prime Digits Replacement
 ** Author: Aparajithan Venkateswaran
 ** Based on: http://www.mathblog.dk/project-euler-51-eight-prime-family/
 */

#include <iostream>

using namespace std;

bool isPrime(int n);
int** patterns5();
int** patterns6();
int* fillPattern(int* pattern, int size, int number);
int generateNumber(int repeat, int* filledPattern, int size);
int familySize(int repeat, int* pattern, int size);

int answer() {
	// can only be 5 or 6 digit numbers
	// the smallest member should have 0, 1, or 2 as the repeating digit
	// otherwise we would not get a 8 member family
	// last digit can not be a repeating digit (1, 3, 5, 7, 9 are the last digits)
	// the repeating digit should repeat 3 times
	// other possibilities cannot generate a 8 member family ( digit sum mod 3)

	int** fiveDigitPattern = patterns5();
	int** sixDigitPattern = patterns6();
	int result = 999999999;

	for (int i = 11; i < 1000; i += 2) {

		//Only 1,3,7,9 are valid endings
		if (i % 5 == 0) {
			continue;
		}
		int size, length;
		int** patterns;
		if (i < 100) {
			patterns = fiveDigitPattern;
			size = 5;
			length = 4;
		}
		else {
			patterns = sixDigitPattern;
			size = 6;
			length = 10;
		}

		for (int j = 0; j  < length; j++) {
			for (int k = 0; k <= 2; k++) {

				//Don't generate candidates with leading zero
				if (patterns[j][0] == 0 && k == 0) {
					continue;
				}

				int* pattern = fillPattern(patterns[j], size, i);
				int candidate = generateNumber(k, pattern, size);

				if (candidate < result && isPrime(candidate)) {
					if (familySize(k, pattern, size) == 8) {
						result = candidate;
						break;
					}
				}
			}
		}
	}
	return result;
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

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i * i <= n; ++i) {
		if (n %i == 0) {
			return false;
		}
	}
	return true;
}

// 5 digit pattern
// 1 - non-repeating; 0 - repeating
int** patterns5() {
	int** patterns = new int*[4];
	patterns[0] = new int[5] {1, 0, 0, 0, 1};
	patterns[1] = new int[5] {0, 1, 0, 0, 1};
	patterns[2] = new int[5] {0, 0, 1, 0, 1};
	patterns[3] = new int[5] {0, 0, 0, 1, 1};
	return patterns;
}

//6 digit pattern
// 1- non-repeating; 0 - repeating
int** patterns6() {
	int** patterns = new int*[10];
	patterns[0] = new int[6] {1, 1, 0, 0, 0, 1};
	patterns[1] = new int[6] {1, 0, 1, 0, 0, 1};
	patterns[2] = new int[6] {1, 0, 0, 1, 0, 1};
	patterns[3] = new int[6] {1, 0, 0, 0, 1, 1};
	patterns[4] = new int[6] {0, 1, 1, 0, 0, 1};
	patterns[5] = new int[6] {0, 1, 0, 1, 0, 1};
	patterns[6] = new int[6] {0, 1, 0, 0, 1, 1};
	patterns[7] = new int[6] {0, 0, 1, 1, 0, 1};
	patterns[8] = new int[6] {0, 0, 1, 0, 1, 1};
	patterns[9] = new int[6] {0, 0, 0, 1, 1, 1};
	return patterns;
}

// fills non-repeating digits with number
// fills repeating digits with -1
int* fillPattern(int* pattern, int size, int number) {
	int* filled = new int[size];
	int temp = number;
	for (int i = size - 1; 0 <= i; i--) {
		if (pattern[i] == 1) {
			filled[i] = temp % 10;
			temp /= 10;
		}
		else {
			filled[i] = -1;
		}
	}
	return filled;
}
// generates a number with a filled pattern
int generateNumber(int repeat, int* filledPattern, int size) {
	int temp = 0;
	for (int i = 0; i < size; i++) {
		temp = temp * 10;
		temp += (filledPattern[i] == -1) ? repeat : filledPattern[i];
	}
	return temp;
}

// finds a family size
int familySize(int repeat, int* pattern, int size) {
	int familySize = 1;
	for (int i = repeat + 1; i < 10; i++) {
		if (isPrime(generateNumber(i, pattern, size))) {
			familySize++;
		}
	}
	return familySize;
}