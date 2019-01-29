#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	M = M % N;
	int input[101];
	for (int i = 0; i < N; i++) scanf("%d", &input[i]);
	reverse(input, input + N - M);
	reverse(input + N - M, input + N);
	reverse(input, input + N);
	for (int i = 0; i < N; i++) {
		printf("%d", input[i]);
		if (i != N - 1) putchar(' ');
	}
	return 0;
}