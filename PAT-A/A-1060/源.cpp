#include<iostream>
#include<string>
using namespace std;
void tosimply(string &temp) {
	auto it = temp.begin();
	while (it != temp.end()&&*it=='0') {
		temp.erase(it);
	}
}
int main() {
	int N;
	string s1, s2;
	cin >> N >> s1 >> s2;
	tosimply(s1);
	tosimply(s2);
	auto it = s1.find('.');
	int e1 = 0;
	if (it != string::npos) {
		s1.erase(it);
		e1 += it;
	}
	else e1 += s1.length();
	it = s2.find('.');
	int e2 = 0;
	if (it != string::npos) {
		s2.erase(it);
		e2 += it;
	}
	else e2 += s2.length();
	if (s1.length() == 0 && s2.length() == 0) printf("YES 0");
	else {
		int flag = 1;
		for (int i = 0; i < s1.length() && i < s2.length() && i < N; i++) {
			if (s1[i] != s2[i]) flag = 0;
		}
		while (s1.length() < N) s1.push_back('0');
		while (s2.length() < N) s2.push_back('0');
		if (flag&&e1==e2) {
			printf("YES 0.%s", s1.substr(0, N).c_str());
			if (e1 != 0) printf("*10^%d", e1);
		}
		else {
			printf("NO ");
			printf("0.%s", s1.substr(0, N).c_str());
			printf("*10^%d", e1);
			printf(" ");
			printf("0.%s", s2.substr(0, N).c_str());
			printf("*10^%d", e2);
		}
	}
	return 0;
}