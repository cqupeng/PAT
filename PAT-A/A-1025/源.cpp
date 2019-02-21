#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct info {
	string id;
	int location, final_rank, local_rank, score;
};
bool cmp(info a, info b) {
	if (a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}
int main() {
	int N;
	scanf("%d", &N);
	vector<info>  input[101];
	unordered_map<string, int> local_rank_list;
	for (int i = 1; i <= N; i++) {
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			info temp;
			char name[14];
			scanf("%s %d", name, &temp.score);
			temp.id = name;
			temp.location = i;
			input[i].push_back(temp);
			input[0].push_back(temp);
		}
		sort(input[i].begin(), input[i].end(), cmp);
		input[i][0].local_rank = 1;
		local_rank_list[input[i][0].id] = 1;
		for (int j = 1; j < K; j++) {
			if (input[i][j].score == input[i][j - 1].score) input[i][j].local_rank = input[i][j - 1].local_rank;
			else input[i][j].local_rank = j + 1;
			local_rank_list[input[i][j].id] = input[i][j].local_rank;
		}
	}
	sort(input[0].begin(), input[0].end(), cmp);
	input[0][0].final_rank = 1;
	printf("%d\n", input[0].size());
	printf("%s 1 %d 1\n", input[0][0].id.c_str(), input[0][0].location);
	int len = input[0].size();
	for (int i = 1; i < len; i++) {
		if (input[0][i].score == input[0][i - 1].score) input[0][i].final_rank = input[0][i - 1].final_rank;
		else input[0][i].final_rank = i + 1;
		printf("%s %d %d %d\n", input[0][i].id.c_str(), input[0][i].final_rank, input[0][i].location, local_rank_list[input[0][i].id]);
	}
	return 0;
}