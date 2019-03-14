#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int value;
	vector<int> child;
}input[101];
bool cmp(int a, int b) {
	return input[a].value > input[b].value;
}
vector<int> path;
int sum = 0;
int N, M, S;
void DFS(int root) {
	if (sum + input[root].value > S) return;
	path.push_back(root);
	sum += input[root].value;
	if (sum == S&&input[root].child.size()==0) {
		for (auto it = path.begin(); it != path.end(); it++) {
			if (it != path.begin()) printf(" ");
			printf("%d", input[*it].value);
		}
		printf("\n");
		sum -= input[root].value;
		path.pop_back();
		return;
	}
	sort(input[root].child.begin(), input[root].child.end(), cmp);
	for (auto it = input[root].child.begin(); it != input[root].child.end(); it++) {
		DFS(*it);
	}
	sum -= input[root].value;
	path.pop_back();
	return;
}
int main() {
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < N; i++) scanf("%d", &input[i].value);
	for (int i = 0; i < M; i++) {
		int r, k;
		scanf("%d %d", &r, &k);
		for (int j = 0; j < k; j++) {
			int tempchild;
			scanf("%d", &tempchild);
			input[r].child.push_back(tempchild);
		}
	}
	DFS(0);
	return 0;
}