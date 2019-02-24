#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int value, next;
}input[100001];
int num[100001];
int main() {
	int root, N, K;
	scanf("%d %d %d", &root, &N, &K);
	unordered_map<int, int> hash_add;
	for (int i = 0; i < N; i++) {
		int add, value, next;
		scanf("%d", &add);
		scanf("%d %d", &input[add].value, &input[add].next);
		hash_add[input[add].value] = add;
	}
	int cnt = 0;
	while (root != -1) {
		num[cnt++] = input[root].value;
		root = input[root].next;
	}
	int first = 0, end = K;
	while (end <= cnt) {
		reverse(num + first, num + end);
		first = end;
		end = first + K;
	}
	for (auto it = 0; it != cnt; it++) {
		if (it != 0) printf("%05d\n", hash_add[num[it]]);
		printf("%05d %d ", hash_add[num[it]], num[it]);
	}
	printf("-1");
	return 0;
}