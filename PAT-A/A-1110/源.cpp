#include<iostream>
#include<string>
#include<queue>
#include<cctype>
using namespace std;
struct node {
	int lchild=-1, rchild=-1;
}input[22];
int main() {
	int N;
	scanf("%d", &N);
	getchar();
	int father[22];
	for (int i = 0; i < N; i++) father[i] = i;
	for (int i = 0; i < N; i++) {
		string temp;
		getline(cin, temp);
		int pos = temp.find(' ');
		if (isdigit(temp[pos - 1])) {
			int child = stoi(temp.substr(0, pos));
			father[child] = i;
			input[i].lchild = child;
		}
		if (isdigit(temp[pos + 1])) {
			int child = stoi(temp.substr(pos+1,temp.size()-pos-1));
			father[child] = i;
			input[i].rchild = child;
		}
	}
	int root;
	for (int i = 0; i < N; i++) {
		if (father[i] == i) {
			root = i;
			break;
		}
	}
	queue<int> q;
	q.push(root);
	int flag = 1, ans = 1, lastnode;
	while (!q.empty()&&ans) {
		int temp = q.front();
		q.pop();
		if (q.empty()) lastnode = temp;
		if (input[temp].lchild != -1) {
			if (flag == 0) ans = 0;
			q.push(input[temp].lchild);
		}
		else flag = 0;
		if (input[temp].rchild != -1) {
			q.push(input[temp].rchild);
			if (flag == 0) ans = 0;
		}
		else flag = 0;
	}
	if (ans) printf("YES %d", lastnode);
	else printf("NO %d", root);
	return 0;
}