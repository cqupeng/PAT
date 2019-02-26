#include<stdio.h>
#include<string.h>
char input[111111];
int sum_P[111111] = { 0 };
int sum_T[111111] = { 0 };
int main() {
	char temp;
	int i = 0;
	while ((temp = getchar()) != EOF) {
		if (i == 0) {
			if (temp == 'P') sum_P[i] = 1;
			else if (temp == 'T') sum_T[i] = 1;
		}
		else {
			if (temp == 'P') {
				sum_P[i] = sum_P[i - 1] + 1;
				sum_T[i] = sum_T[i - 1];
			}
			else if (temp == 'T') {
				sum_P[i] = sum_P[i - 1];
				sum_T[i] = sum_T[i - 1] + 1;
			}
			else {
				sum_P[i] = sum_P[i - 1];
				sum_T[i] = sum_T[i - 1];
			}
		}
		input[i] = temp;
		i++;
	}
	int cnt = 0;
	for (int j = 0; j < i; j++) {
		if (input[j] == 'A') {
			cnt += sum_P[j] * (sum_T[i - 1] - sum_T[j]);
			cnt = cnt % 1000000007;
		}
	}
	printf("%d", cnt);
	return 0;
}