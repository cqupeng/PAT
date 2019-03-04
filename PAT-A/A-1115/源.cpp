#include<stdio.h>
#include<vector>
using namespace std;
struct node {
	int value, deep;
	node* lchild = NULL;
	node* rchild = NULL;
};
vector<int> level[1111];
int maxdeep = 0;
void creat(node* &root, int value, int deep) {
	if (root == NULL) {
		root = new node;
		root->value = value;
		root->deep = deep;
		level[deep].push_back(value);
		maxdeep = deep > maxdeep ? deep : maxdeep;
		return;
	}
	if (value <= root->value) creat(root->lchild, value, deep + 1);
	else creat(root->rchild, value, deep + 1);
}
int main() {
	int N;
	scanf("%d", &N);
	node* root = NULL;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		creat(root, temp, 0);
	}
	printf("%d + %d = %d", level[maxdeep].size(), level[maxdeep - 1].size(), level[maxdeep].size() + level[maxdeep - 1].size());
	return 0;
}