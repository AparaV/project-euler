/* Problem 3: Finding largest prime factor
 *
 */
 
#include <iostream>
#include <cmath>


long long largestPrimeFactor(long long num);

int main(){

    std::cout << largestPrimeFactor(600851475143) << std::endl;

    return 0;
}

long long largestPrimeFactor(long long num){
    long long divisor = 2;

    while (divisor < sqrt(num)){
        while( num % divisor == 0){
            num /= divisor;
        }
        ++divisor;
    }

    return num;
}
