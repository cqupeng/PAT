#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isprime(int digit) {
	if (digit <= 1) return false;
	for (int i = 2; i*i <= digit; i++) {
		if (digit%i == 0) return false;
	}
	return true;
}
int main() {
	int N, D;
	cin >> N;
	while (N > 0) {
		cin >> D;
		int flag=1, d2=0;
		string temp;
		if (isprime(N) == false) flag = 0;
		while (N) {
			temp.insert(temp.begin(), N%D + '0');
			N /= D;
		}
		reverse(temp.begin(), temp.end());
		for (auto it = temp.begin(); it != temp.end(); it++) {
			d2 = d2 * D + *it - '0';
		}
		if (isprime(d2) == false) flag = 0;
		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
		cin >> N;
	}
	return 0;
}
