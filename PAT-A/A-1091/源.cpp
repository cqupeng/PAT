#include<stdio.h>
#include<queue>
using namespace std;
struct node {
	int x, y, z;
	node(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};
const int Maxm = 1289, Maxn = 130, Maxl = 63;
int x[6] = { 0,0,0,0,1,-1 };
int y[6] = { 0,0,1,-1,0,0};
int z[6] = { 1,-1,0,0,0,0 };
int M, N, L,T;
int G[Maxm][Maxn][Maxl] = { 0 };
bool vis[Maxm][Maxn][Maxl] = { 0 };
bool judge(int m, int n, int l) {
	if (m < 0 || m >= M || n < 0 || n >= N || l < 0 || l >= L) 
		return false;
	if (G[m][n][l] == 0 || vis[m][n][l] == true) return false;
	return true;
}
int sum = 0, tempsum = 0;
void BFS(int m, int n, int l) {
	node root(m,n,l);
	queue<node> q;
	q.push(root);
	vis[m][n][l] = true;
	while (!q.empty()) {
		node temp = q.front();
		tempsum++;
		q.pop();
		for (int i = 0; i < 6; i++) {
			node next(temp.x + x[i], temp.y + y[i], temp.z + z[i]);
			if (judge(next.x, next.y, next.z)) {
				vis[next.x][next.y][next.z] = 1;
				q.push(next);
			}
		}
	}
	return;
}
int main() {
	scanf("%d %d %d %d", &M, &N, &L, &T);
	for (int i = 0; i < L; i++) {
		for (int k = 0; k < M; k++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &G[k][j][i]);
			}
		}
	}
	for (int i = 0; i < L; i++) {
		for (int k = 0; k < M; k++) {
			for (int j = 0; j < N; j++) {
				tempsum = 0;
				if (vis[k][j][i] == true||G[k][j][i]==0) continue;
				BFS(k, j, i);
				if (tempsum >= T) sum += tempsum;
			}
		}
	}
	printf("%d", sum);
	return 0;
}