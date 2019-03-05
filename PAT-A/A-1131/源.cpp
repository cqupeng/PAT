#include<stdio.h>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> input[10000];
unordered_map<int, int> line;
int root, des;
vector<int> anspath, temppath;
bool vis[10000];
int caculateline(vector<int> &path) {
	int preline, cnt = 0;
	int len = path.size();
	for (int i = 1; i < len; i++) {
		int nowline = line[path[i] * 10000 + path[i - 1]];
		if (i ==1||preline != nowline) {
			cnt++;
			preline = nowline;
		}
	}
	return cnt;
}
void DFS(int now) {
	temppath.push_back(now);
	vis[now] = 1;
	if (now == des) {
		if (anspath.size() == 0||temppath.size()<anspath.size()) 
			anspath = temppath;
		else if (temppath.size() == anspath.size()) {
			if (caculateline(temppath) < caculateline(anspath)) anspath = temppath;
		}
		temppath.pop_back();
		vis[now] = 0;
		return;
	}
	for (auto it = input[now].begin(); it != input[now].end(); it++) {
		if (vis[*it] == 0) DFS(*it);
	}
	vis[now] = 0;
	temppath.pop_back();
	return;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int M;
		scanf("%d", &M);
		int pre;
		for (int j = 0; j < M; j++) {
			int s;
			scanf("%d", &s);
			if (j == 0) pre = s;
			else {
				line[s * 10000 + pre] = i;
				line[pre * 10000 + s] = i;
				input[s].push_back(pre);
				input[pre].push_back(s);
				pre = s;
			}
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &root, &des);
		fill(vis, vis + 10000, 0);
		anspath.clear();
		temppath.clear();
		DFS(root);
		int preline, nowline;
		int len = anspath.size();
		printf("%d\n", len-1);
		for (int j = 1; j < len; j++) {
			nowline = line[anspath[j] * 10000 + anspath[j-1]];
			if (j == 1) {
				preline = nowline;
				printf("Take Line#%d from %04d to ", nowline, anspath[0]);
			}
			else if (nowline != preline) {
				printf("%04d.\nTake Line#%d from %04d to ", anspath[j-1], nowline, anspath[j-1]);
				preline = nowline;
			}
		}
		printf("%04d.\n", des);
	}
	return 0;
}