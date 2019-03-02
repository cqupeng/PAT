#include<iostream>
#include<string>
using namespace std;
bool isprime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i*i < n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
int main() {
	int L, K;
	cin >> L >> K;
	string input;
	cin >> input;
	for (int i = 0; i + K <= L; i++) {
		if (isprime(stoi(input.substr(i, K)))) {
			cout << input.substr(i, K);
			return 0;
		}
	}
	cout << 404;
	return 0;
}