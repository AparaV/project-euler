/** Problem 042: Coded Triangle Numbers
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

inline bool isTriangular(int n) {
	double temp = (sqrt(1 + 8 * n) - 1.0) / 2.0;
	return (temp == (int)temp);
}

vector<string> readfile() {
	ifstream file;
	file.open("p042_words.txt");

	if (file.fail()) {
		cout << "ERROR" << endl;
		return vector<string>(0, "");
	}

	string word;
	vector<string> words;

	while (getline(file, word, ',')) {
		word.erase(word.begin());
		word.erase(word.end() - 1);
		words.push_back(word);
	}

	return words;
}

int answer() {
	vector<string> words = readfile();
	int number = 0;

	for (int i = 0; i < words.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < words[i].size(); ++j) {
			sum += words[i][j] - 64;
		}
		if (isTriangular(sum)) {
			number++;
		}
	}

	return number;
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