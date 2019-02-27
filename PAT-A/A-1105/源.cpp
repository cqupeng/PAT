#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int output[101][101];
int main() {
	int N;
	vector<int> input;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		input.push_back(temp);
	}
	sort(input.begin(),input.end(),cmp);
	int m=1, n=N;
	while (m < n&&m<N) {		//注意N为质数
		m++;
		if (N%m == 0) n = N / m;
	}
	int l=0, r=n-1, u=0, d=m-1;
	int pos = 0;
	while ((l <= r || u <= d)&&pos<N) {
		for (int i = l; i <= r&&pos<N; i++) {
			output[u][i] = input[pos++];
		}
		for (int i = u + 1; i <= d&&pos<N; i++) {
			output[i][r] = input[pos++];
		}
		for (int i = r - 1; i >= l&&pos<N; i--) {
			output[d][i] = input[pos++];
		}
		for (int i = d - 1; i > u&&pos<N; i--) {
			output[i][l] = input[pos++];
		}
		l++;
		r--;
		u++;
		d--;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j != 0) printf(" ");
			printf("%d", output[i][j]);
			if (j == n-1)  printf("\n");
		}
	}
	return 0;
}