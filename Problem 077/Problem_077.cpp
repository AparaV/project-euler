/* Problem 077: Prime Summations
 * Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> primeList(int upperLimit);

int answer(){
    int result = 2;
    vector<int> primes = primeList(1000);

    while(true){
        vector<int> ways(result + 1, 0);
        ways[0] = 1;

        for (int i = 0; i < primes.size(); ++i){
            for (int j = primes[i]; j <= result; ++j){
                ways[j] += ways[j - primes[i]];
            }
        }

        if (ways[result] > 5000){
            break;
        }
        result++;
    }

    return result;
}

int main(){

    clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;

    return 0;
}

vector<int> primeList(int upperLimit) {
	vector<int> primes;
	primes.push_back(2);
	for (int64_t i = 3; i <= upperLimit; i += 2) {
		bool prime = true;
		for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; ++j) {
			if (i % primes[j] == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			primes.push_back(i);
		}
	}
	return primes;
}
