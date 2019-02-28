#include<stdio.h>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
#define MaxN 555
int N, M, sou, des;
int input[MaxN][MaxN][2];
bool vis[MaxN];
int dis_time[MaxN][2];
vector<int> pre[MaxN][2];
void Dijsktra(int root, int flag) {
	fill(vis, vis + MaxN, 0);
	dis_time[root][flag] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, minpay = INF;
		for (int j = 0; j < N; j++) {
			if (vis[j] == 0 && dis_time[j][flag] < minpay) {
				minpay = dis_time[j][flag];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < N; v++) {
			if (vis[v] == false && input[u][v][flag]!=INF && dis_time[v][flag] > dis_time[u][flag] + input[u][v][flag]) {
				dis_time[v][flag] = dis_time[u][flag] + input[u][v][flag];
				pre[v][flag].clear();
				pre[v][flag].push_back(u);
			}
			else if (vis[v] == false && input[u][v][flag] != INF && dis_time[v][flag] == dis_time[u][flag] + input[u][v][flag]) {
				pre[v][flag].push_back(u);
			}
		}
	}
}
vector<int> outputpath[2], temppath;
int mininsetion = INF, mintime = INF;
void DFS(int root, int flag) {
	if (root == sou) {
		temppath.push_back(root);
		if (flag == 0) {
			int last, temppay = 0;
			for (auto it = temppath.begin(); it != temppath.end(); it++) {
				if (it == temppath.begin()) last = *it;
				else {
					temppay += input[*it][last][1 - flag];
					last = *it;
				}
			}
			if (temppay < mintime) {
				outputpath[flag] = temppath;
				mintime = temppay;
			}
		}
		else if (flag == 1 && temppath.size() < mininsetion) {
			outputpath[flag] = temppath;
			mininsetion = temppath.size();
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(root);
	for (auto it = pre[root][flag].begin(); it != pre[root][flag].end(); it++) {
		DFS(*it, flag);
	}
	temppath.pop_back();
	return;
}
int main() {
	scanf("%d %d", &N, &M);
	fill(input[0][0], input[0][0] + MaxN * MaxN * 2, INF);
	fill(dis_time[0], dis_time[0] + MaxN * 2, INF);
	for (int i = 0; i < M; i++) {
		int v1, v2, one_way, tempdis, temptime;
		scanf("%d %d %d %d %d", &v1,&v2, &one_way, &tempdis, &temptime);
		input[v1][v2][0] = tempdis;
		input[v1][v2][1] = temptime;
		if (one_way != 1) {
			input[v2][v1][0] = tempdis;
			input[v2][v1][1] = temptime;
		}
	}
	scanf("%d %d", &sou, &des);
	Dijsktra(sou, 0);
	Dijsktra(sou, 1);
	DFS(des, 0);
	DFS(des, 1);
	if (outputpath[0] == outputpath[1]) {
		printf("Distance = %d; Time = %d: %d", dis_time[des][0], dis_time[des][1], sou);
		for (int i = outputpath[0].size() - 2; i >= 0; i--) {
			printf(" -> %d", outputpath[0][i]);
		}
	}
	else {
		printf("Distance = %d: %d", dis_time[des][0], sou);
		for (int i = outputpath[0].size() - 2; i >= 0; i--) {
			printf(" -> %d", outputpath[0][i]);
		}
		putchar('\n');
		printf("Time = %d: %d", dis_time[des][1], sou);
		for (int i = outputpath[1].size() - 2; i >= 0; i--) {
			printf(" -> %d", outputpath[1][i]);
		}
	}
	return 0;
}