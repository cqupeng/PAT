#include<stdio.h>
#include<vector>
using namespace std;
int pre[33], post[33];
int N, flag = 1;
vector<int> output;
void creat(int pre_l, int pre_r, int post_l, int post_r) {
	if (pre_l > pre_r||pre_l<0||pre_r>=N) return;
	if (post_l > post_r||post_l<0||post_r>=N) return;
	int pos = post_l;
	while (pos <= post_r && pre[pre_l+1] != post[pos]) pos++;
	if (pre_r - pre_l == 1) flag = 0;
	if (pre_l == pre_r) {
		output.push_back(pre[pre_l]);
		return;
	}
	creat(pre_l + 1, pre_l + pos - post_l+1, post_l, pos);
	output.push_back(pre[pre_l]);
	creat(pre_l + pos - post_l+2, pre_r,pos+1,post_r-1);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < N; i++) scanf("%d", &post[i]);
	creat(0, N - 1, 0, N - 1);
	if (flag == 0) printf("No\n");
	else printf("Yes\n");
	for (auto it = output.begin(); it != output.end(); it++) {
		if (it != output.begin()) printf(" ");
		printf("%d", *it);
	}
	printf("\n");
	return 0;
}