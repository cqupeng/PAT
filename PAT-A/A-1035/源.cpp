#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	unordered_map<string, string> input;
	vector<string> output;
	for (int i = 0; i < N; i++) {
		string user, password;
		cin >> user >> password;
		int flag = 0;
		for (auto it = password.begin(); it != password.end(); it++) {
			switch (*it) {
			case '1': 
				flag = 1;
				*it = '@';
				break;
			case '0': 
				flag = 1;
				*it = '%';
				break;
			case 'l':
				flag = 1;
				*it = 'L';
				break;
			case 'O':
				flag = 1;
				*it = 'o';
				break;
			default:
				break;
			}
		}
		input[user] = password;
		if (flag == 1) {
			output.push_back(user);
		}
	}
	if (output.size() == 0&&N>1) printf("There are %d accounts and no account is modified\n", N);
	else if (output.size() == 0&&N==1) printf("There is 1 account and no account is modified\n");
	else {
		printf("%d\n", output.size());
		for (auto it = output.begin(); it != output.end(); it++) {
			printf("%s %s\n", (*it).c_str(), input[*it].c_str());
		}
	}
	return 0;
}