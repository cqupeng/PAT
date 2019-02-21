#include<stdio.h>
int main() {
	printf("#");
	for (int i = 0; i < 3; i++) {
		int n;
		scanf("%d", &n);
		if (n / 13 == 0) putchar('0');
		else if (n / 13 >= 10) putchar(n / 13 - 10 + 'A');
		else putchar(n / 13 + '0');
		if (n % 13 >= 10) putchar(n % 13 - 10 + 'A');
		else putchar(n % 13+'0');
	}
	return 0;
}