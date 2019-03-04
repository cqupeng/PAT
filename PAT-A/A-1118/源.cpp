#include<stdio.h>

int father[11111];
int find_fa(int root) {
	if (root == father[root]) return root;
	int f = find_fa(father[root]);
	father[root] = f;
	return f;
}
void com(int a, int b) {
	int fa = find_fa(a);
	int fb = find_fa(b);
	father[fa] = fb;
}
int main() {
	for (int i = 0; i < 11111; i++) father[i] = i;
	int N;
	scanf("%d", &N);
	int max_id = 0;
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		int first_id;
		for (int j = 0; j < k; j++) {
			int id;
			scanf("%d", &id);
			max_id = max_id > id ? max_id : id;
			if (j == 0) first_id = id;
			else com(first_id, id);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= max_id; i++) {
		if (father[i] == i) cnt++;
	}
	int q;
	scanf("%d", &q);
	printf("%d %d\n", cnt, max_id);
	for (int i = 0; i < q; i++) {
		int b1, b2;
		scanf("%d %d", &b1, &b2);
		if (find_fa(b1) == find_fa(b2)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}