#include<stdio.h>
#include<algorithm>
using namespace std;
int sum[111111] = { 0 };
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int dis;
		scanf("%d", &dis);
		sum[i+1] = sum[i] + dis;
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int first, end, tempdis;
		scanf("%d %d", &first, &end);
		if (first > end) swap(first, end);
		tempdis = sum[end] - sum[first];
		printf("%d\n", min(tempdis,sum[N+1]-tempdis));
	}
	return 0;
}