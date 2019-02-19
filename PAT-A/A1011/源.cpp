#include<stdio.h>
int main() {
	char state[4] = { 'W','T','L' };
	double possible = 1.0;
	for (int i = 0; i < 3; i++) {
		int flag;
		double maxpossible=0;
		for (int j = 0; j < 3; j++) {
			double temppossible;
			scanf("%lf", &temppossible);
			if (temppossible > maxpossible) {
				maxpossible = temppossible;
				flag = j;
			}
		}
		printf("%c ", state[flag]);
		possible *= maxpossible;
	}
	printf("%.2lf", (possible*0.65 - 1) * 2);
	return 0;
}