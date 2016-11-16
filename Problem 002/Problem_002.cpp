#include <iostream>

int fibonacci(int n);//Prototype for n-th Fibonacci number
int fibonacciEvenSum(int upperLimit);//Prototype for finding sum

int main(){

    std::cout << fibonacciEvenSum(4000000) << std::endl;

    return 0;
}

//Finding nth Fibonacci number
int fibonacci(int n){
    if (n <= 0){
        std::cout << "Your n is invalid" << std::endl;
        return 0;
    }
    if (n == 1 || n == 2)
        return 1;
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int fibonacciEvenSum(int upperLimit){
    int sum = 0;
    int i = 1;
    int fib = fibonacci(i);

    for(i = 1; fib < upperLimit; ++i){
        if (fib % 2 == 0){
            sum += fib;
        }
        fib = fibonacci(i + 1);
    }

    return sum;
}
