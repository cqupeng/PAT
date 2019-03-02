#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct fam {
	int id=0, num=0;
	double sum_sets=0, sum_area=0;
	double avg_sets=0, avg_area=0;
}input[11111];
bool cmp(fam a, fam b) {
	if (a.avg_area != b.avg_area) return a.avg_area > b.avg_area;
	else return a.id < b.id;
}
int father[11111];
bool hash_id[11111] = { 0 };
int find_father(int root) {
	if (father[root] == root) return root;
	else {
		int f = find_father(father[root]);
		father[father[root]] = f;
		return f;
	}
}
void combine(int a, int b) {
	int f_a = find_father(a);
	int f_b = find_father(b);
	int min_f = min(f_a, f_b);//保证一个家庭的father节点id最小
	father[f_a] = min_f;
	father[f_b] = min_f;
	return;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < 10000; i++) {
		father[i] = i;
		input[i].id = i;
	}
	for (int i = 0; i < N; i++) {
		int id, fa, mo, k;
		scanf("%d %d %d %d", &id, &fa, &mo, &k);
		hash_id[id] = 1;
		if (fa != -1 && mo != -1) combine(fa, mo);
		if (fa != -1) {
			hash_id[fa] = true;
			combine(fa, id);
		}
		if (mo != -1) {
			combine(mo, id);
			hash_id[mo] = true;
		}
		for (int j = 0; j < k; j++) {
			int child;
			scanf("%d", &child);
			combine(child, id);
			hash_id[child] = 1;
		}
		scanf("%lf %lf", &input[id].sum_sets, &input[id].sum_area);
	}
	int cnt = 0;
	for (int i = 0; i < 10000; i++) {
		if (hash_id[i] == true) {
			int fa = find_father(i);
			if (fa == i && input[i].num == 0) {
				input[i].num++;
				cnt++;
			}
			else {
				input[fa].num++;
				input[fa].sum_area += input[i].sum_area;
				input[fa].sum_sets += input[i].sum_sets;
			}
			input[fa].avg_area = input[fa].sum_area / (double)input[fa].num;
			input[fa].avg_sets = input[fa].sum_sets / (double)input[fa].num;
		}
	}
	sort(input, input + 11111, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%04d %d %.3f %.3f\n", input[i].id, input[i].num, input[i].avg_sets, input[i].avg_area);
	}
	return 0;
}