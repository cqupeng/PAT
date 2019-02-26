#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
int N;
double p, r;
vector<int> input[100011];
int cnt = 0, maxdeep = 0;
void DFS(int root,int deep) {
	if (input[root].size() == 0) {
		if (deep == maxdeep) cnt++;
		else if (deep > maxdeep) {
			cnt = 1;
			maxdeep = deep;
		}
		return;
	}
	for (auto it = input[root].begin(); it != input[root].end(); it++) {
		DFS(*it, deep + 1);
	}
	return;
}
int main() {

	scanf("%d %lf %lf", &N, &p, &r);
	int root;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp != -1) {
			input[temp].push_back(i);
		}
		else root = i;
	}
	DFS(root,0);
	printf("%.2f %d", pow(r/100+1, maxdeep)*p, cnt);
	return 0;
}