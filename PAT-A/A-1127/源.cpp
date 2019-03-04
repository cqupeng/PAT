#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int N;
int postorder[33], inorder[33];
vector<int> level[33];
void creat(int deep, int postleft,int postright,int inleft,int inright) {
	if (postleft > postright)	return;
	level[deep].push_back(postorder[postright]);
	int p = inleft;
	while (inorder[p] != postorder[postright]) p++;
	creat(deep+1, postleft, postleft + p - inleft-1, inleft, p - 1);
	creat(deep+1, postleft + p - inleft, postright-1, p + 1, inright);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
	for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);
	creat( 1, 0, N - 1, 0, N - 1);
	int l = 1;
	while (level[l].size() != 0) {
		if (l % 2 == 0) {
			for (auto it = level[l].begin(); it != level[l].end(); it++) {
				printf(" %d", *it);
			}
		}
		else {
			for (int it = level[l].size() - 1; it >= 0; it--) {
				if (it == 0 && l == 1);
				else printf(" ");
				printf("%d",level[l][it]);
			}
		}
		l++;
	}
	return 0;
}