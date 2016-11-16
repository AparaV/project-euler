#include <iostream>
#include <cmath>

long sumSquares(int n);
long squaresSum(int n);
long diff();

int main(){

    std::cout << diff() << std::endl;

    return 0;
}

long sumSquares(int n){
    long sum = n * (n + 1) / 2;
    return pow(sum, 2);
}

long squaresSum(int n){
    long squares = n * (n + 1) * (2*n + 1) / 6;
    return squares;
}

long diff(){
    return sumSquares(100) - squaresSum(100);
}
