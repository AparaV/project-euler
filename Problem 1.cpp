/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000
 */

#include <iostream>

int sum3and5Multiples(int upperLimit){
   int sum = 0;
   
   //adding multiples of 3
   for(int i = 0; 3*i < upperLimit; ++i){
      sum += 3 * i;
   }
   
   //adding multiples of 5
   for(int i = 0; 5*i < upperLimit; ++i){
      sum += 5*i;
   }
   
   //subtracting the repeated multiples of 15 (3*5)
   for(int i = 0; 15*i < upperLimit; ++i){
      sum -= 15*i;
   }
   
   return sum;
}

int main(){
    std::cout << sum3and5Multiples(1000) << std::endl;
    return 0;
}
 
