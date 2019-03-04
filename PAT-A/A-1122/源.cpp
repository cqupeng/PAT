#include<stdio.h>
#include<unordered_map>
using namespace std;
int G[222][222] = { 0 };
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int k;
		int input[2222];//最后一个点的k比较大，所以数组要开大一点才不会导致段错误
		scanf("%d", &k);
		bool flag = true;
		unordered_map<int, int> record;
		for (int j = 0; j < k; j++) {
			scanf("%d", &input[j]);
			if (input[j]<1 || input[j]>N) flag = false;
			else record[input[j]] = 1;
		}
		if (k > N + 1 || k < 1) flag = false;
		else if (input[0] != input[k - 1] || record.size() != N) flag = false;
		else if (flag) {
			for (int j = 1; j < k; j++) if (G[input[j]][input[j - 1]] == 0) flag = false;
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}