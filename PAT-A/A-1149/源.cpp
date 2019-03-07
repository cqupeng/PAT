#include<stdio.h>
#include<unordered_map>
#include<vector>
using namespace std;
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	unordered_map<int, vector<int> > record;
	for (int i = 0; i < N; i++) {
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		record[c1].push_back(c2);
		record[c2].push_back(c1);
	}
	for (int i = 0; i < M; i++) {
		int k;
		scanf("%d", &k);
		int input[1001];
		int flag=1;
		unordered_map<int, int> ban;
		for (int j = 0; j < k; j++) {
			scanf("%d", &input[j]);
			if (ban[input[j]] == 1) flag = 0;
			for (auto it = record[input[j]].begin(); flag&&it != record[input[j]].end(); it++) {
				ban[*it] = 1;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}