#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		long long A, B, C;
		scanf("%lld %lld %lld", &A, &B, &C);
		A = A - C + B;
		if (A > 0) printf("Case #%d: true\n", i);
		else printf("Case #%d: false\n", i);
	}
	return 0;
}