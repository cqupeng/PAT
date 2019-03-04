#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	double sum = 0;
	double input[11111];
	for (int i = 0; i < N; i++)  scanf("%lf", &input[i]);
	sort(input, input + N);
	for (int i = 0; i < N; i++) sum += input[i] / pow(2, N-i-1+(i==0?0:1));
	printf("%d", (int)floor(sum));
	return 0;
}