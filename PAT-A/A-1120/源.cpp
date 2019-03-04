#include<iostream>
#include<set>
#include<string.h>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	set<int> output;
	for (int i = 0; i < N; i++) {
		char temp[6];
		scanf("%s", temp);
		int len = strlen(temp);
		int sum = 0;
		for (int j = 0; j < len; j++) sum += temp[j] - '0';
		output.insert(sum);
	}
	printf("%d\n", output.size());
	for (auto it = output.begin(); it != output.end(); it++) {
		if (it != output.begin()) printf(" ");
		printf("%d", *it);
	}
	return 0;
}