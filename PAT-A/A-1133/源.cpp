#include<stdio.h>
#include<vector>
using namespace std;
struct node {
	int add, value, next;
}input[111111];
int main() {
	int root, N, K;
	scanf("%d %d %d", &root, &N, &K);
	vector<node> output[3];
	for (int i = 0; i < N; i++) {
		int a, d, n;
		scanf("%d %d %d", &a, &d, &n);
		input[a] = { a,d,n };
	}
	int now = root;
	while (now != -1) {
		if (input[now].value < 0) output[0].push_back(input[now]);
		else if (input[now].value > K) output[2].push_back(input[now]);
		else output[1].push_back(input[now]);
		now = input[now].next;
	}
	int flag = 0;
	for (int i = 0; i < 3; i++) {
		for (auto it = output[i].begin(); it != output[i].end(); it++) {
			if (flag == 0) {
				printf("%05d %d ", it->add, it->value);
				flag = 1;
			}
			else {
				printf("%05d\n%05d %d ", it->add, it->add, it->value);
			}
		}
	}
	printf("-1");
	return 0;
}