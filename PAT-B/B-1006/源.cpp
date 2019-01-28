#include<stdio.h>
int main(){
	int N, B = 0, S = 0;
	scanf("%d", &N);
	B = N / 100;
	N = N % 100;
	S = N / 10;
	N = N % 10;
	while (B--) printf("B");
	while (S--) printf("S");
	for (int i = 1; i <= N; i++) printf("%d", i);
	return 0;
}