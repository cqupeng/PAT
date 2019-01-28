#include<stdio.h>
int prime[100001] = { 0 };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (prime[i] == 0) {
			for (int j = i + i; j <= n; j+=i) {
				prime[j] = 1;
			}
		}
	}
	int sum = 0, last = 2;
	for (int i = 3; i <= n; i++) {
		if (prime[i] == 0) {
			if (i - last == 2) sum++;
			last = i;
		}
	}
	printf("%d\n", sum);
	return 0;
}