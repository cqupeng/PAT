#include<stdio.h>
#include<algorithm>
using namespace std;
struct node {
	int add, value=111111, next=-1;
	int flag = 0;
}input[100011];
bool cmp(node a, node b) {
	if (a.flag != b.flag) return a.flag > b.flag;
	else return a.value < b.value;
}
int main() {
	int N, root;
	scanf("%d %d", &N, &root);
	for (int i = 0; i < N; i++) {
		int add;
		scanf("%d", &add);
		input[add].add = add;
		scanf("%d %d", &input[add].value, &input[add].next);
	}
	int now = root;
	int cnt = 0;
	while (now != -1) {
		cnt++;
		input[now].flag = 1;
		now = input[now].next;
	}
	sort(input, input + 100011, cmp);
	if (cnt!=0) printf("%d %05d\n", cnt, input[0].add);
	else printf("0 -1\n");
	for (int i = 0; i < cnt; i++) {
		if (0 == i) printf("%05d %d ", input[i].add, input[i].value);
		else printf("%05d\n%05d %d ", input[i].add, input[i].add, input[i].value);
	}
	if (cnt != 0) printf("-1");
	return 0;
}