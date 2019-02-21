#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
struct student {
	char info[3][10];
};
int C;
bool cmp(student a, student b) {
	if (strcmp(a.info[C - 1], b.info[C - 1]) != 0) return strcmp(a.info[C - 1], b.info[C - 1])<0;
	else return strcmp(a.info[0], b.info[0])<0;
}
int main() {
	vector<student> input;
	int N;
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		student temp;
		for (int j = 0; j < 3; j++) {
			scanf("%s", &temp.info[j]);
		}
		input.push_back(temp);
	}
	sort(input.begin(), input.end(), cmp);
	for (auto it = input.begin(); it != input.end(); it++) {
		printf("%s %s %s\n", it->info[0], it->info[1], it->info[2]);
	}
	return 0;
}