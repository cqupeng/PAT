#include<iostream>
#include<string>
#include<set>
#include<unordered_map>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	char str[5];
	unordered_map<string, set<int> > input;
	for (int i = 1; i <= K; i++) {
		int course,Ni;
		cin >> course >> Ni;
		for (int j = 0; j < Ni; j++) {
			string name;
			scanf("%s", str);
			name = str;
			input[name].insert(course);
		}
	}
	for (int i = 0; i < N; i++) {
		string query_name;
		scanf("%s",str);
		query_name = str;
		printf("%s %d", str, input[query_name].size());
		for (auto it = input[query_name].begin(); it != input[query_name].end(); it++) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}
