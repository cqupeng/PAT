#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	vector<pair<int, int>> input;
	int x, z;
	while (scanf("%d %d", &x, &z) != EOF) {
		pair<int, int> temp;
		temp.first = x * z;
		temp.second = z - 1;
		input.push_back(temp);
	}
	int flag = 0;
	for (auto it = input.begin(); it != input.end(); it++) {
		if (it->second >= 0) {
			if (flag != 0) printf(" ");
			printf("%d %d", it->first, it->second);
			flag = 1;
		}
	}
	if (flag == 0) printf("0 0");
	return 0;
}