#include<stdio.h>
#include<algorithm>
using namespace std;
int coupons[100111];
int product[100111];
int main() {
	int N1, N2, temp;
	long long sum = 0;
	scanf("%d", &N1);
	for (int i = 0; i < N1; i++) {
		scanf("%d", &coupons[i]);
	}
	scanf("%d", &N2);
	for (int i = 0; i < N2; i++) {
		scanf("%d", &product[i]);
	}
	int n1 = 0, n2 = 0;
	sort(coupons, coupons + N1);
	sort(product, product + N2);
	while (n1 < N1&&n2 < N2&&coupons[n1] < 0 && product[n2] < 0) {
		sum += (long long)coupons[n1++] * (long long)product[n2++];
	}
	n1 = N1 - 1;
	n2 = N2 - 1;
	while (coupons[n1] > 0 && product[n2] > 0) {
		sum += (long long)coupons[n1--] * (long long)product[n2--];
	}
	printf("%lld", sum);
	return 0;
}