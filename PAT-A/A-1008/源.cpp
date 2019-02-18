#include<stdio.h>
int main() {
	int N, preFloor = 0, sumTime = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int nowFloor;
		scanf("%d", &nowFloor);
		if (nowFloor > preFloor) sumTime += (nowFloor - preFloor) * 6;
		else sumTime += (preFloor - nowFloor) * 4;
		preFloor = nowFloor;
	}
	printf("%d", sumTime + N * 5);
	return 0;
}