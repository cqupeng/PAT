#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool ispalin(string str) {
	string temp = str;
	reverse(temp.begin(), temp.end());
	if (temp == str) return true;
	else return false;
}
string str_add(string a, string b) {
	int r = 0;
	string result;
	for (int i = a.size() - 1; i >= 0; i--) {
		int temp = a[i] + b[i] - 2 * '0'+r;
		result.insert(result.begin(), temp % 10 + '0');
		r = temp / 10;
	}
	if (r != 0) result.insert(result.begin(), r + '0');
	return result;
}
int main() {
	string input;
	int K;
	cin >> input >> K;
	int step = 0;
	while (step != K && !ispalin(input)) {
		string a = input;
		reverse(input.begin(), input.end());
		input = str_add(a, input);
		step++;
	}
	cout << input << endl << step;
	return 0;
}