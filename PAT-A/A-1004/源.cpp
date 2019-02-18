#include<stdio.h>
#include<vector>
using namespace std;
const int MaxN = 101;
vector<int> node[MaxN];
bool vis[MaxN] = { 0 };
int leaves[MaxN] = { 0 };
int maxdeep = 0;
void DFS(int root, int deep) {
	if (node[root].size() == 0) {
		leaves[deep]++;
		maxdeep = maxdeep > deep ? maxdeep : deep;
		return;
	}
	int len = node[root].size();
	for (int i = 0; i < len; i++) {
		if (vis[node[root][i]] == false) {
			vis[node[root][i]] == true;
			DFS(node[root][i], deep + 1);
		}
	}
	return;
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int id, k, childid;
		scanf("%d %d", &id, &k);
		while (k--) {
			scanf("%d", &childid);
			node[id].push_back(childid);
		}
	}
	vis[1] = true;
	DFS(1, 1);
	for (int i = 1; i <= maxdeep; i++) {
		if (i != 1) putchar(' ');
		printf("%d", leaves[i]);
	}
	return 0;
}