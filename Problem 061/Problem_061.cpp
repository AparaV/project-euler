/* Problem 061: Cyclical Figurate Numbers
 * Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isTriangular(int n);
bool isSquare(int n);
bool isPentagonal(int n);
bool isHexagonal(int n);
bool isHeptagonal(int n);
bool isOctagonal(int n);
bool findCyclic(vector<int> typesSeen, vector<vector<int>> numbers, vector<int> &solution);

int answer() {

	vector<vector<int>> numbers(6, vector<int>());
	for (int i = 1011; i < 10000; ++i) {
		if (isOctagonal(i))	numbers[5].push_back(i);
		if (isHeptagonal(i)) numbers[4].push_back(i);
		if (isHexagonal(i))	numbers[3].push_back(i);
		if (isPentagonal(i)) numbers[2].push_back(i);
		if (isSquare(i)) numbers[1].push_back(i);
		if (isTriangular(i)) numbers[0].push_back(i);
	}

	int result = 0;
	vector<int> solution;

	for (int a = 0; a < numbers[5].size(); ++a) {
		solution.push_back(numbers[5][a]);
		vector<int> typesSeen;
		typesSeen.push_back(5);
		if (findCyclic(typesSeen, numbers, solution)) break;
		else solution.clear();
	}

	cout << "The chain is: ";
	for (int i = 0; i < solution.size(); ++i) {
		result += solution[i];
		cout << solution[i];
		if (i != solution.size() - 1) cout << ", ";
	}
	cout << endl;

	return result;
}

int main() {

	clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

	return 0;
}

bool isTriangular(int n) {
	double temp = (sqrt(1 + 8 * n) - 1.0) / 2.0;
	return (temp == static_cast<int>(temp));
}

bool isSquare(int n) {
	double temp = sqrt(n);
	return (temp == static_cast<int>(temp));
}

bool isPentagonal(int n) {
	double temp = (1.0 + sqrt(1 + 24 * n)) / 6.0;
	return temp == static_cast<int>(temp);
}

bool isHexagonal(int n) {
	double temp = (1.0 + sqrt(1 + 8 * n)) / 4.0;
	return temp == static_cast<int>(temp);

}

bool isHeptagonal(int n) {
	double temp = (3.0 + sqrt(9 + 40 * n)) / 10.0;
	return (temp == static_cast<int>(temp));
}

bool isOctagonal(int n) {
	double temp = (2.0 + sqrt(4 + 12 * n)) / 6.0;
	return (temp == static_cast<int>(temp));
}

bool findCyclic(vector<int> typesSeen, vector<vector<int>> numbers, vector<int> &solution) {
	for (int type = 0; type < 6; ++type) {
		if (find(typesSeen.begin(), typesSeen.end(), type) != typesSeen.end()) continue;
		for (int i = 0; i < numbers[type].size(); ++i) {
			if (numbers[type][i] / 100 == solution[solution.size() - 1] % 100) {
				solution.push_back(numbers[type][i]);
				typesSeen.push_back(type);
				if (solution.size() == 6) {
					if (solution[5] % 100 == solution[0] / 100)	return true;
					else {
						solution.pop_back();
						typesSeen.pop_back();
					}
				}
				else if (findCyclic(typesSeen, numbers, solution)) return true;
				else {
					solution.pop_back();
					typesSeen.pop_back();
				}
			}
		}
	}
	return false;
}