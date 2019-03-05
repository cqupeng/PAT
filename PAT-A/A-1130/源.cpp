#include<iostream>
#include<string>
using namespace std;
struct node {
	string value;
	int lchild = -1, rchild = -1;
}input[22];
bool father[22] = { 0 };
int root=1;
void inorder(int now) {
	if (-1 == now) return;
	int flag = 0;
	if (input[now].lchild!=-1||input[now].rchild!=-1) {
		flag = 1;
	}
	//只要该节点有孩子并且不为根节点则需要输出括号
	if (flag&&now != root) cout << '(';
	inorder(input[now].lchild);
	cout << input[now].value;
	inorder(input[now].rchild);
	if (flag&&now!=root) cout << ')';
}
int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string value;
		int c1, c2;
		cin >> value >> c1 >> c2;
		input[i].value = value;
		if (c1 != -1) {
			input[i].lchild = c1;
			father[c1] = i;
		}
		if (c2 != -1) {
			input[i].rchild = c2;
			father[c2] = i;
		}
	}
	while (father[root] != 0) root++;
	inorder(root);
	return 0;
}
