#include<stdio.h>
#include<unordered_map>
using namespace std;
int main() {
	unordered_map<int, int> record;
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			record[temp]++;
			if (record[temp] > N*M / 2) {
				printf("%d", temp);
				return 0;
			}
		}
	}
	return 0;
}