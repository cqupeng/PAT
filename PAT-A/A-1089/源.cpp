#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<int> input;
	vector<int> result;
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		input.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		result.push_back(num);
	}
	int flag = 1;
	vector<int> temp=input;
	for (int i = 1; i < N&&flag; i++) {
		sort(temp.begin(), temp.begin() + min(i,N));
		if (temp == result) {
			flag = 0;
			sort(result.begin(), result.begin() + min(i + 1,N));
			printf("Insertion Sort\n");
		}
	}
	if (flag) {
		printf("Merge Sort\n");
		int step;
		for (step = 2; step < N; step += step) {
			int i = 0;
			while (i < N) {
				sort(input.begin() + i, input.begin() + min(i + step, N));
				i += step;
			}
			if (input == result) break;
		}
		while (input == result&&step<=N) {
			step += step;
			int j = 0;
			while (j < N) {
				sort(result.begin() + j, result.begin() + min(j + step, N));
				j += step;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (i != 0) putchar(' ');
		printf("%d", result[i]);
	}
	return 0;
}