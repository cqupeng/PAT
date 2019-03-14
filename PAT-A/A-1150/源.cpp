#include<stdio.h>
#include<unordered_map>
using namespace std;
const int maxn = 222;
const int INF = 0x3f3f3f3f;
int G[222][222] = { 0 };
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int v1, v2, dis;
		scanf("%d %d %d", &v1, &v2, &dis);
		G[v1][v2] = G[v2][v1] = dis;
	}
	int K;
	scanf("%d", &K);
	int mindis = INF, minindex;
	for (int i = 1; i <= K; i++) {
		int n, pre, tempdis = 0;
		unordered_map<int, int> record;
		scanf("%d", &n);
		int flag = 1, root;
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			if (j == 0)		root = temp;
			else if (G[pre][temp]!=0)	tempdis += G[pre][temp];
			else flag = -1;
			pre = temp;
			record[temp] = 1;
			if (flag!=-1&&j == n - 1 && record.size() == N&&temp==root) {
				if (n == N + 1) flag = 2;
				else flag = 1;
			}
			else if (flag!=-1&&j == n - 1) flag = 0;
		}
		if (flag > 0) {
			if (tempdis < mindis) {
				minindex = i;
				mindis = tempdis;
			}
			if (flag == 2) 	printf("Path %d: %d (TS simple cycle)\n", i, tempdis);
			else if (flag == 1) printf("Path %d: %d (TS cycle)\n", i, tempdis);
		}
		else if(flag!=-1)printf("Path %d: %d (Not a TS cycle)\n", i, tempdis);
		else printf("Path %d: NA (Not a TS cycle)\n", i);
	}
	printf("Shortest Dist(%d) = %d", minindex, mindis);
	return 0;
}