#include<iostream>
#include<string>
using namespace std;
int main() {
	string input;
	int B, R = 0, flag = 1;
	cin >> input >> B;
	for (auto it = input.begin(); it != input.end(); it++) {
		int Q = *it-'0' + R*10;
		if (Q/B == 0 && flag == 1);
		else {
			printf("%d", Q/B);
			flag = 0;
		}
		R = Q % B;
	}
	if (flag == 1) printf("0");
	printf(" %d", R);
	return 0;
}