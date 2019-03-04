#include<stdio.h>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> input[555];
unordered_map<int, int> record;
int N, M;
int flag = 0;
vector<int> path;
void DFS(int now) {
	if (flag) return;
	record[now] = 1;
	path.push_back(now);
	if (path.size() == N) flag = 1;
	for (auto it = input[now].begin(); it != input[now].end(); it++) {
		if (record[*it] == 0) DFS(*it);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	int degree[555] = { 0 };
	for (int i = 0; i < M; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		input[v1].push_back(v2);
		input[v2].push_back(v1);
		degree[v1]++;
		degree[v2]++;
	}
	DFS(1);
	int odd_cnt = 0, even_cnt = 0;
	for (int i = 1; i <= N; i++) {
		printf("%d", degree[i]);
		if (i != N) printf(" ");
		else printf("\n");
		if (degree[i] % 2 == 0) even_cnt++;
		else odd_cnt++;
	}
	if (flag&&even_cnt == N) printf("Eulerian");
	else if (flag&&odd_cnt == 2) printf("Semi-Eulerian");
	else printf("Non-Eulerian");
	return 0;
}