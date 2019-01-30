#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int A1=0, A2=0, A5=0;
	double A4=0.0;
	int flag2=0,n2=1, n3=0, n4=0;
	while (n--) {
		int temp;
		scanf("%d", &temp);
		if (temp % 5 == 0 && temp % 2 == 0) A1 += temp;
		else if (temp % 5 == 1) {
			A2 += n2 * temp;
			n2 *= -1;
			flag2 = 1;
		}
		else if (temp % 5 == 2) n3++;
		else if (temp % 5 == 3) {
			A4 += (double)temp;
			n4++;
		}
		else if (temp%5==4&&temp > A5) A5 = temp;
	}
	if (A1 == 0) printf("N");
	else printf("%d", A1);
	if (flag2 == 0) printf(" N");
	else printf(" %d", A2);
	if (n3 == 0) printf(" N");
	else printf(" %d", n3);
	if (n4 == 0) printf(" N");
	else printf(" %.1lf", A4 / n4);
	if (A5 == 0) printf(" N");
	else printf(" %d", A5);
	return 0;
}