#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string>  input[2511];
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		string name;
		name.resize(5);
		int c;
		scanf("%s %d", &name[0], &c);
		for (int j = 0; j < c; j++) {
			int course;
			scanf("%d", &course);
			input[course].push_back(name);
		}
	}
	for (int i = 1; i <=K; i++) {
		printf("%d %d\n", i, input[i].size());
		sort(input[i].begin(), input[i].end());
		for (auto temp = input[i].begin(); temp != input[i].end(); temp++) {
			printf("%s\n", (*temp).c_str());
		}
	}
	return 0;
}