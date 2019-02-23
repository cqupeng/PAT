#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int move[55], result[55];
	for (int i = 1; i < 55; i++) {
		scanf("%d", &move[i]);
	}
	for (int i = 1; i < 55; i++) {
		int step = 1;
		int pos = move[i];
		while (step < N) {
			pos=move[pos];
			step++;
		}
		result[pos] = i;
	}
	for (int i = 1; i < 55; i++) {
		if (i != 1) putchar(' ');
		if (result[i]<=13) printf("S%d", result[i] % 14);
		else if (result[i] <= 26) printf("H%d", result[i] - 13);
		else if (result[i] <= 39) printf("C%d", result[i] - 26);
		else if (result[i] <= 52)printf("D%d", result[i] - 39);
		else printf("J%d", result[i] - 52);
	}
	return 0;
}