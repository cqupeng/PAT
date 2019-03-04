#include<stdio.h>
#include<vector>
using namespace std;
struct node {
	int value;
	node* lchild = NULL;
	node* rchild = NULL;
};
int pre[33], post[33];
int flag = 1;
int N;
vector<int> output;
void creat(int pre_l, int pre_r, int post_l, int post_r) {
	if (pre_l > pre_r||pre_l<0||pre_r>=N) return;
	if (post_l > post_r||post_l<0||post_r>=N) return;
	int pos = post_l;
	while (pos <= post_r && pre[pre_l] != post[pos]) pos++;
	creat(pre_l + 1, pre_l + pos - post_l, post_l, pos);
	output.push_back(pre[pre_l]);
	creat(pre_l + pos - post_l+1, pre_r,pos+1,post_r);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < N; i++) scanf("%d", &post[i]);
	creat(0, N - 1, 0, N - 1);
	return 0;
}