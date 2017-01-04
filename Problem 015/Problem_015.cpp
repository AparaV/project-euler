/** Problem 015: Lattice Paths
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>

using namespace std;

int64_t lattice_paths(int m , int n) {
	vector<vector<int64_t> > board(m, vector<int64_t>(n, 0));

	for (int i = 0; i < m; ++i) {
		board[i][0] = i + 2;
	}
	for (int i = 0; i < n; ++i) {
		board[0][i] = i + 2;
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			board[i][j] = board[i - 1][j] + board[i][j - 1];
		}
	}

	return board[m - 1][n - 1];
}

int main() {
	
	cout << lattice_paths(20, 20) << endl;

	return 0;
}