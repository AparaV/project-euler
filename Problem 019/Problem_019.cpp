/** Problem 019: Counting Sundays
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>

using std::cout;
using std::endl;

int solution(int start_year=1901, int end_year=2000) {
	int days_passed = 0, sundays = 0;

	//Every year
	for (int i = start_year; i <= end_year; ++i) {
		int days_in_month;
		//Every month
		for (int j = 1; j <= 12; ++j) {
			//Jan, March, May, July, Aug, Oct, Dec
			if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12) {
				days_in_month = 31;
			}
			//April, June, Sept, Nov
			else if (j == 4 || j == 6 || j == 9 || j == 1) {
				days_in_month = 30;
			}
			//Feb in leap years
			else if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
				days_in_month = 29;
			}
			//Feb normal year
			else {
				days_in_month = 28;
			}
	
			if (days_passed % 7 == 0) {
				sundays++;
			}
			days_passed += days_in_month;
		}
	}

	return sundays;
}

int main() {

	cout << solution() << endl;

	return 0;
}