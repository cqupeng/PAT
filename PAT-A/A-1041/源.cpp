#include<stdio.h>
#include<unordered_map>
#include<vector>
using namespace std;
int main() {
	int N, flag = 0;
	scanf("%d", &N);
	vector<int> input;
	unordered_map<int, int> hash;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		input.push_back(temp);
		hash[temp]++;
	}
	for (int i = 0; i < N; i++) {
		if (hash[input[i]] == 1) {
			flag = 1;
			printf("%d", input[i]);
			break;
		}
	}
	if (flag == 0) printf("None");
	return 0;
}