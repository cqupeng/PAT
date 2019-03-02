#include<stdio.h>
#include<unordered_map>
#include<vector>
using namespace std;
struct node {
	int value;
	node* lchild = NULL;
	node* rchild = NULL;
};
int M, N;
int inorder[11111], preorder[11111];
void creattree(node* &root, int preleft, int preright, int inleft, int inright) {
	if (preleft > preright) return;
	root = new node;
	root->value = preorder[preleft];
	int pos = inleft;
	while (inorder[pos] != root->value) pos++;
	creattree(root->lchild, preleft + 1, preleft + pos - inleft, inleft, pos - 1);
	creattree(root->rchild, preleft + pos - inleft + 1, preright, pos+1, inright);
	return;
}
vector<int> path1, path2, temppath;
void DFS_1(node* root, int value) {
	if (root == NULL) return;
	temppath.push_back(root->value);
	if (root->value == value) {
		path1 = temppath;
		temppath.pop_back();
		return;
	}
	DFS_1(root->lchild,value);
	DFS_1(root->rchild, value);
	temppath.pop_back();
	return;
}void DFS_2(node* root, int value) {
	if (root == NULL) return;
	temppath.push_back(root->value);
	if (root->value == value) {
		path2 = temppath;
		temppath.pop_back();
		return;
	}
	DFS_2(root->lchild, value);
	DFS_2(root->rchild, value);
	temppath.pop_back();
	return;
}
int main() {
	scanf("%d %d", &M, &N);
	unordered_map<int, int> num;
	for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
	for (int i = 0; i < N; i++) {
		scanf("%d", &preorder[i]);
		num[preorder[i]] = 1;
	}
	node* root;
	creattree(root, 0, N - 1, 0, N - 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (num[u] == 0 && num[v] == 0)  printf("ERROR: %d and %d are not found.", u, v);
		else if (num[u] == 0) printf("ERROR: %d is not found.", u);
		else if(num[v]==0) printf("ERROR: %d is not found.", v);
		else {
			DFS_1(root, u);
			DFS_2(root, v);
			int len1 = path1.size();
			int len2 = path2.size();
			int fa = path1[0];
			int p1 = 0, p2 = 0;
			while (len1 > p1&&len2 > p2&&path1[p1] == path2[p2]) {
				fa = path1[p1];
				p1++;
				p2++;
			}
			if (fa == u) printf("%d is an ancestor of %d.", u, v);
			else if (fa == v) printf("%d is an ancestor of %d.", v, u);
			else printf("LCA of %d and %d is %d.", u, v, fa);
		}
		putchar('\n');
	}
	return 0;
}