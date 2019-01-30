#include<stdio.h>
bool IsPrime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int main() {
	int num1 = 0,num2=0, N = 2;
	int first, end;
	scanf("%d %d", &first, &end);
	while (num1 < end) {
		if (IsPrime(N++)) {
			num1++;
			if (num1 >= first) {
				printf("%d", N - 1);
				num2++;
				if (num1 != end) {
					if (num2 % 10 == 0) printf("\n");
					else printf(" ");
				}
			}
		}
	}
	return 0;
}