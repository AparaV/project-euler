/**Problem 10: Sum of Primes
 **@author Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>

using namespace std;

const int length = 2000000;

int main(){

    //declare and initialize array
    bool* arrayOfPrimes = new bool[length];
    arrayOfPrimes[0] = false;

    for(int i = 1; i < length; ++i){
        arrayOfPrimes[i] = true;
    }

    //sieve of eratosthenes
    for(int i = 1; i < sqrt(length) + 1; ++i){
        if(arrayOfPrimes[i] == true){
            for(int j = (i+1) * (i+1) - 1; j < length; j += i + 1){
                arrayOfPrimes[j] = false;
            }
        }
    }

    long long sum = 0;

    //sum 'em up
    for(int i = 1; i < length; ++i){
        if(arrayOfPrimes[i] == true){
            sum += i + 1;
        }
    }

    cout << sum << endl;

    return 0;
}
