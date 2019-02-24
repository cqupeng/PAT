#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MaxN= 1111;
const int MaxM = 11;
const int INF = 10000000;
int N, M, K, Ds;
int G[MaxN][MaxN];
struct station {
	int id;
	bool vis[MaxN+MaxM];
	int dis[MaxN+MaxM];
	int min_to_house, serve_dis;
	double average_dis;
}gas[MaxM];
void Dijkstra(int root) {
	fill(gas[root].vis, gas[root].vis + MaxN+MaxM, 0);
	fill(gas[root].dis, gas[root].dis + MaxN+MaxM, INF);
	gas[root].dis[root+N] = 0;
	for (int i = 1; i <= M + N; i++) {
		int u = -1, mindis=INF;
		for (int j = 1; j <= M + N; j++) {
			if (gas[root].vis[j] == 0 && gas[root].dis[j] < mindis) {
				u = j;
				mindis = gas[root].dis[j];
			}
		}
		if (u == -1) return;
		gas[root].vis[u] = 1;
		for (int v = 1; v <= M + N; v++) {
			if (gas[root].vis[v]==0&&gas[root].dis[v] > gas[root].dis[u] + G[u][v]) {
				gas[root].dis[v] = gas[root].dis[u] + G[u][v];
			}
		}
	}
	return;
}
void get_gas(int root) {
	gas[root].id = root;
	int sum_dis = 0, mindis = INF, maxdis = 0;
	double average;
	for (int i = 1; i <= N; i++) {
		sum_dis += gas[root].dis[i];
		if (gas[root].dis[i] < mindis) {
			mindis = gas[root].dis[i];
		}
		if (gas[root].dis[i] > maxdis)
			maxdis = gas[root].dis[i];

	}
	if (maxdis > Ds) gas[root].min_to_house = 0;
	else gas[root].min_to_house = mindis;
	gas[root].average_dis = (double)sum_dis / (double)N;
}
bool cmp(station A, station B) {
	if (A.min_to_house != B.min_to_house) return A.min_to_house > B.min_to_house;
	else if (A.average_dis != B.average_dis) return A.average_dis < B.average_dis;
	else return A.id < B.id;
}
int main() {
	scanf("%d %d %d %d", &N, &M, &K, &Ds);
	fill(G[0], G[0] + MaxN * MaxN, INF);
	for (int i = 0; i < K; i++) {
		string A, B;
		int v1, v2,dis;
		cin >> A >> B >> dis;
		if (A[0] == 'G') {
			A.erase(A.begin());
			v1 = stoi(A) + N;
		}
		else v1 = stoi(A);
		if (B[0] == 'G') {
			B.erase(B.begin());
			v2 = stoi(B) + N;
		}
		else v2 = stoi(B);
		G[v1][v2] = dis;
		G[v2][v1] = dis;
	}
	for (int i = 1; i <= M; i++) {
		Dijkstra(i);
		get_gas(i);
	}
	sort(gas + 1, gas + M + 1, cmp);
	if (gas[1].min_to_house == 0) printf("No Solution");
	else printf("G%d\n%.1lf %.1lf", gas[1].id, (double)gas[1].min_to_house, gas[1].average_dis);
}