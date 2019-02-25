#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	getchar();
	vector<string> input;
	int len[111];
	int minlen = 1111;
	for (int i = 0; i < N; i++) {
		string temp;
		getline(cin, temp);
		len[i] = temp.size();
		minlen = len[i] < minlen ? len[i] : minlen;
		input.push_back(temp);
	}
	string output;
	bool flag = true;
	for (int i = 0; i < minlen&&flag; i++) {
		char temp = input[0][len[0] -i- 1];
		for (int j = 1; j < N&&flag; j++) {
			if (input[j][len[j] - i - 1] != temp) flag = false;
		}
		if (flag) output.insert(output.begin(), temp);
	}
	if (output.size() != 0) printf("%s", output.c_str());
	else printf("nai");
	return 0;
}