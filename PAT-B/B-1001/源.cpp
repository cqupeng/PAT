#include<stdio.h>

int main() {
	int input, step = 0;
	scanf("%d", &input);
	while (input != 1) {
		if (input % 2 == 0) input /= 2;
		else input = (input * 3 + 1) / 2;
		step++;
	}
	printf("%d\n", step);
	return 0;
}