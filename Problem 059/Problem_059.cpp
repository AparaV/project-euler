/* Problem 059: XOR Decryption
 * Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> readFile();
string encryptXOR(vector<int> data, vector<int> key);
vector<int> fingerPrintAnalysis(vector<int> data, int keyLength);
int sumASCII(string message);

int answer() {
	vector<int> data = readFile();
	vector<int> key = fingerPrintAnalysis(data, 3);
	string message = encryptXOR(data, key);
	cout << message << endl;
	return sumASCII(message);
}

int main() {

	clock_t start = clock();
	int solution = answer();
	clock_t end = clock();
	double time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000);

	cout << "Answer is " << solution << endl;
	cout << "It took " << time << " ms" << endl;

	return 0;
}

vector<int> readFile() {
	ifstream file;
	file.open("p059_cipher.txt");
	vector<int> data;
	string content;
	while (getline(file, content, ',')) {
		data.push_back(stoi(content));
	}
	return data;
}

string encryptXOR(vector<int> message, vector<int> key) {
	string encrypted = "";
	for (int i = 0; i < message.size(); ++i) {
		string temp;
		int ascii = message[i] ^ key[i % key.size()];
		temp = static_cast<char>(ascii);
		encrypted += temp;
	}
	return encrypted;
}

// most repeated character in english is <space>
// so divide data into 3 (key length) bins and find most recurrent character
vector<int> fingerPrintAnalysis(vector<int> data, int keyLength) {
	vector<int> key;
	for (int i = 0; i < keyLength; ++i) {
		key.push_back(0);
	}
	int** bins = new int*[keyLength];
	for (int i = 0; i < keyLength; ++i) {
		bins[i] = new int[128];
		for (int j = 0; j < 128; ++j) {
			bins[i][j] = 0;
		}
	}
	for (int i = 0; i < data.size(); ++i) {
		int j = i % keyLength;
		bins[j][data[i]]++;
		if (bins[j][data[i]] > bins[j][key[j]]) {
			key[j] = data[i];
		}
	}
	for (int i = 0; i < keyLength; ++i) {
		key[i] = key[i] ^ 32; //32 = space ASCII
	}
	return key;
}

int sumASCII(string message) {
	int sum = 0;
	for (int i = 0; i < message.size(); ++i) {
		sum += message[i];
	}
	return sum;
}