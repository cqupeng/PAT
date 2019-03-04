#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int M, N, S;
	cin >> M >> N >> S;
	int flag = 0;
	unordered_map<string, int> record;
	for (int i = 1; i <= M; i++) {
		string temp;
		cin >> temp;
		if (i == S) {
			if (record[temp] == 0) {
				record[temp] = 1;
				flag = 1;
				cout << temp << "\n";
				S+=N;
			}
			else S++;
		}
	}
	if (flag == 0) cout << "Keep going...";
	return 0;
}