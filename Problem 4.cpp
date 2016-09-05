/* Problem 4: Finding the Largest Palindrome Product
 *
 */
 
 #include <iostream>
#include <cmath>
#include <algorithm>

bool isPalindrome(long num);
long largestProdPalindrome(int maxDigits);

int main(){

    std::cout << largestProdPalindrome(3) << std::endl;

    return 0;
}

bool isPalindrome(long num){
    int length = static_cast<int>(floor(log10(num)) + 1);
    char* arr = new char[length];
    for (int i = length - 1; i >= 0; --i){
        arr[i] = num % 10;
        num /= 10;
    }

    bool flag = true;
    for (int i = 0; i < length/2; ++i){
        if (arr[i] != arr[length - i - 1]){
            flag = false;
            break;
        }
    }

    return flag;
}

long largestProdPalindrome(int maxDigits){
    long upperLimit = pow(10, maxDigits) - 1;
    long lowerLimit = pow(10, maxDigits - 1) + 1;
    long firstNum;
    long secondNum;
    long product;
    long maxProduct = 0;

    for(firstNum = upperLimit; firstNum >= lowerLimit; firstNum--){
        for(secondNum = firstNum; secondNum >= lowerLimit; secondNum--){
            product = firstNum * secondNum;
            if (isPalindrome(product)){
                maxProduct = std::max(product, maxProduct);
            }
        }
    }

    return maxProduct;
}
