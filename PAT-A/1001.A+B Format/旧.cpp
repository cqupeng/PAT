#include<cstdlib>
#include<cstdio>
#include<cstring>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	a = a + b;
	char output[15] = { 0 };
	if (a < 0)
	{
		putchar('-');
		a = -a;
	}
	int temp = 1;
	if (a == 0)
		putchar('0');
	for (int i = 0; i < 15 && a>0; i++)
	{
		output[i] = a % 10 + '0';
		a = a / 10;
		if (temp % 3 == 0 && a != 0)
			output[++i] = ',';
		temp++;
	}
	for (int i = 15; i >= 0; i--)
	{
		if ((output[i] >= '0'&&output[i] <= '9') || output[i] == ',')
			putchar(output[i]);
	}
	system("pause");
	return 0;
}