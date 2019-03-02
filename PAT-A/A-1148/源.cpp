#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<int>	input;
	input.push_back(1);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		input.push_back(temp);
	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int flag[111];
			fill(flag, flag + 111, 1);
			int cnt = 0;//撒谎人数
			int w_cnt = 0;//狼人撒谎人数
			flag[i] = -1;
			flag[j] = -1;
			for (int k = 1; k <= N; k++) {
				if (flag[abs(input[k])] * input[k] < 0) {
					cnt++;
					if (k == i || k == j) w_cnt++;
				}
			}
			if (cnt == 2 && w_cnt == 1) {
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
}