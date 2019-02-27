#include<stdio.h>
#include<queue>
using namespace std;
struct node {
	int lchild=-1, rchild=-1;
}input[12];
void level(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int temp = q.front();
		if (temp != root) printf(" ");
		printf("%d", temp);
		q.pop();
		if (input[temp].rchild != -1) q.push(input[temp].rchild);
		if (input[temp].lchild != -1) q.push(input[temp].lchild);
	}
	printf("\n");
	return;
}
int flag = 0;
void inverted_in_order(int root) {
	if (root == -1) return;
	inverted_in_order(input[root].rchild);
	if (flag == 0) flag = 1;
	else printf(" ");
	printf("%d", root);
	inverted_in_order(input[root].lchild);
	return;
}
int main() {
	int N;
	scanf("%d", &N);
	int father[11];
	for (int i = 0; i < N; i++) father[i] = i;
	for (int i = 0; i < N; i++) {
		char str[4];
		getchar();
		fgets(str, sizeof(str), stdin);
		if (str[0] != '-') {
			input[i].lchild = str[0] - '0';
			father[str[0] - '0'] = i;
		}
		if (str[2] != '-') {
			input[i].rchild = str[2] - '0';
			father[str[2] - '0'] = i;
		}
	}
	int root = 0;
	while (root<N&&father[root] != root) root++;
	level(root);
	inverted_in_order(root);
	return 0;
}