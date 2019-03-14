#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	unordered_map<char, bool> record;
	for (auto it = s2.begin(); it != s2.end(); it++) {
		record[*it] = 1;
	}
	for (auto it = s1.begin(); it != s1.end(); it++) {
		if (record[*it] == 1) s1.erase(it--);
	}
	cout << s1;
	return 0;
}