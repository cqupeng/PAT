#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	int value;
	node* lchild = NULL;
	node* rchild = NULL;
};
vector<int> postorder, inorder;
void creat_tree(node* &root, int postleft, int postright, int inleft, int inright) {
	if (postright >= postorder.size() || postleft < 0||postleft>postright) return;
	if (inleft<0 || inright >= inorder.size()||inleft>inright) return;
	int i = inleft;
	while (inorder[i] != postorder[postright]&&i<inright) i++;
	root = new node;
	root->value = postorder[postright];
	creat_tree(root->lchild, postleft, postleft + i - inleft-1, inleft, i - 1);
	creat_tree(root->rchild, postleft + i - inleft,postright-1, i + 1, inright);
	return;
}
void levelorder(node* root) {
	queue<node*> q;
	q.push(root);
	int flag = 0;
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (flag) printf(" ");
		else flag = 1;
		printf("%d", temp->value);
		if (temp->lchild != NULL) q.push(temp->lchild);
		if (temp->rchild != NULL) q.push(temp->rchild);
	}
	return;
}
int main() {
	int N, temp_value;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp_value);
		postorder.push_back(temp_value);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp_value);
		inorder.push_back(temp_value);
	}
	node* root=NULL;
	creat_tree(root, 0, N - 1, 0, N - 1);
	levelorder(root);
	return 0;
}