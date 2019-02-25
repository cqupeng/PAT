#include<stdio.h>
#include<algorithm>
using namespace std;
long long input[100011];
int main() {
	int N, p;
	scanf("%d %d", &N, &p);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &input[i]);
	}
	int maxlen = 0;
	sort(input, input + N);
	for (int i = 0; i+maxlen < N; i++) {
		int pos = upper_bound(input + i, input + N, input[i] * p)-input;
		maxlen = max(maxlen, pos - i);
	}
	printf("%d", maxlen);
	return 0;
}