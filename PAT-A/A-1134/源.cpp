#include<stdio.h>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> input[10011];
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		input[v1].push_back(v2);
		input[v2].push_back(v1);
	}
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		unordered_map<int, int> vis;
		int n, cnt = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int v;
			scanf("%d", &v);
			for (auto it = input[v].begin(); it != input[v].end(); it++) {
				if (vis[v * 10000 + *it] == 0) {
					cnt++;
					vis[v * 10000 + *it] = 1;
					vis[(*it) * 10000 + v] = 1;
				}
			}
		}
		if (cnt == M) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}