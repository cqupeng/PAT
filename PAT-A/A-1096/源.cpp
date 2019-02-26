#include<stdio.h>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int get_mul(int i, int j) {
	long long sum = 1;
	while (i <= j) {
		sum *= i;
		i++;
	}
	if (sum > INT_MAX) sum = INT_MAX;
	return (int)sum;
}
int main() {
	int N;
	scanf("%d", &N);
	int maxlen = 0;
	int first =0, end = 0, maxn = sqrt(N);
	for (int i = 2; i <= maxn; i++) {
		int j = i;
		while (j <= maxn&&N%get_mul(i, j) == 0) j++;
		if (j - i> maxlen) {
			maxlen = j - i;
			first = i;
			end = j-1;
		}
	}
	if (first == 0) {
		printf("1\n%d", N);
	}
	else {
		printf("%d\n%d", maxlen, first++);
		while (first <= end) printf("*%d", first++);
	}
	return 0;
}