#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
#define MaxN 31
struct node {
	int value;
	node* lchild = NULL;
	node* rchild = NULL;
};
vector<int> pre, in;

void creat(node* &root, int pre_fisrt, int pre_last, int in_first, int in_last) {
	if (pre_fisrt > pre_last) return;
	root = new node;
	root->value = pre[pre_fisrt];
	int pos = in_first;
	while (in[pos] != root->value) pos++;
	creat(root->lchild, pre_fisrt + 1, pre_fisrt + pos - in_first, in_first, pos - 1);
	creat(root->rchild, pre_fisrt + pos - in_first + 1, pre_last, pos + 1, in_last);
	return;
}
bool flag = 0;
void postorder(node* root) {
	if (root == NULL) return;
	postorder(root->lchild);
	postorder(root->rchild);
	if (flag) printf(" ");
	if (flag == 0) flag = 1;
	printf("%d", root->value);
}
int main() {
	int N;
	scanf("%d", &N);
	stack<int> input;
	for (int i = 0; i < 2*N; i++) {
		char str[6];
		int v;
		scanf("%s", str);
		if (str[1] == 'u') {
			scanf("%d", &v);
			input.push(v);
			pre.push_back(v);
		}
		else {
			v = input.top();
			input.pop();
			in.push_back(v);
		}
	}
	node* root;
	creat(root, 0, N - 1, 0, N - 1);
	postorder(root);
	return 0;
}
