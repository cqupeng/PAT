#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MaxN = 501;
const int INF = 1000000000;
int N, M, C1, C2;
int G[MaxN][MaxN], dis[MaxN], TeamNumber[MaxN];
bool vis[MaxN];
vector<int> pre[MaxN];
void Dijkstra() {
	fill(dis, dis + MaxN, INF);
	fill(vis, vis + MaxN, 0);
	for (int i = 0; i < N; i++) pre[i].push_back(i);
	dis[C1] = 0;
	for (int i = 0; i < N; i++) {
		int agent = -1, mindis = INF;
		for (int i = 0; i < N; i++) {
			if (vis[i] == false && dis[i] < mindis) {
				agent = i;
				mindis = dis[i];
			}
		}
		if (agent == -1) return;
		vis[agent] = true;
		for (int j = 0; j < N; j++) {
			if (vis[j] == false && G[agent][j]!=INF && dis[agent] + G[agent][j] < dis[j]) {
				dis[j] = dis[agent] + G[agent][j];
				pre[j].clear();
				pre[j].push_back(agent);
			}
			else if (vis[j] == false && dis[agent] + G[agent][j] == dis[j])
				pre[j].push_back(agent);
		}
	}
}
int shortest_path_sum = 0;
int max_team_number = 0;
vector<int> temppath;
void DFS(int v) {
	temppath.push_back(v);
	if (v == C1) {
		shortest_path_sum++;
		int temp_team_number=0;
		for (int i = temppath.size() - 1; i >= 0; i--) {
			temp_team_number += TeamNumber[temppath[i]];
		}
		if (temp_team_number > max_team_number) {
			max_team_number = temp_team_number;
		}
		temppath.pop_back();
		return;
	}
	int len = pre[v].size();
	for (int i = 0; i < len; i++) {
		DFS(pre[v][i]);
	}
	temppath.pop_back();
	return;
}

int main() {
	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	fill(G[0], G[0] + MaxN * MaxN, INF);
	for (int i = 0; i < N; i++)
		scanf("%d", &TeamNumber[i]);
	for (int i = 0; i < M; i++) {
		int c1, c2, tempdis;
		scanf("%d %d %d", &c1, &c2, &tempdis);
		G[c1][c2] = tempdis;
		G[c2][c1] = tempdis;
	}
	Dijkstra();
	DFS(C2);
	printf("%d %d", shortest_path_sum, max_team_number);
	return 0;
}