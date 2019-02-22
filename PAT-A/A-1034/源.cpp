#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<map>
using namespace std;
unordered_map<string, vector<string> > input;
unordered_map<string, int> people_time;
unordered_map<string, bool> vis;
unordered_map<string, int> edge_time;
int maxtime, group_num, sum_time;
string head;
void DFS(string root) {
	if (vis[root] == true) return;
	group_num++;
	sum_time += edge_time[root];
	vis[root] = true;
	if (people_time[root] > maxtime) {
		maxtime = people_time[root];
		head = root;
	}
	for (auto it = input[root].begin(); it!= input[root].end(); it++) {
		DFS(*it);
	}
	return;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		string A, B;
		int temp_time;
		cin >> A >> B >> temp_time;
		input[A].push_back(B);
		input[B].push_back(A);
		people_time[A] += temp_time;
		people_time[B] += temp_time;
		vis[A] = 0;
		vis[B] = 0;
		edge_time[A] += temp_time;
	}
	map<string, int> gang;
	for (auto it = vis.begin(); it != vis.end(); it++) {
		if (it->second == false) {
			maxtime = 0;
			group_num = 0;
			sum_time = 0;
			DFS(it->first);
			if (group_num > 2 && sum_time > K) {
				gang[head] = group_num;
			}
		}
	}
	printf("%d\n", gang.size());
	for (auto it = gang.begin(); it != gang.end(); it++) {
		printf("%s %d\n", it->first.c_str(), it->second);
	}
	return 0;
}