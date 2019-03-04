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
	int max = N - 1;
	for (int i = 0; i < N; i++) {
		if (N - i >= input[i]) {
			max = min(input[i + 1] - 1, N - i - 1);
		}
		else break;
	}
	printf("%d", max);
	return 0;
}