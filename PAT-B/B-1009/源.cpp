#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	string temp;
	vector<string> input;
	while ((cin >> temp) &&temp!="/n") {
		input.insert(input.begin(), temp);
	}
	for (auto it = input.begin(); it != input.end(); it++) {
		if (it != input.begin()) putchar(' ');
		cout << *it;
	}
	return 0;
}