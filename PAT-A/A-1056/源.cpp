#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct node {
	int id, w, rank=-1;
}input[1011];
int N, G;
bool cmp(int a, int b) {
	return input[a].w>input[b].w;
}
int cnt = 1;
void getrank(vector<int> temp) {
	if (temp.size() == 1) {
		input[temp[0]].rank = 1;
		cnt++;
		return;
	}
	int first = 0;
	vector<int> next;
	int len = temp.size();
	while (first < len) {
		sort(temp.begin() + first, temp.begin() + min(first + G, len), cmp);
		next.push_back(temp[first]);
		first += G;
	}
	getrank(next);
	int tempcnt = 0;
	for (auto it = temp.begin(); it != temp.end(); it++) {
		if (input[*it].rank == -1) {
			input[*it].rank = cnt;
			tempcnt++;
		}
	}
	cnt += tempcnt;
	return;
}
int main() {
	scanf("%d %d", &N, &G);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i].w);
		input[i].id = i;
	}
	vector<int> root;
	for (int i = 0; i < N; i++) {
		int tempid;
		scanf("%d", &tempid);
		root.push_back(tempid);
	}
	getrank(root);
	for (int i = 0; i < N; i++) {
		if (i != 0) printf(" ");
		printf("%d", input[i].rank);
	}
	return 0;
}