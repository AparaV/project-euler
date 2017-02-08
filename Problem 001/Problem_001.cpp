/** Problem 001: Multiples of 3 and 5
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <ctime>

using namespace std;

int answer(){
    int sum = 0;

	int threes = 999 / 3;
	sum += 3 * threes * (threes + 1) / 2;
	int fives = 999 / 5;
	sum += 5 * fives * (fives + 1) / 2;
	int fifteens = 999 / 15;
	sum -= 15 * fifteens * (fifteens + 1) / 2;

    return sum;
}

int main(){

	clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " milliseconds" << endl;

    return 0;
}
