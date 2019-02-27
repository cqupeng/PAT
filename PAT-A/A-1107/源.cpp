#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
int father[1111];
int find_father(int root) {
	if (father[root] == root) return root;
	else {
		int F = find_father(father[root]);
		father[root] = F;
		return father[root];
	}
}
void combine(int a, int b) {
	int fa = find_father(a);
	int fb = find_father(b);
	if (fa != fb) father[fa] = fb;
}
int N;
vector<int> hobby_num[11111];
unordered_set<int> exist_hobby;
int  cluster[11111] = { 0 };
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) father[i] = i;
	for (int i = 0; i< N; i++) {
		int k;
		scanf("%d: ", &k);
		for (int j = 0; j < k; j++) {
			int h;
			scanf("%d", &h);
			hobby_num[h].push_back(i);
			exist_hobby.insert(h);
		}
	}
	for (auto it = exist_hobby.begin(); it != exist_hobby.end(); it++) {
		int pre;
		for (auto i = hobby_num[*it].begin(); i != hobby_num[*it].end(); i++) {
			if (i == hobby_num[*it].begin()) pre = *i;
			else {
				combine(pre, *i);
				pre = *i;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (cluster[find_father(i)]==0) cnt++;
		cluster[father[i]]++;
	}
	sort(cluster, cluster + N);
	printf("%d\n", cnt);
	for (int i = N - 1; i >= N - cnt; i--) {
		if (i != N - 1) printf(" ");
		printf("%d", cluster[i]);
	}
	return 0;
}