#include<stdio.h>
#include<vector>
using namespace std;
int flagmax, flagmin;
int M, N;
vector<int> output;
int input[1001];
void post(int root) {
	if (root > N) return;
	if (2 * root <= N) {
		if (input[root] >= input[2 * root]) flagmin = 0;
		else flagmax = 0;
		post(root * 2);
	}
	if (2 * root + 1 <= N) {
		if (input[root] >= input[2 * root + 1]) flagmin = 0;
		else flagmax = 0;
		post(root * 2 + 1);
	}
	output.push_back(input[root]);
}
int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		output.clear();
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[j]);
		}
		flagmax = flagmin = 1;
		post(1);
		if (flagmax == 1) printf("Max Heap\n");
		else if (flagmin == 1) printf("Min Heap\n");
		else printf("Not Heap\n");
		for (int j = 0; j < output.size(); j++) {
			if (j != 0)printf(" ");
			printf("%d", output[j]);
		}
		printf("\n");
	}
	return 0;
}