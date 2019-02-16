#include<iostream>
#include<string>
using namespace std;
int main() {
	string A, B;
	char DA, DB;
	int temp=1,sum = 0;
	cin >> A >> DA >> B >> DB;
	for (auto it = A.begin(); it != A.end(); it++) {
		if (*it == DA) {
			sum += (DA-'0') * temp;
			temp *= 10;
		}
	}
	temp = 1;
	for (auto it = B.begin(); it != B.end(); it++) {
		if (*it == DB) {
			sum += (DB-'0') * temp;
			temp *= 10;
		}
	}
	printf("%d", sum);
	return 0;
}