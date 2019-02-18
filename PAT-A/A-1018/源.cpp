#include<cstdio>
#include<vector>
using namespace std;
const int MaxN = 502;
const int INF = 100000000;
int G[MaxN][MaxN], dis[MaxN], bikeNum[MaxN];
bool vis[MaxN];
int Cmax, N, Sp, M, perfect;
vector<int> pre[MaxN];
void Dijkstra() {
	fill(dis, dis + MaxN, INF);
	fill(vis, vis + MaxN, 0);
	dis[0] = 0;
	for (int i = 0; i <= N; i++) {
		int agent = -1, mindis = INF;
		for (int j = 0; j <= N; j++) {
			if (vis[j] == false && dis[j] < mindis) {
				agent = j;
				mindis = dis[j];
			}
		}
		if (agent == -1) return;
		vis[agent] = 1;
		for (int j = 0; j <= N; j++) {
			if (vis[j] == false && dis[agent] + G[agent][j] < dis[j]) {
				dis[j] = dis[agent] + G[agent][j];
				pre[j].clear();
				pre[j].push_back(agent);
			}
			else if (vis[j] == false && dis[agent] + G[agent][j] == dis[j]) {
				pre[j].push_back(agent);
			}
		}
	}
	return;
}
int minTakeBike = INF, minbackBike;
vector<int> resultPath, tempPath;
void DFS(int v) {
	tempPath.push_back(v);
	if (v == 0) {
		int needBike = 0, maxneedBike = 0;
		//最大需求量+原各站点拥有的自行车量-全部达到完美状态时的自行车量=需要带回的自行车量
		int tempbackBike = -perfect*(tempPath.size()-1);
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			needBike -= bikeNum[tempPath[i]] - perfect;
			maxneedBike = maxneedBike > needBike ? maxneedBike : needBike;//记录出现的最大需求量
			tempbackBike += bikeNum[tempPath[i]];
		}
		tempbackBike += maxneedBike;
		if (maxneedBike < minTakeBike||(maxneedBike == minTakeBike && tempbackBike < minbackBike)) {
			resultPath = tempPath;
			minTakeBike = maxneedBike;
			minbackBike = tempbackBike;
		}
		tempPath.pop_back();
		return;
	}
	int len = pre[v].size();
	for (int i = 0; i < len; i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
	return;
}
int main() {
	scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
	perfect = Cmax / 2;
	for (int i = 1; i <= N; i++)
		scanf("%d", &bikeNum[i]);
	fill(G[0], G[0] + MaxN * MaxN, INF);
	for (int i = 0; i < M; i++) {
		int city1, city2, tempdis;
		scanf("%d %d %d", &city1, &city2, &tempdis);
		G[city1][city2] = tempdis;
		G[city2][city1] = tempdis;
	}
	Dijkstra();
	DFS(Sp);
	printf("%d 0", minTakeBike);
	for (int i = resultPath.size() - 2; i >= 0; i--) {
		printf("->%d", resultPath[i]);
	}
	printf(" %d", minbackBike);
	return 0;
}