#include<algorithm>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
struct mooncake {
	double num,value, per_value;
};
bool cmp(mooncake A, mooncake B) {
	if (A.per_value != B.per_value) return A.per_value > B.per_value;
	else return true;
}
int main() {
	int N;
	double sum;
	scanf("%d %lf", &N, &sum);
	mooncake temp;
	vector<mooncake> input;
	for (int i = 0; i < N; i++) {
		scanf("%lf", &temp.num);
		input.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		double tempvalue;
		scanf("%lf", &tempvalue);
		input[i].value = tempvalue;
		input[i].per_value = input[i].value / input[i].num;
	}
	sort(input.begin(), input.end(), cmp);
	double output = 0;
	for (int i = 0; i < N && sum; i++) {
		if (sum > input[i].num) {
			output += input[i].value;
			sum -= input[i].num;
		}
		else {
			output += sum*input[i].per_value;
			sum = 0;
		}
	}
	printf("%.2f", output);
	return 0;
}