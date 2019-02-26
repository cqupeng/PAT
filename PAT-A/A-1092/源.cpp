#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	unordered_map<char, int> hash1, hash2;
	for (auto it = str1.begin(); it != str1.end(); it++) {
		hash1[*it]++;
	}
	for (auto it = str2.begin(); it != str2.end(); it++) {
		hash2[*it]++;
	}
	int flag=1, cnt = 0;
	for (auto it = hash2.begin(); it != hash2.end(); it++) {
		if (hash1[it->first] < it->second) {
			cnt+=it->second-hash1[it->first];//是缺少的球的总数
			flag = 0;
		}
	}
	if (flag) printf("Yes %d", str1.size() - str2.size());
	else printf("No %d", cnt);
	return 0;
}