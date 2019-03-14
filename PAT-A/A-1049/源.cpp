#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
int main() {
	string input;
	cin >> input;
	long long sum = 0;
	int len = input.size();
	for (int i = len-1; i>=0; i--) {
		if (i != 0) {
			sum += sum * 9+pow(10,len-1-i);
		}
		else {
				sum += sum * (input[i] - '0') + stoi(input.substr(1, len - 1))+1;
		}
	}
	cout << sum;
	return 0;
}