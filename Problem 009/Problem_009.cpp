/**Problem 9: Find Special Pythagorean Triplet
 **@author Aparajithan Venkateswaran
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

//check whether given 3 numbers are a Pythagorean triplet
bool isPythTriplet(int a, int b, int c){
    std::vector<int> myVector = {a, b, c};
    std::sort(myVector.begin(), myVector.end());

    if(pow(myVector[0], 2) + pow(myVector[1], 2) == pow(myVector[2], 2)){
        return true;
    }

    return false;
}

//find the product of the special Pythagorean triplet
unsigned long splPythTriplet(int sum){
    unsigned long prod;

    for(int a = 1;a < 1000 ; ++a){
        for(int b = 1;b < 1000 ; ++b){
            for(int c = 1;c < 1000 ; ++c){
                if(a + b + c == sum){
                    if(isPythTriplet(a, b, c)){
                        prod = a * b * c;
                        return prod;
                    }
                }
            }
        }
    }
}

int main(){

    std::cout << splPythTriplet(1000) << std::endl;

    return 0;
}
