#include <iostream>

int sum3and5Multiples(int upperLimit){
    int sum = 0;

    for(int i = 0; 3*i < upperLimit; ++i){
        sum += 3 * i;
    }
    for(int i = 0; 5*i < upperLimit; ++i){
        sum += 5*i;
    }
    for(int i = 0; 15*i < upperLimit; ++i){
        sum -= 15*i;
    }

    return sum;
}

int main(){
    std::cout << sum3and5Multiples(1000) << std::endl;
    return 0;
}
