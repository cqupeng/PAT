#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 501;
const int INF = 100000000;
struct edge {
	int v,dis, cost;
	edge(int _v, int _dis, int _cost) {
		v = _v;
		dis = _dis;
		cost = _cost;
	}
};
vector<edge> G[maxn];
int dis[maxn];
bool vis[maxn] = { 0 };
vector<edge> pre[maxn];
int N, M, S, D;
void Dijkstra() {
	fill(dis, dis + maxn, INF);
	dis[S] = 0;
	for (int i = 0; i < N; i++) {
		int u=-1, mindis=INF;
		for (int j = 0; j < N; j++) {
			if (vis[j] == false && dis[j] < mindis) {
				mindis = dis[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (auto it = G[u].begin(); it != G[u].end(); it++) {
			edge temp(u, it->dis, it->cost);
			if (dis[u] + it->dis < dis[it->v]) {
				dis[it->v] = dis[u] + it->dis;
				pre[it->v].clear();
				pre[it->v].push_back(temp);
			}
			else if (dis[u] + it->dis == dis[it->v])
				pre[it->v].push_back(temp);
		}
	}
	return;
}
vector<edge> result_path, temp_path;
int mincost = INF;
void DFS(edge now) {
	if (now.v == S) {
		int tempcost = 0;
		temp_path.push_back(now);
		for (auto it = temp_path.begin(); it != temp_path.end(); it++) {
			tempcost += it->cost;
		}
		if (tempcost < mincost) {
			result_path = temp_path;
			mincost = tempcost;
		}
		temp_path.pop_back();
		return;
	}
	temp_path.push_back(now);
	for (auto it = pre[now.v].begin(); it != pre[now.v].end(); it++) {
		DFS(*it);
	}
	temp_path.pop_back();
	return;
}
int main() {
	scanf("%d %d %d %d", &N, &M, &S, &D);
	for (int i = 0; i < M; i++) {
		int v1, v2, tempdis, tempcost;
		scanf("%d %d %d %d", &v1, &v2, &tempdis, &tempcost);
		edge e1(v2, tempdis, tempcost);
		edge e2(v1, tempdis, tempcost);
		G[v1].push_back(e1);
		G[v2].push_back(e2);
	}
	Dijkstra();
	for (auto it = pre[D].begin(); it != pre[D].end(); it++) {
		DFS(*it);
	}
	reverse(result_path.begin(), result_path.end());
	for (auto it = result_path.begin(); it != result_path.end(); it++) {
		printf("%d ", it->v);
	}
	printf("%d %d %d", D, dis[D], mincost);
	return 0;
}