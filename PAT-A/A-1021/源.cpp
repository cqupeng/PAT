#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
const int MaxN = 10010;
vector<int> G[MaxN];
set<int> result_1,result_2;
bool vis[MaxN] = { 0 };
int deepest = 0;
void DFS(int start,int root, int deep,set<int> &result) {
	if (vis[root] == true) return;
	if (deep > deepest) {
		deepest = deep;
		result.clear();
		result.insert(start);
	}
	else if (deep == deepest) result_1.insert(start);
	vis[root] = true;
	for (auto it = G[root].begin(); it != G[root].end(); it++) {
		if (vis[*it] == false) DFS(start,*it, deep + 1,result);
	}
	return;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	int  com_count = 0, flag = 1;
	fill(vis, vis + MaxN, 0);
	for (int j = 1; j <= N; j++) {			//计算连通分量个数
		if (vis[j] == false) {
			com_count++;
			DFS(j,j,0,result_1);
		}
		if (com_count != 1) {
			printf("Error: %d components", com_count);
			flag = 0;
			break;
		}
	}
	if (flag) {
		fill(vis, vis + MaxN, 0);
		deepest = 0;
		DFS(*result_1.begin(), *result_1.begin(), 0, result_2);
		for (auto it = result_2.begin(); it != result_2.end(); it++) {
			if(result_1.find(*it)!=result_1.end()) printf("%d\n", *it);
		}
	}
	return 0;
}