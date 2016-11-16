/*  Problem 7: Finding nth Prime number
 *
 */

#include <iostream>
#include <cmath>

bool isPrime(int n);
long nPrime(int n);

int main(){

    std::cout << nPrime(10001) << std::endl;

    return 0;
}

bool isPrime(int n){
    int i = 2;
    while (i <= sqrt(n)){
        if (n % i == 0){
            return false;
        }
        ++i;
    }
    return true;;
}

long nPrime(int n){
    int num = 1;

    for(int i = 0; i <= n; ){
        num++;
        if(isPrime(num) == true){
            ++i;
            if (i == n){
                return num;
            }
        }
    }
}
