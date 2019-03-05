#include<iostream>
#include<string>
#include<climits>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		int len = temp.size() / 2;
		int Z = stol(temp);
		int a = stol(temp.substr(0, len));
		int b = stol(temp.substr(0 + len, len));
		if ((long long)(a*b)<INT_MAX&&a!=0&&b!=0&&Z % (a * b)==0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}