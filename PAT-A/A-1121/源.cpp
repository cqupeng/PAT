#include<iostream>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	unordered_map<string, string> record;
	for (int i = 0; i < N; i++) {
		string c1, c2;
		cin >> c1 >> c2;
		record[c1] = c2;
		record[c2] = c1;
	}
	int M;
	scanf("%d", &M);
	set<string> output;
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if (record.find(temp) == record.end()) output.insert(temp);
		else if (output.find(record[temp]) != output.end()) {
			auto it = output.find(record[temp]);
			output.erase(it);
		}
		else output.insert(temp);
	}
	printf("%d\n", output.size());
	for (auto it = output.begin(); it != output.end(); it++) {
		if (it != output.begin()) printf(" ");
		cout << *it;
	}
	return 0;
}