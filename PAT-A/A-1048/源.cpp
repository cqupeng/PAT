#include<stdio.h>
#include<algorithm>
using namespace std;
int input[100001];
int main() {
	int N, pay;
	scanf("%d %d", &N, &pay);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	sort(input, input + N);
	int left = 0, right = N - 1;
	int flag = 0;
	while (left < right) {
		if (input[left] + input[right] == pay) {
			printf("%d %d", input[left], input[right]);
			flag = 1;
			break;
		}
		else if (input[left] + input[right] < pay) left++;
		else right--;
	}
	if (flag == 0) printf("No Solution");
	return 0;
}