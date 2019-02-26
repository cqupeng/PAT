#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int N, M;
vector<int> input[111];
bool vis[111] = { 0 };
int level_num[111] = { 0 };
int maxnum = 0, maxlevel;
void DFS(int root,int level) {
	if (vis[root] == true) return;
	vis[root] = true;
	level_num[level]++; 
	if (level_num[level] > maxnum) {
		maxnum = level_num[level];
		maxlevel = level;
	}
	for (auto it = input[root].begin(); it != input[root].end(); it++) {
		DFS(*it, level + 1);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int id, K;
		scanf("%d %d", &id, &K);
		for (int j = 0; j < K; j++) {
			int temp;
			scanf("%d", &temp);
			input[id].push_back(temp);
		}
	}
	DFS(1, 1);
	printf("%d %d", maxnum, maxlevel);
	return 0;
}