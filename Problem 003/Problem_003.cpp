/** Problem 003: Largest Prime Factor
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>

int64_t largestPrimeFactor(int64_t num) {
	int64_t largestFactor = 0;
	int64_t sqrtNum = sqrt(num) + 1;

	for (int64_t i = 2; i < sqrtNum; ++i) {
		if (num % i == 0) {
			largestFactor = i;
			num /= i;
			while (num %i == 0) {
				num /= i;
			}
		}
	}

	return largestFactor;
}

int main(){

    std::cout << largestPrimeFactor(600851475143) << std::endl;

    return 0;
}


