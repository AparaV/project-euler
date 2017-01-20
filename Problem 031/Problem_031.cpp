/** Problem 031: Coin Sums
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>

using namespace std;

int coin_sums(vector<int> coins, int amount) {
	vector<vector<int> > solution;
	solution.resize(coins.size() + 1, vector<int>(amount + 1, 0));

	//make zero pennies
	for (int i = 0; i <= coins.size(); ++i) {
		solution[i][0] = 1;
	}
	//have zero coins
	for (int i = 1; i <= amount; ++i) {
		solution[0][i] = 0;
	}

	for (int i = 1; i <= coins.size(); ++i) {
		for (int j = 1; j <= amount; ++j) {
			//if coin value is less than amount needed
			//add number of possibilities with the new coin to # of possibilities without the coin
			if (coins[i - 1] <= j) {
				solution[i][j] = solution[i - 1][j] + solution[i][j - coins[i - 1]];
			}
			//if coin value is more than amount neeed
			//only number of possibilities without the new coin
			else {
				solution[i][j] = solution[i - 1][j];
			}
		}
	}

	return solution[coins.size()][amount];
}

int answer() {
	int coins_temp[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	vector<int> coins (coins_temp, coins_temp + sizeof(coins_temp) / sizeof(int));
	int amount = 200;
	return coin_sums(coins, amount);
}

int main() {

	cout << answer() << endl;

	return 0;
}