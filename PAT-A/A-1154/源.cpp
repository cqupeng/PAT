#include<stdio.h>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int color_v[11111];
vector<int> input[11111];
bool vis[11111] = { 0 };
bool BFS(int root) {
	queue<int> q;
	q.push(root);
	vis[root] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (auto it = input[temp].begin(); it != input[temp].end(); it++) {
			if (color_v[temp] == color_v[*it]) return false;
			else if(vis[*it]==0) {
				q.push(*it);
				vis[*it] = 1;
			}
		}
	}
	return true;
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		input[u].push_back(v);
		input[v].push_back(u);
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		unordered_map<int, int> color_sum;
		fill(vis, vis + 11111, 0);
		for (int j = 0; j < N; j++) {
			scanf("%d", &color_v[j]);
			color_sum[color_v[j]]++;
		}
		int flag = 1;
		for (int j = 0; j < N&&flag; j++) {
			if (vis[j] == 0) {
				if (BFS(j) == false) flag = 0;
			}
		}
		if (flag) printf("%d-coloring\n", color_sum.size());
		else printf("No\n");
	}
	return 0;
}