#include<stdio.h>
#include<map>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	map<int, int> input;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		input[temp*-1] = 1;
	}
	for (auto it = input.begin(); it != input.end(); it++) {
		int temp = it->first;
		while (temp != -1) {
			if (temp % 2 == 0) temp /= 2;
			else temp = (temp * 3 - 1) / 2;
			input[temp] = 0;
		}
	}
	int flag = 0;
	for (auto it = input.begin(); it != input.end(); it++) {
		if (flag == 1) putchar(' ');
		if (it->second == 1) {
			printf("%d", it->first*-1);
			flag = 1;
		}
	}
	return 0;
}