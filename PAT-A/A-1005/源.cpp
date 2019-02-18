#include<iostream>
#include<string>
using namespace std;
int main() {
	string input;
	cin >> input;
	int sum = 0;
	for (auto it = input.begin(); it != input.end(); it++)
		sum += *it - '0';
	char NumToStr[10][6] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	string output = to_string(sum);
	for (auto it = output.begin(); it != output.end(); it++) {
		if (it != output.begin()) putchar(' ');
		printf("%s", NumToStr[*it - '0']);
	}
	return 0;
}