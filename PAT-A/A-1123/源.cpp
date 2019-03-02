#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
	int value, high=1;
	node* lchild = NULL;
	node* rchild = NULL;
}; 

int gethigh(node* root) {
	if (root == NULL) return 0;
	return root->high;
}
int get_ban_fac(node* root) {
	return gethigh(root->lchild) - gethigh(root->rchild);
}
void updatehigh(node* root) {
	root->high = max(gethigh(root->lchild), gethigh(root->rchild)) + 1;
}
void left(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updatehigh(root);
	updatehigh(temp);
	root = temp;
}
void right(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updatehigh(root);
	updatehigh(temp);
	root = temp;
}
void insertnode(node* &root, int value) {
	if (root == NULL) {
		root = new node;
		root->value = value;
		return;
	}
	if (value > root->value) {
		insertnode(root->rchild, value);
		updatehigh(root);
		if (get_ban_fac(root) == -2 && get_ban_fac(root->rchild) == 1) {
			right(root->rchild);
			left(root);
		}
		else if (get_ban_fac(root) == -2 && get_ban_fac(root->rchild) == -1) {
			left(root);
		}
	}
	else {
		insertnode(root->lchild, value);
		updatehigh(root);
		if (get_ban_fac(root) == 2 && get_ban_fac(root->lchild) == 1) {
			right(root);
		}
		else if (get_ban_fac(root) == 2 && get_ban_fac(root->lchild) == -1) {
			left(root->lchild);
			right(root);
		}
	}
	return;
}
int flag = -1;
void BFS(node* root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* temp = q.front();
		if (temp != root) printf(" ");
		printf("%d", temp->value);
		q.pop();
		if (temp->lchild != NULL) {
			q.push(temp->lchild);
			if (flag == 1) flag = 0;
		}
		else if (flag == -1) flag = 1;
		if (temp->rchild != NULL) {
			q.push(temp->rchild);
			if (flag == 1) flag = 0;
		}
		else if (flag == -1) flag = 1;
	}
	if(flag) printf("\nYES");
	else printf("\nNO");
	return;
}
int main() {
	int N;
	scanf("%d", &N);
	node* root=NULL;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		insertnode(root, temp);
	}
	BFS(root);
	return 0;
}