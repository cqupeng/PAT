#include<stdio.h>
#include<string.h>
int main() {
	int N, n1=0, n2;
	char input[82];
	scanf("%s", input);
	N = strlen(input);
	while (N-2*n1+2>=n1) n1++;
	n1--;
	n2 = N - 2 * n1 + 2;
	for (int i = 0; i < n1 - 1; i++) {
		putchar(input[i]);
		for (int j = 0; j < n2 - 2; j++) putchar(' ');
		putchar(input[N - i-1]);
		putchar('\n');
	}
	for (int i = n1 - 1; i < n1 - 1 + n2; i++)
		putchar(input[i]);
	return 0;
}