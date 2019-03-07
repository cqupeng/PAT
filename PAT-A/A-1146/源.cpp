#include<stdio.h>	
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
	vector<int> input[1001];
	unordered_map<int, int> hash;
	int N, M, temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		input[v1].push_back(v2);
		hash[v2]++;
	}
	int n;
	scanf("%d", &n);
	int flag1 = 0;
	for (int i = 0; i < n; i++) {
		int flag2 = 1;
		unordered_map<int, int> temphash = hash;
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp);
			if (temphash[temp] != 0) flag2 = 0;
			for (int k = 0; k < input[temp].size() && flag2; k++) {
				int v2 = input[temp][k];
				temphash[v2]--;
			}
		}
		if (flag2 == 0) {
			if (flag1 == 0) flag1 = 1;
			else printf(" ");
			printf("%d", i);
		}
	}
	return 0;
}
