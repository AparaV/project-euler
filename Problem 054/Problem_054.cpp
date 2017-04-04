/** Problem 054: Poker hands
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int getRank(int* suits, int* values);
string* getHand(string hand);
int compareHands(string* player1, string* player2);
int* getSuits(string* hand);
int* getValues(string* hand);
int valueToInt(char c);

int answer() {
	int answer = 0;
	ifstream file;
	file.open("p054_poker.txt");
	string game;
	while (getline(file, game, '\n')) {
		string player1 = game.substr(0, game.length() / 2);
		string player2 = game.substr(game.length() / 2);
		int winner = compareHands(getHand(player1), getHand(player2));
		if (winner == 1) {
			answer++;
		}
	}

	return answer;
}

int main() {

	clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;

	return 0;
}

int valueToInt(char c) {
	if (c == 'K') {
		return 13;
	}
	if (c == 'A') {
		return 14;
	}
	if (c == 'Q') {
		return 12;
	}
	if (c == 'J') {
		return 11;
	}
	if (c == 'T') {
		return 10;
	}
	return c - '0';
}

int* getSuits(string* hand) {
	int* suits = new int[4]; // hearts, clubs, diamonds, spades
	suits[0] = 0;
	suits[1] = 0;
	suits[2] = 0;
	suits[3] = 0;
	for (int i = 0; i < 5; ++i) {
		if (hand[i][1] == 'H') suits[0]++;
		if (hand[i][1] == 'C') suits[1]++;
		if (hand[i][1] == 'D') suits[2]++;
		if (hand[i][1] == 'S') suits[3]++;
	}
	return suits;
}

int* getValues(string* hand) {
	int* values = new int[14]; //A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A
	for (int i = 0; i < 14; ++i) {
		values[i] = 0;
	}
	for (int i = 0; i < 5; ++i) {
		int val = valueToInt(hand[i][0]);
		if (val == 14) {
			values[0]++;
			values[13]++;
		}
		else {
			values[val - 1]++;
		}
	}
	return values;
}

int getRank(int* suits, int* values) {
	
	int pairs = 0, threes = 0, fours = 0;
	for (int i = 0; i < 13; ++i) { // ignore values[13] since it is a repeat
		if (values[i] == 2) {
			pairs++;
		}
		if (values[i] == 3) {
			threes++;
		}
		if (values[i] == 4) {
			fours++;
		}
	}

	if (threes == 1) {
		// full house
		if (pairs == 1) {
			return 7;
		}
		//three of a kind
		return 4;
	}
	if (pairs == 1) {
		return 2;
	}
	if (pairs == 2) {
		return 3;
	}
	if (fours == 1) {
		//four of a kind
		return 8;
	}

	bool flush = false, straight = false, royal = false;;
	for (int i = 0; i < 4; ++i) {
		if (suits[i] == 5) {
			flush = true;
		}
	}
	int cards = 0;
	for (int i = 0; i < 10; ++i) {
		if (values[i] == 1 && values[i + 1] == 1 && values[i + 2] == 1 && values[i + 3] && values[i + 4] == 1) {
			straight = true;
			if (i == 9) {
				royal = true;
				values[0] = 0; // it is a high street ace
			}
			else {
				values[13] = 0; // it is a low street ace - helps when comparing
			}
		}
	}

	if (royal && flush) {
		return 10;
	}
	else if (straight && flush) {
		return 9;
	}
	else if (straight) {
		return 5;
	}
	else if (flush) {
		return 6;
	}

	return 1;
}

string* getHand(string hand) {
	string* arr = new string[5];
	int index = 0;
	stringstream ss;
	ss << hand;
	string temp;
	while (getline(ss, temp, ' ')) {
		if (temp == "") {
			continue;
		}
		arr[index] = temp;
		index++;
	}

	//sorting
	for (int i = 1; i < 5; ++i) {
		for (int j = 0; j < 5 - i; ++j) {
			int first = valueToInt(arr[j][0]);
			int second = valueToInt(arr[j + 1][0]);
			if (first > second) {
				string temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

int compareHands(string* player1, string* player2) {
	int* suits1 = getSuits(player1);
	int* values1 = getValues(player1);
	int rank1 = getRank(suits1, values1);

	int* suits2 = getSuits(player2);
	int* values2 = getValues(player2);
	int rank2 = getRank(suits2, values2);

	if (rank1 > rank2) {
		return 1;
	}
	else if (rank1 < rank2) {
		return 2;
	}
	// both have same ranks

	// highest card or flush
	if (rank1 == 1 || rank1 == 6) {
		for (int i = 4; i >= 0; --i) {
			if (valueToInt(player1[i][0]) > valueToInt(player2[i][0])) {
				return 1;
			}
			else if (valueToInt(player1[i][0]) < valueToInt(player2[i][0])) {
				return 2;
			}
		}
	}

	// straight flush or straight
	if (rank1 == 9 || rank1 == 5) {
		for (int i = 13; i >= 0; --i) {
			if (values1[i] > 0) { // player 1 ends at a larger card
				return 1;
			}
			else if (values2[i] > 0) {
				return 2;
			}
		}
	}

	// one pair
	if (rank1 == 2) {
		int maxCard1 = -1, maxCard2 = -1;
		// ignore ace as a 1
		for (int i = 1; i < 14; ++i) {
			if (values1[i] == 2) {
				maxCard1 = i;
			}
			if (values2[i] == 2) {
				maxCard2 = i;
			}
		}
		if (maxCard1 > maxCard2) {
			return 1;
		}
		else if (maxCard2 > maxCard1) {
			return 2;
		}
		else {
			for (int i = 4; i >= 0; --i) {
				if (valueToInt(player1[i][0]) == maxCard1 - 1 && valueToInt(player2[i][0]) == maxCard2 - 1) {
					continue;
				}
				if (valueToInt(player1[i][0]) > valueToInt(player2[i][0])) {
					return 1;
				}
				else if (valueToInt(player1[i][0]) < valueToInt(player2[i][0])) {
					return 2;
				}
			}
		}
	}

	// two pairs
	if (rank1 == 3) {
		int maxCard1[2] = { -1, -1 };
		int maxCard2[2] = { -1, -1 };
		int index1 = 0, index2 = 0, otherCard1 = -1, otherCard2 = -1;
		//ignore ace as a 1
		for (int i = 1; i < 14; ++i) {
			if (values1[i] == 2) {
				maxCard1[index1] = i;
				index1++;
			}
			else if (values1[i] == 1) {
				otherCard1 = i;
			}
			if (values2[i] == 2) {
				maxCard2[index2] = i;
				index2++;
			}
			else if (values2[i] == 1) {
				otherCard2 = i;
			}
		}
		//compare the two pairs
		for (int i = 1; i >= 0; --i) {
			if (maxCard1[i] > maxCard2[i]) {
				return 1;
			}
			else if (maxCard2[i] > maxCard1[i]) {
				return 2;
			}
		}
		//compare the other card
		if (otherCard1 > otherCard2) {
			return 1;
		}
		else if (otherCard2 > otherCard1) {
			return 2;
		}
	}

	// three of a kind
	if (rank1 == 4) {
		int maxCard1 = -1, maxCard2 = -1;
		// ignore ace as a 1
		for (int i = 1; i < 14; ++i) {
			if (values1[i] == 3) {
				maxCard1 = i;
			}
			if (values2[i] == 3) {
				maxCard2 = i;
			}
		}
		if (maxCard1 > maxCard2) {
			return 1;
		}
		else if (maxCard1 < maxCard2) {
			return 2;
		}
		else {
			for (int i = 4; i >= 0; --i) {
				if (valueToInt(player1[i][0]) == maxCard1 - 1 && valueToInt(player2[i][0]) == maxCard2 - 1) {
					continue;
				}
				if (valueToInt(player1[i][0]) > valueToInt(player2[i][0])) {
					return 1;
				}
				else if (valueToInt(player1[i][0]) < valueToInt(player2[i][0])) {
					return 2;
				}
			}
		}
	}

	// full house
	if (rank1 == 7) {
		int threeCard1, threeCard2, pairCard1, pairCard2;
		for (int i = 1; i < 14; ++i) {
			if (values1[i] == 3) {
				threeCard1 = i;
			}
			else if (values1[i] == 2) {
				pairCard1 = i;
			}

			if (values2[i] == 3) {
				threeCard2 = i;
			}
			else if (values2[i] == 2) {
				pairCard2 = i;
			}
		}
		if (threeCard1 > threeCard2) {
			return 1;
		}
		else if (threeCard1 < threeCard2) {
			return 2;
		}
		else if (pairCard1 > pairCard2) {
			return 1;
		}
		else if (pairCard1 < pairCard2) {
			return 2;
		}
	}

	// four of a kind
	if (rank1 == 8) {
		int four1, four2, other1, other2;
		for (int i = 1; i < 14; ++i) {
			if (values1[i] == 4) {
				four1 = i;
			}
			else if (values1[i] == 1) {
				other1 = i;
			}

			if (values2[i] == 4) {
				four2 = i;
			}
			else if (values2[i] == 1) {
				other2 = i;
			}
		}
		if (four1 > four2) {
			return 1;
		}
		else if (four1 < four2) {
			return 2;
		}
		else if (other1 > other2) {
			return 1;
		}
		else if (other1 < other2) {
			return 2;
		}
	}

	return -1;
}