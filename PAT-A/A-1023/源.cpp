#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	string input,output,result;
	cin >> input;
	result = input;
	int r = 0;
	for (int i = result.size() - 1; i >= 0; i--) {
		int temp = 2 * (result[i]-'0') + r;
		result[i] = temp % 10+'0';
		r = temp / 10;
	}
	if (r != 0) result.insert(result.begin(), r + '0');
	output = result;
	sort(input.begin(), input.end());
	sort(output.begin(), output.end());
	if (input == output) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << result;
	return 0;
}