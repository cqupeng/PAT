#include<stdio.h>
#include<stack>
using namespace std;
int main() {
	int M, N, K;
	scanf("%d%d%d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		int pre = 1, flag = 1;
		stack<int> input;
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			if (j == 0) {
				for (int i = 1; i < temp; i++) input.push(i);
				if (input.size() >= M)  flag = 0;
			}
			else {
				if (temp > input.top()) {
					for (int i = input.top() + 1; i < temp; i++) {
						input.push(i);
					}
					if (input.size() >= M) flag = 0;
				}
				else {
					for (int i = input.top(); i >= temp; i--) {
						if (input.empty()) flag = 0;
						else input.pop();
					}
				}
			}
		}
		if (flag == 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}