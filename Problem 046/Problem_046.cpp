#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int64_t n) {
	double x = sqrt(n);
	return x == static_cast<int>(x);
}

int64_t answer() {
	int64_t n;

	for(int64_t i = 1)
}

int main() {

	while (true) {
		int n;
		cin >> n;
		cout << isPerfectSquare(n) << endl;
	}
	return 0;
}