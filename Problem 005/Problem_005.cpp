#include <iostream>

int evenlyDivides(int first, int last);

int main(){

    std::cout << evenlyDivides(1, 20) << std::endl;

    return 0;
}

int evenlyDivides(int first, int last){
    int num = last;
    int counter = first;

    while(counter <= last){
        if (num % counter != 0){
            num += num % counter;
            counter = first;
            continue;
        }
        counter++;
    }

    return num;
}
