#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		double temp;
		scanf("%lf", &temp);
		sum += temp * (i + 1)*(N - i);
	}
	printf("%.2f", sum);
	return 0;
}