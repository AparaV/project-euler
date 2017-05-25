/* Problem 068: Magic 5-gon Ring
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool magic(int* ring);
string generateString(int* ring);

string answer() {
	string result = "0000000000000000";

	int numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	while (next_permutation(numbers, numbers + 10)) {
		if (!magic(numbers)) continue;
		string ring = generateString(numbers);
		if (ring > result) {
			result = ring;
		}
	}

	return result;
}

int main() {

	clock_t start = clock();
	string solution = answer();
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}

bool magic(int* ring) {
	if (ring[1] == 10 || ring[2] == 10 || ring[4] == 10 || ring[6] == 10 || ring[8] == 10) return false;
	if (ring[0] > ring[3] || ring[0] > ring[5] || ring[0] > ring[7] || ring[0] > ring[9]) return false;
	if (ring[0] + ring[1] + ring[2] != ring[2] + ring[3] + ring[4]) return false;
	if (ring[2] + ring[3] + ring[4] != ring[4] + ring[5] + ring[6]) return false;
	if (ring[6] + ring[7] + ring[8] != ring[8] + ring[9] + ring[1]) return false;
	return true;
}

string generateString(int* ring) {
	string result = "";
	result += to_string(ring[0]) + to_string(ring[1]) + to_string(ring[2]);
	result += to_string(ring[3]) + to_string(ring[2]) + to_string(ring[4]);
	result += to_string(ring[5]) + to_string(ring[4]) + to_string(ring[6]);
	result += to_string(ring[7]) + to_string(ring[6]) + to_string(ring[8]);
	result += to_string(ring[9]) + to_string(ring[8]) + to_string(ring[1]);
	return result;
}