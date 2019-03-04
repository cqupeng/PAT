#include<stdio.h>
#include<algorithm>
using namespace std;
int input[111111];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	sort(input, input + N);
	int sum = 0;
	int i = 0, j = N / 2;
	while (i < N / 2 && j < N) {
		sum += input[j++] - input[i++];
	}
	printf("%d %d", N % 2, sum+(N%2==0?0:input[N-1]));
	return 0;
}