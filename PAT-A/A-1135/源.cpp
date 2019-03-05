#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node {
	int value, cnt = 0;
	node* lchild = NULL;
	node* rchild = NULL;
};
void insertnode(node* &root, int value) {
	if (root == NULL) {
		root = new node;
		root->value = value;
		return;
	}
	if (abs(value) >= abs(root->value)) {
		insertnode(root->rchild, value);
	}
	else insertnode(root->lchild, value);
}
int flag;
int getblack(node* root) {
	if (root == NULL||flag==0) return 0;
	int l = getblack(root->lchild);
	int r = getblack(root->rchild);
	if (l != r) flag = 0;
	if (root->value >= 0) return max(l,r) + 1;
	else return max(l,r);
}
void DFS(node* root) {
	if (root == NULL) return;
	if (root->value < 0) {
		if (root->lchild == NULL && root->rchild == NULL) ;
		else {
			if (root->lchild != NULL && root->lchild->value < 0) flag = 0;
			if (root->rchild != NULL && root->rchild->value < 0) flag = 0;
		}
	}
	DFS(root->lchild);
	DFS(root->rchild);
}
int main() {
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		flag = 1;
		int N;
		node* root = NULL;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			insertnode(root, temp);
		}
		getblack(root);
		if (root->value < 0) flag = 0;
		else DFS(root);
		if (flag == 0) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}