#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(string A, string B) {
	int len1 = A.size(), len2 = B.size();
	int minlen = len1 < len2 ? len1 : len2;
	if (A.substr(0, minlen) != B.substr(0, minlen)) 
		return A.substr(0, minlen) < B.substr(0, minlen);
	else if (len1 < len2) return A < B.substr(len1, len2 - len1);
	else if(len1>len2) return A.substr(len2, len1-len2)<B;
	else return A < B;
}
int main() {
	int N;
	scanf("%d", &N);
	vector<string> input;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		input.push_back(temp);
	}
	sort(input.begin(), input.end(),cmp);
	bool flag = false;
	for (auto it = input.begin(); it != input.end(); it++) {
		if (flag == false) {
			for (auto i = (*it).begin(); i != (*it).end(); i++) {
				if (*i == '0'&&flag == false);
				else {
					flag = true;
					putchar(*i);
				}
			}
		}
		else cout << *it;
	}
	if (flag == false) printf("0");//·ÀÖ¹½á¹ûÎª0
	return 0;
}