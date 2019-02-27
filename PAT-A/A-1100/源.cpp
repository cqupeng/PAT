#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main() {
	int N;
	cin >> N;
	getchar();
	string num_0[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string num_10[13] = { "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	for (int i = 0; i < N; i++) {
		string temp;
		getline(cin, temp);
		if (isdigit(temp[0])) {
			int n = stoi(temp);
			if (n == 0) cout << num_0[0];
			if (n / 13 != 0) cout << num_10[n / 13];
			if (n / 13 != 0 && n % 13 != 0) cout << ' ';//个位数为0时不输出
			if (n % 13 != 0) cout << num_0[n % 13];
			cout<< '\n';
		}
		else {
			auto it = temp.find(' ');
			int output = 0;
			if (it != string::npos) {
				string next = temp.substr(it+1,temp.size()-it);
				temp = temp.substr(0, it);
				for (int j = 1; j < 13; j++) {
					if (temp == num_10[j]) {
						output += 13 * j;
					}
					if (next == num_0[j]) output += j;
				}
			}
			else {
				for (int j = 1; j < 13; j++) {
					if (temp == num_10[j]) output += j*13;
					if (temp == num_0[j]) output += j;
				}
			}
			cout << output << '\n';
		}
	}
	return 0;
}