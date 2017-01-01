#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;
using std::stringstream;
using std::stoi;

vector< vector<int> > readfile() {
	ifstream fp;
	fp.open("grid.txt");
	if (fp.fail()) {
		cout << "Error opening file" << endl;
	}

	string line;
	vector< vector<int> > grid;
	while (getline(fp, line, '\n')) {
		vector<int> row;
		stringstream ss;
		ss << line;
		string number;
		while (getline(ss, number, ' ')) {
			row.push_back(stoi(number));
		}
		grid.push_back(row);
	}
	return grid;
}

int64_t max_vertical(vector< vector<int> > grid) {
	int64_t m = 0;
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 20; ++j) {
			int64_t cprod = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
			m = std::max(m, cprod);
		}
	}
	return m;
}

int64_t max_horizontal(vector <vector<int> > grid) {
	int64_t m = 0;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 16; ++j) {
			int64_t cprod = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
			m = std::max(m, cprod);
		}
	}
	return m;
}

int64_t max_diagonal(vector< vector<int> > grid) {
	int64_t m = 0;
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			int64_t cprod = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
			m = std::max(m, cprod);
		}
	}
	for (int i = 3; i < 20; ++i) {
		for (int j = 0; j < 16; ++j) {
			int64_t cprod = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3];
			m = std::max(m, cprod);
		}
	}
	return m;
}

int main() {

	vector< vector<int> > grid = readfile();
	
	int64_t mh = max_horizontal(grid);
	int64_t mv = max_vertical(grid);
	int64_t md = max_diagonal(grid);
	int64_t m = std::max(mh, md);
	m = std::max(m, mv);

	cout << m << endl;

	return 0;
}