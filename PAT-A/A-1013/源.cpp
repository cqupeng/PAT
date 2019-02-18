#include<stdio.h>
#include<vector>
using namespace std;
const int MaxN = 1001;
const int INF = 100000000;
vector<int> G[MaxN];
bool vis[MaxN];
int N, M, K;
void DFS(int v) {
	if (vis[v] == true) return;
	vis[v] = true;
	for (auto it = G[v].begin(); it != G[v].end(); it++) {
		DFS(*it);
	}
	return;
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		int city1, city2;
		scanf("%d%d", &city1, &city2);
		G[city1].push_back(city2);
		G[city2].push_back(city1);
	}
	int printflag = 0;
	for (int i = 0; i < K; i++) {
		int lost_city;
		fill(vis, vis + MaxN, 0);
		scanf("%d", &lost_city);
		vis[lost_city] = true;
		int DiffSet = 0;//强联通分量的数量
		for (int i = 1; i <= N; i++) {
			if (vis[i] == false) {
				DiffSet++;
				DFS(i);
			}
		}
		printf("%d\n", DiffSet-1);//需要修复的路径为强连通分量的数量减一
	}
	return 0;
}