#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	string input;
	cin >> input;
	int flag = 1;
	while ((flag||input != "6174")&&input != "0000") {
		while (input.length() < 4) input.insert(input.begin(), '0');
		sort(input.begin(), input.end(), cmp);
		int temp1 = stoi(input);
		sort(input.begin(), input.end());
		int temp2 = stoi(input);
		printf("%04d - %04d = %04d\n", temp1, temp2, temp1 - temp2);
		input = to_string(temp1 - temp2);
		while (input.length() < 4) input.insert(input.begin(), '0');
		flag = 0;
	}
	return 0;
}