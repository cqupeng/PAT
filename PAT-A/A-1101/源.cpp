#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int input[111111];
int left_max[111111];
int right_min[111111];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		if (i == 0) {
			left_max[0] = input[0];
		}
		else {
			if (input[i] > left_max[i - 1]) left_max[i] = input[i];
			else left_max[i] = left_max[i - 1];
		}
	}
	right_min[N - 1] = input[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (input[i] < right_min[i+1]) right_min[i] = input[i];
		else right_min[i] = right_min[i + 1];
	}
	vector<int> output;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			if (input[0] < right_min[1]) output.push_back(input[0]);
		}
		else if (i == N - 1) {
			if (input[N - 1] > left_max[N - 2]) output.push_back(input[N - 1]);
		}
		else if (input[i]<right_min[i + 1] && input[i]>left_max[i - 1]) output.push_back(input[i]);
	}
	printf("%d\n", output.size());
	sort(output.begin(), output.end());
	for (auto it = output.begin(); it != output.end(); it++) {
		if (it != output.begin()) printf(" ");
		printf("%d", *it);
	}
	printf("\n");//即便主元为0也要输出一行空白否则第三个测试点会显示格式错误
	return 0;
}