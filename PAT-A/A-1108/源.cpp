#include<stdio.h>
#include<string.h>
int main(){
	int N;
	scanf("%d", &N);
	int value_num = 0;
	double sum = 0;
	for (int i = 0; i < N; i++){
		char temp1[50], temp2[50];
		scanf("%s", temp1);
		double t1 = 0.0;
		int flag = 1;
		sscanf(temp1, "%lf", &t1);
		sprintf(temp2, "%.2f", t1);
		int len = strlen(temp1);
		for (int j = 0; j < len; j++)
			if (temp1[j] != temp2[j]) flag = 0;
		if (flag&&t1 <= 1000 && t1 >= -1000){
			sum += t1;
			value_num++;
		}
		else printf("ERROR: %s is not a legal number\n", temp1);
	}
	if (value_num == 0) printf("The average of 0 numbers is Undefined\n");
	else if (value_num == 1) printf("The average of 1 number is %.2f\n", sum);
	else printf("The average of %d numbers is %.2f\n", value_num, sum / (double)value_num);
	return 0;
}