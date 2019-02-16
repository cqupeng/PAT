//C>J  J>B B>C
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int N;
	int sumA = 0, sumB = 0;
	int maxA = 0, maxB = 0;
	map<char, int> A;
	map<char, int> B;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char tempA, tempB;
		getchar();
		scanf("%c %c", &tempA, &tempB);
		if (tempA == tempB) continue;
		if ((tempA == 'C'&&tempB == 'J') || (tempA == 'J'&&tempB == 'B') || (tempA == 'B'&&tempB == 'C')) {
			sumA++;
			A[tempA]++;
			maxA = max(maxA, A[tempA]);
		}
		else {
			sumB++;
			B[tempB]++;
			maxB = max(maxB, B[tempB]);
		}
	}
	printf("%d %d %d\n", sumA, N - sumA - sumB, sumB);
	printf("%d %d %d\n", sumB, N - sumA - sumB, sumA);
	for (auto it = A.begin(); it != A.end(); it++) {
		if (it->second == maxA) {
			printf("%c ", it->first);
			break;
		}
	}
	for (auto it = B.begin(); it != B.end(); it++) {
		if (it->second == maxB) {
			printf("%c", it->first);
			break;
		}
	}
	if (A.size() == 0) printf("B ");
	if (B.size() == 0) printf("B");
	return 0;
}