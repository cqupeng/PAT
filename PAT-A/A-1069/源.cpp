#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
bool cmp(char a, char b) {
	return a > b;
}
int main() {
	string input;
	cin >> input;
	do {
		while (input.size() < 4) input.insert(input.begin(), '0');
		sort(input.begin(), input.end());
		int a = stoi(input);
		sort(input.begin(), input.end(), cmp);
		int b = stoi(input);
		printf("%04d - %04d = %04d\n", b, a, b - a);
		input = to_string(b - a);
		while (input.size() < 4) input.insert(input.begin(), '0');
		if (input == "0000") break;
	} while (input != "6174");
	return 0;
}