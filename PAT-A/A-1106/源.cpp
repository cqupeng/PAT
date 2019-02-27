#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

vector<int> input[100011];
int N;
double p, r;
int mindeep = 0x3f3f3f3f, cnt=0;
void DFS(int root,int deep) {
	if (input[root].size() == 0) {
		if (deep < mindeep) {
			mindeep = deep;
			cnt = 1;
		}
		else if (deep == mindeep) cnt++;
		return;
	}
	for (auto it = input[root].begin(); it != input[root].end(); it++) {
		DFS(*it,deep+1);
	}
}
int main() {
	scanf("%d %lf %lf", &N, &p, &r);
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int child;
			scanf("%d", &child);
			input[i].push_back(child);
		}
	}
	DFS(0, 0);
	printf("%.4f %d", pow(r / 100 + 1, mindeep)*p, cnt);
	return 0;
}