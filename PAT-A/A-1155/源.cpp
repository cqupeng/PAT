#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int input[1111];
int N;
int flag = -1;//0：不是堆 1：大堆 2：小堆
vector<int> output;
void DFS(int root) {
	if (root * 2 > N) {
		output.push_back(root);
		int fa = 1;
		for (auto it = output.begin(); it != output.end(); it++) {
			if (it != output.begin()) printf(" ");
			printf("%d", input[*it]);
			if (it != output.begin()) {
				if (flag == 0);
				else if (input[fa] >= input[*it] && flag == 2) flag = 0;
				else if (input[fa] < input[*it]&&flag == 1) flag = 0;
				else if (input[fa] >= input[*it]) flag = 1;
				else flag = 2;
				fa = *it;
			}
		}
		printf("\n");
		output.pop_back();
		return;
	}
	output.push_back(root);
	if(root*2+1<=N) DFS(root * 2 + 1);
	DFS(root * 2);
	output.pop_back();
	return;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &input[i]);
	}
	DFS(1);
	if (flag == 1) printf("Max Heap");
	else if (flag == 2)printf("Min Heap");
	else printf("Not Heap");
	return 0;
}