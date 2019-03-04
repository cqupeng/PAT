#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main() {
	int k;
	scanf("%d", &k);
	getchar();
	string input;
	getline(cin, input);
	unordered_map<char, int> record;
	string output;
	int len = input.size();
	for (int i = 0; i < len; i++) {
		if (record[input[i]] != 1) {
			int flag = 1;
			for (int j = 1; j < k && i+j < len&&flag; j++) {
				if (input[j+i] != input[i]) flag = 0;
				if (i + j == len - 1 && flag == 1) flag = 0;
			}
			if (flag == 0) 	record[input[i]] = 1;
			else {
				if(record[input[i]]!=-1) output.push_back(input[i]);
				record[input[i]] = -1;
				i += k - 1;
			}
		}
	}
	for (auto it = output.begin(); it != output.end(); it++) {
		if (record[*it] == -1) putchar(*it);

	}
	printf("\n");
	for (int i = 0; i < len; i++) {
		putchar(input[i]);
		if (record[input[i]] == -1) i += k-1;
	}
	return 0;
}