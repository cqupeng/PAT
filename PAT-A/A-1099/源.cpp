#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct node {
	int value;
	int lchild = -1, rchild = -1;
};
node input[111];
int num[111];
int N, pos=0;
void inorder(int root) {
	if (root == -1) return;
	inorder(input[root].lchild);
	input[root].value = num[pos++];
	inorder(input[root].rchild);
	return;
}
void le_order(int root) {
	queue<int> q;
	q.push(root);
	int flag = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (flag == 0) flag = 1;
		else printf(" ");
		printf("%d", input[temp].value);
		if (input[temp].lchild != -1) q.push(input[temp].lchild);
		if (input[temp].rchild != -1) q.push(input[temp].rchild);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &input[i].lchild, &input[i].rchild);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	inorder(0);
	le_order(0);
	return 0;
}