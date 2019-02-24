#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
const int Maxn = 1011;
vector<int> G[Maxn];
int N, L;
int BFS(int root) {
	int level[Maxn];
	queue<int> q;
	level[root] = 0;
	bool vis[Maxn] = { 0 };
	vis[root] = 1;
	q.push(root);
	int sum = -1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (level[temp] <= L) sum++;
		else break;
		for (auto it=G[temp].begin(); it != G[temp].end(); it++) {
			if (vis[*it] == 0) {
				vis[*it] = 1;
				level[*it] = level[temp] + 1;
				q.push(*it);
			}
		}
	}
	return sum;
}
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; i++) {
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			int v;
			scanf("%d", &v);
			G[v].push_back(i);
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int query;
		scanf("%d", &query);
		printf("%d\n", BFS(query));
	}
	return 0;
}